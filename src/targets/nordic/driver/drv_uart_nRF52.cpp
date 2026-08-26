/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(NRF52840_XXAA)

#include <yss.h>
#include <drv/peripheral.h>
#include <targets/nordic/nRF52_Uart.h>
#include <yss/scheduler.h>
#include <yss/reg.h>
#include <nrf52840_bitfields.h>

nRF52_Uart::nRF52_Uart(const Drv::setup_t drvSetup, const setup_t setup) : Uart(drvSetup)
{
	mDev = setup.dev;
}

error_t nRF52_Uart::initialize(config_t config)
{
	error_t result;
	uint32_t stopbit, parity;

	if(config.mode == MODE_ONE_WIRE)
		return error_t::NOT_SUPPORTED_YET;

	mDev->ENABLE = UARTE_ENABLE_ENABLE_Disabled;
	
	// Configure baudrate.
	result = changeBaudrate(config.baudrate);
	if(result != error_t::ERROR_NONE)
		return result;

	// Configure stop bits.
	switch(config.stopbit)
	{
	case STOP_1BIT :
		stopbit =  0;
		break;
	
	default :
	case STOP_2BIT :
		stopbit =  1;
		break;
	}

	// Configure parity bit.
	switch(config.parity)
	{
	case Uart::PARITY_NONE :
		parity = 0x00;
		break;
	
	case Uart::PARITY_EVEN :
		parity = 0x07;
		break;
	
	default :
		return error_t::UNSUPPORTED_CONFIG;
	}

	setThreeFieldsData(mDev->CONFIG,	UARTE_CONFIG_HWFC_Msk, config.hwfc, UARTE_CONFIG_HWFC_Pos,
										UARTE_CONFIG_PARITY_Msk, parity, UARTE_CONFIG_PARITY_Pos,
										UARTE_CONFIG_STOP_Msk, stopbit, UARTE_CONFIG_STOP_Pos);
	
	mDev->ENABLE = UARTE_ENABLE_ENABLE_Enabled;

	if(config.mode != MODE_TX_ONLY)
	{
		// Configure receive buffer.
		if(config.rcvBuf == nullptr)
		{
			if(mRcvBuf == nullptr)
				delete mRcvBuf;

			mRcvBuf = new int8_t[config.rcvBufSize];

		}
		else
			mRcvBuf = (int8_t*)config.rcvBuf;
		
		mDmaRxIdx = 0;
    
	    mDev->RXD.MAXCNT = 1; // 1바이트마다 끊어서 받음
    
	    // ENDRX(버퍼 꽉참) 발생 시, 0ns 지연으로 즉시 다음 버퍼(STARTRX)로 수신 재개
	    mDev->SHORTS = UARTE_SHORTS_ENDRX_STARTRX_Msk; 
    
	    // 첫 번째 버퍼 세팅 후 시작
	    mDev->RXD.PTR = (uint32_t)&mDmaRxBuf[0];
	    mDev->TASKS_STARTRX = 1;
    
	    // ★ 핵심: 시작하자마자 하드웨어 내부 섀도우 레지스터에 두 번째 버퍼 미리 예약
	    mDev->RXD.PTR = (uint32_t)&mDmaRxBuf[1];

	    mDev->INTENSET = UARTE_INTENSET_ENDRX_Msk; // RXTO 대신 ENDRX 사용
		mRcvBufSize = config.rcvBufSize;
	}

	mMode = config.mode;

	return error_t::ERROR_NONE;
}

error_t nRF52_Uart::changeBaudrate(int32_t baud)
{
	uint32_t en = mDev->ENABLE;
	
	if(en)
		mDev->ENABLE = UARTE_ENABLE_ENABLE_Disabled;

	mDev->BAUDRATE = (int32_t )((double)268.435456 * (double)baud + 0.5);
	
	if(en)
		mDev->ENABLE = UARTE_ENABLE_ENABLE_Enabled;

	return error_t::ERROR_NONE;
}

error_t nRF52_Uart::send(void *src, int32_t  size)
{
	uint32_t primask = __get_PRIMASK();

	if(size == 0)
        return error_t::ERROR_NONE;

    mDev->TXD.PTR = (uint32_t)src;
    mDev->TXD.MAXCNT = size;
	mDev->INTENSET = UARTE_INTENSET_ENDTX_Msk;
	mTxId = thread::getCurrentThreadId();

	__disable_irq();
    mDev->EVENTS_ENDTX = 0;
    mDev->TASKS_STARTTX = 1;

	thread::waitForSignal();

	mDev->INTENCLR = UARTE_INTENSET_ENDTX_Msk;

	__set_PRIMASK(primask);

    return error_t::ERROR_NONE;
}

void nRF52_Uart::send(int8_t data)
{
	uint32_t primask = __get_PRIMASK();

    mDev->EVENTS_TXSTOPPED = 0;

    mDev->TXD.PTR = (uint32_t)&data;
    mDev->TXD.MAXCNT = 1;
	mDev->INTENSET = UARTE_INTENSET_ENDTX_Msk;
	mTxId = thread::getCurrentThreadId();

	__disable_irq();
    mDev->EVENTS_ENDTX = 0;
    mDev->TASKS_STARTTX = 1;

	thread::waitForSignal();

	mDev->INTENCLR = UARTE_INTENSET_ENDTX_Msk;

	__set_PRIMASK(primask);
}

void nRF52_Uart::isr(void)
{
	if(mDev->INTEN & UARTE_INTENSET_ENDTX_Msk && mDev->EVENTS_ENDTX)
	{
	    mDev->EVENTS_ENDTX = 0;
		thread::signal(mTxId);
	}

	if(mDev->INTENSET & UARTE_INTENSET_ENDRX_Msk && mDev->EVENTS_ENDRX)
    {
        mDev->EVENTS_ENDRX = 0;

        // 1. 방금 수신 완료된 버퍼의 데이터를 링버퍼에 push
        push(mDmaRxBuf[mDmaRxIdx]);

        // 2. 방금 빼낸 그 버퍼를, '다음 다음' 수신을 위해 하드웨어에 미리 예약
        mDev->RXD.PTR = (uint32_t)&mDmaRxBuf[mDmaRxIdx];

        // 3. 인덱스 토글 (0 -> 1 -> 0)
        mDmaRxIdx ^= 1; 
        
        // (필요 시 특정 수량이 찼을 때 thread::signal(mRxId) 호출)
    }
}
#endif


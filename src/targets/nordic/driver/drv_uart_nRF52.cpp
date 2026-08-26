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
		
		mRxDmaBuf = new int8_t[32];
		mDev->RXD.PTR = (uint32_t)mRxDmaBuf;
		mDev->RXD.MAXCNT = 32;
		mRcvBufSize = config.rcvBufSize;
		mDev->TASKS_STARTRX = 1;
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

	__set_PRIMASK(primask);
}

uint32_t nRF52_Uart::getRxCount()
{
	mDev->TASKS_STOPRX = 1;
	thread::delay(1);

	int32_t amount = mDev->RXD.AMOUNT;

	for(int32_t i = 0; i < amount; i++)
		push(mRxDmaBuf[i]);
		
	mDev->TASKS_STARTRX = 1;

	return Uart::getRxCount();
}


void nRF52_Uart::isr(void)
{
	if(mDev->EVENTS_ENDTX)
	{
	    mDev->EVENTS_ENDTX = 0;
		thread::signal(mTxId);
	}
}
#endif


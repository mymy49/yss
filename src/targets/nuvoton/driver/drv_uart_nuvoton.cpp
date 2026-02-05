/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#include <yss.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonUart.h>
#include <yss/thread.h>
#include <yss/reg.h>

NuvotonUart::NuvotonUart(const Drv::setup_t drvSetup, const setup_t setup) : Uart(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mTxDma = nullptr;
}

error_t NuvotonUart::initialize(config_t config)
{
	error_t result;
	uint32_t stopbit;

	if(config.mode == UART_MODE_ONE_WIRE)
		return error_t::NOT_SUPPORTED_YET;
	
	// 보레이트 설정
	result = changeBaudrate(config.baudrate);
	if(result != error_t::ERROR_NONE)
		return result;

	// 데이터 길이를 8 Bit로 설정
	setFieldData(mDev->LINE, UART_LINE_WLS_Msk, 0x3, UART_LINE_WLS_Pos);
	
	// Stop bit 설정
	switch(config.stopbit)
	{
	case UART_STOP_1BIT :
		stopbit =  0;
		break;
	
	default :
	case UART_STOP_2BIT :
		stopbit =  1;
		break;
	}
	setFieldData(mDev->LINE, UART_LINE_NSB_Msk, config.stopbit, UART_LINE_NSB_Pos);
	
	// ISR 설정
	mIsrFrameError = config.isrFrameError;
	mIsrRxData = config.isrRxData;

	if(config.mode != UART_MODE_TX_ONLY)
	{
		// RX 인터럽트 활성화
		setBitData(mDev->INTEN, true, UART_INTEN_RDAIEN_Pos);
		setBitData(mDev->INTEN, true, UART_INTEN_RLSIEN_Pos);
		setBitData(mDev->INTEN, true, UART_INTEN_TXPDMAEN_Pos);

		// 수신 버퍼 설정
		if(config.rcvBuf == nullptr)
		{
			if(mRcvBuf == nullptr)
				delete mRcvBuf;

			mRcvBuf = new int8_t[config.rcvBufSize];
		}
		else
			mRcvBuf = (int8_t*)config.rcvBuf;

		mRcvBufSize = config.rcvBufSize;
	}
	
	if(config.mode != UART_MODE_RX_ONLY && mTxDma == nullptr)
	{
		mTxDma = system::allocateDma();
		if(mTxDma == nullptr)
			return error_t::DMA_ALLOCATION_FAILED;

		mTxDma->setSource(mTxDmaInfo.src);
	}
	else if(config.mode == UART_MODE_RX_ONLY)
		mTxDma = nullptr;

	return error_t::ERROR_NONE;
}

error_t NuvotonUart::changeBaudrate(int32_t baud)
{
	int32_t  clk = Drv::getClockFrequency(), brd;

	brd = clk / (baud * 16);
	brd -= 2;
	if(brd > 0xFFFF || brd < 0)
		return error_t::WRONG_CONFIG;
	
	setFieldData(mDev->BAUD, UART_BAUD_BRD_Msk, brd, UART_BAUD_BRD_Pos);

	return error_t::ERROR_NONE;
}

error_t NuvotonUart::send(void *src, int32_t  size)
{
	if(size == 0)
		return error_t::ERROR_NONE;

	mTxDma->transfer(mTxDmaInfo, src, size);

	while (~mDev->INTSTS & UART_INTSTS_TXENDIF_Msk)
		thread::yield();

	return error_t::ERROR_NONE;
}

void NuvotonUart::send(int8_t data)
{
	mDev->DAT = data;
	while (~mDev->INTSTS & UART_INTSTS_TXENDIF_Msk)
		thread::yield();
}

void NuvotonUart::isr(void)
{
	uint32_t sr = mDev->FIFOSTS;

	if(sr & UART_FIFOSTS_FEF_Msk)
	{
		if(mIsrFrameError)
			mIsrFrameError();
		mDev->FIFOSTS = sr;
	}
	
	sr = mDev->INTSTS;
	if(sr & UART_INTSTS_RDAIF_Msk)
	{
		if(mIsrRxData)
			mIsrRxData(mDev->DAT);
		else
			push(mDev->DAT);
	}
}
#endif


/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M251_SUBFAMILY__)

#include <yss.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonUuart.h>
#include <yss/scheduler.h>
#include <yss/reg.h>

#if defined(UUART0)

NuvotonUuart::NuvotonUuart(const Drv::setup_t drvSetup, const setup_t setup) : Uart(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mTxDma = nullptr;
}

error_t NuvotonUuart::initialize(config_t config)
{
	mDev->CTL = 2 << USPI_CTL_FUNMODE_Pos;

	error_t result;
	uint32_t stopbit;

	if(config.mode == MODE_ONE_WIRE)
		return error_t::NOT_SUPPORTED_YET;

	// 보레이트 설정
	result = changeBaudrate(config.baudrate);
	if(result != error_t::ERROR_NONE)
		return result;

		// 데이터 길이를 8 Bit, LSB First로 설정
	setTwoFieldsData(mDev->LINECTL,	UUART_LINECTL_DWIDTH_Msk, 0x8, UUART_LINECTL_DWIDTH_Pos,
									UUART_LINECTL_LSB_Msk, 0x1, UUART_LINECTL_LSB_Pos);

	// Stop bit 설정
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
	setBitData(mDev->PROTCTL, stopbit, UUART_PROTCTL_STOPB_Pos);
	
	// RX 인터럽트 활성화
	setBitData(mDev->INTEN, true, UUART_INTEN_RXENDIEN_Msk);

	// 수신 버퍼 설정
	if(config.mode != MODE_TX_ONLY)
	{
		if(config.rcvBuf == nullptr)
			mRcvBuf = new int8_t[config.rcvBufSize];
		else
			mRcvBuf = (int8_t*)config.rcvBuf;

		mRcvBufSize = config.rcvBufSize; 
		setBitData(mDev->INTEN, 1, UUART_INTEN_RXENDIEN_Pos);
		setBitData(mDev->INTEN, 1, UUART_PROTIEN_RLSIEN_Pos);
	}
	
	if(config.mode != MODE_RX_ONLY)
	{
		mTxDma = system::allocateDma();
		if(mTxDma == nullptr)
			return error_t::DMA_ALLOCATION_FAILED;

		mTxDma->setSource(mTxDmaInfo.src);

		setBitData(mDev->PDMACTL, 1, UUART_PDMACTL_PDMAEN_Pos);
		setBitData(mDev->PDMACTL, 1, UUART_PDMACTL_TXPDMAEN_Pos);
	}

	setBitData(mDev->PROTCTL, 1, UUART_PROTCTL_PROTEN_Pos);

		return error_t::ERROR_NONE;
}

error_t NuvotonUuart::changeBaudrate(int32_t baud)
{
	uint32_t div, clk = Drv::getClockFrequency(), dscnt = 0;
	
	div = clk / baud;
	if(clk % baud == 0 && div > 0)
		div--;
	
	if(div > 0x3FF)
	{
		dscnt = div / 0x200;
		if(dscnt > 1)
			dscnt--;

		clk /= (dscnt + 1);
		div = clk / baud;
		if(clk % baud == 0 && div > 0)
			div--;
	}

	setTwoFieldsData(mDev->BRGEN,	UUART_BRGEN_CLKDIV_Msk, div, UUART_BRGEN_CLKDIV_Pos,
									UUART_BRGEN_DSCNT_Msk, dscnt, UUART_BRGEN_DSCNT_Pos);

	return error_t::ERROR_NONE;
}

error_t NuvotonUuart::send(void *src, int32_t  size)
{
	if(size == 0)
		return error_t::ERROR_NONE;
	
	mTxDma->transfer(mTxDmaInfo, src, size);

	while (mDev->PROTSTS & USPI_PROTSTS_BUSY_Msk)
		thread::yield();

	return error_t::ERROR_NONE;
}

void NuvotonUuart::send(int8_t data)
{
	mDev->PROTSTS = UUART_PROTSTS_TXENDIF_Msk;

	*(uint8_t*)&mDev->TXDAT = data;
	while (~mDev->PROTSTS & UUART_PROTSTS_TXENDIF_Msk)
		thread::yield();
}

void NuvotonUuart::isr(void)
{
	uint32_t sr = mDev->PROTSTS;

	if(sr & (UUART_PROTSTS_FRMERR_Msk | UUART_PROTSTS_BREAK_Msk | UUART_PROTSTS_PARITYERR_Msk))
	{
		if(sr & UUART_PROTSTS_FRMERR_Msk && mIsrHandler.frameError)
			mIsrHandler.frameError();
		mDev->PROTSTS = UUART_PROTSTS_FRMERR_Msk | UUART_PROTSTS_BREAK_Msk | UUART_PROTSTS_PARITYERR_Msk;
	}
	else if(sr & UUART_PROTSTS_RXENDIF_Msk)
	{
		if(mIsrHandler.dataRx)
			mIsrHandler.dataRx(mDev->RXDAT);		
		else
			push(mDev->RXDAT);
	}
}

#endif

#endif


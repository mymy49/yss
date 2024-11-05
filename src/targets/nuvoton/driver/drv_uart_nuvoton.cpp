/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <yss.h>
#include <drv/peripheral.h>
#include <drv/Uart.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m4xx.h>

Uart::Uart(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
}

error_t Uart::initialize(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize)
{
	error_t result;
	
	// 보레이트 설정
	result = changeBaudrate(baud);
	if(result != error_t::ERROR_NONE)
		return result;
	
	// 데이터 길이를 8 Bit로 설정
	setFieldData(mDev->LINE, UART_LINE_WLS_Msk, 0x3, UART_LINE_WLS_Pos);

	// RX 인터럽트 활성화
	setBitData(mDev->INTEN, true, UART_INTEN_RDAIEN_Pos);
	setBitData(mDev->INTEN, true, UART_INTEN_TXPDMAEN_Pos);
	
	// 수신 버퍼 설정
	mRcvBuf = (int8_t*)receiveBuffer;
	mRcvBufSize = receiveBufferSize;

	mTxDma = allocateDma();
	if(mTxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mTxDma->setSource(mTxDmaInfo.src);

	return error_t::ERROR_NONE;
}

error_t Uart::changeBaudrate(int32_t baud)
{
	int32_t  clk = Drv::getClockFrequency();
	int16_t  brd;

	brd = clk / (baud * 16);
	if(brd > 0xFFFF)
		return error_t::WRONG_CONFIG;
	
	setFieldData(mDev->BAUD, UART_BAUD_BRD_Msk, brd, UART_BAUD_BRD_Pos);

	return error_t::ERROR_NONE;
}

error_t Uart::setStopBit(stopbit_t stopBit)
{
	setFieldData(mDev->LINE, UART_LINE_NSB_Msk, stopBit, UART_LINE_NSB_Pos);

	return error_t::ERROR_NONE;
}

error_t Uart::send(void *src, int32_t  size)
{
	if(size == 0)
		return error_t::ERROR_NONE;

	mTxDma->transfer(mTxDmaInfo, src, size);

	return error_t::ERROR_NONE;
}

void Uart::send(int8_t data)
{
	mDev->DAT = data;
	while (~mDev->INTSTS & UART_INTSTS_TXENDIF_Msk)
		thread::yield();
}

void Uart::isr(void)
{
	push(mDev->DAT);
}
#endif


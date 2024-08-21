/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4) || defined (STM32F1) || defined(GD32F1)

#include <drv/peripheral.h>
#include <drv/Uart.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Uart::Uart(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mTxDma = &setup.txDma;
	mTxDmaInfo = setup.txDmaInfo;
	mDev = setup.dev;
	mRcvBuf = 0;
	mTail = 0;
	mHead = 0;
	mOneWireModeFlag = false;
}

error_t Uart::initialize(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize)
{
	int32_t  man, fra;
	int32_t  clk = Drv::getClockFrequency() >> 4;

	mRcvBuf = (int8_t*)receiveBuffer;
	mRcvBufSize = receiveBufferSize;

	man = clk / baud;
	man &= 0xfff;
	fra = 16 * (clk % baud) / baud;
	fra &= 0xf;
	
	// 장치 비활성화
	setBitData(mDev->CR1, false, USART_CR1_UE_Pos);
	
	// 보레이트 설정
	setTwoFieldData(mDev->BRR,	USART_BRR_DIV_Mantissa_Msk, man, USART_BRR_DIV_Mantissa_Pos, 
								USART_BRR_DIV_Fraction_Msk, fra, USART_BRR_DIV_Fraction_Pos);
	
	// TX En, RX En, Rxnei En, 장치 En
	mDev->CR1 = USART_CR1_RE_Msk | USART_CR1_TE_Msk | USART_CR1_RXNEIE_Msk | USART_CR1_UE_Msk;

	return error_t::ERROR_NONE;
}

error_t Uart::changeBaudrate(int32_t baud)
{
	int32_t  man, fra;
	int32_t  clk = Drv::getClockFrequency() >> 4;
	bool enableFlag;

	man = clk / baud;
	man &= 0xfff;
	fra = 16 * (clk % baud) / baud;
	fra &= 0xf;
	
	enableFlag = (mDev->CR1 & USART_CR1_UE_Msk) == USART_CR1_UE_Msk;
	if(enableFlag)
		mDev->CR1 &= ~USART_CR1_UE_Msk;
	
	setTwoFieldData(mDev->BRR, 0xFFF << 4, man, 4, 0xF << 0, fra, 0);

	if(enableFlag)
		mDev->CR1 |= USART_CR1_UE_Msk;

	return error_t::ERROR_NONE;
}


error_t Uart::setStopBit(stopbit_t stopBit)
{
	bool enableFlag;

	enableFlag = (mDev->CR1 & USART_CR1_UE_Msk) == USART_CR1_UE_Msk;
	if(enableFlag)
		mDev->CR1 &= ~USART_CR1_UE_Msk;
	
	setFieldData(mDev->CR2, USART_CR2_STOP_Msk, stopBit, USART_CR2_STOP_Pos);

	if(enableFlag)
		mDev->CR1 |= USART_CR1_UE_Msk;

	return error_t::ERROR_NONE;
}

void Uart::setOneWireMode(bool en)
{
	mOneWireModeFlag = en;
	setBitData(mDev->CR3, en, USART_CR3_HDSEL_Pos);
}

error_t Uart::send(void *src, int32_t  size)
{
	error_t result;

	if(size == 0)
		return error_t::ERROR_NONE;

	if(mTxDma == 0)
		return error_t::DMA_ERROR;

	mTxDma->lock();

	setBitData(mDev->CR3, true, 7);		// TX DMA 활성화

	mDev->SR = ~USART_SR_TC;

	result = mTxDma->transfer(mTxDmaInfo, src, size);

	if(result == error_t::ERROR_NONE)
		while (!(mDev->SR & USART_SR_TC))
			thread::yield();

	setBitData(mDev->CR3, false, 7);		// TX DMA 비활성화

	mTxDma->unlock();

	return result;
}

void Uart::send(int8_t data)
{
	if(mOneWireModeFlag)
	{
		setBitData(mDev->CR1, false, 2);	// RX 비활성화
	}

	mDev->SR = ~USART_SR_TC;
	mDev->DR = data;
	while (~mDev->SR & USART_SR_TC)
		thread::yield();

	if(mOneWireModeFlag)
	{
		setBitData(mDev->CR1, true, 2);	// RX 활성화
	}
}

void Uart::isr(void)
{
	uint32_t sr = mDev->SR;

	if(sr & (USART_SR_FE_Msk | USART_SR_ORE_Msk | USART_SR_NE_Msk))
	{
		if(sr & USART_SR_FE_Msk && mIsrForFrameError)
			mIsrForFrameError();

		if(sr & USART_SR_ORE_Msk)
			__NOP();

		mDev->DR;
		mDev->SR = USART_SR_FE_Msk | USART_SR_ORE_Msk | USART_SR_NE_Msk;
	}
	else if(mIsrForRxData)
		mIsrForRxData(mDev->DR);
	else
		push(mDev->DR);
}

#endif


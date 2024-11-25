/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4) || defined(STM32F0) || defined(STM32F7) || defined(GD32F1) || defined(STM32F1) || defined(STM32G4)

#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Spi::Spi(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mLastSpec = 0;
	mDataSize = 1;
#if !defined(STM32G4)
	mTxDma = &setup.txDma;
	mRxDma = &setup.rxDma;
#endif
}

error_t Spi::setSpecification(const specification_t &spec)
{
#if defined(STM32F4) ||  defined(GD32F1) || defined(STM32F1)
	uint32_t reg, buf;
#elif defined(STM32F0) || defined(STM32F7)
	uint32_t reg;
#endif

	if (mLastSpec == &spec)
		return error_t::ERROR_NONE;
	mLastSpec = &spec;

	uint32_t div, clk = Drv::getClockFrequency();

	div = clk / spec.maxFreq;
	if (clk % spec.maxFreq)
		div++;

	if (div <= 2)
		div = 0;
	else if (div <= 4)
		div = 1;
	else if (div <= 8)
		div = 2;
	else if (div <= 16)
		div = 3;
	else if (div <= 32)
		div = 4;
	else if (div <= 64)
		div = 5;
	else if (div <= 128)
		div = 6;
	else if (div <= 256)
		div = 7;
	else
		return error_t::WRONG_CONFIG;
	
#if defined(STM32F4) ||  defined(GD32F1) || defined(STM32F1)
	using namespace define::spi;

	switch(spec.bit)
	{
	case bit::BIT8 :
		buf = 0;
		break;
	case bit::BIT16 :
		buf = 1;
		break;
	default :
		return error_t::WRONG_CONFIG;
	}

	reg = mDev->CR1;
	reg &= ~(SPI_CR1_BR_Msk | SPI_CR1_CPHA_Msk | SPI_CR1_CPOL_Msk | SPI_CR1_DFF_Msk);
	reg |= spec.mode << SPI_CR1_CPHA_Pos | div << SPI_CR1_BR_Pos | buf << SPI_CR1_DFF_Pos;
	mDev->CR1 = reg;
#elif defined(STM32F0) || defined(STM32F7)
	reg = mDev->CR1;
	reg &= ~(SPI_CR1_BR_Msk | SPI_CR1_CPHA_Msk | SPI_CR1_CPOL_Msk);
	reg |= spec.mode << SPI_CR1_CPHA_Pos | div << SPI_CR1_BR_Pos;
	mDev->CR1 = reg;
	
	mDev->CR2 = spec.bit << SPI_CR2_DS_Pos | SPI_CR2_FRXTH_Msk;
#endif
	mDev->DR;

	return error_t::ERROR_NONE;
}

error_t Spi::initializeAsMain(void)
{
	setBitData(mDev->CR1, false, SPI_CR1_SPE_Pos);	// SPI 비활성화

	mDev->CR1 |= SPI_CR1_SSI_Msk | SPI_CR1_SSM_Msk | SPI_CR1_MSTR_Msk;

	return error_t::ERROR_NONE;
}

error_t Spi::initializeAsSub(void)
{
	mDev->CR1 = 0;

#if defined(STM32G4)
	mRxDma = getOccupancyDma();
#endif

	return error_t::ERROR_NONE;
}

void Spi::enable(bool en)
{
	setBitData(mDev->CR1, en, 6);
}

error_t Spi::send(void *src, int32_t  size)
{
#if defined(STM32G4)
	error_t result;
	Dma *dma;

	if(size == 1)
	{
		send(*(int8_t*)src);
		return error_t::ERROR_NONE;
	}

	dma = getIdleDma();
	mDev->CR2 = SPI_CR2_TXDMAEN_Msk;
	mThreadId = thread::getCurrentThreadId();

	result = dma->transfer(mTxDmaInfo, src, size);
	dma->unlock();
	
	if(mDev->SR & SPI_SR_BSY_Msk)
	{
		mDev->DR;
		mDev->CR2 = SPI_CR2_RXNEIE_Msk;
		while(mDev->SR & SPI_SR_BSY_Msk)
			thread::yield();
	}

	mDev->DR;
	
	return result;
#else
	error_t result;

	if(size == 1)
	{
		send(*(int8_t*)src);
		return error_t::ERROR_NONE;
	}

	mTxDma->lock();
#if defined(STM32F0) || defined(STM32F7)
	mDev->CR2 |= SPI_CR2_TXDMAEN_Msk;
#else
	mDev->CR2 = SPI_CR2_TXDMAEN_Msk;
#endif
	mThreadId = thread::getCurrentThreadId();

	result = mTxDma->transfer(mTxDmaInfo, src, size);
	mTxDma->unlock();
	
	if(mDev->SR & SPI_SR_BSY_Msk)
	{
		mDev->DR;
#if defined(STM32F0) || defined(STM32F7)
		mDev->CR2 &= ~SPI_CR2_TXDMAEN_Msk;
		mDev->CR2 |= SPI_CR2_RXNEIE_Msk;
#else
		mDev->CR2 = SPI_CR2_RXNEIE_Msk;
#endif
		while(mDev->SR & SPI_SR_BSY_Msk)
			thread::yield();
	}

#if defined(STM32F7)
	mDev->DR;
	mDev->DR;
	mDev->DR;
#else
	mDev->DR;
#endif
	
	return result;
#endif
}

error_t Spi::exchange(void *des, int32_t  size)
{
#if defined(STM32G4)
	error_t rt = error_t::ERROR_NONE;
	Dma *rxDma, *txDma;

	if(size == 1)
	{
		*(int8_t*)des = exchange(*(int8_t*)des);
		return error_t::ERROR_NONE;
	}

	mDev->DR;

	rxDma = getIdleDma();
	txDma = getIdleDma();

	rxDma->lock();
	txDma->lock();

	mDev->CR2 = SPI_CR2_TXDMAEN_Msk | SPI_CR2_RXDMAEN_Msk;
	rxDma->ready(mRxDmaInfo, des, size);
	rt = txDma->send(mTxDmaInfo, des, size);
	
	while(!rxDma->isComplete())
		thread::yield();

	mDev->CR2 = 0;
	rxDma->stop();
	rxDma->unlock();
	txDma->unlock();

	return rt;
#else
	error_t rt = error_t::ERROR_NONE;

	if(size == 1)
	{
		*(int8_t*)des = exchange(*(int8_t*)des);
		return error_t::ERROR_NONE;
	}

	mDev->DR;

	mRxDma->lock();
	mTxDma->lock();

#if defined(STM32F0) || defined(STM32F7)
	mDev->CR2 |= SPI_CR2_TXDMAEN_Msk | SPI_CR2_RXDMAEN_Msk;
#else
	mDev->CR2 = SPI_CR2_TXDMAEN_Msk | SPI_CR2_RXDMAEN_Msk;
#endif

	mRxDma->ready(mRxDmaInfo, des, size);
	rt = mTxDma->transfer(mTxDmaInfo, des, size);
	
	while(!mRxDma->isComplete())
		thread::yield();

#if defined(STM32F0) || defined(STM32F7)
	mDev->CR2 &= ~(SPI_CR2_TXDMAEN_Msk | SPI_CR2_RXDMAEN_Msk);
#else
	mDev->CR2 = 0;
#endif

	mRxDma->unlock();
	mTxDma->unlock();

	return rt;
#endif
}

void Spi::receiveAsCircularMode(void *src, uint16_t count)
{
	mTail = count;
	mTransferBufferSize = count;
	mDataBuffer = (uint8_t*)src;
	mDev->CR2 |= SPI_CR2_RXDMAEN_Msk;

	mRxDma->lock();
	mRxDma->transfer(mRxDmaInfo, src, count);
}

uint8_t Spi::exchange(uint8_t data)
{
	mThreadId = thread::getCurrentThreadId();
#if defined(STM32F0) || defined(STM32F7)
	mDev->CR2 |= SPI_CR2_RXNEIE_Msk;
#else
	mDev->CR2 = SPI_CR2_RXNEIE_Msk;
#endif
	*(uint8_t*)&mDev->DR = data;
	while (~mDev->SR & SPI_SR_RXNE_Msk)
		thread::yield();

	return mDev->DR;
}

void Spi::send(uint8_t data)
{
	mDev->DR;
	mThreadId = thread::getCurrentThreadId();
#if defined(STM32F0) || defined(STM32F7)
	mDev->CR2 |= SPI_CR2_RXNEIE_Msk;
#else
	mDev->CR2 = SPI_CR2_RXNEIE_Msk;
#endif
	*(uint8_t*)&mDev->DR = data;
	while (~mDev->SR & SPI_SR_RXNE_Msk)
		thread::yield();

	mDev->DR;
}

void Spi::isr(void)
{
#if defined(STM32F0) || defined(STM32F7)
	mDev->CR2 &= ~SPI_CR2_RXNEIE_Msk;
#else
	mDev->CR2 = 0;
#endif
	thread::signal(mThreadId);
}

#endif

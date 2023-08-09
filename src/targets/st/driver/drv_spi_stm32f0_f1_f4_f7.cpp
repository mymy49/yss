////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F4_N) || defined(STM32F0_N) || defined(STM32F7_N) || defined(GD32F1) || defined(STM32F1_N)

#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <yss/thread.h>
#include <yss/reg.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#include <targets/st/define_stm32f446xx.h>
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#elif defined(STM32F030xC)
#include <targets/st/bitfield_stm32f030xx.h>
#elif defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#elif defined(GD32F1) || defined(STM32F103xB)
#include <targets/st/bitfield_stm32f103xx.h>
#endif

Spi::Spi(const Drv::Setup drvSetup, const Setup setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDma = &setup.txDma;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDma = &setup.rxDma;
	mRxDmaInfo = setup.rxDmaInfo;
	mLastSpec = 0;
	mDataSize = 1;
}

error Spi::setSpecification(const Specification &spec)
{
	uint32_t reg, buf;

	if (mLastSpec == &spec)
		return error::ERROR_NONE;
	mLastSpec = &spec;

	uint32_t mod;
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
		return error::WRONG_CONFIG;
	
#if defined(STM32F4_N) ||  defined(GD32F1) || defined(STM32F1_N)
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
		return error::WRONG_CONFIG;
	}

	reg = mDev->CR1;
	reg &= ~(SPI_CR1_BR_Msk | SPI_CR1_CPHA_Msk | SPI_CR1_CPOL_Msk | SPI_CR1_DFF_Msk);
	reg |= spec.mode << SPI_CR1_CPHA_Pos | div << SPI_CR1_BR_Pos | buf << SPI_CR1_DFF_Pos;
	mDev->CR1 = reg;
#elif defined(STM32F0_N) || defined(STM32F7_N)
	reg = mDev->CR1;
	reg &= ~(SPI_CR1_BR_Msk | SPI_CR1_CPHA_Msk | SPI_CR1_CPOL_Msk);
	reg |= spec.mode << SPI_CR1_CPHA_Pos | div << SPI_CR1_BR_Pos;
	mDev->CR1 = reg;
	
	mDev->CR2 = spec.bit << SPI_CR2_DS_Pos | SPI_CR2_FRXTH_Msk;
#endif
	mDev->DR;

	return error::ERROR_NONE;
}

error Spi::initializeAsMain(void)
{
	setBitData(mDev->CR1, false, SPI_CR1_SPE_Pos);	// SPI 비활성화

	mDev->CR1 |= SPI_CR1_SSI_Msk | SPI_CR1_SSM_Msk | SPI_CR1_MSTR_Msk;

	return error::ERROR_NONE;
}

error Spi::initializeAsSub(void)
{
	mDev->CR1 = 0;
//	mDev->CR1 |= SPI_CR1_SSI_Msk | SPI_CR1_SSM_Msk;

	return error::ERROR_NONE;
}

void Spi::enable(bool en)
{
	setBitData(mDev->CR1, en, 6);
}

error Spi::send(void *src, int32_t  size)
{
	error result;

	if(size == 1)
	{
		send(*(int8_t*)src);
		return error::ERROR_NONE;
	}

	mTxDma->lock();
#if defined(STM32F0_N)
	mDev->CR2 |= SPI_CR2_TXDMAEN_Msk;
#else
	mDev->CR2 = SPI_CR2_TXDMAEN_Msk;
#endif
	mThreadId = thread::getCurrentThreadId();

	result = mTxDma->send(mTxDmaInfo, src, size);
	mTxDma->unlock();
	
	if(mDev->SR & SPI_SR_BSY_Msk)
	{
		mDev->DR;
#if defined(STM32F0_N)
		mDev->CR2 &= ~SPI_CR2_TXDMAEN_Msk;
		mDev->CR2 |= SPI_CR2_RXNEIE_Msk;
#else
		mDev->CR2 = SPI_CR2_RXNEIE_Msk;
#endif
		while(mDev->SR & SPI_SR_BSY_Msk)
			thread::yield();
	}
	
	mDev->DR;
	
	return result;
}

error Spi::exchange(void *des, int32_t  size)
{
	error rt = error::ERROR_NONE;

	if(size == 1)
	{
		*(int8_t*)des = exchange(*(int8_t*)des);
		return error::ERROR_NONE;
	}

	mDev->DR;

	mRxDma->lock();
	mTxDma->lock();

#if defined(STM32F0_N)
	mDev->CR2 |= SPI_CR2_TXDMAEN_Msk | SPI_CR2_RXDMAEN_Msk;
#else
	mDev->CR2 = SPI_CR2_TXDMAEN_Msk | SPI_CR2_RXDMAEN_Msk;
#endif

	mRxDma->ready(mRxDmaInfo, des, size);
	rt = mTxDma->send(mTxDmaInfo, des, size);
	
	while(!mRxDma->isComplete())
		thread::yield();

#if defined(STM32F0_N)
	mDev->CR2 &= ~(SPI_CR2_TXDMAEN_Msk | SPI_CR2_RXDMAEN_Msk);
#else
	mDev->CR2 = 0;
#endif

	mRxDma->stop();
	mRxDma->unlock();
	mTxDma->unlock();

	return rt;
}

void Spi::receiveAsCircularMode(void *src, uint16_t count)
{
	mLastTransferIndex = count;
	mTransferBufferSize = count;
	mDataBuffer = (uint8_t*)src;
	mDev->CR2 |= SPI_CR2_RXDMAEN_Msk;

	mRxDma->lock();
	mRxDma->transferAsCircularMode(&mRxDmaInfo, src, count);
}

int8_t Spi::exchange(int8_t data)
{
	mThreadId = thread::getCurrentThreadId();
#if defined(STM32F0_N)
	mDev->CR2 |= SPI_CR2_RXNEIE_Msk;
#else
	mDev->CR2 = SPI_CR2_RXNEIE_Msk;
#endif
	*(int8_t*)&mDev->DR = data;
	while (~mDev->SR & SPI_SR_RXNE_Msk)
		thread::yield();

	return mDev->DR;
}

void Spi::send(int8_t data)
{
	mDev->DR;
	mThreadId = thread::getCurrentThreadId();
#if defined(STM32F0_N)
	mDev->CR2 |= SPI_CR2_RXNEIE_Msk;
#else
	mDev->CR2 = SPI_CR2_RXNEIE_Msk;
#endif
	*(int8_t*)&mDev->DR = data;
	while (~mDev->SR & SPI_SR_RXNE_Msk)
		thread::yield();

	mDev->DR;
}

void Spi::isr(void)
{
#if defined(STM32F0_N)
	mDev->CR2 &= ~SPI_CR2_RXNEIE_Msk;
#else
	mDev->CR2 = 0;
#endif
	thread::signal(mThreadId);
}

#endif

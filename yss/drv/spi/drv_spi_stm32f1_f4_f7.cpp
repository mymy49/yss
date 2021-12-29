////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32L0)

#include <__cross_studio_io.h>

#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <drv/spi/register_spi_stm32f1_f4_f7.h>
#include <yss/thread.h>

namespace drv
{

//Uart::Uart(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
//{
//	mGetClockFreq = config.getClockFreq;
//	mDma = &config.txDma;
//	mTxDmaInfo = config.txDmaInfo;
//	mPeri = config.peri;
//	mRcvBuf = 0;
//	mTail = 0;
//	mHead = 0;
//}

Spi::Spi(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mGetClockFreq = config.getClockFreq;
	mPeri = config.peri;
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = config.rxDmaInfo;
	mLastConfig = 0;
}

bool Spi::setConfig(config::spi::Config &config)
{
	register unsigned int reg, buf;

	if (mLastConfig == &config)
		return true;
	mLastConfig = &config;

	unsigned int mod;
	unsigned int div, clk = mGetClockFreq();

	div = clk / config.maxFreq;
	if (clk % config.maxFreq)
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
		return false;
	
	using namespace define::spi;
#if defined(STM32F1) || defined(STM32F4)
	switch(config.bit)
	{
	case bit::BIT8 :
		buf = 0;
		break;
	case bit::BIT16 :
		buf = 1;
		break;
	default :
		return false;
	}
	reg = mPeri->CR1;
	reg &= ~(SPI_CR1_BR_Msk | SPI_CR1_CPHA_Msk | SPI_CR1_CPOL_Msk | SPI_CR1_DFF_Msk);
	reg |= config.mode << SPI_CR1_CPHA_Pos | div << SPI_CR1_BR_Pos | buf << SPI_CR1_DFF_Pos;
	mPeri->CR1 = reg;
#elif defined(STM32F7)
	switch(config.bit)
	{
	case bit::BIT4 :
		buf = 3;
		break;
	case bit::BIT5 :
		buf = 4;
		break;
	case bit::BIT6 :
		buf = 5;
		break;
	case bit::BIT7 :
		buf = 6;
		break;
	case bit::BIT8 :
		buf = 7;
		break;
	case bit::BIT9 :
		buf = 8;
		break;
	case bit::BIT10 :
		buf = 9;
		break;
	case bit::BIT11 :
		buf = 10;
		break;
	case bit::BIT12 :
		buf = 11;
		break;
	case bit::BIT13 :
		buf = 12;
		break;
	case bit::BIT14 :
		buf = 13;
		break;
	case bit::BIT15 :
		buf = 14;
		break;
	case bit::BIT16 :
		buf = 15;
		break;
	default :
		return false;
	}

	reg = mPeri->CR2;
	reg &= ~SPI_CR2_DS_Msk;
	reg |= buf << SPI_CR2_DS_Pos;
	mPeri->CR2 = reg;

	reg = mPeri->CR1;
	reg &= ~(SPI_CR1_BR_Msk | SPI_CR1_CPHA_Msk | SPI_CR1_CPOL_Msk);
	reg |= config.mode << SPI_CR1_CPHA_Pos | div << SPI_CR1_BR_Pos;
	mPeri->CR1 = reg;
#endif

	return true;
}

bool Spi::init(void)
{
	setSpiEn(mPeri, false);
	setSpiDff(mPeri, false);
	setSpiMsbfirst(mPeri);
	setSpiSsi(mPeri, true);
	setSpiSsm(mPeri, true);
	setSpiMstr(mPeri, true);
	setSpiTxeie(mPeri, true);
	setSpiRxneie(mPeri, true);

#if defined(STM32F4) || defined(STM32F7)
	setSpiDmaRxEn(mPeri, true);
	setSpiDmaTxEn(mPeri, true);
#endif

	return true;
}

void Spi::enable(bool en)
{
	setSpiEn(mPeri, en);
}

bool Spi::send(void *src, unsigned int size, unsigned int timeout)
{
	bool rt = false;

	mTxDma->lock();
#if defined(STM32F1)
	setSpiDmaTxEn(mPeri, true);
#endif

	rt = mTxDma->send(mTxDmaInfo, src, size, timeout);

	if (rt)
	{
		thread::yield();
		while (mPeri->SR & SPI_SR_BSY_Msk)
			thread::yield();
	}

#if defined(STM32F1)
	setSpiDmaTxEn(mPeri, false);
#endif
	mTxDma->unlock();

	return rt;
}

bool Spi::exchange(void *des, unsigned int size, unsigned int timeout)
{
	bool rt = false;

	mPeri->DR;

	mRxDma->lock();
	mTxDma->lock();

#if defined(STM32F1)
	setSpiDmaRxEn(mPeri, true);
	setSpiDmaTxEn(mPeri, true);
#endif

	mRxDma->pendRx(mRxDmaInfo, des, size);
	rt = mTxDma->send(mTxDmaInfo, des, size, timeout);

	if (rt)
	{
		thread::yield();
		while (mPeri->SR & SPI_SR_BSY_Msk)
			thread::yield();
	}

#if defined(STM32F1)
	setSpiDmaRxEn(mPeri, false);
	setSpiDmaTxEn(mPeri, false);
#endif

	mRxDma->stop();
	mRxDma->unlock();
	mTxDma->unlock();

	return rt;
}

unsigned char Spi::exchange(unsigned char data)
{
	while (~mPeri->SR & SPI_SR_TXE_Msk)
		thread::yield();
	mPeri->DR = data;
	thread::yield();
	while (mPeri->SR & SPI_SR_BSY_Msk)
		thread::yield();

	return mPeri->DR;
}

void Spi::send(char data)
{
	while (~mPeri->SR & SPI_SR_TXE_Msk)
		thread::yield();
	mPeri->DR = data;
	thread::yield();
	while (mPeri->SR & SPI_SR_BSY_Msk)
		thread::yield();
}

void Spi::send(unsigned char data)
{
	while (~mPeri->SR & SPI_SR_TXE_Msk)
		thread::yield();
	mPeri->DR = data;
	thread::yield();
	while (mPeri->SR & SPI_SR_BSY_Msk)
		thread::yield();
}

}

#endif
////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(GD32F10X_XD) || defined(GD32F10X_HD)

#include <__cross_studio_io.h>

#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <yss/thread.h>
#include <yss/reg.h>

namespace drv
{
Spi::Spi(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mGetClockFreq = config.getClockFreq;
	mPeri = config.peri;
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = config.rxDmaInfo;
	mLastConfig = 0;
	SDIO;
}

//Spi::Spi(SPI_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), Stream *txStream, Stream *rxStream, unsigned char txChannel, unsigned char rxChannel, unsigned short priority, unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
//{
//	this->set(txChannel, rxChannel, (void *)&(peri->DTR), (void *)&(peri->DTR), priority);

//	mGetClockFreq = getClockFreq;
//	mTxStream = txStream;
//	mRxStream = rxStream;
//	mPeri = peri;
//	mLastConfig = 0;
//}

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

	switch(config.bit)
	{
	case bit::BIT8 :
		buf = 0;
		break;
	case bit::BIT16 :
		buf = 1;
		break;
	default :
		buf = 0;
	}

	reg = mPeri->CTLR1;
	reg &= ~(SPI_CTLR1_PSC | SPI_CTLR1_SCKPH | SPI_CTLR1_SCKPL | SPI_CTLR1_FF16);
	reg |= config.mode << 0 | div << 3 | buf << 11;
	mPeri->CTLR1 = reg;

	return true;
}

bool Spi::init(void)
{
	setBitData(mPeri->CTLR1, false, 6);	// SPI 비활성화

	mPeri->CTLR1 |= SPI_CTLR1_SWNSS | SPI_CTLR1_SWNSSEN | SPI_CTLR1_MSTMODE;

	return true;
}

void Spi::enable(bool en)
{
	setBitData(mPeri->CTLR1, en, 6);	// SPI 비활성화
}

bool Spi::send(void *src, unsigned int size, unsigned int timeout)
{
	bool rt = false;

	mTxDma->lock();
	mPeri->CTLR2 |= SPI_CTLR2_DMATE;

	rt = mTxDma->send(mTxDmaInfo, src, size, timeout);

	if (rt)
	{
		thread::yield();
		while (mPeri->STR & SPI_STR_TRANS)
			thread::yield();
	}

	mPeri->CTLR2 &= ~SPI_CTLR2_DMATE;
	mTxDma->unlock();

	return rt;
}

bool Spi::exchange(void *des, unsigned int size, unsigned int timeout)
{
	bool rt = false;

	mPeri->DTR;

	mRxDma->lock();
	mTxDma->lock();

	mPeri->CTLR2 |= SPI_CTLR2_DMATE | SPI_CTLR2_DMARE;

	mRxDma->ready(mRxDmaInfo, des, size);
	rt = mTxDma->send(mTxDmaInfo, des, size, timeout);

	if (rt)
	{
		thread::yield();
		while (mPeri->STR & SPI_STR_TRANS)
			thread::yield();
	}

	mPeri->CTLR2 &= ~(SPI_CTLR2_DMATE | SPI_CTLR2_DMARE);

	mRxDma->stop();
	mRxDma->unlock();
	mTxDma->unlock();

	return rt;
}

unsigned char Spi::exchange(unsigned char data)
{
	while (mPeri->STR & SPI_STR_TRANS)
		thread::yield();
	mPeri->DTR = data;
	thread::yield();
	while (mPeri->STR & SPI_STR_TRANS)
		thread::yield();

	return mPeri->DTR;
}

void Spi::send(char data)
{
	while (mPeri->STR & SPI_STR_TRANS)
		thread::yield();
	mPeri->DTR = data;
}

void Spi::send(unsigned char data)
{
	while (mPeri->STR & SPI_STR_TRANS)
		thread::yield();
	mPeri->DTR = data;
	thread::yield();
	while (mPeri->STR & SPI_STR_TRANS)
		thread::yield();
}

}

#endif
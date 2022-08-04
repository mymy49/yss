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

#if defined(GD32F4)

//#include <__cross_studio_io.h>

#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <util/Timeout.h>

enum
{
	CTL0 = 0, CTL1, STAT, DATA, CRCPOLY, RCRC, TCRC, I2SCTL, I2SPSC, QCTL
};

Spi::Spi(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = config.rxDmaInfo;
	mLastSpec = 0;
	SDIO;
}

bool Spi::setSpecification(const Specification &spec)
{
	unsigned int reg, buf;

	if (mLastSpec == &spec)
		return true;
	mLastSpec = &spec;

	unsigned int mod;
	unsigned int div, clk = Drv::getClockFrequency();

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
		return false;
	
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
		buf = 0;
	}

	reg = mPeri[CTL0];
	reg &= ~(SPI_CTL0_PSC | SPI_CTL0_CKPL | SPI_CTL0_CKPH | SPI_CTL0_FF16);
	reg |= spec.mode << 0 | div << 3 | buf << 11;
	mPeri[CTL0] = reg;

	return true;
}

bool Spi::init(void)
{
	setBitData(mPeri[CTL0], false, 6);	// SPI 비활성화

	mPeri[CTL0] |= SPI_CTL0_SWNSS | SPI_CTL0_SWNSSEN | SPI_CTL0_MSTMOD;
	mPeri[CTL1] |= SPI_CTL1_DMATEN | SPI_CTL1_DMAREN;
	return true;
}

void Spi::enable(bool en)
{
	if(en)
		mPeri[CTL0] |= SPI_CTL0_SPIEN;
	else
		mPeri[CTL0] &= ~SPI_CTL0_SPIEN;
}

error Spi::send(void *src, int size)
{
	error result;

	mTxDma->lock();

	result = mTxDma->transfer(mTxDmaInfo, src, size);
	if (result == Error::NONE)
	{
		__ISB();
		while (mPeri[STAT] & SPI_STAT_TRANS)
			thread::yield();
	}

	mTxDma->unlock();

	return result;
}

error Spi::exchange(void *des, int size)
{
	error result;

	mPeri[DATA];

	mRxDma->lock();
	mTxDma->lock();

	mRxDma->ready(mRxDmaInfo, des, size);
	result = mTxDma->transfer(mTxDmaInfo, des, size);

	if (result == Error::NONE)
	{
		__ISB();
		while (mPeri[STAT] & SPI_STAT_TRANS)
			thread::yield();
	}

	mRxDma->stop();
	mRxDma->unlock();
	mTxDma->unlock();

	return result;
}

char Spi::exchange(char data)
{
	mPeri[DATA] = data;
	__ISB();
	while (mPeri[STAT] & SPI_STAT_TRANS)
		thread::yield();

	return mPeri[DATA];
}

void Spi::send(char data)
{
	mPeri[DATA] = data;
	__ISB();
	while (mPeri[STAT] & SPI_STAT_TRANS)
		thread::yield();
}

#endif


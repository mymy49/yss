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

#warning "GD32, STM32의 F1, F4, F7 드라이버를 이 한 파일에 전부 통합 예정

#include <drv/mcu.h>

#if defined(GD32F1)

#if defined(GD32F1)
#include <drv/spi/register_spi_gd32f1_f4.h>
#include <cmsis/mcu/gd32f10x.h>
#endif

#include <drv/Spi.h>
#include <yss/thread.h>
#include <yss/reg.h>

Spi::Spi(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = config.rxDmaInfo;
	mLastSpec = 0;
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

	reg = mPeri[CTLR1];
	reg &= ~(SPI_CTLR1_PSC | SPI_CTLR1_SCKPH | SPI_CTLR1_SCKPL | SPI_CTLR1_FF16);
	reg |= spec.mode << 0 | div << 3 | buf << 11;
	mPeri[CTLR1] = reg;

	mDelayTime = 9000000 / (clk / (2 << div));

	mPeri[DTR];

	return true;
}

bool Spi::init(void)
{
	setBitData(mPeri[CTLR1], false, 6);	// SPI 비활성화

	mPeri[CTLR1] |= SPI_CTLR1_SWNSS | SPI_CTLR1_SWNSSEN | SPI_CTLR1_MSTMODE;

	return true;
}

void Spi::enable(bool en)
{
	setBitData(mPeri[CTLR1], en, 6);	// SPI 비활성화
}

error Spi::send(void *src, int size)
{
	error result;

	mTxDma->lock();
	mPeri[CTLR2] = SPI_CTLR2_DMATE;
	mThreadId = thread::getCurrentThreadNum();

	result = mTxDma->send(mTxDmaInfo, src, size);
	mTxDma->unlock();
	
	if(mPeri[STR] & SPI_STR_TRANS)
	{
		mPeri[DTR];
		mPeri[CTLR2] = SPI_CTLR2_RBNEIE;
		while(mPeri[STR] & SPI_STR_TRANS)
			thread::yield();
	}
	
	mPeri[DTR];
	
	return result;
}

error Spi::exchange(void *des, int size)
{
	bool rt = false;

	mPeri[DTR];

	mRxDma->lock();
	mTxDma->lock();

	mPeri[CTLR2] = SPI_CTLR2_DMATE | SPI_CTLR2_DMARE;

	mRxDma->ready(mRxDmaInfo, des, size);
	rt = mTxDma->send(mTxDmaInfo, des, size);
	
	while(!mRxDma->isComplete())
		thread::yield();

	mPeri[CTLR2] = 0;

	mRxDma->stop();
	mRxDma->unlock();
	mTxDma->unlock();

	return rt;
}

char Spi::exchange(char data)
{
	mThreadId = thread::getCurrentThreadNum();
	mPeri[CTLR2] = SPI_CTLR2_RBNEIE;
	mPeri[DTR] = data;
	while (~mPeri[STR] & SPI_STR_RBNE)
		thread::yield();

	return mPeri[DTR];
}

void Spi::send(char data)
{
	mPeri[DTR];
	mThreadId = thread::getCurrentThreadNum();
	mPeri[CTLR2] = SPI_CTLR2_RBNEIE;
	mPeri[DTR] = data;
	while (~mPeri[STR] & SPI_STR_RBNE)
		thread::yield();

	mPeri[DTR];
}

void Spi::isr(void)
{
	mPeri[CTLR2] = 0;
	thread::signal(mThreadId);
}

#endif

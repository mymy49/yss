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

#include <drv/peripheral.h>

#if defined(GD32F450)

#include <drv/Timer.h>
#include <yss/reg.h>

enum
{
	CTL0 = 0, CTL1, SMCFG, DMAINTEN, INTF, SWEVG, CHCTL0, CHCTL1, CHCTL2, CNT, PSC, CAR
};

namespace drv
{
Timer::Timer(YSS_TIMER_Peri *peri, const Drv::Config drvConfig) : Drv(drvConfig)
{
	mPeri = peri;
	mIsrUpdate = 0;
	mTimeUpdateCnt = 0;
}
void Timer::initSystemTime(void)
{
	mPeri[PSC] = (unsigned short)(Drv::getClockFrequency() / 1000000) - 1;
	mPeri[CAR] = 60000;
	mPeri[CNT] = 60000;
	mPeri[DMAINTEN] |= TIMER_DMAINTEN_UPIE;
}

void Timer::init(unsigned int psc, unsigned int arr)
{
	mPeri[PSC] = (unsigned short)psc;
	mPeri[CAR] = (unsigned short)arr;
}

void Timer::init(unsigned int freq)
{
	unsigned int psc, arr, clk = mGetClockFreq();

	arr = clk / freq;
	psc = arr / (0xffff + 1);
	arr /= psc + 1;

	mPeri[PSC] = psc;
	mPeri[CAR] = arr;
}

unsigned int Timer::getTop(void)
{
	return mPeri[CAR];
}

void Timer::setUpdateIntEn(bool en)
{
	setBitData(mPeri[DMAINTEN], en, 0);	// Update Interrupt Enable
}

void Timer::start(void)
{
	setBitData(mPeri[CTL0], true, 0);	// Timer Enable
}

void Timer::stop(void)
{
	setBitData(mPeri[CTL0], false, 0);	// Timer Diable
}

unsigned int Timer::getCounterValue(void)
{
	return mPeri[CNT];
}

unsigned int Timer::getOverFlowCount(void)
{
	return 60000;
}

void drv::Timer::setUpdateIsr(void (*isr)(void))
{
	mIsrUpdate = isr;
}

void drv::Timer::isrUpdate(void)
{
	if (mIsrUpdate)
		mIsrUpdate();
	mTimeUpdateCnt++;
}

}
#endif
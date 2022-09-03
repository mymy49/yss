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

#if defined(GD32F1)

#if defined(GD32F1)
#include <drv/timer/register_timer_gd_stm32_f1_f4_f7.h>
#endif

#include <drv/peripheral.h>
#include <drv/Timer.h>
#include <yss/reg.h>

Timer::Timer(YSS_TIMER_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), uint32_t (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
	mPeri = peri;
	mGetClockFreq = getClockFreq;
	mIsrUpdate = 0;
	mTimeUpdateCnt = 0;
}

void Timer::initSystemTime(void)
{
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	mPeri[PSC] = (uint16_t)(mGetClockFreq() / 1000000) - 1;
#else
	mPeri[PSC] = (uint16_t)(mGetClockFreq() / 1000) - 1;
#endif
	mPeri[CARL] = 60000;
	mPeri[CNT] = 60000;
	setBitData(mPeri[DIE], true, 0);	// Update Interrupt Enable
}

void Timer::init(uint32_t psc, uint32_t arr)
{
	mPeri[PSC] = (uint16_t)psc;
	mPeri[CARL] = (uint16_t)arr;
}

void Timer::init(uint32_t freq)
{
	uint32_t psc, arr, clk = mGetClockFreq();

	arr = clk / freq;
	psc = arr / (0xffff + 1);
	arr /= psc + 1;

	mPeri[PSC] = psc;
	mPeri[CARL] = arr;
}

uint32_t Timer::getTop(void)
{
	return mPeri[CARL];
}

void Timer::setUpdateIntEn(bool en)
{
	setBitData(mPeri[DIE], en, 0);	// Update Interrupt Enable
}

void Timer::start(void)
{
	setBitData(mPeri[CTLR1], true, 0);	// Timer Enable
}

void Timer::stop(void)
{
	setBitData(mPeri[CTLR1], false, 0);	// Timer Diable
}

uint32_t Timer::getCounterValue(void)
{
	return mPeri[CNT];
}

uint32_t Timer::getOverFlowCount(void)
{
	return 60000;
}

void Timer::setUpdateIsr(void (*isr)(void))
{
	mIsrUpdate = isr;
}

void Timer::isrUpdate(void)
{
	if (mIsrUpdate)
		mIsrUpdate();
	mTimeUpdateCnt++;
}

#endif


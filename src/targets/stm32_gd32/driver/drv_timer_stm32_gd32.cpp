////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F1) || defined(STM32F4) || defined(GD32F4) || defined(STM32F7) || defined(STM32L1) || defined(STM32F0) || defined(STM32G4)

#include <drv/peripheral.h>
#include <drv/Timer.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/timer_stm32_gd32.h>

Timer::Timer(YSS_TIMER_Dev *dev, const Drv::Config drvConfig) : Drv(drvConfig)
{
	mDev = dev;
	mIsrUpdate = 0;
	mTimeUpdateCnt = 0;
}

void Timer::initializeAsSystemRuntime(void)
{
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	mDev[TIM_REG::PSC] = (uint16_t)(getClockFrequency() / 1000000) - 1;
#else
	mDev[TIM_REG::PSC] = (uint16_t)(getClockFrequency() / 1000) - 1;
#endif
	mDev[TIM_REG::ARR] = 60000;
	mDev[TIM_REG::CNT] = 60000;
}

void Timer::initialize(uint32_t psc, uint32_t arr)
{
	mDev[TIM_REG::PSC] = (uint16_t)psc;
	mDev[TIM_REG::ARR] = (uint16_t)arr;
}

void Timer::initialize(uint32_t freq)
{
	uint32_t psc, arr, clk = getClockFrequency();

	arr = clk / freq;
	psc = arr / (0xffff + 1);
	arr /= psc + 1;

	mDev[TIM_REG::PSC] = psc;
	mDev[TIM_REG::ARR] = arr;
}

void Timer::enableUpdateInterrupt(bool en)
{
	setBitData(mDev[TIM_REG::DIER], en, 0);	// Update Interrupt Enable
}

void Timer::start(void)
{
	setBitData(mDev[TIM_REG::CR1], true, 0);	// Timer Enable
}

void Timer::stop(void)
{
	setBitData(mDev[TIM_REG::CR1], false, 0);	// Timer Diable
}

uint32_t Timer::getCounterValue(void)
{
	return mDev[TIM_REG::CNT];
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


/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4) || defined(STM32F7) || defined(STM32F0) || defined(GD32F1) || defined (STM32F1) || defined(STM32G4)

#include <drv/peripheral.h>
#include <drv/Timer.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Timer::Timer(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mIsrUpdate = 0;
}

void Timer::initializeAsSystemRuntime(void)
{
	mDev->PSC = (uint16_t)(getClockFrequency() / 1000000) - 1;
	mDev->ARR = 60000;
	setBitData(mDev->DIER, true, TIM_DIER_UIE_Pos);	// Update Interrupt Enable
#if defined(STM32F7) || defined(STM3G4)
	setBitData(mDev->CR1, true, TIM_CR1_UIFREMAP_Pos);
#endif
}

void Timer::initialize(uint32_t psc, uint32_t top)
{
	mDev->PSC = (uint16_t)psc;
	mDev->ARR = (uint16_t)top;
	setBitData(mDev->DIER, true, TIM_DIER_UIE_Pos);	// Update Interrupt Enable
}

void Timer::initialize(uint32_t freq)
{
	uint32_t psc, arr, clk = getClockFrequency();

	arr = clk / freq;
	psc = arr / (0xffff + 1);
	arr /= psc + 1;

	mDev->PSC = psc;
	mDev->ARR = arr;
	setBitData(mDev->DIER, true, TIM_DIER_UIE_Pos);	// Update Interrupt Enable
	setBitData(mDev->CR1, true, TIM_CR1_ARPE_Pos);
}

void Timer::start(void)
{
	mDev->CNT = 1;
	setBitData(mDev->CR1, true, TIM_CR1_CEN_Pos);	// Timer Enable
}

void Timer::stop(void)
{
	setBitData(mDev->CR1, false, TIM_CR1_CEN_Pos);	// Timer Diable
}

uint32_t Timer::getCounterValue(void)
{
	return mDev->CNT;
}

uint32_t Timer::getOverFlowCount(void)
{
	return 60000;
}

void Timer::setOnePulse(bool en)
{
	setBitData(mDev->CR1, en, TIM_CR1_OPM_Pos);
}

void Timer::changeFrequency(uint32_t freq)
{
	uint32_t psc, arr, clk = getClockFrequency();

	arr = clk / freq;
	psc = arr / (0xffff + 1);
	arr /= psc + 1;

	mDev->PSC = psc;
	mDev->ARR = arr;
}

#endif


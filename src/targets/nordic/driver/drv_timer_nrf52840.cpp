/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <drv/Timer.h>
#include <yss/reg.h>
#include <targets/nordic/nrf52840_bitfields.h>

Timer::Timer(YSS_TIMER_Dev *dev, const Drv::setup_t drvConfig) : Drv(drvConfig)
{
	mDev = dev;
	mIsrUpdate = 0;
}

void Timer::initializeAsSystemRuntime(void)
{
	mDev->MODE = 0;			// Timer Mode
	mDev->BITMODE = 3;			// 32bit
	mDev->PRESCALER = 4;		// 1 MHz
	mDev->SHORTS = 0x01;		// CC[0] 설정
	mDev->CC[0] = 0xFFFFFFFF;
}

void Timer::initialize(uint32_t psc, uint32_t arr)
{
	mDev->MODE = 0;			// Timer Mode
	mDev->BITMODE = 3;			// 32bit
	mDev->PRESCALER = 0;		// 16 MHz
	mDev->CC[0] = arr;
	mDev->SHORTS = 0x01;		// CC[0] 설정
}

void Timer::initialize(uint32_t freq)
{
	uint32_t psc, arr, clk = 16000000;

	arr = clk / freq;

	mDev->MODE = 0;			// Timer Mode
	mDev->BITMODE = 3;			// 32bit
	mDev->PRESCALER = 0;		// 16 MHz
	mDev->CC[0] = arr;
	mDev->SHORTS = 0x01;		// CC[0] 설정
}

void Timer::enableUpdateInterrupt(bool en)
{
	if(en)
		mDev->INTENSET = TIMER_INTENSET_COMPARE0_Msk;	// CC[0] 활성화
	else
		mDev->INTENCLR = TIMER_INTENCLR_COMPARE0_Msk;	// CC[0] 비활성화
}

void Timer::start(void)
{
	mDev->TASKS_START = 1;
}

void Timer::stop(void)
{
	mDev->TASKS_STOP = 1;
}

uint32_t Timer::getCounterValue(void)
{
	mDev->TASKS_CAPTURE[1] = 1;
	return mDev->CC[1];
}

uint32_t Timer::getOverFlowCount(void)
{
	return 0xFFFFFFFF;
}

void Timer::setUpdateIsr(void (*isr)(void))
{
	mIsrUpdate = isr;
}

void Timer::isrUpdate(void)
{
	if (mIsrUpdate)
		mIsrUpdate();
}

#endif
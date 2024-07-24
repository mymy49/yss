/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(EFM32PG22) || defined(EFR32BG22)

#include <drv/peripheral.h>
#include <drv/Timer.h>
#include <yss/reg.h>

#if defined(EFM32PG22)
#include <targets/siliconlabs/efm32pg22_timer.h>
#elif defined(EFR32BG22)
#include <targets/siliconlabs/efr32bg22_timer.h>
#endif

static uint32_t gDivider = 1;

Timer::Timer(const Drv::setup_t drvSetup, const Setup setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mBit = setup.bit;
	mIsrUpdate = 0;
}

Timer::Timer(YSS_TIMER_Dev *dev, const Drv::setup_t drvConfig) : Drv(drvConfig)
{
	mDev = dev;
	mBit = BIT::BIT_16;
	mIsrUpdate = 0;
}

void Timer::initializeAsSystemRuntime(void)
{
	uint32_t clk = getClockFrequency();

	setFieldData(mDev->CFG, _TIMER_CFG_PRESC_MASK, clk / 1000000 - 1, _TIMER_CFG_PRESC_SHIFT);

	mDev->EN_SET = TIMER_EN_EN;

	if(mBit == BIT::BIT_32)
		mDev->TOP = 0xFFFFFFFF;
	else
		mDev->TOP = 0xFFFF;
}

void Timer::initialize(uint32_t psc, uint32_t arr)
{
	setFieldData(mDev->CFG, _TIMER_CFG_PRESC_MASK, psc, _TIMER_CFG_PRESC_SHIFT);

	mDev->TOP = arr;

	mDev->EN_SET = TIMER_EN_EN;
}

void Timer::initialize(uint32_t freq)
{
	uint32_t clk = getClockFrequency();
	uint32_t psc = 1024, top;
	
	top = clk / freq;
	while(psc)
	{
		if(top % psc == 0)
		{
			clk /= psc;
			psc--;
			break;
		}
		psc--;
	}

	setFieldData(mDev->CFG, _TIMER_CFG_PRESC_MASK, psc, _TIMER_CFG_PRESC_SHIFT);
	mDev->EN_SET = TIMER_EN_EN;
	mDev->TOP = clk / freq - 1;
}

void Timer::enableUpdateInterrupt(bool en)
{
	setBitData(mDev->IEN, en, _TIMER_IEN_OF_SHIFT);
}

void Timer::start(void)
{
	mDev->CMD_SET = _TIMER_CMD_START_MASK;
}

void Timer::stop(void)
{
	mDev->CMD_SET = _TIMER_CMD_STOP_MASK;
}

uint32_t Timer::getCounterValue(void)
{
	return mDev->CNT;
}

uint32_t Timer::getOverFlowCount(void)
{
	if(mBit == BIT::BIT_32)
		return 0xFFFFFFFF;
	else
		return 0xFFFF;
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


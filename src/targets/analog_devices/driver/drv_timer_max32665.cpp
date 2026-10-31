/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__MAX32665_FAMILY)

#include <targets/analog_devices/Max32665Timer.h>
#include <yss/reg.h>

/**
 * @file drv_gpio_nuvoton.cpp
 * @brief GPIO target-specific driver source file for Nuvoton.
 */

Max32665Timer::Max32665Timer(const Drv::setup_t drvSetup, const setup_t setup) : Timer(drvSetup)
{
	mDev = setup.dev;
}

error_t Max32665Timer::initialize(uint32_t freq)
{
	if(freq == 0)
		return error_t::WRONG_CLOCK_FREQUENCY;

	uint32_t clk = getClockFrequency();
	
	mDev->cmp = clk / freq;

	setFieldData(mDev->cn, MXC_F_TMR_CN_TMODE, MXC_V_TMR_CN_TMODE_CONTINUOUS, MXC_F_TMR_CN_TMODE_POS);

	return error_t::ERROR_NONE;
}

error_t Max32665Timer::initializeAsPwm(uint32_t freq)
{
	if(freq == 0)
		return error_t::WRONG_CLOCK_FREQUENCY;

	uint32_t clk = getClockFrequency();
	
	mDev->cmp = clk / freq;

	setFieldData(mDev->cn, MXC_F_TMR_CN_TMODE, MXC_V_TMR_CN_TMODE_PWM, MXC_F_TMR_CN_TMODE_POS);
	mDev->pwm = 0;
	
	return error_t::ERROR_NONE;
}

void Max32665Timer::setOnePulse(bool en)
{
}

void Max32665Timer::start(void)
{
	mDev->cn |= MXC_F_TMR_CN_TEN;
}

void Max32665Timer::stop(void)
{
	mDev->cn &= ~MXC_F_TMR_CN_TEN;
}

uint32_t Max32665Timer::getCounterValue(void)
{
	return mDev->cnt;
}

uint32_t Max32665Timer::getTopValue(void)
{
	return mDev->cmp;
}

void Max32665Timer::setDutyRatio(float ratio)
{
	int32_t value = (mDev->cmp - 2) * ratio + 1;
	
	if(value <= 1)
		value = 1;
	else if(value >= mDev->cmp)
		value = mDev->cmp - 1;

	mDev->pwm = value;
}

void Max32665Timer::setCompareValue(uint32_t  counter)
{
	mDev->pwm = counter;
}

error_t Max32665Timer::changeFrequency(uint32_t freq)
{
	
	return error_t::ERROR_NONE;
}

#endif


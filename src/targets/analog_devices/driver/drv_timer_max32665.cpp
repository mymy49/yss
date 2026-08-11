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
	uint32_t clk = getClockFrequency();
	
	mDev->cmp = clk / freq;

	setFieldData(mDev->cn, MXC_F_TMR_CN_TMODE, MXC_V_TMR_CN_TMODE_CONTINUOUS, MXC_F_TMR_CN_TMODE_POS);

	mDev->cn |= MXC_F_TMR_CN_TEN;
	
	return error_t::ERROR_NONE;
}

void Max32665Timer::setOnePulse(bool en)
{

}

void Max32665Timer::start(void)
{

}

void Max32665Timer::stop(void)
{

}

uint32_t Max32665Timer::getCounterValue(void)
{
	return mDev->cnt;
}

error_t Max32665Timer::changeFrequency(uint32_t freq)
{
	
	return error_t::ERROR_NONE;
}

#endif


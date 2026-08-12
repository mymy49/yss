/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <targets/nordic/nRF52_Timer.h>
#include <yss/reg.h>
#include <nrf52840_bitfields.h>

/**
 * @file drv_gpio_nuvoton.cpp
 * @brief GPIO target-specific driver source file for Nuvoton.
 */

nRF52_Timer::nRF52_Timer(const Drv::setup_t drvSetup, const setup_t setup) : Timer(drvSetup)
{
	mDev = setup.dev;
}

error_t nRF52_Timer::initialize(uint32_t freq)
{
	if(freq == 0)
		return error_t::WRONG_CLOCK_FREQUENCY;

	uint32_t clk = getClockFrequency();

	mDev->MODE = 0;			// Timer Mode
	mDev->BITMODE = 3;		// 32bit
	mDev->PRESCALER = 0;	// 16 MHz
	mDev->SHORTS =  TIMER_SHORTS_COMPARE0_CLEAR_Msk;
	mDev->CC[0] = clk / freq;
	mDev->INTENSET = TIMER_INTENSET_COMPARE0_Msk;
	
	return error_t::ERROR_NONE;
}

void nRF52_Timer::setOnePulse(bool en)
{
	mDev->SHORTS = TIMER_SHORTS_COMPARE0_STOP_Msk;
}

void nRF52_Timer::start(void)
{
	mDev->TASKS_START = 1;
}

void nRF52_Timer::stop(void)
{
	mDev->TASKS_STOP = 1;
}

uint32_t nRF52_Timer::getCounterValue(void)
{
	mDev->TASKS_CAPTURE[1] = 1;
	return mDev->CC[1];
}

error_t nRF52_Timer::changeFrequency(uint32_t freq)
{
	if(freq == 0)
		return error_t::WRONG_CLOCK_FREQUENCY;

	mDev->CC[0] = getClockFrequency() / freq;
	mDev->TASKS_CLEAR = 1;
	
	return error_t::ERROR_NONE;
}

#endif


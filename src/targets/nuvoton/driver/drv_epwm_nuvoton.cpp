/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <targets/nuvoton/NuvotonEpwm.h>
#include <yss/reg.h>

/**
 * @file drv_epwm_nuvoton.cpp
 * @brief EPWM (Enhanced PWM) target-specific driver source file for Nuvoton.
 */

NuvotonEpwm::NuvotonEpwm(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	// Store references to peripheral and clock selection callbacks.
	mDev = setup.dev;
	mGetClock01Func = setup.getClock01Func;
	mGetClock23Func = setup.getClock23Func;
	mGetClock45Func = setup.getClock45Func;
}

error_t NuvotonEpwm::initialize(uint8_t ch, uint32_t freq)
{
	// Initialize frequency for the target EPWM channel.
	error_t result = changeFrequency(ch, freq);

	return error_t::ERROR_NONE;
}

error_t NuvotonEpwm::changeFrequency(uint8_t ch, uint32_t freq)
{
	if(ch >= 6)
		return error_t::OUT_OF_CHANNEL;

	int32_t psc, period, clk;

	// Query target clock based on the channel group (01, 23, 45).
	switch(ch)
	{
	case 0 :
	case 1 :
		clk = mGetClock01Func();
		break;

	case 2 :
	case 3 :
		clk = mGetClock23Func();
		break;

	case 4 :
	case 5 :
		clk = mGetClock45Func();
		break;
	}

	// Calculate and scale timer period.
	period = clk / freq;
	if(period > 0xFFFF)
	{
		psc = period / (0xFFFF);
		if(psc > 0xFFF)
			return error_t::OVERFLOW;
	}
	else
		psc = 0;

	clk /= psc + 1;
	period = clk / freq;

	if(period > 0xFFFF)
		return error_t::OVERFLOW;
	
	// Apply settings to hardware registers.
	mDev->PERIOD[ch] = period;
	mDev->PERIOD[ch] = period;
	mDev->CLKPSC[ch >> 1] = psc;

	return error_t::ERROR_NONE;
}

error_t NuvotonEpwm::start(uint8_t ch)
{
	if(ch >= 6)
		return error_t::OUT_OF_CHANNEL;

	// Enable the designated EPWM counter.
	setBitData(mDev->CNTEN, true, ch);

	return error_t::ERROR_NONE;
}

error_t NuvotonEpwm::stop(uint8_t ch)
{
	if(ch >= 6)
		return error_t::OUT_OF_CHANNEL;

	// Disable the designated EPWM counter.
	setBitData(mDev->CNTEN, false, ch);

	return error_t::ERROR_NONE;
}

error_t NuvotonEpwm::setAsPwmOutput(uint8_t ch, bool inverse)
{
	if(ch > 5)
		return error_t::OUT_OF_CHANNEL;
	
	// Enable pin output and set output polarity.
	setBitData(mDev->POEN, true, ch);
	setBitData(mDev->POLCTL, inverse, ch);

	// Configure output waveform behavior transitions.
	ch <<= 1;
	setFieldData(mDev->WGCTL0, 0x03 << ch, 2, ch);
	setFieldData(mDev->WGCTL1, 0x03 << ch, 1, ch);

	return error_t::ERROR_NONE;
}

error_t NuvotonEpwm::setDutyRatio(uint8_t ch, float ratio)
{
	if(ch > 5)
		return error_t::OUT_OF_CHANNEL;

	// Calculate target comparison value.
	int32_t period = mDev->PERIOD[ch], cmp = (float)period * ratio;

	if(cmp >= period)
		cmp = period;
	else if(cmp < 0)
		cmp = 0;
	
	// Set threshold value in comparison register.
	mDev->CMPDAT[ch] = cmp;

	return error_t::ERROR_NONE;
}

uint32_t NuvotonEpwm::getTopValue(uint8_t ch)
{
	if(ch > 5)
		return 0;
	else
		return mDev->PERIOD[ch];
}

error_t NuvotonEpwm::setCompareValue(uint8_t ch, int16_t  counter)
{
	if(ch > 5)
		return error_t::OUT_OF_RANGE;
	
	// Set the absolute comparison value threshold.
	mDev->CMPDAT[ch] = counter;

	return error_t::ERROR_NONE;
}

#endif



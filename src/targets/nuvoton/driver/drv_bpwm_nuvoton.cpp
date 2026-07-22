/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)

#include <targets/nuvoton/NuvotonBpwm.h>
#include <yss/reg.h>

/**
 * @file drv_bpwm_nuvoton.cpp
 * @brief BPWM (Basic PWM) target-specific driver source file for Nuvoton.
 */

NuvotonBpwm::NuvotonBpwm(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	// Store reference to the hardware register structure.
	mDev = setup.dev;
}

error_t NuvotonBpwm::initialize(uint32_t freq)
{
	// Configure frequency.
	error_t result = changeFrequency(freq);
	if(result != error_t::ERROR_NONE)
		return result;
	
	return error_t::ERROR_NONE;
}

error_t NuvotonBpwm::changeFrequency(uint32_t freq)
{
	int32_t psc, period, clk = getClockFrequency();

	// Calculate target timer period based on clock frequency.
	period = clk / freq;
	if(period > 0xFFFF)
	{
		// Scale prescaler value if period exceeds 16-bit range.
		psc = period / (0xFFFF);
		if(psc > 0xFFF)
			return error_t::OVERFLOW;
	}
	else
		psc = 0;

	// Calculate final scaled period.
	clk /= psc + 1;
	period = clk / freq;

	if(period > 0xFFFF)
		return error_t::OVERFLOW;
	
	// Apply calculated period and prescaler values to peripheral registers.
	mDev->PERIOD = period;
	mDev->CLKPSC = psc;

	return error_t::ERROR_NONE;
}

void NuvotonBpwm::start(void)
{
	// Enable Timer Counter of BPWM.
	setBitData(mDev->CNTEN, true, TIMER_PWMCTL_CNTEN_Pos);
}

void NuvotonBpwm::stop(void)
{
	// Disable Timer Counter of BPWM.
	setBitData(mDev->CNTEN, false, TIMER_PWMCTL_CNTEN_Pos);
}

error_t NuvotonBpwm::setAsPwmOutput(uint8_t ch, bool inverse)
{
	if(ch > 5)
		return error_t::OUT_OF_RANGE;
	
	// Enable pin output and set optional polarity inversion.
	setBitData(mDev->POEN, true, ch);
	setBitData(mDev->POLCTL, inverse, ch);

	// Configure output waveform generation logic.
	ch <<= 1;
	setFieldData(mDev->WGCTL0, 0x03 << ch, 2, ch);
	setFieldData(mDev->WGCTL1, 0x03 << ch, 1, ch);

	return error_t::ERROR_NONE;
}

uint32_t NuvotonBpwm::getTopValue(void)
{
	// Return the current top period count.
	return mDev->PERIOD;
}

error_t NuvotonBpwm::setDutyRatio(uint8_t ch, float ratio)
{
	if(ch > 5)
		return error_t::OUT_OF_RANGE;

	// Calculate and bound comparison threshold.
	int32_t period = mDev->PERIOD, cmp = (float)period * ratio;

	if(cmp >= period)
		cmp = period;
	else if(cmp < 0)
		cmp = 0;
	
	// Set the duty comparison register.
	mDev->CMPDAT[ch] = cmp;

	return error_t::ERROR_NONE;
}

error_t NuvotonBpwm::setCompareValue(uint8_t ch, int16_t  counter)
{
	if(ch > 5)
		return error_t::OUT_OF_RANGE;
	
	// Set the absolute comparison counter threshold.
	mDev->CMPDAT[ch] = counter;

	return error_t::ERROR_NONE;
}

#endif



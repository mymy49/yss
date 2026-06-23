/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M251_SUBFAMILY__)

#include <targets/nuvoton/NuvotonBpwm.h>
#include <yss/reg.h>

NuvotonBpwm::NuvotonBpwm(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
}

error_t NuvotonBpwm::initialize(uint32_t freq)
{
	error_t result = changeFrequency(freq);
	if(result != error_t::ERROR_NONE)
		return result;
	
	return error_t::ERROR_NONE;
}

error_t NuvotonBpwm::changeFrequency(uint32_t freq)
{
	int32_t psc, period, clk = getClockFrequency();

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
	
	mDev->PERIOD = period;
	mDev->CLKPSC = psc;

	return error_t::ERROR_NONE;
}

void NuvotonBpwm::start(void)
{
	setBitData(mDev->CNTEN, true, TIMER_PWMCTL_CNTEN_Pos);	// Timer Enable
}

void NuvotonBpwm::stop(void)
{
	setBitData(mDev->CNTEN, false, TIMER_PWMCTL_CNTEN_Pos);	// Timer Disable
}

error_t NuvotonBpwm::setAsPwmOutput(uint8_t ch, bool inverse)
{
	if(ch > 5)
		return error_t::OUT_OF_RANGE;
	
	setBitData(mDev->POEN, true, ch);
	setBitData(mDev->POLCTL, inverse, ch);

	ch <<= 1;
	setFieldData(mDev->WGCTL0, 0x03 << ch, 2, ch);
	setFieldData(mDev->WGCTL1, 0x03 << ch, 1, ch);

	return error_t::ERROR_NONE;
}

uint32_t NuvotonBpwm::getTopValue(void)
{
	return mDev->PERIOD;
}

error_t NuvotonBpwm::setDutyRatio(uint8_t ch, float ratio)
{
	if(ch > 5)
		return error_t::OUT_OF_RANGE;

	int32_t period = mDev->PERIOD, cmp = (float)period * ratio;

	if(cmp >= period)
		cmp = period;
	else if(cmp < 0)
		cmp = 0;
	
	mDev->CMPDAT[ch] = cmp;

	return error_t::ERROR_NONE;
}

error_t NuvotonBpwm::setCompareValue(uint8_t ch, int16_t  counter)
{
	if(ch > 5)
		return error_t::OUT_OF_RANGE;
	
	mDev->CMPDAT[ch] = counter;

	return error_t::ERROR_NONE;
}

#endif


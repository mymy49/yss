/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <drv/Epwm.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m4xx.h>

Epwm::Epwm(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mGetClock01Func = setup.getClock01Func;
	mGetClock23Func = setup.getClock23Func;
	mGetClock45Func = setup.getClock45Func;
}

error_t Epwm::initialize(uint8_t ch, uint32_t freq)
{
	error_t result = changeFrequency(ch, freq);

	return error_t::ERROR_NONE;
}

error_t Epwm::changeFrequency(uint8_t ch, uint32_t freq)
{
	if(ch >= 6)
		return error_t::OUT_OF_CHANNEL;

	int32_t psc, period, clk;

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
	
	mDev->PERIOD[ch] = period;
	mDev->PERIOD[ch] = period;
	mDev->CLKPSC[ch >> 1] = psc;

	return error_t::ERROR_NONE;
}

error_t Epwm::start(uint8_t ch)
{
	if(ch >= 6)
		return error_t::OUT_OF_CHANNEL;

	setBitData(mDev->CNTEN, true, ch);	// Timer Enable

	return error_t::ERROR_NONE;
}

error_t Epwm::stop(uint8_t ch)
{
	if(ch >= 6)
		return error_t::OUT_OF_CHANNEL;

	setBitData(mDev->CNTEN, false, ch);	// Timer Disable

	return error_t::ERROR_NONE;
}

error_t Epwm::setAsPwmOutput(uint8_t ch, bool inverse)
{
	if(ch > 5)
		return error_t::OUT_OF_CHANNEL;
	
	setBitData(mDev->POEN, true, ch);
	setBitData(mDev->POLCTL, inverse, ch);

	ch <<= 1;
	setFieldData(mDev->WGCTL0, 0x03 << ch, 2, ch);
	setFieldData(mDev->WGCTL1, 0x03 << ch, 1, ch);

	return error_t::ERROR_NONE;
}

error_t Epwm::setDutyRatio(uint8_t ch, float ratio)
{
	if(ch > 5)
		return error_t::OUT_OF_CHANNEL;

	int32_t period = mDev->PERIOD[ch], cmp = (float)period * ratio;

	if(cmp >= period)
		cmp = period;
	else if(cmp < 0)
		cmp = 0;
	
	mDev->CMPDAT[ch] = cmp;

	return error_t::ERROR_NONE;
}

uint32_t Epwm::getTopValue(uint8_t ch)
{
	if(ch > 5)
		return 0;
	else
		return mDev->PERIOD[ch];
}

error_t Epwm::setCompareValue(uint8_t ch, int16_t  counter)
{
	if(ch > 5)
		return error_t::OUT_OF_RANGE;
	
	mDev->CMPDAT[ch] = counter;

	return error_t::ERROR_NONE;
}

#endif


/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <drv/Pwm.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m4xx.h>

Pwm::Pwm(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
}

error_t Pwm::initialize(uint32_t psc, uint32_t top, bool risingAtMatch)
{
	setBitData(mDev->ALTCTL, true, TIMER_ALTCTL_FUNCSEL_Pos);

	if(psc > 0xFFF || top > 0xFFFF)
		return error_t::OVERFLOW;

	mDev->PWMCLKPSC = psc;
	mDev->PWMPERIOD = top;

	return initializeChannel(risingAtMatch);
}

error_t Pwm::changeFrequency(uint32_t freq)
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
	
	mDev->PWMPERIOD = period;
	mDev->PWMCLKPSC = psc;

	return error_t::ERROR_NONE;
}

error_t Pwm::initialize(uint32_t freq, bool risingAtMatch)
{
	setBitData(mDev->ALTCTL, true, TIMER_ALTCTL_FUNCSEL_Pos);

	error_t result = changeFrequency(freq);

	if(result != error_t::ERROR_NONE)
		return result;

	return initializeChannel(risingAtMatch);
}

uint32_t Pwm::getTopValue(void)
{
	return mDev->CMP;
}

void Pwm::start(void)
{
	setBitData(mDev->PWMCTL, true, TIMER_PWMCTL_CNTEN_Pos);	// Timer Enable
}

void Pwm::stop(void)
{
	setBitData(mDev->PWMCTL, false, TIMER_PWMCTL_CNTEN_Pos);	// Timer Disable
}

void Pwm::setOnePulse(bool en)
{
	setBitData(mDev->PWMCTL, en, TIMER_PWMCTL_CNTMODE_Pos);
}

PwmCh1::PwmCh1(const Drv::setup_t drvSetup, const setup_t setup) : Pwm(drvSetup, setup)
{
	
}

error_t PwmCh1::initializeChannel(bool risingAtMatch)
{
	setBitData(mDev->PWMPOEN, true, TIMER_PWMPOEN_POEN0_Pos);
	setBitData(mDev->PWMPOLCTL, risingAtMatch, TIMER_PWMPOLCTL_PINV0_Pos);

	return error_t::ERROR_NONE;
}

uint32_t PwmCh1::getTopValue(void)
{
	return mDev->PWMPERIOD;
}

void PwmCh1::setDutyRatio(float ratio)
{
	int32_t period = mDev->PWMPERIOD, cmp = (float)period * ratio;

	if(cmp >= period)
		cmp = period;
	else if(cmp < 0)
		cmp = 0;
	mDev->PWMCMPDAT = cmp;
}

void PwmCh1::setCompareValue(int32_t counter)
{
	int32_t period = mDev->PWMPERIOD;

	if(counter >= period)
		counter = period;
	else if(counter < 0)
		counter = 0;

	mDev->PWMCMPDAT = counter;
}

#endif


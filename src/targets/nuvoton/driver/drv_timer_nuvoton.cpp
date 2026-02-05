/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#include <yss.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonTmr.h>
#include <yss/thread.h>
#include <yss/reg.h>

NuvotonTmr::NuvotonTmr(const Drv::setup_t drvSetup, const setup_t setup) : Timer(drvSetup)
{
	mDev = setup.dev;
	mIsrUpdate = 0;
}

error_t NuvotonTmr::initialize(uint32_t freq)
{
	register uint32_t reg;
	error_t result;

	result = changeFrequency(freq);
	if(result != error_t::ERROR_NONE)
		return result;

	reg = mDev->CTL;
	reg |= TIMER_CTL_CNTEN_Msk | (1 << TIMER_CTL_OPMODE_Pos) | TIMER_CTL_INTEN_Msk;
	mDev->CTL = reg;

	return error_t::ERROR_NONE;
}

error_t NuvotonTmr::changeFrequency(uint32_t freq)
{
	int32_t psc, cmp, clk = getClockFrequency();

	cmp = clk / freq;
	if(cmp > 0xFFFFFF)
	{
		psc = cmp / (0xFFFFFF);
		if(psc > 0xFF)
			return error_t::OVERFLOW;
	}
	else
		psc = 0;

	clk /= psc + 1;
	cmp = clk / freq;
	if(cmp > 0)
		cmp--;

	setFieldData(mDev->CTL, TIMER_CTL_PSC_Msk, psc, TIMER_CTL_PSC_Pos);
	mDev->CMP = cmp;

	return error_t::ERROR_NONE;
}

void NuvotonTmr::start(void)
{
	mDev->CNT = 1;
	setBitData(mDev->CTL, true, TIMER_CTL_CNTEN_Pos);	// Timer Enable
}

void NuvotonTmr::stop(void)
{
	setBitData(mDev->CTL, false, TIMER_CTL_CNTEN_Pos);	// Timer Disable
}

void NuvotonTmr::setOnePulse(bool en)
{
	setBitData(mDev->PWMCTL, en, TIMER_PWMCTL_CNTMODE_Pos);
}

uint32_t NuvotonTmr::getCounterValue(void)
{
	return mDev->CNT;
}
#endif


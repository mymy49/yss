/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(W7500)

#include <drv/Timer.h>
#include <yss/reg.h>
#include <targets/wiznet/bitfield_w7500x.h>


Timer::Timer(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mIndex = setup.index;
}

void Timer::initialize(uint32_t freq)
{
	uint32_t clk = getClockFrequency();

	mDev->PDMR = PWM_CHn_PDMR_PDM;
	mDev->LR = (clk / freq) - 1;
	mDev->IER = PWM_CHn_IER_OIE;
}

void Timer::changeFrequency(uint32_t freq)
{
	uint32_t clk = getClockFrequency();

	stop();
	mDev->PDMR = PWM_CHn_PDMR_PDM;
	mDev->LR = clk / freq;
	mDev->PCR = 0;
	mDev->IER = PWM_CHn_IER_OIE;
	start();
}

void Timer::initialize(uint32_t psc, uint32_t top)
{
	mDev->PDMR = PWM_CHn_PDMR_PDM;
	mDev->LR = top;
	mDev->PR = psc & 0x3F;
	mDev->IER = PWM_CHn_IER_OIE;
}

void Timer::setOnePulse(bool en)
{
	if(en)
		mDev->PDMR = (~PWM_CHn_PDMR_PDM) & PWM_CHn_PDMR_PDM;		
	else
		mDev->PDMR = PWM_CHn_PDMR_PDM;	
}

void Timer::start(void)
{
	PWM->SSR |= 1 << mIndex;
}

void Timer::stop(void)
{
	PWM->SSR &= ~(1 << mIndex);
}

#endif


/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(W7500)

#include <drv/Pwm.h>
#include <yss/reg.h>
#include <targets/wiznet/bitfield_w7500x.h>


Pwm::Pwm(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mIndex = setup.index;
	mRisingAtMatch = false;
}

error_t Pwm::initialize(uint32_t psc, uint32_t top, bool risingAtMatch)
{
	if(psc > 63)
		return error_t::WRONG_CONFIG;
	
	mDev->PDMR = PWM_CHn_PDMR_PDM;
	mDev->PR = psc;
	mDev->LR = top;
	mDev->PEEER = PWM_CHn_PEEER_PEEE_1;
	mRisingAtMatch = risingAtMatch;

	return error_t::ERROR_NONE;
}

error_t Pwm::initialize(uint32_t freq, bool risingAtMatch)
{
	if(freq < 1)
		return error_t::WRONG_CONFIG;

	uint32_t clk = getClockFrequency();

	mDev->PDMR = PWM_CHn_PDMR_PDM;
	mDev->LR = (clk / freq) - 1;
	mDev->PEEER = PWM_CHn_PEEER_PEEE_1;
	mRisingAtMatch = risingAtMatch;

	return error_t::ERROR_NONE;
}

void Pwm::changeFrequency(uint32_t freq)
{
	uint32_t clk = getClockFrequency();

	stop();
	mDev->PDMR = PWM_CHn_PDMR_PDM;
	mDev->LR = clk / freq;
	mDev->PCR = 0;
	mDev->IER = PWM_CHn_IER_OIE;
	start();
}

void Pwm::setOnePulse(bool en)
{
	if(en)
		mDev->PDMR = (~PWM_CHn_PDMR_PDM) & PWM_CHn_PDMR_PDM;		
	else
		mDev->PDMR = PWM_CHn_PDMR_PDM;	
}

void Pwm::start(void)
{
	PWM->SSR |= 1 << mIndex;
}

void Pwm::stop(void)
{
	PWM->SSR &= ~(1 << mIndex);
}


uint32_t PwmCh1::getTopValue(void)
{
	return mDev->LR;
}

error_t PwmCh1::initializeChannel(bool risingAtMatch)
{
	return error_t::ERROR_NONE;
}

void PwmCh1::setRatio(float ratio)
{
	int32_t lr = mDev->LR, mr = (float)lr * ratio;

	if(mr >= lr)
		mr = lr;
	else if(mr < 0)
		mr = 0;

	PWM->SSR &= ~(1 << mIndex);
	if(mRisingAtMatch)
		mDev->MR = lr-mr;
	else
		mDev->MR = mr;
	PWM->SSR |= (1 << mIndex);
}

void PwmCh1::setCompareValue(int32_t counter)
{
	int32_t lr = mDev->LR;

	if(counter >= lr)
		counter = lr;
	else if(counter < 0)
		counter = 0;

	PWM->SSR &= ~(1 << mIndex);
	if(mRisingAtMatch)
		mDev->MR = lr-counter;
	else
		mDev->MR = counter;
	PWM->SSR |= (1 << mIndex);
}

PwmCh1::PwmCh1(const Drv::setup_t drvSetup, const setup_t setup) : Pwm(drvSetup, setup)
{
}

#endif


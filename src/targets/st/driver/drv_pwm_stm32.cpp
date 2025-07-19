/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(GD32F1) || defined(STM32F1) || defined (STM32F7) || defined(STM32F4)	

#include <drv/Pwm.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Pwm::Pwm(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) : Drv(drvSetup)
{
	mDev = peri;
}

error_t Pwm::initialize(uint32_t psc, uint32_t arr, bool risingAtMatch)
{
	mDev->PSC = psc;
	mDev->ARR = arr;

	return initializeChannel(risingAtMatch);
}

error_t Pwm::changeFrequency(uint32_t freq)
{
	uint32_t psc, arr, clk = getClockFrequency();

	arr = clk / freq;
	psc = arr / (0xffff + 1);
	arr /= psc + 1;

	mDev->PSC = psc;
	mDev->ARR = arr;

	return error_t::ERROR_NONE;
}

error_t Pwm::initialize(uint32_t freq, bool risingAtMatch)
{
	error_t result = changeFrequency(freq);

	if(result != error_t::ERROR_NONE)
		return result;

	return initializeChannel(risingAtMatch);
}

uint32_t Pwm::getTopValue(void)
{
	return mDev->ARR;
}

void Pwm::start(void)
{
	setBitData(mDev->CR1, true, 0);	// Timer Enable
}

void Pwm::stop(void)
{
	setBitData(mDev->CR1, false, 0);	// Timer Diable
}

void Pwm::setOnePulse(bool en)
{
	setBitData(mDev->CR1, en, TIM_CR1_OPM_Pos);
}

PwmCh1::PwmCh1(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) : Pwm(peri, drvSetup)
{
	
}

error_t PwmCh1::initializeChannel(bool risingAtMatch)
{
#if defined(TIM_BDTR_MOE_Pos)
	setBitData(mDev->BDTR, true, TIM_BDTR_MOE_Pos);						// Primary Output Enable
#endif
	setFieldData(mDev->CCMR1, TIM_CCMR1_CC1S_Msk, 0, TIM_CCMR1_CC1S_Pos);	// 출력으로 설정
	setBitData(mDev->CCMR1, true, TIM_CCMR1_OC1PE_Pos);					// Shadow 활성화
	setBitData(mDev->CCMR1, true, TIM_CCMR1_OC1FE_Pos);					// Fast 활성화
	setBitData(mDev->CCER, true, TIM_CCER_CC1E_Pos);						// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mDev->CCMR1, TIM_CCMR1_OC1M_Msk, 7, TIM_CCMR1_OC1M_Pos);
	else
		setFieldData(mDev->CCMR1, TIM_CCMR1_OC1M_Msk, 6, TIM_CCMR1_OC1M_Pos);

	return error_t::ERROR_NONE;
}

uint32_t PwmCh1::getTopValue(void)
{
	return mDev->ARR;
}

void PwmCh1::setDutyRatio(float ratio)
{
	int32_t arr = mDev->ARR, ccr = (float)arr * ratio;

	if(ccr >= arr)
		ccr = arr;
	else if(ccr < 0)
		ccr = 0;
	mDev->CCR1 = ccr;
}

void PwmCh1::setCompareValue(int32_t counter)
{
	int32_t arr = mDev->ARR;

	if(counter >= arr)
		counter = arr;
	else if(counter < 0)
		counter = 0;

	mDev->CCR1 = counter;
}

PwmCh2::PwmCh2(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) : Pwm(peri, drvSetup)
{
	
}

error_t PwmCh2::initializeChannel(bool risingAtMatch)
{
#if defined(TIM_BDTR_MOE_Pos)
	setBitData(mDev->BDTR, true, TIM_BDTR_MOE_Pos);						// Primary Output Enable
#endif
	setFieldData(mDev->CCMR1, TIM_CCMR1_CC2S_Msk, 0, TIM_CCMR1_CC2S_Pos);	// 출력으로 설정
	setBitData(mDev->CCMR1, true, TIM_CCMR1_OC2PE_Pos);					// Shadow 활성화
	setBitData(mDev->CCMR1, true, TIM_CCMR1_OC2FE_Pos);					// Fast 활성화
	setBitData(mDev->CCER, true, TIM_CCER_CC2E_Pos);						// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mDev->CCMR1, TIM_CCMR1_OC2M_Msk, 7, TIM_CCMR1_OC2M_Pos);
	else
		setFieldData(mDev->CCMR1, TIM_CCMR1_OC2M_Msk, 6, TIM_CCMR1_OC2M_Pos);

	return error_t::ERROR_NONE;
}

uint32_t PwmCh2::getTopValue(void)
{
	return mDev->ARR;
}

void PwmCh2::setDutyRatio(float ratio)
{
	mDev->CCR2 = (uint16_t)((float)mDev->ARR * ratio);
}

void PwmCh2::setCompareValue(int32_t  counter)
{
	mDev->CCR2 = counter;
}

PwmCh3::PwmCh3(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) : Pwm(peri, drvSetup)
{
	
}

error_t PwmCh3::initializeChannel(bool risingAtMatch)
{
#if defined(TIM_BDTR_MOE_Pos)
	setBitData(mDev->BDTR, true, TIM_BDTR_MOE_Pos);						// Primary Output Enable
#endif
	setFieldData(mDev->CCMR2, TIM_CCMR2_CC3S_Msk, 0, TIM_CCMR2_CC3S_Pos);	// 출력으로 설정
	setBitData(mDev->CCMR2, true, TIM_CCMR2_OC3PE_Pos);					// Shadow 활성화
	setBitData(mDev->CCMR2, true, TIM_CCMR2_OC3FE_Pos);					// Fast 활성화
	setBitData(mDev->CCER, true, TIM_CCER_CC3E_Pos);						// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mDev->CCMR2, TIM_CCMR2_OC3M_Msk, 7, TIM_CCMR2_OC3M_Pos);
	else
		setFieldData(mDev->CCMR2, TIM_CCMR2_OC3M_Msk, 6, TIM_CCMR2_OC3M_Pos);

	return error_t::ERROR_NONE;
}

uint32_t PwmCh3::getTopValue(void)
{
	return mDev->ARR;
}

void PwmCh3::setDutyRatio(float ratio)
{
	mDev->CCR3 = (uint16_t)((float)mDev->ARR * ratio);
}

void PwmCh3::setCompareValue(int32_t  counter)
{
	mDev->CCR3 = counter;
}

PwmCh4::PwmCh4(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) : Pwm(peri, drvSetup)
{
	
}

error_t PwmCh4::initializeChannel(bool risingAtMatch)
{
#if defined(TIM_BDTR_MOE_Pos)
	setBitData(mDev->BDTR, true, TIM_BDTR_MOE_Pos);						// Primary Output Enable
#endif
	setFieldData(mDev->CCMR2, TIM_CCMR2_CC4S_Msk, 0, TIM_CCMR2_CC4S_Pos);	// 출력으로 설정
	setBitData(mDev->CCMR2, true, TIM_CCMR2_OC4PE_Pos);					// Shadow 활성화
	setBitData(mDev->CCMR2, true, TIM_CCMR2_OC4FE_Pos);					// Fast 활성화
	setBitData(mDev->CCER, true, TIM_CCER_CC4E_Pos);						// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mDev->CCMR2, TIM_CCMR2_OC4M_Msk, 7, TIM_CCMR2_OC4M_Pos);
	else
		setFieldData(mDev->CCMR2, TIM_CCMR2_OC4M_Msk, 6, TIM_CCMR2_OC4M_Pos);

	return error_t::ERROR_NONE;
}

uint32_t PwmCh4::getTopValue(void)
{
	return mDev->ARR;
}

void PwmCh4::setDutyRatio(float ratio)
{
	mDev->CCR4 = (uint16_t)((float)mDev->ARR * ratio);
}

void PwmCh4::setCompareValue(int32_t  counter)
{
	mDev->CCR4 = counter;
}

#endif


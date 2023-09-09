////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(GD32F1) || defined(STM32F1_N) || defined (STM32F7_N) || defined(STM32F4_N)	

#include <drv/Pwm.h>
#include <yss/reg.h>
#if defined(GD32F1)
#include <targets/st/bitfield_stm32f103xx.h>
#elif defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#elif defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#endif

Pwm::Pwm(YSS_PWM_Peri *peri, const Drv::Setup drvSetup) : Drv(drvSetup)
{
	mPeri = peri;
}

void Pwm::initialize(uint32_t psc, uint32_t arr, bool risingAtMatch)
{
	mPeri->PSC = psc;
	mPeri->ARR = arr;

	initializeChannel(risingAtMatch);
}

void Pwm::changeFrequency(uint32_t freq)
{
	uint32_t psc, arr, clk = getClockFrequency();

	arr = clk / freq;
	psc = arr / (0xffff + 1);
	arr /= psc + 1;

	mPeri->PSC = psc;
	mPeri->ARR = arr;
}

void Pwm::initialize(uint32_t freq, bool risingAtMatch)
{
	uint32_t psc, arr, clk = getClockFrequency();

	arr = clk / freq;
	psc = arr / (0xffff + 1);
	arr /= psc + 1;

	mPeri->PSC = psc;
	mPeri->ARR = arr;

	initializeChannel(risingAtMatch);
}

uint32_t Pwm::getTopValue(void)
{
	return mPeri->ARR;
}

void Pwm::start(void)
{
	setBitData(mPeri->CR1, true, 0);	// Timer Enable
}

void Pwm::stop(void)
{
	setBitData(mPeri->CR1, false, 0);	// Timer Diable
}

void Pwm::setOnePulse(bool en)
{
	setBitData(mPeri->CR1, en, TIM_CR1_OPM_Pos);
}

PwmCh1::PwmCh1(YSS_PWM_Peri *peri, const Drv::Setup drvSetup) : Pwm(peri, drvSetup)
{
	
}

void PwmCh1::initializeChannel(bool risingAtMatch)
{
#if defined(TIM_BDTR_MOE_Pos)
	setBitData(mPeri->BDTR, true, TIM_BDTR_MOE_Pos);						// Primary Output Enable
#endif
	setFieldData(mPeri->CCMR1, TIM_CCMR1_CC1S_Msk, 0, TIM_CCMR1_CC1S_Pos);	// 출력으로 설정
	setBitData(mPeri->CCMR1, true, TIM_CCMR1_OC1PE_Pos);					// Shadow 활성화
	setBitData(mPeri->CCMR1, true, TIM_CCMR1_OC1FE_Pos);					// Fast 활성화
	setBitData(mPeri->CCER, true, TIM_CCER_CC1E_Pos);						// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mPeri->CCMR1, TIM_CCMR1_OC1M_Msk, 7, TIM_CCMR1_OC1M_Pos);
	else
		setFieldData(mPeri->CCMR1, TIM_CCMR1_OC1M_Msk, 6, TIM_CCMR1_OC1M_Pos);
}

uint32_t PwmCh1::getTopValue(void)
{
	return mPeri->ARR;
}

void PwmCh1::setRatio(float ratio)
{
	int32_t arr = mPeri->ARR, ccr = (float)arr * ratio;

	if(ccr >= arr)
		ccr = arr;
	else if(ccr < 0)
		ccr = 0;
	mPeri->CCR1 = ccr;
}

void PwmCh1::setCounter(int32_t  counter)
{
	mPeri->CCR1 = counter;
}

PwmCh2::PwmCh2(YSS_PWM_Peri *peri, const Drv::Setup drvSetup) : Pwm(peri, drvSetup)
{
	
}

void PwmCh2::initializeChannel(bool risingAtMatch)
{
#if defined(TIM_BDTR_MOE_Pos)
	setBitData(mPeri->BDTR, true, TIM_BDTR_MOE_Pos);						// Primary Output Enable
#endif
	setFieldData(mPeri->CCMR1, TIM_CCMR1_CC2S_Msk, 0, TIM_CCMR1_CC2S_Pos);	// 출력으로 설정
	setBitData(mPeri->CCMR1, true, TIM_CCMR1_OC2PE_Pos);					// Shadow 활성화
	setBitData(mPeri->CCMR1, true, TIM_CCMR1_OC2FE_Pos);					// Fast 활성화
	setBitData(mPeri->CCER, true, TIM_CCER_CC2E_Pos);						// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mPeri->CCMR1, TIM_CCMR1_OC2M_Msk, 7, TIM_CCMR1_OC2M_Pos);
	else
		setFieldData(mPeri->CCMR1, TIM_CCMR1_OC2M_Msk, 6, TIM_CCMR1_OC2M_Pos);
}

uint32_t PwmCh2::getTopValue(void)
{
	return mPeri->ARR;
}

void PwmCh2::setRatio(float ratio)
{
	mPeri->CCR2 = (uint16_t)((float)mPeri->ARR * ratio);
}

void PwmCh2::setCounter(int32_t  counter)
{
	mPeri->CCR2 = counter;
}

PwmCh3::PwmCh3(YSS_PWM_Peri *peri, const Drv::Setup drvSetup) : Pwm(peri, drvSetup)
{
	
}

void PwmCh3::initializeChannel(bool risingAtMatch)
{
#if defined(TIM_BDTR_MOE_Pos)
	setBitData(mPeri->BDTR, true, TIM_BDTR_MOE_Pos);						// Primary Output Enable
#endif
	setFieldData(mPeri->CCMR2, TIM_CCMR2_CC3S_Msk, 0, TIM_CCMR2_CC3S_Pos);	// 출력으로 설정
	setBitData(mPeri->CCMR2, true, TIM_CCMR2_OC3PE_Pos);					// Shadow 활성화
	setBitData(mPeri->CCMR2, true, TIM_CCMR2_OC3FE_Pos);					// Fast 활성화
	setBitData(mPeri->CCER, true, TIM_CCER_CC3E_Pos);						// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mPeri->CCMR2, TIM_CCMR2_OC3M_Msk, 7, TIM_CCMR2_OC3M_Pos);
	else
		setFieldData(mPeri->CCMR2, TIM_CCMR2_OC3M_Msk, 6, TIM_CCMR2_OC3M_Pos);
}

uint32_t PwmCh3::getTopValue(void)
{
	return mPeri->ARR;
}

void PwmCh3::setRatio(float ratio)
{
	mPeri->CCR3 = (uint16_t)((float)mPeri->ARR * ratio);
}

void PwmCh3::setCounter(int32_t  counter)
{
	mPeri->CCR3 = counter;
}

PwmCh4::PwmCh4(YSS_PWM_Peri *peri, const Drv::Setup drvSetup) : Pwm(peri, drvSetup)
{
	
}

void PwmCh4::initializeChannel(bool risingAtMatch)
{
#if defined(TIM_BDTR_MOE_Pos)
	setBitData(mPeri->BDTR, true, TIM_BDTR_MOE_Pos);						// Primary Output Enable
#endif
	setFieldData(mPeri->CCMR2, TIM_CCMR2_CC4S_Msk, 0, TIM_CCMR2_CC4S_Pos);	// 출력으로 설정
	setBitData(mPeri->CCMR2, true, TIM_CCMR2_OC4PE_Pos);					// Shadow 활성화
	setBitData(mPeri->CCMR2, true, TIM_CCMR2_OC4FE_Pos);					// Fast 활성화
	setBitData(mPeri->CCER, true, TIM_CCER_CC4E_Pos);						// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mPeri->CCMR2, TIM_CCMR2_OC4M_Msk, 7, TIM_CCMR2_OC4M_Pos);
	else
		setFieldData(mPeri->CCMR2, TIM_CCMR2_OC4M_Msk, 6, TIM_CCMR2_OC4M_Pos);
}

uint32_t PwmCh4::getTopValue(void)
{
	return mPeri->ARR;
}

void PwmCh4::setRatio(float ratio)
{
	mPeri->CCR4 = (uint16_t)((float)mPeri->ARR * ratio);
}

void PwmCh4::setCounter(int32_t  counter)
{
	mPeri->CCR4 = counter;
}

#endif


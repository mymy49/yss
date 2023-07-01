////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(GD32F1) || defined(STM32F1_N) || defined (STM32F7_N)

#include <drv/Pwm.h>
#include <yss/reg.h>
#if defined(GD32F1)
#include <targets/st/bitfield_stm32f103xx.h>
#elif defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#endif

Pwm::Pwm(YSS_PWM_Peri *peri, const Drv::Config drvConfig) : Drv(drvConfig)
{
	mPeri = peri;
}

void Pwm::initialize(uint32_t psc, uint32_t arr, bool risingAtMatch)
{
	mPeri->PSC = psc;
	mPeri->ARR = arr;

	initializeChannel(risingAtMatch);
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

uint32_t Pwm::getTop(void)
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
	setBitData(mPeri->CR1, en, 3);
}

PwmCh1::PwmCh1(YSS_PWM_Peri *peri, const Drv::Config drvConfig) : Pwm(peri, drvConfig)
{
	
}

void PwmCh1::initializeChannel(bool risingAtMatch)
{
	setBitData(mPeri->BDTR, true, 15);				// Primary Output Enable
	setFieldData(mPeri->CCMR1, 0x3 << 0, 0, 0);	// 출력으로 설정
	setBitData(mPeri->CCMR1, true, 3);			// Shadow 활성화
	setBitData(mPeri->CCMR1, true, 2);			// Fast 활성화
	setBitData(mPeri->CCER, true, 0);				// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mPeri->CCMR1, 0x7 << 4, 7, 4);
	else
		setFieldData(mPeri->CCMR1, 0x7 << 4, 6, 4);
}

uint32_t PwmCh1::getTop(void)
{
	return mPeri->ARR;
}

void PwmCh1::setRatio(float ratio)
{
	mPeri->CCR1 = (uint16_t)((float)mPeri->ARR * ratio);
}

void PwmCh1::setCounter(int32_t  counter)
{
	mPeri->CCR1 = counter;
}

PwmCh2::PwmCh2(YSS_PWM_Peri *peri, const Drv::Config drvConfig) : Pwm(peri, drvConfig)
{
	
}

void PwmCh2::initializeChannel(bool risingAtMatch)
{
	setBitData(mPeri->BDTR, true, 15);				// Primary Output Enable
	setFieldData(mPeri->CCMR1, 0x3 << 8, 0, 8);	// 출력으로 설정
	setBitData(mPeri->CCMR1, true, 11);			// Shadow 활성화
	setBitData(mPeri->CCMR1, true, 10);			// Fast 활성화
	setBitData(mPeri->CCER, true, 4);				// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mPeri->CCMR1, 0x7 << 12, 7, 12);
	else
		setFieldData(mPeri->CCMR1, 0x7 << 12, 6, 12);
}

uint32_t PwmCh2::getTop(void)
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

PwmCh3::PwmCh3(YSS_PWM_Peri *peri, const Drv::Config drvConfig) : Pwm(peri, drvConfig)
{
	
}

void PwmCh3::initializeChannel(bool risingAtMatch)
{
	setBitData(mPeri->BDTR, true, 15);				// Primary Output Enable
	setFieldData(mPeri->CCMR2, 0x3 << 0, 0, 0);	// 출력으로 설정
	setBitData(mPeri->CCMR2, true, 3);			// Shadow 활성화
	setBitData(mPeri->CCMR2, true, 2);			// Fast 활성화
	setBitData(mPeri->CCER, true, 8);				// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mPeri->CCMR2, 0x7 << 4, 7, 4);
	else
		setFieldData(mPeri->CCMR2, 0x7 << 4, 6, 4);
}

uint32_t PwmCh3::getTop(void)
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

PwmCh4::PwmCh4(YSS_PWM_Peri *peri, const Drv::Config drvConfig) : Pwm(peri, drvConfig)
{
	
}

void PwmCh4::initializeChannel(bool risingAtMatch)
{
	setBitData(mPeri->BDTR, true, 15);				// Primary Output Enable
	setFieldData(mPeri->CCMR2, 0x3 << 8, 0, 8);	// 출력으로 설정
	setBitData(mPeri->CCMR2, true, 11);			// Shadow 활성화
	setBitData(mPeri->CCMR2, true, 10);			// Fast 활성화
	setBitData(mPeri->CCER, true, 12);				// Channel 활성화 

	if (risingAtMatch)
		setFieldData(mPeri->CCMR2, 0x7 << 12, 7, 12);
	else
		setFieldData(mPeri->CCMR2, 0x7 << 12, 6, 12);
}

uint32_t PwmCh4::getTop(void)
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


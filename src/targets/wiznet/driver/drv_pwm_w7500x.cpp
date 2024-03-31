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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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


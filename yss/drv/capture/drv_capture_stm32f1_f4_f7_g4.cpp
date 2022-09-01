////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(STM32F1) || defined(STM32F4)

#include <drv/Capture.h>
#include <drv/timer/register_timer_stm32f1_f4_f7_g4.h>

Capture::Capture(const Drv::Config &drvConfig, const Config &config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mIsr = 0;
	mUpdateCnt = config.updateCnt;
	mLastUpdateCnt = 0;
	mLastCcr = 0;
}

void Capture::init(unsigned int psc, unsigned char option)
{
	mPeri->PSC = (unsigned short)psc;
	mPeri->ARR = 0xFFFF;
	mPeri->DIER |= TIM_DIER_UIE;

	initChannel(option);
}

unsigned int Capture::getSourceFrequency(void)
{
	return getClockFrequency() / (mPeri->PSC + 1);
}

void Capture::start(void)
{
	mPeri->CR1 |= TIM_CR1_CEN;
}

void Capture::stop(void)
{
	mPeri->CR1 &= ~TIM_CR1_CEN;
}

void Capture::isrUpdate(void)
{
	(*mUpdateCnt)++;
}

CaptureCh1::CaptureCh1(const Drv::Config &drvConfig, const Capture::Config &config) : Capture(drvConfig, config)
{
	
}

void CaptureCh1::initChannel(unsigned char option)
{
	mPeri->CCMR1 &= ~(TIM_CCMR1_CC1S | TIM_CCMR1_IC1F);
	mPeri->CCMR1 |= (1 << 0) | (2 << 4);

	if (option & RISING_EDGE)
		mPeri->CCER &= ~TIM_CCER_CC1P;
	else
		mPeri->CCER |= TIM_CCER_CC1P;

	mPeri->CCER |= TIM_CCER_CC1E;
	mPeri->DIER |= TIM_DIER_CC1IE;
}

void CaptureCh1::isrCapture(bool update)
{
	signed int cnt, ccr = (signed int)mPeri->CCR1;
	unsigned long long accCnt;

	cnt = (signed int)(*mUpdateCnt - mLastUpdateCnt);

	if (update)
	{
		if ((unsigned int)ccr > 0x7FFF)
		{
			mLastUpdateCnt = *mUpdateCnt - 1;
			cnt--;
		}
		else
			mLastUpdateCnt = *mUpdateCnt;
	}
	else
		mLastUpdateCnt = *mUpdateCnt;

	cnt = cnt * 65536;
	cnt += ccr - mLastCcr;
	mLastCcr = ccr;

	accCnt = mLastUpdateCnt * 65536 + ccr;

	if (mIsr)
		mIsr(cnt, accCnt);
}

void CaptureCh1::setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt))
{
	mIsr = isr;
}



CaptureCh2::CaptureCh2(const Drv::Config &drvConfig, const Capture::Config &config) : Capture(drvConfig, config)
{
	
}

void CaptureCh2::initChannel(unsigned char option)
{
	mPeri->CCMR1 &= ~(TIM_CCMR1_CC2S | TIM_CCMR1_IC2F);
	mPeri->CCMR1 |= (1 << 8) | (2 << 12);

	if (option & RISING_EDGE)
		mPeri->CCER &= ~TIM_CCER_CC2P;
	else
		mPeri->CCER |= TIM_CCER_CC2P;

	mPeri->CCER |= TIM_CCER_CC2E;
	mPeri->DIER |= TIM_DIER_CC2IE;
}

void CaptureCh2::isrCapture(bool update)
{
	signed int cnt, ccr = (signed int)mPeri->CCR2;
	unsigned long long accCnt;

	cnt = (signed int)(*mUpdateCnt - mLastUpdateCnt);

	if (update)
	{
		if ((unsigned int)ccr > 0x7FFF)
		{
			mLastUpdateCnt = *mUpdateCnt - 1;
			cnt--;
		}
		else
			mLastUpdateCnt = *mUpdateCnt;
	}
	else
		mLastUpdateCnt = *mUpdateCnt;

	cnt = cnt * 65536;
	cnt += ccr - mLastCcr;
	mLastCcr = ccr;

	accCnt = mLastUpdateCnt * 65536 + ccr;

	if (mIsr)
		mIsr(cnt, accCnt);
}

void CaptureCh2::setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt))
{
	mIsr = isr;
}



CaptureCh3::CaptureCh3(const Drv::Config &drvConfig, const Capture::Config &config) : Capture(drvConfig, config)
{
	
}

void CaptureCh3::initChannel(unsigned char option)
{
	mPeri->CCMR2 &= ~(TIM_CCMR2_CC3S | TIM_CCMR2_IC3F);
	mPeri->CCMR2 |= (1 << 0) | (2 << 4);

	if (option & RISING_EDGE)
		mPeri->CCER &= ~TIM_CCER_CC3P;
	else
		mPeri->CCER |= TIM_CCER_CC3P;

	mPeri->CCER |= TIM_CCER_CC3E;
	mPeri->DIER |= TIM_DIER_CC3IE;
}

void CaptureCh3::isrCapture(bool update)
{
	signed int cnt, ccr = (signed int)mPeri->CCR3;
	unsigned long long accCnt;

	cnt = (signed int)(*mUpdateCnt - mLastUpdateCnt);

	if (update)
	{
		if ((unsigned int)ccr > 0x7FFF)
		{
			mLastUpdateCnt = *mUpdateCnt - 1;
			cnt--;
		}
		else
			mLastUpdateCnt = *mUpdateCnt;
	}
	else
		mLastUpdateCnt = *mUpdateCnt;

	cnt = cnt * 65536;
	cnt += ccr - mLastCcr;
	mLastCcr = ccr;

	accCnt = mLastUpdateCnt * 65536 + ccr;

	if (mIsr)
		mIsr(cnt, accCnt);
}

void CaptureCh3::setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt))
{
	mIsr = isr;
}



CaptureCh4::CaptureCh4(const Drv::Config &drvConfig, const Capture::Config &config) : Capture(drvConfig, config)
{
	
}

void CaptureCh4::initChannel(unsigned char option)
{
	mPeri->CCMR2 &= ~(TIM_CCMR2_CC4S | TIM_CCMR2_IC4F);
	mPeri->CCMR2 |= (1 << 8) | (2 << 12);

	if (option & RISING_EDGE)
		mPeri->CCER &= ~TIM_CCER_CC4P;
	else
		mPeri->CCER |= TIM_CCER_CC4P;

	mPeri->CCER |= TIM_CCER_CC4E;
	mPeri->DIER |= TIM_DIER_CC4IE;
}

void CaptureCh4::isrCapture(bool update)
{
	signed int cnt, ccr = (signed int)mPeri->CCR4;
	unsigned long long accCnt;

	cnt = (signed int)(*mUpdateCnt - mLastUpdateCnt);

	if (update)
	{
		if ((unsigned int)ccr > 0x7FFF)
		{
			mLastUpdateCnt = *mUpdateCnt - 1;
			cnt--;
		}
		else
			mLastUpdateCnt = *mUpdateCnt;
	}
	else
		mLastUpdateCnt = *mUpdateCnt;

	cnt = cnt * 65536;
	cnt += ccr - mLastCcr;
	mLastCcr = ccr;

	accCnt = mLastUpdateCnt * 65536 + ccr;

	if (mIsr)
		mIsr(cnt, accCnt);
}

void CaptureCh4::setIsr(void (*isr)(unsigned int cnt, unsigned long long accCnt))
{
	mIsr = isr;
}
#endif


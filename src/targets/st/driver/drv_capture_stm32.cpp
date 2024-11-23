/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F7) || defined(GD32F1) || defined(STM32F1) || defined(STM32F4)

#include <drv/peripheral.h>
#include <drv/Capture.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Capture::Capture(const Drv::setup_t &drvSetup, const setup_t &setup) : Drv(drvSetup)
{
	mPeri = setup.peri;
	mIsr = 0;
	mUpdateCnt = setup.updateCnt;
	mLastUpdateCnt = 0;
	mLastCcr = 0;
}

void Capture::initialize(uint32_t psc, edge_t option)
{
	mPeri->PSC = (uint16_t)psc;
	mPeri->ARR = (uint16_t)0xFFFF;
	setBitData(mPeri->DIER, true, 0);	// Update Interrupt Enable

	initializeChannel(option);
}

uint32_t Capture::getSourceFrequency(void)
{
	return getClockFrequency() / (mPeri->PSC + 1);
}

void Capture::start(void)
{
	setBitData(mPeri->CR1, true, 0);	// Timer Enable
}

void Capture::stop(void)
{
	setBitData(mPeri->CR1, false, 0);	// Timer Diable
}

void Capture::isrUpdate(void)
{
	(*mUpdateCnt)++;
}

void Capture::isrCapture(int32_t ccr, bool update)
{
	int32_t cnt;
	uint64_t  accCnt;

	cnt = (int32_t)(*mUpdateCnt - mLastUpdateCnt);

	if (update)
	{
		if ((uint32_t)ccr > 0x7FFF)
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

CaptureCh1::CaptureCh1(const Drv::setup_t &drvSetup, const Capture::setup_t &setup) : Capture(drvSetup, setup)
{
	
}

void CaptureCh1::initializeChannel(uint8_t option)
{
	mPeri->CCMR1 &= ~(TIM_CCMR1_CC1S_Msk | TIM_CCMR1_IC1F_Msk);
	mPeri->CCMR1 |= (1 << 0) | (2 << 4);

	if (option == define::capture::option::RISING_EDGE)
		mPeri->CCER &= ~TIM_CCER_CC1P_Msk;
	else
		mPeri->CCER |= TIM_CCER_CC1P_Msk;

	mPeri->CCER |= TIM_CCER_CC1E_Msk;
	mPeri->DIER |= TIM_DIER_CC1IE_Msk;
}

void CaptureCh1::isrCapture(bool update)
{
	Capture::isrCapture((int32_t)mPeri->CCR1, update);
}

void CaptureCh1::setIsr(void (*isr)(uint32_t cnt, uint64_t  accCnt))
{
	mIsr = isr;
}



CaptureCh2::CaptureCh2(const Drv::setup_t &drvSetup, const Capture::setup_t &setup) : Capture(drvSetup, setup)
{
	
}

void CaptureCh2::initializeChannel(uint8_t option)
{
	mPeri->CCMR1 &= ~(TIM_CCMR1_CC2S_Msk | TIM_CCMR1_IC2F_Msk);
	mPeri->CCMR1 |= (1 << 8) | (2 << 12);

	if (option == define::capture::option::RISING_EDGE)
		mPeri->CCER &= ~TIM_CCER_CC2P_Msk;
	else
		mPeri->CCER |= TIM_CCER_CC2P_Msk;
	
	setFieldData(mPeri->CCMR1, TIM_CCMR1_IC2F_Msk, 8, TIM_CCMR1_IC2F_Pos);
	mPeri->CCER |= TIM_CCER_CC2E_Msk;
	mPeri->DIER |= TIM_DIER_CC2IE_Msk;
}

void CaptureCh2::isrCapture(bool update)
{
	Capture::isrCapture((int32_t)mPeri->CCR2, update);
}

void CaptureCh2::setIsr(void (*isr)(uint32_t cnt, uint64_t  accCnt))
{
	mIsr = isr;
}



CaptureCh3::CaptureCh3(const Drv::setup_t &drvSetup, const Capture::setup_t &setup) : Capture(drvSetup, setup)
{
	
}

void CaptureCh3::initializeChannel(uint8_t option)
{
	mPeri->CCMR2 &= ~(TIM_CCMR2_CC3S_Msk | TIM_CCMR2_IC3F_Msk);
	mPeri->CCMR2 |= (1 << 0) | (2 << 4);

	if (option == define::capture::option::RISING_EDGE)
		mPeri->CCER &= ~TIM_CCER_CC3P_Msk;
	else
		mPeri->CCER |= TIM_CCER_CC3P_Msk;

	mPeri->CCER |= TIM_CCER_CC3E_Msk;
	mPeri->DIER |= TIM_DIER_CC3IE_Msk;
}

void CaptureCh3::isrCapture(bool update)
{
	Capture::isrCapture((int32_t)mPeri->CCR3, update);
}

void CaptureCh3::setIsr(void (*isr)(uint32_t cnt, uint64_t  accCnt))
{
	mIsr = isr;
}

CaptureCh4::CaptureCh4(const Drv::setup_t &drvSetup, const Capture::setup_t &setup) : Capture(drvSetup, setup)
{
	
}

void CaptureCh4::initializeChannel(uint8_t option)
{
	mPeri->CCMR2 &= ~(TIM_CCMR2_CC4S_Msk | TIM_CCMR2_IC4F_Msk);
	mPeri->CCMR2 |= (1 << 8) | (2 << 12);

	if (option == define::capture::option::RISING_EDGE)
		mPeri->CCER &= ~TIM_CCER_CC4P_Msk;
	else
		mPeri->CCER |= TIM_CCER_CC4P_Msk;

	mPeri->CCER |= TIM_CCER_CC4E_Msk;
	mPeri->DIER |= TIM_DIER_CC4IE_Msk;
}

void CaptureCh4::isrCapture(bool update)
{
	Capture::isrCapture((int32_t)mPeri->CCR4, update);
}

void CaptureCh4::setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt))
{
	mIsr = isr;
}

#endif


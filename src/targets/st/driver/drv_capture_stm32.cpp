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

#if defined(STM32F7_N) || defined(GD32F1)

#include <drv/peripheral.h>
#include <drv/Capture.h>
#include <yss/reg.h>

#if defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#elif defined(GD32F10X_MD)
#include <targets/st/bitfield_stm32f103xx.h>
#endif

Capture::Capture(const Drv::Setup &drvSetup, const Setup &setup) : Drv(drvSetup)
{
	mPeri = setup.peri;
	mIsr = 0;
	mUpdateCnt = setup.updateCnt;
	mLastUpdateCnt = 0;
	mLastCcr = 0;
}

void Capture::initialize(uint32_t psc, uint8_t option)
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

CaptureCh1::CaptureCh1(const Drv::Setup &drvSetup, const Capture::Setup &setup) : Capture(drvSetup, setup)
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



CaptureCh2::CaptureCh2(const Drv::Setup &drvSetup, const Capture::Setup &setup) : Capture(drvSetup, setup)
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



CaptureCh3::CaptureCh3(const Drv::Setup &drvSetup, const Capture::Setup &setup) : Capture(drvSetup, setup)
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

CaptureCh4::CaptureCh4(const Drv::Setup &drvSetup, const Capture::Setup &setup) : Capture(drvSetup, setup)
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


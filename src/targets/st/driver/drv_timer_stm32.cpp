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

#include <drv/mcu.h>

#if defined(STM32F4_N) || defined(STM32F7_N) || defined(STM32F0_N) || defined(GD32F1) || defined (STM32F1_N)

#include <drv/peripheral.h>
#include <drv/Timer.h>
#include <yss/reg.h>

#if defined(STM32F030xC)
#include <targets/st/bitfield_stm32f030xx.h>
#elif defined (STM32F1_N)
#include <targets/st/bitfield_stm32f103xx.h>
#endif

Timer::Timer(const Drv::Setup drvSetup, const Setup setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mIsrUpdate = 0;
	mTimeUpdateCnt = 0;
}

void Timer::initializeAsSystemRuntime(void)
{
	mDev->PSC = (uint16_t)(getClockFrequency() / 1000000) - 1;
	mDev->ARR = 60000;
	mDev->CNT = 0;
}

void Timer::initialize(uint32_t psc, uint32_t arr)
{
	mDev->PSC = (uint16_t)psc;
	mDev->ARR = (uint16_t)arr;
}

void Timer::initialize(uint32_t freq)
{
	uint32_t psc, arr, clk = getClockFrequency();

	arr = clk / freq;
	psc = arr / (0xffff + 1);
	arr /= psc + 1;

	mDev->PSC = psc;
	mDev->ARR = arr;
}

void Timer::enableUpdateInterrupt(bool en)
{
	setBitData(mDev->DIER, en, 0);	// Update Interrupt Enable
}

void Timer::start(void)
{
	setBitData(mDev->CR1, true, 0);	// Timer Enable
#if defined(STM32F030xC)
	while(~mDev->SR & TIM_SR_UIF_Msk);
	mDev->SR = ~TIM_SR_UIF_Msk;
	mDev->CNT = 0;
#endif
}

void Timer::stop(void)
{
	setBitData(mDev->CR1, false, 0);	// Timer Diable
}

uint32_t Timer::getCounterValue(void)
{
	return mDev->CNT & 0xFFFF;
}

uint32_t Timer::getOverFlowCount(void)
{
	return 60000;
}

void Timer::setUpdateIsr(void (*isr)(void))
{
	mIsrUpdate = isr;
}

void Timer::isrUpdate(void)
{
	if (mIsrUpdate)
		mIsrUpdate();
	mTimeUpdateCnt++;
}

#endif


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

#if defined(EFM32PG22) || defined(EFR32BG22)

#include <drv/peripheral.h>
#include <drv/Timer.h>
#include <yss/reg.h>

#if defined(EFM32PG22)
#include <targets/siliconlabs/efm32pg22_timer.h>
#elif defined(EFR32BG22)
#include <targets/siliconlabs/efr32bg22_timer.h>
#endif

static uint32_t gDivider = 1;

Timer::Timer(const Drv::Setup drvSetup, const Setup setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mBit = setup.bit;
	mIsrUpdate = 0;
}

Timer::Timer(YSS_TIMER_Dev *dev, const Drv::Config drvConfig) : Drv(drvConfig)
{
	mDev = dev;
	mBit = BIT::BIT_16;
	mIsrUpdate = 0;
}

void Timer::initializeAsSystemRuntime(void)
{
	uint32_t clk = getClockFrequency();

	setFieldData(mDev->CFG, _TIMER_CFG_PRESC_MASK, clk / 1000000 - 1, _TIMER_CFG_PRESC_SHIFT);

	mDev->EN_SET = TIMER_EN_EN;

	if(mBit == BIT::BIT_32)
		mDev->TOP = 0xFFFFFFFF;
	else
		mDev->TOP = 0xFFFF;
}

void Timer::initialize(uint32_t psc, uint32_t arr)
{
	setFieldData(mDev->CFG, _TIMER_CFG_PRESC_MASK, psc, _TIMER_CFG_PRESC_SHIFT);

	mDev->TOP = arr;

	mDev->EN_SET = TIMER_EN_EN;
}

void Timer::initialize(uint32_t freq)
{
	uint32_t clk = getClockFrequency();
	uint32_t psc = 1024, top;
	
	top = clk / freq;
	while(psc)
	{
		if(top % psc == 0)
		{
			clk /= psc;
			psc--;
			break;
		}
		psc--;
	}

	setFieldData(mDev->CFG, _TIMER_CFG_PRESC_MASK, psc, _TIMER_CFG_PRESC_SHIFT);
	mDev->EN_SET = TIMER_EN_EN;
	mDev->TOP = clk / freq - 1;
}

void Timer::enableUpdateInterrupt(bool en)
{
	setBitData(mDev->IEN, en, _TIMER_IEN_OF_SHIFT);
}

void Timer::start(void)
{
	mDev->CMD_SET = _TIMER_CMD_START_MASK;
}

void Timer::stop(void)
{
	mDev->CMD_SET = _TIMER_CMD_STOP_MASK;
}

uint32_t Timer::getCounterValue(void)
{
	return mDev->CNT;
}

uint32_t Timer::getOverFlowCount(void)
{
	if(mBit == BIT::BIT_32)
		return 0xFFFFFFFF;
	else
		return 0xFFFF;
}

void Timer::setUpdateIsr(void (*isr)(void))
{
	mIsrUpdate = isr;
}

void Timer::isrUpdate(void)
{
	if (mIsrUpdate)
		mIsrUpdate();
}

#endif


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

#include <yss/instance.h>

#if defined(STM32F0_N)

#include <config.h>
#include <yss.h>
#include <yss/reg.h>

#if defined(STM32F030xC)
#include <targets/st/bitfield_stm32f030xx.h>
#endif

static uint32_t getClockFrequency(void)
{
	return clock.getApb2ClockFrequency();
}

#if defined(ADC1_ENABLE) && defined(ADC1)
static void enableClockAdc1(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_ADCEN_Pos, en);
	clock.unlock();
}

static void enableInterruptAdc1(bool en)
{
    nvic.lock();
    nvic.enableInterrupt(ADC1_IRQn, en);
    nvic.unlock();
}

static void resetAdc1(void)
{
	clock.lock();
    clock.resetApb2(RCC_APB2RSTR_ADCRST_Pos);
	clock.unlock();
}

static const Adc::Setup gAdc1Setup
{
	ADC1
};

static const Drv::Setup gDrvAdc1Setup
{
	enableClockAdc1,		//void (*clockFunc)(bool en);
	enableInterruptAdc1,	//void (*nvicFunc)(bool en);
	resetAdc1,				//void (*resetFunc)(void);
	getClockFrequency		//uint32_t (*getClockFunc)(void);
};

Adc adc1(gDrvAdc1Setup, gAdc1Setup);

extern "C"
{
	void ADC1_IRQHandler(void)
	{
		adc1.isr();
	}
}
#endif

#endif


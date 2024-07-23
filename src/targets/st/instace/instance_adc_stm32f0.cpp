/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(STM32F0)

#include <config.h>
#include <yss.h>
#include <yss/reg.h>

#if defined(STM32F030xC)
#include <targets/st/bitfield_stm32f030xx.h>
#endif

#if ADC1_ENABLE && defined(ADC1)
static uint32_t getClockFrequency(void)
{
	return clock.getApb2ClockFrequency();
}

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

static const Adc::setup_t gAdc1Setup
{
	ADC1
};

static const Drv::setup_t gDrvAdc1Setup
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


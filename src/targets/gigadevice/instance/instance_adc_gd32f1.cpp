/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(GD32F1)

#include <config.h>
#include <yss.h>
#include <yss/reg.h>
#include <yss/instance.h>

#include <targets/st/bitfield_stm32f103xx.h>
#define ADC1_IRQn		ADC1_2_IRQn
#define ADC2_IRQn		ADC1_2_IRQn

#if defined(__SEGGER_LINKER)
#define ADC1_2_IRQHandler		ADC_IRQHandler
#endif

static uint32_t getApb1ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}

static uint32_t getApb2ClockFrequency(void)
{
	return clock.getApb2ClockFrequency();
}

#if defined(ADC1_ENABLE) && defined(ADC1)
static void enableClockAdc1(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_ADC1EN_Pos, en);
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
    clock.resetApb2(RCC_APB2RSTR_ADC1RST_Pos);
	clock.unlock();
}

static const Adc::Setup gAdc1Setup
{
	ADC1
};

static const Drv::setup_t gDrvAdc1Setup
{
	enableClockAdc1,		//void (*clockFunc)(bool en);
	enableInterruptAdc1,	//void (*nvicFunc)(bool en);
	resetAdc1,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

Adc adc1(gDrvAdc1Setup, gAdc1Setup);
#endif

#if defined(ADC2_ENABLE) && defined(ADC2)
void enableClockAdc2(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_ADC2EN_Pos, en);
	clock.unlock();
}

void enableInterruptAdc2(bool en)
{
    nvic.lock();
    nvic.enableInterrupt(ADC2_IRQn, en);
    nvic.unlock();
}

static void resetAdc2(void)
{
	clock.lock();
    clock.resetApb2(RCC_APB2RSTR_ADC2RST_Pos);
	clock.unlock();
}

static const Adc::Setup gAdc2Setup
{
	ADC2
};

static const Drv::setup_t gDrvAdc2Setup
{
	enableClockAdc2,		//void (*clockFunc)(bool en);
	enableInterruptAdc2,	//void (*nvicFunc)(bool en);
	resetAdc2,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

Adc adc2(gDrvAdc2Setup, gAdc2Setup);
#endif

#if defined(ADC3_ENABLE) && defined(ADC3)
void enableClockAdc3(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_ADC3EN_Pos, en);
	clock.unlock();
}

void enableInterruptAdc3(bool en)
{
    nvic.lock();
    nvic.enableInterrupt(ADC3_IRQn, en);
    nvic.unlock();
}

static void resetAdc3(void)
{
}

static const Adc::Setup gAdc3Setup
{
	ADC3
};

static const Drv::setup_t gDrvAdc3Setup
{
	enableClockAdc3,		//void (*clockFunc)(bool en);
	enableInterruptAdc3,	//void (*nvicFunc)(bool en);
	resetAdc3,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

Adc adc3(gDrvAdc3Setup, gAdc3Setup);
#endif

#if defined(GD32F1) && ((defined(ADC1_ENABLE) && defined(ADC1)) || (defined(ADC2_ENABLE) && defined(ADC2)))
extern "C"
{
	void ADC1_2_IRQHandler(void)
	{
#if defined(ADC1_ENABLE) && defined(ADC1)
		if (getBitData(ADC1->CR1, 5) && getBitData(ADC1->SR, 1))
		{
			ADC1->SR = 0;
			adc1.isr();
		}
#endif
#if defined(ADC2_ENABLE) && defined(ADC2)
		peri = (YSS_ADC_Peri*)ADC2;
		if (getBitData(peri[ADC->CR1, 5) && getBitData(peri[ADC_REG::SR], 1))
		{
			peri[ADC_REG::SR] = 0;
			adc2.isr();
		}
#endif
	}
}
#elif defined (GD32F4) && ((defined(ADC1_ENABLE) && defined(ADC1)) || (defined(ADC2_ENABLE) && defined(ADC2)) || (defined(ADC3_ENABLE) && defined(ADC3)))
extern "C"
{
	void ADC_IRQHandler(void)
	{
#if defined(ADC1_ENABLE) && defined(ADC1)
		if (getBitData(ADC1[ADC->CR1, 5) && getBitData(ADC1->SR, 1))
		{
			ADC1->SR = 0;
			adc1.isr();
		}
#endif
#if defined(ADC2_ENABLE) && defined(ADC2)
		if (getBitData(ADC2[ADC->CR1, 5) && getBitData(ADC2->SR, 1))
		{
			ADC2->SR = 0;
			adc2.isr();
		}
#endif
#if defined(ADC3_ENABLE) && defined(ADC3)
		if (getBitData(ADC3[ADC->CR1, 5) && getBitData(ADC3->SR, 1))
		{
			ADC3->SR = 0;
			adc3.isr();
		}
#endif
	}
}
#endif

#endif


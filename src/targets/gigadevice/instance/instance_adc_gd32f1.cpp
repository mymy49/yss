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

static const Drv::Setup gDrvAdc1Setup
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

static const Drv::Setup gDrvAdc2Setup
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

static const Drv::Setup gDrvAdc3Setup
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


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

#include <yss/instance.h>

#if defined(STM32F4_N) || defined(STM32F7_N) || defined(STM32F1_N)

#include <config.h>
#include <yss.h>
#include <yss/reg.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#define ADC1_IRQn		ADC_IRQn
#define ADC2_IRQn		ADC_IRQn
#define ADC3_IRQn		ADC_IRQn
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#define ADC1_IRQn		ADC_IRQn
#define ADC2_IRQn		ADC_IRQn
#define ADC3_IRQn		ADC_IRQn
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#define ADC1_IRQn		ADC_IRQn
#define ADC2_IRQn		ADC_IRQn
#define ADC3_IRQn		ADC_IRQn
#elif defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#define ADC1_IRQn		ADC_IRQn
#define ADC2_IRQn		ADC_IRQn
#define ADC3_IRQn		ADC_IRQn
#elif defined(STM32F103xB)
#include <targets/st/bitfield_stm32f103xx.h>
#define ADC1_IRQn		ADC1_2_IRQn
#define ADC2_IRQn		ADC1_2_IRQn
#endif

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

#if ADC1_ENABLE && defined(ADC1)
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
#if defined(STM32F7_N)
    clock.resetApb2(RCC_APB2RSTR_ADCRST_Pos);
#endif
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

#if ADC2_ENABLE && defined(ADC2)
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
#if defined(GD32F1) || defined(STM32F1_N)
    clock.resetApb2(RCC_APB2RSTR_ADC2RST_Pos);
#elif defined(STM32F7)
    clock.resetApb2(RCC_APB2RSTR_ADCRST_Pos);
#endif
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

#if ADC3_ENABLE && defined(ADC3)
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
	clock.lock();
#if defined(STM32F7)
    clock.resetApb2(RCC_APB2RSTR_ADCRST_Pos);
#endif
	clock.unlock();
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

extern "C"
{
#if (defined(STM32F4_N) || defined(STM32F7_N)) && ((defined(ADC1_ENABLE) && defined(ADC1)) || (ADC2_ENABLE && defined(ADC2)) || (ADC3_ENABLE && defined(ADC3)))
	void ADC_IRQHandler(void)
	{
#if defined(ADC1_ENABLE) && defined(ADC1)
		if (getBitData(ADC1->CR1, 5) && getBitData(ADC1->SR, 1))
		{
			ADC1->SR = 0;
			adc1.isr();
		}
#endif
#if ADC2_ENABLE && defined(ADC2)
		if (getBitData(ADC2->CR1, 5) && getBitData(ADC2->SR, 1))
		{
			ADC2->SR = 0;
			adc2.isr();
		}
#endif
#if ADC3_ENABLE && defined(ADC3)
		if (getBitData(ADC3->CR1, 5) && getBitData(ADC3->SR, 1))
		{
			ADC3->SR = 0;
			adc3.isr();
		}
#endif
	}
#elif (defined(STM32F1_N)) && ((ADC1_ENABLE && defined(ADC1)) || (ADC2_ENABLE && defined(ADC2)) || (ADC3_ENABLE && defined(ADC3)))
	void ADC_IRQHandler(void)
	{
#if ADC1_ENABLE && defined(ADC1)
		if (getBitData(ADC1->CR1, ADC_CR1_EOSIE_Pos) && getBitData(ADC1->SR, ADC_SR_EOS_Pos))
		{
			ADC1->SR = 0;
			adc1.isr();
		}
#endif
#if ADC2_ENABLE && defined(ADC2)
		if (getBitData(ADC2->CR1, ADC_CR1_EOSIE_Pos) && getBitData(ADC2->SR, ADC_SR_EOS_Pos))
		{
			ADC2->SR = 0;
			adc2.isr();
		}
#endif
	}
#endif
}

#endif


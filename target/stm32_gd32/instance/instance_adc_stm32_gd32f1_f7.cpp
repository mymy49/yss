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

#include <yss/instance.h>

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F7)

#include <config.h>
#include <yss.h>
#include <yss/reg.h>

#if defined(GD32F1) || defined(STM32F1)
#include <cmsis/mcu/st_gigadevice/rcc_stm32_gd32f1.h>
#define ADC1_IRQn		ADC1_2_IRQn
#define ADC2_IRQn		ADC1_2_IRQn
#elif defined(STM32F7)
#include <cmsis/mcu/st_gigadevice/rcc_stm32f7.h>
#define ADC1_IRQn		ADC_IRQn
#define ADC2_IRQn		ADC_IRQn
#define ADC3_IRQn		ADC_IRQn
#endif
#include <cmsis/mcu/st_gigadevice/adc_stm32_gd32f1.h>

#if defined(__SEGGER_LINKER)
#define ADC1_2_IRQHandler		ADC_IRQHandler
#endif

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
#if defined(GD32F1) || defined(STM32F1)
    clock.resetApb2(RCC_APB2RSTR_ADC1RST_Pos);
#elif defined(STM32F7)
    clock.resetApb2(RCC_APB2RSTR_ADCRST_Pos);
#endif
	clock.unlock();
}

Adc adc1((YSS_ADC_Peri*)ADC1, enableClockAdc1, enableInterruptAdc1, resetAdc1);
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
#if defined(GD32F1) || defined(STM32F1)
    clock.resetApb2(RCC_APB2RSTR_ADC2RST_Pos);
#elif defined(STM32F7)
    clock.resetApb2(RCC_APB2RSTR_ADCRST_Pos);
#endif
	clock.unlock();
}

Adc adc2((YSS_ADC_Peri*)ADC2, enableClockAdc2, enableInterruptAdc2, resetAdc2);
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

void setAdc3IntEn(bool en)
{
	nvic.setAdc3En(en);
}

static void resetAdc3(void)
{
	clock.lock();
#if defined(STM32F7)
    clock.resetApb2(RCC_APB2RSTR_ADCRST_Pos);
#endif
	clock.unlock();
}

Adc adc3(ADC3, enableClockAdc3, enableInterruptAdc3, resetAdc3);
#endif

#if (defined(STM32F1) || defined(GD32F1)) && ((defined(ADC1_ENABLE) && defined(ADC1)) || (defined(ADC2_ENABLE) && defined(ADC2)))
extern "C"
{
	void ADC1_2_IRQHandler(void)
	{
		YSS_ADC_Peri *peri;
#if defined(ADC1_ENABLE) && defined(ADC1)
		peri = (YSS_ADC_Peri*)ADC1;
		if (getBitData(peri[ADC_REG::CR1], 5) && getBitData(peri[ADC_REG::SR], 1))
		{
			peri[ADC_REG::SR] = 0;
			adc1.isr();
		}
#endif
#if defined(ADC2_ENABLE) && defined(ADC2)
		peri = (YSS_ADC_Peri*)ADC2;
		if (getBitData(peri[ADC_REG::CR1], 5) && getBitData(peri[ADC_REG::SR], 1))
		{
			peri[ADC_REG::SR] = 0;
			adc2.isr();
		}
#endif
	}
}
#elif (defined(STM32F7)) && ((defined(ADC1_ENABLE) && defined(ADC1)) || (defined(ADC2_ENABLE) && defined(ADC2)) || (defined(ADC3_ENABLE) && defined(ADC3)))
extern "C"
{
	void ADC_IRQHandler(void)
	{
#if defined(ADC1_ENABLE) && defined(ADC1)
		if (getBitData(ADC1[ADC_REG::CR1], 5) && getBitData(ADC1[ADC_REG::SR], 1))
		{
			ADC1[ADC_REG::SR] = 0;
			adc1.isr();
		}
#endif
#if defined(ADC2_ENABLE) && defined(ADC2)
		if (getBitData(ADC2[ADC_REG::CR1], 5) && getBitData(ADC2[ADC_REG::SR], 1))
		{
			ADC2[ADC_REG::SR] = 0;
			adc2.isr();
		}
#endif
#if defined(ADC3_ENABLE) && defined(ADC3)
		if (getBitData(ADC3[ADC_REG::CR1], 5) && getBitData(ADC3[ADC_REG::SR], 1))
		{
			ADC3[ADC_REG::SR] = 0;
			adc3.isr();
		}
#endif
	}
}
#endif

#endif


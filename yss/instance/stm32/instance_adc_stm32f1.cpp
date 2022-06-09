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

#if defined(STM32F1)

#include <config.h>
#include <yss/yss.h>

#if defined(ADC1_ENABLE) && (defined(ADC1) || defined(ADC))
static void setAdc1ClkEn(bool en)
{
	clock.peripheral.setAdc1En(en);
}

static void setAdc1IntEn(bool en)
{
	nvic.setAdc1En(en);
}

static void resetAdc1(void)
{
	clock.peripheral.resetAdc1();
}

#if defined(ADC1)
drv::Adc adc1(ADC1, setAdc1ClkEn, setAdc1IntEn, resetAdc1);
#elif defined(ADC)
drv::Adc adc1(ADC, setAdc1ClkEn, setAdc1IntEn, resetAdc1);
#endif
#endif

#if defined(ADC2_ENABLE) && defined(ADC2)
void setAdc2ClkEn(bool en)
{
	clock.peripheral.setAdc2En(en);
}

void setAdc2IntEn(bool en)
{
	nvic.setAdc2En(en);
}

static void resetAdc2(void)
{
	clock.peripheral.resetAdc2();
}

drv::Adc adc2(ADC2, setAdc2ClkEn, setAdc2IntEn, resetAdc2);
#endif

#if defined(ADC3_ENABLE) && defined(ADC3)
void setAdc3ClkEn(bool en)
{
	clock.peripheral.setAdc3En(en);
}

void setAdc3IntEn(bool en)
{
	nvic.setAdc3En(en);
}

static void resetAdc3(void)
{
	clock.peripheral.resetAdc3();
}

drv::Adc adc3(ADC3, setAdc3ClkEn, setAdc3IntEn, resetAdc3);
#endif

extern "C"
{
	void __attribute__((weak)) ADC1_2_IRQHandler(void)
	{
#if defined(ADC1_ENABLE) && defined(ADC1)
		adc1.isr();
#endif
#if defined(ADC2_ENABLE) && defined(ADC2)
		adc2.isr();
#endif
	}

	void __attribute__((weak)) ADC3_IRQHandler(void)
	{
#if defined(ADC3_ENABLE) && defined(ADC3)
		adc3.isr();
#endif
	}
}

#endif

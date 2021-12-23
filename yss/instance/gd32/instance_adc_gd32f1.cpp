////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2021.02.11 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(GD32F10X_XD)

#include <config.h>
#include <yss/yss.h>
#include <yss/reg.h>

#if defined(ADC1_ENABLE) && defined(ADC1)
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

drv::Adc adc1(ADC1, setAdc1ClkEn, setAdc1IntEn, resetAdc1);
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

#if (defined(ADC1_ENABLE) && defined(ADC1)) || (defined(ADC2_ENABLE) && defined(ADC2))
extern "C"
{
	void ADC1_2_IRQHandler(void)
	{
#if defined(ADC1_ENABLE) && defined(ADC1)
	if (getBitData(ADC1->CTLR1, 5) && getBitData(ADC1->STR, 1))
	{
		ADC1->STR = 0;
		adc1.isr();
	}
#endif
#if defined(ADC2_ENABLE) && defined(ADC2)
	if (getBitData(ADC1->CTLR1, 5) && getBitData(ADC1->STR, 1))
	{
		ADC1->STR = 0;
		adc2.isr();
	}
#endif
	}
}
#endif

#endif


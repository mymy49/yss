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

#include <drv/mcu.h>
#include <yss/instance.h>
#include <config.h>

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7)

static uint32_t getTimerApb2ClkFreq(void)
{
	return clock.getTimerApb2ClkFreq();
}

static uint32_t getTimerApb1ClkFreq(void)
{
	return clock.getTimerApb1ClkFreq();
}



#if defined(TIM1_ENABLE) && defined(TIM1)
static void setTim1ClockEn(bool en)
{
	if(en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM1EN;
}

static void setTim1IntEn(bool en)
{
#if defined(STM32F7)
	if(en)
		NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
	else
		NVIC_DisableIRQ(TIM1_UP_TIM10_IRQn);
#elif defined(STM32F1)
	if(en)
		NVIC_EnableIRQ(TIM1_UP_IRQn);
	else
		NVIC_DisableIRQ(TIM1_UP_IRQn);
#endif
}

static void resetTim1(void)
{
	clock.peripheral.resetTimer1();
}

Timer timer1(TIM1, setTim1ClockEn, setTim1IntEn, resetTim1, getTimerApb2ClkFreq);

extern "C"
{
#if defined(STM32F1) || defined(STM32F7) || defined(STM32F4)
	void TIM1_UP_TIM10_IRQHandler(void)
	{
		if (TIM1->DIER & TIM_DIER_UIE && TIM1->SR & TIM_SR_UIF)
		{
			TIM1->SR = ~TIM_SR_UIF;
			timer1.isrUpdate();
		}

#if defined(TIM10_ENABLE) && defined(TIM10)
#define TIM10_ISR_DEFINED
		if (TIM10->DIER & TIM_DIER_UIE && TIM10->SR & TIM_SR_UIF)
		{
			TIM10->SR = ~TIM_SR_UIF;
			timer10.isrUpdate();
		}
#endif
	}
#endif
}
#endif



#if defined(TIM2_ENABLE) && defined(TIM2)
static void setTim2ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN;
}

static void setTim2IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM2_IRQn);
	else
		NVIC_DisableIRQ(TIM2_IRQn);
}

static void resetTim2(void)
{
	clock.peripheral.resetTimer2();
}

Timer timer2(TIM2, setTim2ClockEn, setTim2IntEn, resetTim2, getTimerApb1ClkFreq);

extern "C"
{
	void TIM2_IRQHandler(void)
	{
		if (TIM2->DIER & TIM_DIER_UIE && TIM2->SR & TIM_SR_UIF)
		{
			TIM2->SR = ~TIM_SR_UIF;
			timer2.isrUpdate();
		}
	}
}
#endif



#if defined(TIM3_ENABLE) && defined(TIM3)
static void setTim3ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM3EN;
}

static void setTim3IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM3_IRQn);
	else
		NVIC_DisableIRQ(TIM3_IRQn);
}

static void resetTim3(void)
{
	clock.peripheral.resetTimer3();
}

Timer timer3(TIM3, setTim3ClockEn, setTim3IntEn, resetTim3, getTimerApb1ClkFreq);

extern "C"
{
	void TIM3_IRQHandler(void)
	{
		if (TIM3->DIER & TIM_DIER_UIE && TIM3->SR & TIM_SR_UIF)
		{
			TIM3->SR = ~TIM_SR_UIF;
			timer3.isrUpdate();
		}
	}
}
#endif



#if defined(TIM4_ENABLE) && defined(TIM4)
static void setTim4ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM4EN;
}

static void setTim4IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM4_IRQn);
	else
		NVIC_DisableIRQ(TIM4_IRQn);
}

static void resetTim4(void)
{
	clock.peripheral.resetTimer4();
}

Timer timer4(TIM4, setTim4ClockEn, setTim4IntEn, resetTim4, getTimerApb1ClkFreq);

extern "C"
{
	void TIM4_IRQHandler(void)
	{
		if (TIM4->DIER & TIM_DIER_UIE && TIM4->SR & TIM_SR_UIF)
		{
			TIM4->SR = ~TIM_SR_UIF;
			timer4.isrUpdate();
		}
	}
}
#endif



#if defined(TIM5_ENABLE) && defined(TIM5)
static void setTim5ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM5EN;
}

static void setTim5IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM5_IRQn);
	else
		NVIC_DisableIRQ(TIM5_IRQn);
}

static void resetTim5(void)
{
	clock.peripheral.resetTimer5();
}

Timer timer5(TIM5, setTim5ClockEn, setTim5IntEn, resetTim5, getTimerApb1ClkFreq);

extern "C"
{
	void TIM5_IRQHandler(void)
	{
		if (TIM5->DIER & TIM_DIER_UIE && TIM5->SR & TIM_SR_UIF)
		{
			TIM5->SR = ~TIM_SR_UIF;
			timer5.isrUpdate();
		}
	}
}
#endif



#if defined(TIM6_ENABLE) && defined(TIM6)
static void setTim6ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM6EN;
}

static void setTim6IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM6_DAC_IRQn);
	else
		NVIC_DisableIRQ(TIM6_DAC_IRQn);
}

static void resetTim6(void)
{
	clock.peripheral.resetTimer6();
}

Timer timer6(TIM6, setTim6ClockEn, setTim6IntEn, resetTim6, getTimerApb1ClkFreq);

extern "C"
{
	void TIM6_DAC_IRQHandler(void)
	{
		if (TIM6->DIER & TIM_DIER_UIE && TIM6->SR & TIM_SR_UIF)
		{
			TIM6->SR = ~TIM_SR_UIF;
			timer6.isrUpdate();
		}
	}
}
#endif



#if defined(TIM7_ENABLE) && defined(TIM7)
static void setTim7ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM7EN;
}

static void setTim7IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM7_IRQn);
	else
		NVIC_DisableIRQ(TIM7_IRQn);
}

static void resetTim7(void)
{
	clock.peripheral.resetTimer7();
}

Timer timer7(TIM7, setTim7ClockEn, setTim7IntEn, resetTim7, getTimerApb1ClkFreq);

extern "C"
{
	void TIM7_IRQHandler(void)
	{
		if (TIM7->DIER & TIM_DIER_UIE && TIM7->SR & TIM_SR_UIF)
		{
			TIM7->SR = ~TIM_SR_UIF;
			timer7.isrUpdate();
		}
	}
}
#endif



#if defined(TIM8_ENABLE) && defined(TIM8)
static void setTim8ClockEn(bool en)
{
	if(en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM8EN;
}

static void setTim8IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn);
	else
		NVIC_DisableIRQ(TIM8_UP_TIM13_IRQn);
}

static void resetTim8(void)
{
	clock.peripheral.resetTimer8();
}

Timer timer8(TIM8, setTim8ClockEn, setTim8IntEn, resetTim8, getTimerApb2ClkFreq);

extern "C"
{
	void TIM8_UP_TIM13_IRQHandler(void)
	{
		if (TIM8->DIER & TIM_DIER_UIE && TIM8->SR & TIM_SR_UIF)
		{
			TIM8->SR = ~TIM_SR_UIF;
			timer8.isrUpdate();
		}

#if defined(TIM13_ENABLE) && defined(TIM13)
#define TIM13_ISR_DEFINED
		if (TIM13->DIER & TIM_DIER_UIE && TIM13->SR & TIM_SR_UIF)
		{
			TIM13->SR = ~TIM_SR_UIF;
			timer13.isrUpdate();
		}
#endif
	}
}
#endif



#if defined(TIM9_ENABLE) && defined(TIM9)
static void setTim9ClockEn(bool en)
{
	if(en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM9EN;
}

static void setTim9IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
	else
		NVIC_DisableIRQ(TIM1_BRK_TIM9_IRQn);
}

static void resetTim9(void)
{
	clock.peripheral.resetTimer9();
}

Timer timer9(TIM9, setTim9ClockEn, setTim9IntEn, resetTim9, getTimerApb2ClkFreq);

extern "C"
{
	void TIM1_BRK_TIM9_IRQHandler(void)
	{
		if (TIM9->DIER & TIM_DIER_UIE && TIM9->SR & TIM_SR_UIF)
		{
			TIM9->SR = ~TIM_SR_UIF;
			timer9.isrUpdate();
		}
	}
}
#endif



#if defined(TIM10_ENABLE) && defined(TIM10)
static void setTim10ClockEn(bool en)
{
	if(en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM10EN;
}

static void setTim10IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
	else
		NVIC_DisableIRQ(TIM1_UP_TIM10_IRQn);
}

static void resetTim10(void)
{
	clock.peripheral.resetTimer10();
}

Timer timer10(TIM10, setTim10ClockEn, setTim10IntEn, resetTim10, getTimerApb2ClkFreq);

#ifndef TIM10_ISR_DEFINED

void TIM1_UP_TIM10_IRQHandler(void)
{
	if (TIM10->DIER & TIM_DIER_UIE && TIM10->SR & TIM_SR_UIF)
	{
		TIM10->SR = ~TIM_SR_UIF;
		timer10.isrUpdate();
	}
}
#endif
#endif



#if defined(TIM11_ENABLE) && defined(TIM11)
static void setTim11ClockEn(bool en)
{
	if(en)
		RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;
	else
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM11EN;
}

static void setTim11IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);
	else
		NVIC_DisableIRQ(TIM1_TRG_COM_TIM11_IRQn);
}

static void resetTim11(void)
{
	clock.peripheral.resetTimer11();
}

Timer timer11(TIM11, setTim11ClockEn, setTim11IntEn, resetTim11, getTimerApb2ClkFreq);

extern "C"
{
	void TIM1_TRG_COM_TIM11_IRQHandler(void)
	{
		if (TIM11->DIER & TIM_DIER_UIE && TIM11->SR & TIM_SR_UIF)
		{
			TIM11->SR = ~TIM_SR_UIF;
			timer11.isrUpdate();
		}
	}
}
#endif



#if defined(TIM12_ENABLE) && defined(TIM12)
static void setTim12ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM12EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM12EN;
}

static void setTim12IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM8_BRK_TIM12_IRQn);
	else
		NVIC_DisableIRQ(TIM8_BRK_TIM12_IRQn);
}

static void resetTim12(void)
{
	clock.peripheral.resetTimer12();
}

Timer timer12(TIM12, setTim12ClockEn, setTim12IntEn, resetTim12, getTimerApb1ClkFreq);

extern "C"
{
	void TIM8_BRK_TIM12_IRQHandler(void)
	{
		if (TIM12->DIER & TIM_DIER_UIE && TIM12->SR & TIM_SR_UIF)
		{
			TIM12->SR = ~TIM_SR_UIF;
			timer12.isrUpdate();
		}
	}
}
#endif



#if defined(TIM13_ENABLE) && defined(TIM13)
static void setTim13ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM13EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM13EN;
}

static void setTim13IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn);
	else
		NVIC_DisableIRQ(TIM8_UP_TIM13_IRQn);
}

static void resetTim13(void)
{
	clock.peripheral.resetTimer13();
}

Timer timer13(TIM13, setTim13ClockEn, setTim13IntEn, resetTim13, getTimerApb1ClkFreq);

#ifndef TIM13_ISR_DEFINED

extern "C"
{
	void TIM8_UP_TIM13_IRQHandler(void)
	{
		if (TIM13->DIER & TIM_DIER_UIE && TIM13->SR & TIM_SR_UIF)
		{
			TIM13->SR = ~TIM_SR_UIF;
			timer13.isrUpdate();
		}
	}
}
#endif

#endif



#if defined(TIM14_ENABLE) && defined(TIM14)
static void setTim14ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM14EN;
}

static void setTim14IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIM8_TRG_COM_TIM14_IRQn);
	else
		NVIC_DisableIRQ(TIM8_TRG_COM_TIM14_IRQn);
}

static void resetTim14(void)
{
	clock.peripheral.resetTimer14();
}

Timer timer14(TIM14, setTim14ClockEn, setTim14IntEn, resetTim14, getTimerApb1ClkFreq);

extern "C"
{
#if defined(STM32F0)
	void TIM14_IRQHandler(void)
#else
	void TIM8_TRG_COM_TIM14_IRQHandler(void)
#endif
	{
		if (TIM14->DIER & TIM_DIER_UIE && TIM14->SR & TIM_SR_UIF)
		{
			TIM14->SR = ~TIM_SR_UIF;
			timer14.isrUpdate();
		}
	}
}

#endif

#endif

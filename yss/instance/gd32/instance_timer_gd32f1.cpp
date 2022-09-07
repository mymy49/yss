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

#if defined(GD32F1)

static uint32_t getTimerApb2ClkFreq(void)
{
	return clock.getTimerApb2ClkFreq();
}

static uint32_t getTimerApb1ClkFreq(void)
{
	return clock.getTimerApb1ClkFreq();
}



#if defined(TIM1_ENABLE) && defined(TIMER1)
static void setTim1ClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_TIMER1EN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_TIMER1EN;
}

static void setTim1IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER1_UP_TIMER10_IRQn);
	else
		NVIC_DisableIRQ(TIMER1_UP_TIMER10_IRQn);
}

static void resetTim1(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_TIMER1RST;
	RCC->APB2RCR &= ~RCC_APB2RCR_TIMER1RST;
}

Timer timer1((volatile uint32_t*)TIMER1, setTim1ClockEn, setTim1IntEn, resetTim1, getTimerApb2ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER0_UP_TIMER9_IRQHandler(void)
#else
void TIMER1_UP_TIMER10_IRQHandler(void)
#endif
{
	if (TIMER1->DIE & TIMER_DIE_UPIE && TIMER1->STR & TIMER_STR_UPIF)
	{
		TIMER1->STR = ~TIMER_STR_UPIF;
		timer1.isrUpdate();
	}

#if defined(TIM10_ENABLE) && defined(TIMER10)
#define TIMER10_ISR_DEFINED
	if (TIMER10->DIE & TIMER_DIE_UPIE && TIMER10->STR & TIMER_STR_UPIF)
	{
		TIMER10->STR = ~TIMER_STR_UPIF;
		timer10.isrUpdate();
	}
#endif
}
}
#endif



#if defined(TIM2_ENABLE) && defined(TIMER2)
static void setTim2ClockEn(bool en)
{
	if(en)
		RCC->APB1CCR |= RCC_APB1CCR_TIMER2EN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_TIMER2EN;
}

static void setTim2IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER2_IRQn);
	else
		NVIC_DisableIRQ(TIMER2_IRQn);
}

static void resetTim2(void)
{
	RCC->APB1RCR |= RCC_APB1RCR_TIMER2RST;
	RCC->APB1RCR &= ~RCC_APB1RCR_TIMER2RST;
}

Timer timer2((volatile uint32_t*)TIMER2, setTim2ClockEn, setTim2IntEn, resetTim2, getTimerApb1ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER1_IRQHandler(void)
#else
void TIMER2_IRQHandler(void)
#endif
{
	if (TIMER2->DIE & TIMER_DIE_UPIE && TIMER2->STR & TIMER_STR_UPIF)
	{
		TIMER2->STR = ~TIMER_STR_UPIF;
		timer2.isrUpdate();
	}
}
}
#endif



#if defined(TIM3_ENABLE) && defined(TIMER3)
static void setTim3ClockEn(bool en)
{
	if(en)
		RCC->APB1CCR |= RCC_APB1CCR_TIMER3EN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_TIMER3EN;
}

static void setTim3IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER3_IRQn);
	else
		NVIC_DisableIRQ(TIMER3_IRQn);
}

static void resetTim3(void)
{
	RCC->APB1RCR |= RCC_APB1RCR_TIMER3RST;
	RCC->APB1RCR &= ~RCC_APB1RCR_TIMER3RST;
}

Timer timer3((volatile uint32_t*)TIMER3, setTim3ClockEn, setTim3IntEn, resetTim3, getTimerApb1ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER2_IRQHandler(void)
#else
void TIMER3_IRQHandler(void)
#endif
{
	if (TIMER3->DIE & TIMER_DIE_UPIE && TIMER3->STR & TIMER_STR_UPIF)
	{
		TIMER3->STR = ~TIMER_STR_UPIF;
		timer3.isrUpdate();
	}
}
}
#endif



#if defined(TIM4_ENABLE) && defined(TIMER4)
static void setTim4ClockEn(bool en)
{
	if(en)
		RCC->APB1CCR |= RCC_APB1CCR_TIMER4EN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_TIMER4EN;
}

static void setTim4IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER4_IRQn);
	else
		NVIC_DisableIRQ(TIMER4_IRQn);
}

static void resetTim4(void)
{
	RCC->APB1RCR |= RCC_APB1RCR_TIMER4RST;
	RCC->APB1RCR &= ~RCC_APB1RCR_TIMER4RST;
}

Timer timer4((volatile uint32_t*)TIMER4, setTim4ClockEn, setTim4IntEn, resetTim4, getTimerApb1ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER3_IRQHandler(void)
#else
void TIMER4_IRQHandler(void)
#endif
{
	if (TIMER4->DIE & TIMER_DIE_UPIE && TIMER4->STR & TIMER_STR_UPIF)
	{
		TIMER4->STR = ~TIMER_STR_UPIF;
		timer4.isrUpdate();
	}
}
}
#endif



#if defined(TIM5_ENABLE) && defined(TIMER5)
static void setTim5ClockEn(bool en)
{
	if(en)
		RCC->APB1CCR |= RCC_APB1CCR_TIMER5EN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_TIMER5EN;
}

static void setTim5IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER5_IRQn);
	else
		NVIC_DisableIRQ(TIMER5_IRQn);
}

static void resetTim5(void)
{
	RCC->APB1RCR |= RCC_APB1RCR_TIMER5RST;
	RCC->APB1RCR &= ~RCC_APB1RCR_TIMER5RST;
}

Timer timer5((volatile uint32_t*)TIMER5, setTim5ClockEn, setTim5IntEn, resetTim5, getTimerApb1ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER4_IRQHandler(void)
#else
void TIMER5_IRQHandler(void)
#endif
{
	if (TIMER5->DIE & TIMER_DIE_UPIE && TIMER5->STR & TIMER_STR_UPIF)
	{
		TIMER5->STR = ~TIMER_STR_UPIF;
		timer5.isrUpdate();
	}
}
}
#endif



#if defined(TIM6_ENABLE) && defined(TIMER6)
static void setTim6ClockEn(bool en)
{
	if(en)
		RCC->APB1CCR |= RCC_APB1CCR_TIMER6EN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_TIMER6EN;
}

static void setTim6IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER6_IRQn);
	else
		NVIC_DisableIRQ(TIMER6_IRQn);
}

static void resetTim6(void)
{
	RCC->APB1RCR |= RCC_APB1RCR_TIMER6RST;
	RCC->APB1RCR &= ~RCC_APB1RCR_TIMER6RST;
}

Timer timer6((volatile uint32_t*)TIMER6, setTim6ClockEn, setTim6IntEn, resetTim6, getTimerApb1ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER5_IRQHandler(void)
#else
void TIMER6_IRQHandler(void)
#endif
{
	if (TIMER6->DIE & TIMER_DIE_UPIE && TIMER6->STR & TIMER_STR_UPIF)
	{
		TIMER6->STR = ~TIMER_STR_UPIF;
		timer6.isrUpdate();
	}
}
}
#endif



#if defined(TIM7_ENABLE) && defined(TIMER7)
static void setTim7ClockEn(bool en)
{
	if(en)
		RCC->APB1CCR |= RCC_APB1CCR_TIMER7EN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_TIMER7EN;
}

static void setTim7IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER7_IRQn);
	else
		NVIC_DisableIRQ(TIMER7_IRQn);
}

static void resetTim7(void)
{
	RCC->APB1RCR |= RCC_APB1RCR_TIMER7RST;
	RCC->APB1RCR &= ~RCC_APB1RCR_TIMER7RST;
}

Timer timer7((volatile uint32_t*)TIMER7, setTim7ClockEn, setTim7IntEn, resetTim7, getTimerApb1ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER6_IRQHandler(void)
#else
void TIMER7_IRQHandler(void)
#endif
{
	if (TIMER7->DIE & TIMER_DIE_UPIE && TIMER7->STR & TIMER_STR_UPIF)
	{
		TIMER7->STR = ~TIMER_STR_UPIF;
		timer7.isrUpdate();
	}
}
}

#endif

#if defined(TIM8_ENABLE) && defined(TIMER8)
static void setTim8ClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_TIMER8EN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_TIMER8EN;
}

static void setTim8IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER8_UP_TIMER13_IRQn);
	else
		NVIC_DisableIRQ(TIMER8_UP_TIMER13_IRQn);
}

static void resetTim8(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_TIMER8RST;
	RCC->APB2RCR &= ~RCC_APB2RCR_TIMER8RST;
}

Timer timer8((volatile uint32_t*)TIMER8, setTim8ClockEn, setTim8IntEn, resetTim8, getTimerApb2ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER7_UP_TIMER12_IRQHandler(void)
#else
void TIMER8_UP_TIMER13_IRQHandler(void)
#endif
{
	if (TIMER8->DIE & TIMER_DIE_UPIE && TIMER8->STR & TIMER_STR_UPIF)
	{
		TIMER8->STR = ~TIMER_STR_UPIF;
		timer8.isrUpdate();
	}

#if defined(TIM13_ENABLE) && defined(TIMER13)
#define TIMER13_ISR_DEFINED
	if (TIMER13->DIE & TIMER_DIE_UPIE && TIMER13->STR & TIMER_STR_UPIF)
	{
		TIMER13->STR = ~TIMER_STR_UPIF;
		timer13.isrUpdate();
	}
#endif
}
}
#endif

#if defined(TIM9_ENABLE) && defined(TIMER9)
static void setTim9ClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_TIMER9EN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_TIMER9EN;
}

static void setTim9IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER1_BRK_TIMER9_IRQn);
	else
		NVIC_DisableIRQ(TIMER1_BRK_TIMER9_IRQn);
}

static void resetTim9(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_TIMER9RST;
	RCC->APB2RCR &= ~RCC_APB2RCR_TIMER9RST;
}

Timer timer9((volatile uint32_t*)TIMER9, setTim9ClockEn, setTim9IntEn, resetTim9, getTimerApb2ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER0_BRK_TIMER8_IRQHandler(void)
#else
void TIMER1_BRK_TIMER9_IRQHandler(void)
#endif
{
	if (TIMER9->DIE & TIMER_DIE_UPIE && TIMER9->STR & TIMER_STR_UPIF)
	{
		TIMER9->STR = ~TIMER_STR_UPIF;
		timer9.isrUpdate();
	}
}
}
#endif

#if defined(TIM10_ENABLE) && defined(TIMER10)
static void setTim10ClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_TIMER10EN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_TIMER10EN;
}

static void setTim10IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER1_UP_TIMER10_IRQn);
	else
		NVIC_DisableIRQ(TIMER1_UP_TIMER10_IRQn);
}

static void resetTim10(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_TIMER10RST;
	RCC->APB2RCR &= ~RCC_APB2RCR_TIMER10RST;
}

Timer timer10((volatile uint32_t*)TIMER10, setTim10ClockEn, setTim10IntEn, resetTim10, getTimerApb2ClkFreq);

#ifndef TIMER10_ISR_DEFINED
extern "C"
{
#if defined(__SEGGER_LINKER)
void TIM0_UP_TIM9_IRQHandler(void)
#else
void TIM1_UP_TIM10_IRQHandler(void)
#endif
{
	if (TIMER10->DIE & TIMER_DIE_UPIE && TIMER10->STR & TIMER_STR_UPIF)
	{
		TIMER10->STR = ~TIMER_STR_UPIF;
		timer10.isrUpdate();
	}
}
}
#endif

#endif



#if defined(TIM11_ENABLE) && defined(TIMER11)
static void setTim11ClockEn(bool en)
{
	if(en)
		RCC->APB2CCR |= RCC_APB2CCR_TIMER11EN;
	else
		RCC->APB2CCR &= ~RCC_APB2CCR_TIMER11EN;
}

static void setTim11IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER1_TRG_COM_TIMER11_IRQn);
	else
		NVIC_DisableIRQ(TIMER1_TRG_COM_TIMER11_IRQn);
}

static void resetTim11(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_TIMER11RST;
	RCC->APB2RCR &= ~RCC_APB2RCR_TIMER11RST;
}

Timer timer11((volatile uint32_t*)TIMER11, setTim11ClockEn, setTim11IntEn, resetTim11, getTimerApb2ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER0_TRG_COM_TIMER10_IRQHandler(void)
#else
void TIMER1_TRG_COM_TIMER11_IRQHandler(void)
#endif
{
	if (TIMER11->DIE & TIMER_DIE_UPIE && TIMER11->STR & TIMER_STR_UPIF)
	{
		TIMER11->STR = ~TIMER_STR_UPIF;
		timer11.isrUpdate();
	}
}
}
#endif



#if defined(TIM12_ENABLE) && defined(TIMER12)
static void setTim12ClockEn(bool en)
{
	if(en)
		RCC->APB1CCR |= RCC_APB1CCR_TIMER12EN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_TIMER12EN;
}

static void setTim12IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER8_BRK_TIMER12_IRQn);
	else
		NVIC_DisableIRQ(TIMER8_BRK_TIMER12_IRQn);
}

static void resetTim12(void)
{
	RCC->APB1RCR |= RCC_APB1RCR_TIMER12RST;
	RCC->APB1RCR &= ~RCC_APB1RCR_TIMER12RST;
}

Timer timer12((volatile uint32_t*)TIMER12, setTim12ClockEn, setTim12IntEn, resetTim12, getTimerApb1ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER8_BRK_TIMER12_IRQHandler(void)
#else
void TIMER7_BRK_TIMER11_IRQHandler(void)
#endif
{
	if (TIMER12->DIE & TIMER_DIE_UPIE && TIMER12->STR & TIMER_STR_UPIF)
	{
		TIMER12->STR = ~TIMER_STR_UPIF;
		timer12.isrUpdate();
	}
}
}
#endif



#if defined(TIM13_ENABLE) && defined(TIMER13)
static void setTim13ClockEn(bool en)
{
	if(en)
		RCC->APB1CCR |= RCC_APB1CCR_TIMER13EN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_TIMER13EN;
}

static void setTim13IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER8_UP_TIMER13_IRQn);
	else
		NVIC_DisableIRQ(TIMER8_UP_TIMER13_IRQn);
}

static void resetTim13(void)
{
	RCC->APB1RCR |= RCC_APB1RCR_TIMER13RST;
	RCC->APB1RCR &= ~RCC_APB1RCR_TIMER13RST;
}

Timer timer13((volatile uint32_t*)TIMER13, setTim13ClockEn, setTim13IntEn, resetTim13, getTimerApb1ClkFreq);

#ifndef TIMER13_ISR_DEFINED
extern "C"
{
#if defined(__SEGGER_LINKER)
void TIM7_UP_TIM12_IRQHandler(void)
#else
void TIM8_UP_TIM13_IRQHandler(void)
#endif
{
	if (TIMER13->DIE & TIMER_DIE_UPIE && TIMER13->STR & TIMER_STR_UPIF)
	{
		TIMER13->STR = ~TIMER_STR_UPIF;
		timer13.isrUpdate();
	}
}
}
#endif
#endif



#if defined(TIM14_ENABLE) && defined(TIMER14)
static void setTim14ClockEn(bool en)
{
	if(en)
		RCC->APB1CCR |= RCC_APB1CCR_TIMER14EN;
	else
		RCC->APB1CCR &= ~RCC_APB1CCR_TIMER14EN;
}

static void setTim14IntEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(TIMER8_TRG_COM_TIMER14_IRQn);
	else
		NVIC_DisableIRQ(TIMER8_TRG_COM_TIMER14_IRQn);
}

static void resetTim14(void)
{
	RCC->APB1RCR |= RCC_APB1RCR_TIMER14RST;
	RCC->APB1RCR &= ~RCC_APB1RCR_TIMER14RST;
}

Timer timer14((volatile uint32_t*)TIMER14, setTim14ClockEn, setTim14IntEn, resetTim14, getTimerApb1ClkFreq);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER7_TRG_COM_TIMER13_IRQHandler(void)
#else
void TIMER8_TRG_COM_TIMER14_IRQHandler(void)
#endif
{
	if (TIMER14->DIE & TIMER_DIE_UPIE && TIMER14->STR & TIMER_STR_UPIF)
	{
		TIMER14->STR = ~TIMER_STR_UPIF;
		timer14.isrUpdate();
	}
}
}
#endif

#endif


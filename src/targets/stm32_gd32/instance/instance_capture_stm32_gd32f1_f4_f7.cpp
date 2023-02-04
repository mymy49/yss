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
#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(GD32F1)
#if defined(__SEGGER_LINKER)
#define TIM1_UP_IRQHandler		TIMER0_UP_TIMER9_IRQHandler
#define TIM2_IRQHandler			TIMER1_IRQHandler
#define TIM3_IRQHandler			TIMER2_IRQHandler
#define TIM4_IRQHandler			TIMER3_IRQHandler
#define TIM5_IRQHandler			TIMER4_IRQHandler
#define TIM6_IRQHandler			TIMER5_IRQHandler
#define TIM7_IRQHandler			TIMER6_IRQHandler
#define TIM8_UP_IRQHandler		TIMER7_UP_TIMER12_IRQHandler
#else
#define TIM1_UP_IRQHandler		TIMER1_UP_TIMER10_IRQHandler
#define TIM2_IRQHandler			TIMER2_IRQHandler
#define TIM3_IRQHandler			TIMER3_IRQHandler
#define TIM4_IRQHandler			TIMER4_IRQHandler
#define TIM5_IRQHandler			TIMER5_IRQHandler
#define TIM6_IRQHandler			TIMER6_IRQHandler
#endif
#elif defined(STM32F4)
#define TIM1_UP_IRQHandler		TIM1_UP_TIMER10_IRQHandler

#define TIM1_UP_IRQn			TIM1_UP_TIM10_IRQn
#elif defined(GD32F4)
#define TIM1_UP_IRQHandler		TIMER0_UP_TIMER9_IRQHandler
#define TIM2_IRQHandler			TIMER1_IRQHandler
#define TIM3_IRQHandler			TIMER2_IRQHandler
#define TIM4_IRQHandler			TIMER3_IRQHandler
#define TIM5_IRQHandler			TIMER4_IRQHandler
#define TIM6_IRQHandler			TIMER5_IRQHandler
#define TIM7_IRQHandler			TIMER6_IRQHandler
#define TIM8_UP_IRQHandler		TIMER7_UP_TIMER12_IRQHandler

#define TIM1_UP_IRQn			TIM1_UP_TIM10_IRQn
#define	TIM6_IRQn				TIM6_DAC_IRQn
#endif

#if defined(GD32F1) || defined(STM32F1)
static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};

uint32_t getApb1TimerClockFrequency(void);
uint32_t getApb2TimerClockFrequency(void);

#if defined(CAPTURE1_ENABLE) && defined(TIMER1)
#if defined(TIM1_ENABLE) || defined(PWM1_ENABLE)
#error "CAPTURE1, PWM1, TIMER1은 동시에 활성화 될 수 없습니다."
#endif
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
	{
		NVIC_EnableIRQ(TIMER1_UP_TIMER10_IRQn);
		NVIC_EnableIRQ(TIMER1_CC_IRQn);
	}
	else
	{
		NVIC_DisableIRQ(TIMER1_UP_TIMER10_IRQn);
		NVIC_DisableIRQ(TIMER1_CC_IRQn);
	}
}

static void resetTim1(void)
{
	RCC->APB2RCR |= RCC_APB2RCR_TIMER1RST;
	RCC->APB2RCR &= ~RCC_APB2RCR_TIMER1RST;
}

static const Drv::Config gDrvTim1Config = 
{
	setTim1ClockEn,			//void (*clockFunc)(bool en);
	setTim1IntEn,			//void (*nvicFunc)(bool en);
	resetTim1,				//void (*resetFunc)(void);
	getTimerApb2ClkFreq		//uint32_t (*getClockFunc)(void);
};
static uint64_t gCapture1UpdateCnt;
static const drv::Capture::Config gTim11Config = 
{
	TIMER1,				//YSS_PWM_Peri *peri;
	&gCapture1UpdateCnt	//uint64_t *updateCnt;
};

drv::CaptureCh1 capture1Ch1(gDrvTim1Config, gTim11Config);
drv::CaptureCh2 capture1Ch2(gDrvTim1Config, gTim11Config);

extern "C"
{
void TIM1_UP_IRQHandler(void)
{
	bool event1 = false;

	if (TIMER1->DIE & TIMER_DIE_UPIE && TIMER1->STR & TIMER_STR_UPIF)
	{
		TIMER1->STR = ~TIMER_STR_UPIF;
		capture1Ch1.isrUpdate();
		event1 = true;
	}

	if (TIMER1->DIE & TIMER_DIE_CH1IE && TIMER1->STR & TIMER_STR_CH1IF)
	{
		TIMER1->STR = ~TIMER_STR_CH1IF;
		capture1Ch1.isrCapture(event1);
	}

	if (TIMER1->DIE & TIMER_DIE_CH2IE && TIMER1->STR & TIMER_STR_CH2IF)
	{
		TIMER1->STR = ~TIMER_STR_CH2IF;
		capture1Ch2.isrCapture(event1);
	}
}

void TIM1_CC_IRQHandler(void)
{
	bool event1 = false;

	if (TIMER1->DIE & TIMER_DIE_UPIE && TIMER1->STR & TIMER_STR_UPIF)
	{
		TIMER1->STR = ~TIMER_STR_UPIF;
		capture1Ch1.isrUpdate();
		event1 = true;
	}

	if (TIMER1->DIE & TIMER_DIE_CH1IE && TIMER1->STR & TIMER_STR_CH1IF)
	{
		TIMER1->STR = ~TIMER_STR_CH1IF;
		capture1Ch1.isrCapture(event1);
	}

	if (TIMER1->DIE & TIMER_DIE_CH2IE && TIMER1->STR & TIMER_STR_CH2IF)
	{
		TIMER1->STR = ~TIMER_STR_CH2IF;
		capture1Ch2.isrCapture(event1);
	}
}
}

#endif

#endif


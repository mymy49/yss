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

#include <drv/mcu.h>

#if defined(STM32F4) || defined(STM32F7) || defined(STM32F0) || defined(STM32F1) || defined(STM32G4)

#include <drv/peripheral.h>
#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/st/bitfield.h>

#if defined(STM32F4) || defined(STM32F7) || defined(STM32G4)
#define TIM1_UP_IRQn			TIM1_UP_TIM10_IRQn
#define	TIM6_IRQn				TIM6_DAC_IRQn
#define TIM14_IRQn				TIM8_TRG_COM_TIM14_IRQn

#define TIM1_UP_IRQHandler		TIM1_UP_TIM10_IRQHandler
#define TIM6_IRQHandler			TIM6_DAC_IRQHandler
#elif defined(STM32F0)
#define TIM1_UP_IRQn			TIM1_BRK_UP_TRG_COM_IRQn
#endif

static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};

uint32_t getApb1TimerClockFrequency(void)
{
#if defined(STM32F0)
	int8_t pre = gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE_Msk) >> RCC_CFGR_PPRE_Pos)];
#else
	int8_t pre = gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos)];
#endif

	if(pre > 1)
		return clock.getApb1ClockFrequency() << 1;
	else
		return clock.getApb1ClockFrequency();
}

uint32_t getApb2TimerClockFrequency(void)
{
#if defined(STM32F0)
	int8_t pre = gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE_Msk) >> RCC_CFGR_PPRE_Pos)];
#else
	int8_t pre = gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos)];
#endif

	if(pre > 1)
		return clock.getApb2ClockFrequency() << 1;
	else
		return clock.getApb2ClockFrequency();
}

#if TIM1_ENABLE && (defined(TIMER1) || defined(TIM1))
#if (1 < TIM1_ENABLE + PWM1_ENABLE + QENCODER1_ENABLE + CAPTURE1_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer1Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_TIM1EN_Pos, en);
	clock.unlock();
}

static void enableTimer1Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM1_UP_IRQn, en);
	nvic.unlock();
}

static void resetTimer1(void)
{
	clock.lock();
    clock.resetApb2(11);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer1Setup = 
{
	enableTimer1Clock,			//void (*clockFunc)(bool en);
	enableTimer1Interrup,		//void (*nvicFunc)(bool en);
	resetTimer1,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer1Setup = 
{
	TIM1,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer1(gDrvTimer1Setup, gTimer1Setup);

extern "C"
{
void TIM1_UP_IRQHandler(void)
{
	if (TIM1->DIER & TIM_DIER_UIE_Msk && TIM1->SR & TIM_SR_UIF_Msk)
	{
		TIM1->SR = ~TIM_SR_UIF_Msk;
		timer1.isrUpdate();
	}

#if TIM10_ENABLE && defined(TIM10)
#define TIMER10_ISR_DEFINED
	if (TIM10->DIER & TIM_DIER_UIE_Msk && TIM10->SR & TIM_SR_UIF_Msk)
	{
		TIM10->SR = ~TIM_SR_UIF_Msk;
		timer10.isrUpdate();
	}
#endif
}
}
#endif



#if TIM2_ENABLE && (defined(TIMER2) || defined(TIM2))
#if (1 < TIM2_ENABLE + PWM2_ENABLE + QENCODER2_ENABLE + CAPTURE2_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer2Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_TIM2EN_Pos, en);
#else
    clock.enableApb1Clock(RCC_APB1ENR_TIM2EN_Pos, en);
#endif
	clock.unlock();
}

static void enableTimer2Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM2_IRQn, en);
	nvic.unlock();
}

static void resetTimer2(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_TIM2RST_Pos);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer2Setup = 
{
	enableTimer2Clock,			//void (*clockFunc)(bool en);
	enableTimer2Interrup,		//void (*nvicFunc)(bool en);
	resetTimer2,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer2Setup = 
{
	TIM2,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer2(gDrvTimer2Setup, gTimer2Setup);

extern "C"
{
void TIM2_IRQHandler(void)
{
	if (TIM2->DIER & TIM_DIER_UIE_Msk && TIM2->SR & TIM_SR_UIF_Msk)
	{
		TIM2->SR = ~TIM_SR_UIF_Msk;
		timer2.isrUpdate();
	}
}
}
#endif



#if TIM3_ENABLE && (defined(TIMER3) || defined(TIM3))
#if (1 < TIM3_ENABLE + PWM3_ENABLE + QENCODER3_ENABLE + CAPTURE3_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer3Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_TIM3EN_Pos, en);
#else
    clock.enableApb1Clock(RCC_APB1ENR_TIM3EN_Pos, en);
#endif
	clock.unlock();
}

static void enableTimer3Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM3_IRQn, en);
	nvic.unlock();
}

static void resetTimer3(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_TIM3RST_Pos);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer3Setup = 
{
	enableTimer3Clock,			//void (*clockFunc)(bool en);
	enableTimer3Interrup,		//void (*nvicFunc)(bool en);
	resetTimer3,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer3Setup = 
{
	TIM3,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer3(gDrvTimer3Setup, gTimer3Setup);

extern "C"
{
void TIM3_IRQHandler(void)
{
	if (TIM3->DIER & TIM_DIER_UIE_Msk && TIM3->SR & TIM_SR_UIF_Msk)
	{
		TIM3->SR = ~TIM_SR_UIF_Msk;
		timer3.isrUpdate();
	}
}
}
#endif



#if TIM4_ENABLE && (defined(TIMER4) || defined(TIM4))
#if (1 < TIM4_ENABLE + PWM4_ENABLE + QENCODER4_ENABLE + CAPTURE4_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer4Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_TIM4EN_Pos, en);
#else
    clock.enableApb1Clock(RCC_APB1ENR_TIM4EN_Pos, en);
#endif
	clock.unlock();
}

static void enableTimer4Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM4_IRQn, en);
	nvic.unlock();
}

static void resetTimer4(void)
{
	clock.lock();
    clock.resetApb1(2);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer4Setup = 
{
	enableTimer4Clock,			//void (*clockFunc)(bool en);
	enableTimer4Interrup,		//void (*nvicFunc)(bool en);
	resetTimer4,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer4Setup = 
{
	TIM4,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer4(gDrvTimer4Setup, gTimer4Setup);

extern "C"
{
void TIM4_IRQHandler(void)
{
	if (TIM4->DIER & TIM_DIER_UIE_Msk && TIM4->SR & TIM_SR_UIF_Msk)
	{
		TIM4->SR = ~TIM_SR_UIF_Msk;
		timer4.isrUpdate();
	}
}
}
#endif



#if TIM5_ENABLE && defined(TIM5)
#if (1 < TIM5_ENABLE + PWM5_ENABLE + QENCODER5_ENABLE + CAPTURE5_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer5Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_TIM5EN_Pos, en);
#else
    clock.enableApb1Clock(RCC_APB1ENR_TIM5EN_Pos, en);
#endif
	clock.unlock();
}

static void enableTimer5Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM5_IRQn, en);
	nvic.unlock();
}

static void resetTimer5(void)
{
	clock.lock();
    clock.resetApb1(3);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer5Setup = 
{
	enableTimer5Clock,			//void (*clockFunc)(bool en);
	enableTimer5Interrup,		//void (*nvicFunc)(bool en);
	resetTimer5,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer5Setup = 
{
	TIM5,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer5(gDrvTimer5Setup, gTimer5Setup);

extern "C"
{
void TIM5_IRQHandler(void)
{
	if (TIM5->DIER & TIM_DIER_UIE_Msk && TIM5->SR & TIM_SR_UIF_Msk)
	{
		TIM5->SR = ~TIM_SR_UIF_Msk;
		timer5.isrUpdate();
	}
}
}
#endif



#if TIM6_ENABLE && defined(TIM6)
#if (1 < TIM6_ENABLE + PWM6_ENABLE + QENCODER6_ENABLE + CAPTURE6_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer6Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_TIM6EN_Pos, en);
#else
    clock.enableApb1Clock(RCC_APB1ENR_TIM6EN_Pos, en);
#endif
	clock.unlock();
}

static void enableTimer6Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM6_IRQn, en);
	nvic.unlock();
}

static void resetTimer6(void)
{
	clock.lock();
#if defined(STM32G4)
    clock.resetApb1_1(RCC_APB1RSTR1_TIM6RST_Pos);
#else
    clock.resetApb1(RCC_APB1RSTR_TIM6RST_Pos);
#endif
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer6Setup = 
{
	enableTimer6Clock,			//void (*clockFunc)(bool en);
	enableTimer6Interrup,		//void (*nvicFunc)(bool en);
	resetTimer6,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer6Setup = 
{
	TIM6,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer6(gDrvTimer6Setup, gTimer6Setup);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER5_IRQHandler(void)
#else
void TIM6_IRQHandler(void)
#endif
{
	if (TIM6->DIER & TIM_DIER_UIE_Msk && TIM6->SR & TIM_SR_UIF_Msk)
	{
		TIM6->SR = ~TIM_SR_UIF_Msk;
		timer6.isrUpdate();
	}
}
}
#endif



#if TIM7_ENABLE && (defined(TIMER7_IRQn) || defined(TIM7))
#if (1 < TIM7_ENABLE + PWM7_ENABLE + QENCODER7_ENABLE + CAPTURE7_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer7Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_TIM7EN_Pos, en);
	clock.unlock();
}

static void enableTimer7Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM7_IRQn, en);
	nvic.unlock();
}

static void resetTimer7(void)
{
	clock.lock();
    clock.resetApb1(5);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer7Setup = 
{
	enableTimer7Clock,			//void (*clockFunc)(bool en);
	enableTimer7Interrup,		//void (*nvicFunc)(bool en);
	resetTimer7,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer7Setup = 
{
	TIM7,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer7(gDrvTimer7Setup, gTimer7Setup);

extern "C"
{
void TIM7_IRQHandler(void)
{
	if (TIM7->DIER & TIM_DIER_UIE_Msk && TIM7->SR & TIM_SR_UIF_Msk)
	{
		TIM7->SR = ~TIM_SR_UIF_Msk;
		timer7.isrUpdate();
	}
}
}

#endif

#if TIM8_ENABLE && defined(TIM8)
#if (1 < TIM8_ENABLE + PWM8_ENABLE + QENCODER8_ENABLE + CAPTURE8_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer8Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_TIM8EN_Pos, en);
	clock.unlock();
}

static void enableTimer8Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM8_UP_TIM13_IRQn, en);
	nvic.unlock();
}

static void resetTimer8(void)
{
	clock.lock();
    clock.resetApb2(13);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer8Setup = 
{
	enableTimer8Clock,			//void (*clockFunc)(bool en);
	enableTimer8Interrup,		//void (*nvicFunc)(bool en);
	resetTimer8,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer8Setup = 
{
	TIM8,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer8(gDrvTimer8Setup, gTimer8Setup);

extern "C"
{
void TIM8_UP_TIM13_IRQHandler(void)
{
	if (TIM8->DIER & TIM_DIER_UIE_Msk && TIM8->SR & TIM_SR_UIF_Msk)
	{
		TIM8->SR = ~TIM_SR_UIF_Msk;
		timer8.isrUpdate();
	}

#if TIM13_ENABLE && defined(TIM13)
#define TIMER13_ISR_DEFINED
	if (TIM13->DIER & TIM_DIER_UIE_Msk && TIM13->SR & TIM_SR_UIF_Msk)
	{
		TIM13->SR = ~TIM_SR_UIF_Msk;
		timer13.isrUpdate();
	}
#endif
}
}
#endif

#if TIM9_ENABLE && defined(TIM9)
#if (1 < TIM9_ENABLE + PWM9_ENABLE + QENCODER9_ENABLE + CAPTURE9_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer9Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_TIM9EN_Pos, en);
	clock.unlock();
}

static void enableTimer9Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM1_BRK_TIM9_IRQn, en);
	nvic.unlock();
}

static void resetTimer9(void)
{
	clock.lock();
    clock.resetApb2(19);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer9Setup = 
{
	enableTimer9Clock,			//void (*clockFunc)(bool en);
	enableTimer9Interrup,		//void (*nvicFunc)(bool en);
	resetTimer9,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer9Setup = 
{
	TIM9,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer9(gDrvTimer9Setup, gTimer9Setup);

extern "C"
{
void TIM1_BRK_TIM9_IRQHandler(void)
{
	if (TIM9->DIER & TIM_DIER_UIE_Msk && TIM9->SR & TIM_SR_UIF_Msk)
	{
		TIM9->SR = ~TIM_SR_UIF_Msk;
		timer9.isrUpdate();
	}
}
}
#endif

#if TIM10_ENABLE && defined(TIM10)
#if (1 < TIM10_ENABLE + PWM10_ENABLE + QENCODER10_ENABLE + CAPTURE10_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer10Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_TIM10EN_Pos, en);
	clock.unlock();
}

static void enableTimer10Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM1_UP_TIM10_IRQn, en);
	nvic.unlock();
}

static void resetTimer10(void)
{
	clock.lock();
    clock.resetApb2(20);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer10Setup = 
{
	enableTimer10Clock,			//void (*clockFunc)(bool en);
	enableTimer10Interrup,		//void (*nvicFunc)(bool en);
	resetTimer10,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer10Setup = 
{
	TIM10,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer10(gDrvTimer10Setup, gTimer10Setup);

#ifndef TIMER10_ISR_DEFINED
extern "C"
{
void TIM1_UP_TIM10_IRQHandler(void)
{
	if (TIM10->DIER & TIM_DIER_UIE_Msk && TIM10->SR & TIM_SR_UIF_Msk)
	{
		TIM10->SR = ~TIM_SR_UIF_Msk;
		timer10.isrUpdate();
	}
}
}
#endif

#endif



#if TIM11_ENABLE && defined(TIM11)
#if (1 < TIM11_ENABLE + PWM11_ENABLE + QENCODER11_ENABLE + CAPTURE11_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer11Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_TIM11EN_Pos, en);
	clock.unlock();
}

static void enableTimer11Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM1_TRG_COM_TIM11_IRQn, en);
	nvic.unlock();
}

static void resetTimer11(void)
{
	clock.lock();
    clock.resetApb2(21);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer11Setup = 
{
	enableTimer11Clock,			//void (*clockFunc)(bool en);
	enableTimer11Interrup,		//void (*nvicFunc)(bool en);
	resetTimer11,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer11Setup = 
{
	TIM11,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer11(gDrvTimer11Setup, gTimer11Setup);

extern "C"
{
void TIM1_TRG_COM_TIM11_IRQHandler(void)
{
	if (TIM11->DIER & TIM_DIER_UIE_Msk && TIM11->SR & TIM_SR_UIF_Msk)
	{
		TIM11->SR = ~TIM_SR_UIF_Msk;
		timer11.isrUpdate();
	}
}
}
#endif



#if TIM12_ENABLE && defined(TIM12)
#if (1 < TIM12_ENABLE + PWM12_ENABLE + QENCODER12_ENABLE + CAPTURE12_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer12Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(RCC_APB1ENR_TIM12EN_Pos, en);
	clock.unlock();
}

static void enableTimer12Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM8_BRK_TIM12_IRQn, en);
	nvic.unlock();
}

static void resetTimer12(void)
{
	clock.lock();
    clock.resetApb1(6);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer12Setup = 
{
	enableTimer12Clock,			//void (*clockFunc)(bool en);
	enableTimer12Interrup,		//void (*nvicFunc)(bool en);
	resetTimer12,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer12Setup = 
{
	TIM12,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer12(gDrvTimer12Setup, gTimer12Setup);

extern "C"
{
void TIM8_BRK_TIM12_IRQHandler(void)
{
	if (TIM12->DIER & TIM_DIER_UIE_Msk && TIM12->SR & TIM_SR_UIF_Msk)
	{
		TIM12->SR = ~TIM_SR_UIF_Msk;
		timer12.isrUpdate();
	}
}
}
#endif



#if TIM13_ENABLE && defined(TIM13)
#if (1 < TIM13_ENABLE + PWM13_ENABLE + QENCODER13_ENABLE + CAPTURE13_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer13Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(RCC_APB1ENR_TIM13EN_Pos, en);
	clock.unlock();
}

static void enableTimer13Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM8_UP_TIM13_IRQn, en);
	nvic.unlock();
}

static void resetTimer13(void)
{
	clock.lock();
    clock.resetApb1(7);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer13Setup = 
{
	enableTimer13Clock,			//void (*clockFunc)(bool en);
	enableTimer13Interrup,		//void (*nvicFunc)(bool en);
	resetTimer13,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer13Setup = 
{
	TIM13,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer13(gDrvTimer13Setup, gTimer13Setup);

#ifndef TIMER13_ISR_DEFINED
extern "C"
{
void TIM8_UP_TIM13_IRQHandler(void)
{
	if (TIM13->DIER & TIM_DIER_UIE_Msk && TIM13->SR & TIM_SR_UIF_Msk)
	{
		TIM13->SR = ~TIM_SR_UIF_Msk;
		timer13.isrUpdate();
	}
}
}
#endif
#endif



#if TIM14_ENABLE && defined(TIM14)
#if (1 < TIM14_ENABLE + PWM14_ENABLE + QENCODER14_ENABLE + CAPTURE14_ENABLE)
	#error "STM32에서는 같은 번호의 TIM, PWM, QENCODER, CAPTURE의 중복 사용을 금지합니다."	
#endif
static void enableTimer14Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(RCC_APB1ENR_TIM14EN_Pos, en);
	clock.unlock();
}

static void enableTimer14Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIM14_IRQn, en);
	nvic.unlock();
}

static void resetTimer14(void)
{
	clock.lock();
    clock.resetApb1(8);
	clock.unlock();
}

static const Drv::Setup_t gDrvTimer14Setup = 
{
	enableTimer14Clock,			//void (*clockFunc)(bool en);
	enableTimer14Interrup,		//void (*nvicFunc)(bool en);
	resetTimer14,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup_t gTimer14Setup = 
{
	TIM14,						//YSS_TIMER_Dev *dev;
	Timer::BIT::BIT_16			//uint8_t bit;
};

Timer timer14(gDrvTimer14Setup, gTimer14Setup);

extern "C"
{
void TIM8_TRG_COM_TIM14_IRQHandler(void)
{
	if (TIM14->DIER & TIM_DIER_UIE_Msk && TIM14->SR & TIM_SR_UIF_Msk)
	{
		TIM14->SR = ~TIM_SR_UIF_Msk;
		timer14.isrUpdate();
	}
}
}
#endif

#endif


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

#if defined(STM32F4_N) || defined(STM32F7_N) || defined(STM32F0_N) || defined(STM32F1_N)

#include <drv/peripheral.h>
#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#elif defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#elif defined(STM32F030xC)
#include <targets/st/bitfield_stm32f030xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#elif defined(STM32F103xB) || defined(STM32F103xE)
#include <targets/st/bitfield_stm32f103xx.h>
#endif

#if defined(STM32F4) || defined(STM32F7) || defined(STM32F4_N) || defined(STM32F7_N)
#define TIM1_UP_IRQn			TIM1_UP_TIM10_IRQn
#define	TIM6_IRQn				TIM6_DAC_IRQn
#define TIM14_IRQn				TIM8_TRG_COM_TIM14_IRQn

#define TIM1_UP_IRQHandler		TIM1_UP_TIM10_IRQHandler
#define TIM6_IRQHandler			TIM6_DAC_IRQHandler
#elif defined(STM32F0_N)
#define TIM1_UP_IRQn			TIM1_BRK_UP_TRG_COM_IRQn
#endif

static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};

uint32_t getApb1TimerClockFrequency(void)
{
#if defined(STM32F0_N)
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
#if defined(STM32F0_N)
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

static const Drv::Setup gDrvTimer1Setup = 
{
	enableTimer1Clock,			//void (*clockFunc)(bool en);
	enableTimer1Interrup,		//void (*nvicFunc)(bool en);
	resetTimer1,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer1Setup = 
{
	TIM1
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

#if defined(TIM10_ENABLE) && defined(TIM10)
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

static const Drv::Setup gDrvTimer2Setup = 
{
	enableTimer2Clock,			//void (*clockFunc)(bool en);
	enableTimer2Interrup,		//void (*nvicFunc)(bool en);
	resetTimer2,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer2Setup = 
{
	TIM2
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

static const Drv::Setup gDrvTimer3Setup = 
{
	enableTimer3Clock,			//void (*clockFunc)(bool en);
	enableTimer3Interrup,		//void (*nvicFunc)(bool en);
	resetTimer3,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer3Setup = 
{
	TIM3
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

static const Drv::Setup gDrvTimer4Setup = 
{
	enableTimer4Clock,			//void (*clockFunc)(bool en);
	enableTimer4Interrup,		//void (*nvicFunc)(bool en);
	resetTimer4,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer4Setup = 
{
	TIM4
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

static const Drv::Setup gDrvTimer5Setup = 
{
	enableTimer5Clock,			//void (*clockFunc)(bool en);
	enableTimer5Interrup,		//void (*nvicFunc)(bool en);
	resetTimer5,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer5Setup = 
{
	TIM5
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
    clock.resetApb1(4);
	clock.unlock();
}

static const Drv::Setup gDrvTimer6Setup = 
{
	enableTimer6Clock,			//void (*clockFunc)(bool en);
	enableTimer6Interrup,		//void (*nvicFunc)(bool en);
	resetTimer6,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer6Setup = 
{
	TIM6
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

static const Drv::Setup gDrvTimer7Setup = 
{
	enableTimer7Clock,			//void (*clockFunc)(bool en);
	enableTimer7Interrup,		//void (*nvicFunc)(bool en);
	resetTimer7,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer7Setup = 
{
	TIM7
};

Timer timer7(gDrvTimer7Setup, gTimer7Setup);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER6_IRQHandler(void)
#else
void TIMER7_IRQHandler(void)
#endif
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

static const Drv::Setup gDrvTimer8Setup = 
{
	enableTimer8Clock,			//void (*clockFunc)(bool en);
	enableTimer8Interrup,		//void (*nvicFunc)(bool en);
	resetTimer8,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer8Setup = 
{
	TIM8
};

Timer timer8(gDrvTimer8Setup, gTimer8Setup);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER7_UP_TIMER12_IRQHandler(void)
#else
void TIMER8_UP_TIMER13_IRQHandler(void)
#endif
{
	if (TIM8->DIER & TIM_DIER_UIE_Msk && TIM8->SR & TIM_SR_UIF_Msk)
	{
		TIM8->SR = ~TIM_SR_UIF_Msk;
		timer8.isrUpdate();
	}

#if defined(TIM13_ENABLE) && defined(TIMER13)
#define TIMER13_ISR_DEFINED
	if (TIMER13->DIE & TIM_DIER_UIE_Msk && TIMER13->STR & TIM_SR_UIF_Msk)
	{
		TIMER13->STR = ~TIM_SR_UIF_Msk;
		timer13.isrUpdate();
	}
#endif
}
}
#endif

#if TIM9_ENABLE && defined(TIM9)
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

static const Drv::Setup gDrvTimer9Setup = 
{
	enableTimer9Clock,			//void (*clockFunc)(bool en);
	enableTimer9Interrup,		//void (*nvicFunc)(bool en);
	resetTimer9,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer9Setup = 
{
	TIM9
};

Timer timer9(gDrvTimer9Setup, gTimer9Setup);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER0_BRK_TIMER8_IRQHandler(void)
#else
void TIMER1_BRK_TIMER9_IRQHandler(void)
#endif
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

static const Drv::Setup gDrvTimer10Setup = 
{
	enableTimer10Clock,			//void (*clockFunc)(bool en);
	enableTimer10Interrup,		//void (*nvicFunc)(bool en);
	resetTimer10,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer10Setup = 
{
	TIM10
};

Timer timer10(gDrvTimer10Setup, gTimer10Setup);

#ifndef TIMER10_ISR_DEFINED
extern "C"
{
#if defined(__SEGGER_LINKER)
void TIM0_UP_TIM9_IRQHandler(void)
#else
void TIM1_UP_TIM10_IRQHandler(void)
#endif
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

static const Drv::Setup gDrvTimer11Setup = 
{
	enableTimer11Clock,			//void (*clockFunc)(bool en);
	enableTimer11Interrup,		//void (*nvicFunc)(bool en);
	resetTimer11,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer11Setup = 
{
	TIM11
};

Timer timer11(gDrvTimer11Setup, gTimer11Setup);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER0_TRG_COM_TIMER10_IRQHandler(void)
#else
void TIMER1_TRG_COM_TIMER11_IRQHandler(void)
#endif
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

static const Drv::Setup gDrvTimer12Setup = 
{
	enableTimer12Clock,			//void (*clockFunc)(bool en);
	enableTimer12Interrup,		//void (*nvicFunc)(bool en);
	resetTimer12,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer12Setup = 
{
	TIM12
};

Timer timer12(gDrvTimer12Setup, gTimer12Setup);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER7_BRK_TIMER11_IRQHandler(void)
#else
void TIM8_BRK_TIM12_IRQHandler(void)
#endif
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

static const Drv::Setup gDrvTimer13Setup = 
{
	enableTimer13Clock,			//void (*clockFunc)(bool en);
	enableTimer13Interrup,		//void (*nvicFunc)(bool en);
	resetTimer13,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer13Setup = 
{
	TIM13
};

Timer timer13(gDrvTimer13Setup, gTimer13Setup);

#ifndef TIMER13_ISR_DEFINED
extern "C"
{
#if defined(__SEGGER_LINKER)
void TIM7_UP_TIM12_IRQHandler(void)
#else
void TIM8_UP_TIM13_IRQHandler(void)
#endif
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

static const Drv::Setup gDrvTimer14Setup = 
{
	enableTimer14Clock,			//void (*clockFunc)(bool en);
	enableTimer14Interrup,		//void (*nvicFunc)(bool en);
	resetTimer14,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::Setup gTimer14Setup = 
{
	TIM14
};

Timer timer14(gDrvTimer14Setup, gTimer14Setup);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER7_TRG_COM_TIMER13_IRQHandler(void)
#else
void TIMER8_TRG_COM_TIMER14_IRQHandler(void)
#endif
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


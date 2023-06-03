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

#if defined (STM32F1) || defined(STM32F4) || defined(GD32F4) || defined(STM32F7) || defined(STM32L1) || \
	defined(STM32F0) || defined(STM32G4)

#include <drv/peripheral.h>
#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/st_gigadevice/timer_stm32_gd32.h>

#if defined(GD32F1)
#include <targets/st/define_stm32f103xb.h>
#elif defined (STM32F1)
#include <targets/st_gigadevice/rcc_stm32_gd32f1.h>
#elif defined(STM32F4) || defined(GD32F4) || defined(STM32F7)
#include <targets/st_gigadevice/rcc_stm32_gd32f4_f7.h>
#elif defined(STM32L1)
#include <targets/st_gigadevice/rcc_stm32l1.h>
#elif defined(STM32F0)
#include <targets/st_gigadevice/rcc_stm32f0.h>
#elif defined(STM32G4)
#include <targets/st_gigadevice/rcc_stm32g4.h>
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_CL)
#define TIM1_UP_IRQn			TIM1_UP_TIM10_IRQn

#define TIM1_UP_IRQHandler		TIMER1_UP_TIMER10_IRQHandler
#define TIM2_IRQHandler			TIMER2_IRQHandler
#define TIM3_IRQHandler			TIMER3_IRQHandler
#define TIM4_IRQHandler			TIMER4_IRQHandler
#define TIM5_IRQHandler			TIMER5_IRQHandler
#define TIM6_IRQHandler			TIMER6_IRQHandler
#define TIM7_IRQHandler			TIMER7_IRQHandler
#define TIM8_UP_IRQHandler		TIMER8_UP_TIMER13_IRQHandler
#elif defined(GD32F10X_HD)
#define TIM1_UP_IRQHandler		TIMER1_UP_IRQHandler
#define TIM2_IRQHandler			TIMER2_IRQHandler
#define TIM3_IRQHandler			TIMER3_IRQHandler
#define TIM4_IRQHandler			TIMER4_IRQHandler
#define TIM5_IRQHandler			TIMER5_IRQHandler
#define TIM6_IRQHandler			TIMER6_IRQHandler
#define TIM7_IRQHandler			TIMER7_IRQHandler
#define TIM8_UP_IRQHandler		TIMER8_UP_TIMER13_IRQHandler
#elif defined(GD32F10X_MD)
#define TIM1_UP_IRQHandler		TIMER1_UP_IRQHandler
#define TIM2_IRQHandler			TIMER2_IRQHandler
#define TIM3_IRQHandler			TIMER3_IRQHandler
#define TIM4_IRQHandler			TIMER4_IRQHandler

#elif defined(STM32F4) || defined(STM32F7)
#define TIM1_UP_IRQHandler		TIM1_UP_TIM10_IRQHandler
#define TIM1_UP_IRQn			TIM1_UP_TIM10_IRQn
#define	TIM6_IRQn				TIM6_DAC_IRQn
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
#elif defined(STM32F0)
#define TIM1_UP_IRQn			TIM1_BRK_UP_TRG_COM_IRQn
#elif defined(STM32G4)
#define TIM1_UP_IRQn			TIM1_UP_TIM16_IRQn
#define TIM6_IRQn				TIM6_DAC_IRQn
#endif

static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};

#if defined (STM32F0)
uint32_t getApb1TimerClockFrequency(void)
{
	int8_t pre = gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE_Msk) >> RCC_CFGR_PPRE_Pos)];

	if(pre > 1)
		return getApb1ClockFrequency() << 1;
	else
		return getApb1ClockFrequency();
}

uint32_t getApb2TimerClockFrequency(void)
{
	int8_t pre = gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE_Msk) >> RCC_CFGR_PPRE_Pos)];

	if(pre > 1)
		return getApb2ClockFrequency() << 1;
	else
		return getApb2ClockFrequency();
}
#else
uint32_t getApb1TimerClockFrequency(void)
{
	//int8_t pre = gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos)];

	//if(pre > 1)
	//	return clock.getApb1ClockFrequency() << 1;
	//else
	//	return clock.getApb1ClockFrequency();
	return 0;
}

uint32_t getApb2TimerClockFrequency(void)
{
	//int8_t pre = gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos)];

	//if(pre > 1)
	//	return clock.getApb2ClockFrequency() << 1;
	//else
	//	return clock.getApb2ClockFrequency();
	return 0;
}
#endif

#if defined(TIM1_ENABLE) && (defined(TIMER1) || defined(TIM1))
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

static const Drv::Config gDrvTimer1Config = 
{
	enableTimer1Clock,			//void (*clockFunc)(bool en);
	enableTimer1Interrup,		//void (*nvicFunc)(bool en);
	resetTimer1,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer1((volatile uint32_t*)TIM1, gDrvTimer1Config);

extern "C"
{
void TIM1_UP_IRQHandler(void)
{
	if (TIM1->DIER & TIM_DIER_UIE_Msk && TIM1->SR & TIM_SR_UIF_Msk)
	{
		TIM1->SR = ~TIM_SR_UIF_Msk;
		timer1.isrUpdate();
	}

#if defined(TIM10_ENABLE) && defined(TIMER10)
#define TIMER10_ISR_DEFINED
	if (TIMER10->DIE & TIM_DIER_UIE_Msk && TIMER10->STR & TIM_SR_UIF_Msk)
	{
		TIMER10->STR = ~TIM_SR_UIF_Msk;
		timer10.isrUpdate();
	}
#endif
}
}
#endif



#if defined(TIM2_ENABLE) && (defined(TIMER2) || defined(TIM2))
static void enableTimer2Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_TIM2EN_Pos, en);
#else
    clock.enableApb1Clock(0, en);
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
    clock.resetApb1(0);
	clock.unlock();
}

static const Drv::Config gDrvTimer2Config = 
{
	enableTimer2Clock,			//void (*clockFunc)(bool en);
	enableTimer2Interrup,		//void (*nvicFunc)(bool en);
	resetTimer2,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer2((volatile uint32_t*)TIM2, gDrvTimer2Config);

extern "C"
{
void TIM2_IRQHandler(void)
{
	if (TIM2[TIM_REG::DIER] & TIM_DIER_UIE_Msk && TIM2[TIM_REG::SR] & TIM_SR_UIF_Msk)
	{
		TIM2[TIM_REG::SR] = ~TIM_SR_UIF_Msk;
		timer2.isrUpdate();
	}
}
}
#endif



#if defined(TIM3_ENABLE) && (defined(TIMER3) || defined(TIM3))
static void enableTimer3Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_TIM3EN_Pos, en);
#else
    clock.enableApb1Clock(1, en);
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
    clock.resetApb1(1);
	clock.unlock();
}

static const Drv::Config gDrvTimer3Config = 
{
	enableTimer3Clock,			//void (*clockFunc)(bool en);
	enableTimer3Interrup,		//void (*nvicFunc)(bool en);
	resetTimer3,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer3((volatile uint32_t*)TIM3, gDrvTimer3Config);

extern "C"
{
void TIM3_IRQHandler(void)
{
	if (TIM3[TIM_REG::DIER] & TIM_DIER_UIE_Msk && TIM3[TIM_REG::SR] & TIM_SR_UIF_Msk)
	{
		TIM3[TIM_REG::SR] = ~TIM_SR_UIF_Msk;
		timer3.isrUpdate();
	}
}
}
#endif



#if defined(TIM4_ENABLE) && (defined(TIMER4) || defined(TIM4))
static void enableTimer4Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_TIM4EN_Pos, en);
#else
    clock.enableApb1Clock(2, en);
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

static const Drv::Config gDrvTimer4Config = 
{
	enableTimer4Clock,			//void (*clockFunc)(bool en);
	enableTimer4Interrup,		//void (*nvicFunc)(bool en);
	resetTimer4,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer4((volatile uint32_t*)TIM4, gDrvTimer4Config);

extern "C"
{
void TIM4_IRQHandler(void)
{
	if (TIM4[TIM_REG::DIER] & TIM_DIER_UIE_Msk && TIM4[TIM_REG::SR] & TIM_SR_UIF_Msk)
	{
		TIM4[TIM_REG::SR] = ~TIM_SR_UIF_Msk;
		timer4.isrUpdate();
	}
}
}
#endif



#if defined(TIM5_ENABLE) && defined(TIM5_IRQn)
static void enableTimer5Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_TIM5EN_Pos, en);
#else
    clock.enableApb1Clock(3, en);
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

static const Drv::Config gDrvTimer5Config = 
{
	enableTimer5Clock,			//void (*clockFunc)(bool en);
	enableTimer5Interrup,		//void (*nvicFunc)(bool en);
	resetTimer5,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer5((volatile uint32_t*)TIM5, gDrvTimer5Config);

extern "C"
{
void TIM5_IRQHandler(void)
{
	if (TIM5[TIM_REG::DIER] & TIM_DIER_UIE_Msk && TIM5[TIM_REG::SR] & TIM_SR_UIF_Msk)
	{
		TIM5[TIM_REG::SR] = ~TIM_SR_UIF_Msk;
		timer5.isrUpdate();
	}
}
}
#endif



#if defined(TIM6_ENABLE) && defined(TIM6_IRQn)
static void enableTimer6Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_TIM6EN_Pos, en);
#else
    clock.enableApb1Clock(4, en);
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

static const Drv::Config gDrvTimer6Config = 
{
	enableTimer6Clock,			//void (*clockFunc)(bool en);
	enableTimer6Interrup,		//void (*nvicFunc)(bool en);
	resetTimer6,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer6((volatile uint32_t*)TIM6, gDrvTimer6Config);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER5_IRQHandler(void)
#else
void TIM6_IRQHandler(void)
#endif
{
	if (TIM6[TIM_REG::DIER] & TIM_DIER_UIE_Msk && TIM6[TIM_REG::SR] & TIM_SR_UIF_Msk)
	{
		TIM6[TIM_REG::SR] = ~TIM_SR_UIF_Msk;
		timer6.isrUpdate();
	}
}
}
#endif



#if defined(TIM7_ENABLE) && defined(TIMER7_IRQn)
static void enableTimer7Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(5, en);
	clock.unlock();
}

static void enableTimer7Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER7_IRQn, en);
	nvic.unlock();
}

static void resetTimer7(void)
{
	clock.lock();
    clock.resetApb1(5);
	clock.unlock();
}

static const Drv::Config gDrvTimer7Config = 
{
	enableTimer7Clock,			//void (*clockFunc)(bool en);
	enableTimer7Interrup,		//void (*nvicFunc)(bool en);
	resetTimer7,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer7((volatile uint32_t*)TIMER7, gDrvTimer7Config);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER6_IRQHandler(void)
#else
void TIMER7_IRQHandler(void)
#endif
{
	if (TIMER7->DIE & TIM_DIER_UIE_Msk && TIMER7->STR & TIM_SR_UIF_Msk)
	{
		TIMER7->STR = ~TIM_SR_UIF_Msk;
		timer7.isrUpdate();
	}
}
}

#endif

#if defined(TIM8_ENABLE) && defined(TIMER8_UP_TIMER13_IRQn)
static void enableTimer8Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(13, en);
	clock.unlock();
}

static void enableTimer8Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER8_UP_TIMER13_IRQn, en);
	nvic.unlock();
}

static void resetTimer8(void)
{
	clock.lock();
    clock.resetApb2(13);
	clock.unlock();
}

static const Drv::Config gDrvTimer8Config = 
{
	enableTimer8Clock,			//void (*clockFunc)(bool en);
	enableTimer8Interrup,		//void (*nvicFunc)(bool en);
	resetTimer8,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer8((volatile uint32_t*)TIMER8, gDrvTimer8Config);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER7_UP_TIMER12_IRQHandler(void)
#else
void TIMER8_UP_TIMER13_IRQHandler(void)
#endif
{
	if (TIMER8->DIE & TIM_DIER_UIE_Msk && TIMER8->STR & TIM_SR_UIF_Msk)
	{
		TIMER8->STR = ~TIM_SR_UIF_Msk;
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

#if defined(TIM9_ENABLE) && defined(TIMER1_BRK_TIMER9_IRQn)
static void enableTimer9Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(19, en);
	clock.unlock();
}

static void enableTimer9Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER1_BRK_TIMER9_IRQn, en);
	nvic.unlock();
}

static void resetTimer9(void)
{
	clock.lock();
    clock.resetApb2(19);
	clock.unlock();
}

static const Drv::Config gDrvTimer9Config = 
{
	enableTimer9Clock,			//void (*clockFunc)(bool en);
	enableTimer9Interrup,		//void (*nvicFunc)(bool en);
	resetTimer9,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer9((volatile uint32_t*)TIMER9, gDrvTimer9Config);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER0_BRK_TIMER8_IRQHandler(void)
#else
void TIMER1_BRK_TIMER9_IRQHandler(void)
#endif
{
	if (TIMER9->DIE & TIM_DIER_UIE_Msk && TIMER9->STR & TIM_SR_UIF_Msk)
	{
		TIMER9->STR = ~TIM_SR_UIF_Msk;
		timer9.isrUpdate();
	}
}
}
#endif

#if defined(TIM10_ENABLE) && defined(TIMER1_UP_TIMER10_IRQn)
static void enableTimer10Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(20, en);
	clock.unlock();
}

static void enableTimer10Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER1_UP_TIMER10_IRQn, en);
	nvic.unlock();
}

static void resetTimer10(void)
{
	clock.lock();
    clock.resetApb2(20);
	clock.unlock();
}

static const Drv::Config gDrvTimer10Config = 
{
	enableTimer10Clock,			//void (*clockFunc)(bool en);
	enableTimer10Interrup,		//void (*nvicFunc)(bool en);
	resetTimer10,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer10((volatile uint32_t*)TIMER10, gDrvTimer10Config);

#ifndef TIMER10_ISR_DEFINED
extern "C"
{
#if defined(__SEGGER_LINKER)
void TIM0_UP_TIM9_IRQHandler(void)
#else
void TIM1_UP_TIM10_IRQHandler(void)
#endif
{
	if (TIMER10->DIE & TIM_DIER_UIE_Msk && TIMER10->STR & TIM_SR_UIF_Msk)
	{
		TIMER10->STR = ~TIM_SR_UIF_Msk;
		timer10.isrUpdate();
	}
}
}
#endif

#endif



#if defined(TIM11_ENABLE) && defined(TIMER1_TRG_COM_TIMER11_IRQn)
static void enableTimer11Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(21, en);
	clock.unlock();
}

static void enableTimer11Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER1_TRG_COM_TIMER11_IRQn, en);
	nvic.unlock();
}

static void resetTimer11(void)
{
	clock.lock();
    clock.resetApb2(21);
	clock.unlock();
}

static const Drv::Config gDrvTimer11Config = 
{
	enableTimer11Clock,			//void (*clockFunc)(bool en);
	enableTimer11Interrup,		//void (*nvicFunc)(bool en);
	resetTimer11,				//void (*resetFunc)(void);
	getApb2TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer11((volatile uint32_t*)TIMER11, gDrvTimer11Config);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER0_TRG_COM_TIMER10_IRQHandler(void)
#else
void TIMER1_TRG_COM_TIMER11_IRQHandler(void)
#endif
{
	if (TIMER11->DIE & TIM_DIER_UIE_Msk && TIMER11->STR & TIM_SR_UIF_Msk)
	{
		TIMER11->STR = ~TIM_SR_UIF_Msk;
		timer11.isrUpdate();
	}
}
}
#endif



#if defined(TIM12_ENABLE) && defined(TIMER8_BRK_TIMER12_IRQn)
static void enableTimer12Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(6, en);
	clock.unlock();
}

static void enableTimer12Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER8_BRK_TIMER12_IRQn, en);
	nvic.unlock();
}

static void resetTimer12(void)
{
	clock.lock();
    clock.resetApb1(6);
	clock.unlock();
}

static const Drv::Config gDrvTimer12Config = 
{
	enableTimer12Clock,			//void (*clockFunc)(bool en);
	enableTimer12Interrup,		//void (*nvicFunc)(bool en);
	resetTimer12,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer12((volatile uint32_t*)TIMER12, gDrvTimer12Config);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER8_BRK_TIMER12_IRQHandler(void)
#else
void TIMER7_BRK_TIMER11_IRQHandler(void)
#endif
{
	if (TIMER12->DIE & TIM_DIER_UIE_Msk && TIMER12->STR & TIM_SR_UIF_Msk)
	{
		TIMER12->STR = ~TIM_SR_UIF_Msk;
		timer12.isrUpdate();
	}
}
}
#endif



#if defined(TIM13_ENABLE) && defined(TIMER8_UP_TIMER13_IRQn)
static void enableTimer13Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(7, en);
	clock.unlock();
}

static void enableTimer13Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER8_UP_TIMER13_IRQn, en);
	nvic.unlock();
}

static void resetTimer13(void)
{
	clock.lock();
    clock.resetApb1(7);
	clock.unlock();
}

static const Drv::Config gDrvTimer13Config = 
{
	enableTimer13Clock,			//void (*clockFunc)(bool en);
	enableTimer13Interrup,		//void (*nvicFunc)(bool en);
	resetTimer13,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer13((volatile uint32_t*)TIMER13, gDrvTimer13Config);

#ifndef TIMER13_ISR_DEFINED
extern "C"
{
#if defined(__SEGGER_LINKER)
void TIM7_UP_TIM12_IRQHandler(void)
#else
void TIM8_UP_TIM13_IRQHandler(void)
#endif
{
	if (TIMER13->DIE & TIM_DIER_UIE_Msk && TIMER13->STR & TIM_SR_UIF_Msk)
	{
		TIMER13->STR = ~TIM_SR_UIF_Msk;
		timer13.isrUpdate();
	}
}
}
#endif
#endif



#if defined(TIM14_ENABLE) && defined(TIMER8_TRG_COM_TIMER14_IRQn)
static void enableTimer14Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(8, en);
	clock.unlock();
}

static void enableTimer14Interrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER8_TRG_COM_TIMER14_IRQn, en);
	nvic.unlock();
}

static void resetTimer14(void)
{
	clock.lock();
    clock.resetApb1(8);
	clock.unlock();
}

static const Drv::Config gDrvTimer14Config = 
{
	enableTimer14Clock,			//void (*clockFunc)(bool en);
	enableTimer14Interrup,		//void (*nvicFunc)(bool en);
	resetTimer14,				//void (*resetFunc)(void);
	getApb1TimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

Timer timer14((volatile uint32_t*)TIMER14, gDrvTimer14Config);

extern "C"
{
#if defined(__SEGGER_LINKER)
void TIMER7_TRG_COM_TIMER13_IRQHandler(void)
#else
void TIMER8_TRG_COM_TIMER14_IRQHandler(void)
#endif
{
	if (TIMER14->DIE & TIM_DIER_UIE_Msk && TIMER14->STR & TIM_SR_UIF_Msk)
	{
		TIMER14->STR = ~TIM_SR_UIF_Msk;
		timer14.isrUpdate();
	}
}
}
#endif

#endif


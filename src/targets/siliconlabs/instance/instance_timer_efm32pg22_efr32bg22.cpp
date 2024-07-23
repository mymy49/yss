/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(EFM32PG22) || defined(EFR32BG22)

#include <drv/peripheral.h>
#include <yss/instance.h>
#include <config.h>

#if defined(EFM32PG22)
#include <targets/siliconlabs/efm32pg22_cmu.h>
#include <targets/siliconlabs/efm32pg22_timer.h>
#elif defined(EFR32BG22)
#include <targets/siliconlabs/efr32bg22_cmu.h>
#include <targets/siliconlabs/efr32bg22_timer.h>
#endif

static uint32_t  getApb0Frequency(void)
{
	return clock.getApb0Frequency();
}

static uint32_t  getApb1Frequency(void)
{
	return clock.getApb1Frequency();
}

#if defined(TIM0_ENABLE) && defined(TIMER0)
static void enableTimer0Clock(bool en)
{
	clock.lock();
    clock.enableApb0Clock(_CMU_CLKEN0_TIMER0_SHIFT, en);
	clock.unlock();
}

static void enableInterruptTim0(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER0_IRQn);
	nvic.unlock();
}

static const Timer::Setup gTimer0Setup = 
{
	TIMER0_S,
	Timer::BIT_32
};

static const Drv::setup_t gDrvTimer0Setup = 
{
	enableTimer0Clock,		//void (*clockFunc)(bool en);
	enableInterruptTim0,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getApb0Frequency		//uint32_t (*getClockFunc)(void);
};

Timer timer0(gDrvTimer0Setup, gTimer0Setup);

extern "C"
{
void TIMER0_IRQHandler(void)
{
	TIMER0_S->IF_CLR = _TIMER_IF_OF_MASK;
	timer0.isrUpdate();
}
}
#endif



#if defined(TIM1_ENABLE) && defined(TIMER1)
static void enableTimer1Clock(bool en)
{
	clock.lock();
    clock.enableApb0Clock(_CMU_CLKEN0_TIMER1_SHIFT, en);
	clock.unlock();
}

static void enableInterruptTim1(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER1_IRQn);
	nvic.unlock();
}

static const Timer::Setup gTimer1Setup = 
{
	TIMER1_S,
	Timer::BIT_16
};

static const Drv::setup_t gDrvTimer1Setup = 
{
	enableTimer1Clock,		//void (*clockFunc)(bool en);
	enableInterruptTim1,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getApb0Frequency		//uint32_t (*getClockFunc)(void);
};

Timer timer1(gDrvTimer1Setup, gTimer1Setup);

extern "C"
{
void TIMER1_IRQHandler(void)
{
	TIMER1_S->IF_CLR = _TIMER_IF_OF_MASK;
	timer1.isrUpdate();
}
}
#endif



#if defined(TIM2_ENABLE) && defined(TIMER2)
static void enableTimer2Clock(bool en)
{
	clock.lock();
    clock.enableApb0Clock(_CMU_CLKEN0_TIMER2_SHIFT, en);
	clock.unlock();
}

static void enableInterruptTim2(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER2_IRQn);
	nvic.unlock();
}

static const Timer::Setup gTimer2Setup = 
{
	TIMER2_S,
	Timer::BIT_16
};

static const Drv::setup_t gDrvTimer2Setup = 
{
	enableTimer2Clock,		//void (*clockFunc)(bool en);
	enableInterruptTim2,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getApb0Frequency		//uint32_t (*getClockFunc)(void);
};

Timer timer2(gDrvTimer2Setup, gTimer2Setup);

extern "C"
{
void TIMER2_IRQHandler(void)
{
	TIMER2_S->IF_CLR = _TIMER_IF_OF_MASK;
	timer2.isrUpdate();
}
}
#endif



#if defined(TIM3_ENABLE) && defined(TIMER3)
static void enableTimer3Clock(bool en)
{
	clock.lock();
    clock.enableApb0Clock(_CMU_CLKEN0_TIMER3_SHIFT, en);
	clock.unlock();
}

static void enableInterruptTim3(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER3_IRQn);
	nvic.unlock();
}

static const Timer::Setup gTimer3Setup = 
{
	TIMER3_S,
	Timer::BIT_16
};

static const Drv::setup_t gDrvTimer3Setup = 
{
	enableTimer3Clock,		//void (*clockFunc)(bool en);
	enableInterruptTim3,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getApb0Frequency		//uint32_t (*getClockFunc)(void);
};

Timer timer3(gDrvTimer3Setup, gTimer3Setup);

extern "C"
{
void TIMER3_IRQHandler(void)
{
	TIMER3_S->IF_CLR = _TIMER_IF_OF_MASK;
	timer3.isrUpdate();
}
}
#endif



#if defined(TIM4_ENABLE) && defined(TIMER4)
static void enableTimer4Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(_CMU_CLKEN1_TIMER4_SHIFT, en);
	clock.unlock();
}

static void enableInterruptTim4(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER4_IRQn);
	nvic.unlock();
}

static const Timer::Setup gTimer4Setup = 
{
	TIMER4_S,
	Timer::BIT_16
};

static const Drv::setup_t gDrvTimer4Setup = 
{
	enableTimer4Clock,		//void (*clockFunc)(bool en);
	enableInterruptTim4,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getApb1Frequency		//uint32_t (*getClockFunc)(void);
};

Timer timer4(gDrvTimer4Setup, gTimer4Setup);

extern "C"
{
void TIMER4_IRQHandler(void)
{
	TIMER4_S->IF_CLR = _TIMER_IF_OF_MASK;
	timer4.isrUpdate();
}
}
#endif

#endif


/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
/**
 * @file instance_gpio_nuvoton.cpp
 * @brief Global driver instances initialization for Nuvoton GPIO peripheral.
 */

#include <yss/instance.h>
#include <config.h>
#include <max32665.h>

#if defined(__MAX32665_FAMILY)

static uint32_t getTimerClockFrequency(void)
{
	return clock.getApbClockFrequency();
}

#if defined(MXC_TMR1) && TIMER1_ENABLE
#if YSS_TIMER == RUNTIME_TIM1
#error "TMR1 is currently used by the Yss OS Runtime. General use is not allowed."
#endif

static void enableTimer1Clock(bool en)
{
	clock.enableTmr1(en);
}

static void enableTimer1Interrupt(bool en)
{
	nvic.enableInterrupt(TMR1_IRQn, en);
}

static const Drv::setup_t gDrvTimer1Setup = 
{
	enableTimer1Clock,		//void (*clockFunc)(bool en);
	enableTimer1Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Max32665Timer::setup_t gTimer1Setup = 
{
	(mxc_tmr_regs_t*)MXC_TMR1	// YSS_TIMER_Dev *dev;
};

Max32665Timer timer1(gDrvTimer1Setup, gTimer1Setup);

extern "C"
{
	void TMR1_IRQHandler(void)
	{
		MXC_TMR1->intr = MXC_F_TMR_INTR_IRQ_CLR;
		timer1.isrUpdate();
	}
}
#endif



#if defined(MXC_TMR2) && TIMER2_ENABLE
#if YSS_TIMER == RUNTIME_TIM2
#error "TMR1 is currently used by the Yss OS Runtime. General use is not allowed."
#endif

static void enableTimer2Clock(bool en)
{
	clock.enableTmr2(en);
}

static void enableTimer2Interrupt(bool en)
{
	nvic.enableInterrupt(TMR2_IRQn, en);
}

static const Drv::setup_t gDrvTimer2Setup = 
{
	enableTimer2Clock,		//void (*clockFunc)(bool en);
	enableTimer2Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Max32665Timer::setup_t gTimer2Setup = 
{
	(mxc_tmr_regs_t*)MXC_TMR2	// YSS_TIMER_Dev *dev;
};

Max32665Timer timer2(gDrvTimer2Setup, gTimer2Setup);

extern "C"
{
	void TMR2_IRQHandler(void)
	{
		MXC_TMR2->intr = MXC_F_TMR_INTR_IRQ_CLR;
		timer2.isrUpdate();
	}
}
#endif



#if defined(MXC_TMR3) && TIMER3_ENABLE
#if YSS_TIMER == RUNTIME_TIM3
#error "TMR1 is currently used by the Yss OS Runtime. General use is not allowed."
#endif

static void enableTimer3Clock(bool en)
{
	clock.enableTmr3(en);
}

static void enableTimer3Interrupt(bool en)
{
	nvic.enableInterrupt(TMR3_IRQn, en);
}

static const Drv::setup_t gDrvTimer3Setup = 
{
	enableTimer3Clock,		//void (*clockFunc)(bool en);
	enableTimer3Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Max32665Timer::setup_t gTimer3Setup = 
{
	(mxc_tmr_regs_t*)MXC_TMR3	// YSS_TIMER_Dev *dev;
};

Max32665Timer timer3(gDrvTimer3Setup, gTimer3Setup);

extern "C"
{
	void TMR3_IRQHandler(void)
	{
		MXC_TMR3->intr = MXC_F_TMR_INTR_IRQ_CLR;
		timer3.isrUpdate();
	}
}
#endif



#if defined(MXC_TMR4) && TIMER4_ENABLE
#if YSS_TIMER == RUNTIME_TIM4
#error "TMR1 is currently used by the Yss OS Runtime. General use is not allowed."
#endif

static void enableTimer4Clock(bool en)
{
	clock.enableTmr4(en);
}

static void enableTimer4Interrupt(bool en)
{
	nvic.enableInterrupt(TMR4_IRQn, en);
}

static const Drv::setup_t gDrvTimer4Setup = 
{
	enableTimer4Clock,		//void (*clockFunc)(bool en);
	enableTimer4Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Max32665Timer::setup_t gTimer4Setup = 
{
	(mxc_tmr_regs_t*)MXC_TMR4	// YSS_TIMER_Dev *dev;
};

Max32665Timer timer4(gDrvTimer4Setup, gTimer4Setup);

extern "C"
{
	void TMR4_IRQHandler(void)
	{
		MXC_TMR4->intr = MXC_F_TMR_INTR_IRQ_CLR;
		timer4.isrUpdate();
	}
}
#endif



#if defined(MXC_TMR5) && TIMER5_ENABLE
#if YSS_TIMER == RUNTIME_TIM5
#error "TMR5 is currently used by the Yss OS Runtime. General use is not allowed."
#endif

static void enableTimer5Clock(bool en)
{
	clock.enableTmr5(en);
}

static void enableTimer5Interrupt(bool en)
{
	nvic.enableInterrupt(TMR5_IRQn, en);
}

static const Drv::setup_t gDrvTimer5Setup = 
{
	enableTimer5Clock,		//void (*clockFunc)(bool en);
	enableTimer5Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Max32665Timer::setup_t gTimer5Setup = 
{
	(mxc_tmr_regs_t*)MXC_TMR5	// YSS_TIMER_Dev *dev;
};

Max32665Timer timer5(gDrvTimer5Setup, gTimer5Setup);

extern "C"
{
	void TMR5_IRQHandler(void)
	{
		MXC_TMR5->intr = MXC_F_TMR_INTR_IRQ_CLR;
		timer5.isrUpdate();
	}
}
#endif

#endif


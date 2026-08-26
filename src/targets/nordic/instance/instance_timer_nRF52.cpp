/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <yss/instance.h>
#include <config.h>
#include <drv/peripheral.h>
#include <nrf52840_bitfields.h>

static uint32_t getTimerClockFrequency(void)
{
	return 16000000;
}

#if defined(NRF_TIMER0) && TIMER0_ENABLE
#if YSS_RUNTIME_TIMER == RUNTIME_TIMER0
#error "TIMER0 is currently used by the Yss OS Runtime. General use is not allowed."
#endif

static void enableTimer0Interrupt(bool en)
{
	nvic.enableInterrupt(TIMER0_IRQn, en);
}

static const Drv::setup_t gDrvTimer0Setup = 
{
	0,						//void (*clockFunc)(bool en);
	enableTimer0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const nRF52_Timer::setup_t gTimer0Setup = 
{
	(NRF_TIMER_Type*)NRF_TIMER0
};

nRF52_Timer timer0(gDrvTimer0Setup, gTimer0Setup);

extern "C"
{
	void TIMER0_IRQHandler(void)
	{
		NRF_TIMER0->EVENTS_COMPARE[0] = 0;
		timer0.isrUpdate();
	}
}
#endif



#if defined(NRF_TIMER1) && TIMER1_ENABLE
#if YSS_RUNTIME_TIMER == RUNTIME_TIMER1
#error "TIMER1 is currently used by the Yss OS Runtime. General use is not allowed."
#endif

static void enableTimer1Interrupt(bool en)
{
	nvic.enableInterrupt(TIMER1_IRQn, en);
}

static const Drv::setup_t gDrvTimer1Setup = 
{
	0,						//void (*clockFunc)(bool en);
	enableTimer1Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const nRF52_Timer::setup_t gTimer1Setup = 
{
	(NRF_TIMER_Type*)NRF_TIMER1
};

nRF52_Timer timer1(gDrvTimer1Setup, gTimer1Setup);

extern "C"
{
	void TIMER1_IRQHandler(void)
	{
		NRF_TIMER1->EVENTS_COMPARE[0] = 0;
		timer1.isrUpdate();
	}
}
#endif



#if defined(NRF_TIMER2) && TIMER2_ENABLE
#if YSS_RUNTIME_TIMER == RUNTIME_TIMER2
#error "TIMER2 is currently used by the Yss OS Runtime. General use is not allowed."
#endif

static void enableTimer2Interrupt(bool en)
{
	nvic.enableInterrupt(TIMER2_IRQn, en);
}

static const Drv::setup_t gDrvTimer2Setup = 
{
	0,						//void (*clockFunc)(bool en);
	enableTimer2Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const nRF52_Timer::setup_t gTimer2Setup = 
{
	(NRF_TIMER_Type*)NRF_TIMER2
};

nRF52_Timer timer2(gDrvTimer2Setup, gTimer2Setup);

extern "C"
{
	void TIMER2_IRQHandler(void)
	{
		NRF_TIMER2->EVENTS_COMPARE[0] = 0;
		timer2.isrUpdate();
	}
}
#endif



#if defined(NRF_TIMER3) && TIMER3_ENABLE
#if YSS_RUNTIME_TIMER == RUNTIME_TIMER3
#error "TIMER3 is currently used by the Yss OS Runtime. General use is not allowed."
#endif

static void enableTimer3Interrupt(bool en)
{
	nvic.enableInterrupt(TIMER3_IRQn, en);
}

static const Drv::setup_t gDrvTimer3Setup = 
{
	0,						//void (*clockFunc)(bool en);
	enableTimer3Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const nRF52_Timer::setup_t gTimer3Setup = 
{
	(NRF_TIMER_Type*)NRF_TIMER3
};

nRF52_Timer timer3(gDrvTimer3Setup, gTimer3Setup);

extern "C"
{
	void TIMER3_IRQHandler(void)
	{
		NRF_TIMER3->EVENTS_COMPARE[0] = 0;
		timer3.isrUpdate();
	}
}
#endif



#if defined(NRF_TIMER4) && TIMER4_ENABLE
#if YSS_RUNTIME_TIMER == RUNTIME_TIMER4
#error "TIMER4 is currently used by the Yss OS Runtime. General use is not allowed."
#endif

static void enableTimer4Interrupt(bool en)
{
	nvic.enableInterrupt(TIMER4_IRQn, en);
}

static const Drv::setup_t gDrvTimer4Setup = 
{
	0,						//void (*clockFunc)(bool en);
	enableTimer4Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimerClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const nRF52_Timer::setup_t gTimer4Setup = 
{
	(NRF_TIMER_Type*)NRF_TIMER4
};

nRF52_Timer timer4(gDrvTimer4Setup, gTimer4Setup);

extern "C"
{
	void TIMER4_IRQHandler(void)
	{
		NRF_TIMER4->EVENTS_COMPARE[0] = 0;
		timer4.isrUpdate();
	}
}
#endif

#endif


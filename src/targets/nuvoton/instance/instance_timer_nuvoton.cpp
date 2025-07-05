/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m4xx.h>

#if defined(TIMER0) && TIMER0_ENABLE
#if YSS_TIMER == RUNTIME_TIM0
#error "현재 TIMER0는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#endif

static void enableTimer0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_TMR0CKEN_Pos, en);
}

static void enableTimer0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(TMR0_IRQn, en);
}

static uint32_t getTimer0ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL1 & CLK_CLKSEL1_TMR0SEL_Msk) >> CLK_CLKSEL1_TMR0SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // LXT
		clk = 32768;
		break;

	case 2 : // PCLK
		clk = clock.getApb0ClockFrequency();
		break;
	
	case 4 : // LIRC
		clk = clock.getLircFrequency();
		break;

	case 5 : // LIRC
		clk = clock.getLircFrequency();
		break;

	case 7 : // LIRC
		clk = clock.getLircFrequency();
		break;

	default:
	case 3 : // TM0 Pin
		clk = 0;
	}

	return clk;
}

static const Drv::setup_t gDrvTimer0Setup = 
{
	enableTimer0Clock,		//void (*clockFunc)(bool en);
	enableTimer0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimer0ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::setup_t gTimer0Setup = 
{
	(YSS_TIMER_Dev*)TIMER0	// YSS_TIMER_Dev *dev;
};

Timer timer0(gDrvTimer0Setup, gTimer0Setup);

extern "C"
{
	void TMR0_IRQHandler(void)
	{
		TIMER0->INTSTS = TIMER_INTSTS_TIF_Msk;
		timer0.isrUpdate();
	}
}
#endif



#if defined(TIMER1) && TIMER1_ENABLE
#if YSS_TIMER == RUNTIME_TIM1
#error "현재 TIMER1는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#endif

static void enableTimer1Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_TMR1CKEN_Pos, en);
}

static void enableTimer1Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(TMR1_IRQn, en);
}

static uint32_t getTimer1ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL1 & CLK_CLKSEL1_TMR1SEL_Msk) >> CLK_CLKSEL1_TMR1SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // LXT
		clk = 32768;
		break;

	case 2 : // PCLK
		clk = clock.getApb0ClockFrequency();
		break;
	
	case 4 : // LIRC
		clk = clock.getLircFrequency();
		break;

	case 5 : // LIRC
		clk = clock.getLircFrequency();
		break;

	case 7 : // LIRC
		clk = clock.getLircFrequency();
		break;

	default:
	case 3 : // TM1 Pin
		clk = 0;
	}

	return clk;
}

static const Drv::setup_t gDrvTimer1Setup = 
{
	enableTimer1Clock,		//void (*clockFunc)(bool en);
	enableTimer1Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimer1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::setup_t gTimer1Setup = 
{
	(YSS_TIMER_Dev*)TIMER1	// YSS_TIMER_Dev *dev;
};

Timer timer1(gDrvTimer1Setup, gTimer1Setup);

extern "C"
{
	void TMR1_IRQHandler(void)
	{
		TIMER1->INTSTS = TIMER_INTSTS_TIF_Msk;
		timer1.isrUpdate();
	}
}
#endif



#if defined(TIMER2) && TIMER2_ENABLE
#if YSS_TIMER == RUNTIME_TIM2
#error "현재 TIMER2는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#endif

static void enableTimer2Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_TMR2CKEN_Pos, en);
}

static void enableTimer2Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(TMR2_IRQn, en);
}

static uint32_t getTimer2ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL1 & CLK_CLKSEL1_TMR2SEL_Msk) >> CLK_CLKSEL1_TMR2SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // LXT
		clk = 32768;
		break;

	case 2 : // PCLK
		clk = clock.getApb0ClockFrequency();
		break;
	
	case 4 : // LIRC
		clk = clock.getLircFrequency();
		break;

	case 5 : // LIRC
		clk = clock.getLircFrequency();
		break;

	case 7 : // LIRC
		clk = clock.getLircFrequency();
		break;

	default:
	case 3 : // TM2 Pin
		clk = 0;
	}

	return clk;
}

static const Drv::setup_t gDrvTimer2Setup = 
{
	enableTimer2Clock,		//void (*clockFunc)(bool en);
	enableTimer2Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimer2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::setup_t gTimer2Setup = 
{
	(YSS_TIMER_Dev*)TIMER2	// YSS_TIMER_Dev *dev;
};

Timer timer2(gDrvTimer2Setup, gTimer2Setup);

extern "C"
{
	void TMR2_IRQHandler(void)
	{
		TIMER2->INTSTS = TIMER_INTSTS_TIF_Msk;
		timer2.isrUpdate();
	}
}
#endif



#if defined(TIMER3) && TIMER3_ENABLE
#if YSS_TIMER == RUNTIME_TIM3
#error "현재 TIMER3는 yss OS의 Runtime에서 사용하고 있습니다. 일반적인 사용이 불가능합니다."
#endif

static void enableTimer3Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_TMR3CKEN_Pos, en);
}

static void enableTimer3Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(TMR3_IRQn, en);
}

static uint32_t getTimer3ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL1 & CLK_CLKSEL1_TMR3SEL_Msk) >> CLK_CLKSEL1_TMR3SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // LXT
		clk = 32768;
		break;

	case 2 : // PCLK
		clk = clock.getApb0ClockFrequency();
		break;
	
	case 4 : // LIRC
		clk = clock.getLircFrequency();
		break;

	case 5 : // LIRC
		clk = clock.getLircFrequency();
		break;

	case 7 : // LIRC
		clk = clock.getLircFrequency();
		break;

	default:
	case 3 : // TM3 Pin
		clk = 0;
	}

	return clk;
}

static const Drv::setup_t gDrvTimer3Setup = 
{
	enableTimer3Clock,		//void (*clockFunc)(bool en);
	enableTimer3Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getTimer3ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Timer::setup_t gTimer3Setup = 
{
	(YSS_TIMER_Dev*)TIMER3	// YSS_TIMER_Dev *dev;
};

Timer timer3(gDrvTimer3Setup, gTimer3Setup);

extern "C"
{
	void TMR3_IRQHandler(void)
	{
		TIMER3->INTSTS = TIMER_INTSTS_TIF_Msk;
		timer3.isrUpdate();
	}
}
#endif



#endif


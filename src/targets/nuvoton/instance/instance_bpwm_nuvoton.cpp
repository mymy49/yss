/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <yss/reg.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
#include <targets/nuvoton/bitfield_m4xx.h>
#elif defined(__M2xx_FAMILY)
#include <targets/nuvoton/bitfield_m2xx.h>
#endif

#if BPWM0_ENABLE && defined(BPWM0)

static void enableBpwm0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb1Clock(CLK_APBCLK1_BPWM0CKEN_Pos, en);
}

static void enableBpwm0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(BPWM0_IRQn, en);
}

static uint32_t getBpwm0ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((BPWM0->CLKSRC & BPWM_CLKPSC_CLKPSC_Msk) >> BPWM_CLKPSC_CLKPSC_Pos)
	{
	case 0 : // APB1
		clk = clock.getApb1ClockFrequency();
		break;
	
	default :
		clk = 0;
	}

	return clk;
}

static const Drv::setup_t gDrvBpwm0Setup = 
{
	enableBpwm0Clock,		//void (*clockFunc)(bool en);
	enableBpwm0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getBpwm0ClockFrequency	//uint32_t (*getClockFunc)(void);
};


static const Bpwm::setup_t gBpwm0Setup = 
{
	BPWM0			//YSS_BPWM_Dev *dev;
};

Bpwm bpwm0(gDrvBpwm0Setup, gBpwm0Setup);

#endif



#if BPWM1_ENABLE && defined(BPWM1)

static void enableBpwm1Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb1Clock(CLK_APBCLK1_BPWM1CKEN_Pos, en);
}

static void enableBpwm1Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(BPWM1_IRQn, en);
}

static uint32_t getBpwm1ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((BPWM1->CLKSRC & BPWM_CLKPSC_CLKPSC_Msk) >> BPWM_CLKPSC_CLKPSC_Pos)
	{
	case 0 : // APB1
		clk = clock.getApb1ClockFrequency();
		break;
	
	default :
		clk = 0;
	}

	return clk;
}

static const Drv::setup_t gDrvBpwm1Setup = 
{
	enableBpwm1Clock,		//void (*clockFunc)(bool en);
	enableBpwm1Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getBpwm1ClockFrequency	//uint32_t (*getClockFunc)(void);
};


static const Bpwm::setup_t gBpwm1Setup = 
{
	BPWM1			//YSS_BPWM_Dev *dev;
};

Bpwm bpwm1(gDrvBpwm1Setup, gBpwm1Setup);

#endif

#endif


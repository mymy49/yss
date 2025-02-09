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

#if EPWM0_ENABLE && defined(EPWM0)

static void enableEpwm0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb1Clock(CLK_APBCLK1_EPWM0CKEN_Pos, en);
}

static void enableEpwm0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(EPWM0P0_IRQn, en);
	nvic.enableInterrupt(EPWM0P1_IRQn, en);
	nvic.enableInterrupt(EPWM0P2_IRQn, en);
}

static uint32_t getEpwm01ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((EPWM0->CLKSRC & EPWM_CLKSRC_ECLKSRC0_Msk) >> EPWM_CLKSRC_ECLKSRC0_Pos)
	{
	case 0 : // APB1
		clk = clock.getApb1ClockFrequency();
		break;
	
	default :
		clk = 0;
	}

	return clk;
}

static uint32_t getEpwm23ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((EPWM0->CLKSRC & EPWM_CLKSRC_ECLKSRC2_Msk) >> EPWM_CLKSRC_ECLKSRC2_Pos)
	{
	case 0 : // APB1
		clk = clock.getApb1ClockFrequency();
		break;
	
	default :
		clk = 0;
	}

	return clk;
}

static uint32_t getEpwm45ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((EPWM0->CLKSRC & EPWM_CLKSRC_ECLKSRC4_Msk) >> EPWM_CLKSRC_ECLKSRC4_Pos)
	{
	case 0 : // APB1
		clk = clock.getApb1ClockFrequency();
		break;
	
	default :
		clk = 0;
	}

	return clk;
}

static const Drv::setup_t gDrvEpwm0Setup = 
{
	enableEpwm0Clock,		//void (*clockFunc)(bool en);
	enableEpwm0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	0						//uint32_t (*getClockFunc)(void);
};


static const Epwm::setup_t gEpwm0Setup = 
{
	EPWM0,						//YSS_BPWM_Dev *dev;
	getEpwm01ClockFrequency,	//uint32_t (*getClock01Func)(void);
	getEpwm23ClockFrequency,	//uint32_t (*getClock23Func)(void);
	getEpwm45ClockFrequency		//uint32_t (*getClock45Func)(void);
};

Epwm epwm0(gDrvEpwm0Setup, gEpwm0Setup);

#endif

#endif


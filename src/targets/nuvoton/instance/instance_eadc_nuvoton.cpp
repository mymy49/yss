/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
/**
 * @file instance_eadc_nuvoton.cpp
 * @brief Global driver instances initialization for Nuvoton EADC peripheral.
 */

#if defined(__M251_SUBFAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(EADC) && EADC_ENABLE
static void enableEadcClock(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableApb0Clock().
	clock.enableApb0Clock(CLK_APBCLK0_EADCCKEN_Pos, en);
}

static void enableEadcInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(EADC_INT0_IRQn, en);
}

static uint32_t getEadcClockFrequency(void)
{
	uint32_t clk = clock.getApb0ClockFrequency();
	return clk / (((CLK->CLKDIV0 & CLK_CLKDIV0_EADCDIV_Msk) >> CLK_CLKDIV0_EADCDIV_Pos) + 1);
}

static const Drv::setup_t gDrvEadcSetup = 
{
	enableEadcClock,		//void (*clockFunc)(bool en);
	enableEadcInterrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getEadcClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const NuvotonEadc::setup_t gEadcSetup = 
{
	EADC,				// YSS_SPI_Peri *peri;
};

NuvotonEadc eadc(gDrvEadcSetup, gEadcSetup);

extern "C"
{
	void EADC0_IRQHandler(void)
	{
		eadc.isr();
	}
}
#endif


#endif


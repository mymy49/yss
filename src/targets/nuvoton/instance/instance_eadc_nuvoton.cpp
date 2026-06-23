/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M251_SUBFAMILY__)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(EADC) && EADC_ENABLE
static void enableEadcClock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_EADCCKEN_Pos, en);
}

static void enableEadcInterrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
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


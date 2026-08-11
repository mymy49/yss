/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(WDT) && WDT_ENABLE
static void enableClock(bool en)
{
	clock.enableApb0Clock(CLK_APBCLK0_WDTCKEN_Pos, en);
}

static void enableInterrupt(bool en)
{
	nvic.enableInterrupt(WDT_IRQn, en);
}

static const Drv::setup_t gDrvWdtSetup = 
{
	enableClock,			//void (*clockFunc)(bool en);
	enableInterrupt,		//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	0						//uint32_t (*getClockFunc)(void);
};

static const NuvotonWdt::setup_t gWdtSetup = 
{
	WDT						// WDT_T *dev;
};

NuvotonWdt wdt(gDrvWdtSetup, gWdtSetup);

extern "C"
{
	void WDT_IRQHandler(void)
	{
		wdt.isr();
	}
}
#endif


#endif


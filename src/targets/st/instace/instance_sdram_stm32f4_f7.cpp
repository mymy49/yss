/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>
#include <config.h>

#if defined(STM32F4) || defined(STM32F7)

#if defined(FMC_Bank5_6)

#include <targets/st/bitfield.h>

#if SDRAM_ENABLE
static void enableClock(bool en)
{
	clock.lock();
	clock.enableAhb3Clock(RCC_AHB3ENR_FMCEN_Pos, en);
	clock.unlock();
}

static const Drv::setup_t gDrvConfig
{
	enableClock,		//void (*clockFunc)(bool en);
	0,					//void (*nvicFunc)(bool en);
	0,					//void (*resetFunc)(void);
	0					//uint32_t (*getClockFunc)(void);
};

Sdram sdram(gDrvConfig);
#endif

#endif

#endif


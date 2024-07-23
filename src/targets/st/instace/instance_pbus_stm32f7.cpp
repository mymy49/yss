/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>
#include <config.h>

#if defined(STM32F7)

#if defined(FMC_Bank1)

#include <targets/st/bitfield.h>

#if PBUS_ENABLE
static void enableClock(bool en)
{
	clock.lock();
	clock.enableAhb3Clock(RCC_AHB3ENR_FMCEN_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvSetup = 
{
	enableClock,		//void (*clockFunc)(bool en);
};

Pbus pbus(gDrvSetup);
#endif

#endif

#endif


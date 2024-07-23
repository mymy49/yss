/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F7) || defined (STM32F4)

#include <config.h>
#include <yss/instance.h>

#if defined(LTDC_ENABLE) && defined(LTDC)

#include <targets/st/bitfield.h>

static void enableClock(bool en)
{
	clock.lock();
	clock.enableApb2Clock(RCC_APB2ENR_LTDCEN_Pos, en);
	clock.unlock();
}

static void reset(void)
{
	clock.lock();
	clock.resetApb2(RCC_APB2RSTR_LTDCRST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvSpi1Config
{
	enableClock,	//void (*clockFunc)(bool en);
	0,				//void (*nvicFunc)(bool en);
	reset,			//void (*resetFunc)(void);
	0				//uint32_t (*getClockFunc)(void);
};

Ltdc ltdc(gDrvSpi1Config);

#endif

#endif

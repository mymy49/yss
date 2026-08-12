/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(NRF52840_XXAA)

#include <config.h>
#include <yss/reg.h>

#include <yss/instance.h>

void initializeSystem(void)
{
#if USE_HFXO
	NRF_CLOCK->TASKS_HFCLKSTART = 1;
	while(NRF_CLOCK->EVENTS_HFCLKSTARTED == 0)
		;
#endif
}

void initializeDma(void)
{
}

extern "C"
{
void SystemCoreClockUpdate(void)
{

}
}

#endif
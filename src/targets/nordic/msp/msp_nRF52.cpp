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
#if (!defined(__NO_FPU) || defined(__FPU_PRESENT)) && !defined(__SOFTFP__) || ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2));
    __DSB();
    __ISB();
#endif

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
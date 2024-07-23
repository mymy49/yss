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

void __WEAK initializeSystem(void)
{
	clock.enableHse(HSE_CLOCK_FREQ);
}

void __WEAK initializeDma(void)
{
}

extern "C"
{
void __WEAK SystemCoreClockUpdate(void)
{

}
}

#endif
/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(CPU_MIMXRT1011DAE5A)

#include <config.h>
#include <yss/instance.h>

void __WEAK initializeSystem(void)
{
#if defined(OSC_CLOCK_FREQ)
	clock.enableOsc(OSC_CLOCK_FREQ);
#endif
}

void initializeDma(void)
{

}


#endif
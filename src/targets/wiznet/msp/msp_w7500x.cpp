/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(W7500)

#include <config.h>
#include <yss/instance.h>
#include <targets/wiznet/bitfield_w7500x.h>

void __WEAK initializeSystem(void)
{
#if defined(OSC_CLOCK_FREQ)
	clock.enableOsc(OSC_CLOCK_FREQ);
	clock.setPllFrequency(Clock::PLL_SRC_OCLK, 48000000 / OSC_CLOCK_FREQ, 1, 0);
#else
	clock.setPllFrequency(Clock::PLL_SRC_RCLK, 48000000 / 8000000, 1, 0);
#endif
}

void initializeDma(void)
{
	dmaChannel1.initialize();
}


#endif


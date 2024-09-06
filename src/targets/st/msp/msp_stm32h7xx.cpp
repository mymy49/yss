/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32H7)

#include <config.h>
#include <yss/instance.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

void __WEAK initializeSystem(void)
{
	// 외부 클럭 활성화
#if defined(HSE_CLOCK_FREQ)
	clock.enableHse(HSE_CLOCK_FREQ);
#endif
}

void initializeDma(void)
{

}

extern "C"
{
	void __WEAK SystemCoreClockUpdate(void)
	{

	}
}

#endif

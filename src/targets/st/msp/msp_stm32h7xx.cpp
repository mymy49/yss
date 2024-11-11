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

	// Power Scaling 설정
	clock.setVoltageScaling(Clock::VOS_SCALE_0);
	
#if defined(HSE_CLOCK_FREQ)
	clock.setPllSource(Clock::PLL_SRC_HSE);
#else
	clock.setPllSource(Clock::PLL_SRC_HSI);
#endif

	clock.enablePll1
	(
#if defined(HSE_CLOCK_FREQ)
		HSE_CLOCK_FREQ / 2000000,
#else
		64000000 / 2000000,
#endif
		274,
		0,
		10,
		10
	);
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

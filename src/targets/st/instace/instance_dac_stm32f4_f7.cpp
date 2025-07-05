/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(STM32F4) || defined(STM32F7)

#include <yss.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#elif defined(STM32F407xx)
#include <targets/st/bitfield_stm32f407xx.h>
#endif

#if defined(DAC1) && DAC1_ENABLE
static void enableClockDac1(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_DACEN_Pos, en);
	clock.unlock();
}

static const Dac::setup_t gDac1Setup
{
	DAC1
};

static const Drv::setup_t gDrvDac1Setup
{
	enableClockDac1,		//void (*clockFunc)(bool en);
	0,						//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	0						//uint32_t (*getClockFunc)(void);
};

Dac dac1(gDrvDac1Setup, gDac1Setup);
#endif

#endif

/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32H7)

#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

#if defined(STM32H723xx)
// HSE
#define HSI_FREQ				64000000
#define HSE_MIN_FREQ			4000000
#define HSE_MAX_FREQ			50000000
#endif

uint32_t Clock::mHseFreq __attribute__((section(".non_init")));
//static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
//static const uint32_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

bool Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	mHseFreq = hseHz;

	if (hseHz < HSE_MIN_FREQ && HSE_MAX_FREQ < hseHz)
		return false;

	if (useOsc)
		RCC->CR |= RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk;
	else
		RCC->CR |= RCC_CR_HSEON_Msk;

	for (uint32_t i = 0; i < 1000000; i++)
	{
		if (RCC->CR & RCC_CR_HSERDY_Msk)
			return true;
	}

	return false;
}

#endif


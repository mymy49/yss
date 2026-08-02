/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_CLOCK_MAX32665__H_
#define YSS_CLASS_CLOCK_MAX32665__H_

#include <yss/error.h>
#include <drv/Drv.h>

class Clock : public Drv
{
public:
	error_t enableHirc8m(bool en = true) __attribute__((optimize("-O1")));

	error_t enableHirc96m(bool en = true) __attribute__((optimize("-O1")));

	typedef enum
	{
		HCLK_SRC_HIRC = 0,
		//HCLK_SRC_XTAL32M = 2,
		HCLK_SRC_HIRC96 = 4
	}hclkSrc_t;

	error_t setHclkClockSource(hclkSrc_t src, uint8_t hclkDiv) __attribute__((optimize("-O1")));
	
	uint32_t getHclkClockFrequency() __attribute__((optimize("-O1")));
	
	uint32_t getApbClockFrequency() __attribute__((optimize("-O1")));

	error_t enableCache0(bool en = true) __attribute__((optimize("-O1")));

	error_t enableCache1(bool en = true) __attribute__((optimize("-O1")));

	error_t enableCpu1(void *vtor, bool en = true) __attribute__((optimize("-O1")));

	error_t enableCpu1(const void *vtor, bool en = true) __attribute__((optimize("-O1")));

	error_t enableSemaphore(bool en = true) __attribute__((optimize("-O1")));

private:
};

#endif
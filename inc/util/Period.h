/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_PERIOD__H_
#define YSS_UTIL_PERIOD__H_

#include <drv/peripheral.h>
#include <stdint.h>

class Period
{
	uint64_t mLastTime;
	uint32_t mPeriod;

  public:
	Period(uint32_t time);
	Period(void);
	void reset(void);
	uint32_t wait(void);
	void setPeriod(uint32_t time);
};

#endif

/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_TIMEOUT__H_
#define YSS_UTIL_TIMEOUT__H_

#include <drv/mcu.h>
#include <stdint.h>

class Timeout
{
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	uint64_t mEndTime;
#else
	uint32_t mEndTime;
#endif
	uint32_t mTimeout;
  public:
	Timeout(void);
	Timeout(uint32_t timeout);
	void reset(void);
	void reset(uint32_t timeout);
	bool isTimeout(void);

};

#endif
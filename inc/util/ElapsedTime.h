/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_ELAPSED_TIME__H_
#define YSS_UTIL_ELAPSED_TIME__H_

#include <drv/mcu.h>
#include <yss/Mutex.h>

class ElapsedTime
{
public:
	ElapsedTime(void);

	void reset(void);

	uint32_t getUsec(void);

	uint32_t getMsec(void);

	uint32_t getSec(void);

private:
	Mutex mMutex;
	uint64_t mStartTime;
};

#endif
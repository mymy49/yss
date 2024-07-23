/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/Period.h>
#include <util/runtime.h>
#include <yss/thread.h>

Period::Period(void)
{
	mPeriod = 1000000;
	mLastTime = 0;
}

Period::Period(uint32_t time)
{
	mPeriod = time;
	mLastTime = 0;
}

void Period::reset(void)
{
	mLastTime = runtime::getUsec();
}

uint32_t Period::wait(void)
{
	uint64_t thisTime;

	mLastTime += mPeriod;
	do
	{
		thread::yield();
		thisTime = runtime::getUsec();
	} while (mLastTime >= thisTime);

	return (uint32_t)(mLastTime - thisTime + mPeriod);
}

void Period::setPeriod(uint32_t time)
{
	mPeriod = time;
	reset();
}


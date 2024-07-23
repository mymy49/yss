/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/ElapsedTime.h>
#include <util/runtime.h>
#include <yss/thread.h>

ElapsedTime::ElapsedTime(void)
{
	mStartTime = runtime::getUsec();
}

void ElapsedTime::reset(void)
{
	mMutex.lock();
	mStartTime = runtime::getUsec();
	mMutex.unlock();
}

uint32_t ElapsedTime::getUsec(void)
{
	uint32_t time;
	mMutex.lock();
	time = runtime::getUsec() - mStartTime;
	mMutex.unlock();
	return time;
}

uint32_t ElapsedTime::getMsec(void)
{
	uint32_t time;
	mMutex.lock();
	time = (runtime::getUsec() - mStartTime) / 1000;
	mMutex.unlock();
	return time;
}

uint32_t ElapsedTime::getSec(void)
{
	uint32_t time;
	mMutex.lock();
	time = (runtime::getUsec() - mStartTime) / 1000000;
	mMutex.unlock();
	return time;
}
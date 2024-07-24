/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/Timeout.h>
#include <util/runtime.h>
#include <yss/thread.h>

Timeout::Timeout(uint32_t timeout)
{
	mEndTime = runtime::getMsec() + timeout;
	mTimeout = timeout;
}

Timeout::Timeout(void)
{
	mEndTime = runtime::getMsec();
}

void Timeout::reset(void)
{
	mEndTime = runtime::getMsec() + mTimeout;
}

void Timeout::reset(uint32_t timeout)
{
	mEndTime = runtime::getMsec() + timeout;
	mTimeout = timeout;
}

bool Timeout::isTimeout(void)
{
	return mEndTime <= runtime::getMsec();
}

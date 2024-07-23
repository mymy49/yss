/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/Lpf.h>
#include <util/runtime.h>

Lpf::Lpf(float ratio)
{
	mRatio = ratio;
	mTime.reset();
	mData = 0;
}

Lpf::Lpf(void)
{
	mRatio = 1;
	mTime.reset();
	mData = 0;
}

void Lpf::setRatio(float value)
{
	mRatio = value;
}

float Lpf::calculate(float value)
{
	float buf, elapsedTime;

	buf = mData - value;
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	elapsedTime = mTime.getUsec();
	mTime.reset();
	mData -= buf * mRatio * ((float)elapsedTime / (float)1000000);
#else
	elapsedTime = mTime.getMsec();
	mTime.reset();
	mData -= buf * mRatio * ((float)elapsedTime / (float)1000);
#endif

	return mData;
}

float Lpf::getCurrentData(void)
{
	return mData;
}

void Lpf::setCurrentData(float data)
{
	mData = data;
}
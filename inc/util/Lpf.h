/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_LPF__H_
#define YSS_UTIL_LPF__H_

#include <util/ElapsedTime.h>
#include <yss/Mutex.h>

class Lpf
{
	float mData, mRatio;
	ElapsedTime mTime;

  public:
	Lpf(float ratio);
	Lpf(void);
	void setRatio(float value);
	float calculate(float value);
	float getCurrentData(void);
	void setCurrentData(float data);
};

#endif
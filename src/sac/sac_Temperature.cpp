/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <sac/Temperature.h>

void thread_monitor(void *var);

enum
{
	NORMAL,
	OVER_TEMPERATURE,
	UNDER_TEMPERATURE,
};

Temperature::Temperature(void)
{
	mCallback_overTemperature = 0;
	mCallback_underTemperature = 0;
	mCallback_release = 0;
	mThreadId = -1;
	mState = NORMAL;
	mHysteresis = 1;
}

void Temperature::runAlarm(uint32_t interval, uint32_t stackSize)
{
	if(mThreadId < 0)
	{
		mInterval = interval;
		mThreadId = thread::add(thread_monitor, this, stackSize);
	}
}

void Temperature::setHysteresis(float hysteresis)
{
	mHysteresis = hysteresis;
}

void Temperature::stopAlarm(void)
{
	if(mThreadId > 0)
		thread::remove(mThreadId);
}

void Temperature::process(void)
{
	float temp;

	while(1)
	{
		thread::delay(mInterval);
		temp = getTemperature();
		switch(mState)
		{
		case NORMAL :
			if(temp > mOverTemperature)
			{
				if(mCallback_overTemperature)
				{
					mCallback_overTemperature(temp);
					mState = OVER_TEMPERATURE;
				}
			}
			else if(temp < mUnderTemperature)
			{
				if(mCallback_underTemperature)
				{
					mCallback_underTemperature(temp);
					mState = UNDER_TEMPERATURE;
				}
			}
			break;
		case OVER_TEMPERATURE :
			if(temp - mHysteresis < mOverTemperature)
			{
				if(mCallback_release)
					mCallback_release(temp);
				mState = NORMAL;
			}
			break;
		}
	}
}

void Temperature::setOverTemperature(float temperature, void (*callback)(float temperature))
{
	mOverTemperature = temperature;
	mCallback_overTemperature = callback;
}

void Temperature::setUnderTemperature(float temperature, void (*callback)(float temperature))
{
	mUnderTemperature = temperature;
	mCallback_underTemperature = callback;
}

void Temperature::setRelease(void (*func)(float temperature))
{
	mCallback_release = func;
}

void thread_monitor(void *var)
{
	Temperature *obj = (Temperature*)var;

	obj->process();
}
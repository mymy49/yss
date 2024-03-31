////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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
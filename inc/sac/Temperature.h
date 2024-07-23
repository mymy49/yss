/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_TEMPERATURE__H_
#define YSS_SAC_TEMPERATURE__H_

#include <stdint.h>
#include <yss/thread.h>

class Temperature
{
public :

	// 온도 알람의 모니터를 시작합니다.
	// setOverTemperature(), setUnderTemperature() 함수에서 설정한 온도에 따라 임계 온도에 도착하면 대응하는 callback 함수를 호출합니다.
	// 임계 온도에서 벗어난 경우 setRelease() 함수에서 등록한 callback 함수를 호출합니다.
	// 
	// uint32_t interval
	//		온도를 체크하는 주기를 ms 단위로 설정합니다.
	// uint32_t stackSize = 512
	//		온도를 체크하고 callback을 호출하는 thread의 스택 크기를 설정합니다.
	void runAlarm(uint32_t interval, uint32_t stackSize = 512);

	void stopAlarm(void);

	void process(void);

	void setOverTemperature(float temperature, void (*callback)(float temperature));

	void setUnderTemperature(float temperature, void (*callback)(float temperature));

	void setRelease(void (*callback)(float temperature));

	virtual float getTemperature(void) = 0;

	void setHysteresis(float hysteresis);

	Temperature(void);

private :
	threadId_t mThreadId;
	uint32_t mInterval;
	uint8_t mState;
	float mOverTemperature, mUnderTemperature, mHysteresis;
	void (*mCallback_overTemperature)(float temperature);
	void (*mCallback_underTemperature)(float temperature);
	void (*mCallback_release)(float temperature);
};

#endif
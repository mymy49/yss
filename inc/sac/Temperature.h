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
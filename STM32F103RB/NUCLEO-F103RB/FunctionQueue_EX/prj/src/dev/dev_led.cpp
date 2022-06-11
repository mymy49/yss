////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <dev/led.h>
#include <util/Period.h>
#include <yss/yss.h>

namespace led
{
int gOnTime, gSpeed = 20;
int gId1, gId2;
const float gOnTimeTable[33] =
	{
		0.000, 0.001, 0.004, 0.009, 0.016, 0.024, 0.035, 0.048, 0.063,
		0.079, 0.098, 0.118, 0.141, 0.165, 0.191, 0.220, 0.250, 0.282,
		0.316, 0.353, 0.391, 0.431, 0.473, 0.517, 0.563, 0.610, 0.660,
		0.712, 0.766, 0.821, 0.879, 0.938, 1.000};

void init(void)
{
	using namespace define::gpio;

	// LED 초기화
	gpioA.setAsOutput(5);
}

void clear(void)
{
	if (gId1)
	{
		thread::remove(gId1);
		gId1 = 0;
	}

	if (gId2)
	{
		thread::remove(gId2);
		gId2 = 0;
	}
}

void on(bool en)
{
	clear();
	gpioA.setOutput(5, en);
}

void thread_fadeinoutBlink(void)
{
	Period period(10000);

	period.reset();
	while (1)
	{
		period.wait();
		gpioA.setOutput(5, true);
		thread::delayUs(gOnTime);
		gpioA.setOutput(5, false);
	}
}

void thread_fadeinoutChangeDelay(void)
{
	while (1)
	{
		for (int i = 0; i < 32; i++)
		{
			gOnTime = gOnTimeTable[i] * (float)10000;
			thread::delay(gSpeed);
		}
		for (signed int i = 32; i >= 0; i--)
		{
			gOnTime = gOnTimeTable[i] * (float)10000;
			thread::delay(gSpeed);
		}
	}
}

void fadeInOut(void)
{
	clear();

	gId1 = thread::add(thread_fadeinoutBlink, 256);
	gId2 = thread::add(thread_fadeinoutChangeDelay, 256);
}
}
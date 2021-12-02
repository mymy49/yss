////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2021.03.31 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <memory.h>
#include <stdio.h>
#include <task/task_voltage.h>
#include <util/Measure.h>
#include <util/MultiMeasure.h>
#include <util/key.h>
#include <yss/instance.h>
#include <yss/thread.h>

namespace task
{
namespace voltage1
{
unsigned int gId;
drv::Adc *gAdc;
bool (*gGetKey)(void);
Measure gVoltage1, gVoltage2, gVoltage3;
Measure gCurrent1, gCurrent2, gCurrent3;
MultiMeasure gMultiVoltage1(10), gMultiVoltage2(10), gMultiVoltage3(10);
MultiMeasure gMultiCurrent1(10), gMultiCurrent2(10), gMultiCurrent3(10);
Mutex gMutex;

void thread_voltageEx1(void);

void init(drv::Adc *adc, bool (*getKeyFunc)(void))
{
	gAdc = adc;
	gGetKey = getKeyFunc;

	gVoltage1.setValueP1(0);
	gVoltage1.setValueP2(3.3);
	gVoltage1.setAdcP1(0);
	gVoltage1.setAdcP2(65535);

	gVoltage2.setValueP1(0.3);
	gVoltage2.setValueP2(3.0);
	gVoltage2.setAdcP1(5957);
	gVoltage2.setAdcP2(59578);

	gVoltage3.setValueP1(0.5);
	gVoltage3.setValueP2(2.5);
	gVoltage3.setAdcP1(9929);
	gVoltage3.setAdcP2(49647);

	gMultiVoltage1.setNumberOfPoint(4);
	gMultiVoltage1.setPoint(0, 0, 0);
	gMultiVoltage1.setPoint(1, 0.3, 5957);
	gMultiVoltage1.setPoint(2, 2.5, 49647);
	gMultiVoltage1.setPoint(3, 3.3, 65535);

	gMultiVoltage2.setNumberOfPoint(5);
	gMultiVoltage2.setPoint(0, 0, 0);
	gMultiVoltage2.setPoint(1, 0.3, 5957);
	gMultiVoltage2.setPoint(2, 0.5, 9929);
	gMultiVoltage2.setPoint(3, 2.5, 49647);
	gMultiVoltage2.setPoint(4, 3.3, 65535);

	gMultiVoltage3.setNumberOfPoint(6);
	gMultiVoltage3.setPoint(0, 0, 0);
	gMultiVoltage3.setPoint(1, 0.3, 5957);
	gMultiVoltage3.setPoint(2, 0.5, 9929);
	gMultiVoltage3.setPoint(3, 2.5, 49647);
	gMultiVoltage3.setPoint(4, 3.0, 59578);
	gMultiVoltage3.setPoint(5, 3.3, 65535);

	gCurrent1.setValueP1(4);
	gCurrent1.setValueP2(20);
	gCurrent1.setAdcP1(11397);
	gCurrent1.setAdcP2(56986);

	gCurrent2.setValueP1(5);
	gCurrent2.setValueP2(19);
	gCurrent2.setAdcP1(14246);
	gCurrent2.setAdcP2(54137);

	gCurrent3.setValueP1(6);
	gCurrent3.setValueP2(18);
	gCurrent3.setAdcP1(17096);
	gCurrent3.setAdcP2(51288);

	gMultiCurrent1.setNumberOfPoint(4);
	gMultiCurrent1.setPoint(0, 4, 11397);
	gMultiCurrent1.setPoint(1, 5, 14246);
	gMultiCurrent1.setPoint(2, 19, 54137);
	gMultiCurrent1.setPoint(3, 20, 56986);

	gMultiCurrent2.setNumberOfPoint(5);
	gMultiCurrent2.setPoint(0, 4, 11397);
	gMultiCurrent2.setPoint(1, 5, 14246);
	gMultiCurrent2.setPoint(2, 6, 17096);
	gMultiCurrent2.setPoint(3, 19, 54137);
	gMultiCurrent2.setPoint(4, 20, 56986);

	gMultiCurrent3.setNumberOfPoint(6);
	gMultiCurrent3.setPoint(0, 4, 11397);
	gMultiCurrent3.setPoint(1, 5, 14246);
	gMultiCurrent3.setPoint(2, 6, 17096);
	gMultiCurrent3.setPoint(3, 18, 51288);
	gMultiCurrent3.setPoint(4, 19, 54137);
	gMultiCurrent3.setPoint(5, 20, 56986);
}

void clear(void)
{
	if (gId)
	{
		thread::remove(gId);
		gId = 0;
	}
}

signed int stop(FunctionQueue *fq)
{
	gMutex.lock();

	clear();

	gMutex.unlock();

	return 0;
}

void thread_voltageEx1(void)
{
	char str[128];
	bool flag = false;
	float result1, result2, result3;

	key::clear();
	key::addPushHandler(gGetKey, flag);

	// debug_printf("\n전압 입력 예제1 시작!!\n");
	debug_printf("\nVoltage input Ex1 start!!\n");

	while (1)
	{
		result1 = gVoltage1.calculate(gAdc->get(0));
		result2 = gVoltage2.calculate(gAdc->get(1));
		result3 = gVoltage3.calculate(gAdc->get(2));
		sprintf(str, "%5.3f[V], %5.3f[V], %5.3f[V]\r", result1, result2, result3);
		debug_printf("%s", str);

		if (flag)
		{
			// debug_printf("\n전압 출력 예제1 끝!!\n");
			debug_printf("\nVoltage input Ex1 end!!\n");
			flag = false;
			gFq.add(startEx2);
			while (true)
				thread::yield();
		}
	}
}

signed int startEx1(FunctionQueue *fq)
{
	gMutex.lock();

	clear();

	gId = thread::add(thread_voltageEx1, 1024);

	gMutex.unlock();

	return 0;
}

void thread_voltageEx2(void)
{
	char str[128];
	bool flag = false;

	key::clear();
	key::addPushHandler(gGetKey, flag);

	// debug_printf("\n전압 출력 예제2 시작!!\n");
	debug_printf("\nVoltage input Ex2 start!!\n");

	while (1)
	{
		sprintf(str, "%5.3f[V], %5.3f[V], %5.3f[V]\r", gMultiVoltage1.calculate(gAdc->get(0)), gMultiVoltage2.calculate(gAdc->get(1)), gMultiVoltage3.calculate(gAdc->get(2)));
		debug_printf("%s", str);

		if (flag)
		{
			// debug_printf("\n전압 출력 예제2 끝!!\n");
			debug_printf("\nVoltage input Ex2 end!!\n");
			flag = false;
			gFq.add(startEx3);
			while (true)
				thread::yield();
		}
	}
}

signed int startEx2(FunctionQueue *fq)
{
	gMutex.lock();

	clear();

	gId = thread::add(thread_voltageEx2, 1024);

	gMutex.unlock();

	return 0;
}

void thread_currentEx1(void)
{
	char str[128];
	bool flag = false;

	key::clear();
	key::addPushHandler(gGetKey, flag);

	// debug_printf("\n전류 출력 예제1 시작!!\n");
	debug_printf("\nCurrent input Ex1 start!!\n");

	while (1)
	{
		sprintf(str, "%6.3f[mA], %6.3f[mA], %6.3f[mA]\r", gCurrent1.calculate(gAdc->get(0)), gCurrent2.calculate(gAdc->get(1)), gCurrent3.calculate(gAdc->get(2)));
		debug_printf("%s", str);

		if (flag)
		{
			// debug_printf("\n전류 출력 예제1 끝!!\n");
			debug_printf("\nCurrent input Ex1 end!!\n");
			flag = false;
			gFq.add(startEx4);
			while (true)
				thread::yield();
		}
	}
}

signed int startEx3(FunctionQueue *fq)
{
	gMutex.lock();

	clear();

	gId = thread::add(thread_currentEx1, 1024);

	gMutex.unlock();

	return 0;
}

void thread_currentEx2(void)
{
	char str[128];
	bool flag = false;

	key::clear();
	key::addPushHandler(gGetKey, flag);

	// debug_printf("\n전류 출력 예제2 시작!!\n");
	debug_printf("\nCurrent input Ex2 start!!\n");

	while (1)
	{
		sprintf(str, "%6.3f[mA], %6.3f[mA], %6.3f[mA]\r", gMultiCurrent1.calculate(gAdc->get(0)), gMultiCurrent2.calculate(gAdc->get(1)), gMultiCurrent3.calculate(gAdc->get(2)));
		debug_printf("%s", str);

		if (flag)
		{
			// debug_printf("\n전류 출력 예제2 끝!!\n");
			debug_printf("\nCurrent input Ex2 end!!\n");
			flag = false;
			gFq.add(startEx1);
			while (true)
				thread::yield();
		}
	}
}

signed int startEx4(FunctionQueue *fq)
{
	gMutex.lock();

	clear();

	gId = thread::add(thread_currentEx2, 1024);

	gMutex.unlock();

	return 0;
}

}
}
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

#include "contextSwitching.h"
#include <__cross_studio_io.h>
#include <util/ElapsedTime.h>
#include <yss/yss.h>

void thread_dummyUsingYield(void)
{
	while (1)
		thread::yield();

	/* 아래와 같은 경우 비슷하다고 볼 수 있음
	while (1)
	{
		// 만약 키 입력이 있다면
		if (false)
		{
			// 아래 코드를 실행하라
		}

		thread::yield();
	}
	*/
}

void thread_dummy(void)
{
	while (1)
		;
}

void testContextSwitcing1(void)
{
	int spendTime;
	ElapsedTime elapsedTime;

	// 다른 쓰레드가 없는 상황에서 복귀 시간 확인
	elapsedTime.reset();
	thread::yield();

#if !defined(__CORE_CM0PLUS_H_GENERIC)
	spendTime = elapsedTime.getUsec();
	debug_printf("testContextSwitcing1 : %d usec\n", spendTime);
#else
	spendTime = elapsedTime.getMsec();
	debug_printf("testContextSwitcing1 : %d msec\n", spendTime);
#endif

}

void testContextSwitcing2(void)
{
	int spendTime, id;
	ElapsedTime elapsedTime;

	id = thread::add(thread_dummyUsingYield, 512);

	// 다른 쓰레드가 즉시 yield로 빠져나가는 쓰레드가 하나 있는 상황에서 복귀 시간 확인
	elapsedTime.reset();
	thread::yield();

#if !defined(__CORE_CM0PLUS_H_GENERIC)
	spendTime = elapsedTime.getUsec();
	debug_printf("testContextSwitcing2 : %d usec\n", spendTime);
#else
	spendTime = elapsedTime.getMsec();
	debug_printf("testContextSwitcing2 : %d msec\n", spendTime);
#endif


	thread::remove(id);
}

void testContextSwitcing3(void)
{
	int spendTime, id;
	ElapsedTime elapsedTime;

	id = thread::add(thread_dummy, 512);

	// 다른 쓰레드가 yield 없이 while문이 도는 쓰레드가 하나 있는 상황에서 복귀 시간 확인
	elapsedTime.reset();
	thread::yield();

#if !defined(__CORE_CM0PLUS_H_GENERIC)
	spendTime = elapsedTime.getUsec();
	debug_printf("testContextSwitcing3 : %d usec\n", spendTime);
#else
	spendTime = elapsedTime.getMsec();
	debug_printf("testContextSwitcing3 : %d msec\n", spendTime);
#endif


	thread::remove(id);
}
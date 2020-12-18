#include "contextSwitching.h"
#include <util/TimeLapse.h>
#include <yss/yss.h>
#include <__cross_studio_io.h>

void dummyUsingYield(void)
{
	while(1)
		thread::yield();
}

void testContextSwitcing1(void)
{
	int spendTime;
	TimeLapse timelapse;
	
	// 다른 쓰레드가 없는 상황에서 복귀 시간 확인
	timelapse.reset();
	thread::yield();
	
	spendTime = timelapse.getUsec();
	debug_printf("testContextSwitcing1 : %d usec\n", spendTime);
}

void testContextSwitcing2(void)
{
	int spendTime, id;
	TimeLapse timelapse;
	
	id = thread::add(dummyUsingYield, 512);

	// 다른 쓰레드가 즉시 yield로 빠져나가는 쓰레드가 하나 있는 상황에서 복귀 시간 확인
	timelapse.reset();
	thread::yield();
	
	spendTime = timelapse.getUsec();
	debug_printf("testContextSwitcing2 : %d usec\n", spendTime);

	thread::remove(id);
}


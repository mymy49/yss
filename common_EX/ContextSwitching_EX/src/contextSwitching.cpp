#include "contextSwitching.h"
#include <__cross_studio_io.h>
#include <util/TimeLapse.h>
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

    id = thread::add(thread_dummyUsingYield, 512);

    // 다른 쓰레드가 즉시 yield로 빠져나가는 쓰레드가 하나 있는 상황에서 복귀 시간 확인
    timelapse.reset();
    thread::yield();

    spendTime = timelapse.getUsec();
    debug_printf("testContextSwitcing2 : %d usec\n", spendTime);

    thread::remove(id);
}

void testContextSwitcing3(void)
{
    int spendTime, id;
    TimeLapse timelapse;

    id = thread::add(thread_dummy, 512);

    // 다른 쓰레드가 yield 없이 while문이 도는 쓰레드가 하나 있는 상황에서 복귀 시간 확인
    timelapse.reset();
    thread::yield();

    spendTime = timelapse.getUsec();
    debug_printf("testContextSwitcing3 : %d usec\n", spendTime);

    thread::remove(id);
}
#include <util/Period.h>
#include <util/time.h>
#include <yss/thread.h>

#if !defined(__CORE_CM0PLUS_H_GENERIC)

Period::Period(unsigned int time)
{
    mPeriod = time;
    mLastTime = 0;
}

void Period::reset(void)
{
    mLastTime = time::getRunningUsec();
}

unsigned int Period::wait(void)
{
    unsigned long long thisTime;

    mLastTime += mPeriod;
    do
    {
        thread::yield();
        thisTime = time::getRunningUsec();
    } while (mLastTime >= thisTime);

    return (unsigned int)(mLastTime - thisTime + mPeriod);
}

#endif

#include <util/PeriodMili.h>
#include <util/time.h>
#include <yss/thread.h>

PeriodMili::PeriodMili(unsigned int time)
{
    mPeriod = time;
    mLastTime = time::getRunningMsec();
}

void PeriodMili::reset(void)
{
    mLastTime = time::getRunningMsec();
}

unsigned int PeriodMili::wait(void)
{
    unsigned int thisTime;

    mLastTime += mPeriod;
    do
    {
        thread::yield();
        thisTime = time::getRunningMsec();
    } while (mLastTime >= thisTime);

    return (unsigned int)(mLastTime - thisTime + mPeriod);
}
#include <util/Period.h>
#include <util/time.h>
#include <yss/thread.h>

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
	unsigned int a;

	mLastTime += mPeriod;
	do
	{
		thread::yield();
		thisTime = time::getRunningUsec();
	}while(mLastTime >= thisTime);

	a = mLastTime - thisTime + mPeriod;

	if(a < 1000)
		return 0;

	return a;
}


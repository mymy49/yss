#include <util/TimeLapse.h>
#include <util/time.h>
#include <yss/thread.h>

TimeLapse::TimeLapse(void)
{
	mStartTime = time::getRunningUsec();
}

void TimeLapse::reset(void)
{
	mStartTime = time::getRunningUsec();
}

unsigned int TimeLapse::getUsec(void)
{
	return time::getRunningUsec() - mStartTime;
}

unsigned int TimeLapse::getMsec(void)
{
	return (time::getRunningUsec() - mStartTime) / 1000;
}

unsigned int TimeLapse::getSec(void)
{
	return (time::getRunningUsec() - mStartTime) / 1000000;
}



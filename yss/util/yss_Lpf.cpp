#include <util/Lpf.h>
#include <util/time.h>

Lpf::Lpf(float threshold, float ratio)
{
	mThreshold = threshold;
	mRatio = ratio;
	mTime.reset();
}

Lpf::Lpf(void)
{
	mThreshold = 999999999;
	mRatio = 1;
	mTime.reset();
}

void Lpf::setThreshold(float value)
{
	mThreshold = value;
}

void Lpf::setRatio(float value)
{
	mRatio = value;
}

float Lpf::calculate(float value)
{
	float buf, abs;
	signed long gap;

    buf = mData - value;
    abs = buf;
    if (abs < 0)
        abs *= (float)-1;

	if(abs > mThreshold)
		mData = value;
	else
	{
#if !defined(__CORE_CM0PLUS_H_GENERIC)
		gap = mTime.getUsec();
		mTime.reset();
		if(gap > 1000000)
			gap = 1000000;
		mData -= buf*mRatio*((float)gap/(float)1000000);
#else
		gap = mTime.getMsec();
		mTime.reset();
		if(gap > 1000)
			gap = 1000;
		mData -= buf*mRatio*((float)gap/(float)1000);
#endif
	}

	return mData;
}

float Lpf::getCurrentData(void)
{
	return mData;
}

void Lpf::setCurrentData(float data)
{
	mData = data;
}

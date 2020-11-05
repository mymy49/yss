#include <util/Lpf.h>
#include <yss/time.h>

Lpf::Lpf(float threshold, float ratio)
{
	mThreshold = threshold;
	mRatio = ratio;
}

float Lpf::process(float value)
{
	float buf, abs;
	signed long gap;
	unsigned long long thisTime = time::getRunningUsec();
	
	buf = mData - value;
	abs = buf;
	if(abs < 0)
		abs *= (float)-1;

	if(abs > mThreshold)
		mData = value;
	else
	{
		gap = (signed long)(thisTime - mLastTime);
		if(gap > 1000000)
			gap = 1000000;
		mData -= buf*mRatio*((float)gap/(float)1000000);
	}

	mLastTime = thisTime;
	return mData;
}
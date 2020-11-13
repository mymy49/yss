#include <util/Pid.h>
#include <yss/time.h>
Pid::Pid(void)
{
	mPgain = 1.0;
	mIgain = 1.0;
	mDgain = 1.0;
	
	mPLimitMax = 1.0;
	mPLimitMin = -1.0;
	mILimitMax = 1.0;
	mILimitMin = -1.0;
	mDLimitMax = 1.0;
	mDLimitMin = -1.0;
    mOutputLimitMax = 1.0;
    mOutputLimitMin = -1.0;

    mBeforeError = 0;
    mIsum = 0;
	mTarget = 0;
}

float Pid::calculate(float value)
{
	unsigned long long thisTime = time::getRunningUsec();
    unsigned long lapse = (unsigned long)(thisTime - mLastTime);
	float p, err, d;
	
	err = mTarget - value;
    p = err * mPgain;
	mIsum += err * ((float)lapse/(float)1000000) * mIgain;
	d = (err - mBeforeError) * mDgain;

    if(p > mPLimitMax)
		p = mPLimitMax;
	else if(p < mPLimitMin)
		p = mPLimitMin;
	
    if(mIsum > mILimitMax)
		mIsum = mILimitMax;
	else if(mIsum < mILimitMin)
		mIsum = mILimitMin;

    if(d > mDLimitMax)
		d = mDLimitMax;
	else if(d < mDLimitMin)
		d = mDLimitMin;

	p = p + mIsum + d;
    if(p > mOutputLimitMax)
		p = mOutputLimitMax;
	else if(p < mOutputLimitMin)
		p = mOutputLimitMin;
	
	mLastTime = thisTime;
    mBeforeError = err;

	return p;
}

float Pid::calculate(float target, float value)
{
	mTarget = target;
	return calculate(value);
}

void Pid::setPgain(float gain)
{
	mPgain = gain;
}

void Pid::setIgain(float gain)
{
	mIgain = gain;
}

void Pid::setDgain(float gain)
{
	mDgain = gain;
}

void Pid::setGain(float p, float i, float d)
{
	mPgain = p;
    mIgain = i;
    mDgain = d;
}

float Pid::getPgain(void)
{
	return mPgain;
}

float Pid::getIgain(void)
{
	return mIgain;
}

float Pid::getDgain(void)
{
	return mDgain;
}

void Pid::setPLimit(float min, float max)
{
	mPLimitMin = min;
    mPLimitMax = max;
}

void Pid::setILimit(float min, float max)
{
	mILimitMin = min;
	mILimitMax = max;
}

void Pid::setDLimit(float min, float max)
{
	mDLimitMin = min;
	mDLimitMax = max;
}

float Pid::getPLimitMin(void)
{
	return mPLimitMin;
}

float Pid::getPLimitMax(void)
{
	return mPLimitMax;
}

float Pid::getILimitMin(void)
{
	return mILimitMin;
}

float Pid::getILimitMax(void)
{
	return mILimitMax;
}

float Pid::getDLimitMin(void)
{
	return mDLimitMin;
}

float Pid::getDLimitMax(void)
{
	return mDLimitMax;
}

float Pid::getCurrentP(void)
{
	return mP;
}

float Pid::getCurrentIsum(void)
{
	return mIsum;
}

float Pid::getCurrentD(void)
{
	return mD;
}

void Pid::setTarget(float target)
{
	mTarget = target;
}

float Pid::getTarget(void)
{
	return mTarget;
}



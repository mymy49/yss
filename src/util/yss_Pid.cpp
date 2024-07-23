/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/Pid.h>
#include <util/runtime.h>

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
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	mLastTime = runtime::getUsec();
#else
	mLastTime = runtime::getMsec();
#endif
}

float Pid::calculate(float value)
{
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	uint64_t thisTime = runtime::getUsec();
#else
	uint64_t thisTime = runtime::getMsec();
#endif
	uint32_t lapse = (uint32_t)(thisTime - mLastTime);
	float p, err, d;

	err = mTarget - value;
	p = err * mPgain;
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	mIsum += err * mIgain * ((float)lapse / (float)1000000);
#else
	mIsum += err * mIgain * ((float)lapse / (float)1000);
#endif
	d = (err - mBeforeError) * mDgain;

	if (p > mPLimitMax)
		p = mPLimitMax;
	else if (p < mPLimitMin)
		p = mPLimitMin;

	if (mIsum > mILimitMax)
		mIsum = mILimitMax;
	else if (mIsum < mILimitMin)
		mIsum = mILimitMin;

	if (d > mDLimitMax)
		d = mDLimitMax;
	else if (d < mDLimitMin)
		d = mDLimitMin;

	p = p + mIsum + d;
	if (p > mOutputLimitMax)
		p = mOutputLimitMax;
	else if (p < mOutputLimitMin)
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

void Pid::setLimit(float min, float max)
{
	mOutputLimitMin = min;
	mOutputLimitMax = max;
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

void Pid::reset(void)
{
	mIsum = 0;
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	mLastTime = runtime::getUsec();
#else
	mLastTime = runtime::getMsec();
#endif
}

float Pid::getError(void)
{
	return mBeforeError;
}
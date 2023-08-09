////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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
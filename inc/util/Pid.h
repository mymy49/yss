/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_PID__H_
#define YSS_UTIL_PID__H_

#include <stdint.h>

class Pid
{
public :
	Pid(void);

	float calculate(float value);

	float calculate(float target, float value);

	void setPgain(float gain);

	void setIgain(float gain);

	void setDgain(float gain);

	void setGain(float p, float i, float d);

	float getPgain(void);

	float getIgain(void);

	float getDgain(void);

	void setLimit(float min, float max);

	void setPLimit(float min, float max);

	void setILimit(float min, float max);

	void setDLimit(float min, float max);

	float getPLimitMin(void);

	float getPLimitMax(void);

	float getILimitMin(void);

	float getILimitMax(void);

	float getDLimitMin(void);

	float getDLimitMax(void);

	float getCurrentP(void);

	float getCurrentIsum(void);

	float getCurrentD(void);

	void setTarget(float target);

	float getTarget(void);

	float getError(void);

	void reset(void);
private :
	uint64_t mLastTime;
	float mPgain, mIgain, mDgain, mP, mIsum, mD;
	float mPLimitMax, mPLimitMin, mILimitMax, mILimitMin, mDLimitMax, mDLimitMin;
	float mOutputLimitMax, mOutputLimitMin;
	float mBeforeError, mTarget;
};

#endif


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


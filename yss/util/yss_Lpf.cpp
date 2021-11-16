////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2020.09.01 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <util/Lpf.h>
#include <util/time.h>

Lpf::Lpf(float threshold, float ratio)
{
	mThreshold = threshold;
	mRatio = ratio;
	mTime.reset();
	mData = 0;
}

Lpf::Lpf(void)
{
	mThreshold = 999999999;
	mRatio = 1;
	mTime.reset();
	mData = 0;
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

	if (abs > mThreshold)
		mData = value;
	else
	{
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
		gap = mTime.getUsec();
		mTime.reset();
		if (gap > 1000000)
			gap = 1000000;
		mData -= buf * mRatio * ((float)gap / (float)1000000);
#else
		gap = mTime.getMsec();
		mTime.reset();
		if (gap > 1000)
			gap = 1000;
		mData -= buf * mRatio * ((float)gap / (float)1000);
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
////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <util/Measure.h>

Measure::Measure(float valueP1, float ValueP2)
{
	mAdcP1 = 0;
	mAdcP2 = 65535;
	mValueP1 = valueP1;
	mValueP2 = ValueP2;
	mValueOffset = mValueP2 - mValueP1;
}

Measure::Measure(void)
{
	mAdcP1 = 0;
	mAdcP2 = 65535;
	mValueP1 = 0;
	mValueP2 = 100;
	mValueOffset = mValueP2 - mValueP1;
}

void Measure::setAdcP1(float val)
{
	mAdcP1 = val;
	mAdcOffset = mAdcP2 - mAdcP1;
}

void Measure::setAdcP2(float val)
{
	mAdcP2 = val;
	mAdcOffset = mAdcP2 - mAdcP1;
}

void Measure::setValueP1(float value)
{
	mValueP1 = value;
	mValueOffset = mValueP2 - mValueP1;
}

void Measure::setValueP2(float value)
{
	mValueP2 = value;
	mValueOffset = mValueP2 - mValueP1;
}

float Measure::calculate(float adc)
{
	if(mAdcOffset != 0)
		return (adc - mAdcP1) / mAdcOffset * mValueOffset + mValueP1;
	else
		return 0;
}

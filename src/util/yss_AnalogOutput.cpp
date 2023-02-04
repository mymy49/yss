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

#include <util/AnalogOutput.h>

AnalogOutput::AnalogOutput(float maxDac, float referenceValueP1, float referenceValueP2, float minValue, float maxValue)
{
	mDacMax = maxDac;
	mErrorP1 = mValueP1 = referenceValueP1;
	mErrorP2 = mValueP2 = referenceValueP2;
	mErrorOffset = mErrorP2 - mErrorP1;

	mReferenceDacP1 = (referenceValueP1 - minValue) / (maxValue - minValue) * maxDac;
	mReferenceDacP2 = (referenceValueP2 - minValue) / (maxValue - minValue) * maxDac;

	mRefrenceOffset = mReferenceDacP2 - mReferenceDacP1;
}

void AnalogOutput::setErrorP1(float val)
{
	mErrorP1 = val;
	mErrorOffset = mErrorP2 - mErrorP1;
}

void AnalogOutput::setErrorP2(float val)
{
	mErrorP2 = val;
	mErrorOffset = mErrorP2 - mErrorP1;
}

uint32_t AnalogOutput::calculate(float voltage)
{
	return (voltage - mErrorP1) / (mErrorOffset) * (mRefrenceOffset) + mReferenceDacP1;
}

uint32_t AnalogOutput::getReferenceDacP1(void)
{
	return mReferenceDacP1;
}

uint32_t AnalogOutput::getReferenceDacP2(void)
{
	return mReferenceDacP2;
}

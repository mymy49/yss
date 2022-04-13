////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <util/MultiMeasure.h>

MultiMeasure::MultiMeasure(unsigned short maxPoint)
{
	mValue = new float[maxPoint];
	mAdc = new float[maxPoint];
	mMaxPoint = maxPoint;
	mWorkingPoint = mMaxPoint;
}

void MultiMeasure::setPoint(unsigned short num, float value, float adc)
{
	if(num < mMaxPoint)
	{
		mValue[num] = value;
		mAdc[num] = adc;
	}
}

void MultiMeasure::setNumberOfPoint(unsigned short num)
{
	if(num < 2)
		mWorkingPoint = mMaxPoint;
	else if(num < mMaxPoint)
		mWorkingPoint = num;
	else
		mWorkingPoint = mMaxPoint;
}

float MultiMeasure::calculate(float adc)
{
	float buf = 0;
	int index;

	if(adc < mAdc[0])
	{
		return (adc - mAdc[0]) / (mAdc[1] - mAdc[0]) * (mValue[1] - mValue[0]) + mValue[0];
	}

	for(int i=1;i<mWorkingPoint;i++)
	{
		if(adc < mAdc[i])
		{
			return (adc - mAdc[i-1]) / (mAdc[i] - mAdc[i-1]) * (mValue[i] - mValue[i-1]) + mValue[i-1];
		}
	}
	
	index = mWorkingPoint - 2;
	buf = (adc - mAdc[index]) / (mAdc[index+1] - mAdc[index]);
	buf *= (mValue[index+1] - mValue[index]);
	buf += mValue[index];
	return buf;
}



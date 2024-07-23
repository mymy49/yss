/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/MultiMeasure.h>

MultiMeasure::MultiMeasure(uint16_t maxPoint)
{
	mValue = new float[maxPoint];
	mAdc = new float[maxPoint];
	mMaxPoint = maxPoint;
	mWorkingPoint = mMaxPoint;
}

void MultiMeasure::setPoint(uint16_t num, float value, float adc)
{
	if(num < mMaxPoint)
	{
		mValue[num] = value;
		mAdc[num] = adc;
	}
}

void MultiMeasure::getPoint(uint16_t num, float *value, float *adc)
{
	if(num < mMaxPoint)
	{
		*value = mValue[num];
		*adc = mAdc[num];
	}
}

void MultiMeasure::setNumberOfPoint(uint16_t num)
{
	if(num < 2)
		mWorkingPoint = mMaxPoint;
	else if(num < mMaxPoint)
		mWorkingPoint = num;
	else
		mWorkingPoint = mMaxPoint;
}

uint16_t MultiMeasure::getNumberOfPoint(void)
{
	return mWorkingPoint;
}

float MultiMeasure::calculate(float adc)
{
	float buf = 0;
	int32_t  index;

	if(adc < mAdc[0])
	{
		return (adc - mAdc[0]) / (mAdc[1] - mAdc[0]) * (mValue[1] - mValue[0]) + mValue[0];
	}

	for(int32_t  i=1;i<mWorkingPoint;i++)
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



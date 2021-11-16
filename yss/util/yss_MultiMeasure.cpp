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



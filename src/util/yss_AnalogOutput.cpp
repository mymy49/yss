/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/AnalogOutput.h>

AnalogOutput::AnalogOutput(void)
{
	mDacMax = 1 << 14;
	mErrorP1 = mValueP1 = 4;
	mErrorP2 = mValueP2 = 20;
	mErrorOffset = mErrorP2 - mErrorP1;
	mReferenceDacP1 = (mValueP1 - 4) / (float)(20 - 4) * mDacMax;
	mReferenceDacP2 = (mValueP2 - 4) / (float)(20 - 4) * mDacMax;
	mReferenceOffset = mReferenceDacP2 - mReferenceDacP1;
}

void AnalogOutput::setup(uint8_t dacBit, float referenceValueP1, float referenceValueP2, float minValue, float maxValue)
{
	mDacMax = 1 << dacBit;
	mErrorP1 = mValueP1 = referenceValueP1;
	mErrorP2 = mValueP2 = referenceValueP2;
	mErrorOffset = mErrorP2 - mErrorP1;
	mReferenceDacP1 = (referenceValueP1 - minValue) / (maxValue - minValue) * mDacMax;
	mReferenceDacP2 = (referenceValueP2 - minValue) / (maxValue - minValue) * mDacMax;
	mReferenceOffset = mReferenceDacP2 - mReferenceDacP1;
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

float AnalogOutput::calculate(float voltage)
{
	float output = (voltage - mErrorP1) / (mErrorOffset) * (mReferenceOffset) + mReferenceDacP1;

	if(output > mDacMax - 1)
		return mDacMax - 1;
	else
		return output;
}

uint32_t AnalogOutput::getReferenceDacP1(void)
{
	return mReferenceDacP1;
}

uint32_t AnalogOutput::getReferenceDacP2(void)
{
	return mReferenceDacP2;
}

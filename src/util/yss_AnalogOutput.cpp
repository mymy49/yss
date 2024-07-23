/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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

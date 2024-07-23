/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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

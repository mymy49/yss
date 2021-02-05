#include <util/Measure.h>

Measure::Measure(void)
{
	mAdcP1 = mAdcP2 = mValueP1 = mValueP2 = 0;
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

void Measure::setValueP1(float val)
{
	mValueP1 = val;
	mValueOffset = mValueP2 - mValueP1;
}

void Measure::setValueP2(float val)
{
	mValueP2 = val;
	mValueOffset = mValueP2 - mValueP1;
}

float Measure::calculate(float adc)
{
	if(mAdcOffset != 0)
		return (adc - mAdcP1) / mAdcOffset * mValueOffset + mValueP1;
	else
		return 0;
}

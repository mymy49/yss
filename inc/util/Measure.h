/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_UTIL_MEASURE__H_
#define	YSS_UTIL_MEASURE__H_

class Measure
{
	float mAdcP1, mAdcP2, mValueP1, mValueP2, mAdcOffset, mValueOffset;
public:
	Measure(float valueP1, float ValueP2);
	Measure(void);
	void setValueP1(float value);
	void setValueP2(float value);
	void setAdcP1(float val);
	void setAdcP2(float val);
	float calculate(float adc);
};

#endif
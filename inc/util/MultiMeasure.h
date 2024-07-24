/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_MULTI_MEASURE__H_
#define YSS_UTIL_MULTI_MEASURE__H_

#include <stdint.h>

class MultiMeasure
{
	uint16_t mMaxPoint, mWorkingPoint;
	float *mValue, *mAdc;

  public:
	MultiMeasure(uint16_t maxPoint);
	void setPoint(uint16_t num, float value, float adc);
	void setNumberOfPoint(uint16_t num);
	void getPoint(uint16_t num, float *value, float *adc);
	uint16_t getNumberOfPoint(void);
	float calculate(float adc);
};

#endif
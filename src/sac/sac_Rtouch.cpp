/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#include <sac/Rtouch.h>
#include <yss/event.h>
#include <yss/PointerEvent.h>
#include <yss/debug.h>

namespace  sac
{
	Rtouch::Rtouch(void)
	{
		mCalibrationData = 0;
	}
	
	void Rtouch::setCalibrationData(const CalibrationData &calibrationData)
	{
		mCalibrationData = &calibrationData;
	}

	const Rtouch::CalibrationData* Rtouch::getCalibrationData(void)
	{
		return mCalibrationData;
	}

	uint16_t Rtouch::calculateX(int32_t x)
	{
		int32_t width = mCalibrationData->width - mCalibrationData->xOffset * 2;

		x = (x - mCalibrationData->p1x) * width / (mCalibrationData->p2x - mCalibrationData->p1x) + mCalibrationData->xOffset;
		if(x < 0)
			x = 0;
		else if(x > mCalibrationData->width)
			x = mCalibrationData->width;
		
		return (uint16_t)x;
	}

	uint16_t Rtouch::calculateY(int32_t y)
	{
		int32_t height = mCalibrationData->height - mCalibrationData->yOffset * 2;

		y = (y - mCalibrationData->p1y) * height / (mCalibrationData->p2y - mCalibrationData->p1y) + mCalibrationData->yOffset;
		if(y < 0)
			y = 0;
		else if(y > mCalibrationData->height)
			y = mCalibrationData->height;

		return (uint16_t)y;
	}

	Position_t Rtouch::calculate(int32_t x, int32_t y)
	{
		int32_t width = mCalibrationData->width - mCalibrationData->xOffset * 2;
		int32_t height = mCalibrationData->height - mCalibrationData->yOffset * 2;
		x = (x - mCalibrationData->p1x) * width / (mCalibrationData->p2x - mCalibrationData->p1x) + mCalibrationData->xOffset;
		if(x < 0)
			x = 0;
		else if(x > mCalibrationData->width)
			x = mCalibrationData->width;
		
		y = (y - mCalibrationData->p1y) * height / (mCalibrationData->p2y - mCalibrationData->p1y) + mCalibrationData->yOffset;
		if(y < 0)
			y = 0;
		else if(y > mCalibrationData->height)
			y = mCalibrationData->height;
		return Position_t {(int16_t)x, (int16_t)y};
	}
}


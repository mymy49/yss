/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_HAL_RESISTIVE_TOUCH__H_
#define	YSS_HAL_RESISTIVE_TOUCH__H_

#include "PointerDevice.h"
#include <yss/Position.h>

class Position;

class ResistiveTouch : public PointerDevice
{		
public :
	struct calibration_t
	{
		uint16_t topLeftX;
		uint16_t topLeftY;
		uint16_t botRightX;
		uint16_t botRightY;
		uint16_t width;
		uint16_t height;
	};

	ResistiveTouch();

	void setCalibrationData(calibration_t data);

	calibration_t getCalibrationData();

	Position calculate(uint16_t x, uint16_t y);

	uint16_t calculateX(uint16_t x);

	uint16_t calculateY(uint16_t y);

	uint16_t getLastConvertedAdcX();
	
	uint16_t getLastConvertedAdcY();

protected :
	int32_t mXDivider; 
	int32_t mYDivider;
	Position mPosition;

	void update();

private :
	calibration_t mCalibrationData;
	uint16_t mLastConvertedAdcX;
	uint16_t mLastConvertedAdcY;
};

#endif


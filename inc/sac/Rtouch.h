/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_SAC_RTOUCH__H_
#define	YSS_SAC_RTOUCH__H_

#include "Touch.h"

namespace sac
{
	class Rtouch : public Touch
	{
	public :
		struct CalibrationData
		{
			int32_t p1x;
			int32_t p1y;
			int32_t p2x;
			int32_t p2y;
			int32_t xOffset;
			int32_t yOffset;
			int32_t width;
			int32_t height;
		};

		Rtouch(void);
		void setCalibrationData(const CalibrationData &calibrationData);
		const CalibrationData* getCalibrationData(void);

	private:
		Position_t calculate(int32_t x, int32_t y);
		uint16_t calculateY(int32_t y);
		uint16_t calculateX(int32_t x);
		const CalibrationData *mCalibrationData;
	};
}

#endif

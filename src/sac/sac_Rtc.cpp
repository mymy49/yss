/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <sac/Rtc.h>

namespace sac
{
#define SEC_FOR_DAY		(24 * 60 * 60)
	static const int32_t  secTableForMonth[13] = {0, 0, 31*SEC_FOR_DAY, 59*SEC_FOR_DAY, 90*SEC_FOR_DAY, 120*SEC_FOR_DAY, 151*SEC_FOR_DAY, 181*SEC_FOR_DAY, 212*SEC_FOR_DAY, 243*SEC_FOR_DAY, 273*SEC_FOR_DAY, 304*SEC_FOR_DAY, 334*SEC_FOR_DAY};

	uint32_t Rtc::calculateTimeLapse(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
	{
		if(month > 12)
			return 0;

		uint32_t timelapse = (uint32_t)year * (365 * SEC_FOR_DAY);
		timelapse += secTableForMonth[month];
		day += (uint8_t)(year / 4);
		timelapse += (day - 1) * SEC_FOR_DAY;
		timelapse += hour * 60 * 60;
		timelapse += min * 60;
		timelapse += sec;

		return timelapse;
	}

	uint32_t Rtc::getTimeLapse(void)
	{
		return calculateTimeLapse(getYear(), getMonth(), getDay(), getHour(), getMin(), getSec());
	}

	int32_t Rtc::compareTimeLapse(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
	{
		int32_t timelapse = (int32_t)calculateTimeLapse(getYear(), getMonth(), getDay(), getHour(), getMin(), getSec());
		return timelapse-(int32_t)calculateTimeLapse(year, month, day, hour, min, sec);
	}
}

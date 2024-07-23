/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_RTC__H_
#define YSS_SAC_RTC__H_

#include <stdint.h>

namespace sac
{
class Rtc
{
  public:
	uint32_t getTimeLapse(void);
	int32_t compareTimeLapse(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);
	uint32_t calculateTimeLapse(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);

	virtual void refresh(void) = 0;

	virtual uint8_t getYear(void) = 0;
	virtual bool setYear(uint8_t year) = 0;
	virtual uint8_t getMonth(void) = 0;
	virtual bool setMonth(uint8_t month) = 0;
	virtual uint8_t getDay(void) = 0;
	virtual bool setDay(uint8_t day) = 0;
	virtual uint8_t getWeekDay(void) = 0;
	virtual bool setWeekDay(uint8_t weekDay) = 0;

	virtual uint8_t getHour(void) = 0;
	virtual bool setHour(uint8_t hour) = 0;
	virtual uint8_t getMin(void) = 0;
	virtual bool setMin(uint8_t min) = 0;
	virtual uint8_t getSec(void) = 0;
	virtual bool setSec(uint8_t min) = 0;
	virtual uint16_t getSubsec(void) = 0;
};
}

#endif
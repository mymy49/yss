/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_RTC_CALENDAR__H_
#define YSS_SAC_RTC_CALENDAR__H_

#include <sac/Rtc.h>

namespace sac
{
class RtcCalendar : public sac::Rtc
{
  public:
	uint8_t getYear(void);
	bool setYear(uint8_t year);
	uint8_t getMonth(void);
	bool setMonth(uint8_t month);
	uint8_t getDay(void);
	bool setDay(uint8_t day);
	uint8_t getWeekDay(void);
	bool setWeekDay(uint8_t weekDay);

	uint8_t getHour(void);
	bool setHour(uint8_t hour);
	uint8_t getMin(void);
	bool setMin(uint8_t min);
	uint8_t getSec(void);
	bool setSec(uint8_t min);
	uint16_t getSubsec(void);

	virtual uint32_t getCounter(void) = 0;
	virtual bool setCounter(uint32_t cnt) = 0;
};
}

#endif
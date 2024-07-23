/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_RTC_HT1382__H_
#define YSS_MOD_RTC_HT1382__H_

#include <sac/Rtc.h>
#include <yss/instance.h>

#ifndef YSS_DRV_I2C_UNSUPPORTED

class HT1382 : public sac::Rtc
{
	I2c *mPeri;
	bool mInitFlag;
	uint8_t mTimeBuf[7];

	uint8_t read(uint8_t addr);
	void write(uint8_t addr, uint8_t data);

  public:
	bool init(I2c &peri);
	void refresh(void);

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

	bool setTime(uint8_t year, uint8_t month, uint8_t day, uint8_t dayOfWeek, uint8_t hour, uint8_t min, uint8_t sec);
};

#endif

#endif

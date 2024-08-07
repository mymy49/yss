/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/rtc/HT1382.h>

#ifndef YSS_DRV_I2C_UNSUPPORTED

#define ADDR	0xd0

bool HT1382::init(I2c &peri)
{
	mPeri = &peri;
	mInitFlag = true;

	refresh();

	if((read(0) & 0x80) || (read(7) & 0x80))
	{
		write(7, 0x00);
		write(0, 0x00);
		return true;
	}
	else
		return false;
}

uint8_t HT1382::read(uint8_t addr)
{
	if(addr > 20)
		return 0;

	mPeri->lock();
	mPeri->send(ADDR, &addr, 1, 300);
	mPeri->receive(ADDR, &addr, 1, 300);
	mPeri->unlock();

	return addr;
}

void HT1382::write(uint8_t addr, uint8_t data)
{
	uint8_t buf[2];

	if(addr > 20)
		return;

	buf[0] = addr;
	buf[1] = data;

	mPeri->lock();
	mPeri->send(ADDR, buf, 2, 300);
	mPeri->stop();
	mPeri->unlock();
}

void HT1382::refresh(void)
{
	uint8_t addr = 0;

	mPeri->lock();
	mPeri->send(ADDR, &addr, 1, 300);
	mPeri->receive(ADDR, mTimeBuf, 7, 300);
	mPeri->unlock();
}

uint16_t HT1382::getSubsec(void)
{
	return 0;
}

uint8_t HT1382::getSec(void)
{
	uint8_t sec = (mTimeBuf[0] >> 4) & 0x7;
	sec *= 10;
	sec += mTimeBuf[0] & 0x0f;

	return sec;
}

bool HT1382::setSec(uint8_t sec)
{
	refresh();
	return setTime(getYear(), getMonth(), getDay(), getWeekDay(), getHour(), getMin(), sec);
}

uint8_t HT1382::getMin(void)
{
	uint8_t min = mTimeBuf[1] >> 4;
	min *= 10;
	min += mTimeBuf[1] & 0x0f;

	return min;
}

bool HT1382::setMin(uint8_t min)
{
	refresh();
	return setTime(getYear(), getMonth(), getDay(), getWeekDay(), getHour(), min, getSec());
}

uint8_t HT1382::getHour(void)
{
	uint8_t hour;
	if(mTimeBuf[2] & 0x80)
	{
		hour = (mTimeBuf[2] >> 4) & 0x03;
		hour *= 10;
		hour += mTimeBuf[2] & 0x0f;
	}
	else
	{
		hour = mTimeBuf[2] >> 5;
		hour += (mTimeBuf[2] >> 4) & 0x01;
		hour *= 10;
		hour += mTimeBuf[2] & 0x0f;
	}

	return hour;
}

bool HT1382::setHour(uint8_t hour)
{
	refresh();
	return setTime(getYear(), getMonth(), getDay(), getWeekDay(), hour, getMin(), getSec());
}

uint8_t HT1382::getDay(void)
{
	uint8_t date = mTimeBuf[3] >> 4;
	date *= 10;
	date += mTimeBuf[3] & 0x0f;

	return date;
}

bool HT1382::setDay(uint8_t day)
{
	refresh();
	return setTime(getYear(), getMonth(), day, getWeekDay(), getHour(), getMin(), getSec());
}

uint8_t HT1382::getMonth(void)
{
	uint8_t month = mTimeBuf[4] >> 4;
	month *= 10;
	month += mTimeBuf[4] & 0x0f;

	return month;
}

bool HT1382::setMonth(uint8_t month)
{
	refresh();
	return setTime(getYear(), month, getDay(), getWeekDay(), getHour(), getMin(), getSec());
}

uint8_t HT1382::getYear(void)
{
	uint8_t year = mTimeBuf[6] >> 4;
	year *= 10;
	year += mTimeBuf[6] & 0x0f;

	return year;
}

bool HT1382::setYear(uint8_t year)
{
	refresh();
	return setTime(year, getMonth(), getDay(), getWeekDay(), getHour(), getMin(), getSec());
}

uint8_t HT1382::getWeekDay(void)
{
	return mTimeBuf[5];
}

bool HT1382::setWeekDay(uint8_t weekDay)
{
	refresh();
	return setTime(getYear(), getMonth(), getDay(), weekDay, getHour(), getMin(), getSec());
}

bool HT1382::setTime(uint8_t year, uint8_t month, uint8_t day, uint8_t dayOfWeek, uint8_t hour, uint8_t min, uint8_t sec)
{
	uint8_t buf[8];
	bool result;

	buf[0] = 0;
	buf[1] = (sec/10) << 4 | (sec % 10);
	buf[2] = (min/10) << 4 | (min % 10);
	buf[3] = (hour/10) << 4 | (hour % 10);
	buf[4] = (day/10) << 4 | (day % 10) | 0x80;
	buf[5] = (month/10) << 4 | (month % 10);
	buf[6] = dayOfWeek;
	buf[7] = (year/10) << 4 | (year % 10);

	mPeri->lock();
	result = mPeri->send(ADDR, buf, 8, 300);
	mPeri->stop();
	mPeri->unlock();

	return result;
}

#endif


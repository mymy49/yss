////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <sac/RtcCalendar.h>

namespace sac
{
#define SEC_FOR_DAY (24 * 60 * 60)
static const int32_t  gSecTableForMonth[12] = {0, 31 * SEC_FOR_DAY, 59 * SEC_FOR_DAY, 90 * SEC_FOR_DAY, 120 * SEC_FOR_DAY, 151 * SEC_FOR_DAY, 181 * SEC_FOR_DAY, 212 * SEC_FOR_DAY, 243 * SEC_FOR_DAY, 273 * SEC_FOR_DAY, 304 * SEC_FOR_DAY, 334 * SEC_FOR_DAY};
static const int32_t  gEndDayOfMonth1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const int32_t  gEndDayOfMonth2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

uint8_t RtcCalendar::getYear(void)
{
	int32_t  day = getCounter() / 86400;
	day -= day / 1460 + 1;
	return day / 365;
}

bool RtcCalendar::setYear(uint8_t year)
{
	int32_t  sec = getCounter() % 86400;
	int32_t  month = getMonth();
	int32_t  day = getDay();

	if (month > 2)
		day += year / 4 + 1;
	else
		day += (year - 1) / 4 + 1;

	sec += gSecTableForMonth[month - 1] + (year * (365 * 86400)) + ((day - 1) * 86400);
	return setCounter(sec);
}

uint8_t RtcCalendar::getMonth(void)
{
	int32_t  day = getCounter() / 86400;
	day -= day / 1460 + 1;
	day %= 365;
	for (int32_t  i = 11; i > 0; i--)
	{
		if (day >= (gSecTableForMonth[i] / SEC_FOR_DAY))
			return i + 1;
	}

	return 1;
}

bool RtcCalendar::setMonth(uint8_t month)
{
	if (month < 1 || month > 12)
		return false;

	int32_t  year = getYear();
	int32_t  sec = gSecTableForMonth[month - 1] + (getCounter() % 86400) + (year * (365 * 86400)) + ((getDay() - 1) * 86400);

	if (month > 2)
		sec += ((year / 4 + 1) * 86400);

	return setCounter(sec);
}

uint8_t RtcCalendar::getDay(void)
{
	int32_t  day = getCounter() / 86400;
	day -= day / 1460 + 1;
	day %= 365;
	for (int32_t  i = 11; i >= 0; i--)
	{
		if (day >= (gSecTableForMonth[i] / SEC_FOR_DAY))
			return day - gSecTableForMonth[i] / SEC_FOR_DAY + 1;
	}

	return 1;
}

bool RtcCalendar::setDay(uint8_t day)
{
	int32_t  year = getYear(), month = getMonth(), sec;

	if (year % 4 == 0)
		sec = gEndDayOfMonth2[month - 1];
	else
		sec = gEndDayOfMonth1[month - 1];

	if (1 < day && day > sec)
		return false;

	if (month > 2)
		day += year / 4 + 1;
	else
		day += (year - 1) / 4 + 1;

	sec = getCounter() % 86400;
	sec += (year * (365 * 86400)) + gSecTableForMonth[month - 1] + (day - 1) * 86400;

	return setCounter(sec);
}

uint8_t RtcCalendar::getWeekDay(void)
{
	return (getCounter() / 86400 + 5) % 7 + 1;
}

bool RtcCalendar::setWeekDay(uint8_t weekDay)
{
	return false;
}

uint8_t RtcCalendar::getHour(void)
{
	return getCounter() / 3600 % 24;
}

bool RtcCalendar::setHour(uint8_t hour)
{
	int32_t  sec = getCounter();
	int32_t  day = sec / (3600 * 24);
	sec %= 3600;
	sec += hour * 3600 + day * (3600 * 24);
	return setCounter(sec);
}

uint8_t RtcCalendar::getMin(void)
{
	return getCounter() / 60 % 60;
}

bool RtcCalendar::setMin(uint8_t min)
{
	int32_t  sec = getCounter();
	int32_t  hour = sec / 3600;
	sec %= 60;
	sec += hour * 3600 + min * 60;
	return setCounter(sec);
}

uint8_t RtcCalendar::getSec(void)
{
	return getCounter() % 60;
}

bool RtcCalendar::setSec(uint8_t sec)
{
	int32_t  buf = getCounter();
	int32_t  min = buf / 60;
	buf = min * 60 + sec;
	return setCounter(buf);
}

uint16_t RtcCalendar::getSubsec(void)
{
	return 0;
}
}
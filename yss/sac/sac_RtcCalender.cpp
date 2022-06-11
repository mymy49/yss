////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

//#include <__cross_studio_io.h>
#include <sac/RtcCalendar.h>

namespace sac
{
#define SEC_FOR_DAY (24 * 60 * 60)
static const int gSecTableForMonth[12] = {0, 31 * SEC_FOR_DAY, 59 * SEC_FOR_DAY, 90 * SEC_FOR_DAY, 120 * SEC_FOR_DAY, 151 * SEC_FOR_DAY, 181 * SEC_FOR_DAY, 212 * SEC_FOR_DAY, 243 * SEC_FOR_DAY, 273 * SEC_FOR_DAY, 304 * SEC_FOR_DAY, 334 * SEC_FOR_DAY};
static const int gEndDayOfMonth1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const int gEndDayOfMonth2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

unsigned char RtcCalendar::getYear(void)
{
	int day = getCounter() / 86400;
	day -= day / 1460 + 1;
	return day / 365;
}

bool RtcCalendar::setYear(unsigned char year)
{
	int sec = getCounter() % 86400;
	int month = getMonth();
	int day = getDay();

	if (month > 2)
		day += year / 4 + 1;
	else
		day += (year - 1) / 4 + 1;

	sec += gSecTableForMonth[month - 1] + (year * (365 * 86400)) + ((day - 1) * 86400);
	return setCounter(sec);
}

unsigned char RtcCalendar::getMonth(void)
{
	int day = getCounter() / 86400;
	day -= day / 1460 + 1;
	day %= 365;
	for (int i = 11; i > 0; i--)
	{
		if (day >= (gSecTableForMonth[i] / SEC_FOR_DAY))
			return i + 1;
	}

	return 1;
}

bool RtcCalendar::setMonth(unsigned char month)
{
	if (month < 1 || month > 12)
		return false;

	int year = getYear();
	int sec = gSecTableForMonth[month - 1] + (getCounter() % 86400) + (year * (365 * 86400)) + ((getDay() - 1) * 86400);

	if (month > 2)
		sec += ((year / 4 + 1) * 86400);

	return setCounter(sec);
}

unsigned char RtcCalendar::getDay(void)
{
	int day = getCounter() / 86400;
	day -= day / 1460 + 1;
	day %= 365;
	for (int i = 11; i >= 0; i--)
	{
		if (day >= (gSecTableForMonth[i] / SEC_FOR_DAY))
			return day - gSecTableForMonth[i] / SEC_FOR_DAY + 1;
	}

	return 1;
}

bool RtcCalendar::setDay(unsigned char day)
{
	int year = getYear(), month = getMonth(), sec;

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

unsigned char RtcCalendar::getWeekDay(void)
{
	return (getCounter() / 86400 + 5) % 7 + 1;
}

bool RtcCalendar::setWeekDay(unsigned char weekDay)
{
	return false;
}

unsigned char RtcCalendar::getHour(void)
{
	return getCounter() / 3600 % 24;
}

bool RtcCalendar::setHour(unsigned char hour)
{
	int sec = getCounter();
	int day = sec / (3600 * 24);
	sec %= 3600;
	sec += hour * 3600 + day * (3600 * 24);
	return setCounter(sec);
}

unsigned char RtcCalendar::getMin(void)
{
	return getCounter() / 60 % 60;
}

bool RtcCalendar::setMin(unsigned char min)
{
	int sec = getCounter();
	int hour = sec / 3600;
	sec %= 60;
	sec += hour * 3600 + min * 60;
	return setCounter(sec);
}

unsigned char RtcCalendar::getSec(void)
{
	return getCounter() % 60;
}

bool RtcCalendar::setSec(unsigned char sec)
{
	int buf = getCounter();
	int min = buf / 60;
	buf = min * 60 + sec;
	return setCounter(buf);
}

unsigned short RtcCalendar::getSubsec(void)
{
	return 0;
}
}
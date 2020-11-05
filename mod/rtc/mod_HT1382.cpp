////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2020.02.14 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/rtc/HT1382.h>
#include <__cross_studio_io.h>

#define ADDR	0xd0

namespace mod
{
namespace rtc
{
    bool HT1382::init(drv::I2c &peri)
	{
		unsigned char data[20];

		mPeri = &peri;
        mInitFlag = true;

		refresh();
		
		if((read(0) & 0x80) || (read(7) & 0x80))
		{
			write(7, 0x00);
			write(0, 0x00);
		}
			
		return true;
	}
	
	unsigned char HT1382::read(unsigned char addr)
	{
		if(addr > 20)
			return 0;
		
		mPeri->lock();
		mPeri->send(ADDR, &addr, 1, 300);
		mPeri->receive(ADDR, &addr, 1, 300);
		mPeri->unlock();

		return addr;
	}

	void HT1382::write(unsigned char addr, unsigned char data)
	{
		unsigned char buf[2];

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
		unsigned char addr = 0;

		mPeri->lock();
		mPeri->send(ADDR, &addr, 1, 300);
		mPeri->receive(ADDR, mTimeBuf, 7, 300);
		mPeri->unlock();
	}

	unsigned char HT1382::getSec(void)
	{
		unsigned char sec = (mTimeBuf[0] >> 4) & 0x7;
		sec *= 10;
		sec += mTimeBuf[0] & 0x0f;

		return sec;
	}

	unsigned char HT1382::getMin(void)
	{
		unsigned char min = mTimeBuf[1] >> 4;
		min *= 10;
		min += mTimeBuf[1] & 0x0f;

		return min;
	}

	unsigned char HT1382::getHour(void)
	{
		unsigned char hour;
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

	unsigned char HT1382::getDay(void)
	{
		unsigned char date = mTimeBuf[3] >> 4;
		date *= 10;
		date += mTimeBuf[3] & 0x0f;

		return date;
	}

	unsigned char HT1382::getMonth(void)
	{
		unsigned char month = mTimeBuf[4] >> 4;
		month *= 10;
		month += mTimeBuf[4] & 0x0f;

		return month;
	}

	unsigned char HT1382::getYear(void)
	{
		unsigned char year = mTimeBuf[6] >> 4;
		year *= 10;
		year += mTimeBuf[6] & 0x0f;

		return year;
	}

	void HT1382::setTime(unsigned char year, unsigned char month, unsigned char day, unsigned char dayOfWeek, unsigned char hour, unsigned char min, unsigned char sec)
	{
		unsigned char buf[8];

		buf[0] = 0;
		buf[1] = (sec/10) << 4 | (sec % 10);
		buf[2] = (min/10) << 4 | (min % 10);
		buf[3] = (hour/10) << 4 | (hour % 10);
		buf[4] = (day/10) << 4 | (day % 10) | 0x80;
		buf[5] = (month/10) << 4 | (month % 10);
		buf[6] = dayOfWeek;
		buf[7] = (year/10) << 4 | (year % 10);

		mPeri->lock();
		mPeri->send(ADDR, buf, 8, 300);
		mPeri->stop();
		mPeri->unlock();
	}
}
}

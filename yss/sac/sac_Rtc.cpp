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

#include <sac/Rtc.h>

namespace sac
{
#define SEC_FOR_DAY		(24 * 60 * 60)
	static const int secTableForMonth[13] = {0, 0, 31*SEC_FOR_DAY, 59*SEC_FOR_DAY, 90*SEC_FOR_DAY, 120*SEC_FOR_DAY, 151*SEC_FOR_DAY, 181*SEC_FOR_DAY, 212*SEC_FOR_DAY, 243*SEC_FOR_DAY, 273*SEC_FOR_DAY, 304*SEC_FOR_DAY, 334*SEC_FOR_DAY};

	unsigned long Rtc::calculateTimeLapse(unsigned char year, unsigned char month, unsigned char day, unsigned char hour, unsigned char min, unsigned char sec)
	{
		if(month > 12)
			return 0;

		unsigned int timelapse = (unsigned int)year * (365 * SEC_FOR_DAY);
		timelapse += secTableForMonth[month];
		day += (unsigned char)(year / 4);
		timelapse += (day - 1) * SEC_FOR_DAY;
		timelapse += hour * 60 * 60;
		timelapse += min * 60;
		timelapse += sec;

		return timelapse;
	}

	unsigned long Rtc::getTimeLapse(void)
	{
		return calculateTimeLapse(getYear(), getMonth(), getDay(), getHour(), getMin(), getSec());
	}

	signed long Rtc::compareTimeLapse(unsigned char year, unsigned char month, unsigned char day, unsigned char hour, unsigned char min, unsigned char sec)
	{
		signed long timelapse = (signed long)calculateTimeLapse(getYear(), getMonth(), getDay(), getHour(), getMin(), getSec());
		return timelapse-(signed long)calculateTimeLapse(year, month, day, hour, min, sec);
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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

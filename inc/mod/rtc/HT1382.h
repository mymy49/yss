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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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

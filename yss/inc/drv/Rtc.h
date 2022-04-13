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

#ifndef YSS_DRV_RTC__H_
#define YSS_DRV_RTC__H_

#include "mcu.h"

#if defined(STM32F1)

#define USE_CALENDAR

typedef RTC_TypeDef		YSS_RTC_Peri;

#include "rtc/define_rtc_stm32f1.h"

#elif defined(STM32F4) || defined(STM32L0) || defined(STM32F7)

#define USE_RTC_INTERFACE

typedef RTC_TypeDef		YSS_RTC_Peri;

#include "rtc/define_rtc_stm32f4_f7_g4.h"

#else

#define YSS_DRV_RTC_UNSUPPORTED

#endif

#ifndef YSS_DRV_RTC_UNSUPPORTED

#include <drv/Drv.h>
#include <sac/RtcCalendar.h>

namespace drv
{
#if defined(USE_CALENDAR)
class Rtc : public Drv, public sac::RtcCalendar
#elif defined(USE_RTC_INTERFACE)
class Rtc : public Drv, public sac::Rtc
#else
class Rtc : public Drv
#endif
{
	YSS_RTC_Peri *mPeri;

	void unprotect(void);
	void protect(void);

  public:
	Rtc(YSS_RTC_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void));

	bool init(unsigned char src, unsigned int freq, unsigned char lseDrive = 0);
	void refresh(void);

	unsigned int getCounter(void);
	bool setCounter(unsigned int cnt);

#if defined(STM32F7) || defined(STM32F4) || defined(STM32L0) || defined(STM32G4)
	unsigned char getYear(void);
	bool setYear(unsigned char year);
	unsigned char getMonth(void);
	bool setMonth(unsigned char month);
	unsigned char getDay(void);
	bool setDay(unsigned char day);
	unsigned char getWeekDay(void);
	bool setWeekDay(unsigned char weekDay);

	unsigned char getHour(void);
	bool setHour(unsigned char hour);
	unsigned char getMin(void);
	bool setMin(unsigned char min);
	unsigned char getSec(void);
	bool setSec(unsigned char min);
	unsigned short getSubsec(void);
#endif
};
}

#endif

#endif


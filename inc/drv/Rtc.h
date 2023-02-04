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

#ifndef YSS_DRV_RTC__H_
#define YSS_DRV_RTC__H_

#include "mcu.h"

#if false
//#if defined(STM32F1)

#define USE_CALENDAR

typedef RTC_TypeDef		YSS_RTC_Peri;

#include "rtc/define_rtc_stm32f1.h"

#elif defined(STM32F4) || defined(STM32L0) || defined(STM32F7)

#define USE_RTC_INTERFACE

typedef volatile uint32_t		YSS_RTC_Peri;

#include "rtc/define_rtc_stm32f4_f7_g4.h"

#else

#define YSS_DRV_RTC_UNSUPPORTED

#endif

#ifndef YSS_DRV_RTC_UNSUPPORTED

#include "Drv.h"
#include <sac/RtcCalendar.h>

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

	bool init(uint8_t src, uint32_t freq, uint8_t lseDrive = 0);
	void refresh(void);

	uint32_t getCounter(void);
	bool setCounter(uint32_t cnt);

#if defined(STM32F7) || defined(STM32F4) || defined(STM32L0) || defined(STM32G4)
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
#endif
};

#endif

#endif


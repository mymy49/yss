/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_RTC__H_
#define YSS_DRV_RTC__H_

#include "mcu.h"

#if false

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


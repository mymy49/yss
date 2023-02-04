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

#ifndef YSS_DRV_RTC_ST_TYPE_A_REG__H_
#define YSS_DRV_RTC_ST_TYPE_A_REG__H_

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
	defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
	defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
	defined(STM32F429xx) || defined(STM32F439xx) ||                                                 \
	defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
	defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
	defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
	defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
	defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
	defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
	defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx) || \
	defined(STM32G431xx) || defined(STM32G441xx) || \
	defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)


#include <yss/reg.h>

#define getRtcSecUnit() getRegField(RTC->TR, 0xf, 0)
#define setRtcSecUnit(x) setRegField(RTC->TR, 0xf, x, 0)
#define getRtcSecTen() getRegField(RTC->TR, 0x7, 4)
#define setRtcSecTen(x) setRegField(RTC->TR, 0x7, x, 4)
#define getRtcMinUnit() getRegField(RTC->TR, 0xf, 8)
#define setRtcMinUnit(x) setRegField(RTC->TR, 0xf, x, 8)
#define getRtcMinTen() getRegField(RTC->TR, 0x7, 12)
#define setRtcMinTen(x) setRegField(RTC->TR, 0x7, x, 12)
#define getRtcHourUnit() getRegField(RTC->TR, 0xf, 16)
#define setRtcHourUnit(x) setRegField(RTC->TR, 0xf, x, 16)
#define getRtcHourTen() getRegField(RTC->TR, 0x3, 20)
#define setRtcHourTen(x) setRegField(RTC->TR, 0x3, x, 20)

#define getRtcDayUnit() getRegField(RTC->DR, 0xf, 0)
#define setRtcDayUnit(x) setRegField(RTC->DR, 0xf, x, 0)
#define getRtcDayTen() getRegField(RTC->DR, 0x3, 4)
#define setRtcDayTen(x) setRegField(RTC->DR, 0x3, x, 4)
#define getRtcMonthUnit() getRegField(RTC->DR, 0xf, 8)
#define setRtcMonthUnit(x) setRegField(RTC->DR, 0xf, x, 8)
#define getRtcMonthTen() getRegField(RTC->DR, 0x1, 12)
#define setRtcMonthTen(x) setRegField(RTC->DR, 0x1, x, 12)
#define getRtcWeekDayUnit() getRegField(RTC->DR, 0x7, 13)
#define setRtcWeekDayUnit(x) setRegField(RTC->DR, 0x7, x, 13)
#define getRtcYearUnit() getRegField(RTC->DR, 0xf, 16)
#define setRtcYearUnit(x) setRegField(RTC->DR, 0xf, x, 16)
#define getRtcYearTen() getRegField(RTC->DR, 0xf, 20)
#define setRtcYearTen(x) setRegField(RTC->DR, 0xf, x, 20)

#define setRtcBypassShadowReg(x) setRegBit(RTC->CR, x, 5)

#define getRtcSyncFlag() getRegBit(RTC->ISR, 5)
#define getRtcInitf() getRegBit(RTC->ISR, 6)
#define setRtcInit(x) setRegBit(RTC->ISR, x, 7)

#define setRtcSyncPrescaler(x) setRegField(RTC->PRER, 0x7FFFUL, x, 0)
#define setRtcAsyncPrescaler(x) setRegField(RTC->PRER, 0x7FUL, x, 16)

#endif

#endif
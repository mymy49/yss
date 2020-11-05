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
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_RTC_ST_TYPE_A_REG__H_
#define YSS_DRV_RTC_ST_TYPE_A_REG__H_

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <yss/reg.h>

#define getRtcSecUnit()			getRegField(RTC->TR, 0xf, 0)
#define setRtcSecUnit(x)		setRegField(RTC->TR, 0xf, x, 0)
#define getRtcSecTen()			getRegField(RTC->TR, 0x7, 4)
#define setRtcSecTen(x)			setRegField(RTC->TR, 0x7, x, 4)
#define getRtcMinUnit()			getRegField(RTC->TR, 0xf, 8)
#define setRtcMinUnit(x)		setRegField(RTC->TR, 0xf, x, 8)
#define getRtcMinTen()			getRegField(RTC->TR, 0x7, 12)
#define setRtcMinTen(x)			setRegField(RTC->TR, 0x7, x, 12)
#define getRtcHourUnit()		getRegField(RTC->TR, 0xf, 16)
#define setRtcHourUnit(x)		setRegField(RTC->TR, 0xf, x, 16)
#define getRtcHourTen()			getRegField(RTC->TR, 0x3, 20)
#define setRtcHourTen(x)		setRegField(RTC->TR, 0x3, x, 20)

#define getRtcDayUnit()			getRegField(RTC->DR, 0xf, 0)
#define setRtcDayUnit(x)		setRegField(RTC->DR, 0xf, x, 0)
#define getRtcDayTen()			getRegField(RTC->DR, 0x3, 4)
#define setRtcDayTen(x)			setRegField(RTC->DR, 0x3, x, 4)
#define getRtcMonthUnit()		getRegField(RTC->DR, 0xf, 8)
#define setRtcMonthUnit(x)		setRegField(RTC->DR, 0xf, x, 8)
#define getRtcMonthTen()		getRegField(RTC->DR, 0x1, 12)
#define setRtcMonthTen(x)		setRegField(RTC->DR, 0x1, x, 12)
#define getRtcWeekDayUnit()		getRegField(RTC->DR, 0x7, 13)
#define setRtcWeekDayUnit(x)	setRegField(RTC->DR, 0x7, x, 13)
#define getRtcYearUnit()		getRegField(RTC->DR, 0xf, 16)
#define setRtcYearUnit(x)		setRegField(RTC->DR, 0xf, x, 16)
#define getRtcYearTen()			getRegField(RTC->DR, 0xf, 20)
#define setRtcYearTen(x)		setRegField(RTC->DR, 0xf, x, 20)

#define setRtcBypassShadowReg(x)setRegBit(RTC->CR, x, 5)

#define getRtcSyncFlag()		getRegBit(RTC->ISR, 5)
#define getRtcInitf()			getRegBit(RTC->ISR, 6)
#define setRtcInit(x)			setRegBit(RTC->ISR, x, 7)

#define setRtcSyncPrescaler(x)	setRegField(RTC->PRER, 0x7FFFUL, x, 0)
#define setRtcAsyncPrescaler(x)	setRegField(RTC->PRER, 0x7FUL, x, 16)

#endif

#endif

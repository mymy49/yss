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
//  주담당자 : 아이구 (mymy49@nate.com) 2018.02.08 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(MAX32660)

#include <__cross_studio_io.h>

#include <yss/thread.h>
#include <util/time.h>

#include <drv/peripherals.h>

#if defined(RTC_ENABLE) && defined(MXC_RTC)

drv::Rtc rtc(MXC_RTC, 0, 0);
#endif

namespace drv
{
	inline bool enableClock(unsigned char src, unsigned char lseDrive);
	inline void setClockSrc(unsigned char src);
	inline unsigned char getClockSrc(void);

	Rtc::Rtc(mxc_rtc_regs_t *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
	{
		mPeri = peri;
	}

	bool Rtc::init(void)
	{
		return true;
	}

	void Rtc::refresh(void)
	{
	}

	unsigned char Rtc::getYear(void)
	{
		
	}

	bool Rtc::setYear(unsigned	char year)
	{
		return true;
	}

	unsigned char Rtc::getMonth(void)
	{
	}

	bool Rtc::setMonth(unsigned char month)
	{
	}

	unsigned char Rtc::getDay(void)
	{
	}

	bool Rtc::setDay(unsigned char	day)
	{
	}

	unsigned char Rtc::getWeekDay(void)
	{
	}

	bool Rtc::setWeekDay(unsigned char	weekDay)
	{
	}

	unsigned char Rtc::getHour(void)
	{
	}

	bool Rtc::setHour(unsigned	char hour)
	{
	}

	unsigned char Rtc::getMin(void)
	{
	}

	bool Rtc::setMin(unsigned char	min)
	{
	}

	unsigned char Rtc::getSec(void)
	{
	}

	bool Rtc::setSec(unsigned char	sec)
	{
	}

	unsigned short Rtc::getSubsec(void)
	{
	}
}

#endif

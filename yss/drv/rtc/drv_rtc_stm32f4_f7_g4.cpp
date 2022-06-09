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

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32L0) || defined(STM32F7)

#include <drv/Rtc.h>
#include <drv/rtc/register_rtc_stm32f4_f7_g4.h>
#include <util/time.h>
#include <yss/thread.h>

namespace drv
{
inline bool enableClock(unsigned char src, unsigned char lseDrive);
inline void setClockSrc(unsigned char src);
inline unsigned char getClockSrc(void);

Rtc::Rtc(RTC_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
}

bool Rtc::init(unsigned char src, unsigned int freq, unsigned char lseDrive)
{
	signed int apre = 0x7f, spre;
	unsigned long long endTime = time::getRunningMsec() + 100000;

	if (getClockSrc() != src)
	{
		unprotect();
		reset();

		unprotect();
		if(src == define::rtc::clockSrc::LSE)
			enableClock(src, lseDrive);
		setClockSrc(src);
		protect();
	}

#if defined(STM32F7) || defined(STM32F4)
	if ((RCC->BDCR & RCC_BDCR_RTCEN_Msk) == 0)
	{
		RCC->BDCR |= RCC_BDCR_RTCEN_Msk;
#elif defined(STM32L0)
	if ((RCC->CSR & RCC_CSR_RTCEN_Msk) == 0)
	{
		unprotect();
		RCC->CSR |= RCC_CSR_RTCEN_Msk;
#endif

		while (!(RTC->ISR & RTC_ISR_INITF_Msk))
		{
			thread::yield();
			if (time::getRunningMsec() >= endTime)
				return false;
		}

		for (apre = 0x7f; apre; apre >>= 1)
		{
			if ((freq & apre) == 0x00)
				break;
		}
		spre = freq / (apre + 1) - 1;

		RTC->CR |= RTC_CR_BYPSHAD_Msk;
		RTC->PRER = spre << RTC_PRER_PREDIV_S_Pos | apre << RTC_PRER_PREDIV_A_Pos;
	}

	protect();

	return true;
}

inline void enableLseClock(void)
{
#if defined(STM32F7) || defined(STM32F4)

	RCC->BDCR |= RCC_BDCR_LSEON_Msk;

	for (unsigned long i = 0; i < 1000000; i++)
	{
		if (RCC->BDCR & RCC_BDCR_LSERDY_Msk)
			break;
		;
	}

#elif defined(STM32L0)

	RCC->CSR |= RCC_CSR_LSEON_Msk;

	for (unsigned long i = 0; i < 1000000; i++)
	{
		if (RCC->CSR & RCC_CSR_LSERDY_Msk)
			break;
		;
	}

#endif
}

inline void enableLsiClock(void)
{
	RCC->CSR |= RCC_CSR_LSION_Msk;

	for (unsigned long i = 0; i < 1000000; i++)
	{
		if (RCC->CSR & RCC_CSR_LSIRDY_Msk)
			break;
		;
	}
}

inline bool enableClock(unsigned char src, unsigned char lseDrive)
{
	switch (src)
	{
	case define::rtc::clockSrc::NO_CLOCK:
		return false;
	case define::rtc::clockSrc::LSE:
#if defined(RCC_BDCR_LSEDRV)
		RCC->BDCR &= ~RCC_BDCR_LSEDRV_Msk;
		RCC->BDCR |= lseDrive << RCC_BDCR_LSEDRV_Pos;
#endif

#if defined(STM32F7) || defined(STM32F4)
		if ((RCC->BDCR & RCC_BDCR_LSERDY_Msk) == 0)
			enableLseClock();
#elif defined(STM32L0)
		if ((RCC->CSR & RCC_CSR_LSERDY_Msk) == 0)
			enableLseClock();
#endif
		break;
	case define::rtc::clockSrc::LSI:
		if ((RCC->CSR & RCC_CSR_LSIRDY_Msk) == 0)
			enableLsiClock();
		break;
	case define::rtc::clockSrc::HSE:
		return false;
	}

	return true;
}

inline void setClockSrc(unsigned char src)
{
#if defined(STM32F7) || defined(STM32F4)
	RCC->BDCR &= ~RCC_BDCR_RTCSEL_Msk;
	RCC->BDCR |= src << RCC_BDCR_RTCSEL_Pos;
#elif defined(STM32L0)
	RCC->CSR &= ~RCC_CSR_RTCSEL_Msk;
	RCC->CSR |= src << RCC_CSR_RTCSEL_Pos;
#endif
}

inline unsigned char getClockSrc(void)
{
#if defined(STM32F7) || defined(STM32F4)
	return (RCC->BDCR & RCC_BDCR_RTCSEL_Msk) >> RCC_BDCR_RTCSEL_Pos;
#elif defined(STM32L0)
	return (RCC->CSR & RCC_CSR_RTCSEL_Msk) >> RCC_CSR_RTCSEL_Pos;
#endif
}

void Rtc::refresh(void)
{
}

unsigned char Rtc::getYear(void)
{
	return ((RTC->DR & RTC_DR_YT_Msk) >> RTC_DR_YT_Pos) * 10 + ((RTC->DR & RTC_DR_YU_Msk) >> RTC_DR_YU_Pos);
}

bool Rtc::setYear(unsigned char year)
{
	unsigned long dr = RTC->DR;
	unsigned long long endTime = time::getRunningMsec() + 1000;

	unprotect();
	while (!(RTC->ISR & RTC_ISR_INITF_Msk))
	{
		thread::yield();
		if (time::getRunningMsec() >= endTime)
			return false;
	}

	dr &= ~(RTC_DR_YT_Msk | RTC_DR_YU_Msk);
	dr |= ((year / 10 % 10) << RTC_DR_YT_Pos) | ((year % 10) << RTC_DR_YU_Pos);
	RTC->DR = dr;

	protect();
	return true;
}

unsigned char Rtc::getMonth(void)
{
	return ((RTC->DR & RTC_DR_MT_Msk) >> RTC_DR_MT_Pos) * 10 + ((RTC->DR & RTC_DR_MU_Msk) >> RTC_DR_MU_Pos);
}

bool Rtc::setMonth(unsigned char month)
{
	unsigned long dr = RTC->DR;
	unsigned long long endTime = time::getRunningMsec() + 1000;

	unprotect();
	while (!(RTC->ISR & RTC_ISR_INITF_Msk))
	{
		thread::yield();
		if (time::getRunningMsec() >= endTime)
			return false;
	}

	dr &= ~(RTC_DR_MT_Msk | RTC_DR_MU_Msk);
	dr |= ((month / 10 % 10) << RTC_DR_MT_Pos) | ((month % 10) << RTC_DR_MU_Pos);
	RTC->DR = dr;

	protect();
	return true;
}

unsigned char Rtc::getDay(void)
{
	return ((RTC->DR & RTC_DR_DT_Msk) >> RTC_DR_DT_Pos) * 10 + ((RTC->DR & RTC_DR_DU_Msk) >> RTC_DR_DU_Pos);
}

bool Rtc::setDay(unsigned char day)
{
	unsigned long dr = RTC->DR;
	unsigned long long endTime = time::getRunningMsec() + 1000;

	unprotect();
	while (!(RTC->ISR & RTC_ISR_INITF_Msk))
	{
		thread::yield();
		if (time::getRunningMsec() >= endTime)
			return false;
	}

	dr &= ~(RTC_DR_DT_Msk | RTC_DR_DU_Msk);
	dr |= ((day / 10 % 10) << RTC_DR_DT_Pos) | ((day % 10) << RTC_DR_DU_Pos);
	RTC->DR = dr;

	protect();
	return true;
}

unsigned char Rtc::getWeekDay(void)
{
	return (RTC->DR & RTC_DR_WDU_Msk) >> RTC_DR_WDU_Pos;
}

bool Rtc::setWeekDay(unsigned char weekDay)
{
	unsigned long dr = RTC->DR;
	unsigned long long endTime = time::getRunningMsec() + 1000;

	unprotect();
	while (!(RTC->ISR & RTC_ISR_INITF_Msk))
	{
		thread::yield();
		if (time::getRunningMsec() >= endTime)
			return false;
	}

	dr &= ~RTC_DR_WDU_Msk;
	dr |= weekDay << RTC_DR_WDU_Pos;
	RTC->DR = dr;

	protect();
	return true;
}

unsigned char Rtc::getHour(void)
{
	return ((RTC->TR & RTC_TR_HT_Msk) >> RTC_TR_HT_Pos) * 10 + ((RTC->TR & RTC_TR_HU_Msk) >> RTC_TR_HU_Pos);
}

bool Rtc::setHour(unsigned char hour)
{
	unsigned long tr = RTC->TR;
	unsigned long long endTime = time::getRunningMsec() + 1000;

	unprotect();
	while (!(RTC->ISR & RTC_ISR_INITF_Msk))
	{
		thread::yield();
		if (time::getRunningMsec() >= endTime)
			return false;
	}

	tr &= ~(RTC_TR_HT_Msk | RTC_TR_HU_Msk);
	tr |= ((hour / 10 % 10) << RTC_TR_HT_Pos) | ((hour % 10) << RTC_TR_HU_Pos);
	RTC->TR = tr;

	protect();
	return true;
}

unsigned char Rtc::getMin(void)
{
	return ((RTC->TR & RTC_TR_MNT_Msk) >> RTC_TR_MNT_Pos) * 10 + ((RTC->TR & RTC_TR_MNU_Msk) >> RTC_TR_MNU_Pos);
}

bool Rtc::setMin(unsigned char min)
{
	unsigned long tr = RTC->TR;
	unsigned long long endTime = time::getRunningMsec() + 1000;

	unprotect();
	while (!(RTC->ISR & RTC_ISR_INITF_Msk))
	{
		thread::yield();
		if (time::getRunningMsec() >= endTime)
			return false;
	}

	tr &= ~(RTC_TR_MNT_Msk | RTC_TR_MNU_Msk);
	tr |= ((min / 10 % 10) << RTC_TR_MNT_Pos) | ((min % 10) << RTC_TR_MNU_Pos);
	RTC->TR = tr;

	protect();
	return true;
}

unsigned char Rtc::getSec(void)
{
	return ((RTC->TR & RTC_TR_ST_Msk) >> RTC_TR_ST_Pos) * 10 + ((RTC->TR & RTC_TR_SU_Msk) >> RTC_TR_SU_Pos);
}

bool Rtc::setSec(unsigned char sec)
{
	unsigned long tr = RTC->TR;
	unsigned long long endTime = time::getRunningMsec() + 1000;

	unprotect();
	while (!(RTC->ISR & RTC_ISR_INITF_Msk))
	{
		thread::yield();
		if (time::getRunningMsec() >= endTime)
			return false;
	}

	tr &= ~(RTC_TR_ST_Msk | RTC_TR_SU_Msk);
	tr |= ((sec / 10 % 10) << RTC_TR_ST_Pos) | ((sec % 10) << RTC_TR_SU_Pos);
	RTC->TR = tr;

	protect();
	return true;
}

unsigned short Rtc::getSubsec(void)
{
	unsigned long prer = RTC->PRER & 0x7fff;
	unsigned long sub = (prer - RTC->SSR) * 100;
	sub /= prer;
	return (unsigned short)sub;
}

void Rtc::protect(void)
{
	RTC->ISR &= ~RTC_ISR_INIT_Msk;
	while (RTC->ISR & RTC_ISR_INITF_Msk)
		thread::yield();
	RTC->WPR = 0X00;

#if defined(STM32F7)
	PWR->CR1 &= ~PWR_CR1_DBP_Msk;
#elif defined(STM32L0) || defined(STM32F4)
	PWR->CR &= ~PWR_CR_DBP_Msk;
#endif
}

void Rtc::unprotect(void)
{
#if defined(STM32F7)
	PWR->CR1 |= PWR_CR1_DBP_Msk;
#elif defined(STM32L0) || defined(STM32F4)
	PWR->CR |= PWR_CR_DBP_Msk;
#endif
	RTC->WPR = 0xca;
	RTC->WPR = 0x53;
	RTC->ISR |= RTC_ISR_INIT_Msk;
}
}

#endif
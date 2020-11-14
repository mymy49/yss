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

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <__cross_studio_io.h>

#include <yss/thread.h>
#include <util/time.h>

#include <drv/peripherals.h>
#include <drv/rtc/drv_st_rtc_type_A_register.h>

#if defined(RTC_ENABLE) && defined(RTC)
static void reset(void)
{
	PWR->CR |= PWR_CR_DBP_Msk;
	RCC->BDCR |= RCC_BDCR_BDRST_Msk;
	__NOP();
	__NOP();
	RCC->BDCR &= ~RCC_BDCR_BDRST_Msk;
	PWR->CR &= ~PWR_CR_DBP_Msk;
}

drv::Rtc rtc(RTC, 0, 0, reset);
#endif

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
		unsigned long long endTime = time::getRunningMsec() + 1000;

		unprotect();

		enableClock(src, lseDrive);

		if(getClockSrc() != src)
		{
			reset();
			unprotect();
		}

		if((RCC->BDCR & RCC_BDCR_RTCEN_Msk) == 0)
		{
			RCC->BDCR |= RCC_BDCR_RTCEN_Msk;

			setClockSrc(src);

			while(!(RTC->ISR & RTC_ISR_INITF_Msk))
			{
				thread::yield();
				if(time::getRunningMsec() >= endTime)
					return false;
			}

			for(apre = 0x7f;apre;apre >>= 1)
			{
				if((freq & apre) == 0x00)
					break;
			}
			spre = freq / (apre + 1) - 1;
	
			RTC->CR |= RTC_CR_BYPSHAD_Msk;
			RTC->PRER = spre << RTC_PRER_PREDIV_S_Pos | apre << RTC_PRER_PREDIV_A_Pos;
		}
	
		protect();

		return true;
	}

	inline void	enableLseClock(void)
	{
		RCC->BDCR |= RCC_BDCR_LSEON_Msk;

		for(unsigned long i=0;i<1000000;i++)
		{
			if(RCC->BDCR & RCC_BDCR_LSERDY_Msk)
				break;;
		}
	}

	inline void	enableLsiClock(void)
	{
		RCC->CSR |= RCC_CSR_LSION_Msk;

		for(unsigned long i=0;i<1000000;i++)
		{
			if(RCC->CSR & RCC_CSR_LSIRDY_Msk)
				break;;
		}
	}

	inline bool enableClock(unsigned char src, unsigned char lseDrive)
	{
		switch(src)
		{
		case define::rtc::clockSrc::NO_CLOCK :
			return false;
		case define::rtc::clockSrc::LSE	: 
#if defined(RCC_BDCR_LSEDRV)
			RCC->BDCR &= ~RCC_BDCR_LSEDRV_Msk;
			RCC->BDCR |= lseDrive << RCC_BDCR_LSEDRV_Pos;
#endif
			if((RCC->BDCR & RCC_BDCR_LSERDY_Msk) == 0)
				enableLseClock();
			break;
		case define::rtc::clockSrc::LSI	:
			if((RCC->CSR & RCC_CSR_LSIRDY_Msk) == 0)
				enableLsiClock();
			break;
		case define::rtc::clockSrc::HSE	: 
			return false;
		}

		return true;
	}

	inline void setClockSrc(unsigned char src)
	{
		RCC->BDCR &= ~RCC_BDCR_RTCSEL_Msk;
		RCC->BDCR |= src << RCC_BDCR_RTCSEL_Pos;
	}

	inline unsigned char getClockSrc(void)
	{
		return (RCC->BDCR & RCC_BDCR_RTCSEL_Msk) >> RCC_BDCR_RTCSEL_Pos;
	}

	void Rtc::refresh(void)
	{
	
	}

	unsigned char Rtc::getYear(void)
	{
		return ((RTC->DR & RTC_DR_YT_Msk) >> RTC_DR_YT_Pos) * 10 + ((RTC->DR & RTC_DR_YU_Msk) >> RTC_DR_YU_Pos);
	}

	bool Rtc::setYear(unsigned	char year)
	{
		unsigned long dr = RTC->DR;
		unsigned long long endTime = time::getRunningMsec() + 1000;

		unprotect();
		while(!(RTC->ISR & RTC_ISR_INITF_Msk))
		{
			thread::yield();
			if(time::getRunningMsec() >= endTime)
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
		while(!(RTC->ISR & RTC_ISR_INITF_Msk))
		{
			thread::yield();
			if(time::getRunningMsec() >= endTime)
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

	bool Rtc::setDay(unsigned char	day)
	{
		unsigned long dr = RTC->DR;
		unsigned long long endTime = time::getRunningMsec() + 1000;

		unprotect();
		while(!(RTC->ISR & RTC_ISR_INITF_Msk))
		{
			thread::yield();
			if(time::getRunningMsec() >= endTime)
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

	bool Rtc::setWeekDay(unsigned char	weekDay)
	{
		unsigned long dr = RTC->DR;
		unsigned long long endTime = time::getRunningMsec() + 1000;

		unprotect();
		while(!(RTC->ISR & RTC_ISR_INITF_Msk))
		{
			thread::yield();
			if(time::getRunningMsec() >= endTime)
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

	bool Rtc::setHour(unsigned	char hour)
	{
		unsigned long tr = RTC->TR;
		unsigned long long endTime = time::getRunningMsec() + 1000;

		unprotect();
		while(!(RTC->ISR & RTC_ISR_INITF_Msk))
		{
			thread::yield();
			if(time::getRunningMsec() >= endTime)
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

	bool Rtc::setMin(unsigned char	min)
	{
		unsigned long tr = RTC->TR;
		unsigned long long endTime = time::getRunningMsec() + 1000;

		unprotect();
		while(!(RTC->ISR & RTC_ISR_INITF_Msk))
		{
			thread::yield();
			if(time::getRunningMsec() >= endTime)
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

	bool Rtc::setSec(unsigned char	sec)
	{
		unsigned long tr = RTC->TR;
		unsigned long long endTime = time::getRunningMsec() + 1000;

		unprotect();
		while(!(RTC->ISR & RTC_ISR_INITF_Msk))
		{
			thread::yield();
			if(time::getRunningMsec() >= endTime)
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
		unsigned long sub =	(prer-RTC->SSR)	* 100;
		sub	/= prer;
		return (unsigned short)sub;
	}

	void Rtc::protect(void)
	{
		RTC->ISR &= ~RTC_ISR_INIT_Msk;
		RTC->WPR = 0X00;
		PWR->CR &= ~PWR_CR_DBP_Msk;
	}

	void Rtc::unprotect(void)
	{
		PWR->CR |= PWR_CR_DBP_Msk;
		RTC->WPR = 0xca;
		RTC->WPR = 0x53;
		RTC->ISR |= RTC_ISR_INIT_Msk;
	}
}

#endif

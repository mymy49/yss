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
/*
#if defined(STM32F1)

#include <util/ElapsedTime.h>
#include <yss/thread.h>
#include <cmsis/mcu/common/rcc_stm32_gd32f1.h>

#include <drv/Rtc.h>

Rtc::Rtc(RTC_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
	mPeri = peri;
}

uint32_t Rtc::getCounter(void)
{
	return ((uint32_t)mPeri->CNTH << 16 & 0xFFFF0000) | ((uint32_t)mPeri->CNTL & 0xFFFF);
}

bool Rtc::setCounter(uint32_t cnt)
{
	PWR->CR |= PWR_CR_DBP;
	while (~mPeri->CRL & RTC_CRL_RTOFF)
		thread::yield();

	mPeri->CRL |= RTC_CRL_CNF;

	while (~mPeri->CRL & RTC_CRL_RTOFF)
		thread::yield();
	mPeri->CNTL = cnt & 0xFFFF;

	while (~mPeri->CRL & RTC_CRL_RTOFF)
		thread::yield();
	mPeri->CNTH = (cnt >> 16) & 0xFFFF;

	while (~mPeri->CRL & RTC_CRL_RTOFF)
		thread::yield();

	mPeri->CRL &= ~RTC_CRL_CNF;

	while (~mPeri->CRL & RTC_CRL_RTOFF)
		thread::yield();

	PWR->CR &= ~PWR_CR_DBP;

	return true;
}

inline bool enableClock(uint8_t src);

bool Rtc::init(uint8_t src, uint32_t freq, uint8_t lseDrive)
{
	int32_t apre = 0x7f, spre;
	uint32_t reg;
	ElapsedTime timelapse;

	if (src != (RCC->BDCR & RCC_BDCR_RTCSEL) >> 8)
	{
		PWR->CR |= PWR_CR_DBP;
		RCC->BDCR |= RCC_BDCR_BDRST;
		RCC->BDCR &= ~RCC_BDCR_BDRST;

		enableClock(src);

		reg = RCC->BDCR;
		reg &= ~RCC_BDCR_RTCSEL;
		reg |= (src << 8 & RCC_BDCR_RTCSEL) | RCC_BDCR_RTCEN;
		RCC->BDCR = reg;

		mPeri->CRL |= RTC_CRL_CNF;

		freq--;
		while (~mPeri->CRL & RTC_CRL_RTOFF)
			thread::yield();
		mPeri->PRLH = (freq >> 16) & 0x0F;
		while (~mPeri->CRL & RTC_CRL_RTOFF)
			thread::yield();
		mPeri->PRLL = freq & 0xFFFF;

		mPeri->CRL &= ~RTC_CRL_CNF;

		PWR->CR &= ~PWR_CR_DBP;
	}

	return false;
}

void Rtc::refresh(void)
{
}

void Rtc::unprotect(void)
{
}

inline void enableLsiClock(void)
{
	RCC->CSR |= RCC_CSR_LSION;

	for (uint32_t i = 0; i < 1000000; i++)
	{
		if (RCC->CSR & RCC_CSR_LSIRDY)
			break;
		;
	}
}

inline void enableLseClock(void)
{
	ElapsedTime timelapse;
	RCC->BDCR |= RCC_BDCR_LSEON;

	while (1)
	{
		if (RCC->BDCR & RCC_BDCR_LSERDY)
			return;
		if (timelapse.getMsec() > 3000)
			return;
	}
}

inline bool enableClock(uint8_t src)
{
	switch (src)
	{
	case define::rtc::clockSrc::NO_CLOCK:
		return false;
	case define::rtc::clockSrc::LSE:
		if (~RCC->BDCR & RCC_BDCR_LSERDY)
			enableLseClock();
		break;
	case define::rtc::clockSrc::LSI:
		if ((RCC->CSR & RCC_CSR_LSIRDY) == 0)
			enableLsiClock();
		break;
	case define::rtc::clockSrc::HSE:
		return false;
	}

	return true;
}

#endif

*/
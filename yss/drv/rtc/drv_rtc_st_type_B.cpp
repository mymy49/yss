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

#if defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)

#include <__cross_studio_io.h>

#include <util/TimeLapse.h>
#include <yss/thread.h>

#include <drv/peripherals.h>
#include <drv/rtc/drv_st_rtc_type_A_register.h>

static void reset(void)
{
    PWR->CR |= PWR_CR_DBP_Msk;
    RCC->BDCR |= RCC_BDCR_BDRST_Msk;
    RCC->BDCR &= ~RCC_BDCR_BDRST_Msk;
    PWR->CR &= ~PWR_CR_DBP_Msk;
}

drv::Rtc rtc(RTC, 0, 0, reset);

namespace drv
{
Rtc::Rtc(RTC_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
    mPeri = peri;
}

unsigned int Rtc::getCounter(void)
{
    return ((unsigned int)mPeri->CNTH << 16 & 0xFFFF0000) | ((unsigned int)mPeri->CNTL & 0xFFFF);
}

bool Rtc::setCounter(unsigned int cnt)
{
    PWR->CR |= PWR_CR_DBP_Msk;
    while (~mPeri->CRL & RTC_CRL_RTOFF_Msk)
        thread::yield();

    mPeri->CRL |= RTC_CRL_CNF_Msk;

    while (~mPeri->CRL & RTC_CRL_RTOFF_Msk)
        thread::yield();
    mPeri->CNTL = cnt & 0xFFFF;

    while (~mPeri->CRL & RTC_CRL_RTOFF_Msk)
        thread::yield();
    mPeri->CNTH = (cnt >> 16) & 0xFFFF;

    while (~mPeri->CRL & RTC_CRL_RTOFF_Msk)
        thread::yield();

    mPeri->CRL &= ~RTC_CRL_CNF_Msk;

    while (~mPeri->CRL & RTC_CRL_RTOFF_Msk)
        thread::yield();

    PWR->CR &= ~PWR_CR_DBP_Msk;

    return true;
}

inline bool enableClock(unsigned char src);

bool Rtc::init(unsigned char src, unsigned int freq)
{
    signed int apre = 0x7f, spre;
    unsigned int reg;
    TimeLapse timelapse;

    if (src != (RCC->BDCR & RCC_BDCR_RTCSEL_Msk) >> RCC_BDCR_RTCSEL_Pos)
    {
        PWR->CR |= PWR_CR_DBP_Msk;
        RCC->BDCR |= RCC_BDCR_BDRST_Msk;
        RCC->BDCR &= ~RCC_BDCR_BDRST_Msk;

        enableClock(src);

        reg = RCC->BDCR;
        reg &= ~RCC_BDCR_RTCSEL_Msk;
        reg |= (src << RCC_BDCR_RTCSEL_Pos & RCC_BDCR_RTCSEL_Msk) | RCC_BDCR_RTCEN_Msk;
        RCC->BDCR = reg;

        mPeri->CRL |= RTC_CRL_CNF_Msk;

        freq--;
        while (~mPeri->CRL & RTC_CRL_RTOFF_Msk)
            thread::yield();
        mPeri->PRLH = (freq >> 16) & 0x0F;
        while (~mPeri->CRL & RTC_CRL_RTOFF_Msk)
            thread::yield();
        mPeri->PRLL = freq & 0xFFFF;

        mPeri->CRL &= ~RTC_CRL_CNF_Msk;

        PWR->CR &= ~PWR_CR_DBP_Msk;
    }
    //    unprotect();

    return false;
}

void Rtc::refresh(void)
{
}

void Rtc::unprotect(void)
{
    //PWR->CR |= PWR_CR_DBP_Msk;
    //RTC->WPR = 0xca;
    //RTC->WPR = 0x53;
    //RTC->ISR |= RTC_ISR_INIT_Msk;
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

inline void enableLseClock(void)
{
    TimeLapse timelapse;
    RCC->BDCR |= RCC_BDCR_LSEON_Msk;

    while (1)
    {
        if (RCC->BDCR & RCC_BDCR_LSERDY_Msk)
            return;
        if (timelapse.getMsec() > 3000)
            return;
    }
}

inline bool enableClock(unsigned char src)
{
    switch (src)
    {
    case define::rtc::clockSrc::NO_CLOCK:
        return false;
    case define::rtc::clockSrc::LSE:
        if (~RCC->BDCR & RCC_BDCR_LSERDY_Msk)
            enableLseClock();
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
}

#endif
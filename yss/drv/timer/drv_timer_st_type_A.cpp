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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) ||                                                 \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                                                                 \
    defined(STM32F429xx) || defined(STM32F439xx) ||                                                                                                 \
    defined(STM32F100xB) || defined(STM32F100xE) ||                                                                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) ||                                                 \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) ||                                                 \
    defined(STM32F105xC) ||                                                                                                                         \
    defined(STM32F107xC) ||                                                                                                                         \
    defined(STM32G431xx) || defined(STM32G441xx) ||                                                                                                 \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB) || \
    defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) ||                                                 \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                                                                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                                                                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                                                                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx) ||                                                                         \
    defined(STM32L412xx) || defined(STM32L422xx) ||                                                                                                 \
    defined(STM32L431xx) || defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || defined(STM32L443xx) ||                         \
    defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) ||                                                                         \
    defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) ||                         \
    defined(STM32L496xx) || defined(STM32L4A6xx) ||                                                                                                 \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx) ||                                                                                                 \
    defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <drv/timer/drv_st_timer_type_A_register.h>
#include <instance/instance_clock.h>
#include <instance/instance_nvic.h>

namespace drv
{
Timer::Timer(TIM_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
    mPeri = peri;
    mGetClockFreq = getClockFreq;
    mIsrUpdate = 0;
    mTimeUpdateCnt = 0;
    mIsrInputCapture1 = 0;
    mIsrInputCapture2 = 0;
    mIsrInputCapture3 = 0;
    mIsrInputCapture4 = 0;
}

void Timer::initSystemTime(void)
{
    mPeri->PSC = (unsigned short)(getClockFreq() / 1000000) - 1;
    mPeri->ARR = 60000;
    mPeri->CNT = 60000;
    mPeri->DIER |= TIM_DIER_UIE_Msk;
}

void Timer::init(unsigned int psc, unsigned int arr)
{
    mPeri->PSC = (unsigned short)psc;
    mPeri->ARR = (unsigned short)arr;
}

void Timer::init(unsigned int freq)
{
    unsigned int psc, arr, clk = getClockFreq();

    arr = clk / freq;
    psc = arr / (0xffff + 1);
    arr /= psc + 1;

    mPeri->PSC = psc;
    mPeri->ARR = arr;
}

void Timer::setUpdateIntEn(bool en)
{
    if (en)
        mPeri->DIER |= TIM_DIER_UIE_Msk;
    else
        mPeri->DIER &= ~TIM_DIER_UIE_Msk;
}

void Timer::setCC1IntEn(bool en)
{
    if (en)
        mPeri->DIER |= TIM_DIER_CC1IE_Msk;
    else
        mPeri->DIER &= ~TIM_DIER_CC1IE_Msk;
}

void Timer::setCC2IntEn(bool en)
{
    if (en)
        mPeri->DIER |= TIM_DIER_CC2IE_Msk;
    else
        mPeri->DIER &= ~TIM_DIER_CC2IE_Msk;
}

void Timer::setCC3IntEn(bool en)
{
    if (en)
        mPeri->DIER |= TIM_DIER_CC3IE_Msk;
    else
        mPeri->DIER &= ~TIM_DIER_CC3IE_Msk;
}

void Timer::setCC4IntEn(bool en)
{
    if (en)
        mPeri->DIER |= TIM_DIER_CC4IE_Msk;
    else
        mPeri->DIER &= ~TIM_DIER_CC4IE_Msk;
}

void Timer::start(void)
{
    mPeri->CR1 |= TIM_CR1_CEN_Msk;
}

void Timer::stop(void)
{
    mPeri->CR1 &= ~TIM_CR1_CEN_Msk;
}

void Timer::setOnePulse(bool en)
{
    if (en)
        mPeri->CR1 |= TIM_CR1_OPM_Msk;
    else
        mPeri->CR1 &= ~TIM_CR1_OPM_Msk;
}

void Timer::initInputCaptureCh1(unsigned char option)
{
    mPeri->CCMR1 = (1 << TIM_CCMR1_CC1S_Pos) | (2 << TIM_CCMR1_IC1F_Pos);

    if (option & define::timer::inputCapture::RISING_EDGE)
        mPeri->CCER &= TIM_CCER_CC1P_Msk;
    else
        mPeri->CCER |= TIM_CCER_CC1P_Msk;

    mPeri->CCER |= TIM_CCER_CC1E_Msk;
}

void Timer::initInputCaptureCh2(unsigned char option)
{
    mPeri->CCMR1 = (1 << TIM_CCMR1_CC2S_Pos) | (2 << TIM_CCMR1_IC2F_Pos);

    if (option & define::timer::inputCapture::RISING_EDGE)
        mPeri->CCER &= TIM_CCER_CC2P_Msk;
    else
        mPeri->CCER |= TIM_CCER_CC2P_Msk;

    mPeri->CCER |= TIM_CCER_CC2E_Msk;
}

void Timer::initInputCaptureCh3(unsigned char option)
{
    mPeri->CCMR2 = (1 << TIM_CCMR2_CC3S_Pos) | (2 << TIM_CCMR2_IC3F_Pos);

    if (option & define::timer::inputCapture::RISING_EDGE)
        mPeri->CCER &= TIM_CCER_CC3P_Msk;
    else
        mPeri->CCER |= TIM_CCER_CC3P_Msk;

    mPeri->CCER |= TIM_CCER_CC3E_Msk;
}

void Timer::initInputCaptureCh4(unsigned char option)
{
    mPeri->CCMR2 = (1 << TIM_CCMR2_CC4S_Pos) | (2 << TIM_CCMR2_IC4F_Pos);

    if (option & define::timer::inputCapture::RISING_EDGE)
        mPeri->CCER &= TIM_CCER_CC4P_Msk;
    else
        mPeri->CCER |= TIM_CCER_CC4P_Msk;

    mPeri->CCER |= TIM_CCER_CC4E_Msk;
}

void Timer::initPwmCh1(bool risingAtMatch)
{
#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx) ||                         \
    defined(STM32L412xx) || defined(STM32L422xx) ||                                                                                                 \
    defined(STM32L431xx) || defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || defined(STM32L443xx) ||                         \
    defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) ||                                                                         \
    defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) ||                         \
    defined(STM32L496xx) || defined(STM32L4A6xx) ||                                                                                                 \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx) ||                                                                                                 \
    defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#else
    setTimMainOutputEn(mPeri, true);
#endif
    setTimCc1s(mPeri, 0);
    setTimOc1pe(mPeri, 0);
    setTimOc1fe(mPeri, 1);
    setTimCc1e(mPeri, 1);
    if (risingAtMatch)
        setTimOc1m(mPeri, 6);
    else
        setTimOc1m(mPeri, 7);
}

void Timer::initPwmCh2(bool risingAtMatch)
{
#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
#else
    setTimMainOutputEn(mPeri, true);
#endif
    setTimCc2s(mPeri, 0);
    setTimOc2pe(mPeri, 0);
    setTimOc2fe(mPeri, 1);
    setTimCc2e(mPeri, 1);
    if (risingAtMatch)
        setTimOc2m(mPeri, 6);
    else
        setTimOc2m(mPeri, 7);
}

void Timer::initPwmCh3(bool risingAtMatch)
{
#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
#else
    setTimMainOutputEn(mPeri, true);
#endif
    setTimCc3s(mPeri, 0);
    setTimOc3pe(mPeri, 0);
    setTimOc3fe(mPeri, 1);
    setTimCc3e(mPeri, 1);
    if (risingAtMatch)
        setTimOc3m(mPeri, 6);
    else
        setTimOc3m(mPeri, 7);
}

void Timer::initPwmCh4(bool risingAtMatch)
{
#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
#else
    setTimMainOutputEn(mPeri, true);
#endif
    setTimCc4s(mPeri, 0);
    setTimOc4pe(mPeri, 0);
    setTimOc4fe(mPeri, 1);
    setTimCc4e(mPeri, 1);
    if (risingAtMatch)
        setTimOc4m(mPeri, 6);
    else
        setTimOc4m(mPeri, 7);
}

void Timer::setPwmCh1(float ratio)
{
    mPeri->CCR1 = (unsigned short)((float)mPeri->ARR * ratio);
}

void Timer::setPwmCh2(float ratio)
{
    mPeri->CCR2 = (unsigned short)((float)mPeri->ARR * ratio);
}

void Timer::setPwmCh3(float ratio)
{
    mPeri->CCR3 = (unsigned short)((float)mPeri->ARR * ratio);
}

void Timer::setPwmCh4(float ratio)
{
    mPeri->CCR4 = (unsigned short)((float)mPeri->ARR * ratio);
}

unsigned int Timer::getCounterValue(void)
{
    return getTimCnt(mPeri);
}

unsigned int Timer::getOverFlowCount(void)
{
    return 60000;
}

unsigned int drv::Timer::getClockFreq(void)
{
    return mGetClockFreq();
}

void drv::Timer::setUpdateIsr(void (*isr)(void))
{
    mIsrUpdate = isr;
}

void drv::Timer::setInputCapture1Isr(void (*isr)(unsigned int cnt, unsigned long long acc))
{
    mIsrInputCapture1 = isr;
}

void drv::Timer::setInputCapture2Isr(void (*isr)(unsigned int cnt, unsigned long long acc))
{
    mIsrInputCapture2 = isr;
}

void drv::Timer::setInputCapture3Isr(void (*isr)(unsigned int cnt, unsigned long long acc))
{
    mIsrInputCapture3 = isr;
}

void drv::Timer::setInputCapture4Isr(void (*isr)(unsigned int cnt, unsigned long long acc))
{
    mIsrInputCapture4 = isr;
}

void drv::Timer::isrCC1(bool event)
{
    signed int cnt, ccr = (signed int)mPeri->CCR1;
    unsigned long long accCnt;

    cnt = (signed int)(mTimeUpdateCnt - mLastUpdateCnt1);

    if (event)
    {
        if ((unsigned int)ccr > (unsigned int)mLastCcr1)
        {
            mLastUpdateCnt1 = mTimeUpdateCnt - 1;
            cnt--;
        }
        else
            mLastUpdateCnt1 = mTimeUpdateCnt;
    }
    else
        mLastUpdateCnt1 = mTimeUpdateCnt;

    cnt = cnt * 65536;
    cnt += ccr - mLastCcr1;
    mLastCcr1 = ccr;

    accCnt = mLastUpdateCnt1 * 65536 + ccr;

    if (mIsrInputCapture1)
        mIsrInputCapture1(cnt, accCnt);
}

void drv::Timer::isrCC2(bool event)
{
    signed int cnt, ccr = (signed int)mPeri->CCR2;
    unsigned long long accCnt;

    cnt = (signed int)(mTimeUpdateCnt - mLastUpdateCnt2);

    if (event)
    {
        if ((unsigned int)ccr > (unsigned int)mLastCcr2)
        {
            mLastUpdateCnt2 = mTimeUpdateCnt - 1;
            cnt--;
        }
        else
            mLastUpdateCnt2 = mTimeUpdateCnt;
    }
    else
        mLastUpdateCnt2 = mTimeUpdateCnt;

    cnt = cnt * 65536;
    cnt += ccr - mLastCcr2;
    mLastCcr2 = ccr;

    accCnt = mLastUpdateCnt2 * 65536 + ccr;

    if (mIsrInputCapture2)
        mIsrInputCapture2(cnt, accCnt);
}

void drv::Timer::isrCC3(bool event)
{
    signed int cnt, ccr = (signed int)mPeri->CCR3;

    cnt = (signed int)(mTimeUpdateCnt - mLastUpdateCnt3);

    if (event)
    {
        if ((unsigned int)ccr > (unsigned int)mLastCcr3)
        {
            mLastUpdateCnt3 = mTimeUpdateCnt - 1;
            cnt--;
        }
        else
            mLastUpdateCnt3 = mTimeUpdateCnt;
    }
    else
        mLastUpdateCnt3 = mTimeUpdateCnt;

    cnt = cnt * 65536;
    cnt += ccr - mLastCcr3;

    mLastCcr3 = ccr;

    if (mIsrInputCapture3)
        mIsrInputCapture3(cnt, 0);
}

void drv::Timer::isrCC4(bool event)
{
    signed int cnt, ccr = (signed int)mPeri->CCR4;

    cnt = (signed int)(mTimeUpdateCnt - mLastUpdateCnt4);

    if (event)
    {
        if ((unsigned int)ccr > (unsigned int)mLastCcr4)
        {
            mLastUpdateCnt4 = mTimeUpdateCnt - 1;
            cnt--;
        }
        else
            mLastUpdateCnt4 = mTimeUpdateCnt;
    }
    else
        mLastUpdateCnt4 = mTimeUpdateCnt;

    cnt = cnt * 65536;
    cnt += ccr - mLastCcr4;

    mLastCcr4 = ccr;

    if (mIsrInputCapture4)
        mIsrInputCapture4(cnt, 0);
}

unsigned long long drv::Timer::getCaptureUpdateCntCh1(void)
{
    unsigned long long buf = mLastUpdateCnt1;
    buf *= 65536;
    buf += mLastCcr1;
    return buf;
}

unsigned long long drv::Timer::getCaptureUpdateCntCh2(void)
{
    unsigned long long buf = mLastUpdateCnt2;
    buf *= 65536;
    buf += mLastCcr2;
    return buf;
}

unsigned long long drv::Timer::getCaptureUpdateCntCh3(void)
{
    unsigned long long buf = mLastUpdateCnt3;
    buf *= 65536;
    buf += mLastCcr3;
    return buf;
}

unsigned long long drv::Timer::getCaptureUpdateCntCh4(void)
{
    unsigned long long buf = mLastUpdateCnt4;
    buf *= 65536;
    buf += mLastCcr4;
    return buf;
}

void drv::Timer::isrUpdate(void)
{
    if (mIsrUpdate)
        mIsrUpdate();
    mTimeUpdateCnt++;
}

}
#endif
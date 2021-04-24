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

#ifndef YSS_DRV_TIMER_ST_TYPE_A__H_
#define YSS_DRV_TIMER_ST_TYPE_A__H_

#include <yss/mcu.h>

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32L4) || defined(STM32F0)

#include "drv_st_timer_type_A_define.h"
#include <config.h>
#include <yss/mcu.h>
#include <drv/Drv.h>

namespace drv
{
class Timer : public Drv
{
    TIM_TypeDef *mPeri;
    unsigned long long mTimeUpdateCnt, mLastUpdateCnt1, mLastUpdateCnt2, mLastUpdateCnt3, mLastUpdateCnt4;
    unsigned int mLastCcr1, mLastCcr2, mLastCcr3, mLastCcr4;
    unsigned int (*mGetClockFreq)(void);
    void (*mIsrUpdate)(void);
    void (*mIsrInputCapture1)(unsigned int cnt, unsigned long long accCnt);
    void (*mIsrInputCapture2)(unsigned int cnt, unsigned long long accCnt);
    void (*mIsrInputCapture3)(unsigned int cnt, unsigned long long accCnt);
    void (*mIsrInputCapture4)(unsigned int cnt, unsigned long long accCnt);

    void isrInputCapture(void);

  public:
    Timer(TIM_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), unsigned int (*getClockFreq)(void));

    void setUpdateIsr(void (*isr)(void));
    void setInputCapture1Isr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
    void setInputCapture2Isr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
    void setInputCapture3Isr(void (*isr)(unsigned int cnt, unsigned long long accCnt));
    void setInputCapture4Isr(void (*isr)(unsigned int cnt, unsigned long long accCnt));

    void init(unsigned int freq);
    void init(unsigned int psc, unsigned int arr);
    void start(void);
    void stop(void);
    void setOnePulse(bool en);

    void setUpdateIntEn(bool en);
    void setCC1IntEn(bool en);
    void setCC2IntEn(bool en);
    void setCC3IntEn(bool en);
    void setCC4IntEn(bool en);

    void initInputCaptureCh1(unsigned char option = define::timer::inputCapture::RISING_EDGE);
    void initInputCaptureCh2(unsigned char option = define::timer::inputCapture::RISING_EDGE);
    void initInputCaptureCh3(unsigned char option = define::timer::inputCapture::RISING_EDGE);
    void initInputCaptureCh4(unsigned char option = define::timer::inputCapture::RISING_EDGE);

    void initPwmCh1(bool risingAtMatch = true);
    void initPwmCh2(bool risingAtMatch = true);
    void initPwmCh3(bool risingAtMatch = true);
    void initPwmCh4(bool risingAtMatch = true);

    void setPwmCh1(float ratio);
    void setPwmCh2(float ratio);
    void setPwmCh3(float ratio);
    void setPwmCh4(float ratio);

    unsigned long long getCaptureUpdateCntCh1(void);
    unsigned long long getCaptureUpdateCntCh2(void);
    unsigned long long getCaptureUpdateCntCh3(void);
    unsigned long long getCaptureUpdateCntCh4(void);

    void initSystemTime(void);
    unsigned int getClockFreq(void);

    void isrUpdate(void);
    void isrCC1(bool event);
    void isrCC2(bool event);
    void isrCC3(bool event);
    void isrCC4(bool event);

    unsigned int getCounterValue(void);
    unsigned int getOverFlowCount(void);
};
}

#endif

#endif
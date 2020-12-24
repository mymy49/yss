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

#ifndef YSS_DRV_CLOCK_ST_TYPE_C__H_
#define YSS_DRV_CLOCK_ST_TYPE_C__H_

#if defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || \
    defined(STM32L496xx) || defined(STM32L4A6xx)

#include "drv_st_clock_type_F_config.h"
#include "drv_st_clock_type_F_define.h"
#include "drv_st_clock_type_F_ec.h"
#include <config.h>
#include <yss/mcu.h>

namespace drv
{
class Mainpll
{
    int mPClk, mQClk, mRClk;

  public:
    bool enable(unsigned char src, unsigned int vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv);
    unsigned int getFreq(void);
    unsigned int getPClk(void);
    unsigned int getQClk(void);
    unsigned int getRClk(void);
    void setPEn(bool en);
    void setQEn(bool en);
    void setREn(bool en);
};

class Saipll
{
  public:
    bool enable(unsigned int vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv);
    unsigned int getLcdFreq(void);
    unsigned int getSaiFreq(void);
};

class Peripheral
{
  public:
// ################################### AHB2ENR 시작 ########################################
#if defined(GPIOA)
    void setGpioAEn(bool en);
    void resetGpioA(void);
#endif
#if defined(GPIOB)
    void setGpioBEn(bool en);
    void resetGpioB(void);
#endif
#if defined(GPIOC)
    void setGpioCEn(bool en);
    void resetGpioC(void);
#endif
#if defined(GPIOD)
    void setGpioDEn(bool en);
    void resetGpioD(void);
#endif
#if defined(GPIOE)
    void setGpioEEn(bool en);
    void resetGpioE(void);
#endif
#if defined(GPIOF)
    void setGpioFEn(bool en);
    void resetGpioF(void);
#endif
#if defined(GPIOG)
    void setGpioGEn(bool en);
    void resetGpioG(void);
#endif
#if defined(GPIOH)
    void setGpioHEn(bool en);
    void resetGpioH(void);
#endif
#if defined(GPIOI)
    void setGpioIEn(bool en);
    void resetGpioI(void);
#endif
    // ################################### AHB2ENR 끝 ########################################

    // ################################### APB1ENR1 시작 ########################################

#if defined(TIM2)
    void setTimer2En(bool en);
    void resetTimer2(void);
#endif

#if defined(TIM3)
    void setTimer3En(bool en);
    void resetTimer3(void);
#endif

#if defined(TIM4)
    void setTimer4En(bool en);
    void resetTimer4(void);
#endif

#if defined(TIM5)
    void setTimer5En(bool en);
    void resetTimer5(void);
#endif

#if defined(TIM6)
    void setTimer6En(bool en);
    void resetTimer6(void);
#endif

#if defined(TIM7)
    void setTimer7En(bool en);
    void resetTimer7(void);
#endif

    // ################################### APB1ENR1 끝 ########################################

    // ################################### APB2ENR1 시작 ########################################

#if defined(TIM1)
    void setTimer1En(bool en);
    void resetTimer1(void);
#endif

#if defined(TIM8)
    void setTimer8En(bool en);
    void resetTimer8(void);
#endif

#if defined(TIM15)
    void setTimer15En(bool en);
    void resetTimer15(void);
#endif

#if defined(TIM16)
    void setTimer16En(bool en);
    void resetTimer16(void);
#endif

#if defined(TIM17)
    void setTimer17En(bool en);
    void resetTimer17(void);
#endif

    // ################################### APB2ENR1 끝 ########################################

};

class Clock
{
  public:
    bool setVosRange(unsigned char range);
    unsigned char getVosRange(void);
    bool enableHse(unsigned char hseMhz, bool useOsc = false);
    bool enableLsi(bool en = true);
    bool enableLse(bool en = true);
    bool setUsbClkSrc(unsigned char src);
    bool setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2);
    unsigned int getSysClkFreq(void);
    unsigned int getApb1ClkFreq(void);
    unsigned int getApb2ClkFreq(void);
    unsigned int getTimerApb1ClkFreq(void);
    unsigned int getTimerApb2ClkFreq(void);
    Mainpll pll;
    Saipll saipll;
    Peripheral peripheral;
};
}

#if defined(RCC)
extern drv::Clock clock;
#endif

#endif

#endif
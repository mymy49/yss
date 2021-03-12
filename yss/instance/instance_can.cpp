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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.02.11 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <instance/instance_can.h>
#include <instance/instance_clock.h>
#include <instance/instance_nvic.h>

#include <config.h>
#include <yss/yss.h>

//********** can1 구성 설정 및 변수 선언 **********
#if defined(CAN1_ENABLE) && (defined(CAN1) || defined(FDCAN1))

static unsigned int getClockFreq(void)
{
    return clock.getApb1ClkFreq();
}

static void setCan1ClockEn(bool en)
{
    clock.peripheral.setCan1En(en);
}

static void setCan1IntEn(bool en)
{
    nvic.setCan1En(en);
}

static void resetCan1(void)
{
    clock.peripheral.resetCan1();
}

#if defined(YSS_DRV_CAN_ST_TYPE_A__H_)
drv::Can can1(CAN1, setCan1ClockEn, setCan1IntEn, resetCan1, getClockFreq);
#elif defined(YSS_DRV_CAN_ST_TYPE_B__H_)
drv::Can can1(FDCAN1, setCan1ClockEn, setCan1IntEn, resetCan1, getClockFreq);
#endif
extern "C"
{
#if defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)
    void USB_LP_CAN1_RX0_IRQHandler(void)
#elif defined(STM32F405xx) || defined(STM32F415xx) || \
    defined(STM32F407xx) || defined(STM32F417xx) ||   \
    defined(STM32F427xx) || defined(STM32F437xx) ||   \
    defined(STM32F429xx) || defined(STM32F439xx) ||   \
    defined(STM32F746xx) || defined(STM32F745xx) ||   \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx)
    void CAN1_RX0_IRQHandler(void)
#elif defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)
    void FDCAN1_IT0_IRQHandler(void)
#endif
    {
        can1.isr();
    }
}

#endif

//********** can2 구성 설정 및 변수 선언 **********
#if defined(CAN2_ENABLE) && defined(CAN2)

static void setCan2ClockEn(bool en)
{
    clock.peripheral.setCan2En(en);
}

static void setCan2IntEn(bool en)
{
    nvic.setCan2En(en);
}

static void resetCan2(void)
{
    clock.peripheral.resetCan2();
}

drv::Can can2(CAN2, setCan2ClockEn, setCan2IntEn, resetCan2, getClockFreq);

extern "C"
{
    void CAN2_RX0_IRQHandler(void)
    {
        can2.isr();
    }
}
#endif
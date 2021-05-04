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

#include <yss/mcu.h>

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)

#include <__cross_studio_io.h>
#include <drv/exti/drv_st_exti_type_A.h>
#include <drv/exti/drv_st_exti_type_A_register.h>
#include <yss/thread.h>

namespace drv
{
Exti::Exti(void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
{
}

bool Exti::add(drv::Gpio &gpio, unsigned char pin, unsigned char mode, void (*func)(void))
{
    if (pin > 15)
        return false;

    mTriggerFlag[pin] = false;
    mIsr[pin] = func;
    gpio.setExti(pin);

    if (define::exti::mode::RISING & mode)
        setExtiRisingEdgeTrigger(pin, true);
    else
        setExtiRisingEdgeTrigger(pin, false);

    if (define::exti::mode::FALLING & mode)
        setExtiFallingEdgeTrigger(pin, true);
    else
        setExtiFallingEdgeTrigger(pin, false);

    setExtiIntMask(pin, true);

    return true;
}

bool Exti::add(drv::Gpio &gpio, unsigned char pin, unsigned char mode, int trigger)
{
    if (pin > 15)
        return false;

    mTriggerFlag[pin] = true;
    mTriggerNum[pin] = trigger;
    gpio.setExti(pin);

    if (define::exti::mode::RISING & mode)
        setExtiRisingEdgeTrigger(pin, true);
    else
        setExtiRisingEdgeTrigger(pin, false);

    if (define::exti::mode::FALLING & mode)
        setExtiFallingEdgeTrigger(pin, true);
    else
        setExtiFallingEdgeTrigger(pin, false);

    setExtiIntMask(pin, true);

    return true;
}

void Exti::isr(int num)
{
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)
    if (mTriggerFlag[num])
    {
        trigger::run(mTriggerNum[num]);
    }
    else
    {
        mIsr[num]();
    }
#else
    if (mIsr[num])
        mIsr[num]();
#endif
}
}

#endif
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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.04.22 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/mcu.h>

#if defined(STM32F0)

#include <config.h>

#include <instance/instance_clock.h>
#include <instance/instance_flash.h>

void __attribute__((weak)) initSystem(void)
{
    signed int hseFreq = HSE_CLOCK_FREQ, mul = -1, div = -1, freq;
    const int mulTable[9] = {3, 4, 6, 8, 12, 16, 24, 32, 48};
    const int divTable[3] = {1, 2, 3};

    using namespace ec::clock::sysclk;
    for (int i = 2; i <= 16; i++)
    {
        freq = hseFreq * i;

        if (freq == MAX_FREQ / 1000000)
        {
            mul = i;
            div = 0;
            break;
        }
        else if (freq == MAX_FREQ / 1000000 * 2)
        {
            mul = i;
            div = 1;
            break;
        }
        else if (freq == MAX_FREQ / 1000000 * 3)
        {
            mul = i;
            div = 2;
            break;
        }
    }

    clock.peripheral.setPwrEn(true);
    clock.enableHse(HSE_CLOCK_FREQ);

    if (mul >= 2 && div >= 0)
    {
        clock.pll.enable(
            define::clock::pll::src::HSE, // unsigned char src;
            mul,                          // unsigned char mul;
            div                           // unsigned char div;
        );

        clock.setSysclk(
            define::clock::sysclk::src::PLL,       // unsigned char sysclkSrc;
            define::clock::divFactor::ahb::NO_DIV, // unsigned char ahb;
            define::clock::divFactor::apb::NO_DIV, // unsigned char apb1;
            define::clock::divFactor::apb::NO_DIV  // unsigned char apb2;
        );
    }

    flash.setPrefetchEn(true);

#if defined(GPIOA)
    clock.peripheral.setGpioAEn(true);
#endif
#if defined(GPIOB)
    clock.peripheral.setGpioBEn(true);
#endif
#if defined(GPIOC)
    clock.peripheral.setGpioCEn(true);
#endif
#if defined(GPIOD)
    clock.peripheral.setGpioDEn(true);
#endif
#if defined(GPIOE)
    clock.peripheral.setGpioEEn(true);
#endif
#if defined(GPIOF)
    clock.peripheral.setGpioFEn(true);
#endif
#if defined(GPIOH)
    clock.peripheral.setGpioHEn(true);
#endif
}

#endif
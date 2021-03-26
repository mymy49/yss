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

#include <__cross_studio_io.h>

#include <yss/mcu.h>

#if defined(STM32F4)

#include <config.h>
#include <instance/instance_clock.h>
#include <instance/instance_flash.h>

void __attribute__((weak)) initSystem(void)
{
    clock.enableHse(HSE_CLOCK_FREQ);

#if defined(STM32F427xx) || defined(STM32F437xx) || \
    defined(STM32F429xx) || defined(STM32F439xx)

    clock.pll.enable(
        define::clock::pll::src::HSE,   // unsigned char src
        360,                            // unsigned long vcoMhz
        define::clock::pll::pdiv::DIV2, // unsigned char pDiv
        define::clock::pll::qdiv::DIV7, // unsigned char qDiv
        0                               // unsigned char rDiv
    );

    clock.saipll.enable(
        120,                                // unsigned long vcoMhz
        0,                                  // unsigned char pDiv
        define::clock::saipll::qdiv::DIV10, // unsigned char qDiv
        define::clock::saipll::rdiv::DIV4   // unsigned char rDiv
    );
#else
    clock.pll.enable(
        define::clock::pll::src::HSE,   // unsigned char src
        336,                            // unsigned long vcoMhz
        define::clock::pll::pdiv::DIV2, // unsigned char pDiv
        define::clock::pll::qdiv::DIV7, // unsigned char qDiv
        0                               // unsigned char rDiv
    );
#endif

    clock.setSysclk(
        define::clock::sysclk::src::PLL,       // unsigned char sysclkSrc;
        define::clock::divFactor::ahb::NO_DIV, // unsigned char ahb;
        define::clock::divFactor::apb::DIV4,   // unsigned char apb1;
        define::clock::divFactor::apb::DIV2,   // unsigned char apb2;
        33                                     // unsigned char vcc
    );

    flash.setPrefetchEn(true);
    flash.setDCacheEn(true);
    flash.setICacheEn(true);

    clock.peripheral.setGpioAEn(true);
    clock.peripheral.setGpioBEn(true);
    clock.peripheral.setGpioCEn(true);
    clock.peripheral.setGpioDEn(true);
    clock.peripheral.setGpioEEn(true);
    clock.peripheral.setGpioFEn(true);
    clock.peripheral.setGpioGEn(true);
    clock.peripheral.setGpioHEn(true);
    clock.peripheral.setGpioIEn(true);
#if defined(GPIOJ)
    clock.peripheral.setGpioJEn(true);
#endif
#if defined(GPIOK)
    clock.peripheral.setGpioKEn(true);
#endif

    clock.peripheral.setPwrEn(true);
}

#endif
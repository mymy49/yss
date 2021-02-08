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

#if defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)

#include <config.h>

#if YSS_USE_DEFAULT_MSP == true

#include <drv/peripherals.h>
#include <instance/instance_clock.h>

void initSystem(void)
{
    signed int hseFreq = HSE_CLOCK_FREQ, mul = -1, div = -1, freq;
    const int mulTable[9] = {3, 4, 6, 8, 12, 16, 24, 32, 48};
    const int divTable[3] = {1, 2, 3};

	clock.peripheral.setPwrEn(true);

#if defined(HSE_USE_OSCILLATOR)
    clock.enableHse(HSE_CLOCK_FREQ, HSE_USE_OSCILLATOR);
#else
    clock.enableHse(HSE_CLOCK_FREQ);
#endif

    for (int i = 2; i <= 16; i++)
    {
        freq = hseFreq * i;

        if (freq == ec::clock::sysclk::MAX_FREQ / 1000000)
        {
            mul = i;
            div = 0;
            break;
        }
        else if (freq == ec::clock::sysclk::MAX_FREQ / 1000000 * 2)
        {
            mul = i;
            div = 1;
            break;
        }
    }

    if (mul >= 0 && div >= 0)
    {
        clock.pll.enable(
            define::clock::pll::src::HSE, // unsigned char src;
            div,                          // unsigned char xtpre;
            mul                           // unsigned char mul;
        );

        clock.setSysclk(
            define::clock::sysclk::src::PLL,       // unsigned char sysclkSrc;
            define::clock::divFactor::ahb::NO_DIV, // unsigned char ahb;
            define::clock::divFactor::apb::DIV2,   // unsigned char apb1;
            define::clock::divFactor::apb::NO_DIV  // unsigned char apb2;
        );
    }

    flash.setPrefetchEn(true);

    clock.peripheral.setGpioAEn(true);
    clock.peripheral.setGpioBEn(true);
    clock.peripheral.setGpioCEn(true);
    clock.peripheral.setGpioDEn(true);
    clock.peripheral.setAfioEn(true);

    AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE_Msk;
}

#endif

#endif
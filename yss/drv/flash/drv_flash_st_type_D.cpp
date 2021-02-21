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

#if defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

#include <drv/peripherals.h>
#include <instance/instance_clock.h>

namespace drv
{
void Flash::setLatency(unsigned int freq, unsigned char vcc)
{
    unsigned char wait;
    unsigned int ws0, ws1, ws2, ws3, ws4, acr;

    switch (clock.getVoltageScale())
    {
    case define::clock::voltageScale::RANGE2:
        ws0 = 12 * 1000000;
        ws1 = 24 * 1000000;
        ws2 = 26 * 1000000;
        ws3 = 999 * 1000000;
        ws4 = 999 * 1000000;
        break;
    case define::clock::voltageScale::RANGE1_NORMAL:
        ws0 = 30 * 1000000;
        ws1 = 60 * 1000000;
        ws2 = 90 * 1000000;
        ws3 = 120 * 1000000;
        ws4 = 150 * 1000000;
        break;
    case define::clock::voltageScale::RANGE1_BOOST:
        ws0 = 34 * 1000000;
        ws1 = 68 * 1000000;
        ws2 = 102 * 1000000;
        ws3 = 136 * 1000000;
        ws4 = 170 * 1000000;
        break;
    }

    if (freq <= ws0)
    {
        wait = 0;
    }
    else if (freq <= ws1)
    {
        wait = 1;
    }
    else if (freq <= ws2)
    {
        wait = 2;
    }
    else if (freq <= ws3)
    {
        wait = 3;
    }
    else if (freq <= ws4)
    {
        wait = 4;
    }

    acr = FLASH->ACR;
    acr &= ~FLASH_ACR_LATENCY_Msk;
    acr |= wait << FLASH_ACR_LATENCY_Pos;
    FLASH->ACR = acr;
}

void Flash::setPrefetchEn(bool en)
{
    if (en)
        FLASH->ACR |= FLASH_ACR_PRFTEN_Msk;
    else
        FLASH->ACR &= ~FLASH_ACR_PRFTEN_Msk;
}

void Flash::setDCacheEn(bool en)
{
    if (en)
        FLASH->ACR |= FLASH_ACR_DCEN_Msk;
    else
        FLASH->ACR &= ~FLASH_ACR_DCEN_Msk;
}

void Flash::setICacheEn(bool en)
{
    if (en)
        FLASH->ACR |= FLASH_ACR_ICEN_Msk;
    else
        FLASH->ACR &= ~FLASH_ACR_ICEN_Msk;
}

unsigned int Flash::getAddress(unsigned short sector)
{
    unsigned int max = *(unsigned short *)FLASHSIZE_BASE / 2;

    if (sector > max)
        sector = max;

    return 0x08000000 + (unsigned int)sector * 2048;
}

}
#endif
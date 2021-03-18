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

#if defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

#include <__cross_studio_io.h>
#include <config.h>
#include <drv/peripherals.h>

#define CONFIG_UNLOCK 0x5555
#define CONFIG_LOCK 0x1234
#define RENEW 0xAAAA
#define START 0xCCCC

#if defined(IWDG) && defined(WDOG_ENABLE)

drv::Wdog wdog(IWDG);

#endif

namespace drv
{
Wdog::Wdog(WDOG_peri *peri)
{
    mPeri = peri;
    mReload = 0xFFF;
}

bool Wdog::init(unsigned char prescale, unsigned short reload)
{
#if defined(YSS_PERI_REPORT)
    const short pres[8] = {4, 8, 16, 32, 64, 128, 256, 256};
    debug_printf("\n########## IWDG 장치 설정 ##########\n\n");
#endif

    if (prescale > define::wdog::prescale::DIV256)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("분주비 설정 입력이 허용 범위를 초과했습니다. %d(user) < %d(max)\n", prescale, 7);
#endif
        return false;
    }

    if (reload > 0xFFF)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("Reload 설정 입력이 허용 범위를 초과했습니다. %d(user) < %d(max)\n", reload, 0xFFF);
#endif
        return false;
    }

    mPeri->KR = CONFIG_UNLOCK;
    mPeri->PR = prescale;
    mPeri->KR = START;
    mPeri->RLR = reload;
    mReload = reload;
    mPeri->KR = CONFIG_LOCK;

#if defined(YSS_PERI_REPORT)
    int time = reload * 1000 * pres[prescale] / 32000;

    debug_printf("소스 클럭 = %d kHz\n", 32000);
    debug_printf("분주비 = 1/%d\n", pres[prescale]);
    debug_printf("만료 시간 = %d mS\n", time);
    debug_printf("장치 설정 완료.\n");
#endif

    return true;
}

void Wdog::renew(void)
{
    mPeri->KR = RENEW;
}

}
#endif
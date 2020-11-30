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

#if defined(__SAML21E15A__) || defined(__SAML21E15B__) || defined(__SAML21E16A__) || defined(__SAML21E16B__) || \
    defined(__SAML21E17A__) || defined(__SAML21E17B__) || defined(__SAML21E18B__) || defined(__SAML21G16A__) || \
    defined(__SAML21G16B__) || defined(__SAML21G17A__) || defined(__SAML21G17B__) || defined(__SAML21G18A__) || \
    defined(__SAML21G18B__) || defined(__SAML21J16A__) || defined(__SAML21J16B__) || defined(__SAML21J17A__) || \
    defined(__SAML21J17B__) || defined(__SAML21J18A__) || defined(__SAML21J18B__)

#define GCLK_DFLL48M_REF 0
#define GCLK_DPLL 1
#define GCLK_DPLL_32K 2
#define GCLK_EIC 3
#define GCLK_USB 4
#define GCLK_EVSYS_CHANNEL_0 5
#define GCLK_EVSYS_CHANNEL_1 6
#define GCLK_EVSYS_CHANNEL_2 7
#define GCLK_EVSYS_CHANNEL_3 8
#define GCLK_EVSYS_CHANNEL_4 9
#define GCLK_EVSYS_CHANNEL_5 10
#define GCLK_EVSYS_CHANNEL_6 11
#define GCLK_EVSYS_CHANNEL_7 12
#define GCLK_EVSYS_CHANNEL_8 13
#define GCLK_EVSYS_CHANNEL_9 14
#define GCLK_EVSYS_CHANNEL_10 15
#define GCLK_EVSYS_CHANNEL_11 16
#define GCLK_SERCOM_SLOW 17
#define GCLK_SERCOM0_CORE 18
#define GCLK_SERCOM1_CORE 19
#define GCLK_SERCOM2_CORE 20
#define GCLK_SERCOM3_CORE 21
#define GCLK_SERCOM4_CORE 22
#define GCLK_SERCOM5_SLOW 23
#define GCLK_SERCOM5_CORE 24
#define GCLK_TCC0 25
#define GCLK_TCC1 25
#define GCLK_TCC2 26
#define GCLK_TC0 27
#define GCLK_TC1 27
#define GCLK_TC2 28
#define GCLK_TC3 28
#define GCLK_TC4 29
#define GCLK_ADC 30
#define GCLK_AC 31
#define GCLK_DAC 32
#define GCLK_PTC 33
#define GCLK_CCL 34

#include <__cross_studio_io.h>

#include <drv/peripherals.h>

namespace drv
{
bool Peripheral::setPeripheralClock(unsigned char num, unsigned char gen, bool en, bool lock)
{
    if (num >= sizeof(GCLK->PCHCTRL) / 4)
        return false;

    GCLK->PCHCTRL[num].reg = (gen << GCLK_PCHCTRL_GEN_Pos & GCLK_PCHCTRL_GEN_Msk) | (en << GCLK_PCHCTRL_CHEN_Pos & GCLK_PCHCTRL_CHEN) | (en << GCLK_PCHCTRL_WRTLOCK_Pos & GCLK_PCHCTRL_WRTLOCK);

    return true;
}

#if defined(SERCOM0)
void Peripheral::setSerCom0En(bool en)
{
    GCLK->PCHCTRL[(GCLK_SERCOM0_CORE)].bit.CHEN = en;
}
#endif

}

#endif
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

#include <__cross_studio_io.h>

#include <drv/clock/drv_microchip_clock_type_A.h>

namespace drv
{
unsigned int Clock::mXosc32Frequency __attribute__((section(".non_init")));
unsigned int Clock::mFdpllFrequency __attribute__((section(".non_init")));
unsigned int Clock::mMclkFrequency __attribute__((section(".non_init")));

void Clock::init(void)
{
    mXosc32Frequency = 0;
    mFdpllFrequency = 0;
    mMclkFrequency = 4000000;

    PM->PLCFG.reg = PM_PLCFG_PLSEL_PL2;
    while (!(PM->INTFLAG.reg & PM_INTFLAG_PLRDY))
        ;
    PM->INTFLAG.reg = PM_INTFLAG_PLRDY;

    MCLK->LPDIV.reg = MCLK_LPDIV_LPDIV(0x01);

    /*Initialize Backup Divider*/
    MCLK->BUPDIV.reg = MCLK_BUPDIV_BUPDIV(0x08);
}

bool Clock::enableXosc32(unsigned int Hz)
{
    OSC32KCTRL->XOSC32K.bit.XTALEN = true;
    OSC32KCTRL->XOSC32K.bit.ONDEMAND = false;
    OSC32KCTRL->XOSC32K.bit.ENABLE = true;

    for (int i = 0; i < 10000; i++)
        if (OSC32KCTRL->STATUS.bit.XOSC32KRDY == true)
        {
            mXosc32Frequency = Hz;
            return true;
        }

    mXosc32Frequency = 0;
    return false;
}

bool Clock::enableDfll(void)
{
    /****************** DFLL Initialization  *********************************/
    OSCCTRL->DFLLCTRL.reg = 0;

    while ((OSCCTRL->STATUS.reg & OSCCTRL_STATUS_DFLLRDY) != OSCCTRL_STATUS_DFLLRDY)
    {
        /* Waiting for the Ready state */
    }

    /*Load Calibration Value*/
    unsigned char calibCoarse = (uint8_t)(((*(uint32_t *)0x806020) >> 26) & 0x3f);

    OSCCTRL->DFLLVAL.reg = OSCCTRL_DFLLVAL_COARSE(calibCoarse) | OSCCTRL_DFLLVAL_FINE(512);
    OSCCTRL->DFLLCTRL.reg = 0;

    while ((OSCCTRL->STATUS.reg & OSCCTRL_STATUS_DFLLRDY) != OSCCTRL_STATUS_DFLLRDY)
    {
        /* Waiting for the Ready state */
    }

    /* Configure DFLL    */
    OSCCTRL->DFLLCTRL.reg = OSCCTRL_DFLLCTRL_ENABLE;

    while (!OSCCTRL->STATUS.bit.DFLLRDY)
    {
        /* Waiting for DFLL to be ready */
    }

    return true;
}

unsigned int Clock::getDfllFrequency(void)
{
    return 48000000;
}

unsigned int Clock::getApbClkFrequency(void)
{
    return mMclkFrequency;
}

bool Clock::enableDpll(unsigned char src, unsigned int Hz)
{
    GCLK->PCHCTRL[OSCCTRL_GCLK_ID_FDPLL].bit.CHEN = true;
    GCLK->PCHCTRL[OSCCTRL_GCLK_ID_FDPLL32K].bit.CHEN = true;

    switch (src)
    {
    case define::clock::dpll::src::_XOSC32K:
        if (OSC32KCTRL->STATUS.bit.XOSC32KRDY == false)
            return false;

        OSCCTRL->DPLLRATIO.bit.LDR = Hz / mXosc32Frequency - 1;
        OSCCTRL->DPLLRATIO.bit.LDRFRAC = Hz % mXosc32Frequency * 16 / mXosc32Frequency;
        break;
    default:
        return false;
    }

    OSCCTRL->DPLLCTRLA.bit.ENABLE = true;
    return false;
}

bool Clock::setGenericClock0(bool en, unsigned short div, unsigned char src)
{
    unsigned int reg = GCLK->GENCTRL[0].reg, freq = 0, div_ = 1;
    unsigned char pl = PM->PLCFG.bit.PLSEL, wait = 0;

    using namespace define::clock::gclk;

    switch (src)
    {
    case src::_DFLL48M:
        freq = getDfllFrequency();
        break;
    }

    switch (pl)
    {
    case 0:
        div_ = 12000000;
        break;
    case 2:
        div_ = 24000000;
        break;
    }

    mMclkFrequency = freq / div;
    wait = (unsigned char)(mMclkFrequency / div_);
    NVMCTRL->CTRLB.reg |= wait << NVMCTRL_CTRLB_RWS_Pos;

    reg &= ~(GCLK_GENCTRL_DIV_Msk | GCLK_GENCTRL_GENEN | GCLK_GENCTRL_SRC_Msk);
    reg |= (div << GCLK_GENCTRL_DIV_Pos & GCLK_GENCTRL_DIV_Msk) | (en << GCLK_GENCTRL_GENEN_Pos) | (src << GCLK_GENCTRL_SRC_Pos & GCLK_GENCTRL_SRC_Msk);
    GCLK->GENCTRL[0].reg = reg;

    while (GCLK->SYNCBUSY.bit.GENCTRL)
        ;

    return true;
}

bool Clock::setGenericClock(unsigned char num, bool en, unsigned short div, unsigned char src)
{
    if (num >= sizeof(GCLK->GENCTRL) / 4 || num == 0)
        return false;

    unsigned int reg = GCLK->GENCTRL[num].reg;

    reg &= ~(GCLK_GENCTRL_DIV_Msk | GCLK_GENCTRL_GENEN | GCLK_GENCTRL_SRC_Msk);
    reg |= (div << GCLK_GENCTRL_DIV_Pos & GCLK_GENCTRL_DIV_Msk) | (en << GCLK_GENCTRL_GENEN_Pos) | (src << GCLK_GENCTRL_SRC_Pos & GCLK_GENCTRL_SRC_Msk);
    GCLK->GENCTRL[num].reg = reg;

    while (GCLK->SYNCBUSY.bit.GENCTRL)
        ;

    return true;
}
}

#endif
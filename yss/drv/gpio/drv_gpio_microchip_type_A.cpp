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

#if defined(__SAML21E15A__) || defined(__SAML21E15B__) || defined(__SAML21E16A__) || defined(__SAML21E16B__) || \
    defined(__SAML21E17A__) || defined(__SAML21E17B__) || defined(__SAML21E18B__) || defined(__SAML21G16A__) || \
    defined(__SAML21G16B__) || defined(__SAML21G17A__) || defined(__SAML21G17B__) || defined(__SAML21G18A__) || \
    defined(__SAML21G18B__) || defined(__SAML21J16A__) || defined(__SAML21J16B__) || defined(__SAML21J17A__) || \
    defined(__SAML21J17B__) || defined(__SAML21J18A__) || defined(__SAML21J18B__)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <yss/stdlib.h>

#if defined(MICROCHIP_GPIOA)
static void setGpioAClockEn(bool en)
{
    //	clock.peripheral.setGpioAEn(en);
}

drv::Gpio gpioA(&PORT->Group[0], setGpioAClockEn, 0, 0);
#endif

#if defined(MICROCHIP_GPIOB)
static void setGpioBClockEn(bool en)
{
    //	clock.peripheral.setGpioBEn(en);
}

drv::Gpio gpioB(&PORT->Group[1], setGpioBClockEn, 0, 0);
#endif

namespace drv
{
Gpio::Gpio(PortGroup *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned char exti) : Drv(clockFunc, nvicFunc)
{
    mPeri = peri;
}

void Gpio::setToOutput(unsigned char pin, unsigned char ospeed, bool otype)
{
    mPeri->DIRSET.reg = 1 << pin;
    mPeri->PINCFG[pin].reg &= ~(PORT_PINCFG_INEN | PORT_PINCFG_PMUXEN);
}

void Gpio::setOutput(unsigned char pin, bool data)
{
    if (data)
        mPeri->OUTSET.reg = 1 << pin;
    else
        mPeri->OUTCLR.reg = 1 << pin;
}

void Gpio::setToAltFunc(unsigned char pin, unsigned char altFunc, unsigned char ospeed, bool otype)
{
    unsigned int reg;
    unsigned char shift = pin % 2 * 4, index = pin >> 1;
    mPeri->PINCFG[pin].reg &= ~PORT_PINCFG_INEN;
    mPeri->PINCFG[pin].reg |= PORT_PINCFG_PMUXEN;
    reg = mPeri->PMUX[index].reg;
    reg &= ~(0xF << shift);
    reg |= altFunc << shift;
    mPeri->PMUX[index].reg = reg;
}

void Gpio::setPullUpDown(unsigned char pin, unsigned char pupd)
{
    using namespace define::gpio::pupd;

    switch (pupd)
    {
    case NONE:
        mPeri->PINCFG[pin].reg &= ~PORT_PINCFG_PULLEN;
        break;
    case PULL_UP:
        mPeri->PINCFG[pin].reg |= PORT_PINCFG_PULLEN;
        mPeri->OUTSET.reg = 1 << pin;
        break;
    case PULL_DOWN:
        mPeri->PINCFG[pin].reg |= PORT_PINCFG_PULLEN;
        mPeri->OUTCLR.reg = 1 << pin;
        break;
    }
}

void Gpio::setToInput(unsigned char pin, unsigned char pullUpDown)
{
    mPeri->PINCFG[pin].reg &= ~PORT_PINCFG_PMUXEN;
    mPeri->PINCFG[pin].reg |= PORT_PINCFG_INEN;
    mPeri->DIRCLR.reg = 1 << pin;
    setPullUpDown(pin, pullUpDown);
}

bool Gpio::getData(unsigned char pin)
{
    unsigned int reg = mPeri->IN.reg;
    return (reg >> pin) & 0x01;
}

void Gpio::setToAnalog(unsigned char pin)
{
    setToAltFunc(pin, define::gpio::altfunc::ANALOG_B);
}

}

#endif
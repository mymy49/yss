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

#include <config.h>
#include <drv/peripherals.h>
#include <util/TimeLapse.h>
#include <yss/instance.h>

static unsigned int getTimerClkFreq(void)
{
    return clock.getApbClkFrequency();
}

#if defined(SPI0_ENABLE) && defined(SERCOM0)
static void setSpi0ClockEn(bool en)
{
    clock.peripheral.setSpi0En(true);
}

drv::Spi spi0(SERCOM0, setSpi0ClockEn, 0, getTimerClkFreq);
#endif

#if defined(SPI1_ENABLE) && defined(SERCOM1)
static void setSpi1ClockEn(bool en)
{
    clock.peripheral.setSpi1En(true);
}

drv::Spi spi1(SERCOM1, setSpi1ClockEn, 0, getTimerClkFreq);
#endif

#if defined(SPI2_ENABLE) && defined(SERCOM2)
static void setSpi2ClockEn(bool en)
{
    clock.peripheral.setSpi2En(en);
}

drv::Spi spi2(SERCOM2, setSpi2ClockEn, 0, getTimerClkFreq);
#endif

#if defined(SPI3_ENABLE) && defined(SERCOM3)
static void setSpi3ClockEn(bool en)
{
    clock.peripheral.setSpi3En(en);
}

drv::Spi spi3(SERCOM3, setSpi3ClockEn, 0, getTimerClkFreq);
#endif

#if defined(SPI4_ENABLE) && defined(SERCOM4)
static void setSpi4ClockEn(bool en)
{
    clock.peripheral.setSpi4En(en);
}

drv::Spi spi4(SERCOM4, setSpi4ClockEn, 0, getTimerClkFreq);
#endif

#if defined(SPI5_ENABLE) && defined(SERCOM5)
static void setSpi5ClockEn(bool en)
{
    clock.peripheral.setSpi5En(en);
}

drv::Spi spi5(SERCOM5, setSpi5ClockEn, 0, getTimerClkFreq);
#endif

namespace drv
{
Spi::Spi(Sercom *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc)
{
    mPeri = peri;
    mLastConfig = 0;
    mGetClockFreq = getClockFreq;
}

bool Spi::setConfig(config::spi::Config &config)
{
    SercomUsart *peri = (SercomUsart *)mPeri;

    if (mLastConfig == &config)
        return true;
    mLastConfig = &config;

    unsigned short baud = mGetClockFreq() / (config.maxFreq * 2);
    unsigned int reg;

    if (baud > 0)
        baud--;

    peri->BAUD.reg = baud;
    reg = peri->CTRLA.reg;
    reg &= ~(SERCOM_SPI_CTRLA_CPHA | SERCOM_SPI_CTRLA_CPOL);
    reg |= config.mode << SERCOM_SPI_CTRLA_CPHA_Pos;
    peri->CTRLA.reg = reg;

    return true;
}

bool Spi::init(void)
{
    SercomUsart *peri = (SercomUsart *)mPeri;

    peri->CTRLA.bit.SWRST = true;
    while (peri->SYNCBUSY.bit.SWRST)
        thread::yield();

    peri->CTRLA.reg |= 0x03 << SERCOM_SPI_CTRLA_MODE_Pos | mTxPad << SERCOM_SPI_CTRLA_DOPO_Pos | mRxPad << SERCOM_SPI_CTRLA_DIPO_Pos;
    peri->CTRLB.reg |= SERCOM_SPI_CTRLB_RXEN;

    return true;
}

void Spi::enable(bool en)
{
    SercomUsart *peri = (SercomUsart *)mPeri;

    peri->CTRLA.bit.ENABLE = en;
}

bool Spi::send(void *src, unsigned int size, unsigned int timeout)
{
    volatile SercomUsart *peri = (SercomUsart *)mPeri;
    TimeLapse time;
    unsigned char *data = (unsigned char *)src;

    for (int i = 0; i < size; i++)
    {
        while (~peri->INTFLAG.reg & SERCOM_SPI_INTFLAG_DRE)
        {
            if (time.getMsec() > timeout)
                return false;
            thread::yield();
        }

        peri->DATA.reg = data[i];
    }

    while (~peri->INTFLAG.reg & SERCOM_SPI_INTFLAG_TXC)
    {
        if (time.getMsec() > timeout)
            return false;
        thread::yield();
    }

    peri->INTFLAG.reg = SERCOM_SPI_INTFLAG_TXC;

    return true;
}

bool Spi::exchange(void *des, unsigned int size, unsigned int timeout)
{
    SercomUsart *peri = (SercomUsart *)mPeri;
    TimeLapse time;
    unsigned char *data = (unsigned char *)des;

    for (int i = 0; i < size; i++)
    {
        peri->DATA.reg = data[i];
        while (~peri->INTFLAG.reg & SERCOM_SPI_INTFLAG_TXC)
        {
            if (time.getMsec() > timeout)
                return false;
            thread::yield();
        }
        data[i] = peri->DATA.reg;
        peri->INTFLAG.reg = SERCOM_SPI_INTFLAG_TXC;
    }

    return true;
}

unsigned char Spi::exchange(unsigned char data)
{
    SercomUsart *peri = (SercomUsart *)mPeri;

    peri->DATA.reg = data;
    while (~peri->INTFLAG.reg & SERCOM_SPI_INTFLAG_TXC)
        thread::yield();
    data = peri->DATA.reg;
    peri->INTFLAG.reg = SERCOM_SPI_INTFLAG_TXC;

    return data;
}

void Spi::send(char data)
{
    SercomUsart *peri = (SercomUsart *)mPeri;

    peri->DATA.reg = data;
    while (~peri->INTFLAG.reg & SERCOM_SPI_INTFLAG_TXC)
        thread::yield();
    peri->INTFLAG.reg = SERCOM_SPI_INTFLAG_TXC;
}

void Spi::send(unsigned char data)
{
    SercomUsart *peri = (SercomUsart *)mPeri;

    peri->DATA.reg = data;
    while (~peri->INTFLAG.reg & SERCOM_SPI_INTFLAG_TXC)
        thread::yield();
    peri->INTFLAG.reg = SERCOM_SPI_INTFLAG_TXC;
}

void Spi::setPad(unsigned char txPad, unsigned char rxPad)
{
    mTxPad = txPad;
    mRxPad = rxPad;
}

}

#endif
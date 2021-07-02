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

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx) ||                                                 \
    defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC) ||                                                                         \
    defined(STM32L0)

#include <__cross_studio_io.h>

#include <drv/spi/drv_st_spi_type_A.h>
#include <drv/spi/drv_st_spi_type_A_register.h>
#include <yss/thread.h>

namespace drv
{
Spi::Spi(SPI_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), Stream *txStream, Stream *rxStream, unsigned char txChannel, unsigned char rxChannel, unsigned short priority, unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
    this->set(txChannel, rxChannel, (void *)&(peri->DR), (void *)&(peri->DR), priority);

    mGetClockFreq = getClockFreq;
    mTxStream = txStream;
    mRxStream = rxStream;
    mPeri = peri;
    mLastConfig = 0;
}

bool Spi::setConfig(config::spi::Config &config)
{
    if (mLastConfig == &config)
        return true;
    mLastConfig = &config;

    unsigned long mod;
    unsigned long div, clk = mGetClockFreq();

    div = clk / config.maxFreq;
    if (clk % config.maxFreq)
        div++;

    if (div <= 2)
        div = 0;
    else if (div <= 4)
        div = 1;
    else if (div <= 8)
        div = 2;
    else if (div <= 16)
        div = 3;
    else if (div <= 32)
        div = 4;
    else if (div <= 64)
        div = 5;
    else if (div <= 128)
        div = 6;
    else if (div <= 256)
        div = 7;
    else
        return false;

    setSPiMode(mPeri, config.mode);
    setSpiBaudrate(mPeri, div);

    return true;
}

bool Spi::init(void)
{
    setSpiEn(mPeri, false);
    setSpiDff(mPeri, false);
    setSpiMsbfirst(mPeri);
    setSpiSsi(mPeri, true);
    setSpiSsm(mPeri, true);
    setSpiMstr(mPeri, true);
    setSpiTxeie(mPeri, true);
    setSpiRxneie(mPeri, true);
    setSpiDmaTxEn(mPeri, true);

    return true;
}

void Spi::enable(bool en)
{
    setSpiEn(mPeri, en);
}

bool Spi::send(void *src, unsigned int size, unsigned int timeout)
{
    bool rt = false;

    setSpiDmaRxEn(mPeri, false);
    setSpiDmaTxEn(mPeri, true);

    if (mTxStream)
        rt = mTxStream->send(this, src, size, timeout);

    if (rt)
    {
        thread::yield();
        while (mPeri->SR & SPI_SR_BSY_Msk)
            thread::yield();
    }

    return rt;
}

bool Spi::exchange(void *des, unsigned int size, unsigned int timeout)
{
    bool rt = false;

    setSpiDmaRxEn(mPeri, true);
    setSpiDmaTxEn(mPeri, true);

    if (mRxStream)
        mRxStream->pendRx(this, des, size);

    if (mTxStream)
        rt = mTxStream->send(this, des, size, timeout);

    if (rt)
    {
        thread::yield();
        while (mPeri->SR & SPI_SR_BSY_Msk)
            thread::yield();
    }

    mRxStream->stop();
    return rt;
}

unsigned char Spi::exchange(unsigned char data)
{
    while (~mPeri->SR & SPI_SR_TXE_Msk)
        thread::yield();
    mPeri->DR = data;
    thread::yield();
    while (mPeri->SR & SPI_SR_BSY_Msk)
        thread::yield();

    return mPeri->DR;
}

void Spi::send(char data)
{
    while (~mPeri->SR & SPI_SR_TXE_Msk)
        thread::yield();
    mPeri->DR = data;
    thread::yield();
    while (mPeri->SR & SPI_SR_BSY_Msk)
        thread::yield();
}

void Spi::send(unsigned char data)
{
    while (~mPeri->SR & SPI_SR_TXE_Msk)
        thread::yield();
    mPeri->DR = data;
    thread::yield();
    while (mPeri->SR & SPI_SR_BSY_Msk)
        thread::yield();
}

}

#endif
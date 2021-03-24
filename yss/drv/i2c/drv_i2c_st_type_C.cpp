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

#if defined(STM32G431xx) || defined(STM32G441xx) ||                                                                                               \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB) || \
    defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) ||                                                 \
    defined(STM32L0)

#include <__cross_studio_io.h>

#include <config.h>
#include <drv/i2c/drv_st_i2c_type_C.h>
#include <util/time.h>
#include <yss/thread.h>

namespace drv
{
I2c::I2c(I2C_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), Stream *txStream, Stream *rxStream, unsigned char txChannel, unsigned char rxChannel, unsigned int (*getClockFrequencyFunc)(void), unsigned short priority) : Drv(clockFunc, nvicFunc, resetFunc)
{
    mPeri = peri;
}

bool I2c::init(unsigned char speed)
{
    switch (speed)
    {
    case define::i2c::speed::STANDARD:
        mPeri->TIMINGR = 3 << I2C_TIMINGR_PRESC_Pos |
                         4 << I2C_TIMINGR_SCLDEL_Pos |
                         2 << I2C_TIMINGR_SDADEL_Pos |
                         0xC3 << I2C_TIMINGR_SCLH_Pos |
                         0xC7 << I2C_TIMINGR_SCLL_Pos;
        break;
    case define::i2c::speed::FAST:
        mPeri->TIMINGR = 1 << I2C_TIMINGR_PRESC_Pos |
                         3 << I2C_TIMINGR_SCLDEL_Pos |
                         2 << I2C_TIMINGR_SDADEL_Pos |
                         3 << I2C_TIMINGR_SCLH_Pos |
                         9 << I2C_TIMINGR_SCLL_Pos;
        break;
    case define::i2c::speed::FAST_PLUS:
        mPeri->TIMINGR = 0 << I2C_TIMINGR_PRESC_Pos |
                         2 << I2C_TIMINGR_SCLDEL_Pos |
                         0 << I2C_TIMINGR_SDADEL_Pos |
                         2 << I2C_TIMINGR_SCLH_Pos |
                         4 << I2C_TIMINGR_SCLL_Pos;
        break;
    }

    mPeri->CR1 |= I2C_CR1_PE_Msk;

    return true;
}

inline void waitUntilComplete(I2C_TypeDef *peri)
{
    while ((peri->ISR & I2C_ISR_TC) == false)
        thread::yield();
}

#define setNbytes(data, x) setRegField(data, 0xFFUL, x, 16)
#define setSaddr(data, x) setRegField(data, 0x3FFUL, x, 0)

bool I2c::send(unsigned char addr, void *src, unsigned int size, unsigned int timeout)
{
    unsigned int isr;
    unsigned long long endTime = time::getRunningMsec() + timeout;
    unsigned char *csrc = (unsigned char *)src;

    mPeri->ICR = 0xffff;
    mPeri->CR2 = I2C_CR2_START_Msk | ((size << I2C_CR2_NBYTES_Pos) & I2C_CR2_NBYTES_Msk) | (addr & I2C_CR2_SADD_Msk);


    thread::delayUs(2);

    do
    {
        isr = mPeri->ISR;
        if (isr & I2C_ISR_NACKF)
            return false;
        thread::yield();

        if (endTime < time::getRunningMsec())
            return false;
    } while (!(isr & I2C_ISR_TXIS));

    while (size)
    {
        while (!(mPeri->ISR & I2C_ISR_TXE_Msk))
        {
            if (endTime < time::getRunningMsec())
                return false;
            thread::yield();
        }

        mPeri->TXDR = *csrc++;

        size--;
    }

    while (!(mPeri->ISR & I2C_ISR_TXE_Msk))
    {
        if (endTime < time::getRunningMsec())
            return false;
        thread::yield();
    }

    return true;
}

bool I2c::receive(unsigned char addr, void *des, unsigned int size, unsigned int timeout)
{
    unsigned int isr;
    unsigned long long endTime = time::getRunningMsec() + timeout;
    unsigned char *cdes = (unsigned char *)des;

    mPeri->ICR = 0xffff;
    mPeri->CR2 = I2C_CR2_START_Msk | I2C_CR2_RD_WRN_Msk | ((size << I2C_CR2_NBYTES_Pos) & I2C_CR2_NBYTES_Msk) | (addr & I2C_CR2_SADD_Msk);

    while (size)
    {
        while (!(mPeri->ISR & I2C_ISR_RXNE_Msk))
        {
            if (endTime < time::getRunningMsec())
                return false;
            thread::yield();
        }

        *cdes++ = mPeri->RXDR;
        size--;
    }

    return true;
}

void I2c::stop(void)
{
    mPeri->CR2 = I2C_CR2_STOP_Msk;
}
}

#endif
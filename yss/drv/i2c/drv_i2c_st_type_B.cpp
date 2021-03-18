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

#if defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC) ||                                                                         \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx)

#include <__cross_studio_io.h>

#include <drv/i2c/drv_st_i2c_type_B.h>
#include <drv/i2c/drv_st_i2c_type_B_register.h>

#include <util/time.h>

namespace drv
{
I2c::I2c(I2C_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), Stream *txStream, Stream *rxStream, unsigned char txChannel, unsigned char rxChannel, unsigned int (*getClockFrequencyFunc)(void), unsigned short priority) : Drv(clockFunc, nvicFunc, resetFunc)
{
    this->set(0, 0, (void *)&(peri->DR), (void *)&(peri->DR), priority);

    mGetClockFrequency = getClockFrequencyFunc;
    mTxStream = txStream;
    mRxStream = rxStream;
    mPeri = peri;
}

bool I2c::init(unsigned char speed)
{
    unsigned long clk = mGetClockFrequency(), mod;

    setI2cSoftReset(mPeri, true);
    setI2cSoftReset(mPeri, false);

    setI2cFreq(mPeri, clk / 1000000);

    switch (speed)
    {
    case define::i2c::speed::STANDARD:
        mod = clk % 200000;
        clk /= 200000;
        if (mod)
            clk++;
        break;
    case define::i2c::speed::FAST:
        mod = clk % 800000;
        clk /= 800000;
        if (mod)
            clk++;
        break;
    default:
        return false;
    }

    getI2cSr1(mPeri);
    setI2cSpeed(mPeri, speed);
    setI2cFastModeDuty(mPeri, define::i2c::duty::DUTY_1_2);

    setI2cClockControl(mPeri, clk);
    setI2cEn(mPeri, true);

    return true;
}

#define setNbytes(data, x) setRegField(data, 0xFFUL, x, 16)
#define setSaddr(data, x) setRegField(data, 0x3FFUL, x, 0)
#define checkBusError(sr) (sr & 0x0100)
#define checkStart(sr) (sr & 0x0001)
#define checkAddress(sr) (sr & 0x0002)

inline bool isStartingComplete(I2C_TypeDef *peri, unsigned int timeout)
{
    volatile unsigned int sr1;

    thread::delayUs(10);
    while (1)
    {
        sr1 = getI2cSr1(peri);
        if (timeout <= time::getRunningMsec())
            goto error;
        if (checkBusError(sr1))
            goto error;
        if (checkStart(sr1))
            break;
        thread::yield();
    }

    return true;
error:
    return false;
}

inline bool isAddressComplete(I2C_TypeDef *peri, unsigned int timeout)
{
    volatile unsigned int sr1, sr2;

    thread::delayUs(10);
    while (1)
    {
        sr1 = getI2cSr1(peri);
        if (timeout <= time::getRunningMsec())
            goto error;
        if (checkBusError(sr1))
            goto error;
        if (checkAddress(sr1))
            break;
        thread::yield();
    }

    sr1 = getI2cSr1(peri);
    sr2 = getI2cSr2(peri);
    return true;
error:
    sr1 = getI2cSr1(peri);
    sr2 = getI2cSr2(peri);
    return false;
}

bool I2c::send(unsigned char addr, void *src, unsigned int size, unsigned int timeout)
{
    unsigned char *data = (unsigned char *)src;
    unsigned long long endingTime = time::getRunningMsec() + timeout;

    setI2cStart(mPeri);
    if (isStartingComplete(mPeri, endingTime) == false)
        return false;

    addr &= 0xfe;
    setI2cDr(mPeri, addr);

    if (isAddressComplete(mPeri, endingTime) == false)
        return false;

    for (int i = 0; i < size; i++)
    {
        while (getI2cTxe(mPeri) == false)
        {
            if (endingTime <= time::getRunningMsec())
                return false;

            thread::yield();
        }

        setI2cDr(mPeri, data[i]);
    }

    while (getI2cBtf(mPeri) == false)
    {
        if (endingTime <= time::getRunningMsec())
        {
            return false;
        }

        thread::yield();
    }

    return true;
}

bool I2c::receive(unsigned char addr, void *des, unsigned int size, unsigned int timeout)
{
    unsigned long long endingTime = time::getRunningMsec() + timeout;
    unsigned char *data = (unsigned char *)des;
    switch (size)
    {
    case 0:
        return true;
    case 1:
        setI2cAck(mPeri, false);
        size = 0;
        break;
    default:
        setI2cAck(mPeri, true);
        break;
    }

    setI2cStart(mPeri);

    if (isStartingComplete(mPeri, endingTime) == false)
        goto error;

    addr |= 0x01;
    setI2cDr(mPeri, addr);

    if (isAddressComplete(mPeri, endingTime) == false)
        goto error;

    for (unsigned long i = 0; i < size; i++)
    {
        while ((getI2cRxne(mPeri) == false) || (getI2cBtf(mPeri) == false))
        {
            if (endingTime <= time::getRunningMsec())
            {
                goto error;
            }

            thread::yield();
        }
        if (size - 1 == i)
            setI2cAck(mPeri, false);
        data[i] = mPeri->DR;
    }

    if (size == 0)
    {
        stop();
        while (getI2cRxne(mPeri) == false)
        {
            if (endingTime <= time::getRunningMsec())
                goto error;

            thread::yield();
        }
        data[0] = mPeri->DR;
    }
    else
    {
        stop();
    }

    return true;
error:
    stop();
    return false;
}

void I2c::stop(void)
{
    if (getI2cBusy(mPeri) == true)
    {
        setI2cStop(mPeri);
        setI2cLast(mPeri, false);
        setI2cAck(mPeri, false);
    }
}
}

#endif
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
//  주담당자 : 아이구 (mymy49@nate.com) 2020.07.01 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <mod/eeprom/CAT24C256.h>
#include <string.h>
#include <util/time.h>

#define ADDR 0xa0

namespace mod
{
namespace eeprom
{
CAT24C256::CAT24C256(void)
{
    mPeri = 0;
    mWp = 0;
    mInitFlag = false;
    mAddr = ADDR;
    mLastWritingTime = 0;
}

unsigned long CAT24C256::getSize(void)
{
    return 32 * 1024;
}

bool CAT24C256::init(drv::I2c *peri, config::gpio::Set *wp, unsigned char addr)
{
    bool rt;
    char buf[2] = {0, 0};

    mPeri = peri;
    mWp = wp;
    mInitFlag = true;
    mAddr |= (addr & 0xe);

    if (mWp)
        mWp->port->setOutput(mWp->pin, true);

    mPeri->lock();
    mPeri->send(ADDR | 0x01, buf, 2, 300);
    mInitFlag = mPeri->receive(ADDR | 0x01, buf, 1, 500);
    mPeri->unlock();

    return mInitFlag;
}

bool CAT24C256::writeBytes(unsigned int addr, void *src, unsigned long size)
{
    volatile unsigned char i, j, k, num;
    unsigned char *cSrc = (unsigned char *)src, buf[66];
    bool rt;

    while (size)
    {
        if (size > 64)
        {
            num = 64;
            size -= 64;
        }
        else
        {
            num = size;
            size = 0;
        }

        k = 64 - (addr % 64);

        if (k < num)
        {
            buf[0] = addr >> 8;
            buf[1] = addr;

            for (i = 2; i < k + 2; i++)
                buf[i] = *cSrc++;

            for (int i = 0; i < 3; i++)
            {
                while (mThisTime < mLastWritingTime + 10)
                {
                    thread::yield();
                    mThisTime = time::getRunningMsec();
                }

                mPeri->lock();
                if (mWp)
                    mWp->port->setOutput(mWp->pin, false);
                rt = mPeri->send(mAddr, buf, k + 2, 500);
                mPeri->stop();
                if (mWp)
                    mWp->port->setOutput(mWp->pin, true);
                mPeri->unlock();
                mLastWritingTime = time::getRunningMsec();

                if (rt)
                    break;
            }

            if (rt == false)
            {
                return false;
            }

            num -= k;
            addr += k;
        }

        buf[0] = addr >> 8;
        buf[1] = addr;

        for (i = 2; i < num + 2; i++)
            buf[i] = *cSrc++;

        for (int i = 0; i < 3; i++)
        {
            while (mThisTime < mLastWritingTime + 10)
            {
                thread::yield();
                mThisTime = time::getRunningMsec();
            }

            mPeri->lock();
            if (mWp)
                mWp->port->setOutput(mWp->pin, false);
            rt = mPeri->send(mAddr, buf, num + 2, 500);
            mPeri->stop();
            if (mWp)
                mWp->port->setOutput(mWp->pin, true);
            mPeri->unlock();
            mLastWritingTime = time::getRunningMsec();

            if (rt)
                break;
        }

        addr += num;

        if (rt == false)
        {
            return false;
        }
    }

    return true;
}

bool CAT24C256::readBytes(unsigned int addr, void *des, unsigned long size)
{
    char buf[2];
    char *pAddr = (char *)&addr;
    bool rt = false;

    mThisTime = time::getRunningMsec();
    while (mThisTime < mLastWritingTime + 5)
    {
        thread::yield();
        mThisTime = time::getRunningMsec();
    }

    if (addr + size > getSize())
        return false;

    buf[0] = pAddr[1];
    buf[1] = pAddr[0];

    for (int i = 0; i < 3; i++)
    {
        mPeri->lock();
        mPeri->send(mAddr, buf, 2, 300);
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
        thread::delayUs(100);
#else
        thread::yield();
#endif
        rt = mPeri->receive(mAddr, (char *)des, size, 500);
        mPeri->unlock();

        if (rt)
            break;
    }

    return rt;
}

}
}
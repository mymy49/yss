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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.06.11 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/glcd/TM0027.h>
#include <string.h>

#define CMD false
#define DATA true

namespace mod
{
namespace glcd
{
config::spi::Config gLcdConfig =
    {
        define::spi::mode::MODE3,
        10000000};

TM0027::TM0027(void)
{
    mCs.port = 0;
    mA0.port = 0;
    mRst.port = 0;
    mPeri = 0;
    setSize(128, 64);
}

bool TM0027::init(drv::Spi &spi, config::gpio::Set &cs, config::gpio::Set &A0, config::gpio::Set &rst)
{
    mPeri = &spi;
    mCs = cs;
    mA0 = A0;
    mRst = rst;

    mCs.port->setOutput(mCs.pin, true);
    if (mRst.port)
        mRst.port->setOutput(mRst.pin, false);
    thread::delay(100);
    if (mRst.port)
        mRst.port->setOutput(mRst.pin, true);
    thread::delay(100);

    sendCmd(0xaf);
    thread::delay(10);
    sendCmd(0xa4);
    thread::delay(10);
    sendCmd(0xa0);
    thread::delay(10);
    sendCmd(0xc0);
    thread::delay(10);
    sendCmd(0x24);
    thread::delay(10);
    sendCmd(0x81);
    thread::delay(10);
    sendCmd(0x27);
    thread::delay(10);
    sendCmd(0x2f);

    return true;
}

void TM0027::sendCmd(unsigned char cmd)
{
    mPeri->lock();
    mA0.port->setOutput(mA0.pin, CMD);
    mPeri->setConfig(gLcdConfig);
    mPeri->enable(true);
    mCs.port->setOutput(mCs.pin, false);
    mPeri->send(cmd);
    mCs.port->setOutput(mCs.pin, true);
    //    mPeri->enable(false);
    mPeri->unlock();
}

void TM0027::sendData(void *data, unsigned int size)
{
    mPeri->lock();
    mA0.port->setOutput(mA0.pin, DATA);
    mPeri->setConfig(gLcdConfig);
    mPeri->enable(true);
    mCs.port->setOutput(mCs.pin, false);
    mPeri->send(data, size, 1000);
    mCs.port->setOutput(mCs.pin, true);
    //    mPeri->enable(false);
    mPeri->unlock();
}

void TM0027::clear(void)
{
    memset(mFrameBuffer, 0x00, 128 * 64 / 8);
}

void TM0027::fill(void)
{
    memset(mFrameBuffer, 0xff, 128 * 64 / 8);
}

void TM0027::refresh(void)
{
    unsigned char *des = mFrameBuffer;

    for (int i = 0; i < 8; i++)
    {
        sendCmd(0x40);     // Display start line set
        sendCmd(0xb0 | i); // Page address set
        sendCmd(0x10);     // Column address set upper bit
        sendCmd(0x00);     // Column address set lower bit

        sendData(des, 128);
        des += 128;
//		thread::delay(5);
    }
}

void TM0027::drawDot(unsigned short x, unsigned short y, bool data)
{
    if (x < 128 && y < 64)
    {
        x = 127 - x;
        if (data)
            mFrameBuffer[y / 8 * 128 + x] |= 1 << (y % 8);
        else
            mFrameBuffer[y / 8 * 128 + x] &= ~(1 << (y % 8));
    }
}
}
}
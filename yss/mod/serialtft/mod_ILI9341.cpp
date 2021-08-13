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

#include <mod/serialtft/ILI9341.h>
#include <stdlib.h>
#include <string.h>
#include <yss/malloc.h>
#include <yss/stdlib.h>

#if !defined(SPI_NOT_DEFINED)

namespace mod
{
namespace cputft
{
namespace CMD
{
enum
{
    NOP = 0x00,
    SOFTWARE_RESET = 0x01,
    READ_DISP_ID = 0x04,
    READ_DISP_STATUS = 0x09,
    READ_DISP_MADCTRL = 0x0B,
    READ_DISP_PIXEL_FORMAT = 0x0C,
    READ_DISP_IMAGE_FORMAT = 0x0D,
    READ_DISP_SIGNAL_MODE = 0x0E,
    READ_DISP_SELF_DIAGNOSTIC = 0x0F,
    ENTER_SLEEP_MODE = 0x10,
    SLEEP_OUT = 0x11,
    PARTIAL_MODE_ON = 0x12,
    NORMAL_DISP_MODE_ON = 0x13,
    DISP_INVERSION_OFF = 0x20,
    DISP_INVERSION_ON = 0x21,
    GAMMA_SET = 0x26,
    DISPLAY_OFF = 0x28,
    DISPLAY_ON = 0x29,
    COLUMN_ADDRESS_SET = 0x2A,
    PAGE_ADDRESS_SET = 0x2B,
    MEMORY_WRITE = 0x2C,
    COLOR_SET = 0x2D,
    MEMORY_READ = 0x2E,
    PARTIAL_AREA = 0x30,
    VERT_SCROLL_DEFINITION = 0x33,
    TEARING_EFFECT_LINE_OFF = 0x34,
    TEARING_EFFECT_LINE_ON = 0x35,
    MEMORY_ACCESS_CONTROL = 0x36,
    VERT_SCROLL_START_ADDRESS = 0x37,
    IDLE_MODE_OFF = 0x38,
    IDLE_MODE_ON = 0x39,
    COLMOD_PIXEL_FORMAT_SET = 0x3A,
    WRITE_MEMORY_CONTINUE = 0x3C,
    READ_MEMORY_CONTINUE = 0x3E,
    SET_TEAR_SCANLINE = 0x44,
    GET_SCANLINE = 0x45,
    WRITE_DISPLAY_BRIGHTNESS = 0x51,
    READ_DISPLAY_BRIGHTNESS = 0x52,
    WRITE_CTRL_DISPLAY = 0x53,
    READ_CTRL_DISPLAY = 0x54,
    WRITE_CONTENT_ADAPT_BRIGHTNESS = 0x55,
    READ_CONTENT_ADAPT_BRIGHTNESS = 0x56,
    WRITE_MIN_CAB_LEVEL = 0x5E,
    READ_MIN_CAB_LEVEL = 0x5F,
    FRAME_RATE = 0xb1,
    DISPLAY_CTRL = 0xb6,
    POWER_CTRL1 = 0xc0,
    POWER_CTRL2 = 0xc1,
    VCOM_CTRL1 = 0xc5,
    VCOM_CTRL2 = 0xc7,
    POWER_A = 0xcb,
    POWER_B = 0xcf,
    CMD_READ_ID1 = 0xDA,
    READ_ID2 = 0xDB,
    CMD_READ_ID3 = 0xDC,
    POS_GAMMA = 0xe0,
    NEG_GAMMA = 0xe1,
    DTCA = 0xe8,
    DTCB = 0xea,
    POWER_SEQ = 0xed,
    GAMMA3_FUNC_DIS = 0xf2,
    PRC = 0xf7
};
}

config::spi::Config gLcdConfig =
    {
        define::spi::mode::MODE0,
        10000000};

ILI9341::ILI9341(void)
{
    mCs.port = 0;
    mDc.port = 0;
    mBl.port = 0;
    mRst.port = 0;
    mPeri = 0;
}

unsigned short ILI9341::getWidth(void)
{
    return mSize.width;
}

unsigned short ILI9341::getHeight(void)
{
    return mSize.height;
}

unsigned short ILI9341::getColor(void)
{
    return mBrushColor;
}

unsigned short ILI9341::getFontColor(unsigned char a4, unsigned short color)
{
    RGB565_union back, fore;
    signed int buf;

    back.halfword = translateColor(color);
    fore.halfword = translateColor(mFontColor);

    buf = (signed int)fore.color.red - (signed int)back.color.red;
    buf *= a4;
    buf /= 15;
    fore.color.red = back.color.red + buf;

    buf = (signed int)fore.color.green - (signed int)back.color.green;
    buf *= a4;
    buf /= 15;
    fore.color.green = back.color.green + buf;

    buf = (signed int)fore.color.blue - (signed int)back.color.blue;
    buf *= a4;
    buf /= 15;
    fore.color.blue = back.color.blue + buf;

    return translateColor(fore.halfword);
}

unsigned short ILI9341::getBgColor(void)
{
    return mBgColor;
}

void ILI9341::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    RGB565_union color;
    color.color.red = red >> 3;
    color.color.green = green >> 2;
    color.color.blue = blue >> 3;
    mBrushColor = translateColor(color);
}

void ILI9341::setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    RGB565_union color;
    color.color.red = red >> 3;
    color.color.green = green >> 2;
    color.color.blue = blue >> 3;
    mFontColor = translateColor(color);
}

void ILI9341::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
    RGB565_union color;
    color.color.red = red >> 3;
    color.color.green = green >> 2;
    color.color.blue = blue >> 3;
    mBgColor = translateColor(color);
}

void ILI9341::fillFrameBuffer(void *framBuffer)
{
    unsigned int size = mSize.width * mSize.height * 2, sendingSize;
    unsigned char *src = (unsigned char *)framBuffer;

    setArea(0, 0, mSize.width, mSize.height);
    sendCmd(CMD::MEMORY_WRITE);
    sendData(src, size);
}

void ILI9341::fillFrameBuffer(void *framBuffer, signed short x, signed short y, unsigned short width, unsigned short height)
{
    unsigned int w = mSize.width, h = mSize.height;
    unsigned int size = width * 2;
    unsigned char *src = (unsigned char *)framBuffer;
    unsigned char *line;

    setArea(x, y, width, height);
    sendCmd(CMD::MEMORY_WRITE);

    for (int i = 0; i < height; i++)
    {
        line = &src[w * (i + y) * 2 + x * 2];
        sendData(line, size);
    }
}

void ILI9341::setArea(signed short x, signed short y, unsigned short width, unsigned short height)
{
    unsigned char data[4], buf;
    signed short end;

    if (x < 0)
        x = 0;
    else if (x > mSize.width - 1)
        x = mSize.width - 1;

    if (y < 0)
        y = 0;
    else if (y > mSize.height - 1)
        y = mSize.height - 1;

    if (x + width > mSize.width)
        width = mSize.width - x;
    if (y + height > mSize.height)
        height = mSize.height - y;

    end = x + width - 1;
    data[0] = x >> 8;
    data[1] = x & 0xff;
    data[2] = end >> 8;
    data[3] = end & 0xff;
    sendCmd(CMD::COLUMN_ADDRESS_SET, (char *)data, 4);

    end = y + height - 1;
    data[0] = y >> 8;
    data[1] = y & 0xff;
    data[2] = end >> 8;
    data[3] = end & 0xff;
    sendCmd(CMD::PAGE_ADDRESS_SET, (char *)data, 4);
}

void ILI9341::setCs(bool en)
{
    mCs.port->setOutput(mCs.pin, en);
}

void ILI9341::setDc(bool en)
{
    mDc.port->setOutput(mDc.pin, en);
}

void ILI9341::setRst(bool en)
{
    mRst.port->setOutput(mRst.pin, en);
}

void ILI9341::setBl(bool en)
{
    mBl.port->setOutput(mBl.pin, en);
}

void ILI9341::setBlackLight(bool en)
{
    setBl(en);
}

void ILI9341::sendCmd(unsigned char cmd)
{
    mPeri->lock();
    mPeri->setConfig(gLcdConfig);
    mPeri->enable(true);
    setDc(false);
    setCs(false);
    mPeri->exchange(cmd);
    setCs(true);
    mPeri->enable(false);
    mPeri->unlock();
}

void ILI9341::sendCmd(unsigned char cmd, void *data, unsigned short len)
{
    mPeri->lock();
    mPeri->setConfig(gLcdConfig);
    mPeri->enable(true);
    setDc(false);
    setCs(false);
    mPeri->exchange(cmd);
    setDc(true);
    mPeri->send((char *)data, len, 1000);
    setCs(true);
    mPeri->enable(false);
    mPeri->unlock();
}

void ILI9341::sendData(void *src, unsigned long size)
{
    mPeri->lock();
    mPeri->setConfig(gLcdConfig);
    mPeri->enable(true);
    setDc(true);
    setCs(false);
    mPeri->send((char *)src, size, 1000);
    setCs(true);
    mPeri->enable(false);
    mPeri->unlock();
}

void ILI9341::readData(unsigned char cmd, void *src, unsigned long size) {}

bool ILI9341::init(drv::Spi &spi, unsigned short width, unsigned short height, config::gpio::Set &cs, config::gpio::Set &dc, config::gpio::Set &rst, config::gpio::Set &backLight, unsigned char madctl, unsigned int frameBufferSize)
{
    Brush::setSize(Size{width, height});

    mBufferSize = frameBufferSize;

    if (frameBufferSize > 0)
    {
#if YSS_L_HEAP_USE == true
        mFrameBuffer = (unsigned short *)lmalloc(frameBufferSize);
#elif YSS_C_HEAP_USE == true
        mFrameBuffer = (unsigned short *)cmalloc(frameBufferSize);
#elif YSS_H_HEAP_USE == true
        mFrameBuffer = (unsigned short *)hmalloc(frameBufferSize);
#endif
    }

    mPeri = &spi;
    mCs.port = cs.port;
    mCs.pin = cs.pin;
    mDc.port = dc.port;
    mDc.pin = dc.pin;
    mRst.port = rst.port;
    mRst.pin = rst.pin;
    mBl.port = backLight.port;
    mBl.pin = backLight.pin;

    setRst(false);
    setCs(true);

    thread::delay(300);
    setRst(true);

    sendCmd(CMD::SOFTWARE_RESET);
    thread::delay(100);

    sendCmd(CMD::DISPLAY_OFF);

    const char powerA[5] = {0x39, 0x2c, 0x00, 0x34, 0x02};
    sendCmd(CMD::POWER_A, (char *)powerA, sizeof(powerA));

    const char powerB[3] = {0x00, 0xc1, 0x30};
    sendCmd(CMD::POWER_B, (char *)powerB, sizeof(powerB));

    const char dtca[3] = {0x85, 0x00, 0x78};
    sendCmd(CMD::DTCA, (char *)dtca, sizeof(dtca));

    const char dtcb[2] = {0x00, 0x00};
    sendCmd(CMD::DTCB, (char *)dtcb, sizeof(dtcb));

    const char powerSeq[4] = {0x64, 0x03, 0x12, 0x81};
    sendCmd(CMD::POWER_SEQ, (char *)powerSeq, sizeof(powerSeq));

    const char prc[1] = {0x20};
    sendCmd(CMD::PRC, (char *)prc, sizeof(prc));

    const char powerCtrl1[1] = {0x23};
    sendCmd(CMD::POWER_CTRL1, (char *)powerCtrl1, sizeof(powerCtrl1));

    const char powerCtrl2[1] = {0x10};
    sendCmd(CMD::POWER_CTRL2, (char *)powerCtrl2, sizeof(powerCtrl2));

    const char vcomCtrl1[2] = {0x3e, 0x28};
    sendCmd(CMD::VCOM_CTRL1, (char *)vcomCtrl1, sizeof(vcomCtrl1));

    const char vcomCtrl2[1] = {0x86};
    sendCmd(CMD::VCOM_CTRL2, (char *)vcomCtrl2, sizeof(vcomCtrl2));

    char memAccCtrl[1] = {0x08};
    memAccCtrl[0] |= madctl;
    sendCmd(CMD::MEMORY_ACCESS_CONTROL, (char *)memAccCtrl, sizeof(memAccCtrl));

    const char fixelFormat[1] = {0x55};
    sendCmd(CMD::COLMOD_PIXEL_FORMAT_SET, (char *)fixelFormat, sizeof(fixelFormat));

    const char frameRate[2] = {0x00, 0x18};
    sendCmd(CMD::FRAME_RATE, (char *)frameRate, sizeof(frameRate));

    const char gammaFuncDis[1] = {0x00};
    sendCmd(CMD::GAMMA3_FUNC_DIS, (char *)gammaFuncDis, sizeof(gammaFuncDis));

    const char gammaSet4[1] = {0x01};
    sendCmd(CMD::GAMMA_SET, (char *)gammaSet4, sizeof(gammaSet4));

    const char posGamma[15] = {0x0f, 0x31, 0x2b, 0x0c, 0x0e, 0x08, 0x4e, 0xf1, 0x37, 0x07, 0x10, 0x03, 0x0e, 0x09, 0x00};
    sendCmd(CMD::POS_GAMMA, (char *)posGamma, sizeof(posGamma));

    const char negGamma[15] = {0x00, 0x0e, 0x14, 0x03, 0x11, 0x07, 0x31, 0xc1, 0x48, 0x08, 0x0f, 0x0c, 0x31, 0x36, 0x0f};
    sendCmd(CMD::NEG_GAMMA, (char *)negGamma, sizeof(negGamma));

    const char displayCtrl[4] = {0x08, 0x82, 0x27};
    sendCmd(CMD::DISPLAY_CTRL, (char *)displayCtrl, sizeof(displayCtrl));

    sendCmd(CMD::SLEEP_OUT);
    thread::delay(500);

    sendCmd(CMD::DISPLAY_ON);
    thread::delay(100);

    sendCmd(CMD::MEMORY_WRITE);

    return true;
}

void ILI9341::drawDot(signed short x, signed short y)
{
    unsigned char data[4];

    if (y < mSize.height && x < mSize.width)
    {
        data[0] = x >> 8;
        data[1] = x & 0xff;
        data[2] = data[0];
        data[3] = data[1];
        sendCmd(CMD::COLUMN_ADDRESS_SET, (char *)data, 4);

        data[0] = y >> 8;
        data[1] = y & 0xff;
        data[2] = data[0];
        data[3] = data[1];
        sendCmd(CMD::PAGE_ADDRESS_SET, (char *)data, 4);

        sendCmd(CMD::MEMORY_WRITE);
        sendData(&mBrushColor, 2);
    }
}

void ILI9341::drawDot(signed short x, signed short y, unsigned short color)
{
    unsigned char data[4];

    if (y < mSize.height && x < mSize.width)
    {
        data[0] = x >> 8;
        data[1] = x & 0xff;
        data[2] = data[0];
        data[3] = data[1];
        sendCmd(CMD::COLUMN_ADDRESS_SET, (char *)data, 4);

        data[0] = y >> 8;
        data[1] = y & 0xff;
        data[2] = data[0];
        data[3] = data[1];
        sendCmd(CMD::PAGE_ADDRESS_SET, (char *)data, 4);

        sendCmd(CMD::MEMORY_WRITE);
        sendData(&color, 2);
    }
}

void ILI9341::drawDot(signed short x, signed short y, unsigned int color)
{
    drawDot(x, y, (unsigned short)color);
}

void ILI9341::drawFontDot(signed short x, signed short y, unsigned char color)
{
    unsigned char data[4];

    if (y < mSize.height && x < mSize.width)
    {
        data[0] = x >> 8;
        data[1] = x & 0xff;
        data[2] = data[0];
        data[3] = data[1];
        sendCmd(CMD::COLUMN_ADDRESS_SET, (char *)data, 4);

        data[0] = y >> 8;
        data[1] = y & 0xff;
        data[2] = data[0];
        data[3] = data[1];
        sendCmd(CMD::PAGE_ADDRESS_SET, (char *)data, 4);

        sendCmd(CMD::MEMORY_WRITE);
        sendData(&mFontColor, 2);
    }
}

void ILI9341::eraseDot(Pos pos)
{
    unsigned char data[4];
    signed short x = pos.x, y = pos.y;

    if (y < mSize.height && x < mSize.width)
    {
        data[0] = x >> 8;
        data[1] = x & 0xff;
        data[2] = data[0];
        data[3] = data[1];
        sendCmd(CMD::COLUMN_ADDRESS_SET, (char *)data, 4);

        data[0] = y >> 8;
        data[1] = y & 0xff;
        data[2] = data[0];
        data[3] = data[1];
        sendCmd(CMD::PAGE_ADDRESS_SET, (char *)data, 4);

        sendCmd(CMD::MEMORY_WRITE);
        sendData(&mBgColor, 2);
    }
}

void ILI9341::drawBmp565(Pos pos, const Bmp565 *image)
{
    unsigned char *src = image->data;
    unsigned char data[4];
    signed short end;
    unsigned short width = image->width, height = image->height;
    unsigned long size = width * height * 2;
    signed short x = pos.x, y = pos.y;

    // RGB565가 아니면 리턴
    if (image->type != 0)
        return;

    end = x + width - 1;
    data[0] = x >> 8;
    data[1] = x & 0xff;
    data[2] = end >> 8;
    data[3] = end & 0xff;
    sendCmd(CMD::COLUMN_ADDRESS_SET, (char *)data, 4);

    end = y + height - 1;
    data[0] = y >> 8;
    data[1] = y & 0xff;
    data[2] = end >> 8;
    data[3] = end & 0xff;
    sendCmd(CMD::PAGE_ADDRESS_SET, (char *)data, 4);

    sendCmd(CMD::MEMORY_WRITE);
    sendData(src, size);
}

void ILI9341::drawBmp565(Pos pos, const Bmp565 &image)
{
    drawBmp565(pos, &image);
}

void ILI9341::fillRect(Pos p1, Pos p2)
{
    signed short buf;

    if (p1.x > p2.x)
    {
        buf = p1.x;
        p1.x = p2.x;
        p2.x = buf;
    }

    if (p1.y > p2.y)
    {
        buf = p1.y;
        p1.y = p2.y;
        p2.y = buf;
    }

    fillRect(p1, Size{(unsigned short)(p2.x - p1.x), (unsigned short)(p2.y - p1.y)});
}

void ILI9341::fillRect(Pos pos, Size size, unsigned short color)
{
    unsigned char data[4];
    signed short end, x = pos.x, y = pos.y;
    unsigned short width = size.width, height = size.height;
    unsigned long bufSize = width * height * 2;

    if (mBufferSize == 0)
        return;

    end = x + width - 1;
    data[0] = x >> 8;
    data[1] = x & 0xff;
    data[2] = end >> 8;
    data[3] = end & 0xff;
    sendCmd(CMD::COLUMN_ADDRESS_SET, (char *)data, 4);

    end = y + height - 1;
    data[0] = y >> 8;
    data[1] = y & 0xff;
    data[2] = end >> 8;
    data[3] = end & 0xff;
    sendCmd(CMD::PAGE_ADDRESS_SET, (char *)data, 4);

    sendCmd(CMD::MEMORY_WRITE);

    if (bufSize > mBufferSize)
        end = mBufferSize;
    else
        end = bufSize;

    color = translateColor(color);

    memsethw(mFrameBuffer, color, end);
    while (bufSize)
    {
        if (bufSize > mBufferSize)
        {
            end = mBufferSize;
            bufSize -= mBufferSize;
        }
        else
        {
            end = bufSize;
            bufSize = 0;
        }
        sendData(mFrameBuffer, end);
    }
}

void ILI9341::fillRect(Pos pos, Size size)
{
    fillRect(pos, size, mBrushColor);
}

void ILI9341::fill(void)
{
    fillRect(Pos{0, 0}, mSize, mBrushColor);
}

void ILI9341::clear(void)
{
    fillRect(Pos{0, 0}, mSize, mBgColor);
}

unsigned short ILI9341::translateColor(RGB565_union color)
{
    unsigned short buf;

    buf = color.byte[1];
    buf |= ((unsigned short)color.byte[0] << 8) & 0xff00;

    return buf;
}

unsigned short ILI9341::translateColor(unsigned short color)
{
    unsigned short buf;

    buf = color << 8;
    buf |= color >> 8;

    return buf;
}
}
}

#endif
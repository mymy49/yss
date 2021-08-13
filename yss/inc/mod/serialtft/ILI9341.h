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

#ifndef YSS_MOD_CPUTFT_ILI9341__H_
#define YSS_MOD_CPUTFT_ILI9341__H_

#include <yss/instance.h>
#include <sac/SerialTft.h>

#if !defined(SPI_NOT_DEFINED)

namespace mod
{
namespace cputft
{
class ILI9341 : public sac::SerialTft
{
    drv::Spi *mPeri;
    config::gpio::Set mCs, mDc, mRst, mBl;
    unsigned short mBrushColor, mBgColor, mFontColor;
    unsigned int mBufferSize;
    unsigned short *mFrameBuffer;

    void setCs(bool en);
    void setDc(bool en);
    void setRst(bool en);
    void setBl(bool en);
    void sendCmd(unsigned char cmd);
    void sendCmd(unsigned char cmd, void *data, unsigned short len);
    void sendData(void *src, unsigned long size);
    void readData(unsigned char cmd, void *src, unsigned long size);
    void fillRect(Pos p1, Size size, unsigned short color);

  public:
    enum
    {
        Y_MIRROR = 0x80,
        X_MIRROR = 0x40,
        V_MIRROR = 0x20
    };

    ILI9341(void);
    bool init(drv::Spi &spi, unsigned short width, unsigned short height, config::gpio::Set &cs, config::gpio::Set &dc, config::gpio::Set &rst, config::gpio::Set &backLight, unsigned char madctl = 0, unsigned int frameBufferSize = 0);

    void drawDot(signed short x, signed short y);
    void drawDot(signed short x, signed short y, unsigned short color);
    void drawDot(signed short x, signed short y, unsigned int color);
    void drawFontDot(signed short x, signed short y, unsigned char color);
    void eraseDot(Pos pos);
    void drawBmp565(Pos pos, const Bmp565 *image);
    void drawBmp565(Pos pos, const Bmp565 &image);

    void setBlackLight(bool en);
    void fillRect(Pos p1, Pos p2);
    void fillRect(Pos pos, Size size);
    void fill(void);
    void clear(void);

    unsigned short getColor(void);
    unsigned short getFontColor(unsigned char a4, unsigned short color);
    unsigned short getBgColor(void);
    unsigned short translateColor(RGB565_union color);
    unsigned short translateColor(unsigned short color);

    unsigned short getWidth(void);
    unsigned short getHeight(void);
    void setArea(signed short x, signed short y, unsigned short width, unsigned short height);
    void fillFrameBuffer(void *framBuffer);
    void fillFrameBuffer(void *framBuffer, signed short x, signed short y, unsigned short width, unsigned short height);

    void setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
    void setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
    void setBgColor(unsigned char red, unsigned char green, unsigned char blue);

    void drawLine(signed short sx, signed short sy, signed short ex, signed short ey, unsigned short color);
    void drawRect(signed short x, signed short y, unsigned short width, unsigned short height, unsigned short color);
    void drawRect(signed short x, signed short y, unsigned short width, unsigned short height, unsigned short thickness, unsigned short color);
};
}
}

#endif

#endif
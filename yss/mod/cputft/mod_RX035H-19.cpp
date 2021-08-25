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

#include <mod/cputft/RX035H-19.h>
#include <stdlib.h>
#include <string.h>
#include <yss/malloc.h>
#include <yss/stdlib.h>

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

void dummy(void) {}

RX035H_19::RX035H_19(void)
{
    sendCmd_ = (void (*)(unsigned char))dummy;
    sendData_ = (void (*)(unsigned short))dummy;
    drawDot_ = (void (*)(unsigned short, unsigned short, unsigned short))dummy;
    drawDots_ = (void (*)(unsigned short, unsigned short, unsigned short, unsigned short))dummy;
    drawDotsImg_ = (void (*)(unsigned short, unsigned short, unsigned short *, unsigned short))dummy;
}

bool RX035H_19::init(const Config config)
{
    sendCmd_ = config.sendCmd;
    sendData_ = config.sendData;
    drawDot_ = config.drawDot;
    drawDots_ = config.drawDots;
    drawDotsImg_ = config.drawDotsImg;

    Brush::setSize(Size{480, 320});

    sendCmd_(0x00);

    sendCmd_(0xb0);
    sendData_(0x00);
    sendCmd_(0x01); // reset
    thread::delay(300);

    sendCmd_(0x33);

    sendData_(0x00); // TFA
    sendData_(0x00);

    sendData_(0x01); //VSA
    sendData_(0xE0);

    sendData_(0x00); //BFA
    sendData_(0x00);

    sendCmd_(0x37);
    sendData_(0x00);
    sendData_(0x00);

    sendCmd_(0xC0);
    sendData_(0x19); //VREG1OUT POSITIVE
    sendData_(0x1a); //VREG2OUT NEGATIVE

    sendCmd_(0xC1);
    sendData_(0x45); //VGH,VGL    VGH>=14V.
    sendData_(0x00);

    sendCmd_(0xC2);
    sendData_(0x33);

    sendCmd_(0XC5);
    sendData_(0x00);
    sendData_(0x28); //VCM_REG[7:0]. <=0X80.

    sendCmd_(0xB1);  //OSC Freq set.
    sendData_(0xB0); //0xA0=62HZ,0XB0 =70HZ, <=0XB0.
    sendData_(0x11);

    sendCmd_(0xB4);
    sendData_(0x02); //2 DOT FRAME MODE,F<=70HZ.

    sendCmd_(0xB6);
    sendData_(0x00);
    sendData_(0x42); //0 GS SS SM ISC[3:0];
    sendData_(0x3B);

    sendCmd_(0xB7);
    sendData_(0x47);

    sendCmd_(0x36);
    sendData_(0xA0);

    sendCmd_(0x3A);
    sendData_(0x55);

    sendCmd_(0x11);
    thread::delay(120);

    sendCmd_(0x13);
    sendCmd_(0x29);

    return true;
}

void RX035H_19::gotoXy(unsigned short x, unsigned short y)
{
    sendCmd_(0x2A);
    sendData_(x >> 8);
    sendData_(x & 0x00FF);
    sendData_(0x01);
    sendData_(0xDF);

    sendCmd_(0x2B);
    sendData_(y >> 8);
    sendData_(y & 0x00FF);
    sendData_(0x01);
    sendData_(0x3F);
}

void RX035H_19::drawDots(unsigned short x, unsigned short y, unsigned short color, unsigned short size)
{
    drawDots_(x, y, color, size);
}

void RX035H_19::drawDots(unsigned short x, unsigned short y, unsigned short *src, unsigned short size)
{
    drawDotsImg_(x, y, src, size);
}

void RX035H_19::drawDot(signed short x, signed short y)
{
    drawDot_(x, y, mBrushColor.halfword);
}

void RX035H_19::drawDot(signed short x, signed short y, unsigned short color)
{
    drawDot_(x, y, color);
}

void RX035H_19::drawDot(signed short x, signed short y, unsigned int color)
{
}

void RX035H_19::drawFontDot(signed short x, signed short y, unsigned char color)
{
    drawDot_(x, y, color);
}

void RX035H_19::eraseDot(Pos pos)
{
    drawDot_(pos.x, pos.y, mBgColor.halfword);
}

void RX035H_19::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    RGB565_union color;
    color.color.blue = red >> 3;
    color.color.green = green >> 2;
    color.color.red = blue >> 3;
    mBrushColor.halfword = color.halfword;
}

void RX035H_19::setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
    mFontColor.setFontColor(red, green, blue);
}

void RX035H_19::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
    mBgColor.color.blue = red >> 3;
    mBgColor.color.green = green >> 2;
    mBgColor.color.red = blue >> 3;
    mFontColor.setBgColor(blue, green, red);
}
}
}
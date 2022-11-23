////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/cputft/RX035H-19.h>
#include <stdlib.h>
#include <string.h>
#include <yss/malloc.h>
#include <yss/string.h>

namespace mod
{
namespace cputft
{
void dummy(void) {}

RX035H_19::RX035H_19(void)
{
	sendCmd_ = (void (*)(uint8_t))dummy;
	sendData_ = (void (*)(uint16_t))dummy;
	drawDot_ = (void (*)(uint16_t, uint16_t, uint16_t))dummy;
	drawDots_ = (void (*)(uint16_t, uint16_t, uint16_t, uint16_t))dummy;
	drawDotsImg_ = (void (*)(uint16_t, uint16_t, uint16_t *, uint16_t))dummy;
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

void RX035H_19::gotoXy(uint16_t x, uint16_t y)
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

void RX035H_19::drawDots(uint16_t x, uint16_t y, uint16_t color, uint16_t size)
{
	drawDots_(x, y, color, size);
}

void RX035H_19::drawDots(uint16_t x, uint16_t y, uint16_t *src, uint16_t size)
{
	drawDotsImg_(x, y, src, size);
}

void RX035H_19::drawDot(int16_t x, int16_t y)
{
	drawDot_(x, y, mBrushColor.halfword);
}

void RX035H_19::drawDot(int16_t x, int16_t y, uint16_t color)
{
	drawDot_(x, y, color);
}

void RX035H_19::drawDot(int16_t x, int16_t y, uint32_t color)
{
}

void RX035H_19::drawFontDot(int16_t x, int16_t y, uint8_t color)
{
	drawDot_(x, y, color);
}

void RX035H_19::eraseDot(Position pos)
{
	drawDot_(pos.x, pos.y, mBgColor.halfword);
}

void RX035H_19::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	RGB565_union color;
	color.color.red = red >> 3;
	color.color.green = green >> 2;
	color.color.blue = blue >> 3;
	mBrushColor.halfword = color.halfword;
}

void RX035H_19::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mFontColor.setFontColor(red, green, blue);
	mFontColor.calculate();
}

void RX035H_19::setBgColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 2;
	mBgColor.color.blue = blue >> 3;
	mFontColor.setBgColor(red, green, blue);
	mFontColor.calculate();
}
}
}
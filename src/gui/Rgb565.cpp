////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.1
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/instance.h>
#include <yss/gui.h>
#include <gui/painter.h>

Rgb565::Rgb565(void)
{
	mDotSize = 2;
	mBrushColor.halfword = 0x0;
	mFontColorReg = 0xff000000;
	mBgColor.halfword = 0xffff;
	mColorMode = define::ltdc::format::RGB565;
}

void Rgb565::drawDot(int16_t x, int16_t y)
{
	uint16_t *buf = (uint16_t *)mFrameBuffer;
	buf[FrameBuffer::mSize.width * y + x] = mBrushColor.halfword;
}

void Rgb565::drawDot(int16_t x, int16_t y, uint16_t color)
{
	uint16_t *buf = (uint16_t *)mFrameBuffer;
	buf[FrameBuffer::mSize.width * y + x] = color;
}

void Rgb565::drawDot(int16_t x, int16_t y, uint32_t color)
{
}

void Rgb565::drawFontDot(int16_t x, int16_t y, uint8_t color)
{
}

void Rgb565::eraseDot(Position pos)
{
	uint16_t *buf = (uint16_t *)mFrameBuffer;
	buf[FrameBuffer::mSize.width * pos.y + pos.x] = mBgColor.halfword;
}

void Rgb565::setBrushColor(RGB565_struct color)
{
	mBrushColor.color = color;
}

void Rgb565::setBackgroundColor(RGB565_struct color)
{
	mBgColor.color = color;
}

void Rgb565::setBrushColor(RGB565_union color)
{
	mBrushColor = color;
}

void Rgb565::setBackgroundColor(RGB565_union color)
{
	mBgColor = color;
}

void Rgb565::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mFontColorReg = alpha << 24 | red << 16 | green << 8 | blue;
}

void Rgb565::setBrushColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mBrushColor.color.red = red >> 3;
	mBrushColor.color.green = green >> 2;
	mBrushColor.color.blue = blue >> 3;
}

void Rgb565::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 2;
	mBgColor.color.blue = blue >> 3;
}

void Rgb565::setBrushColor(uint16_t color)
{
	mBrushColor.halfword = color;
}

void Rgb565::setBackgroundColor(uint16_t color)
{
	mBgColor.halfword = color;
}

void Rgb565::clear(void)
{
	Painter::fill(*this, mBgColor);
}

uint8_t Rgb565::drawChar(Position pos, uint32_t utf8)
{
	if (mFrameBuffer)
		return Painter::drawChar(*this, &mFont, utf8, pos, mFontColorReg, (uint8_t)(mFontColorReg >> 24));
	else
		return 0;
}

void Rgb565::clearRectangle(Position pos, Size size)
{
	Painter::fillRectangle(*this, pos, size, mBgColor);
}

void Rgb565::drawBmp565(Position pos, const Bmp565 *image)
{
	Painter::draw(*this, image, pos);
}

void Rgb565::drawBmp565(Position pos, const Bmp565 &image)
{
	Painter::draw(*this, &image, pos);
}

#endif


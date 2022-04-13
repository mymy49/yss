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

#include <yss/instance.h>
#include <config.h>

#if defined(DMA2D) && USE_GUI == true && YSS_L_HEAP_USE == true

#include <yss/gui.h>

Rgb565::Rgb565(void)
{
	mDotSize = 2;
	mBrushColor.halfword = 0x0;
	mFontColorReg = 0xff000000;
	mBgColor.halfword = 0xffff;
	mColorMode = define::ltdc::format::RGB565;
}

void Rgb565::drawDot(signed short x, signed short y)
{
	unsigned short *buf = (unsigned short *)mFrameBuffer;
	buf[FrameBuffer::mSize.width * y + x] = mBrushColor.halfword;
}

void Rgb565::drawDot(signed short x, signed short y, unsigned short color)
{
	unsigned short *buf = (unsigned short *)mFrameBuffer;
	buf[FrameBuffer::mSize.width * y + x] = color;
}

void Rgb565::drawDot(signed short x, signed short y, unsigned int color)
{
}

void Rgb565::drawFontDot(signed short x, signed short y, unsigned char color)
{
}

void Rgb565::eraseDot(Pos pos)
{
	unsigned short *buf = (unsigned short *)mFrameBuffer;
	buf[FrameBuffer::mSize.width * pos.y + pos.x] = mBgColor.halfword;
}

void Rgb565::setColor(RGB565_struct color)
{
	mBrushColor.color = color;
}

void Rgb565::setBgColor(RGB565_struct color)
{
	mBgColor.color = color;
}

void Rgb565::setColor(RGB565_union color)
{
	mBrushColor = color;
}

void Rgb565::setBgColor(RGB565_union color)
{
	mBgColor = color;
}

void Rgb565::setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	mFontColorReg = alpha << 24 | red << 16 | green << 8 | blue;
}

void Rgb565::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	mBrushColor.color.red = red >> 3;
	mBrushColor.color.green = green >> 2;
	mBrushColor.color.blue = blue >> 3;
}

void Rgb565::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 2;
	mBgColor.color.blue = blue >> 3;
}

void Rgb565::setColor(unsigned short color)
{
	mBrushColor.halfword = color;
}

void Rgb565::setBgColor(unsigned short color)
{
	mBgColor.halfword = color;
}

void Rgb565::clear(void)
{
	dma2d.fill(*this, mBgColor);
}

unsigned char Rgb565::drawChar(Pos pos, unsigned int utf8)
{
	if (mFrameBuffer)
		return dma2d.drawChar(*this, &mFont, utf8, pos, mFontColorReg, (unsigned char)(mFontColorReg >> 24));
	else
		return 0;
}

void Rgb565::clearRectangle(Pos pos, Size size)
{
	dma2d.fillRectangle(*this, pos, size, mBgColor);
}

void Rgb565::drawBmp565(Pos pos, const Bmp565 *image)
{
	dma2d.draw(*this, image, pos);
}

void Rgb565::drawBmp565(Pos pos, const Bmp565 &image)
{
	dma2d.draw(*this, &image, pos);
}

#endif
/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/instance.h>
#include <yss/gui.h>
#include <yss.h>
#include <sac/TftLcdDriver.h>
/*
Rgb565::Rgb565(void)
{
}

void Rgb565::drawDot(int16_t x, int16_t y)
{
	uint16_t *buf = (uint16_t *)mFrameBuffer;
	buf[FrameBuffer::mSize.width * y + x] = mBrushColorCode;
}

void Rgb565::drawDot(int16_t x, int16_t y, Color color)
{
	uint16_t *buf = (uint16_t *)mFrameBuffer;
	buf[FrameBuffer::mSize.width * y + x] = color.getRgb565Code();
}

void Rgb565::eraseDot(Position pos)
{
	uint16_t *buf = (uint16_t *)mFrameBuffer;
	buf[FrameBuffer::mSize.width * pos.y + pos.x] = mBgColorCode;
}

void Rgb565::clear(void)
{
	Painter::fill(*this, mBgColor);
}

uint8_t Rgb565::drawChar(Position pos, uint32_t utf8)
{
	if (mFrameBuffer)
		return Painter::drawChar(*this, &mFont, utf8, pos, mFontColor);
	else
		return 0;
}

void Rgb565::clearRectangle(Position pos, Size size)
{
//	Painter::fillRectangle(*this, pos, size, mBgColor);
}

void Rgb565::drawBmp565(Position pos, const Bmp565 *image)
{
	Painter::draw(*this, image, pos);
}

void Rgb565::drawBmp565(Position pos, const Bmp565 &image)
{
	Painter::draw(*this, &image, pos);
}

void Rgb565::setBrushColor(Color color)
{
	//mBrushColor = color;
	//mBrushColorCode = color.getRgb565Code();
}

void Rgb565::setBrushColor(uint8_t red, uint8_t green, uint8_t blue)
{
	//mBrushColor.setColor(red, green, blue);
	//mBrushColorCode = mBrushColor.getRgb565Code();
}

void Rgb565::setBackgroundColor(Color color)
{
	mBgColor = color;
	mBgColorCode = color.getRgb565Code();
}

void Rgb565::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mBgColor.setColor(red, green, blue);
	mBgColorCode = mBgColor.getRgb565Code();
}
*/
#endif


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

#include <drv/peripheral.h>

#include <gui/Bmp565Brush.h>
#include <yss/string.h>

Bmp565Brush::Bmp565Brush(uint32_t pointSize)
{
	mBufferSize = pointSize * 2;
	mFrameBuffer = new uint16_t[pointSize];

	mBmp565.width = 0;
	mBmp565.height = 0;
	mBmp565.data = (uint8_t *)mFrameBuffer;
	mBmp565.type = 0;
	mOkFlag = false;
}

Bmp565Brush::~Bmp565Brush(void)
{
	if (mFrameBuffer)
		delete mFrameBuffer;
}

void Bmp565Brush::setSize(uint16_t width, uint16_t height)
{
	if (mBufferSize < width * height * 2)
	{
		mOkFlag = false;
		return;
	}

	mOkFlag = true;
	mBmp565.width = width;
	mBmp565.height = height;
	Brush::setSize(Size{width, height});
}

void Bmp565Brush::setSize(Size size)
{
	if (mBufferSize < size.width * size.height * 2)
	{
		mOkFlag = false;
		return;
	}

	mOkFlag = true;
	mBmp565.width = size.width;
	mBmp565.height = size.height;
	Brush::setSize(size);
}

uint32_t Bmp565Brush::getBufferSize(void)
{
	return mBufferSize;
}

void Bmp565Brush::drawDot(int16_t x, int16_t y, uint16_t color)
{
	if (mOkFlag)
		mFrameBuffer[y * mSize.width + x] = color;
}

void Bmp565Brush::drawDot(int16_t x, int16_t y)
{
	if (mOkFlag)
		mFrameBuffer[y * mSize.width + x] = mBrushColor.halfword;
}

void Bmp565Brush::drawDot(int16_t x, int16_t y, uint32_t color)
{
}

void Bmp565Brush::drawFontDot(int16_t x, int16_t y, uint8_t color)
{
	if (mOkFlag)
		mFrameBuffer[y * mSize.width + x] = color;
}

void Bmp565Brush::eraseDot(Position pos)
{
	if (mOkFlag)
		mFrameBuffer[pos.y * mSize.width + pos.x] = mBgColor.halfword;
}

void Bmp565Brush::setBrushColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	RGB565_union color;
	color.color.red = red >> 3;
	color.color.green = green >> 2;
	color.color.blue = blue >> 3;
	mBrushColor.halfword = color.halfword;
}

void Bmp565Brush::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mFontColor.setFontColor(red, green, blue);
	mFontColor.calculate();
}

void Bmp565Brush::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 2;
	mBgColor.color.blue = blue >> 3;
	mFontColor.setBgColor(red, green, blue);
	mFontColor.calculate();
}

uint8_t Bmp565Brush::drawChar(Position pos, uint32_t utf8)
{
	if (!mOkFlag)
		return 0;

	int32_t buf;
	uint16_t *colorTable = mFontColor.getColorTable();

	if (mFont.setChar(utf8))
		return 0;

	YssFontInfo *fontInfo = mFont.getFontInfo();
	uint8_t *fontFb = mFont.getFrameBuffer(), color;
	int32_t  index = 0;
	uint16_t width = fontInfo->width, height = fontInfo->height, offset = 0;
	int16_t xs = pos.x, ys = pos.y + (int8_t)fontInfo->ypos;

	if (xs + width > mSize.width)
	{
		width = mSize.width - xs;
		offset = fontInfo->width - width;
	}
	if (ys + height > mSize.height)
		height = mSize.height - ys;

	width += xs;
	height += ys;

	for (int32_t  y = ys; y < height; y++)
	{
		for (int32_t  x = xs; x < width; x++, index++)
		{
			if (index % 2 == 0)
			{
				color = fontFb[index / 2] & 0x0f;
				drawDot(x, y, colorTable[color]);
			}
			else
			{
				color = (fontFb[index / 2] >> 4) & 0x0f;
				drawDot(x, y, colorTable[color]);
			}
		}
		index += offset;
	}

	return fontInfo->width;
}

void Bmp565Brush::fillRect(Position pos, Size size)
{
	if (!mOkFlag)
		return;

	int16_t sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;
	uint16_t *des = mFrameBuffer;
	uint16_t width;

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	width = (ex - sx + 1) * 2;
	des += sx + sy * mSize.width;
	for (int16_t y = sy; y <= ey; y++)
	{
		memsethw(des, mBrushColor.halfword, width);
		des += mSize.width;
	}
}

void Bmp565Brush::fillRect(Position p1, Position p2)
{
	if (!mOkFlag)
		return;

	int16_t sx, ex, sy, ey;
	uint16_t width;
	uint16_t *des = mFrameBuffer;

	if (p1.x < p2.x)
	{
		sx = p1.x;
		ex = p2.x;
	}
	else
	{
		sx = p2.x;
		ex = p1.x;
	}

	if (p1.y < p2.y)
	{
		sy = p1.y;
		ey = p2.y;
	}
	else
	{
		sy = p2.y;
		ey = p1.y;
	}

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	width = (ex - sx + 1) * 2;
	des += sx + sy * mSize.width;
	for (int16_t y = sy; y <= ey; y++)
	{
		memsethw(des, mBrushColor.halfword, width);
		des += mSize.width;
	}
}

void Bmp565Brush::clear(void)
{
	if (!mOkFlag)
		return;

	memsethw(mFrameBuffer, mBgColor.halfword, mSize.width * mSize.height * 2);
}

const Bmp565 *Bmp565Brush::getBmp565(void)
{
	return &mBmp565;
}

void Bmp565Brush::drawStringToCenterAligned(const char *str)
{
	if (!mOkFlag)
		return;

	Position pos;
	Size size = calculateStringSize(str);

	pos.x = (mSize.width - size.width) / 2;
	if (pos.x < 0)
		pos.x = 0;
	pos.y = (mSize.height - size.height) / 2;
	if (pos.y < 0)
		pos.y = 0;
	Brush::drawString(pos, str);
}

Bmp565BrushSwappedByte::Bmp565BrushSwappedByte(uint32_t pointSize) : Bmp565Brush(pointSize)
{

}

void Bmp565BrushSwappedByte::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	RGB565_union color;
	uint8_t buf;

	color.color.red = red >> 3;
	color.color.green = green >> 2;
	color.color.blue = blue >> 3;

	buf = color.byte[0];
	color.byte[0] = color.byte[1];
	color.byte[1] = buf;

	mBrushColor.halfword = color.halfword;
}

void Bmp565BrushSwappedByte::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mFontColor.setFontColor(red, green, blue);
	mFontColor.calculateSwappedByte();
}

void Bmp565BrushSwappedByte::setBgColor(uint8_t red, uint8_t green, uint8_t blue)
{
	RGB565_union color;
	uint8_t buf;

	color.color.red = red >> 3;
	color.color.green = green >> 2;
	color.color.blue = blue >> 3;

	buf = color.byte[0];
	color.byte[0] = color.byte[1];
	color.byte[1] = buf;

	mBgColor.halfword = color.halfword;
	mFontColor.setBgColor(red, green, blue);
	mFontColor.calculateSwappedByte();
}


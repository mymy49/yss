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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.08.24 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/mcu.h>

#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE)

#include <gui/Bmp565Brush.h>
#include <yss/stdlib.h>

Bmp565Brush::Bmp565Brush(unsigned int pointSize)
{
	mBufferSize = pointSize * 2;
	mFrameBuffer = new unsigned short[pointSize];

	mBmp565.width = 0;
	mBmp565.height = 0;
	mBmp565.data = (unsigned char *)mFrameBuffer;
	mBmp565.type = 0;
	mOkFlag = false;
}

Bmp565Brush::~Bmp565Brush(void)
{
	if (mFrameBuffer)
		delete mFrameBuffer;
}

void Bmp565Brush::setSize(unsigned short width, unsigned short height)
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

void Bmp565Brush::drawDot(signed short x, signed short y, unsigned short color)
{
	if (mOkFlag)
		mFrameBuffer[y * mSize.width + x] = color;
}

void Bmp565Brush::drawDot(signed short x, signed short y)
{
	if (mOkFlag)
		mFrameBuffer[y * mSize.width + x] = mBrushColor.halfword;
}

void Bmp565Brush::drawDot(signed short x, signed short y, unsigned int color)
{
}

void Bmp565Brush::drawFontDot(signed short x, signed short y, unsigned char color)
{
	if (mOkFlag)
		mFrameBuffer[y * mSize.width + x] = color;
}

void Bmp565Brush::eraseDot(Pos pos)
{
	if (mOkFlag)
		mFrameBuffer[pos.y * mSize.width + pos.x] = mBgColor.halfword;
}

void Bmp565Brush::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	RGB565_union color;
	color.color.red = red >> 3;
	color.color.green = green >> 2;
	color.color.blue = blue >> 3;
	mBrushColor.halfword = color.halfword;
}

void Bmp565Brush::setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	mFontColor.setFontColor(red, green, blue);
	mFontColor.calculate();
}

void Bmp565Brush::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 2;
	mBgColor.color.blue = blue >> 3;
	mFontColor.setBgColor(red, green, blue);
	mFontColor.calculate();
}

unsigned char Bmp565Brush::drawChar(Pos pos, unsigned int utf8)
{
	if (!mOkFlag)
		return 0;

	signed int buf;
	unsigned short *colorTable = mFontColor.getColorTable();

	if (mFont.setChar(utf8))
		return 0;

	YssFontInfo *fontInfo = mFont.getFontInfo();
	unsigned char *fontFb = mFont.getFrameBuffer(), color;
	int index = 0;
	unsigned short width = fontInfo->width, height = fontInfo->height, offset = 0;
	signed short xs = pos.x, ys = pos.y + (signed char)fontInfo->ypos;

	if (xs + width > mSize.width)
	{
		width = mSize.width - xs;
		offset = fontInfo->width - width;
	}
	if (ys + height > mSize.height)
		height = mSize.height - ys;

	width += xs;
	height += ys;

	for (int y = ys; y < height; y++)
	{
		for (int x = xs; x < width; x++, index++)
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

void Bmp565Brush::fillRect(Pos pos, Size size)
{
	if (!mOkFlag)
		return;

	signed short sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;
	unsigned short *des = mFrameBuffer;
	unsigned short width;

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	width = (ex - sx + 1) * 2;
	des += sx + sy * mSize.width;
	for (signed short y = sy; y <= ey; y++)
	{
		memsethw(des, mBrushColor.halfword, width);
		des += mSize.width;
	}
}

void Bmp565Brush::fillRect(Pos p1, Pos p2)
{
	if (!mOkFlag)
		return;

	signed short sx, ex, sy, ey;
	unsigned short width;
	unsigned short *des = mFrameBuffer;

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
	for (signed short y = sy; y <= ey; y++)
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

Bmp565 *Bmp565Brush::getBmp565(void)
{
	return &mBmp565;
}

void Bmp565Brush::drawStringToCenterAligned(const char *str)
{
	if (!mOkFlag)
		return;

	Pos pos;
	Size size = calculateStringSize(str);

	pos.x = (mSize.width - size.width) / 2;
	if (pos.x < 0)
		pos.x = 0;
	pos.y = (mSize.height - size.height) / 2;
	if (pos.y < 0)
		pos.y = 0;
	Brush::drawString(pos, str);
}

Bmp565BrushSwappedByte::Bmp565BrushSwappedByte(unsigned int pointSize) : Bmp565Brush(pointSize)
{

}

void Bmp565BrushSwappedByte::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	RGB565_union color;
	unsigned char buf;

	color.color.red = red >> 3;
	color.color.green = green >> 2;
	color.color.blue = blue >> 3;

	buf = color.byte[0];
	color.byte[0] = color.byte[1];
	color.byte[1] = buf;

	mBrushColor.halfword = color.halfword;
}

void Bmp565BrushSwappedByte::setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	mFontColor.setFontColor(red, green, blue);
	mFontColor.calculateSwappedByte();
}

void Bmp565BrushSwappedByte::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	RGB565_union color;
	unsigned char buf;

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

#endif
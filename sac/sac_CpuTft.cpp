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

#include <config.h>
#include <sac/CpuTft.h>
#include <yss/malloc.h>
#include <yss/string.h>

namespace sac
{
CpuTft::CpuTft(void)
{
	mBrushColor.halfword = 0xFFFF;
	mBgColor.halfword = 0x0000;
}

void CpuTft::lock(void)
{
	mMutex.lock();
}

void CpuTft::unlock(void)
{
	mMutex.unlock();
}

void CpuTft::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mBrushColor.color.red = red >> 3;
	mBrushColor.color.green = green >> 2;
	mBrushColor.color.blue = blue >> 3;
}

void CpuTft::setBgColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mFontColor.setBgColor(red, green, blue);
	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 2;
	mBgColor.color.blue = blue >> 3;
}

void CpuTft::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mFontColor.setFontColor(red, green, blue);
}

uint8_t CpuTft::drawChar(Position pos, uint32_t utf8)
{
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

void CpuTft::fillRect(Position p1, Position p2)
{
	int16_t buf;

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

	fillRect(p1, Size{(uint16_t)(p2.x - p1.x), (uint16_t)(p2.y - p1.y)});
}

void CpuTft::fillRect(Position pos, Size size)
{
	int32_t  loop = size.height, width = size.width;

	for (int32_t  i = 0; i < loop; i++)
	{
		drawDots(pos.x, pos.y + i, mBrushColor.halfword, width);
	}
}

void CpuTft::clear(void)
{
	int32_t  loop = mSize.height, width = mSize.width;

	for (int32_t  i = 0; i < loop; i++)
	{
		drawDots(0, i, mBgColor.halfword, width);
	}
}

void CpuTft::drawBmp(Position pos, const Bmp565 *image)
{
	uint16_t *fb = (uint16_t *)image->data;
	uint16_t width = image->width;
	uint16_t height = image->height, offset = 0;
	int16_t xs = pos.x, ys = pos.y;

	if (xs + width > mSize.width)
	{
		offset = (xs + width) - mSize.width;
		width = mSize.width - xs;
	}
	if (ys + height > mSize.height)
		height = mSize.height - ys;

	height += ys;

	for (int16_t y = ys; y < height; y++)
	{
		drawDots(xs, y, fb, width);
		fb += width + offset;
	}
}

void CpuTft::drawBmp(Position pos, const Bmp565 &image)
{
	drawBmp(pos, &image);
}

}
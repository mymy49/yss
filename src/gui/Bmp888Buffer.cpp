////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if USE_GUI

#include <drv/peripheral.h>
#include <gui/Bmp888Buffer.h>
#include <std_ext/string.h>

Bmp888Buffer::Bmp888Buffer(uint32_t pointSize)
{
	mBufferSize = pointSize * 3;
	mFrameBuffer = new uint8_t[mBufferSize];

	mBmp888.width = 0;
	mBmp888.height = 0;
	mBmp888.data = mFrameBuffer;
	mBmp888.type = 1;
}

Bmp888Buffer::~Bmp888Buffer(void)
{
	if (mFrameBuffer)
		delete mFrameBuffer;
}

void Bmp888Buffer::setSize(uint16_t width, uint16_t height)
{
	if (mBufferSize < width * height * 3)
	{
		return;
	}

	mOkFlag = true;
	mBmp888.width = width;
	mBmp888.height = height;
	Brush::setSize(Size{width, height});
}

void Bmp888Buffer::setSize(Size size)
{
	mBmp888.width = size.width;
	mBmp888.height = size.height;
	Brush::setSize(size);
}

uint32_t Bmp888Buffer::getBufferSize(void)
{
	return mBufferSize;
}

void Bmp888Buffer::drawDot(int16_t x, int16_t y)
{
	uint32_t offset = y * mSize.width * 3 + x * 3;
	uint8_t *des = &mFrameBuffer[offset];
	uint32_t color = mBrushColorCode;
	uint8_t *src = (uint8_t*)&color;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

void Bmp888Buffer::drawDot(int16_t x, int16_t y, Color color)
{
	uint8_t *des = &mFrameBuffer[y * mSize.width * 3 + x * 3];
	uint32_t buf = color.getRgb888Code();
	uint8_t *src = (uint8_t*)&buf;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

void Bmp888Buffer::drawDot(int16_t x, int16_t y, uint32_t color)
{
	uint8_t *des = &mFrameBuffer[y * mSize.width * 3 + x * 3];
	uint8_t *src = (uint8_t*)&color;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

void Bmp888Buffer::eraseDot(Position pos)
{
	uint8_t *des = &mFrameBuffer[pos.y * mSize.width * 3 + pos.x * 3];
	uint32_t color = mBgColor.getRgb888Code();
	uint8_t *src = (uint8_t*)&color;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

uint8_t Bmp888Buffer::drawChar(Position pos, uint32_t utf8)
{
	int32_t buf;
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
				drawDot(x, y, mFontColorTable[color]);
			}
			else
			{
				color = (fontFb[index / 2] >> 4) & 0x0f;
				drawDot(x, y, mFontColorTable[color]);
			}
		}
		index += offset;
	}

	return fontInfo->width;
}

void Bmp888Buffer::fillRect(Position pos, Size size)
{
	int16_t sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;
	uint32_t offset;
	uint8_t *des = (uint8_t*)mFrameBuffer;

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	des += sx * 3 + sy * mSize.width * 3;
	offset = mSize.width * 3;
	for (int16_t y = sy; y <= ey; y++)
	{
		copyRgb888DotPattern(des, mBrushColorCode, size.width);
		des += offset;
	}
}

void Bmp888Buffer::fillRect(Position p1, Position p2)
{
	int16_t sx, ex, sy, ey;
	uint8_t *des = mFrameBuffer;

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

	des += sx * 3 + sy * mSize.width * 3;
	for (int16_t y = sy; y <= ey; y++)
	{
		copyRgb888DotPattern(des, mBrushColorCode, mSize.width);
		des += mSize.width * 3;
	}
}

void Bmp888Buffer::clear(void)
{
	if (!mOkFlag)
		return;

	copyRgb888DotPattern(mFrameBuffer, mBgColor.getRgb888Code(), mSize.width * mSize.height);
}

Bmp888 *Bmp888Buffer::getBmp888(void)
{
	return &mBmp888;
}

void Bmp888Buffer::drawStringToCenterAligned(const char *str)
{
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

void Bmp888Buffer::setBrushColor(Color color)
{
	mBrushColor = color;
	mBrushColorCode = color.getRgb888Code();
}

void Bmp888Buffer::setBrushColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mBrushColor.setColor(red, green, blue);
	mBrushColorCode = mBrushColor.getRgb888Code();
}

#endif


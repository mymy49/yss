/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI == true

#include <gui/BrushRgb888.h>
#include <gui/Bmp888.h>

BrushRgb888::BrushRgb888(void)
{
	enableMemoryAlloc(false);
	setColorMode(COLOR_MODE_RGB888);
}

BrushRgb888::~BrushRgb888(void)
{
}

void BrushRgb888::drawDot(int16_t x, int16_t y)
{
	uint8_t *des = (uint8_t *)mFrameBuffer, *src = (uint8_t *)&mBrushColorCode;

	des += (mSize.width * y + x) * 3;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

void BrushRgb888::drawDot(int16_t x, int16_t y, Color color)
{
	uint32_t code = color.getRgb888Code();
	uint8_t *des = (uint8_t *)mFrameBuffer, *src = (uint8_t *)&code;

	des += (mSize.width * y + x) * 3;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

void BrushRgb888::drawDot(int16_t x, int16_t y, uint32_t color)
{
	uint8_t *des = &((uint8_t*)mFrameBuffer)[(y * mSize.width + x) * 3];
	uint8_t *src = (uint8_t*)&color;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

void BrushRgb888::fillRectBase(Position_t pos, Size_t size, uint32_t color)
{
	int16_t sx = pos.x, ex = pos.x + size.width - 1, sy = pos.y, ey = pos.y + size.height - 1;
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
		copyRgb888DotPattern(des, color, size.width);
		des += offset;
	}
}

#endif
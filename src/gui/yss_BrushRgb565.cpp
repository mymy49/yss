/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI == true

#include <gui/BrushRgb565.h>
#include <gui/Bmp565.h>
#include <std_ext/string.h>
#include <yss.h>

#define PI (float)3.14159265358979323846

BrushRgb565::BrushRgb565(void)
{
	enableMemoryAlloc(false);
	setColorMode(COLOR_MODE_RGB565);
}

BrushRgb565::~BrushRgb565(void)
{
}

void BrushRgb565::drawDot(int16_t x, int16_t y)
{
	uint16_t *des = (uint16_t *)mFrameBuffer, *src = (uint16_t *)&mBrushColorCode;

	des[mSize.width * y + x] = *src;
} 

void BrushRgb565::drawDot(int16_t x, int16_t y, Color color)
{
	uint16_t code = color.getRgb565Code();
	uint16_t *des = (uint16_t *)mFrameBuffer;

	des[mSize.width * y + x] = code;
}

void BrushRgb565::drawDot(int16_t x, int16_t y, uint32_t color)
{
	uint16_t *des = (uint16_t *)mFrameBuffer;

	des[mSize.width * y + x] = (uint16_t)color;
}

void BrushRgb565::fillRectBase(Position_t pos, Size_t size, uint32_t color)
{
	if(mSize.width == size.width)
	{
		uint16_t *des = (uint16_t*)mFrameBuffer;
		des += pos.y * mSize.width;

#if defined(YSS_MEMDMA_SUPPORT)
		memsethwd(des, color, size.width * size.height);
#else
		memsethw(des, color, size.width * size.height * 2);
#endif
	}
	else
	{
		int16_t sx = pos.x, ex = pos.x + size.width - 1, sy = pos.y, ey = pos.y + size.height - 1;
		uint32_t offset;
		uint16_t *des = (uint16_t*)mFrameBuffer;

		if (ey > mSize.height - 1)
			ey = mSize.height - 1;
		if (ex > mSize.width - 1)
			ex = mSize.width - 1;

		des += sx + sy * mSize.width;
		offset = mSize.width;

		for (int16_t y = sy; y <= ey; y++)
		{
#if defined(YSS_MEMDMA_SUPPORT)
			memsethwd(des, color, size.width);
#else
			memsethw(des, color, size.width * 2);
#endif
			des += offset;
		}
	}
}

#endif
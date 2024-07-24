/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <gui/Rgb888.h>

Rgb888::Rgb888(void)
{
	enableMemoryAlloc();
	setColorMode(COLOR_MODE_RGB888);
}

Rgb888::~Rgb888(void)
{
	
}

void Rgb888::drawDot(int16_t x, int16_t y)
{
	uint8_t *des = (uint8_t *)mFrameBuffer, *src = (uint8_t *)&mBrushColorCode;

	des += (mSize.width * y + x) * 3;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

void Rgb888::drawDot(int16_t x, int16_t y, Color color)
{
	uint32_t code = color.getRgb888Code();
	uint8_t *des = (uint8_t *)mFrameBuffer, *src = (uint8_t *)&code;

	des += (mSize.width * y + x) * 3;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

void Rgb888::drawDot(int16_t x, int16_t y, uint32_t color)
{
	uint8_t *des = &((uint8_t*)mFrameBuffer)[(y * mSize.width + x) * 3];
	uint8_t *src = (uint8_t*)&color;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
}

#endif
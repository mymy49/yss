/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <gui/Argb1555.h>

Argb1555::Argb1555(void)
{
	enableMemoryAlloc();
	setColorMode(COLOR_MODE_ARGB1555);
}

Argb1555::~Argb1555(void)
{
	
}

void Argb1555::drawDot(int16_t x, int16_t y)
{
	uint16_t *des = (uint16_t*)mFrameBuffer;
	des[mSize.width * y + x] = (uint16_t)mBrushColorCode;
}

void Argb1555::drawDot(int16_t x, int16_t y, Color color)
{
	uint16_t *des = (uint16_t*)mFrameBuffer;
	des[mSize.width * y + x] = (uint16_t)color.getArgb1555Code();
}

void Argb1555::drawDot(int16_t x, int16_t y, uint32_t color)
{
	uint16_t *des = (uint16_t*)mFrameBuffer;
	des[mSize.width * y + x] = (uint16_t)color;
}

#endif
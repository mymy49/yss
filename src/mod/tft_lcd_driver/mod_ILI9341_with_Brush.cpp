/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI == true

#include <mod/tft_lcd_driver/ILI9341_with_Brush.h>

ILI9341_with_Brush::ILI9341_with_Brush(void)
{
}

void ILI9341_with_Brush::drawDot(int16_t x, int16_t y)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &mBrushColorCode, 2);
		disable();
	}
}

void ILI9341_with_Brush::drawDot(int16_t x, int16_t y, uint32_t color)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &color, 2);
		disable();
	}
}

void ILI9341_with_Brush::drawDot(int16_t x, int16_t y, Color color)
{
	uint16_t buf = color.getRgb565Code();

	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &buf, 2);
		disable();
	}
}

void ILI9341_with_Brush::updateLcdSize(void)
{
	Size_t size;

	if(mRotateFlag)
	{
		size.width = getLcdSize().height;
		size.height = getLcdSize().width;
		setSize(size);
	}
	else
	{
		setSize(getLcdSize());
	}
}

void ILI9341_with_Brush::drawBitmapBase(Position_t pos, const Bitmap_t &bitmap)
{
	// RGB565가 아니면 리턴
	if (bitmap.type != 0)
		return;
	
	enable();
	setWindows(pos.x, pos.y, bitmap.width, bitmap.height);
	sendCmd(MEMORY_WRITE, bitmap.data, bitmap.width * bitmap.height * 2);
	disable();
}

void ILI9341_with_Brush::setBmp565Buffer(Bmp565Buffer &obj)
{
	mBmpBrush = &obj;
	mBmpBufferSize = obj.getBufferSize();
}

void ILI9341_with_Brush::fillRectBase(Position_t pos, Size_t size, uint32_t color)
{
	if(!mBmpBrush)
		return;

	uint32_t width, height, loop, remain;
	Bitmap_t *bitmap;
	Color bgColor;

	width = size.width;
	height = (mBmpBufferSize / 2) / width;
	loop = size.height / height;
	remain = size.height % height;

	mBmpBrush->setSize(width, height);

	bgColor.setColorCodeRgb565(color);
	mBmpBrush->setBackgroundColor(bgColor);
	mBmpBrush->clear();

	bitmap = mBmpBrush->getBitmap();

	for(uint32_t i=0;i<loop;i++)
	{
		drawBitmap(pos, bitmap);
		pos.y += height;
	}

	if(remain)
	{
		mBmpBrush->setSize(width, remain);
		drawBitmap(pos, bitmap);
	}
}

#endif


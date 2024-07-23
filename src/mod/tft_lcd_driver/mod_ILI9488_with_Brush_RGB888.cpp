/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI == true

#include <mod/tft_lcd_driver/ILI9488_with_Brush_RGB888.h>

ILI9488_with_Brush_RGB888::ILI9488_with_Brush_RGB888(void)
{
}

void ILI9488_with_Brush_RGB888::setBmp888Buffer(Bmp888Buffer &obj)
{
	mBmp888Brush = &obj;
	mBmp888BufferSize = obj.getBufferSize();
}

void ILI9488_with_Brush_RGB888::drawDot(int16_t x, int16_t y)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &mBrushColorCode, 2);
		disable();
	}
}

void ILI9488_with_Brush_RGB888::drawDot(int16_t x, int16_t y, uint32_t color)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &color, 3);
		disable();
	}
}

void ILI9488_with_Brush_RGB888::drawDot(int16_t x, int16_t y, Color color)
{
	uint32_t buf = color.getRgb888Code();

	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &buf, 3);
		disable();
	}
}

void ILI9488_with_Brush_RGB888::updateLcdSize(void)
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

void ILI9488_with_Brush_RGB888::drawBitmapBase(Position_t pos, const Bitmap_t &bitmap)
{
	// RGB888이 아니면 리턴
	if (bitmap.type != 1)
		return;
	
	enable();
	setWindows(pos.x, pos.y, bitmap.width, bitmap.height);
	sendCmd(MEMORY_WRITE, bitmap.data, bitmap.width * bitmap.height * 3);
	disable();
}

void ILI9488_with_Brush_RGB888::fillRectBase(Position_t pos, Size_t size, uint32_t color)
{
	if(!mBmp888Brush)
		return;

	uint32_t width, height, loop, remain;
	Bitmap_t *bitmap;
	Color bgColor;

	width = size.width;
	height = (mBmp888BufferSize / 3) / width;
	loop = size.height / height;
	remain = size.height % height;

	mBmp888Brush->setSize(width, height);

	bgColor.setColorCodeRgb888(color);
	mBmp888Brush->setBackgroundColor(bgColor);
	mBmp888Brush->clear();

	bitmap = mBmp888Brush->getBitmap();

	for(uint32_t i=0;i<loop;i++)
	{
		drawBitmap(pos, bitmap);
		pos.y += height;
	}

	if(remain)
	{
		mBmp888Brush->setSize(width, remain);
		drawBitmap(pos, bitmap);
	}
}

#endif


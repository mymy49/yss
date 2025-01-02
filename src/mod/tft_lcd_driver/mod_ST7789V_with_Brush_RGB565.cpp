/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI == true

#include <mod/tft_lcd_driver/ST7789V_with_Brush_RGB565.h>

ST7789V_with_Brush_RGB565::ST7789V_with_Brush_RGB565(void)
{
	mRotateFlag = false;
	mBmp565Buffer = 0;
	mBmp565BufferSize = 0;
}

void ST7789V_with_Brush_RGB565::drawDot(int16_t x, int16_t y)
{
	enable();
	setWindows(x, y);
	sendCmd(MEMORY_WRITE, &mBrushColorCode, 3);
	disable();
}

void ST7789V_with_Brush_RGB565::drawDot(int16_t x, int16_t y, uint32_t color)
{
	enable();
	setWindows(x, y);
	sendCmd(MEMORY_WRITE, &color, 3);
	disable();
}

void ST7789V_with_Brush_RGB565::drawDot(int16_t x, int16_t y, Color color)
{
	uint32_t buf = color.getRgb888Code();

	enable();
	setWindows(x, y);
	sendCmd(MEMORY_WRITE, &buf, 3);
	disable();
}

void ST7789V_with_Brush_RGB565::setBmp565Buffer(Bmp565Buffer &obj)
{
	mBmp565Buffer = &obj;
	mBmp565BufferSize = obj.getBufferSize();
}

void ST7789V_with_Brush_RGB565::fillRectBase(Position_t pos, Size_t size, uint32_t color)
{
	if(!mBmp565Buffer)
		return;

	uint32_t width, height, loop, remain;
	Bitmap_t *bitmap;
	Color bgColor;

	width = size.width;
	height = (mBmp565BufferSize / 2) / width;
	loop = size.height / height;
	remain = size.height % height;

	mBmp565Buffer->setSize(width, height);

	bgColor.setColorCodeRgb565(color);
	mBmp565Buffer->setBackgroundColor(bgColor);
	mBmp565Buffer->clear();

	bitmap = mBmp565Buffer->getBitmap();

	for(uint32_t i=0;i<loop;i++)
	{
		drawBitmap(pos, bitmap);
		pos.y += height;
	}

	if(remain)
	{
		mBmp565Buffer->setSize(width, remain);
		drawBitmap(pos, bitmap);
	}
}

void ST7789V_with_Brush_RGB565::drawBitmapBase(Position_t pos, const Bitmap_t &bitmap)
{
	// RGB888이 아니면 리턴
	if (bitmap.type != 0)
		return;
	
	enable();
	setWindows(pos.x, pos.y, bitmap.width, bitmap.height);
	sendCmd(MEMORY_WRITE, bitmap.data, bitmap.width * bitmap.height * 2);
	disable();
}

void ST7789V_with_Brush_RGB565::updateLcdSize(void)
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

#endif


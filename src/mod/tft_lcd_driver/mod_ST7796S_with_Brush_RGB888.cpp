/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI == true

#include <mod/tft_lcd_driver/ST7796S_with_Brush_RGB888.h>

ST7796S_with_Brush_RGB888::ST7796S_with_Brush_RGB888(void)
{
	mRotateFlag = false;
	mBmp888Buffer = 0;
	mBmp888BufferSize = 0;
}

void ST7796S_with_Brush_RGB888::drawDot(int16_t x, int16_t y)
{
	enable();
	setWindows(x, y);
	sendCmd(MEMORY_WRITE, &mBrushColorCode, 3);
	disable();
}

void ST7796S_with_Brush_RGB888::drawDot(int16_t x, int16_t y, uint32_t color)
{
	enable();
	setWindows(x, y);
	sendCmd(MEMORY_WRITE, &color, 3);
	disable();
}

void ST7796S_with_Brush_RGB888::drawDot(int16_t x, int16_t y, Color color)
{
	uint32_t buf = color.getRgb888Code();

	enable();
	setWindows(x, y);
	sendCmd(MEMORY_WRITE, &buf, 3);
	disable();
}

void ST7796S_with_Brush_RGB888::eraseDot(Position_t pos)
{
	if (pos.y < mSize.height && pos.x < mSize.width)
	{
		enable();
		setWindows(pos.x, pos.y);
		sendCmd(MEMORY_WRITE, &mBgColorCode, 3);
		disable();
	}
}

void ST7796S_with_Brush_RGB888::drawBmp(Position_t pos, const Bmp888 *image)
{
	// RGB888이 아니면 리턴
	if (image->type != 1)
		return;
	
	enable();
	setWindows(pos.x, pos.y, image->width, image->height);
	sendCmd(MEMORY_WRITE, image->data, image->width * image->height * 3);
	disable();
}

void ST7796S_with_Brush_RGB888::setBmp888Buffer(Bmp888Buffer &obj)
{
	mBmp888Buffer = &obj;
	mBmp888BufferSize = obj.getBufferSize();
}

void ST7796S_with_Brush_RGB888::clear(void)
{
	if(!mBmp888Buffer)
		return;
	uint32_t width, height, loop, lastPos = 0;

	if(mRotateFlag)
	{
		width = mSize.height;
		height = (mBmp888BufferSize / 3) / width;
		loop = mSize.width / height;
		if(mSize.width % height)
		{
			lastPos = mSize.width - 1 - height;
		}
	}
	else
	{
		width = mSize.width;
		height = (mBmp888BufferSize / 3) / width;
		loop = mSize.height / height;
		if(mSize.height % height)
		{
			lastPos = mSize.height - 1 - height;
		}
	}
	
	mBmp888Buffer->setSize(width, height);
	mBmp888Buffer->setBackgroundColor(mBgColor);
	mBmp888Buffer->clear();
	
	for(uint32_t  i=0;i<loop;i++)
	{
		drawBitmap(Position_t{0, (int16_t)(height * i)}, mBmp888Buffer->getBitmap());
	}

	if(lastPos)
		drawBitmap(Position_t{0, (int16_t)lastPos}, mBmp888Buffer->getBitmap());
}

void ST7796S_with_Brush_RGB888::fillRect(Position_t p1, Position_t p2)
{
	if(!mBmp888Buffer)
		return;
	uint32_t width, height, loop, bufHeight;
	Position_t pos;

	if(p1.x < p2.x)
	{
		width = p2.x - p1.x;
		pos.x = p1.x;
	}
	else if(p1.x > p2.x)
	{
		width = p1.x - p2.x;
		pos.x = p2.x;
	}
	else
		return;

	if(p1.y < p2.y)
	{
		height = p2.y - p1.y;
		pos.y = p1.y;
	}
	else if(p1.y > p2.y)
	{
		height = p1.y - p2.y;
		pos.y = p2.y;
	}
	else
		return;

	bufHeight = (mBmp888BufferSize / 3) / width;
	loop = height / bufHeight;
	if(loop)
		mBmp888Buffer->setSize(width, bufHeight);
	else
		mBmp888Buffer->setSize(width, height);

#warning "업데이트 필요"
	//mBmp888Buffer->setBackgroundColor(mBrushColor);
	//mBmp888Buffer->clear();
	
	for(uint32_t  i=0;i<loop;i++)
	{
		drawBitmap(pos, mBmp888Buffer->getBitmap());
		pos.y += bufHeight;
	}
	
	height -= loop * bufHeight;
	if(height)
	{
		mBmp888Buffer->setSize(width, height);
		drawBitmap(Position_t{pos.x, pos.y}, mBmp888Buffer->getBitmap());
	}
}

void ST7796S_with_Brush_RGB888::fillRect(Position_t pos, Size_t size)
{
	fillRect(pos, Position_t{(int16_t)(pos.x + size.width), (int16_t)(pos.y + size.height)});
}

void ST7796S_with_Brush_RGB888::setBrushColor(Color color)
{
	mBrushColorCode = color.getRgb888Code();
}

void ST7796S_with_Brush_RGB888::setBrushColor(uint8_t red, uint8_t green, uint8_t blue)
{
	Color color(red, green, blue);

	mBrushColorCode = color.getRgb888Code();
}

#endif


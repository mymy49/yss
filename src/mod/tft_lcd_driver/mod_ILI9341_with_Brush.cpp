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

#include <mod/tft_lcd_driver/ILI9341_with_Brush.h>

ILI9341_with_Brush::ILI9341_with_Brush(void)
{
}

void ILI9341_with_Brush::setWindows(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
	uint8_t data[4];
	uint16_t end;

	end = x + width - 1;
	data[0] = x >> 8;
	data[1] = x & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(COLUMN_ADDRESS_SET, data, 4);
	
	end = y + height - 1;
	data[0] = y >> 8;
	data[1] = y & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(PAGE_ADDRESS_SET, data, 4);
}

void ILI9341_with_Brush::setDirection(bool xMirror, bool yMirror, bool rotate)
{
	enable();
	int8_t memAccCtrl[] = {0x00};
	if(rotate)
	{
		memAccCtrl[0] |= 0x20;

		if(xMirror)
			memAccCtrl[0] |= 0x80;
		if(yMirror)
			memAccCtrl[0] |= 0x40;
	}
	else
	{
		if(xMirror)
			memAccCtrl[0] |= 0x40;
		if(yMirror)
			memAccCtrl[0] |= 0x80;
	}

	mRotateFlag = rotate;

	sendCmd(MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));
	disable();
}

void ILI9341_with_Brush::drawDot(int16_t x, int16_t y)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &mBrushColor, 2);
		disable();
	}
}

void ILI9341_with_Brush::drawDot(int16_t x, int16_t y, uint16_t color)
{
}

void ILI9341_with_Brush::drawDot(int16_t x, int16_t y, uint32_t color)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &color, 3);
		disable();
	}
}

void ILI9341_with_Brush::drawFontDot(int16_t x, int16_t y, uint8_t color)
{
}

void ILI9341_with_Brush::eraseDot(Position pos)
{
	if (pos.y < mSize.height && pos.x < mSize.width)
	{
		enable();
		setWindows(pos.x, pos.y);
		sendCmd(MEMORY_WRITE, mBgColor.byte, 2);
		disable();
	}
}

void ILI9341_with_Brush::setBrushColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	RGB565_union color;
	uint8_t buf;

	color.color.red = red >> 3;
	color.color.green = green >> 2;
	color.color.blue = blue >> 3;

	buf = color.byte[0];
	color.byte[0] = color.byte[1];
	color.byte[1] = buf;

	mBrushColor.halfword = color.halfword;
}

void ILI9341_with_Brush::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
}

void ILI9341_with_Brush::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
{
	RGB565_union color;
	uint8_t buf;

	color.color.red = red >> 3;
	color.color.green = green >> 2;
	color.color.blue = blue >> 3;

	buf = color.byte[0];
	color.byte[0] = color.byte[1];
	color.byte[1] = buf;

	mBgColor.halfword = color.halfword;
}

void ILI9341_with_Brush::drawBmp(Position pos, const Bmp565 *image)
{
	// RGB565가 아니면 리턴
	if (image->type != 0)
		return;
	
	enable();
	setWindows(pos.x, pos.y, image->width, image->height);
	sendCmd(MEMORY_WRITE, image->data, image->width * image->height * 2);
	disable();
}

void ILI9341_with_Brush::setBmp565Brush(Bmp565BrushSwappedByte &obj)
{
	mBmpBrush = &obj;
	mBmpBufferSize = obj.getBufferSize();
}

void ILI9341_with_Brush::clear(void)
{
	if(!mBmpBrush)
		return;
	uint32_t width, height, loop, lastPos = 0;

	if(mRotateFlag)
	{
		width = 320;
		height = (mBmpBufferSize / 2) / width;
		loop = 240 / height;
		if(240 % height)
		{
			lastPos = 240 - height;
		}
	}
	else
	{
		width = 240;
		height = (mBmpBufferSize / 2) / width;
		loop = 320 / height;
		if(320 % height)
		{
			lastPos = 320 - height;
		}
	}
	
	mBmpBrush->setSize(width, height);
	mBmpBrush->Bmp565BrushSwappedByte::setBackgroundColor(mBgColor);
	mBmpBrush->clear();
	
	for(int32_t  i=0;i<loop;i++)
	{
		drawBmp(Position{0, (int16_t)(height * i)}, mBmpBrush->getBmp565());
	}

	if(lastPos)
		drawBmp(Position{0, (int16_t)lastPos}, mBmpBrush->getBmp565());
}

void ILI9341_with_Brush::fillRect(Position p1, Position p2)
{
	if(!mBmpBrush)
		return;
	uint32_t width, height, loop, bufHeight, y;
	Position pos;

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
		y = p1.y;
	}
	else if(p1.y > p2.y)
	{
		height = p1.y - p2.y;
		pos.y = p2.y;
		y = p2.y;
	}
	else
		return;

	bufHeight = (mBmpBufferSize / 2) / width;
	loop = height / bufHeight;
	if(loop)
		mBmpBrush->setSize(width, bufHeight);
	else
		mBmpBrush->setSize(width, height);

	mBmpBrush->setBackgroundColor(mBrushColor);
	mBmpBrush->clear();
	
	for(int32_t  i=0;i<loop;i++)
	{
		drawBmp(pos, mBmpBrush->getBmp565());
		pos.y += bufHeight;
	}
	
	height -= loop * bufHeight;
	if(height)
	{
		mBmpBrush->setSize(width, height);
		drawBmp(Position{pos.x, pos.y}, mBmpBrush->getBmp565());
	}
}

void ILI9341_with_Brush::fillRect(Position pos, Size size)
{
	fillRect(pos, Position{(int16_t)(pos.x + size.width), (int16_t)(pos.y + size.height)});
}


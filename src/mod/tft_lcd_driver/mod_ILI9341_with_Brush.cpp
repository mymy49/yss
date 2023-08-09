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
		sendCmd(MEMORY_WRITE, &mBrushColor, 2);
		disable();
	}
}

void ILI9341_with_Brush::drawDot(int16_t x, int16_t y, uint16_t color)
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

void ILI9341_with_Brush::eraseDot(Position pos)
{
	uint16_t buf = mBgColor.getRgb565Code();

	if (pos.y < mSize.height && pos.x < mSize.width)
	{
		enable();
		setWindows(pos.x, pos.y);
		sendCmd(MEMORY_WRITE, &buf, 2);
		disable();
	}
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

void ILI9341_with_Brush::setBmp565Buffer(Bmp565Buffer &obj)
{
	mBmpBrush = &obj;
	mBmpBufferSize = obj.getBufferSize();

	mBmpBrush->setBrushColor(mBrushColor);
	mBmpBrush->setFontColor(mFontColor);
	mBmpBrush->setBackgroundColor(mBgColor);
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
	mBmpBrush->setBackgroundColor(mBgColor);
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

#endif


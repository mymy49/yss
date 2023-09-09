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

#include <mod/tft_lcd_driver/ILI9488_with_Brush_RGB888.h>

ILI9488_with_Brush_RGB888::ILI9488_with_Brush_RGB888(void)
{
}

void ILI9488_with_Brush_RGB888::drawDot(int16_t x, int16_t y)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &mBrushColor, 2);
		disable();
	}
}

void ILI9488_with_Brush_RGB888::drawDot(int16_t x, int16_t y, uint16_t color)
{
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

void ILI9488_with_Brush_RGB888::drawFontDot(int16_t x, int16_t y, uint8_t color)
{
}

void ILI9488_with_Brush_RGB888::eraseDot(Position pos)
{
	uint32_t color = mBgColor.getRgb888Code();
	if (pos.y < mSize.height && pos.x < mSize.width)
	{
		enable();
		setWindows(pos.x, pos.y);
		sendCmd(MEMORY_WRITE, &color, 3);
		disable();
	}
}

void ILI9488_with_Brush_RGB888::drawBmp(Position pos, const Bmp888 *image)
{
	// RGB888이 아니면 리턴
	if (image->type != 1)
		return;
	
	enable();
	setWindows(pos.x, pos.y, image->width, image->height);
	sendCmd(MEMORY_WRITE, image->data, image->width * image->height * 3);
	disable();
}

void ILI9488_with_Brush_RGB888::setBmp888Buffer(Bmp888Buffer &obj)
{
	mBmp888Brush = &obj;
	mBmp888BufferSize = obj.getBufferSize();
}

void ILI9488_with_Brush_RGB888::clear(void)
{
	if(!mBmp888Brush)
		return;
	uint32_t width, height, loop, lastPos = 0;

	if(mRotateFlag)
	{
		width = mSize.height;
		height = (mBmp888BufferSize / 3) / width;
		loop = mSize.width / height;
		if(mSize.width % height)
		{
			lastPos = (mSize.width - 1) - height;
		}
	}
	else
	{
		width = mSize.width;
		height = (mBmp888BufferSize / 3) / width;
		loop = mSize.height / height;
		if(mSize.height % height)
		{
			lastPos = (mSize.height) - height;
		}
	}
	
	mBmp888Brush->setSize(width, height);
	mBmp888Brush->setBackgroundColor(mBgColor);
	mBmp888Brush->clear();
	
	for(int32_t  i=0;i<loop;i++)
	{
		drawBmp(Position{0, (int16_t)(height * i)}, mBmp888Brush->getBmp888());
	}

	if(lastPos)
		drawBmp(Position{0, (int16_t)lastPos}, mBmp888Brush->getBmp888());
}

void ILI9488_with_Brush_RGB888::fillRect(Position p1, Position p2)
{
	if(!mBmp888Brush)
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

	bufHeight = (mBmp888BufferSize / 3) / width;
	loop = height / bufHeight;
	if(loop)
		mBmp888Brush->setSize(width, bufHeight);
	else
		mBmp888Brush->setSize(width, height);

	mBmp888Brush->setBackgroundColor(mBrushColor);
	mBmp888Brush->clear();
	
	for(int32_t  i=0;i<loop;i++)
	{
		drawBmp(pos, mBmp888Brush->getBmp888());
		pos.y += bufHeight;
	}
	
	height -= loop * bufHeight;
	if(height)
	{
		mBmp888Brush->setSize(width, height);
		drawBmp(Position{pos.x, pos.y}, mBmp888Brush->getBmp888());
	}
}

void ILI9488_with_Brush_RGB888::fillRect(Position pos, Size size)
{
	fillRect(pos, Position{(int16_t)(pos.x + size.width), (int16_t)(pos.y + size.height)});
}

#endif


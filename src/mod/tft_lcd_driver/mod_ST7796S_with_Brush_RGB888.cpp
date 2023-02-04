////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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

void ST7796S_with_Brush_RGB888::eraseDot(Position pos)
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

void ST7796S_with_Brush_RGB888::drawBmp(Position pos, const Bmp888 *image)
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
	
	for(int32_t  i=0;i<loop;i++)
	{
		drawBmp(Position{0, (int16_t)(height * i)}, mBmp888Buffer->getBmp888());
	}

	if(lastPos)
		drawBmp(Position{0, (int16_t)lastPos}, mBmp888Buffer->getBmp888());
}

void ST7796S_with_Brush_RGB888::fillRect(Position p1, Position p2)
{
	if(!mBmp888Buffer)
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
		mBmp888Buffer->setSize(width, bufHeight);
	else
		mBmp888Buffer->setSize(width, height);

	mBmp888Buffer->setBackgroundColor(mBrushColor);
	mBmp888Buffer->clear();
	
	for(int32_t  i=0;i<loop;i++)
	{
		drawBmp(pos, mBmp888Buffer->getBmp888());
		pos.y += bufHeight;
	}
	
	height -= loop * bufHeight;
	if(height)
	{
		mBmp888Buffer->setSize(width, height);
		drawBmp(Position{pos.x, pos.y}, mBmp888Buffer->getBmp888());
	}
}

void ST7796S_with_Brush_RGB888::fillRect(Position pos, Size size)
{
	fillRect(pos, Position{(int16_t)(pos.x + size.width), (int16_t)(pos.y + size.height)});
}

void ST7796S_with_Brush_RGB888::setBrushColor(Color color)
{
	mBrushColor = color;
	mBrushColorCode = color.getRgb888Code();
}

void ST7796S_with_Brush_RGB888::setBrushColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mBrushColor.setColor(red, green, blue);
	mBrushColorCode = mBrushColor.getRgb888Code();
}

#endif


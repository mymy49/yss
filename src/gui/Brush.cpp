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

#include <math.h>
#include <yss/gui.h>
#include <gui/Bmp1555.h>
#include <gui/Bmp565.h>
#include <gui/Bmp888.h>

#define PI (float)3.14159265358979323846

Brush::Brush(void)
{
	mSize.height = 0;
	mSize.width = 0;

	mBrushColor.setToWhite();
	mFontColor.setToWhite();
	mBgColor.setToBlack();
}

void Brush::setBrushColor(Color color)
{
	mBrushColor = color;
}

void Brush::setFontColor(Color color)
{
	mFontColor = color;
	updateFontColor();
}

void Brush::setBackgroundColor(Color color)
{
	mBgColor = color;
	updateFontColor();
}

void Brush::setBrushColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mBrushColor.setColor(red, green, blue);
}

void Brush::setFontColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mFontColor.setColor(red, green, blue);
	updateFontColor();
}

void Brush::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mBgColor.setColor(red, green, blue);
	updateFontColor();
}

Color Brush::getBrushColor(void)
{
	return mBrushColor;
}

Color Brush::getFontColor(void)
{
	return mFontColor;
}

Color Brush::getBackgroundColor(void)
{
	return mBgColor;
}

void Brush::drawLine(Position start, Position end)
{
	uint16_t startX = start.x, startY = start.y, endX = end.x, endY = end.y;
	uint16_t buf, lenX, lenY, x, y;
	float slope;

	if (startX > mSize.width || endX > mSize.width || startY > mSize.height || endY > mSize.height)
		return;

	if (startX <= endX && startY <= endY)
	{
		lenX = endX - startX;
		lenY = endY - startY;

		if (lenX > lenY)
		{
			slope = (float)lenY / (float)lenX;
			for (uint16_t i = 0; i <= lenX; i++)
			{
				x = startX + i;
				y = startY + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = startX + slope * (float)i;
				y = startY + i;
				drawDot(x, y);
			}
		}
	}
	else if (startX >= endX && startY <= endY)
	{
		lenX = startX - endX;
		lenY = endY - startY;

		if (lenX > lenY)
		{
			slope = (float)lenY / (float)lenX;
			for (uint16_t i = 0; i <= lenX; i++)
			{
				x = startX - i;
				y = startY + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY * (float)-1;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = startX + slope * (float)i;
				y = startY + i;
				drawDot(x, y);
			}
		}
	}
	else if (startX <= endX && startY >= endY)
	{
		lenX = endX - startX;
		lenY = startY - endY;

		if (lenX > lenY)
		{
			slope = (float)lenY / (float)lenX * (float)-1;
			for (uint16_t i = 0; i <= lenX; i++)
			{
				x = startX + i;
				y = startY + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = startX + slope * (float)i;
				y = startY - i;
				drawDot(x, y);
			}
		}
	}
	else
	{
		startX = end.x;
		endX = start.x;
		startY = end.y;
		endY = start.y;

		lenX = endX - startX;
		lenY = endY - startY;

		if (lenX > lenY)
		{
			slope = (float)lenY / (float)lenX;
			for (uint16_t i = 0; i <= lenX; i++)
			{
				x = startX + i;
				y = startY + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = startX + slope * (float)i;
				y = startY + i;
				drawDot(x, y);
			}
		}
	}
}

void Brush::setFont(Font font)
{
	mFont = font;
}

void Brush::drawTriangle(Position p1, Position p2, Position p3)
{
	drawLine(p1, p2);
	drawLine(p2, p3);
	drawLine(p3, p1);
}

void Brush::drawRect(Position p1, Position p2)
{
	Position p3, p4;
	p3.x = p1.x;
	p3.y = p2.y;
	p4.x = p2.x;
	p4.y = p1.y;

	drawLine(p1, p3);
	drawLine(p1, p4);
	drawLine(p2, p3);
	drawLine(p2, p4);
}

void Brush::drawRect(Position p1, Size size)
{
	Position p2;
	p2.x = p1.x + size.width;
	p2.y = p1.y + size.height;

	drawRect(p1, p2);
}

void Brush::setSize(Size size)
{
	mSize = size;
}

uint8_t Brush::drawChar(Position pos, uint32_t utf8)
{
/*
	if (mFont.setChar(utf8))
		return 0;

	YssFontInfo *fontInfo = mFont.getFontInfo();
	uint8_t *fontFb = mFont.getFrameBuffer(), color;
	int32_t  index = 0;
	uint16_t width = fontInfo->width, height = fontInfo->height, offset = 0;
	int16_t xs = pos.x, ys = pos.y + (int8_t)fontInfo->ypos;

	if (xs + width > mSize.width)
	{
		width = mSize.width - xs;
		offset = fontInfo->width - width;
	}
	if (ys + height > mSize.height)
		height = mSize.height - ys;

	width += xs;
	height += ys;

	for (int32_t  y = ys; y < height; y++)
	{
		for (int32_t  x = xs; x < width; x++, index++)
		{
			if (index % 2 == 0)
			{
				color = fontFb[index / 2] & 0x0f;
				if (color == 0)
					continue;
				drawFontDot(x, y, color);
			}
			else
			{
				color = (fontFb[index / 2] >> 4) & 0x0f;
				if (color == 0)
					continue;
				drawFontDot(x, y, color);
			}
		}
		index += offset;
	}

	return fontInfo->width;
*/
}

uint8_t Brush::drawString(Position pos, const char *str, uint8_t int8_tWidth)
{
	uint16_t sum = 0;

	while (*str)
	{
		if (*str == ' ')
			str++;
		else
			drawChar(pos, mFont.getUtf8(&str));
		sum += int8_tWidth;
		pos.x += int8_tWidth;
	}

	return sum;
}

uint8_t Brush::drawString(Position pos, const char *str)
{
	uint8_t width, int8_tWidth = mFont.getCharWidth();
	uint16_t sum = 0;
	uint32_t utf8;
	YssFontInfo *fontInfo;
	Position tpos;

	if (int8_tWidth)
	{
		while (*str)
		{
			if (*str == ' ')
			{
				str++;
				width = mFont.getSpaceWidth();
				sum += width;
				pos.x += width;
			}
			else
			{
				utf8 = mFont.getUtf8(&str);
				mFont.setChar(utf8);
				fontInfo = mFont.getFontInfo();
				tpos = pos;
				if (int8_tWidth > fontInfo->width)
					tpos.x += (int8_tWidth - fontInfo->width) / 2;
				width = drawChar(tpos, utf8);

				sum += int8_tWidth;
				pos.x += int8_tWidth;
			}
		}
	}
	else
	{
		while (*str)
		{
			if (*str == ' ')
			{
				str++;
				width = mFont.getSpaceWidth();
			}
			else
				width = drawChar(pos, mFont.getUtf8(&str));
			sum += width;
			pos.x += width;
		}
	}

	return sum;
}

Size Brush::calculateStringSize(const char *str)
{
	Size size;

	size.width = mFont.getStringWidth(str);
	size.height = mFont.getStringHeight(str);

	return size;
}

void Brush::drawCircle(Position pos, uint16_t radius)
{
	float r = radius, x, yp, yn;

	if (radius < 3)
		return;

	for (uint16_t i = 0; i < radius; i++)
	{
		x = i;
		yp = r * r - x * x;
		yp = pow(yp, (float)0.5) + (float)0.5;
		yn = yp - (float)1.0;

		drawDot(pos.x + x, pos.y + yp);
		drawDot(pos.x + x, pos.y - yn);
		drawDot(pos.x - x, pos.y - yn);
		drawDot(pos.x - x, pos.y + yp);
		drawDot(pos.x + yp, pos.y + x);
		drawDot(pos.x + yp, pos.y - x);
		drawDot(pos.x - yn, pos.y - x);
		drawDot(pos.x - yn, pos.y + x);
	}
}

void Brush::fillCircle(Position pos, uint16_t radius)
{
	Position p;
	float r = radius, x, y, y2;

	if (radius < 3)
		return;

	for (uint16_t i = 0; i < radius; i++)
	{
		x = i;
		y = r * r - x * x;
		y = pow(y, (float)0.5) + (float)0.5;
		y2 = y - (float)1.0;

		drawLine(Position{(int16_t)(pos.x + x), (int16_t)(pos.y + y)}, Position{(int16_t)(pos.x + x), (int16_t)(pos.y - y2)});
		drawLine(Position{(int16_t)(pos.x - x), (int16_t)(pos.y + y)}, Position{(int16_t)(pos.x - x), (int16_t)(pos.y - y2)});
	}
}

void Brush::fillTriangle(Position top, Position left, Position right)
{
	float slope1, slope2, slope3;
	int16_t sx, sy, ex, ey, buf, cy;
	bool nextDrawFlag = false;
	Position p;
	
	if(top.y < left.y)
	{
		p = top;
		top = left;
		left = p;
	}
	
	if(top.y < right.y)
	{
		p = top;
		top = right;
		right = p;
	}

	if(left.x > right.x)
	{
		p = left;
		left = right;
		right = p;
	}

	if(top.y != right.y && top.y != left.y)
	{
		if(left.y < right.y)
			ey = top.y - right.y;
		else
			ey = top.y - left.y;
	
		slope1 = (float)(top.x - left.x) / (float)(top.y - left.y);
		slope2 = (float)(top.x - right.x) / (float)(top.y - right.y);
	
		for(int32_t  y=0;y<=ey;y++)
		{
			sx = top.x - (y * slope1);
			ex = top.x - (y * slope2);

			if(sx > ex)
			{
				buf = sx;
				sx = ex;
				ex = buf;
			}
			cy = top.y - y;
			for(int32_t  x=sx;x<=ex;x++)
			{
				drawDot(x, cy);
			}
		}

		if(top.y < left.y)
		{
			top.x = ex;
			top.y = cy;
		}
	}
	else 
		nextDrawFlag = true;

	if(ey == top.y && nextDrawFlag == false)
		return;
	
	if(top.y > left.y)
	{
		p = top;
		top = left;
		left = p;
	}
	
	if(top.y > right.y)
	{
		p = top;
		top = right;
		right = p;
	}

	if(left.x > right.x)
	{
		p = left;
		left = right;
		right = p;
	}

	if(top.y == right.y || top.y == left.y)
		return;

	slope1 = (float)(left.x - top.x) / (float)(left.y - top.y);
	slope2 = (float)(right.x - top.x) / (float)(right.y - top.y);

	if(left.y < right.y)
		ey = left.y - top.y;
	else
		ey = right.y - top.y;

	for(int32_t  y=0;y<=ey;y++)
	{
		sx = top.x + (y * slope1);
		ex = top.x + (y * slope2);

		if(sx > ex)
		{
			buf = sx;
			sx = ex;
			ex = buf;
		}
		cy = top.y + y;
		for(int32_t  x=sx;x<=ex;x++)
		{
			drawDot(x, cy);
		}
	}
}

void Brush::fillRect(Position p1, Position p2)
{
	int16_t sx, ex, sy, ey;

	if (p1.x < p2.x)
	{
		sx = p1.x;
		ex = p2.x;
	}
	else
	{
		sx = p2.x;
		ex = p1.x;
	}

	if (p1.y < p2.y)
	{
		sy = p1.y;
		ey = p2.y;
	}
	else
	{
		sy = p2.y;
		ey = p1.y;
	}

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	for (int16_t y = sy; y <= ey; y++)
	{
		for (int16_t x = sx; x <= ex; x++)
			drawDot(x, y);
	}
}

void Brush::fillRect(Position pos, Size size)
{
	int16_t sx = pos.x, ex = pos.x + size.width - 1, sy = pos.y, ey = pos.y + size.height - 1;

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	for (int16_t y = sy; y <= ey; y++)
	{
		for (int16_t x = sx; x <= ex; x++)
			drawDot(x, y);
	}
}

void Brush::eraseRect(Position p1, Position p2)
{
	int16_t sx, ex, sy, ey;

	if (p1.x < p2.x)
	{
		sx = p1.x;
		ex = p2.x;
	}
	else
	{
		sx = p2.x;
		ex = p1.x;
	}

	if (p1.y < p2.y)
	{
		sy = p1.y;
		ey = p2.y;
	}
	else
	{
		sy = p2.y;
		ey = p1.y;
	}

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	for (int16_t y = sy; y <= ey; y++)
	{
		for (int16_t x = sx; x <= ex; x++)
			eraseDot(Position{x, y});
	}
}

void Brush::eraseRect(Position pos, Size size)
{
	int16_t sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;

	for (int16_t y = sy; y < ey; y++)
	{
		for (int16_t x = sx; x <= ex; x++)
			eraseDot(Position{x, y});
	}
}

void Brush::fill(void)
{
	fillRect(Position{0, 0}, mSize);
}

void Brush::clear(void)
{
	eraseRect(Position{0, 0}, mSize);
}

void Brush::drawBmp(Position pos, const Bmp1555 *image)
{
/*
	uint16_t *fb = (uint16_t *)image->data, *src, buf;
	uint16_t width = image->width;
	uint16_t height = image->height;
	int16_t xs = pos.x, ys = pos.y;

	if (xs + width > mSize.width)
		width = mSize.width - xs;
	if (ys + height > mSize.height)
		height = mSize.height - ys;

	width += xs;
	height += ys;

	for (int16_t y = ys; y < height; y++)
	{
		src = fb;
		fb += image->width;

		for (int16_t x = xs; x < width; x++)
		{
			if (*src & 0x8000)
			{
				if (*src & 0x0200)
					buf = (*src << 1 & 0xFFC0) | (*src & 0x001F) | 0x0020;
				else
					buf = (*src << 1 & 0xFFC0) | (*src & 0x001F);

				drawDot(x, y, buf);
			}
			src++;
		}
	}
*/
}

void Brush::drawBmp(Position pos, const Bmp1555 &image)
{
	drawBmp(pos, &image);
}

Brush::~Brush(void)
{
}

void Brush::setReverseRgbOrder(bool reverse)
{
	mBrushColor.setReverseRgbOrder(reverse);
	mFontColor.setReverseRgbOrder(reverse);
	mBgColor.setReverseRgbOrder(reverse);
}

void Brush::setReverseEndian(bool reverse)
{
	mBrushColor.setReverseEndian(reverse);
	mFontColor.setReverseEndian(reverse);
	mBgColor.setReverseEndian(reverse);
}

#endif
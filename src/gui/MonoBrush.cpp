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

#if USE_GUI

#include <gui/MonoBrush.h>
#include <math.h>

MonoBrush::MonoBrush(void)
{
	mSize.width = 0;
	mSize.height = 0;
}

void MonoBrush::setFont(Font font)
{
	mFont = font;
}

void MonoBrush::setSize(Size size)
{
	mSize.width = size.width - 1;
	mSize.height = size.height - 1;
}

void MonoBrush::setSize(uint16_t width, uint16_t height)
{
	mSize.width = width - 1;
	mSize.height = height - 1;
}

uint8_t MonoBrush::drawChar(Position pos, uint32_t utf8, bool data)
{
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
				if (color > 5)
					drawDot(x, y, data);
				else
					drawDot(x, y, !data);
			}
			else
			{
				color = (fontFb[index / 2] >> 4) & 0x0f;
				if (color > 5)
					drawDot(x, y, data);
				else
					drawDot(x, y, !data);
			}
		}
		index += offset;
	}

	return fontInfo->width;
}

uint8_t MonoBrush::drawString(Position pos, const char *str, bool data)
{
	uint8_t width, charWidth = mFont.getCharWidth();
	uint16_t sum = 0;
	uint32_t utf8;
	YssFontInfo *fontInfo;
	Position tpos;

	if (charWidth)
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
				if (charWidth > fontInfo->width)
					tpos.x += (charWidth - fontInfo->width) / 2;
				width = drawChar(tpos, utf8, data);

				sum += charWidth;
				pos.x += charWidth;
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
				width = drawChar(pos, mFont.getUtf8(&str), data);
			sum += width;
			pos.x += width;
		}
	}

	return sum;
}

void MonoBrush::clear(void)
{
	uint16_t width = mSize.width, height = mSize.height;

	for (int32_t  y = 0; y < height; y++)
	{
		for (int32_t  x = 0; x < width; x++)
		{
			drawDot(x, y, false);
		}
	}
}

void MonoBrush::fill(void)
{
	uint16_t width = mSize.width, height = mSize.height;

	for (int32_t  y = 0; y < height; y++)
	{
		for (int32_t  x = 0; x < width; x++)
		{
			drawDot(x, y, true);
		}
	}
}

void MonoBrush::drawLine(Position start, Position end, bool data)
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
				drawDot(x, y, data);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = startX + slope * (float)i;
				y = startY + i;
				drawDot(x, y, data);
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
				drawDot(x, y, data);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY * (float)-1;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = startX + slope * (float)i;
				y = startY + i;
				drawDot(x, y, data);
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
				drawDot(x, y, data);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = startX + slope * (float)i;
				y = startY - i;
				drawDot(x, y, data);
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
				drawDot(x, y, data);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = startX + slope * (float)i;
				y = startY + i;
				drawDot(x, y, data);
			}
		}
	}
}

void MonoBrush::drawLine(int16_t sx, int16_t sy, int16_t ex, int16_t ey, bool data)
{
	drawLine(Position{sx, sy}, Position{ex, ey}, data);
}

void MonoBrush::drawRect(Position p1, Position p2, bool data)
{
	Position p3, p4;
	p3.x = p1.x;
	p3.y = p2.y;
	p4.x = p2.x;
	p4.y = p1.y;

	drawLine(p1, p3, data);
	drawLine(p1, p4, data);
	drawLine(p2, p3, data);
	drawLine(p2, p4, data);
}

void MonoBrush::drawRect(Position p1, Size size, bool data)
{
	Position p2;
	p2.x = p1.x + size.width;
	p2.y = p1.y + size.height;

	drawRect(p1, p2, data);
}

void MonoBrush::drawCircle(Position pos, uint16_t radius, bool data)
{
	Position p;
	float r = radius, x, y;

	if (radius < 3)
		return;

	for (uint16_t i = 0; i < radius; i++)
	{
		x = i;
		y = r * r - x * x;
		y = pow(y, (float)0.5075);

		drawDot(pos.x + x, pos.y + y, data);
		drawDot(pos.x + x, pos.y - y, data);
		drawDot(pos.x - x, pos.y - y, data);
		drawDot(pos.x - x, pos.y + y, data);
		drawDot(pos.x + y, pos.y + x, data);
		drawDot(pos.x + y, pos.y - x, data);
		drawDot(pos.x - y, pos.y - x, data);
		drawDot(pos.x - y, pos.y + x, data);
	}
}

void MonoBrush::fillRect(Position p1, Position p2, bool data)
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
			drawDot(x, y, data);
	}
}

void MonoBrush::fillRect(Position pos, Size size, bool data)
{
	int16_t sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	for (int16_t y = sy; y <= ey; y++)
	{
		for (int16_t x = sx; x <= ex; x++)
			drawDot(x, y, data);
	}
}

#endif


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

#include <config.h>

#if USE_GUI == true

#include <math.h>
#include <yss/gui.h>

#define PI (float)3.14159265358979323846

Brush::Brush(void)
{
	mSize.height = 0;
	mSize.width = 0;
}

void Brush::drawLine(Position start, Position end)
{
	unsigned short startX = start.x, startY = start.y, endX = end.x, endY = end.y;
	unsigned short buf, lenX, lenY, x, y;
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
			for (unsigned short i = 0; i <= lenX; i++)
			{
				x = startX + i;
				y = startY + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (unsigned short i = 0; i <= lenY; i++)
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
			for (unsigned short i = 0; i <= lenX; i++)
			{
				x = startX - i;
				y = startY + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY * (float)-1;
			for (unsigned short i = 0; i <= lenY; i++)
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
			for (unsigned short i = 0; i <= lenX; i++)
			{
				x = startX + i;
				y = startY + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (unsigned short i = 0; i <= lenY; i++)
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
			for (unsigned short i = 0; i <= lenX; i++)
			{
				x = startX + i;
				y = startY + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (unsigned short i = 0; i <= lenY; i++)
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

unsigned char Brush::drawChar(Position pos, unsigned int utf8)
{
	if (mFont.setChar(utf8))
		return 0;

	YssFontInfo *fontInfo = mFont.getFontInfo();
	unsigned char *fontFb = mFont.getFrameBuffer(), color;
	int index = 0;
	unsigned short width = fontInfo->width, height = fontInfo->height, offset = 0;
	signed short xs = pos.x, ys = pos.y + (signed char)fontInfo->ypos;

	if (xs + width > mSize.width)
	{
		width = mSize.width - xs;
		offset = fontInfo->width - width;
	}
	if (ys + height > mSize.height)
		height = mSize.height - ys;

	width += xs;
	height += ys;

	for (int y = ys; y < height; y++)
	{
		for (int x = xs; x < width; x++, index++)
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
}

unsigned char Brush::drawString(Position pos, const char *str, unsigned char charWidth)
{
	unsigned short sum = 0;

	while (*str)
	{
		if (*str == ' ')
			str++;
		else
			drawChar(pos, mFont.getUtf8(&str));
		sum += charWidth;
		pos.x += charWidth;
	}

	return sum;
}

unsigned char Brush::drawString(Position pos, const char *str)
{
	unsigned char width, charWidth = mFont.getCharWidth();
	unsigned short sum = 0;
	unsigned int utf8;
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
				width = drawChar(tpos, utf8);

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

void Brush::drawCircle(Position pos, unsigned short radius)
{
	float r = radius, x, yp, yn;

	if (radius < 3)
		return;

	for (unsigned short i = 0; i < radius; i++)
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

void Brush::fillCircle(Position pos, unsigned short radius)
{
	Position p;
	float r = radius, x, y, y2;

	if (radius < 3)
		return;

	for (unsigned short i = 0; i < radius; i++)
	{
		x = i;
		y = r * r - x * x;
		y = pow(y, (float)0.5) + (float)0.5;
		y2 = y - (float)1.0;

		drawLine(Position{(signed short)(pos.x + x), (signed short)(pos.y + y)}, Position{(signed short)(pos.x + x), (signed short)(pos.y - y2)});
		drawLine(Position{(signed short)(pos.x - x), (signed short)(pos.y + y)}, Position{(signed short)(pos.x - x), (signed short)(pos.y - y2)});
	}
}

void Brush::fillTriangle(Position top, Position left, Position right)
{
	float slope1, slope2, slope3;
	short sx, sy, ex, ey, buf, cy;
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
	
		for(int y=0;y<=ey;y++)
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
			for(int x=sx;x<=ex;x++)
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

	for(int y=0;y<=ey;y++)
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
		for(int x=sx;x<=ex;x++)
		{
			drawDot(x, cy);
		}
	}
}

void Brush::fillRect(Position p1, Position p2)
{
	signed short sx, ex, sy, ey;

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

	for (signed short y = sy; y <= ey; y++)
	{
		for (signed short x = sx; x <= ex; x++)
			drawDot(x, y);
	}
}

void Brush::fillRect(Position pos, Size size)
{
	signed short sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;

	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	for (signed short y = sy; y <= ey; y++)
	{
		for (signed short x = sx; x <= ex; x++)
			drawDot(x, y);
	}
}

void Brush::eraseRect(Position p1, Position p2)
{
	signed short sx, ex, sy, ey;

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

	for (signed short y = sy; y <= ey; y++)
	{
		for (signed short x = sx; x <= ex; x++)
			eraseDot(Position{x, y});
	}
}

void Brush::eraseRect(Position pos, Size size)
{
	signed short sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;

	for (signed short y = sy; y < ey; y++)
	{
		for (signed short x = sx; x <= ex; x++)
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

void Brush::drawBmp(Position pos, const Bmp565 *image)
{
	unsigned short *fb = (unsigned short *)image->data, *src;
	unsigned short width = image->width;
	unsigned short height = image->height;
	signed short xs = pos.x, ys = pos.y;

	if (xs + width > mSize.width)
		width = mSize.width - xs;
	if (ys + height > mSize.height)
		height = mSize.height - ys;

	width += xs;
	height += ys;

	for (signed short y = ys; y < height; y++)
	{
		src = fb;
		fb += image->width;

		for (signed short x = xs; x < width; x++)
		{
			drawDot(x, y, *src++);
		}
	}
}

void Brush::drawBmp(Position pos, const Bmp888 *image)
{
	unsigned char *fb = (unsigned char *)image->data, *src;
	unsigned short width = image->width;
	unsigned short height = image->height;
	signed short xs = pos.x, ys = pos.y;

	if (xs + width > mSize.width)
		width = mSize.width - xs;
	if (ys + height > mSize.height)
		height = mSize.height - ys;

	width += xs;
	height += ys;

	for (signed short y = ys; y < height; y++)
	{
		src = fb;
		fb += image->width * 3;

		for (signed short x = xs; x < width; x++)
		{
			drawDot(x, y, *(unsigned int*)src);
			src += 3;
		}
	}
}


void Brush::drawBmp(Position pos, const Bmp565 &image)
{
	drawBmp(pos, &image);
}

void Brush::drawBmp(Position pos, const Bmp1555 *image)
{
	unsigned short *fb = (unsigned short *)image->data, *src, buf;
	unsigned short width = image->width;
	unsigned short height = image->height;
	signed short xs = pos.x, ys = pos.y;

	if (xs + width > mSize.width)
		width = mSize.width - xs;
	if (ys + height > mSize.height)
		height = mSize.height - ys;

	width += xs;
	height += ys;

	for (signed short y = ys; y < height; y++)
	{
		src = fb;
		fb += image->width;

		for (signed short x = xs; x < width; x++)
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
}

void Brush::drawBmp(Position pos, const Bmp1555 &image)
{
	drawBmp(pos, &image);
}

Brush::~Brush(void)
{
}

#endif
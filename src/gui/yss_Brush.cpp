/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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
	mFont = 0;
	
	mBrushColorCode = 0x00;
	mFontColor.setToBlack();
	mBgColor.setToWhite();
	mBgColorCode = 0xFFFFFFFF;
	updateFontColor();
}

Brush::~Brush(void)
{

}

void Brush::translateFromPositionToSize(Position_t &desPos, Size_t &desSize, Position_t &srcPos1, Position_t &srcPos2)
{
	if(srcPos1.x > srcPos2.x)
	{
		desSize.width = srcPos1.x - srcPos2.x + 1;
		desPos.x = srcPos2.x;
	}
	else
	{
		desSize.width = srcPos2.x - srcPos1.x + 1;
		desPos.x = srcPos1.x;
	}

	if(srcPos1.y > srcPos2.y)
	{
		desSize.height = srcPos1.y - srcPos2.y + 1;
		desPos.y = srcPos2.y;
	}
	else
	{
		desSize.height = srcPos2.y - srcPos1.y + 1;
		desPos.y = srcPos1.y;
	}	
}

void Brush::eraseDot(Position_t pos)
{
	drawDot(pos.x, pos.y, mBgColorCode);
}

void Brush::setBrushColor(Color color)
{
	switch(mColorMode)
	{
	case COLOR_MODE_RGB565 :
		mBrushColorCode = color.getRgb565Code();
		break;

	case COLOR_MODE_RGB888 :
		mBrushColorCode = color.getRgb888Code();
		break;

	case COLOR_MODE_ARGB1555 :
		mBrushColorCode = color.getArgb1555Code();
		break;
	}
}

void Brush::setFontColor(Color color)
{
	mFontColor = color;
	updateFontColor();
}

void Brush::setBackgroundColor(Color color)
{
	mBgColor.setColor(color);

	switch(mColorMode)
	{
	case COLOR_MODE_RGB565 :
		mBgColorCode = color.getRgb565Code();
		break;

	case COLOR_MODE_RGB888 :
		mBgColorCode = color.getRgb888Code();
		break;

	case COLOR_MODE_ARGB1555 :
		mBgColorCode = color.getArgb1555Code();
		break;
	}

	updateFontColor();
}

void Brush::setBrushColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	Color color(red, green, blue, alpha);

	switch(mColorMode)
	{
	case COLOR_MODE_RGB565 :
		mBrushColorCode = color.getRgb565Code();
		break;

	case COLOR_MODE_RGB888 :
		mBrushColorCode = color.getRgb888Code();
		break;

	case COLOR_MODE_ARGB1555 :
		mBrushColorCode = color.getArgb1555Code();
		break;
	}
}

void Brush::setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mFontColor.setColor(red, green, blue, alpha);
	updateFontColor();
}

void Brush::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mBgColor.setColor(red, green, blue, alpha);

	switch(mColorMode)
	{
	case COLOR_MODE_RGB565 :
		mBgColorCode = mBgColor.getRgb565Code();
		break;

	case COLOR_MODE_RGB888 :
		mBgColorCode = mBgColor.getRgb888Code();
		break;

	case COLOR_MODE_ARGB1555 :
		mBgColorCode = mBgColor.getArgb1555Code();
		break;
	}

	updateFontColor();
}

void Brush::drawLine(Position_t start, Position_t end)
{
	uint16_t startX = start.x, startY = start.y, endX = end.x, endY = end.y;
	uint16_t lenX, lenY, x, y;
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

void Brush::setFont(Font &font)
{
	mFont = &font;
}

Font* Brush::getFont(void)
{
	return mFont;
}

void Brush::drawTriangle(Position_t p1, Position_t p2, Position_t p3)
{
	drawLine(p1, p2);
	drawLine(p2, p3);
	drawLine(p3, p1);
}

void Brush::drawRect(Position_t p1, Position_t p2)
{
	Position_t p3, p4;
	p3.x = p1.x;
	p3.y = p2.y;
	p4.x = p2.x;
	p4.y = p1.y;

	drawLine(p1, p3);
	drawLine(p1, p4);
	drawLine(p2, p3);
	drawLine(p2, p4);
}

void Brush::drawRect(Position_t pos, Size_t size)
{
	Position_t p2;
	p2.x = pos.x + size.width;
	p2.y = pos.y + size.height;

	drawRect(pos, p2);
}

uint16_t Brush::drawString(Position_t pos, const char *str, uint8_t charWidth)
{
	if(mFont == 0)
		return 0;

	while (*str)
	{
		if (*str == ' ')
			str++;
		else
			drawChar(pos, mFont->getUtf8(&str));
		
		pos.x += charWidth;
	}

	return pos.x;
}

uint16_t Brush::drawString(Position_t pos, const char *str)
{
	if(mFont == 0)
		return 0;

	uint8_t width, charWidth = mFont->getCharWidth(), spaceWidth = mFont->getSpaceWidth();

	if (charWidth)
	{
		while (*str)
		{
			if (*str == ' ')
			{
				str++;
				pos.x += spaceWidth;
			}
			else
			{
				width = drawChar(pos, mFont->getUtf8(&str));
				if (charWidth > width)
					pos.x += charWidth;
				else
					pos.x += width;
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
				pos.x += spaceWidth;
			}
			else
				pos.x += drawChar(pos, mFont->getUtf8(&str));
		}
	}

	return pos.x;
}

Size_t Brush::calculateStringSize(const char *str)
{
	if(mFont == 0)
		return Size_t{0, 0};

	Size_t size;

	size.width = mFont->getStringWidth(str);
	size.height = mFont->getStringHeight();

	return size;
}

void Brush::drawCircle(Position_t pos, uint16_t radius)
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

void Brush::fillCircle(Position_t pos, uint16_t radius)
{
	float r = radius, buf;
	int32_t sx, ex, y;

	if (radius < 3)
		return;

	for (uint16_t i = 0; i < radius; i++)
	{
		buf = i + 1;
		buf = r * r - buf * buf;
		ex = sx = pow(buf, (float)0.5);

		sx = pos.x - sx + 1;
		ex = pos.x + ex;

		if(sx < 0)
			sx = 0;
		if(ex > mSize.width - 1)
			ex = mSize.width - 1;
		
		y = pos.y + i + 1;
		if(y < mSize.height)
		{
			for(int32_t x=sx;x<=ex;x++)
				drawDot(x, y);
		}
		
		y = pos.y - i;
		if(y >= 0)
		{
			for(int32_t x=sx;x<=ex;x++)
				drawDot(x, y);
		}
	}
}

void Brush::fillTriangle(Position_t top, Position_t left, Position_t right)
{
	float slope1, slope2;
	int16_t sx, ex, ey, buf, cy = 0;
	bool nextDrawFlag = false;
	Position_t p;
	
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

void Brush::fillRectBase(Position_t pos, Size_t size, uint32_t color)
{
	int16_t sx = pos.x, ex = pos.x + size.width - 1, sy = pos.y, ey = pos.y + size.height - 1;
	
	if (ey > mSize.height - 1)
		ey = mSize.height - 1;
	if (ex > mSize.width - 1)
		ex = mSize.width - 1;

	for (int16_t y = sy; y <= ey; y++)
	{
		for (int16_t x = sx; x <= ex; x++)
			drawDot(x, y, color);
	}
}

void Brush::fillRect(Position_t pos, Size_t size, uint32_t color)
{
	fillRectBase(pos, size, color);
}

void Brush::fillRect(Position_t pos, Size_t size, Color color)
{
	switch(mColorMode)
	{
	case COLOR_MODE_RGB888 :
		fillRectBase(pos, size, color.getRgb888Code());
		break;
	case COLOR_MODE_RGB565 :
		fillRectBase(pos, size, color.getRgb565Code());
		break;
	default :
		return;
	}
}

void Brush::fillRect(Position_t p1, Position_t p2)
{
	Size_t size;
	Position_t pos;

	translateFromPositionToSize(pos, size, p1, p2);

	fillRectBase(pos, size, mBrushColorCode);
}

void Brush::fillRect(Position_t pos, Size_t size)
{
	fillRectBase(pos, size, mBrushColorCode);
}

void Brush::eraseRectangle(Position_t p1, Position_t p2)
{
	Size_t size;
	Position_t pos;

	translateFromPositionToSize(pos, size, p1, p2);

	fillRectBase(pos, size, mBgColorCode);
}

void Brush::eraseRectangle(Position_t pos, Size_t size)
{
	fillRectBase(pos, size, mBgColorCode);
}

void Brush::fill(void)
{
	fillRectBase(Position_t{0, 0}, mSize, mBrushColorCode);
}

void Brush::clear(void)
{
	eraseRectangle(Position_t{0, 0}, mSize);
}

void Brush::drawBitmapBase(Position_t pos, const Bitmap_t &bitmap)
{
#warning "내용 작성이 필요함"
	(void)pos;
	(void)bitmap;
}

void Brush::drawBitmap(Position_t pos, const Bitmap_t &bitmap)
{
	drawBitmapBase(pos, bitmap);
}

void Brush::drawBitmap(Position_t pos, const Bitmap_t *bitmap)
{
	drawBitmapBase(pos, *bitmap);
}

void Brush::drawBitmapFileBase(Position_t pos, const BitmapFile_t &bitmap)
{
#warning "내용 작성이 필요함"
	(void)pos;
	(void)bitmap;
}

void Brush::drawBitmapFile(Position_t pos, const BitmapFile_t &bitmap)
{
	drawBitmapFileBase(pos, bitmap);
}

void Brush::drawBitmapFile(Position_t pos, const BitmapFile_t *bitmap)
{
	drawBitmapFileBase(pos, *bitmap);
}

uint8_t Brush::drawChar(Position_t pos, uint32_t utf8)
{
	if (mFont == 0)
		return 0;

	Font::fontInfo_t *fontInfo = mFont->getFontInfo(utf8);
	uint8_t *fontFb, color;
	int32_t  index = 0;
	int16_t width = fontInfo->width, height = fontInfo->height, offset = 0, xoffset;
	int16_t xs = pos.x, ys = pos.y + (int8_t)fontInfo->ypos;
	
	if(fontInfo == 0)
		return 0;
	
	fontFb = fontInfo->data;
	xoffset = (int8_t)fontInfo->xpos;

	if(xoffset == 0) // 문자의 앞 여백이 없을 경우
		xoffset = 1; // 문자의 앞 여백 하나를 추가해줌
	
	xs += xoffset;

	if(width & 0x01) // 문자 크기가 홀수 일 경우
		width++; // 짝수로 만들어줌

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
				drawDot(x, y, mFontColorCodeTable[color]);
			}
			else
			{
				color = (fontFb[index / 2] >> 4) & 0x0f;
				drawDot(x, y, mFontColorCodeTable[color]);
			}
		}
		index += offset;
	}

	return fontInfo->width + xoffset;
}

void Brush::updateFontColor(void)
{
	switch(mColorMode)
	{
	case COLOR_MODE_RGB888 :
		for(uint8_t i=0;i<16;i++)
			mFontColorCodeTable[i] = mFontColor.calculateFontColorLevel(mBgColor, i).getRgb888Code();
		break;
	case COLOR_MODE_RGB565 :
		for(uint8_t i=0;i<16;i++)
			mFontColorCodeTable[i] = mFontColor.calculateFontColorLevel(mBgColor, i).getRgb565Code();
		break;
	case COLOR_MODE_ARGB1555 :
		for(uint8_t i=0;i<16;i++)
			mFontColorCodeTable[i] = mFontColor.calculateFontColorLevel(mBgColor, i).getArgb1555Code();
		break;
	}
}


#endif
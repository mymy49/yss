////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021.yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2021.02.23 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <gui/MonoBrush.h>

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

void MonoBrush::setSize(unsigned short width, unsigned short height)
{
    mSize.width = width - 1;
    mSize.height = height - 1;
}

unsigned char MonoBrush::drawChar(Pos pos, unsigned int utf8)
{
    if (mFont.setChar(utf8))
        return 0;

    YssFontInfo *fontInfo = mFont.getFontInfo();
    unsigned char *fontFb = mFont.getFrameBuffer(), color;
    int index = 0;
    unsigned short width = fontInfo->width, height = fontInfo->height, offset = 0;
    signed short xs = pos.x, ys = pos.y; // + (signed char)fontInfo->ypos;

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
                if (color > 5)
                    drawDot(x, y, true);
                else
                    drawDot(x, y, false);
            }
            else
            {
                color = (fontFb[index / 2] >> 4) & 0x0f;
                if (color > 5)
                    drawDot(x, y, true);
                else
                    drawDot(x, y, false);
            }
        }
        index += offset;
    }

    return fontInfo->width;
}

void MonoBrush::clear(void)
{
	unsigned short width = mSize.width, height = mSize.height;

	for(int y=0;y<height;y++)
	{
		for(int x=0;x<width;x++)
		{
			drawDot(x, y, false);
		}
	}
}

void MonoBrush::fill(void)
{
	unsigned short width = mSize.width, height = mSize.height;

	for(int y=0;y<height;y++)
	{
		for(int x=0;x<width;x++)
		{
			drawDot(x, y, true);
		}
	}
}

void MonoBrush::drawLine(Pos start, Pos end, bool data)
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
                drawDot(x, y, data);
            }
        }
        else
        {
            slope = (float)lenX / (float)lenY;
            for (unsigned short i = 0; i <= lenY; i++)
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
            for (unsigned short i = 0; i <= lenX; i++)
            {
                x = startX - i;
                y = startY + slope * (float)i;
                drawDot(x, y, data);
            }
        }
        else
        {
            slope = (float)lenX / (float)lenY * (float)-1;
            for (unsigned short i = 0; i <= lenY; i++)
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
            for (unsigned short i = 0; i <= lenX; i++)
            {
                x = startX + i;
                y = startY + slope * (float)i;
                drawDot(x, y, data);
            }
        }
        else
        {
            slope = (float)lenX / (float)lenY;
            for (unsigned short i = 0; i <= lenY; i++)
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
            for (unsigned short i = 0; i <= lenX; i++)
            {
                x = startX + i;
                y = startY + slope * (float)i;
                drawDot(x, y, data);
            }
        }
        else
        {
            slope = (float)lenX / (float)lenY;
            for (unsigned short i = 0; i <= lenY; i++)
            {
                x = startX + slope * (float)i;
                y = startY + i;
                drawDot(x, y, data);
            }
        }
    }
}

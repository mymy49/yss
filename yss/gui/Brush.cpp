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
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <drv/peripherals.h>

#if USE_GUI == true

#include <math.h>
#include <yss/gui.h>

#define PI (float)3.14159265358979323846

Brush::Brush(void)
{
    mSize.height = 0;
    mSize.width = 0;
}

void Brush::drawLine(Pos start, Pos end)
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

void Brush::drawTriangle(Pos p1, Pos p2, Pos p3)
{
    drawLine(p1, p2);
    drawLine(p2, p3);
    drawLine(p3, p1);
}

void Brush::drawRect(Pos p1, Pos p2)
{
    Pos p3, p4;
    p3.x = p1.x;
    p3.y = p2.y;
    p4.x = p2.x;
    p4.y = p1.y;

    drawLine(p1, p3);
    drawLine(p1, p4);
    drawLine(p2, p3);
    drawLine(p2, p4);
}

void Brush::drawRect(Pos p1, Size size)
{
    Pos p2;
    p2.x = p1.x + size.width;
    p2.y = p1.y + size.height;

    drawRect(p1, p2);
}

void Brush::setSize(Size size)
{
    mSize = size;
}

unsigned char Brush::drawChar(Pos pos, unsigned int utf8)
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

unsigned char Brush::drawString(Pos pos, char *ch, unsigned char charWidth)
{
    unsigned short sum = 0;

    while (*ch)
    {
        if (*ch == ' ')
            ch++;
        else
            drawChar(pos, mFont.getUtf8(&ch));
        sum += charWidth;
        pos.x += charWidth;
    }

    return sum;
}

unsigned char Brush::drawString(Pos pos, char *ch)
{
    unsigned char width, charWidth = mFont.getCharWidth();
    unsigned short sum = 0;
    unsigned int utf8;
    YssFontInfo *fontInfo;
    Pos tpos;

    if (charWidth)
    {
        while (*ch)
        {
            if (*ch == ' ')
            {
                ch++;
                if (mFont.isHaveSpaceWidth())
                {
                    width = mFont.getSpaceWidth();
                    sum += width;
                    pos.x += width;
                }
                else
                {
                    sum += charWidth;
                    pos.x += charWidth;
                }
            }
            else
            {
                utf8 = mFont.getUtf8(&ch);
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
        while (*ch)
        {
            if (*ch == ' ')
            {
                ch++;
                width = mFont.getSpaceWidth();
            }
            else
                width = drawChar(pos, mFont.getUtf8(&ch));
            sum += width;
            pos.x += width;
        }
    }

    return sum;
}

//void Brush::drawString(Pos pos, char *str)
//{
//	unsigned short i = 0;
//	unsigned short *unicode;
//	while(str[i])
//	{
//		if(str[i] < 127)
//		{
//			pos.x += drawChar(pos, str[i]);
//			i++;
//		}
//		else
//		{
//			pos.x += drawChar(pos, &str[i]);
//			i += 3;
//		}
//	}
//}

Size Brush::calculateStringSize(char *str)
{
    return Size{0, 0};
    //	return dma2d.calculateStringSize(str);
}

void Brush::drawCircle(Pos pos, unsigned short radius)
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

void Brush::fillCircle(Pos pos, unsigned short radius)
{
    Pos p;
    float r = radius, x, y, y2;

    if (radius < 3)
        return;

    for (unsigned short i = 0; i < radius; i++)
    {
        x = i;
        y = r * r - x * x;
        y = pow(y, (float)0.5) + (float)0.5;
        y2 = y - (float)1.0;

        drawLine(Pos{pos.x + x, pos.y + y}, Pos{pos.x + x, pos.y - y2});
        drawLine(Pos{pos.x - x, pos.y + y}, Pos{pos.x - x, pos.y - y2});
    }
}

void Brush::fillRect(Pos p1, Pos p2)
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

void Brush::fillRect(Pos pos, Size size)
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

void Brush::eraseRect(Pos p1, Pos p2)
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
            eraseDot(Pos{x, y});
    }
}

void Brush::eraseRect(Pos pos, Size size)
{
    signed short sx = pos.x, ex = pos.x + size.width, sy = pos.y, ey = pos.y + size.height;

    for (signed short y = sy; y <= ey; y++)
    {
        for (signed short x = sx; x <= ex; x++)
            eraseDot(Pos{x, y});
    }
}

void Brush::fill(void)
{
    fillRect(Pos{0, 0}, mSize);
}

void Brush::clear(void)
{
    eraseRect(Pos{0, 0}, mSize);
}

void Brush::drawBmp(Pos pos, const Bmp565 *image)
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

void Brush::drawBmp(Pos pos, const Bmp565 &image)
{
    drawBmp(pos, &image);
}

void Brush::drawBmp(Pos pos, const Bmp1555 *image)
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

void Brush::drawBmp(Pos pos, const Bmp1555 &image)
{
    drawBmp(pos, &image);
}

Brush::~Brush(void)
{
}

#endif
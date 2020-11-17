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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <drv/peripherals.h>

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE
/*
#include <yss/gui.h>

Argb1555::Argb1555(void)
{
	mDotSize = 2;
	mBrushColor.data = 0x8000;
	mBgColor.data = 0xffff;
	mColorMode = define::ltdc::format::ARGB1555;
}

void Argb1555::drawDot(Pos pos)
{
	unsigned short *buf = (unsigned short*)mFrameBuffer;

	if(mFrameBuffer)
	{
		if(pos.y < FrameBuffer::mSize.height && pos.x < FrameBuffer::mSize.width)
		{
			buf[FrameBuffer::mSize.width * pos.y + pos.x] = mBrushColor.data;
		}
	}
}

void Argb1555::drawDotQuick(Pos pos)
{
	unsigned short *buf = (unsigned short*)mFrameBuffer;
	buf[FrameBuffer::mSize.width * pos.y + pos.x] = mBrushColor.data;
}

void Argb1555::setColor(ARGB1555_struct color)
{
	mBrushColor.color = color;
}

void Argb1555::setBgColor(ARGB1555_struct color)
{
	mBgColor.color = color;
}

void Argb1555::setColor(ARGB1555_union color)
{
	mBrushColor = color;
}

void Argb1555::setBgColor(ARGB1555_union color)
{
	mBgColor = color;
}

void Argb1555::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	if(alpha == 0)
		mBrushColor.color.alpha = false;
	else
		mBrushColor.color.alpha = true;

	mBrushColor.color.red = red >> 3;
	mBrushColor.color.green = green >> 3;
	mBrushColor.color.blue = blue >> 3;
}

void Argb1555::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mBgColor.color.alpha = false;
	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 3;
	mBgColor.color.blue = blue >> 3;
}

void Argb1555::setColor(unsigned short color)
{
	mBrushColor.data = color;
}

void Argb1555::setBgColor(unsigned short color)
{
	mBgColor.data = color;
}

void Argb1555::fill(void)
{
	dma2d.fill(*this, mBrushColor);
}

void Argb1555::clear(void)
{
	dma2d.fill(*this, mBgColor);
}

void Argb1555::setSize(Size size)
{
	FrameBuffer::setSize(size);
//	Brush::setSize(size);
}

signed char Argb1555::drawChar(Pos pos, char* ch)
{
	if(mFrameBuffer)
	{
		unsigned char r, g, b;

		if(mBrushColor.color.red & 0x10)
			r = (mBrushColor.color.red << 3) | 0x7;
		else
			r = mBrushColor.color.red << 3;
		if(mBrushColor.color.green & 0x10)
			g = (mBrushColor.color.green << 3) | 0x7;
		else
			g = mBrushColor.color.green << 2;
		if(mBrushColor.color.blue & 0x10)
			b = (mBrushColor.color.blue << 3) | 0x7;
		else
			b = mBrushColor.color.blue << 3;

		dma2d.setFontColor(r, g, b);

		return dma2d.drawChar(*this, ch, pos);
	}

	return 0;
}

signed char Argb1555::drawChar(Pos pos, char ch)
{
	if(mFrameBuffer)
	{
		unsigned char r, g, b;

		if(mBrushColor.color.red & 0x10)
			r = (mBrushColor.color.red << 3) | 0x7;
		else
			r = mBrushColor.color.red << 3;
		if(mBrushColor.color.green & 0x10)
			g = (mBrushColor.color.green << 3) | 0x7;
		else
			g = mBrushColor.color.green << 2;
		if(mBrushColor.color.blue & 0x10)
			b = (mBrushColor.color.blue << 3) | 0x7;
		else
			b = mBrushColor.color.blue << 3;

		dma2d.setFontColor(r, g, b);

		return dma2d.drawChar(*this, ch, pos);
	}

	return 0;
}

void Argb1555::fillRect(Pos p1, Pos p2)
{
	dma2d.fillRectangle(*this, p1, p2, mBrushColor);
}

void Argb1555::fillRect(Pos pos, Size size)
{
	dma2d.fillRectangle(*this, pos, size, mBrushColor);
}
*/
/*
void Argb1555::draw(Argb1555 obj, Pos pos)
{
	dma2d.draw(*this, obj, pos);
}
*/
#endif
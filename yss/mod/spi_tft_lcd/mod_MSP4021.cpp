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

#include <mod/spi_tft_lcd/MSP4021.h>
#include <yss/stdlib.h>

MSP4021::MSP4021(void)
{
	Brush::setSize(Size{320, 480});
}

void MSP4021::setDirection(bool xMirror, bool yMirror, bool rotate)
{
	ST7796S_SPI::setDirection(xMirror, yMirror, rotate);

	if(rotate)
		Brush::setSize(Size{480, 320});
	else
		Brush::setSize(Size{320, 480});
}

void MSP4021::drawDot(signed short x, signed short y)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &mBrushColor, 3);
		disable();
	}
}

void MSP4021::drawDot(signed short x, signed short y, unsigned short color)
{
}

void MSP4021::drawDot(signed short x, signed short y, unsigned int color)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &color, 3);
		disable();
	}
}

void MSP4021::drawFontDot(signed short x, signed short y, unsigned char color)
{
}

void MSP4021::eraseDot(Pos pos)
{
	if (pos.y < mSize.height && pos.x < mSize.width)
	{
		enable();
		setWindows(pos.x, pos.y);
		sendCmd(MEMORY_WRITE, mBgColor.byte, 3);
		disable();
	}
}

void MSP4021::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	mBrushColor.color.red = red;
	mBrushColor.color.green = green;
	mBrushColor.color.blue = blue;
}

void MSP4021::setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	//mFontColor.setFontColor(red, green, blue);
	//mFontColor.calculateSwappedByte();
}

void MSP4021::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mBgColor.color.red = red;
	mBgColor.color.green = green;
	mBgColor.color.blue = blue;

	//mFontColor.setBgColor(red, green, blue);
	//mFontColor.calculateSwappedByte();
}

void MSP4021::drawBmp(Pos pos, const Bmp888 *image)
{
	// RGB565가 아니면 리턴
	//if (image->type != 0)
	//	return;
	
	enable();
	setWindows(pos.x, pos.y, image->width, image->height);
	sendCmd(MEMORY_WRITE, image->data, image->width * image->height * 3);
	disable();
}

/*
*/
/*
void MSP4021::drawDot(signed short x, signed short y)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &mBrushColor, 3);
		disable();
	}
}

void MSP4021::drawDot(signed short x, signed short y, unsigned short color)
{
}

void MSP4021::drawDot(signed short x, signed short y, unsigned int color)
{
	if (y < mSize.height && x < mSize.width)
	{
		enable();
		setWindows(x, y);
		sendCmd(MEMORY_WRITE, &color, 3);
		disable();
	}
}

void MSP4021::drawFontDot(signed short x, signed short y, unsigned char color)
{
	
}

void MSP4021::eraseDot(Pos pos)
{
}

void MSP4021::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	unsigned char buf;

	mBrushColor.color.red = red >> 3;
	mBrushColor.color.green = green >> 2;
	mBrushColor.color.blue = blue >> 3;

	buf = mBrushColor.byte[0];
	mBrushColor.byte[0] = mBrushColor.byte[1];
	mBrushColor.byte[1] = buf;
}

void MSP4021::setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{

}

void MSP4021::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	unsigned char buf;

	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 2;
	mBgColor.color.blue = blue >> 3;

	buf = mBgColor.byte[0];
	mBgColor.byte[0] = mBgColor.byte[1];
	mBgColor.byte[1] = buf;

	//mFontColor.setBgColor(red, green, blue);
	//mFontColor.calculateSwappedByte();
}

void MSP4021::setWindows(unsigned short x, unsigned short y, unsigned short width, unsigned short height)
{
	unsigned char data[4];
	unsigned short end;

	end = x + width - 1;
	data[0] = x >> 8;
	data[1] = x & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(COLUMN_ADDRESS_SET, data, 4);
	
	end = y + height - 1;
	data[0] = y >> 8;
	data[1] = y & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(PAGE_ADDRESS_SET, data, 4);
}

*/


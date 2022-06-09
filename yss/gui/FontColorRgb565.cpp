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

#include <gui/FontColorRgb565.h>

FontColorRgb565::FontColorRgb565(void)
{
	mFontColor.color.red = 0x1F;
	mFontColor.color.green = 0x3F;
	mFontColor.color.blue = 0x1F;

	mBgColor.color.red = 0x00;
	mBgColor.color.green = 0x00;
	mBgColor.color.blue = 0x00;
}

void FontColorRgb565::calculate(void)
{
	signed int r, g, b, rf, rb, gf, gb, bf, bb;
	RGB565_union table;

	rf = (signed int)mFontColor.color.red;
	rb = (signed int)mBgColor.color.red;
	gf = (signed int)mFontColor.color.green;
	gb = (signed int)mBgColor.color.green;
	bf = (signed int)mFontColor.color.blue;
	bb = (signed int)mBgColor.color.blue;

	mFontColorTable[0] = mBgColor.halfword;

	for (signed int i = 1; i < 16; i++)
	{
		r = (rf - rb) * i / 15 + rb;
		g = (gf - gb) * i / 15 + gb;
		b = (bf - bb) * i / 15 + bb;
		table.color.red = r;
		table.color.green = g;
		table.color.blue = b;
		mFontColorTable[i] = table.halfword;
	}
}

void FontColorRgb565::calculateSwappedByte(void)
{
	signed int r, g, b, rf, rb, gf, gb, bf, bb;
	RGB565_union table;
	unsigned char buf;

	rf = (signed int)mFontColor.color.red;
	rb = (signed int)mBgColor.color.red;
	gf = (signed int)mFontColor.color.green;
	gb = (signed int)mBgColor.color.green;
	bf = (signed int)mFontColor.color.blue;
	bb = (signed int)mBgColor.color.blue;

	table = mBgColor;
	buf = table.byte[0];
	table.byte[0] = table.byte[1];
	table.byte[1] = buf;
	mFontColorTable[0] = table.halfword;

	for (signed int i = 1; i < 16; i++)
	{
		r = (rf - rb) * i / 15 + rb;
		g = (gf - gb) * i / 15 + gb;
		b = (bf - bb) * i / 15 + bb;
		table.color.red = r;
		table.color.green = g;
		table.color.blue = b;

		buf = table.byte[0];
		table.byte[0] = table.byte[1];
		table.byte[1] = buf;

		mFontColorTable[i] = table.halfword;
	}
}

void FontColorRgb565::setFontColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mFontColor.color.red = red >> 3;
	mFontColor.color.green = green >> 2;
	mFontColor.color.blue = blue >> 3;
}

void FontColorRgb565::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mBgColor.color.red = red >> 3;
	mBgColor.color.green = green >> 2;
	mBgColor.color.blue = blue >> 3;
}

unsigned short *FontColorRgb565::getColorTable(void)
{
	return mFontColorTable;
}
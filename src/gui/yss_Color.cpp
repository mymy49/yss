/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <gui/Color.h>

bool Color::mReverseRgb = false, Color::mLittleEndian = false;

Color::Color(void)
{
	setToBlack();
	mAlpha = 0xFF;
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mRed = red;
	mGreen = green;
	mBlue = blue;
	mAlpha = alpha;
}

void Color::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mRed = red;
	mGreen = green;
	mBlue = blue;
	mAlpha = alpha;
}

void Color::setColor(Color color)
{
	color.getColor(mRed, mGreen, mBlue, mAlpha);
}

uint16_t Color::getRgb565Code(void)
{
	uint8_t code[2];

	if(mReverseRgb == true)
	{
		if(mLittleEndian == true)
		{
			code [0] = (mGreen & 0xFC) << 3;
			code [0] |= mBlue >> 3;
			code [1] = mRed & 0xF8;
			code [1] |= mGreen >> 5;
		}
		else
		{
			code [1] = (mGreen & 0xFC) << 3;
			code [1] |= mBlue >> 3;
			code [0] = mRed & 0xF8;
			code [0] |= mGreen >> 5;
		}
	}
	else
	{
		if(mLittleEndian == true)
		{
			code [0] = (mGreen & 0xFC) << 3;
			code [0] |= mRed >> 3;
			code [1] = mBlue & 0xF8;
			code [1] |= mGreen >> 5;
		}
		else
		{
			code [1] = (mGreen & 0xFC) << 3;
			code [1] |= mRed >> 3;
			code [0] = mBlue & 0xF8;
			code [0] |= mGreen >> 5;
		}
	}

	return *(uint16_t*)code;
}

void Color::setColorCodeRgb565(uint16_t code)
{
	mAlpha = 0xFF;

	if(mReverseRgb == true)
	{
		if(mLittleEndian == true)
		{
		}
		else
		{
			mBlue = (code >> 5) & 0xF8;
			if(mBlue & 0x80)
				mBlue |= 0x07;
			
			mGreen = code << 5 & 0xE0;
			mGreen |= code >> 11 & 0x1C;
			if(mGreen & 0x80)
				mGreen |= 0x03;

			mRed = code & 0xF8;
			if(mRed & 0x80)
				mRed |= 0x07;
		}
	}
	else
	{
		if(mLittleEndian == true)
		{
		
		}
		else
		{
			mRed = (code >> 5) & 0xF8;
			if(mRed & 0x80)
				mRed |= 0x07;
			
			mGreen = code << 5 & 0xE0;
			mGreen |= code >> 11 & 0x1C;
			if(mGreen & 0x80)
				mGreen |= 0x03;

			mBlue = code & 0xF8;
			if(mBlue & 0x80)
				mBlue |= 0x07;
		}
	}
}

uint16_t Color::getArgb1555Code(void)
{
	uint8_t code[2];

	if(mReverseRgb == true)
	{
		if(mLittleEndian == true)
		{
			code [0] = (mGreen & 0xF8) << 2;
			code [0] |= mBlue >> 3;
			code [1] = (mRed >> 1) & 0x7C;
			code [1] |= mGreen >> 6;
			if(mAlpha)
				code[1] |= 0x80;
		}
		else
		{
			code [1] = (mGreen & 0xF8) << 2;
			code [1] |= mBlue >> 3;
			code [0] = (mRed >> 1) & 0x7C;
			code [0] |= mGreen >> 6;
			if(mAlpha)
				code[0] |= 0x80;
		}
	}
	else
	{
		if(mLittleEndian == true)
		{
			code [0] = (mGreen & 0xF8) << 2;
			code [0] |= mRed >> 3;
			code [1] = (mBlue >> 1) & 0x7C;
			code [1] |= mGreen >> 6;
			if(mAlpha)
				code[1] |= 0x80;
		}
		else
		{
			code [1] = (mGreen & 0xF8) << 2;
			code [1] |= mRed >> 3;
			code [0] = (mBlue >> 1) & 0x7C;
			code [0] |= mGreen >> 6;
			if(mAlpha)
				code[0] |= 0x80;
		}
	}

	return *(uint16_t*)code;
}

void Color::setColorCodeRgb888(uint32_t code)
{
	mAlpha = 0xFF;
	mRed = code >> 16;
	mGreen = code >> 8;
	mBlue = code;
}

uint32_t Color::getRgb888Code(void)
{
	return (uint32_t)mRed << 16 | (uint32_t)mGreen << 8 | (uint32_t)mBlue;
}

void Color::setToRed(void)
{
	mRed = 0xFF;
	mGreen = mBlue = 0x00;
}

void Color::setToGreen(void)
{
	mGreen = 0xFF;
	mRed = mBlue = 0x00;
}

void Color::setToBlue(void)
{
	mBlue = 0xFF;
	mRed = mGreen = 0x00;
}

void Color::setToWhite(void)
{
	mBlue = mRed = mGreen = 0xFF;
}

void Color::setToBlack(void)
{
	mBlue = mRed = mGreen = 0x00;
}

Color Color::calculateFontColorLevel(Color &bgColor, uint8_t level)
{
	int32_t blue = bgColor.getRgb888Code();
	int32_t red = blue >> 16 & 0xFF;
	int32_t green = blue >> 8 & 0xFF;
	blue &= 0xFF;

	red = (mRed - red) * level / 15 + red;
	green = (mGreen - green) * level / 15 + green;
	blue = (mBlue - blue) * level / 15 + blue;

	return Color{(uint8_t)red, (uint8_t)green, (uint8_t)blue};
}		 

void Color::setReverseRgbOrder(bool reverse)
{
	mReverseRgb = reverse;
}

void Color::setLittleEndian(bool reverse)
{
	mLittleEndian = reverse;
}

void Color::getColor(uint8_t &red, uint8_t &green, uint8_t &blue, uint8_t &alpha)
{
	red = mRed;
	green = mGreen;
	blue = mBlue;
	alpha = mAlpha;
}

bool Color::compare(Color color)
{
	uint8_t r, g, b, a;

	color.getColor(r, g, b, a);

	if(mRed != r)
		return true;
	
	if(mGreen != g)
		return true;

	if(mBlue != b)
		return true;

	if(mAlpha != a)
		return true;

	return false;
}


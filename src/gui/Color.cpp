////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <gui/Color.h>

Color::Color(void)
{
	setToBlack();
	mReverseRgb = false;
	mReverseEndian = false;
	mAlpha = 0xFF;
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue)
{
	mRed = red;
	mGreen = green;
	mBlue = blue;
	mAlpha = 0xFF;
	mReverseRgb = false;
	mReverseEndian = false;
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue, bool reverseRgb, bool reverseEndian)
{
	mRed = red;
	mGreen = green;
	mBlue = blue;
	mAlpha = 0xFF;
	mReverseRgb = reverseRgb;
	mReverseEndian = reverseEndian;
}

void Color::setColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mRed = red;
	mGreen = green;
	mBlue = blue;
}

void Color::setColor(Color color)
{
	color.getColor(mRed, mGreen, mBlue, mAlpha, mReverseRgb, mReverseEndian);
}

uint16_t Color::getRgb565Code(void)
{
	uint8_t code[2];

	if(mReverseRgb == true)
	{
		if(mReverseEndian == true)
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
		if(mReverseEndian == true)
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

	return Color{(uint8_t)red, (uint8_t)green, (uint8_t)blue, mReverseRgb, mReverseEndian};
}		 

void Color::setReverseRgbOrder(bool reverse)
{
	mReverseRgb = reverse;
}

void Color::setReverseEndian(bool reverse)
{
	mReverseEndian = reverse;
}

void Color::getColor(uint8_t &red, uint8_t &green, uint8_t &blue, uint8_t &alpha)
{
	red = mRed;
	green = mGreen;
	blue = mBlue;
	alpha = mAlpha;
}

void Color::getColor(uint8_t &red, uint8_t &green, uint8_t &blue, uint8_t &alpha, bool &reverseRgb, bool &reverseEndian)
{
	red = mRed;
	green = mGreen;
	blue = mBlue;
	alpha = mAlpha;
	reverseRgb = mReverseRgb;
	reverseEndian = mReverseEndian;
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


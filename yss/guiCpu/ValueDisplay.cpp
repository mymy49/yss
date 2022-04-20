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

#include <guiCpu/ValueDisplay.h>
#include <string.h>
#include <stdio.h>

ValueDisplay::ValueDisplay(void)
{
	mBgBmp565 = 0;
	mBrush = 0;
	mSize = Size{0, 0};
	mPos = mUnitPos = mValuePos = Pos{0, 0};
	mBgRed = mBgGreen = mBgBlue = 0xFF;
	mFontRed = 0x00;
	mFontGreen = 0xFF;
	mFontBlue = 0x00;
	mOverRed = mOverGreen = mOverBlue = 0xFF;
	mUnderRed = mUnderGreen = mUnderBlue = 0xFF;
	mOverValue = 999999999999.f;
	mUnderValue = -999999999999.f;
	mFont = 0;
	mUnit[0] = mUnit[9] = 0;
	mFormat = 0;
}

void ValueDisplay::setSize(unsigned short width, unsigned short height)
{
	mSize.width = width;
	mSize.height = height;
}

void ValueDisplay::setSize(Size size)
{
	mSize = size;
}

void ValueDisplay::setPosition(Pos pos)
{
	mPos = pos;
}

void ValueDisplay::setPosition(signed short x, signed short y)
{
	mPos.x = x;
	mPos.y = y;
}

void ValueDisplay::setBmp565Brush(Bmp565Brush &brush)
{
	mBrush = &brush;
}

void ValueDisplay::setBmp565Brush(Bmp565Brush *brush)
{
	mBrush = brush;
}

void ValueDisplay::setCpuTft(sac::CpuTft &obj)
{
	mLcd = &obj;
}

void ValueDisplay::setCpuTft(sac::CpuTft *obj)
{
	mLcd = obj;
}

void ValueDisplay::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mBgRed = red;
	mBgGreen = green;
	mBgBlue = blue;
}

void ValueDisplay::setFontColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mFontRed = red;
	mFontGreen = green;
	mFontBlue = blue;
}

void ValueDisplay::setOverValue(float value, unsigned char red, unsigned char green, unsigned char blue)
{
	mOverValue = value;
	mOverRed = red;
	mOverGreen = green;
	mOverBlue = blue;
}

void ValueDisplay::setUnderValue(float value, unsigned char red, unsigned char green, unsigned char blue)
{
	mUnderValue = value;
	mUnderRed = red;
	mUnderGreen = green;
	mUnderBlue = blue;
}

void ValueDisplay::drawBackground(unsigned char unitColorRed, unsigned char unitColorGreen, unsigned char unitColorBlue)
{
	mBrush->setBgColor(mBgRed, mBgGreen, mBgBlue);
	mBrush->setFontColor(unitColorRed, unitColorGreen, unitColorBlue);
	mBrush->setSize(mSize);
	mBrush->setFont(mFont);

	mBrush->clear();
	mBrush->drawString(mUnitPos, mUnit);
	mLcd->drawBmp(mPos, mBrush->getBmp565());
}

void ValueDisplay::setUnit(Pos pos, const char *unit)
{
	mUnitPos = pos;
	memcpy(mUnit, unit, 9);
}

void ValueDisplay::setUnit(signed short x, signed short y, const char *unit)
{
	setUnit(Pos{x, y}, unit);
}

void ValueDisplay::setValue(Pos pos, const char *format)
{
	mValuePos = pos;
	mFormat = format;
}

void ValueDisplay::setValue(signed short x, signed short y, const char *format)
{
	setValue(Pos{x, y}, format);
}

void ValueDisplay::setFont(Font font)
{
	mFont = font;
}

void ValueDisplay::setFont(Font *font)
{
	mFont = *font;
}

void ValueDisplay::drawValue(float value)
{
	Size size = mSize;
	char str[24];

	if(mFormat == 0)
		return;
	
	size.width = mUnitPos.x - mValuePos.x;
	size.height = mSize.height;
	
	mBrush->setBgColor(mBgRed, mBgGreen, mBgBlue);
	mBrush->setSize(size);
	mBrush->setFont(mFont);
	
	if(value <= mUnderValue)
		mBrush->setFontColor(mUnderRed, mUnderGreen, mUnderBlue);
	else if(value >= mOverValue)
		mBrush->setFontColor(mOverRed, mOverGreen, mOverBlue);
	else
		mBrush->setFontColor(mFontRed, mFontGreen, mFontBlue);
	
	sprintf(str, mFormat, value);
	mBrush->clear();
	mBrush->drawString(Pos{0, mValuePos.y}, str);
	mLcd->drawBmp( Pos{mValuePos.x + mPos.x, 0 + mPos.y}, mBrush->getBmp565());
}

#endif

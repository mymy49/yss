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

#ifndef YSS_GUI_CPU_VALUE_DISPLAY__H_
#define YSS_GUI_CPU_VALUE_DISPLAY__H_

#include <gui/util.h>
#include <gui/Bmp565.h>
#include <gui/Font.h>
#include <gui/Bmp565Brush.h>
#include <sac/CpuTft.h>

class ValueDisplay
{
  protected:
	Bmp565 *mBgBmp565;
	Bmp565Brush *mBrush;
	unsigned int mBufferSize;
	sac::CpuTft *mLcd;
	unsigned char mBgRed, mBgGreen, mBgBlue;
	unsigned char mFontRed, mFontGreen, mFontBlue;
	unsigned char mOverRed, mOverGreen, mOverBlue;
	unsigned char mUnderRed, mUnderGreen, mUnderBlue;
	char mUnit[10];
	const char *mFormat;
	
	Size mSize;
	Pos mPos, mUnitPos, mValuePos;
	Font mFont;
	float mOverValue, mUnderValue;

  public:
	ValueDisplay(void);
	void setBmp565Brush(Bmp565Brush &brush);
	void setBmp565Brush(Bmp565Brush *brush);
	void setCpuTft(sac::CpuTft &obj);
	void setCpuTft(sac::CpuTft *obj);
	void setSize(unsigned short width, unsigned short height);
	void setSize(Size size);
	void setPosition(Pos pos);
	void setPosition(signed short x, signed short y);
	void setBgColor(unsigned char red, unsigned char green, unsigned char blue);
	void setFontColor(unsigned char red, unsigned char green, unsigned char blue);
	void setOverValue(float value, unsigned char red = 0xFF, unsigned char green = 0x00, unsigned char blue = 0x00);
	void setUnderValue(float value, unsigned char red = 0x00, unsigned char green = 0x00, unsigned char blue = 0xFF);
	void drawBackground(unsigned char unitColorRed = 0x00, unsigned char unitColorGreen = 0x00, unsigned char unitColorBlue = 0x00);
	void drawValue(float value);
	void setUnit(Pos pos, const char *unit);
	void setUnit(signed short x, signed short y, const char *unit);
	void setValue(Pos pos, const char *format = "%f");
	void setValue(signed short x, signed short y, const char *format = "%f");
	void setFont(Font font);
	void setFont(Font *font);
};

#endif
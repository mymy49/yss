////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_GUI_RGB565__H_
#define YSS_GUI_RGB565__H_

#include "FrameBuffer.h"

class Rgb565 : public FrameBuffer
{
protected:
	uint16_t mFontColorTable[16];
	uint16_t mBrushColorCode, mBgColorCode;

public:
	Rgb565(void);

	uint8_t drawChar(Position pos, uint32_t utf8);

	void setColorLevel(uint8_t level);

	void drawBmp565(Position pos, const Bmp565 *image);

	void drawBmp565(Position pos, const Bmp565 &image);

	void clearRectangle(Position pos, Size size);

	// Brush
	virtual void clear(void);

	virtual void drawDot(int16_t x, int16_t y); // virtual 0

	virtual void drawDot(int16_t x, int16_t y, Color color); // virtual 0

	virtual void eraseDot(Position pos); // virtual 0

	virtual void updateFontColor(void); // virtual 0

	virtual void setBrushColor(Color color);
	
	virtual void setBrushColor(uint8_t red, uint8_t green, uint8_t blue);
	
	virtual void setBackgroundColor(Color color);
	
	virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue);
};

#endif


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

#ifndef YSS_GUI_BRUSH__H_
#define YSS_GUI_BRUSH__H_

#include "util.h"
#include <gui/Font.h>

class Bmp565;
class Bmp888;
class Bmp1555;

class Brush
{
  protected:
	Size mSize;
	Font mFont;

  public:
	Brush(void);
	~Brush(void);
	void setSize(Size size);

	void drawLine(Position start, Position end);
	void drawTriangle(Position p1, Position p2, Position p3);
	void drawRect(Position p1, Position p2);
	void drawRect(Position p1, Size size);
	void drawCircle(Position p1, uint16_t r);
	uint8_t drawString(Position pos, const char *str);
	uint8_t drawString(Position pos, const char *str, uint8_t charWidth);

	void eraseRect(Position p1, Position p2);
	void eraseRect(Position pos, Size size);
	void clear(void);

	Size calculateStringSize(const char *str);

	void setFont(Font font);


	virtual uint8_t drawChar(Position pos, uint32_t utf8);
	virtual void drawBmp(Position pos, const Bmp565 *image);
	virtual void drawBmp(Position pos, const Bmp565 &image);

	virtual void drawBmp(Position pos, const Bmp888 *image);
//	virtual void drawBmp(Position pos, const Bmp888 &image);

	virtual void drawBmp(Position pos, const Bmp1555 *image);
	virtual void drawBmp(Position pos, const Bmp1555 &image);

	virtual void fill(void);
	virtual void fillCircle(Position p1, uint16_t r);
	virtual void fillRect(Position p1, Position p2);
	virtual void fillRect(Position pos, Size size);
	virtual void fillTriangle(Position p1, Position p2, Position p3);

	virtual void drawDot(int16_t x, int16_t y) = 0;
	virtual void drawDot(int16_t x, int16_t y, uint16_t color) = 0;
	virtual void drawDot(int16_t x, int16_t y, uint32_t color) = 0;
	virtual void drawFontDot(int16_t x, int16_t y, uint8_t color) = 0;
	virtual void eraseDot(Position pos) = 0;
	virtual void setBrushColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255) = 0;
	virtual void setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255) = 0;
	virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue) = 0;
};

#endif


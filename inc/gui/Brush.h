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

#ifndef YSS_GUI_BRUSH__H_
#define YSS_GUI_BRUSH__H_

#include "Color.h"
#include "Font.h"
#include "util.h"

class Bmp565;
class Bmp888;
class Bmp1555;

class Brush
{
protected:
	Size mSize;
	Font mFont;
	Color mBgColor, mFontColor, mBrushColor;

public:
	Brush(void);

	~Brush(void);

	void setSize(Size size);

	void setReverseRgbOrder(bool reverse);

	void setReverseEndian(bool reverse);

	void drawLine(Position start, Position end);
	
	void drawTriangle(Position p1, Position p2, Position p3);
	
	void drawRect(Position p1, Position p2);
	
	void drawRect(Position p1, Size size);
	
	void drawCircle(Position p1, uint16_t r);
	
	uint8_t drawString(Position pos, const char *str);
	
	uint8_t drawString(Position pos, const char *str, uint8_t charWidth);

	void eraseRect(Position p1, Position p2);
	
	void eraseRect(Position pos, Size size);
	
	Size calculateStringSize(const char *str);

	void setFont(Font font);

	virtual void clear(void);
	
	virtual void setBrushColor(Color color);
	
	virtual void setBrushColor(uint8_t red, uint8_t green, uint8_t blue);
	
	// 현재 설정된 브러쉬 색을 얻어온다.
	//
	// 반환
	//		현재 설정된 브러쉬 색을 반환한다.
	virtual Color getBrushColor(void);
	
	virtual void setFontColor(Color color);
	
	virtual void setFontColor(uint8_t red, uint8_t green, uint8_t blue);

	// 현재 설정된 글자색을 얻어온다.
	//
	// 반환
	//		현재 설정된 글자색을 반환한다.
	virtual Color getFontColor(void);
	
	// 브러쉬의 배경색을 설정한다.
	//
	// Color color
	//		배경색을 설정한다.
	virtual void setBackgroundColor(Color color);
	
	// 브러쉬의 배경색을 설정한다.
	//
	// uint8_t red
	//		배경색의 빨간색 농도를 설정한다.
	// uint8_t green
	//		배경색의 녹색 농도를 설정한다.
	// uint8_t blue
	//		배경색의 파랑색 농도를 설정한다.
	virtual void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue);

	// 현재 설정된 배경색을 얻어온다.
	//
	// 반환
	//		현재 설정된 배경색을 반환한다.
	virtual Color getBackgroundColor(void);

	virtual uint8_t drawChar(Position pos, uint32_t utf8);
	
	virtual void drawBmp(Position pos, const Bmp1555 *image);
	
	virtual void drawBmp(Position pos, const Bmp1555 &image);

	virtual void fill(void);
	
	virtual void fillCircle(Position p1, uint16_t r);
	
	virtual void fillRect(Position p1, Position p2);
	
	virtual void fillRect(Position pos, Size size);
	
	virtual void fillTriangle(Position p1, Position p2, Position p3);

	virtual void drawDot(int16_t x, int16_t y) = 0;
	
	virtual void drawDot(int16_t x, int16_t y, Color color) = 0;
	
	virtual void eraseDot(Position pos) = 0;

	virtual void updateFontColor(void) = 0;
};

#endif


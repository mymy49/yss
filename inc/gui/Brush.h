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

#ifndef YSS_GUI_BRUSH__H_
#define YSS_GUI_BRUSH__H_

#include "Color.h"
#include "Font.h"
#include "FrameBuffer.h"
#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE
class Object;
class Painter;
#endif

class Brush : public FrameBuffer
{
public:
	Brush(void);

	virtual ~Brush(void);
	
	// 선을 그리는 함수이다.
	// Position_t 구조체 두 개로 시작점과 끝접을 지정하여 선을 그린다.
	// 선의 색상은 setBrushColor() 함수를 통해 설정된다.
	// 
	// Position_t start
	//		선의 시작 점을 설정한다.
	// Position_t end
	//		선의 끝 점을 설정한다.
	void drawLine(Position_t start, Position_t end);
	
	// 삼각형을 그리는 함수이다.
	// Position_t 구조체 세 개로 삼각형의 각 꼭지점을 지정하여 선을 그린다.
	// 선의 색상은 setBrushColor() 함수를 통해 설정된다.
	// 
	// Position_t p1
	//		삼각형의 꼭지점1을 설정한다.
	// Position_t p2
	//		삼각형의 꼭지점2를 설정한다.
	// Position_t p3
	//		삼각형의 꼭지점3을 설정한다.
	void drawTriangle(Position_t p1, Position_t p2, Position_t p3);
	
	// 직사각형을 그리는 함수이다.
	// 사각형의 시작점과 그 크기를 지정하여 그린다.
	// 선의 색상은 setBrushColor() 함수를 통해 설정된다.
	// 
	// Position_t pos
	//		사각형의 시작 좌표를 설정한다.
	// Size_t size
	//		사각형의 크기를 설정한다.
	void drawRect(Position_t pos, Size_t size);

	// 직사각형을 그리는 함수이다.
	// 직사각형의 대각선을 꼭지점을 지정하는 사각형을 그린다.
	// 선의 색상은 setBrushColor() 함수를 통해 설정된다.
	// 
	// Position_t p1
	//		사각형 대각선의 꼭지점 1을 지정하는 좌표를 설정한다.
	// Position_t p2
	//		사각형 대각선의 꼭지점 2를 지정하는 좌표를 설정한다.
	void drawRect(Position_t p1, Position_t p2);
	
	// 원을 그리는 함수이다.
	// 원의 중심점과 반지름을 지정하여 원을 그린다.
	// 선의 색상은 setBrushColor() 함수를 통해 설정된다.
	// 
	// Position_t pos
	//		원의 중심점을 설정한다.
	// uint16_t r
	//		원의 반지름을 설정한다.
	void drawCircle(Position_t pos, uint16_t r);
	
	uint8_t drawString(Position_t pos, const char *str);
	
	uint8_t drawString(Position_t pos, const char *str, uint8_t charWidth);

	void eraseRectangle(Position_t p1, Position_t p2);
	
	void eraseRectangle(Position_t pos, Size_t size);
	
	Size_t calculateStringSize(const char *str);

	void setFont(Font font);

	Font* getFont(void);

	void setBrushColor(Color color);
	
	void setBrushColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xFF);
	
	void setFontColor(Color color);
	
	void setFontColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xFF);

	// 브러쉬의 배경색을 설정한다.
	//
	// Color color
	//		배경색을 설정한다.
	void setBackgroundColor(Color color);
	
	// 브러쉬의 배경색을 설정한다.
	//
	// uint8_t red
	//		배경색의 빨간색 농도를 설정한다.
	// uint8_t green
	//		배경색의 녹색 농도를 설정한다.
	// uint8_t blue
	//		배경색의 파랑색 농도를 설정한다.
	void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xFF);

	virtual uint8_t drawChar(Position_t pos, uint32_t utf8);

	virtual void drawBitmapBase(Position_t pos, const Bitmap_t &bitmap);

	void drawBitmap(Position_t pos, const Bitmap_t &bitmap);

	void drawBitmap(Position_t pos, const Bitmap_t *bitmap);

	virtual void drawBitmapFileBase(Position_t pos, const BitmapFile_t &bitmap);

	void drawBitmapFile(Position_t pos, const BitmapFile_t &bitmap);

	void drawBitmapFile(Position_t pos, const BitmapFile_t *bitmap);
	
	void fillCircle(Position_t p1, uint16_t r);

	virtual void fillRectBase(Position_t pos, Size_t size, uint32_t color);

	void fillRect(Position_t pos, Size_t size, uint32_t color);

	void fillRect(Position_t pos, Size_t size, Color color);

	void fillRect(Position_t pos, Size_t size);

	void fillRect(Position_t p1, Position_t p2);

	void fill(void);

	void clear(void);

	void fillTriangle(Position_t p1, Position_t p2, Position_t p3);

	virtual void updateFontColor(void);

	virtual void drawDot(int16_t x, int16_t y) = 0;
	
	virtual void drawDot(int16_t x, int16_t y, Color color) = 0;

	virtual void drawDot(int16_t x, int16_t y, uint32_t color) = 0;
	
	void eraseDot(Position_t pos);


#if USE_GUI && YSS_L_HEAP_USE
	virtual void drawObjectToPartialArea(Position_t pos, Size_t size, Object *src) = 0;

	virtual void drawPainter(Position_t pos, Painter *src) = 0;
#endif

protected:
	Font mFont;
	Color mFontColor, mBgColor;
	uint32_t mBgColorCode, mBrushColorCode;
	uint32_t mFontColorCodeTable[16];

	void translateFromPositionToSize(Position_t &desPos, Size_t &desSize, Position_t &srcPos1, Position_t &srcPos2);
};

#endif


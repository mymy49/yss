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

#ifndef YSS_GUI_ARGB1555__H_
#define YSS_GUI_ARGB1555__H_
/*
#include "Brush.h"
#include "FrameBuffer.h"

struct ARGB1555_struct
{
	unsigned blue : 5;
	unsigned green : 5;
	unsigned red : 5;
	unsigned alpha : 1;
};

union ARGB1555_union
{
	ARGB1555_struct color;
	uint16_t data;
};

class Argb1555 : public Brush, public FrameBuffer
{
	ARGB1555_union mBrushColor, mBgColor;
public:
	Argb1555(void);
	int8_t drawChar(Pos pos, int8_t* ch);
	int8_t drawChar(Pos pos, int8_t ch);
	void drawDot(Pos pos);
	void eraseDot(Pos pos);
	void drawBmp565(Pos pos, const Bmp565 *image);
	void drawDotQuick(Pos pos);
	void fill(void);
	void clear(void);
	void fillRect(Pos p1, Pos p2);
	void fillRect(Pos pos, Size size);

//	void draw(Argb1555 obj, Pos pos);
	void setSize(Size size);
	void setColor(ARGB1555_struct);
	void setColor(ARGB1555_union);
	void setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
	void setColor(uint8_t *arry);
	void setColor(uint16_t color);
	void setBgColor(ARGB1555_struct);
	void setBgColor(ARGB1555_union);
	void setBgColor(uint8_t red, uint8_t green, uint8_t blue);
	void setBgColor(uint8_t *arry);
	void setBgColor(uint16_t color);
};
*/
#endif
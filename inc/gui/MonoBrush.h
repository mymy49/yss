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

#ifndef YSS_GUI_MONO_BRUSH__H_
#define YSS_GUI_MONO_BRUSH__H_

#include "util.h"
#include <gui/Font.h>

class MonoBrush
{
  protected:
	Size mSize;
	Font mFont;

	void setSize(Size size);
	void setSize(uint16_t width, uint16_t height);

  public:
	MonoBrush(void);

	void setFont(Font font);
	uint8_t drawChar(Position pos, uint32_t utf8, bool data = true);
	uint8_t drawString(Position pos, const char *str, bool data = true);
	void clear(void);
	void fill(void);
	void drawLine(int16_t sx, int16_t sy, int16_t ex, int16_t ey, bool data = true);
	void drawLine(Position start, Position end, bool data = true);
	void drawRect(Position p1, Position p2, bool data = true);
	void drawRect(Position p1, Size size, bool data = true);
	void drawCircle(Position pos, uint16_t radius, bool data = true);
	void fillRect(Position p1, Position p2, bool data = true);
	void fillRect(Position pos, Size size, bool data = true);

	virtual void drawDot(uint16_t x, uint16_t y, bool data = true) = 0;
};

#endif



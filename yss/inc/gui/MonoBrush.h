////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021 yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2021.02.23 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_GUI_MONO_BRUSH__H_
#define YSS_GUI_MONO_BRUSH__H_

#include "util.h"
#include <gui/Font.h>
#include <yss/Mutex.h>

class MonoBrush
{
  protected:
	Size mSize;
	Mutex mMutex;
	Font mFont;

	void setSize(Size size);
	void setSize(unsigned short width, unsigned short height);

  public:
	MonoBrush(void);

	void setFont(Font font);
	unsigned char drawChar(Pos pos, unsigned int utf8, bool data = true);
	unsigned char drawString(Pos pos, const char *str, bool data = true);
	void clear(void);
	void fill(void);
	void drawLine(signed short sx, signed short sy, signed short ex, signed short ey, bool data = true);
	void drawLine(Pos start, Pos end, bool data = true);
	void drawRect(Pos p1, Pos p2, bool data = true);
	void drawRect(Pos p1, Size size, bool data = true);
	void drawCircle(Pos pos, unsigned short radius, bool data = true);
	void fillRect(Pos p1, Pos p2, bool data = true);
	void fillRect(Pos pos, Size size, bool data = true);

	virtual void drawDot(unsigned short x, unsigned short y, bool data = true) = 0;
};

#endif
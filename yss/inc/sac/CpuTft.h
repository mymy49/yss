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

#ifndef YSS_SAC_CPU_TFT__H_
#define YSS_SAC_CPU_TFT__H_

#include <gui/Brush.h>
#include <gui/FontColorRgb565.h>
#include <yss/thread.h>

namespace sac
{
class CpuTft : public Brush
{
	Mutex mMutex;

  protected:
	RGB565_union mBrushColor, mBgColor;
	FontColorRgb565 mFontColor;

  public:
	CpuTft(void);
	void lock(void);
	void unlock(void);

	void setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
	void setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
	void setBgColor(unsigned char red, unsigned char green, unsigned char blue);

	virtual void fillRect(Pos pos, Size size);
	virtual void fillRect(Pos p1, Pos p2);
	virtual void clear(void);

	virtual unsigned char drawChar(Pos pos, unsigned int utf8);

	virtual void drawDots(unsigned short x, unsigned short y, unsigned short color, unsigned short size) = 0;
	virtual void drawDots(unsigned short x, unsigned short y, unsigned short *src, unsigned short size) = 0;

	virtual void drawBmp(Pos pos, const Bmp565 *image);
	virtual void drawBmp(Pos pos, const Bmp565 &image);
};
}

#endif
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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2020.06.07 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_GUI_CPU_FRAME_BUFFER__H_
#define YSS_GUI_CPU_FRAME_BUFFER__H_

#include "Object.h"
#include <sac/CpuTft.h>
#include <gui/Brush.h>

class CpuFrameBuffer : public Brush
{
	sac::CpuTft *mLcd;
	unsigned int mBufferSize;
	unsigned char *mFrameBuffer;
	bool mOkFlag;

public :
	CpuFrameBuffer(void);
	virtual ~CpuFrameBuffer(void);
    bool init(sac::CpuTft *obj);
    void refresh(void);
    void refresh(signed short x, signed short y, unsigned short width, unsigned short height);
    void clear(void);
    void drawDot(signed short x, signed short y);
    void drawDot(signed short x, signed short y, unsigned short color);
	void drawDot(signed short x, signed short y, unsigned int color);
	void drawFontDot(signed short x, signed short y, unsigned char color);
	void eraseDot(Pos pos);
	void fillRect(Pos p1, Pos p2);
	void fillRect(Pos pos, Size size);
	void eraseRect(Pos p1, Pos p2);
	void eraseRect(Pos pos, Size size);
	void fill(void);
   	void drawBmp565(Pos pos, const Bmp565 *image);
	void drawBmp565(Pos pos, const Bmp565 &image);

	void setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
	void setFontColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
	void setBgColor(unsigned char red, unsigned char green, unsigned char blue);
};

#endif

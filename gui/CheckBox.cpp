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
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <config.h>
#include <drv/peripherals.h>
#include <gui/CheckBox.h>

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE

CheckBox::CheckBox(void)
{
	mState = true;
	mPushHandler = 0;
	mText = 0;

    setColor(0x00, 0x00, 0x00);
}

Object* CheckBox::handlerPush(Pos pos)
{
	mState = !mState;
	paint();
	update();
    if(mPushHandler)
		mPushHandler(mState);
	return this;
}

void CheckBox::paint(void)
{
	if(mFrameBuffer == 0)
		return;

	signed short width = mSize.width, height = mSize.height;
    Pos p1, p2;
	
    if(width > height)
		width = height;
	else
		height = width;

	clear(); 
	
	drawRect(Pos{2, 2}, Size{width-5, height-5});

	if(mState)
    {
		p1 = Pos{4, 4};
        p2 = Pos{width/2, height-6};
		drawLine(p1, p2);
        p1.x++;
        p2.x++;
		drawLine(p1, p2);
		
        p1 = p2;
        p1.x--;
        p2 = Pos{width-6, 4};
		drawLine(p1, p2);
        p1.x++;
        p2.x++;
		drawLine(p1, p2);
    }

    if(mText && mFont.isAble())
    {
		drawString(Pos{(signed short)(width + 2), (signed short)(2)}, (char*)mText);
    }
}

void CheckBox::setText(const char *text)
{
	mText = text;
}

void CheckBox::setPushEventHandler(void (*handler)(bool))
{
	mPushHandler = handler;
}

#endif

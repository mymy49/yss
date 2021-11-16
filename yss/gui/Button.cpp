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
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <yss/instance.h>
#include <config.h>
#include <yss/gui.h>
#include <gui/Button.h>
#include <string.h>

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE

Button::Button(void)
{
	mState = false;
	mUpHandler = 0;
	mPushHandler = 0;
	mText = 0;
}

void Button::paint(void)
{
	if (mFrameBuffer == 0)
		return;

	unsigned short width, height;
	if (mState)
	{
		clear();
		setColor(20, 20, 20);
		drawLine(Pos{0, 0}, Pos{(signed short)(mSize.width - 1), 0});
		drawLine(Pos{0, 0}, Pos{0, (signed short)(mSize.height - 1)});
		setColor(40, 40, 40);
		drawLine(Pos{1, 1}, Pos{(signed short)(mSize.width - 2), 1});
		drawLine(Pos{1, 1}, Pos{1, (signed short)(mSize.height - 2)});
		setColor(60, 60, 60);
		drawLine(Pos{2, 2}, Pos{(signed short)(mSize.width - 3), 2});
		drawLine(Pos{2, 2}, Pos{2, (signed short)(mSize.height - 3)});

		setColor(160, 160, 160);
		drawLine(Pos{(signed short)(mSize.width - 3), (signed short)(mSize.height - 3)}, Pos{(signed short)(mSize.width - 3), 2});
		drawLine(Pos{2, (signed short)(mSize.height - 3)}, Pos{(signed short)(mSize.width - 3), (signed short)(mSize.height - 3)});

		setColor(192, 192, 192);
		drawLine(Pos{(signed short)(mSize.width - 2), (signed short)(mSize.height - 2)}, Pos{(signed short)(mSize.width - 2), 1});
		drawLine(Pos{1, (signed short)(mSize.height - 2)}, Pos{(signed short)(mSize.width - 2), (signed short)(mSize.height - 2)});

		setColor(224, 224, 224);
		drawLine(Pos{(signed short)(mSize.width - 1), (signed short)(mSize.height - 1)}, Pos{(signed short)(mSize.width - 1), 0});
		drawLine(Pos{0, (signed short)(mSize.height - 1)}, Pos{(signed short)(mSize.width - 1), (signed short)(mSize.height - 1)});
	}
	else
	{
		clear();
		setColor(224, 224, 224);
		drawLine(Pos{0, 0}, Pos{(signed short)(mSize.width - 1), 0});
		drawLine(Pos{0, 0}, Pos{0, (signed short)(mSize.height - 1)});
		setColor(192, 192, 192);
		drawLine(Pos{1, 1}, Pos{(signed short)(mSize.width - 2), 1});
		drawLine(Pos{1, 1}, Pos{1, (signed short)(mSize.height - 2)});
		setColor(160, 160, 160);
		drawLine(Pos{2, 2}, Pos{(signed short)(mSize.width - 3), 2});
		drawLine(Pos{2, 2}, Pos{2, (signed short)(mSize.height - 3)});

		setColor(60, 60, 60);
		drawLine(Pos{(signed short)(mSize.width - 3), (signed short)(mSize.height - 3)}, Pos{(signed short)(mSize.width - 3), 2});
		drawLine(Pos{2, (signed short)(mSize.height - 3)}, Pos{(signed short)(mSize.width - 3), (signed short)(mSize.height - 3)});

		setColor(40, 40, 40);
		drawLine(Pos{(signed short)(mSize.width - 2), (signed short)(mSize.height - 2)}, Pos{(signed short)(mSize.width - 2), 1});
		drawLine(Pos{1, (signed short)(mSize.height - 2)}, Pos{(signed short)(mSize.width - 2), (signed short)(mSize.height - 2)});

		setColor(20, 20, 20);
		drawLine(Pos{(signed short)(mSize.width - 1), (signed short)(mSize.height - 1)}, Pos{(signed short)(mSize.width - 1), 0});
		drawLine(Pos{0, (signed short)(mSize.height - 1)}, Pos{(signed short)(mSize.width - 1), (signed short)(mSize.height - 1)});
	}

	if (mText && mFont.isAble())
	{
		width = mFont.getStringWidth((char *)mText);
		height = mFont.getStringHeight((char *)mText);
		drawString(Pos{(signed short)(mSize.width / 2 - width / 2), (signed short)(mSize.height / 2 - height / 2)}, (char *)mText);
	}
}

void Button::setPushEventHandler(void (*handler)(void))
{
	mPushHandler = handler;
}

void Button::setUpEventHandler(void (*handler)(void))
{
	mUpHandler = handler;
}

void Button::setText(const char *text)
{
	mText = text;
}

Object *Button::handlerPush(Pos pos)
{
	mState = true;
	paint();
	update();
	if (mPushHandler)
		mPushHandler();
	return this;
}

Object *Button::handlerUp(void)
{
	mState = false;
	paint();
	update();
	if (mUpHandler)
		mUpHandler();
	return this;
}

#endif
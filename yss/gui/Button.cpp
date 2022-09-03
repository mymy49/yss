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

	uint16_t width, height;
	if (mState)
	{
		clear();
		setBrushColor(20, 20, 20);
		drawLine(Position{0, 0}, Position{(int16_t)(mSize.width - 1), 0});
		drawLine(Position{0, 0}, Position{0, (int16_t)(mSize.height - 1)});
		setBrushColor(40, 40, 40);
		drawLine(Position{1, 1}, Position{(int16_t)(mSize.width - 2), 1});
		drawLine(Position{1, 1}, Position{1, (int16_t)(mSize.height - 2)});
		setBrushColor(60, 60, 60);
		drawLine(Position{2, 2}, Position{(int16_t)(mSize.width - 3), 2});
		drawLine(Position{2, 2}, Position{2, (int16_t)(mSize.height - 3)});

		setBrushColor(160, 160, 160);
		drawLine(Position{(int16_t)(mSize.width - 3), (int16_t)(mSize.height - 3)}, Position{(int16_t)(mSize.width - 3), 2});
		drawLine(Position{2, (int16_t)(mSize.height - 3)}, Position{(int16_t)(mSize.width - 3), (int16_t)(mSize.height - 3)});

		setBrushColor(192, 192, 192);
		drawLine(Position{(int16_t)(mSize.width - 2), (int16_t)(mSize.height - 2)}, Position{(int16_t)(mSize.width - 2), 1});
		drawLine(Position{1, (int16_t)(mSize.height - 2)}, Position{(int16_t)(mSize.width - 2), (int16_t)(mSize.height - 2)});

		setBrushColor(224, 224, 224);
		drawLine(Position{(int16_t)(mSize.width - 1), (int16_t)(mSize.height - 1)}, Position{(int16_t)(mSize.width - 1), 0});
		drawLine(Position{0, (int16_t)(mSize.height - 1)}, Position{(int16_t)(mSize.width - 1), (int16_t)(mSize.height - 1)});
	}
	else
	{
		clear();
		setBrushColor(224, 224, 224);
		drawLine(Position{0, 0}, Position{(int16_t)(mSize.width - 1), 0});
		drawLine(Position{0, 0}, Position{0, (int16_t)(mSize.height - 1)});
		setBrushColor(192, 192, 192);
		drawLine(Position{1, 1}, Position{(int16_t)(mSize.width - 2), 1});
		drawLine(Position{1, 1}, Position{1, (int16_t)(mSize.height - 2)});
		setBrushColor(160, 160, 160);
		drawLine(Position{2, 2}, Position{(int16_t)(mSize.width - 3), 2});
		drawLine(Position{2, 2}, Position{2, (int16_t)(mSize.height - 3)});

		setBrushColor(60, 60, 60);
		drawLine(Position{(int16_t)(mSize.width - 3), (int16_t)(mSize.height - 3)}, Position{(int16_t)(mSize.width - 3), 2});
		drawLine(Position{2, (int16_t)(mSize.height - 3)}, Position{(int16_t)(mSize.width - 3), (int16_t)(mSize.height - 3)});

		setBrushColor(40, 40, 40);
		drawLine(Position{(int16_t)(mSize.width - 2), (int16_t)(mSize.height - 2)}, Position{(int16_t)(mSize.width - 2), 1});
		drawLine(Position{1, (int16_t)(mSize.height - 2)}, Position{(int16_t)(mSize.width - 2), (int16_t)(mSize.height - 2)});

		setBrushColor(20, 20, 20);
		drawLine(Position{(int16_t)(mSize.width - 1), (int16_t)(mSize.height - 1)}, Position{(int16_t)(mSize.width - 1), 0});
		drawLine(Position{0, (int16_t)(mSize.height - 1)}, Position{(int16_t)(mSize.width - 1), (int16_t)(mSize.height - 1)});
	}

	if (mText && mFont.isAble())
	{
		width = mFont.getStringWidth((int8_t *)mText);
		height = mFont.getStringHeight((int8_t *)mText);
		drawString(Position{(int16_t)(mSize.width / 2 - width / 2), (int16_t)(mSize.height / 2 - height / 2)}, (int8_t *)mText);
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

void Button::setText(const int8_t *text)
{
	mText = text;
}

Object *Button::handlerPush(Position pos)
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
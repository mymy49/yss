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

#include <config.h>
#include <yss/gui.h>
#include <gui/CheckBox.h>
#include <yss/instance.h>

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE

CheckBox::CheckBox(void)
{
	mState = true;
	mPushHandler = 0;
	mText = 0;

	setBrushColor(0x00, 0x00, 0x00);
}

Object *CheckBox::handlerPush(Position pos)
{
	mState = !mState;
	paint();
	update();
	if (mPushHandler)
		mPushHandler(mState);
	return this;
}

void CheckBox::paint(void)
{
	if (mFrameBuffer == 0)
		return;

	int16_t width = mSize.width, height = mSize.height;
	Position p1, p2;

	if (width > height)
		width = height;
	else
		height = width;

	clear();

	drawRect(Position{2, 2}, Size{(uint16_t)(width - 5), (uint16_t)(height - 5)});

	if (mState)
	{
		p1 = Position{4, 4};
		p2 = Position{(int16_t)(width / 2), (int16_t)(height - 6)};
		drawLine(p1, p2);
		p1.x++;
		p2.x++;
		drawLine(p1, p2);

		p1 = p2;
		p1.x--;
		p2 = Position{(int16_t)(width - 6), 4};
		drawLine(p1, p2);
		p1.x++;
		p2.x++;
		drawLine(p1, p2);
	}

	if (mText && mFont.isAble())
	{
		drawString(Position{(int16_t)(width + 2), (int16_t)(2)}, (int8_t *)mText);
	}
}

void CheckBox::setText(const int8_t *text)
{
	mText = text;
}

void CheckBox::setPushEventHandler(void (*handler)(bool))
{
	mPushHandler = handler;
}

#endif
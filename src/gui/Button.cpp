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

#include <yss/instance.h>
#include <config.h>
#include <yss/gui.h>
#include <gui/Button.h>
#include <string.h>

#if USE_GUI && YSS_L_HEAP_USE

Button::Button(void)
{
	mState = false;
	mUpHandler = 0;
	mPushHandler = 0;
	mText = 0;

	mFrameBuffer->setBackgroundColor(128, 128, 128);
}

void Button::paint(void)
{
	Size size = mFrameBuffer->getSize();
	Font *font = mFrameBuffer->getFont();

	if (mFrameBuffer == 0)
		return;

	uint16_t width, height;
	if (mState)
	{
		mFrameBuffer->clear();
		mFrameBuffer->setBrushColor(20, 20, 20);
		mFrameBuffer->drawLine(Position{0, 0}, Position{(int16_t)(size.width - 1), 0});
		mFrameBuffer->drawLine(Position{0, 0}, Position{0, (int16_t)(size.height - 1)});
		mFrameBuffer->setBrushColor(40, 40, 40);
		mFrameBuffer->drawLine(Position{1, 1}, Position{(int16_t)(size.width - 2), 1});
		mFrameBuffer->drawLine(Position{1, 1}, Position{1, (int16_t)(size.height - 2)});
		mFrameBuffer->setBrushColor(60, 60, 60);
		mFrameBuffer->drawLine(Position{2, 2}, Position{(int16_t)(size.width - 3), 2});
		mFrameBuffer->drawLine(Position{2, 2}, Position{2, (int16_t)(size.height - 3)});

		mFrameBuffer->setBrushColor(160, 160, 160);
		mFrameBuffer->drawLine(Position{(int16_t)(size.width - 3), (int16_t)(size.height - 3)}, Position{(int16_t)(size.width - 3), 2});
		mFrameBuffer->drawLine(Position{2, (int16_t)(size.height - 3)}, Position{(int16_t)(size.width - 3), (int16_t)(size.height - 3)});

		mFrameBuffer->setBrushColor(192, 192, 192);
		mFrameBuffer->drawLine(Position{(int16_t)(size.width - 2), (int16_t)(size.height - 2)}, Position{(int16_t)(size.width - 2), 1});
		mFrameBuffer->drawLine(Position{1, (int16_t)(size.height - 2)}, Position{(int16_t)(size.width - 2), (int16_t)(size.height - 2)});

		mFrameBuffer->setBrushColor(224, 224, 224);
		mFrameBuffer->drawLine(Position{(int16_t)(size.width - 1), (int16_t)(size.height - 1)}, Position{(int16_t)(size.width - 1), 0});
		mFrameBuffer->drawLine(Position{0, (int16_t)(size.height - 1)}, Position{(int16_t)(size.width - 1), (int16_t)(size.height - 1)});
	}
	else
	{
		mFrameBuffer->clear();
		mFrameBuffer->setBrushColor(224, 224, 224);
		mFrameBuffer->drawLine(Position{0, 0}, Position{(int16_t)(size.width - 1), 0});
		mFrameBuffer->drawLine(Position{0, 0}, Position{0, (int16_t)(size.height - 1)});
		mFrameBuffer->setBrushColor(192, 192, 192);
		mFrameBuffer->drawLine(Position{1, 1}, Position{(int16_t)(size.width - 2), 1});
		mFrameBuffer->drawLine(Position{1, 1}, Position{1, (int16_t)(size.height - 2)});
		mFrameBuffer->setBrushColor(160, 160, 160);
		mFrameBuffer->drawLine(Position{2, 2}, Position{(int16_t)(size.width - 3), 2});
		mFrameBuffer->drawLine(Position{2, 2}, Position{2, (int16_t)(size.height - 3)});

		mFrameBuffer->setBrushColor(60, 60, 60);
		mFrameBuffer->drawLine(Position{(int16_t)(size.width - 3), (int16_t)(size.height - 3)}, Position{(int16_t)(size.width - 3), 2});
		mFrameBuffer->drawLine(Position{2, (int16_t)(size.height - 3)}, Position{(int16_t)(size.width - 3), (int16_t)(size.height - 3)});

		mFrameBuffer->setBrushColor(40, 40, 40);
		mFrameBuffer->drawLine(Position{(int16_t)(size.width - 2), (int16_t)(size.height - 2)}, Position{(int16_t)(size.width - 2), 1});
		mFrameBuffer->drawLine(Position{1, (int16_t)(size.height - 2)}, Position{(int16_t)(size.width - 2), (int16_t)(size.height - 2)});

		mFrameBuffer->setBrushColor(20, 20, 20);
		mFrameBuffer->drawLine(Position{(int16_t)(size.width - 1), (int16_t)(size.height - 1)}, Position{(int16_t)(size.width - 1), 0});
		mFrameBuffer->drawLine(Position{0, (int16_t)(size.height - 1)}, Position{(int16_t)(size.width - 1), (int16_t)(size.height - 1)});
	}

	if (mText && font->isAble())
	{
		width = font->getStringWidth((char *)mText);
		height = font->getStringHeight((char *)mText);
		mFrameBuffer->drawString(Position{(int16_t)(size.width / 2 - width / 2), (int16_t)(size.height / 2 - height / 2)}, (char *)mText);
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
	paint();
	update();
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

void Button::setFont(Font font)
{
	mFrameBuffer->setFont(font);
}

void Button::setColor(Color color)
{
	mFrameBuffer->setBackgroundColor(color);
	paint();
	update();
}

void Button::setColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mFrameBuffer->setBackgroundColor(red, green, blue);
	paint();
	update();
}

#endif
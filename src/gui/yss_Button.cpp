/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>
#include <config.h>
#include <yss/gui.h>
#include <gui/Button.h>
#include <gui/Font.h>
#include <string.h>

#if USE_GUI && YSS_L_HEAP_USE

Button::Button(void)
{
	mState = false;
	mUpHandler = 0;
	mPushHandler = 0;
	mText = 0;
}

Button::~Button(void)
{

}

void Button::paint(void)
{
	uint16_t width, height;

	if (mFrameBuffer == 0)
		return;

	Size_t size = mFrameBuffer->getSize();
	Font *font = mFrameBuffer->getFont();

	mFrameBuffer->setBackgroundColor(128, 128, 128);
	if (mState)
	{
		mFrameBuffer->clear();
		mFrameBuffer->setBrushColor(20, 20, 20);
		mFrameBuffer->drawLine(Position_t{0, 0}, Position_t{(int16_t)(size.width - 1), 0});
		mFrameBuffer->drawLine(Position_t{0, 0}, Position_t{0, (int16_t)(size.height - 1)});
		mFrameBuffer->setBrushColor(40, 40, 40);
		mFrameBuffer->drawLine(Position_t{1, 1}, Position_t{(int16_t)(size.width - 2), 1});
		mFrameBuffer->drawLine(Position_t{1, 1}, Position_t{1, (int16_t)(size.height - 2)});
		mFrameBuffer->setBrushColor(60, 60, 60);
		mFrameBuffer->drawLine(Position_t{2, 2}, Position_t{(int16_t)(size.width - 3), 2});
		mFrameBuffer->drawLine(Position_t{2, 2}, Position_t{2, (int16_t)(size.height - 3)});

		mFrameBuffer->setBrushColor(160, 160, 160);
		mFrameBuffer->drawLine(Position_t{(int16_t)(size.width - 3), (int16_t)(size.height - 3)}, Position_t{(int16_t)(size.width - 3), 2});
		mFrameBuffer->drawLine(Position_t{2, (int16_t)(size.height - 3)}, Position_t{(int16_t)(size.width - 3), (int16_t)(size.height - 3)});

		mFrameBuffer->setBrushColor(192, 192, 192);
		mFrameBuffer->drawLine(Position_t{(int16_t)(size.width - 2), (int16_t)(size.height - 2)}, Position_t{(int16_t)(size.width - 2), 1});
		mFrameBuffer->drawLine(Position_t{1, (int16_t)(size.height - 2)}, Position_t{(int16_t)(size.width - 2), (int16_t)(size.height - 2)});

		mFrameBuffer->setBrushColor(224, 224, 224);
		mFrameBuffer->drawLine(Position_t{(int16_t)(size.width - 1), (int16_t)(size.height - 1)}, Position_t{(int16_t)(size.width - 1), 0});
		mFrameBuffer->drawLine(Position_t{0, (int16_t)(size.height - 1)}, Position_t{(int16_t)(size.width - 1), (int16_t)(size.height - 1)});
	}
	else
	{
		mFrameBuffer->clear();
		mFrameBuffer->setBrushColor(224, 224, 224);
		mFrameBuffer->drawLine(Position_t{0, 0}, Position_t{(int16_t)(size.width - 1), 0});
		mFrameBuffer->drawLine(Position_t{0, 0}, Position_t{0, (int16_t)(size.height - 1)});
		mFrameBuffer->setBrushColor(192, 192, 192);
		mFrameBuffer->drawLine(Position_t{1, 1}, Position_t{(int16_t)(size.width - 2), 1});
		mFrameBuffer->drawLine(Position_t{1, 1}, Position_t{1, (int16_t)(size.height - 2)});
		mFrameBuffer->setBrushColor(160, 160, 160);
		mFrameBuffer->drawLine(Position_t{2, 2}, Position_t{(int16_t)(size.width - 3), 2});
		mFrameBuffer->drawLine(Position_t{2, 2}, Position_t{2, (int16_t)(size.height - 3)});

		mFrameBuffer->setBrushColor(60, 60, 60);
		mFrameBuffer->drawLine(Position_t{(int16_t)(size.width - 3), (int16_t)(size.height - 3)}, Position_t{(int16_t)(size.width - 3), 2});
		mFrameBuffer->drawLine(Position_t{2, (int16_t)(size.height - 3)}, Position_t{(int16_t)(size.width - 3), (int16_t)(size.height - 3)});

		mFrameBuffer->setBrushColor(40, 40, 40);
		mFrameBuffer->drawLine(Position_t{(int16_t)(size.width - 2), (int16_t)(size.height - 2)}, Position_t{(int16_t)(size.width - 2), 1});
		mFrameBuffer->drawLine(Position_t{1, (int16_t)(size.height - 2)}, Position_t{(int16_t)(size.width - 2), (int16_t)(size.height - 2)});

		mFrameBuffer->setBrushColor(20, 20, 20);
		mFrameBuffer->drawLine(Position_t{(int16_t)(size.width - 1), (int16_t)(size.height - 1)}, Position_t{(int16_t)(size.width - 1), 0});
		mFrameBuffer->drawLine(Position_t{0, (int16_t)(size.height - 1)}, Position_t{(int16_t)(size.width - 1), (int16_t)(size.height - 1)});
	}

	//if (mText && font->isAble())
	//{
	//	width = font->getStringWidth((char *)mText);
	//	height = font->getStringHeight((char *)mText);
	//	mFrameBuffer->drawString(Position_t{(int16_t)(size.width / 2 - width / 2), (int16_t)(size.height / 2 - height / 2)}, (char *)mText);
	//}
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

Object *Button::handlerPush(Position_t pos)
{
	(void)pos;

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

void Button::setFont(Font &font)
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
/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <yss/gui.h>
#include <gui/CheckBox.h>
#include <yss/instance.h>

#if USE_GUI && YSS_L_HEAP_USE

CheckBox::CheckBox(void)
{
	mState = true;
	mPushHandler = 0;
	mText = 0;

	mFrameBuffer->setBrushColor(0x00, 0x00, 0x00);
}

Object *CheckBox::handlerPush(Position_t pos)
{
	(void)pos;

	mState = !mState;
	paint();
	update();
	if (mPushHandler)
		mPushHandler(mState);
	return this;
}

void CheckBox::paint(void)
{
	Size_t size = mFrameBuffer->getSize();
	Font *font = mFrameBuffer->getFont();

	if (mFrameBuffer == 0)
		return;

	int16_t width = size.width, height = size.height;
	Position_t p1, p2;

	if (width > height)
		width = height;
	else
		height = width;

	mFrameBuffer->clear();

	mFrameBuffer->drawRect(Position_t{2, 2}, Size_t{(uint16_t)(width - 5), (uint16_t)(height - 5)});

	if (mState)
	{
		p1 = Position_t{4, 4};
		p2 = Position_t{(int16_t)(width / 2), (int16_t)(height - 6)};
		mFrameBuffer->drawLine(p1, p2);
		p1.x++;
		p2.x++;
		mFrameBuffer->drawLine(p1, p2);

		p1 = p2;
		p1.x--;
		p2 = Position_t{(int16_t)(width - 6), 4};
		mFrameBuffer->drawLine(p1, p2);
		p1.x++;
		p2.x++;
		mFrameBuffer->drawLine(p1, p2);
	}

	if (mText && font != 0)
	{
		mFrameBuffer->drawString(Position_t{(int16_t)(width + 2), (int16_t)(2)}, (char *)mText);
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
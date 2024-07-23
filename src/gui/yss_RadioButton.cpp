/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/gui.h>
#include <gui/RadioButton.h>
#include <yss/instance.h>

RadioButton::RadioButton(void)
{
	mState = true;
	mText = 0;

	mFrameBuffer->setBrushColor(0x00, 0x00, 0x00);
}

void RadioButton::setText(const int8_t *text)
{
	mText = text;
	paint();
	update();
}

void RadioButton::select(bool en)
{
	mState = en;
	paint();
	update();
}

void RadioButton::paint(void)
{
	if (mFrameBuffer == 0)
		return;
	
	Size_t size = mFrameBuffer->getSize();
	Font *font = mFrameBuffer->getFont();

	mFrameBuffer->clear();
	
	int16_t height = size.height;
	int16_t half = height / 2;
	Position_t pos = Position_t{half, half};
	mFrameBuffer->drawCircle(pos, half - 2);
	pos.x -= height / 4 - 1;
	pos.y -= height / 4 - 1;
	if (mState)
		mFrameBuffer->fillRect(pos, Size_t{(uint16_t)(half - 3), (uint16_t)(half - 3)});

	if (mText && font != 0)
	{
		mFrameBuffer->drawString(Position_t{(int16_t)(height + 2), (int16_t)(half - font->getStringHeight() / 2)}, (char *)mText);
	}
}

#endif
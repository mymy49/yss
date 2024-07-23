/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/instance.h>
#include <yss/gui.h>
#include <std_ext/malloc.h>

Panel::Panel()
{
}

void Panel::setPosition(Position_t pos)
{
	setPosition(pos.x, pos.y);
}

void Panel::setPosition(int16_t x, int16_t y)
{
	Size_t size = mFrameBuffer->getSize();
	Position_t before = mPos;
	mPos = Position_t{x, y};

	if(mParent)
		mParent->update(before, size, mPos, size);
}

#endif
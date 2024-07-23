/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/gui.h>
#include <gui/Segment.h>
#include <string.h>
#include <yss/instance.h>

segment::segment(void)
{
	mNumOfSegment = 1;
	mFrameBuffer->setBackgroundColor(20, 20, 20);
}

void segment::setSize(Size_t size)
{
	const uint16_t minWidth = 20 * mNumOfSegment, minHeight = 30;

	if (size.width < minWidth)
		size.width = minWidth;
	if (size.height < minHeight)
		size.height = minHeight;

	mFrameBuffer->setSize(size.width, size.height);
	paint();
	update(mPos, size, mPos, size);
//	mMutex.unlock();
}

void segment::setSize(uint16_t width, uint16_t height)
{
	setSize(Size_t{width, height});
}

void segment::paint(void)
{
	if (mFrameBuffer == 0)
		return;

	mFrameBuffer->clear();
}

#endif
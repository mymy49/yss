/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <yss/gui.h>
#include <gui/HSlider.h>
#include <yss/instance.h>

#if USE_GUI && YSS_L_HEAP_USE

HSlider::HSlider(void)
{
	mChangeHandler = 0;
	mLastPos = -1;
	mMax = 100;
}

void HSlider::paint(void)
{
	Size_t frameSize = mFrameBuffer->getSize();

	if (mFrameBuffer == 0)
		return;

	if (mLastPos == mThisPos)
		return;

	if (frameSize.width < 50)
		return;

	mLastPos = mThisPos;

	int16_t buf;

	buf = frameSize.height / 2;
	Position_t p1 = Position_t{buf, (int16_t)(buf - 1)};
	Position_t p2 = Position_t{(int16_t)(frameSize.width - buf), p1.y};

	buf = frameSize.height - 6;
	Size_t size = Size_t{(uint16_t)buf, (uint16_t)buf};

	mFrameBuffer->clear();

	mFrameBuffer->setBrushColor(0x30, 0x30, 0x30);
	mFrameBuffer->drawLine(p1, p2);

	p1.y++;
	p2.y++;
	mFrameBuffer->setBrushColor(0x0, 0x0, 0x0);
	mFrameBuffer->drawLine(p1, p2);

	p1.y++;
	p2.y++;
	mFrameBuffer->setBrushColor(0x30, 0x30, 0x30);
	mFrameBuffer->drawLine(p1, p2);

	p1.x = 3 + mThisPos;
	p1.y = 3;
	mFrameBuffer->fillRect(p1, size);
}

void HSlider::setSize(Size_t size)
{
	Size_t frameSize = mFrameBuffer->getSize();

//	mMutex.lock();
	if (size.height > 30)
		size.height = 25;
	else if (size.height < 25)
		size.height = 25;

	mFrameBuffer->setSize(size.width, size.height);
	paint();
	update(mPos, frameSize, mPos, size);
	frameSize = size;
//	mMutex.unlock();
}

void HSlider::setSize(uint16_t width, uint16_t height)
{
	setSize(Size_t{width, height});
}

Object *HSlider::handlerPush(Position_t pos)
{
	Size_t frameSize = mFrameBuffer->getSize();

	int32_t  buf = frameSize.width - 5 - frameSize.height;

	mThisPos = pos.x - frameSize.height / 2;

	if (mThisPos < 3)
		mThisPos = 3;
	else if (mThisPos > buf)
		mThisPos = buf;

	paint();
	update();

	if (mChangeHandler)
	{
		buf = (float)mThisPos / (float)buf * (float)mMax;
		mChangeHandler(buf);
	}

	return this;
}

Object *HSlider::handlerDrag(Position_t pos)
{
	Size_t frameSize = mFrameBuffer->getSize();
	int32_t  buf = frameSize.width - 5 - frameSize.height;

	mThisPos = pos.x - frameSize.height / 2;

	if (mThisPos < 3)
		mThisPos = 3;
	else if (mThisPos > buf)
		mThisPos = buf;

	paint();
	update();

	if (mChangeHandler)
	{
		buf = (float)mThisPos / (float)buf * (float)mMax;
		mChangeHandler(buf);
	}

	return this;
}

void HSlider::setChangeEventHandler(void (*handler)(int32_t ))
{
	mChangeHandler = handler;
}

void HSlider::setMaxValue(uint16_t max)
{
	mMax = max;
}

#endif
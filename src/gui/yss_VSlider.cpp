/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/gui.h>
#include <gui/VSlider.h>

VSlider::VSlider(void)
{
	mChangeHandler = 0;
	mLastPos = -1;
	mMax = 100;
}

void VSlider::paint(void)
{
	Size_t frameSize = mFrameBuffer->getSize();

	if (mFrameBuffer == 0)
		return;

	if (mLastPos == mThisPos)
		return;

	if (frameSize.height < 50)
		return;

	mLastPos = mThisPos;

	int16_t buf;

	buf = frameSize.width / 2;
	Position_t p1 = Position_t{(int16_t)(buf - 1), buf};
	Position_t p2 = Position_t{p1.x, (int16_t)(frameSize.height - buf)};

	buf = frameSize.width - 6;
	Size_t size = Size_t{(uint16_t)buf, (uint16_t)buf};

	mFrameBuffer->clear();

	mFrameBuffer->setBrushColor(0x30, 0x30, 0x30);
	mFrameBuffer->drawLine(p1, p2);

	p1.x++;
	p2.x++;
	mFrameBuffer->setBrushColor(0x0, 0x0, 0x0);
	mFrameBuffer->drawLine(p1, p2);

	p1.x++;
	p2.x++;
	mFrameBuffer->setBrushColor(0x30, 0x30, 0x30);
	mFrameBuffer->drawLine(p1, p2);

	p1.y = 3 + mThisPos;
	p1.x = 3;
	mFrameBuffer->fillRect(p1, size);
}

void VSlider::setSize(Size_t size)
{
//	mMutex.lock();
	if (size.width > 30)
		size.width = 25;
	else if (size.width < 25)
		size.width = 25;

	mFrameBuffer->setSize(size.width, size.height);
	paint();
	update(mPos, size, mPos, size);
//	mMutex.unlock();
}

void VSlider::setSize(uint16_t width, uint16_t height)
{
	setSize(Size_t{width, height});
}

Object *VSlider::handlerPush(Position_t pos)
{
	Size_t size = mFrameBuffer->getSize();
	int32_t  buf = size.height - 5 - size.width;

	mThisPos = pos.y - size.width / 2;

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

Object *VSlider::handlerDrag(Position_t pos)
{
	Size_t size = mFrameBuffer->getSize();
	int32_t  buf = size.height - 5 - size.width;

	mThisPos = pos.y - size.width / 2;

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

void VSlider::setChangeEventHandler(void (*handler)(int32_t ))
{
	mChangeHandler = handler;
}

void VSlider::setMaxValue(uint16_t max)
{
	mMax = max;
}

#endif
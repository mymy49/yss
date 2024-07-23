/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/gui.h>
#include <yss/Mutex.h>

Object::Object(void)
{
	mPos.x = 0;
	mPos.y = 0;
	mParent = 0;
	mVisibleFlag = true;
	mResizeAble = true;

	mFrameBuffer = new YSS_GUI_FRAME_BUFFER;
}

Object::~Object(void)
{
	delete mFrameBuffer;
}

void Object::update(Position_t pos, Size_t size)
{
	if(mParent)
	{
		//pos.x += mPos.x;
		//pos.y += mPos.y;
		mParent->update(pos, size);
	}
}

void Object::update(Position_t beforePos, Size_t beforeSize, Position_t currentPos, Size_t currentSize)
{
	if(mParent)
		mParent->update(beforePos, beforeSize, currentPos, currentSize);
}

Size_t Object::getSize(void)
{
	return mFrameBuffer->getSize();
}

void Object::update(void)
{
	if(mParent)
		mParent->update(mPos, mFrameBuffer->getSize());
}

void Object::setPosition(Position_t pos)
{
	setPosition(pos.x, pos.y);
}

void Object::setPosition(int16_t x, int16_t y)
{
	Size_t size = mFrameBuffer->getSize();
	Position_t before = mPos;
	mPos = Position_t{x, y};
	update(before, size, mPos, size);
}

Position_t Object::getPosition(void)
{
	return mPos;
}

void Object::setSize(Size_t size)
{
	if(mResizeAble)
	{
		mFrameBuffer->setSize(size.width, size.height);
		eventSizeChanged(size);
		paint();
		update(mPos, size, mPos, size);
	}
}

void Object::setSize(uint16_t width, uint16_t height)
{
	setSize(Size_t{width, height});
}

void Object::setVisible(bool on)
{
	mVisibleFlag = on;
	update(mPos, mFrameBuffer->getSize());
}

bool Object::isVisible(void)
{
	return mVisibleFlag;
}

void Object::setParent(Container *parent)
{
	mParent = parent;
}

Object *Object::handlerPush(Position_t pos)
{
	(void)pos;
	return this;
}

Object *Object::handlerDrag(Position_t pos)
{
	(void)pos;
	return this;
}

Object *Object::handlerUp(void)
{
	return this;
}

Position_t Object::getAbsolutePos(void)
{
	Position_t pos = Position_t{0, 0};

	if (mParent)
		pos = mParent->getAbsolutePos();

	pos.x = mPos.x;
	pos.y = mPos.y;

	return pos;
}

Brush* Object::getFrameBuffer(void)
{
	return mFrameBuffer;
}

void Object::eventSizeChanged(Size_t size)
{
	(void)size;
}

#endif
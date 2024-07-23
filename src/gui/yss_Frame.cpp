/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/instance.h>

#include <yss.h>
#include <std_ext/malloc.h>
#include <gui/OutputFrameBuffer.h>

Frame::Frame()
{
	mOutputFrameBuffer = 0;
	mFrameBuffer->setSize(ltdc.getLcdSize());
	mResizeAble = false;
	mFrameBuffer->clear();
}

Frame::~Frame(void)
{
	clearActiveFrame();
}

void Frame::setPosition(Position_t pos)
{
	// Frame의 위치 조정 못하게 막을 목적으로 생성
	(void)pos;
}

void Frame::setPosition(int16_t x, int16_t y)
{
	// Frame의 위치 조정 못하게 막을 목적으로 생성
	(void)x;
	(void)y;
}

void Frame::setOutputFrameBuffer(OutputFrameBuffer *outputFrameBuffer)
{
	mOutputFrameBuffer = outputFrameBuffer;

	update();
}

void Frame::update(void)
{
	update(mPos, mFrameBuffer->getSize());

	if(mOutputFrameBuffer)
		mOutputFrameBuffer->update();
}

void Frame::update(Position_t pos, Size_t size)
{
	Object *obj;

	mFrameBuffer->eraseRectangle(pos, size);

	for (uint16_t i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];
		if (obj->isVisible())
			mFrameBuffer->drawObjectToPartialArea(pos, size, obj);
	}

	if (mOutputFrameBuffer)
	{
		pos.x += mPos.x;
		pos.y += mPos.y;
		mOutputFrameBuffer->update(pos, size);
	}
}

void Frame::update(Position_t beforePos, Size_t beforeSize, Position_t currentPos, Size_t currentSize)
{
	Object *obj;

	mFrameBuffer->eraseRectangle(beforePos, beforeSize);
	mFrameBuffer->eraseRectangle(currentPos, currentSize);

	for (uint16_t i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];
		if (obj->isVisible())
		{
			mFrameBuffer->drawObjectToPartialArea(beforePos, beforeSize, obj);
			mFrameBuffer->drawObjectToPartialArea(currentPos, currentSize, obj);
		}
	}

	if (mOutputFrameBuffer)
	{
		beforePos.x += mPos.x;
		beforePos.y += mPos.y;
		currentPos.x += mPos.x;
		currentPos.y += mPos.y;
		mOutputFrameBuffer->update(beforePos, beforeSize, currentPos, currentSize);
	}
}

void Frame::add(Object &obj)
{
	obj.paint();

	if (mNumOfObj + 1 >= mMaxObj)
		increaseObjArr();

	mObjArr[mNumOfObj] = &obj;
	mNumOfObj++;

	obj.setParent(this);

	update(obj.getPosition(), obj.getSize());
}

void Frame::add(Object *obj)
{
	add(*obj);
}

Object *Frame::handlerPush(Position_t pos)
{
	return Container::handlerPush(pos);
}

Object *Frame::handlerDrag(Position_t pos)
{
	return Container::handlerDrag(pos);
}

Object *Frame::handlerUp(void)
{
	return Container::handlerUp();
}

#endif
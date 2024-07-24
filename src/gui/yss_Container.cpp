/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/instance.h>
#include <config.h>
#include <yss/gui.h>
#include <std_ext/malloc.h>

#if YSS_GUI_FRAME_BUFFER == 0	// Rgb565
	typedef Rgb565		SysFrameBuffer;
#elif YSS_GUI_FRAME_BUFFER == 1	// Rgb888
	typedef Rgb888		SysFrameBuffer;
#elif YSS_GUI_FRAME_BUFFER == 2	// Argb1555
	typedef Argb1555	SysFrameBuffer;
#endif

Container::Container()
{
	mObjArr = 0;
	mMaxObj = 0;
	mNumOfObj = 0;
	mLastEventObj = 0;
	mValidFlag = true;
	increaseObjArr();
}

Container::~Container()
{
	for(int32_t  i=0;i<mNumOfObj;i++)
	{
		delete mObjArr[i];
	}

	if (mObjArr)
		lfree(mObjArr);
	
	mValidFlag = false;
}

void Container::paint(void)
{
	uint16_t i;
	Object *obj;

	for (i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];

		if (obj->isVisible())
		{
//			Painter::draw(*this, *obj);
		}
	}
}

void Container::add(Object &obj)
{
	if(!mValidFlag)
	{
		// Container가 이미 제거된 상태에서 add를 시도할 경우 빠져나감
		return;
	}

	if (mNumOfObj + 1 >= mMaxObj)
		increaseObjArr();

	mObjArr[mNumOfObj] = &obj;
	mNumOfObj++;

	obj.setParent(this);

	update(obj.getPosition(), obj.getSize());
}

void Container::add(Object *obj)
{
	add(*obj);
}

void Container::increaseObjArr(void)
{
	uint16_t i;
	Object **temp;

	temp = (Object **)lmalloc(sizeof(Object *) * (mMaxObj + 512));

	if (mMaxObj)
	{
		for (i = 0; i < mMaxObj; i++)
			temp[i] = mObjArr[i];

		lfree(mObjArr);
	}
	mMaxObj += 512;

	mObjArr = temp;
}

void Container::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	mFrameBuffer->setBackgroundColor(red, green, blue, alpha);
	update(Position_t{0, 0}, mFrameBuffer->getSize());
}

void Container::update(void)
{
	update(mPos, mFrameBuffer->getSize());
}

void Container::update(Position_t pos, Size_t size)
{
	Object *obj;

	mFrameBuffer->eraseRectangle(pos, size);

	for (uint16_t i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];
		if (obj->isVisible())
			mFrameBuffer->drawObjectToPartialArea(pos, size, obj);
	}

	if (mParent)
	{
		pos.x += mPos.x;
		pos.y += mPos.y;
		mParent->update(pos, size);
	}
}

void Container::update(Position_t beforePos, Size_t beforeSize, Position_t currentPos, Size_t currentSize)
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

	if (mParent)
	{
		beforePos.x += mPos.x;
		beforePos.y += mPos.y;
		currentPos.x += mPos.x;
		currentPos.y += mPos.y;
		mParent->update(beforePos, beforeSize, currentPos, currentSize);
	}
}

Object *Container::handlerPush(Position_t pos)
{
	Position_t objPos;
	Size_t objSize;
	Position_t calculatedPos;
	Object *rt;

	for (int16_t i = mNumOfObj - 1; i >= 0; i--)
	{
		objPos = mObjArr[i]->getPosition();
		objSize = mObjArr[i]->getSize();

		if (mObjArr[i]->isVisible() && objPos.x < pos.x && objPos.y < pos.y && objPos.x + objSize.width > pos.x && objPos.y + objSize.height > pos.y)
		{
			calculatedPos.x = pos.x - objPos.x;
			calculatedPos.y = pos.y - objPos.y;

			rt = mObjArr[i]->handlerPush(calculatedPos);
			return rt;
		}
	}

	return 0;
}

Object *Container::handlerDrag(Position_t pos)
{
	Position_t objPos;
	Size_t objSize;
	Position_t calculatedPos;
	Object *rt;

	for (int16_t i = mNumOfObj - 1; i >= 0; i--)
	{
		objPos = mObjArr[i]->getPosition();
		objSize = mObjArr[i]->getSize();

		if (mObjArr[i]->isVisible() && objPos.x < pos.x && objPos.y < pos.y && objPos.x + objSize.width > pos.x && objPos.y + objSize.height > pos.y)
		{
			calculatedPos.x = pos.x - objPos.x;
			calculatedPos.y = pos.y - objPos.y;

			rt = mObjArr[i]->handlerDrag(calculatedPos);
			return rt;
		}
	}

	return 0;
}

Object *Container::handlerUp(void)
{
	return 0;
}

#endif
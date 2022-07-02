////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <yss/instance.h>

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE

#include <__cross_studio_io.h>

#include <config.h>
#include <yss/gui.h>
#include <yss/malloc.h>

typedef YSS_GUI_FRAME_BUFFER SysFrameBuffer;

Container::Container()
{
	mObjArr = 0;
	mMaxObj = 0;
	mNumOfObj = 0;
	mLastEventObj = 0;
	increaseObjArr();
}

Container::~Container()
{
	for(int i=0;i<mNumOfObj;i++)
	{
		mObjArr[i]->destroy();
		delete mObjArr[i];
	}

	if (mObjArr)
		lfree(mObjArr);
}

void Container::paint(void)
{
	unsigned short i;
	Object *obj;

	for (i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];

		if (obj->isVisible())
		{
			dma2d.draw(*this, *obj);
		}
	}
}

void Container::add(Object &obj)
{
	if (mNumOfObj + 1 >= mMaxObj)
		increaseObjArr();

	mObjArr[mNumOfObj] = &obj;
	mNumOfObj++;

	obj.setParent(this);

	update(obj.getPos(), obj.getSize());
}

void Container::add(Object *obj)
{
	add(*obj);
}

void Container::increaseObjArr(void)
{
	unsigned short i;
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

void Container::setBgColor(unsigned char red, unsigned char green, unsigned char blue)
{
	mMutex.lock();
	SysFrameBuffer::setBgColor(red, green, blue);
	update(Pos{0, 0}, mSize);
	mMutex.unlock();
}

void Container::update(void)
{
	update(mPos, mSize);
}

void Container::update(Pos pos, Size size)
{
	Object *obj;

	clearRectangle(pos, size);

	for (unsigned short i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];
		if (obj->isVisible())
			dma2d.drawArea(*this, pos, size, *obj);
	}

	if (mFrame)
	{
		pos.x += mPos.x;
		pos.y += mPos.y;
		mFrame->update(pos, size);
	}
	else if (mParent)
	{
		pos.x += mPos.x;
		pos.y += mPos.y;
		mParent->update(pos, size);
	}
}

void Container::update(Pos beforePos, Size beforeSize, Pos currentPos, Size currentSize)
{
	Object *obj;

	clearRectangle(beforePos, beforeSize);
	clearRectangle(currentPos, currentSize);

	for (unsigned short i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];
		if (obj->isVisible())
		{
			dma2d.drawArea(*this, beforePos, beforeSize, *obj);
			dma2d.drawArea(*this, currentPos, currentSize, *obj);
		}
	}

	if (mFrame)
	{
		beforePos.x += mPos.x;
		beforePos.y += mPos.y;
		currentPos.x += mPos.x;
		currentPos.y += mPos.y;
		mFrame->update(beforePos, beforeSize, currentPos, currentSize);
	}
	else if (mParent)
	{
		beforePos.x += mPos.x;
		beforePos.y += mPos.y;
		currentPos.x += mPos.x;
		currentPos.y += mPos.y;
		mParent->update(beforePos, beforeSize, currentPos, currentSize);
	}
}

Object *Container::handlerPush(Pos pos)
{
	Pos objPos;
	Size objSize;
	Pos calculatedPos;
	Object *rt;

	for (signed short i = mNumOfObj - 1; i >= 0; i--)
	{
		objPos = mObjArr[i]->getPos();
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

Object *Container::handlerDrag(Pos pos)
{
	Pos objPos;
	Size objSize;
	Pos calculatedPos;
	Object *rt;

	for (signed short i = mNumOfObj - 1; i >= 0; i--)
	{
		objPos = mObjArr[i]->getPos();
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
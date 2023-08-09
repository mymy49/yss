////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <yss/instance.h>
#include <config.h>
#include <yss/gui.h>
#include <std_ext/malloc.h>
#include <gui/painter.h>

typedef YSS_GUI_FRAME_BUFFER SysFrameBuffer;

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
	mMutex.lock();

	for(int32_t  i=0;i<mNumOfObj;i++)
	{
		mObjArr[i]->destroy();
		delete mObjArr[i];
	}

	if (mObjArr)
		lfree(mObjArr);
	
	mValidFlag = false;

	mMutex.unlock();
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
			Painter::draw(*this, *obj);
		}
	}
}

void Container::add(Object &obj)
{
	mMutex.lock();
	
	if(!mValidFlag)
	{
		// Container가 이미 제거된 상태에서 add를 시도할 경우 빠져나감
		mMutex.unlock();
		return;
	}

	if (mNumOfObj + 1 >= mMaxObj)
		increaseObjArr();

	mObjArr[mNumOfObj] = &obj;
	mNumOfObj++;

	obj.setParent(this);

	update(obj.getPos(), obj.getSize());

	mMutex.unlock();
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

void Container::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mFrameBuffer->setBackgroundColor(red, green, blue);
	update(Position{0, 0}, mFrameBuffer->getSize());
}

void Container::update(void)
{
	update(mPos, mFrameBuffer->getSize());
}

void Container::update(Position pos, Size size)
{
	Object *obj;

	mFrameBuffer->clearRectangle(pos, size);

	for (uint16_t i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];
		if (obj->isVisible())
			Painter::drawArea(*this, pos, size, *obj);
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

void Container::update(Position beforePos, Size beforeSize, Position currentPos, Size currentSize)
{
	Object *obj;

	mFrameBuffer->clearRectangle(beforePos, beforeSize);
	mFrameBuffer->clearRectangle(currentPos, currentSize);

	for (uint16_t i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];
		if (obj->isVisible())
		{
			Painter::drawArea(*this, beforePos, beforeSize, *obj);
			Painter::drawArea(*this, currentPos, currentSize, *obj);
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

Object *Container::handlerPush(Position pos)
{
	Position objPos;
	Size objSize;
	Position calculatedPos;
	Object *rt;

	for (int16_t i = mNumOfObj - 1; i >= 0; i--)
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

Object *Container::handlerDrag(Position pos)
{
	Position objPos;
	Size objSize;
	Position calculatedPos;
	Object *rt;

	for (int16_t i = mNumOfObj - 1; i >= 0; i--)
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
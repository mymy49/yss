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

#include <yss/gui.h>
#include <std_ext/malloc.h>
#include <gui/painter.h>

Frame::Frame()
{
	mSerialFrameBuffer = 0;
	mFrameBuffer->setSize(ltdc.getLcdSize());
	mResizeAble = false;
	mFrameBuffer->clear();
}

Frame::~Frame(void)
{
}

void Frame::setPosition(Position pos)
{
	// Frame 위치 조정 못하게 막을 목적으로 생성
}

void Frame::setPosition(int16_t x, int16_t y)
{
	// Frame 위치 조정 못하게 막을 목적으로 생성
}

void Frame::setSize(int16_t width, int16_t height)
{
	// Frame 사이즈 조정 못하게 막을 목적으로 생성
}

void Frame::setSize(Size size)
{
	// Frame 사이즈 조정 못하게 막을 목적으로 생성
}

void Frame::setSerialFrameBuffer(SerialFrameBuffer *parent)
{
	mSerialFrameBuffer = parent;
}

void Frame::update(void)
{
	update(mPos, mFrameBuffer->getSize());
}

void Frame::update(Position pos, Size size)
{
//	mMutex.lock();
	mFrameMutex.lock();
	Object *obj;

	mFrameBuffer->clearRectangle(pos, size);

	for (uint16_t i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];
		if (obj->isVisible())
			Painter::drawArea(*this, pos, size, *obj);
	}

	if (mSerialFrameBuffer)
	{
		pos.x += mPos.x;
		pos.y += mPos.y;
		mSerialFrameBuffer->update(pos, size);
	}
//	mMutex.unlock();
	mFrameMutex.unlock();
}

void Frame::update(Position beforePos, Size beforeSize, Position currentPos, Size currentSize)
{
	Object *obj;

//	mMutex.lock();
	mFrameMutex.lock();
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

	if (mSerialFrameBuffer)
	{
		beforePos.x += mPos.x;
		beforePos.y += mPos.y;
		currentPos.x += mPos.x;
		currentPos.y += mPos.y;
		mSerialFrameBuffer->update(beforePos, beforeSize, currentPos, currentSize);
	}

	mFrameMutex.unlock();
//	mMutex.unlock();
}

void Frame::add(Object &obj)
{
	obj.paint();

	if (mNumOfObj + 1 >= mMaxObj)
		increaseObjArr();

	mObjArr[mNumOfObj] = &obj;
	mNumOfObj++;

	obj.setFrame(this);

	update(obj.getPos(), obj.getSize());
}

void Frame::add(Object *obj)
{
	add(*obj);
}

Object *Frame::handlerPush(Position pos)
{
	return Container::handlerPush(pos);
}

Object *Frame::handlerDrag(Position pos)
{
	return Container::handlerDrag(pos);
}

Object *Frame::handlerUp(void)
{
	return Container::handlerUp();
}

#endif
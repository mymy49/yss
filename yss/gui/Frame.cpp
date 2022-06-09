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

#include <yss/gui.h>
#include <yss/malloc.h>

Frame::Frame()
{
	mFrameBuffer = 0;
	YssSysFrameBuffer::setSize(ltdc.getLcdSize());
	clear();
}

Frame::~Frame(void)
{
}

void Frame::setPos(Pos pos)
{
	// Fraem은 위치 조정 못하게 막을 목적으로 생성
}

void Frame::setPos(signed short x, signed short y)
{
	// Fraem은 위치 조정 못하게 막을 목적으로 생성
}

void Frame::setSize(unsigned short width, unsigned short height)
{
	// Fraem은 사이즈 조정 못하게 막을 목적으로 생성
}

void Frame::setSize(Size size)
{
	// Fraem은 사이즈 조정 못하게 막을 목적으로 생성
}

void Frame::setSerialFrameBuffer(SerialFrameBuffer *parent)
{
	mFrameBuffer = parent;
}

void Frame::update(void)
{
	update(mPos, mSize);
}

void Frame::update(Pos pos, Size size)
{
	Object *obj;

	clearRectangle(pos, size);

	for (unsigned short i = 0; i < mNumOfObj; i++)
	{
		obj = mObjArr[i];
		if (obj->isVisible())
			dma2d.drawArea(*this, pos, size, *obj);
	}

	if (mFrameBuffer)
	{
		pos.x += mPos.x;
		pos.y += mPos.y;
		mFrameBuffer->update(pos, size);
	}
}

void Frame::update(Pos beforePos, Size beforeSize, Pos currentPos, Size currentSize)
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

	if (mFrameBuffer)
	{
		beforePos.x += mPos.x;
		beforePos.y += mPos.y;
		currentPos.x += mPos.x;
		currentPos.y += mPos.y;
		mFrameBuffer->update(beforePos, beforeSize, currentPos, currentSize);
	}
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

Object *Frame::handlerPush(Pos pos)
{
	return Container::handlerPush(pos);
}

Object *Frame::handlerDrag(Pos pos)
{
	return Container::handlerDrag(pos);
}

Object *Frame::handlerUp(void)
{
	return Container::handlerUp();
}

#endif
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

#include <gui/Object.h>
#include <gui/Frame.h>

Mutex Object::mMutex;

Object::Object(void)
{
	mPos.x = 0;
	mPos.y = 0;
	mParent = 0;
	mFrame = 0;
	mVisibleFlag = true;
	mResizeAble = true;
	mFrameBuffer = new YssSysFrameBuffer();
}

Object::~Object(void)
{
}

void Object::destroy(void)
{
}

void Object::update(Position pos, Size size)
{
	if (mFrame)
		mFrame->update(pos, size);
	else if (mParent)
		mParent->update(pos, size);
}

void Object::update(Position beforePos, Size beforeSize, Position currentPos, Size currentSize)
{
	if (mFrame)
		mFrame->update(beforePos, beforeSize, currentPos, currentSize);
	else if (mParent)
		mParent->update(beforePos, beforeSize, currentPos, currentSize);
}

Size Object::getSize(void)
{
	return mFrameBuffer->getSize();
}

void Object::update(void)
{
	if (mFrame)
	{
		mFrame->update(mPos, mFrameBuffer->getSize());
	}
	else if (mParent)
		mParent->update(mPos, mFrameBuffer->getSize());
}

void Object::setPosition(Position pos)
{
	setPosition(pos.x, pos.y);
}

void Object::setPosition(int16_t x, int16_t y)
{
	Size size = mFrameBuffer->getSize();
	Position before = mPos;
	mPos = Position{x, y};
	update(before, size, mPos, size);
}

Position Object::getPos(void)
{
	return mPos;
}

void Object::setSize(Size size)
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
	setSize(Size{width, height});
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

void Object::setFrame(Frame *frame)
{
	mFrame = frame;
}

Object *Object::handlerPush(Position pos)
{
	return this;
}

Object *Object::handlerDrag(Position pos)
{
	return this;
}

Object *Object::handlerUp(void)
{
	return this;
}

Position Object::getAbsolutePos(void)
{
	Position pos = Position{0, 0};

	if (mParent)
		pos = mParent->getAbsolutePos();

	pos.x = mPos.x;
	pos.y = mPos.y;

	return pos;
}

YssSysFrameBuffer* Object::getFrameBuffer(void)
{
	return mFrameBuffer;
}

void Object::eventSizeChanged(Size size)
{

}

#endif
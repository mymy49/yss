////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>
#include <config.h>
#include <yss/gui.h>
#include <gui/HSlider.h>
#include <yss/instance.h>

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE

HSlider::HSlider(void)
{
	mChangeHandler = 0;
	mLastPos = -1;
	mMax = 100;
}

void HSlider::paint(void)
{
	if (mFrameBuffer == 0)
		return;

	if (mLastPos == mThisPos)
		return;

	if (mSize.width < 50)
		return;

	mLastPos = mThisPos;

	unsigned short buf;

	buf = mSize.height / 2;
	Pos p1 = Pos{buf, buf - 1};
	Pos p2 = Pos{mSize.width - buf, p1.y};

	buf = mSize.height - 6;
	Size size = Size{buf, buf};

	clear();

	setColor(0x30, 0x30, 0x30);
	drawLine(p1, p2);

	p1.y++;
	p2.y++;
	setColor(0x0, 0x0, 0x0);
	drawLine(p1, p2);

	p1.y++;
	p2.y++;
	setColor(0x30, 0x30, 0x30);
	drawLine(p1, p2);

	p1.x = 3 + mThisPos;
	p1.y = 3;
	fillRect(p1, size);
}

void HSlider::setSize(Size size)
{
	mMutex.lock();
	if (size.height > 30)
		size.height = 25;
	else if (size.height < 25)
		size.height = 25;

	FrameBuffer::setSize(size.width, size.height);
	paint();
	update(mPos, mSize, mPos, size);
	mSize = size;
	mMutex.unlock();
}

void HSlider::setSize(unsigned short width, unsigned short height)
{
	setSize(Size{width, height});
}

Object *HSlider::handlerPush(Pos pos)
{
	int buf = mSize.width - 5 - mSize.height;

	mThisPos = pos.x - mSize.height / 2;

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

Object *HSlider::handlerDrag(Pos pos)
{
	int buf = mSize.width - 5 - mSize.height;

	mThisPos = pos.x - mSize.height / 2;

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

void HSlider::setChangeEventHandler(void (*handler)(int))
{
	mChangeHandler = handler;
}

void HSlider::setMaxValue(unsigned short max)
{
	mMax = max;
}

#endif
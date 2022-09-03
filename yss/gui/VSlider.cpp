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
#include <yss/gui.h>
#include <gui/VSlider.h>

#if defined(DMA2D) && USE_GUI && YSS_L_HEAP_USE

VSlider::VSlider(void)
{
	mChangeHandler = 0;
	mLastPos = -1;
	mMax = 100;
}

void VSlider::paint(void)
{
	if (mFrameBuffer == 0)
		return;

	if (mLastPos == mThisPos)
		return;

	if (mSize.height < 50)
		return;

	mLastPos = mThisPos;

	uint16_t buf;

	buf = mSize.width / 2;
	Position p1 = Position{buf - 1, buf};
	Position p2 = Position{p1.x, mSize.height - buf};

	buf = mSize.width - 6;
	Size size = Size{buf, buf};

	clear();

	setBrushColor(0x30, 0x30, 0x30);
	drawLine(p1, p2);

	p1.x++;
	p2.x++;
	setBrushColor(0x0, 0x0, 0x0);
	drawLine(p1, p2);

	p1.x++;
	p2.x++;
	setBrushColor(0x30, 0x30, 0x30);
	drawLine(p1, p2);

	p1.y = 3 + mThisPos;
	p1.x = 3;
	fillRect(p1, size);
}

void VSlider::setSize(Size size)
{
	mMutex.lock();
	if (size.width > 30)
		size.width = 25;
	else if (size.width < 25)
		size.width = 25;

	FrameBuffer::setSize(size.width, size.height);
	paint();
	update(mPos, mSize, mPos, size);
	mSize = size;
	mMutex.unlock();
}

void VSlider::setSize(uint16_t width, uint16_t height)
{
	setSize(Size{width, height});
}

Object *VSlider::handlerPush(Position pos)
{
	int32_t  buf = mSize.height - 5 - mSize.width;

	mThisPos = pos.y - mSize.width / 2;

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

Object *VSlider::handlerDrag(Position pos)
{
	int32_t  buf = mSize.height - 5 - mSize.width;

	mThisPos = pos.y - mSize.width / 2;

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
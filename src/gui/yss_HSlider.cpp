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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>
#include <yss/gui.h>
#include <gui/HSlider.h>
#include <yss/instance.h>

#if USE_GUI && YSS_L_HEAP_USE

HSlider::HSlider(void)
{
	mChangeHandler = 0;
	mLastPos = -1;
	mMax = 100;
}

void HSlider::paint(void)
{
	Size_t frameSize = mFrameBuffer->getSize();

	if (mFrameBuffer == 0)
		return;

	if (mLastPos == mThisPos)
		return;

	if (frameSize.width < 50)
		return;

	mLastPos = mThisPos;

	int16_t buf;

	buf = frameSize.height / 2;
	Position_t p1 = Position_t{buf, (int16_t)(buf - 1)};
	Position_t p2 = Position_t{(int16_t)(frameSize.width - buf), p1.y};

	buf = frameSize.height - 6;
	Size_t size = Size_t{(uint16_t)buf, (uint16_t)buf};

	mFrameBuffer->clear();

	mFrameBuffer->setBrushColor(0x30, 0x30, 0x30);
	mFrameBuffer->drawLine(p1, p2);

	p1.y++;
	p2.y++;
	mFrameBuffer->setBrushColor(0x0, 0x0, 0x0);
	mFrameBuffer->drawLine(p1, p2);

	p1.y++;
	p2.y++;
	mFrameBuffer->setBrushColor(0x30, 0x30, 0x30);
	mFrameBuffer->drawLine(p1, p2);

	p1.x = 3 + mThisPos;
	p1.y = 3;
	mFrameBuffer->fillRect(p1, size);
}

void HSlider::setSize(Size_t size)
{
	Size_t frameSize = mFrameBuffer->getSize();

//	mMutex.lock();
	if (size.height > 30)
		size.height = 25;
	else if (size.height < 25)
		size.height = 25;

	mFrameBuffer->setSize(size.width, size.height);
	paint();
	update(mPos, frameSize, mPos, size);
	frameSize = size;
//	mMutex.unlock();
}

void HSlider::setSize(uint16_t width, uint16_t height)
{
	setSize(Size_t{width, height});
}

Object *HSlider::handlerPush(Position_t pos)
{
	Size_t frameSize = mFrameBuffer->getSize();

	int32_t  buf = frameSize.width - 5 - frameSize.height;

	mThisPos = pos.x - frameSize.height / 2;

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

Object *HSlider::handlerDrag(Position_t pos)
{
	Size_t frameSize = mFrameBuffer->getSize();
	int32_t  buf = frameSize.width - 5 - frameSize.height;

	mThisPos = pos.x - frameSize.height / 2;

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

void HSlider::setChangeEventHandler(void (*handler)(int32_t ))
{
	mChangeHandler = handler;
}

void HSlider::setMaxValue(uint16_t max)
{
	mMax = max;
}

#endif
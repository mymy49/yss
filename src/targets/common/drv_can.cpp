////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(STM32F1_N) || defined(STM32F4) || defined(STM32F7) || defined(GD32F1)

#include <drv/Can.h>

uint32_t Can::getRxCount(void)
{
	if(mTail <= mHead)	
		return mHead - mTail;
	else 
		return mRxBufferDepth - mTail;
}

void Can::releaseFifo(uint32_t count)
{
	mTail += count;
	if(mTail >= mRxBufferDepth)
		mTail = 0;
}

void Can::push(CanFrame *frame)
{
	CanFrame *des = &mCanFrame[mHead];
	*des = *frame;

	if(des->extension == 0)
		des->id >>= 18;

	mHead++;
	if (mHead >= mRxBufferDepth)
		mHead = 0;
}

CanFrame* Can::getRxPacketPointer(void)
{
	return &mCanFrame[mTail];
}

void Can::flush(void)
{
	mTail = mHead = 0;
}

error Can::send(J1939Frame packet)
{
	CanFrame *src = (CanFrame*)&packet;
	return send(*src);
}

J1939Frame Can::generateJ1939Frame(uint8_t priority, uint16_t pgn, uint8_t sa, uint8_t count)
{
	J1939Frame buf = {0, 0, true, sa, pgn, 0, 0, priority, count, 0, 0,};
	return buf;
}

void Can::setIsrForEvent(void (*func)(error code))
{
	mIsrForEvent = func;
}

#endif


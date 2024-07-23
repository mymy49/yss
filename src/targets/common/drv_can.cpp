/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F1) || defined(GD32F1) || defined(STM32F7) || defined (STM32F4)

#include <drv/Can.h>

uint32_t Can::getRxCount(void)
{
	uint32_t head = mHead;

	if(mTail <= head)	
		return head - mTail;
	else 
		return mRxBufferDepth - mTail;
}

void Can::releaseFifo(uint32_t count)
{
	mTail += count;
	if(mTail >= mRxBufferDepth)
		mTail = 0;
}

void Can::push(CanFrame_t *frame)
{
	CanFrame_t *des = &mCanFrame[mHead];
	*des = *frame;

	if(des->extension == 0)
		des->id >>= 18;

	mHead++;
	if (mHead >= mRxBufferDepth)
		mHead = 0;
}

CanFrame_t* Can::getRxPacketPointer(void)
{
	return &mCanFrame[mTail];
}

void Can::flush(void)
{
	__disable_irq();
	mTail = mHead = 0;
	__enable_irq();
}

error_t Can::send(J1939Frame_t packet)
{
	CanFrame_t *src = (CanFrame_t*)&packet;
	return send(*src);
}

J1939Frame_t Can::generateJ1939Frame(uint8_t priority, uint16_t pgn, uint8_t sa, uint8_t count)
{
	J1939Frame_t buf = {0, 0, true, sa, pgn, 0, 0, priority, count, 0, 0,};
	return buf;
}

void Can::setIsrForEvent(void (*func)(error_t code))
{
	mIsrForEvent = func;
}

#endif


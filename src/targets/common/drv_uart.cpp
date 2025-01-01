/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#include <drv/Uart.h>
#include <yss/thread.h>
#include <util/Timeout.h>

#if !defined(YSS_DRV_UART_UNSUPPORTED)

error_t Uart::send(const void *src, int32_t  size)
{
	return send((void*)src, size);
}

void Uart::push(int8_t data)
{
#if defined(YSS__UART_RX_DMA)
#else
	mRcvBuf[mHead++] = data;
	if (mHead >= mRcvBufSize)
		mHead = 0;
#endif
}

void Uart::flush(void)
{
	__disable_irq();
#if defined(YSS__UART_RX_DMA)
	mTail = mRxDma->getCurrentTransferBufferCount();
#else
	mTail = mHead = 0;
#endif
	__enable_irq();
}

int16_t Uart::getRxByte(void)
{
#if defined(YSS__UART_RX_DMA)
	int32_t thisCount = mRxDma->getCurrentTransferBufferCount();
	int16_t buf = -1;

	if(mTail != thisCount)
	{
		buf = mRcvBuf[mRcvBufSize - mTail--];
		if(mTail <= 0)
			mTail = mRcvBufSize;
	}

	return buf;
#else
	int16_t buf = -1;

	if (mHead != mTail)
	{
		buf = (uint8_t)mRcvBuf[mTail++];
		if (mTail >= mRcvBufSize)
			mTail = 0;
	}

	return buf;
#endif
}

bool Uart::waitUntilReceive(uint32_t timeout)
{
	Timeout tout(timeout);

	while(true)
	{
		if(getRxCount() > 0)
			return true;
		else if(tout.isTimeout())
			return false;

		thread::yield();
	}
}

uint32_t Uart::getRxCount(void)
{
#if defined(YSS__UART_RX_DMA)
	int32_t thisCount = mRxDma->getCurrentTransferBufferCount();
	
	if(mTail == thisCount)	
		return 0;
	else if(mTail >= thisCount)
		return mTail - thisCount;
	else 
		return mTail;
#else
	uint32_t head = mHead, tail = mTail;

	if(tail <= head)	
		return head - tail;
	else 
		return mRcvBufSize - tail;
#endif
}

int8_t* Uart::getRxBuffer(void)
{
	return &mRcvBuf[mTail];
}

void Uart::releaseRxBuffer(uint32_t count)
{
	uint32_t buf;

#if defined(YSS__UART_RX_DMA)
	mTail -= count;
	if(mTail <= 0)
		mTail = mRcvBufSize;
#else
	if(mTail < mHead)
	{
		buf = mHead - mTail;
		if(count > buf)
			count = buf;
	}
	else if(mTail > mHead)
	{
		buf = mRcvBufSize - mTail;
		if(count > buf)
			count = buf;
	}
	else
		count = 0;

	mTail += count;
	if(mTail >= mRcvBufSize)
		mTail = 0;
#endif
}

void Uart::setIsrForRxData(void (*isr)(uint8_t rxData))
{
	mIsrForRxData = isr;
}

void Uart::setIsrForFrameError(void (*isr)(void))
{
	mIsrForFrameError = isr;
}

#endif


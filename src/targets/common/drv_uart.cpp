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

#include <drv/peripheral.h>

#include <drv/Uart.h>
#include <yss/thread.h>

#if !defined(YSS_DRV_UART_UNSUPPORTED)

error Uart::initialize(int32_t  baud, int32_t  receiveBufferSize)
{
	void *buf = new uint8_t[receiveBufferSize];
	if (buf == 0)
		return error::MALLOC_FAILED;
	
	return initialize(baud, buf, receiveBufferSize);
}

error Uart::send(const void *src, int32_t  size)
{
	return send((void*)src, size);
}

void Uart::setOneWireMode(bool en)
{
	mOneWireModeFlag = true;
}


void Uart::push(int8_t data)
{
	mRcvBuf[mHead++] = data;
	if (mHead >= mRcvBufSize)
		mHead = 0;
}

void Uart::flush(void)
{
	mTail = mHead;
}

int16_t Uart::getRxByte(void)
{
	int16_t buf = -1;

	if (mHead != mTail)
	{
		buf = (uint8_t)mRcvBuf[mTail++];
		if (mTail >= mRcvBufSize)
			mTail = 0;
	}

	return buf;
}

int16_t Uart::get(void)
{
	return getRxByte();
}

uint8_t Uart::getWaitUntilReceive(void)
{
	int16_t data;

	while (1)
	{
		data = get();
		if (data >= 0)
			return (int8_t)data;
		thread::yield();
	}
}

uint32_t Uart::getRxCount(void)
{
	uint32_t count, head = mHead, tail = mTail;

	if(tail <= head)	
		count = head - tail;
	else 
		count = mRcvBufSize - tail;

	return count;
}

void* Uart::getRxBuffer(void)
{
	return &mRcvBuf[mTail];
}

void Uart::releaseRxBuffer(uint32_t count)
{
	uint32_t buf;

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


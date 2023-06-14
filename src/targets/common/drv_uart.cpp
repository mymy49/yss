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
	mHead = mTail = 0;
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
	if(mTail <= mHead)	
		return mHead - mTail;
	else 
		return mRcvBufSize - mTail;
}

void* Uart::getCurrentBuffer(void)
{
	return &mRcvBuf[mTail];
}

void Uart::releaseBuffer(uint32_t count)
{
	mTail += count;
	if(mTail >= mRcvBufSize)
		mTail = 0;
}

#endif


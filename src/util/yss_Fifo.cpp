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

#include <config.h>
#include <util/Fifo.h>
#include <std_ext/malloc.h>
#include <std_ext/string.h>
#include <yss/thread.h>

Fifo::Fifo(uint32_t size)
{
	mData = 0;
	mHead = 0;
	mTail = 0;
	mSize = size;

	if (mData)
#if (YSS_L_HEAP_USE == true)
		lfree(mData);
	mData = (uint8_t *)lmalloc(size);
#elif (YSS_C_HEAP_USE == true)
		cfree(mData);
	mData = (uint8_t *)cmalloc(size);
#else
		delete mData;
	mData = new uint8_t[size];
#endif
}

Fifo::~Fifo(void)
{
	if (mData)
#if (YSS_L_HEAP_USE == true)
		lfree(mData);
#elif (YSS_C_HEAP_USE == true)
		cfree(mData);
#elif (YSS_H_HEAP_USE == true)
		hfree(mData);
#else
		;
#endif
}

void Fifo::push(void *src, uint32_t size)
{
	uint32_t freeSize;
	int8_t *cSrc = (int8_t*)src;

	while(size)
	{
		if (mTail <= mHead)
			freeSize = mSize - mHead;
		else
			freeSize = mTail - mHead;

		if(freeSize > size)
			freeSize = size;

		if(freeSize)
		{
			memcpy(&mData[mHead], cSrc, freeSize);
			mHead += freeSize;
			cSrc += freeSize;
			if(mHead >= mSize)
				mHead = 0;
			size -= freeSize;
		}
	}
}

void Fifo::push(int8_t src)
{
	mData[mHead++] = src;
	if (mHead >= mSize)
		mHead = 0;
}

void Fifo::pop(void *des, uint32_t size)
{
	uint32_t usedSize;
	int8_t *cDes = (int8_t*)des;

	while(size)
	{
		if (mTail <= mHead)
			usedSize = mSize - mHead;
		else
			usedSize = mTail - mHead;

		if(usedSize > size)
			usedSize = size;
		
		if(usedSize)
		{
			memcpy(cDes, &mData[mTail], usedSize);
			mTail += usedSize;
			cDes += usedSize;
			if(mTail >= mSize)
				mTail = 0;
			size -= usedSize;
		}
	}
}

int8_t Fifo::pop(void)
{
	if(mTail != mHead)
	{
		int8_t ch = mData[mTail++];
		if (mTail >= mSize)
			mTail = 0;
		return ch;
	}
	else
		return 0;
}

uint32_t Fifo::getStoredSize(void)
{
	if (mTail <= mHead)
		return mHead - mTail;
	else
		return mSize - (mTail - mHead);
}

uint32_t Fifo::getFreeSize(void)
{
	if (mTail <= mHead)
		return mSize - (mHead - mTail);
	else
		return mTail - mHead;
}

void Fifo::flush(void)
{
	mTail = mHead = 0;
}
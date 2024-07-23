/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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
#if (YSS_L_HEAP_USE == true)
	if (mData)
		lfree(mData);
#elif (YSS_C_HEAP_USE == true)
	if (mData)
		cfree(mData);
#elif (YSS_H_HEAP_USE == true)
	if (mData)
		hfree(mData);
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
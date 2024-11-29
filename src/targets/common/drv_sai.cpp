/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>
#include <yss/debug.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/Sai.h>
#include <yss/thread.h>
#include <yss/reg.h>

uint32_t Sai::getTxCount(void)
{
	int32_t thisCount = mCurrentDma->getRemainingTransferCount();
	
	if(mLastTransferIndex == thisCount)	
		return 0;
	else if(mLastTransferIndex > thisCount)
		mLastCheckCount =  mLastTransferIndex - thisCount;
	else 
		mLastCheckCount = mLastTransferIndex;

	return mLastCheckCount;
}

uint32_t Sai::getRxCount(void)
{
	int32_t thisCount = mCurrentDma->getRemainingTransferCount();
	
	if(mLastTransferIndex == thisCount)	
		return 0;
	else if(mLastTransferIndex >= thisCount)
		mLastCheckCount =  mLastTransferIndex - thisCount;
	else 
		mLastCheckCount = mLastTransferIndex;

	return mLastCheckCount;
}

void* Sai::getCurrrentBuffer(void)
{
	return &mDataBuffer[(int32_t)mDataSize * (mTransferBufferSize - mLastTransferIndex)];
}

void Sai::releaseBuffer(int32_t count)
{
	if(mLastCheckCount < count)
		count = mLastCheckCount;

	mLastTransferIndex -= count;
	if(mLastTransferIndex == 0)
		mLastTransferIndex = mTransferBufferSize;
}

void Sai::flush(void)
{
	mLastTransferIndex = mCurrentDma->getRemainingTransferCount();
}


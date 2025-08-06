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
#include <drv/I2s.h>
#include <yss/thread.h>
#include <yss/reg.h>

#if !defined(YSS_DRV_I2S_UNSUPPORTED)

uint32_t __WEAK I2s::getRxCount(void)
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

uint32_t __WEAK I2s::getTxCount(void)
{
	int32_t thisCount = mCurrentDma->getRemainingTransferCount();
	
	if(mLastTransferIndex == thisCount)	
		return 0;
	else if(mLastTransferIndex > thisCount)
		mLastCheckCount =  mLastTransferIndex - thisCount;
	else 
		mLastCheckCount = mLastTransferIndex;

	mLastCheckCount &= ~0x01;

	return mLastCheckCount;
}

void* __WEAK I2s::getCurrentBuffer(void)
{
	return &mDataBuffer[(int32_t)mDataSize * (mTransferBufferSize - mLastTransferIndex)];
}

void __WEAK I2s::releaseBuffer(int32_t count)
{
	if(mLastCheckCount < count)
		count = mLastCheckCount;

	mLastTransferIndex -= count;
	if(mLastTransferIndex == 0)
		mLastTransferIndex = mTransferBufferSize;
}

uint32_t __WEAK I2s::getChannelFrameSize(void)
{
	return mDataSize;
}

#endif


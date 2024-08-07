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

//uint32_t I2s::getRxCount(void)
//{
//	int32_t thisCount = mCurrentDma->getCurrentTransferBufferCount();
	
//	if(mLastTransferIndex == thisCount)	
//		return 0;
//	else if(mLastTransferIndex >= thisCount)
//		mLastCheckCount =  mLastTransferIndex - thisCount;
//	else 
//		mLastCheckCount = mLastTransferIndex;

//	return mLastCheckCount;
//}

//uint32_t I2s::getTxCount(void)
//{
//	int32_t thisCount = mCurrentDma->getCurrentTransferBufferCount();
	
//	if(mLastTransferIndex == thisCount)	
//		return 0;
//	else if(mLastTransferIndex > thisCount)
//		mLastCheckCount =  mLastTransferIndex - thisCount;
//	else 
//		mLastCheckCount = mLastTransferIndex;

//	return mLastCheckCount;
//}

//void* I2s::getCurrrentBuffer(void)
//{
//	return &mDataBuffer[(int32_t)mDataSize * (mTransferBufferSize - mLastTransferIndex)];
//}

//void I2s::releaseBuffer(int32_t count)
//{
//	if(mLastCheckCount < count)
//		count = mLastCheckCount;

//	mLastTransferIndex -= count;
//	if(mLastTransferIndex == 0)
//		mLastTransferIndex = mTransferBufferSize;
//}

//void I2s::flush(void)
//{
//	mLastTransferIndex = mCurrentDma->getCurrentTransferBufferCount();
//}

//void I2s::setFrameErrorIsr(void (*isr)(void))
//{
//	mFrameErrorIsr = isr;
//}

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
#include <drv/Spi.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <drv/Spi.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED)

uint32_t Spi::getRxCount(void)
{
	int32_t thisCount = mRxDma->getRemainingTransferCount();
	
	if(mTail >= thisCount)
		return mTail - thisCount;
	else 
		return mTail;
}

void* Spi::getCurrentBuffer(void)
{
	return &mDataBuffer[(int32_t)mDataSize * (mTransferBufferSize - mTail)];
}

void Spi::releaseBuffer(int32_t count)
{
	mTail -= count;
	if(mTail == 0)
		mTail = mTransferBufferSize;
}

void Spi::flush(void)
{
	mTail = mRxDma->getRemainingTransferCount();
}

#endif


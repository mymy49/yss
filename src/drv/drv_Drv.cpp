/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/Drv.h>
#include <yss/instance.h>

Drv::Drv(void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void))
{
	mClockFunc = clockFunc;
	mNvicFunc = nvicFunc;
	mResetFunc = resetFunc;
}

Drv::Drv(const setup_t &setup)
{
	mClockFunc = setup.clockFunc;
	mNvicFunc = setup.nvicFunc;
	mResetFunc = setup.resetFunc;
	mGetClockFunc = setup.getClockFunc;
}

Drv::Drv(void)
{
	mClockFunc = 0;
	mNvicFunc = 0;
	mResetFunc = 0;
	mGetClockFunc = 0;
}

void Drv::enableClock(bool en)
{
	if (mClockFunc)
		mClockFunc(en);
}

void Drv::enableInterrupt(bool en)
{
	if (mNvicFunc)
		mNvicFunc(en);
}

void Drv::reset(void)
{
	if (mResetFunc)
		mResetFunc();
}

uint32_t Drv::getClockFrequency(void)
{
	if (mGetClockFunc)
		return mGetClockFunc();
	else
		return 0;
}

#if defined(DMA_OCCUPANCY_ABLE)
Dma* Drv::getOccupancyDma(void)
{
	while(1)
	{
		for(int8_t ch = DMA_COUNT-1; ch >= 0; ch--)
		{
			if(dmaChannelList[ch]->check())
				return dmaChannelList[ch];
		}
		thread::yield();
	}
}

Dma* Drv::getIdleDma(void)
{
	while(1)
	{
		for(uint8_t ch = 0; ch < DMA_COUNT; ch++)
		{
			if(dmaChannelList[ch]->check())
				return dmaChannelList[ch];
		}
		thread::yield();
	}
}
#endif


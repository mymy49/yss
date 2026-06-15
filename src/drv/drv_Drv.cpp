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
	// Store the platform-specific callbacks for clock, interrupt, and reset control.
	mClockFunc = clockFunc;
	mNvicFunc = nvicFunc;
	mResetFunc = resetFunc;
}

Drv::Drv(const setup_t &setup)
{
	// Initialize callback members from the provided driver setup structure.
	mClockFunc = setup.clockFunc;
	mNvicFunc = setup.nvicFunc;
	mResetFunc = setup.resetFunc;
	mGetClockFunc = setup.getClockFunc;
}

Drv::Drv(void)
{
	// Initialize all callbacks to null so driver methods can safely check existence.
	mClockFunc = 0;
	mNvicFunc = 0;
	mResetFunc = 0;
	mGetClockFunc = 0;
}

void Drv::enableClock(bool en)
{
	// Invoke the platform-specific clock enable/disable callback if available.
	if (mClockFunc)
		mClockFunc(en);
}

void Drv::enableInterrupt(bool en)
{
	// Invoke the platform-specific interrupt enable/disable callback if provided.
	if (mNvicFunc)
		mNvicFunc(en);
}

void Drv::reset(void)
{
	// Reset the peripheral using the registered reset callback.
	if (mResetFunc)
		mResetFunc();
}

uint32_t Drv::getClockFrequency(void)
{
	// Query the current peripheral clock frequency if a callback is available.
	if (mGetClockFunc)
		return mGetClockFunc();
	else
		return 0;
}

#if defined(DMA_OCCUPANCY_ABLE)
Dma* Drv::getOccupancyDma(void)
{
	// Search DMA channels from highest to lowest priority for an available channel.
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
	// Search DMA channels from lowest to highest index to find the first idle channel.
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


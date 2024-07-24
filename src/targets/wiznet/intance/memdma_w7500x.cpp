/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss.h>
#include <config.h>

#if defined(W7500)

#include <targets/wiznet/bitfield_w7500x.h>

void memcpyd(void* des, const void* src, uint32_t size)
{
	if(size == 0)
		return;

	Dma::dmaInfo_t dmaInfo = 
	{
		DMA_CONTROL_DST_INC_Msk |		// uint32_t controlRegister1;
		DMA_CONTROL_DST_SIZE_BYTE << DMA_CONTROL_DST_SIZE_Pos |
		DMA_CONTROL_SRC_INC_Msk |
		DMA_CONTROL_SRC_SIZE_Msk << DMA_CONTROL_SRC_SIZE_Pos |
		size - 1 << DMA_CONTROL_N_MINUS_1_Pos,
//		(void*)src
		(void*)((uint32_t)src + size - 1)		//void *dataRegister;
	};

	des = (void*)((uint32_t)des + size - 1);
	COPY_DMA.lock();
	COPY_DMA.transfer(dmaInfo, des, size);
	COPY_DMA.unlock();
}

void memsetd(void* des, uint8_t data, uint32_t size)
{

	Dma::dmaInfo_t dmaInfo = 
	{
	};

	COPY_DMA.lock();
	COPY_DMA.transfer(dmaInfo, des, size);
	COPY_DMA.unlock();
}

void memsetd(void* des, uint16_t data, uint32_t size)
{
	Dma::dmaInfo_t dmaInfo = 
	{
	};

	COPY_DMA.lock();
	COPY_DMA.send(dmaInfo, des, size);
	COPY_DMA.unlock();
}

void memsetd(void* des, uint32_t data, uint32_t size)
{
	Dma::dmaInfo_t dmaInfo = 
	{
	};

	COPY_DMA.lock();
	COPY_DMA.send(dmaInfo, des, size);
	COPY_DMA.unlock();
}

#endif


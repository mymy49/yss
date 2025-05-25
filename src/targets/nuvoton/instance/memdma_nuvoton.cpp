/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss.h>
#include <config.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#include <targets/nuvoton/bitfield_m4xx.h>
#include <std_ext/string.h>

Dma *gDma;

void initializeDmaCopy(void)
{
	gDma = allocateDma();
	gDma->setSource(PDMA_MEM);
}

void memcpyd(void* des, void* src, uint32_t count)
{
	if(count == 0)
		return;

	Dma::dmaInfo_t dmaInfo = 
	{
		PDMA_WIDTH_8 |
		PDMA_SAR_INC |
		PDMA_REQ_BURST |  
		PDMA_DAR_INC | 
		PDMA_BURST_1 | 
		PDMA_OP_BASIC,		// uint32_t ctl;
		PDMA_MEM,			// uint8_t src;
		src					// void *cpar;
	};
	
	gDma->lock();
	gDma->transfer(dmaInfo, des, count);
	gDma->unlock();
}

void memsetd(void* des, uint8_t data, uint32_t count)
{
	if(count == 0)
		return;

	Dma::dmaInfo_t dmaInfo = 
	{
		PDMA_WIDTH_8 |
		PDMA_SAR_FIX |
		PDMA_REQ_BURST |  
		PDMA_DAR_INC | 
		PDMA_BURST_1 | 
		PDMA_OP_BASIC,		// uint32_t ctl;
		PDMA_MEM,			// uint8_t src;
		&data				// void *cpar;
	};
	
	gDma->lock();
	gDma->transfer(dmaInfo, des, count);
	gDma->unlock();
}

void memsethwd(void* des, uint16_t data, uint32_t count)
{
	if(count == 0)
		return;

	Dma::dmaInfo_t dmaInfo = 
	{
		PDMA_WIDTH_16 |
		PDMA_SAR_FIX |
		PDMA_REQ_BURST |  
		PDMA_DAR_INC | 
		PDMA_BURST_1 | 
		PDMA_OP_BASIC,		// uint32_t ctl;
		PDMA_MEM,			// uint8_t src;
		&data				// void *cpar;
	};
	
	gDma->lock();
	gDma->transfer(dmaInfo, des, count);
	gDma->unlock();
}

void memsetwd(void* des, uint32_t data, uint32_t count)
{
	if(count == 0)
		return;

	Dma::dmaInfo_t dmaInfo = 
	{
		PDMA_WIDTH_32 |
		PDMA_SAR_FIX |
		PDMA_REQ_BURST |  
		PDMA_DAR_INC | 
		PDMA_BURST_1 | 
		PDMA_OP_BASIC,		// uint32_t ctl;
		PDMA_MEM,			// uint8_t src;
		&data				// void *cpar;
	};
	
	gDma->lock();
	gDma->transfer(dmaInfo, des, count);
	gDma->unlock();
}

#endif


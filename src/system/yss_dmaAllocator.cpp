/**
 * @file yss_dmaAllocator.cpp
 * @brief DMA channel allocation interface implementation.
 */

#include <drv/mcu.h>

#if defined(YSS__DMA_ALLOCATION)

#include <drv/Dma.h>

extern Dma *gDmaChannel[YSS__NUM_OF_DMA_CH];
static uint8_t gDmaIndex;

namespace system 
{
	Dma *allocateDma(void)
	{
		if(gDmaIndex >= YSS__NUM_OF_DMA_CH)
			return nullptr;
	
		return gDmaChannel[gDmaIndex++];
	}
}

#endif


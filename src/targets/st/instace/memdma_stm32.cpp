/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss.h>
#include <config.h>

#if defined(STM32F0) || defined(STM32F7)

#if defined(STM32F0) || defined(STM32F7)
#include <targets/st/bitfield.h>
#endif

void memcpyd(void* des, const void* src, uint32_t size)
{

	Dma::dmaInfo_t dmaInfo = 
	{
#if defined(STM32F030xC)
		(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		 // uint32_t controlRegister1
		(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
		(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
		DMA_CCR_PINC_Msk | 
		DMA_CCR_MINC_Msk | 
		DMA_CCR_TCIE_Msk | 
		DMA_CCR_TEIE_Msk | 
		DMA_CCR_MEM2MEM_Msk |
		DMA_CCR_EN_Msk ,
		0xF << (4 * 4),												// uint32_t controlRegister2
		0x0 << (4 * 4),												// uint32_t controlRegister3
		(void*)src													//void *dataRegister;
#elif defined(STM32F7)
		(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) |		// uint32_t controlRegister1
		(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
		(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
		(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
		(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
		DMA_SxCR_PINC_Msk | 
		DMA_SxCR_MINC_Msk | 
		(define::dma::dir::MEM_TO_MEM << DMA_SxCR_DIR_Pos) | 
		DMA_SxCR_TCIE_Msk | 
		DMA_SxCR_TEIE_Msk | 
		DMA_SxCR_EN_Msk,
		0x03,														// uint32_t controlRegister2
		0,															// uint32_t controlRegister3
		(void*)src,													//void *dataRegister;
#endif
	};

	COPY_DMA.lock();
	COPY_DMA.transfer(dmaInfo, des, size);
	COPY_DMA.unlock();
}

void memsetd(void* des, uint8_t data, uint32_t size)
{

	Dma::dmaInfo_t dmaInfo = 
	{
#if defined(STM32F030xC)
		(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		 // uint32_t controlRegister1
		(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
		(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
		DMA_CCR_MINC_Msk | 
		DMA_CCR_TCIE_Msk | 
		DMA_CCR_TEIE_Msk | 
		DMA_CCR_MEM2MEM_Msk |
		DMA_CCR_EN_Msk ,
		0xF << (4 * 4),												// uint32_t controlRegister2
		0x0 << (4 * 4),												// uint32_t controlRegister3
		&data														//void *dataRegister;
#elif defined(STM32F7)
		(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) |		// uint32_t controlRegister1
		(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
		(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
		(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
		(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
		DMA_SxCR_MINC_Msk | 
		(define::dma::dir::MEM_TO_MEM << DMA_SxCR_DIR_Pos) | 
		DMA_SxCR_TCIE_Msk | 
		DMA_SxCR_TEIE_Msk | 
		DMA_SxCR_EN_Msk,
		0x03,														// uint32_t controlRegister2
		0,															// uint32_t controlRegister3
		&data,														//void *dataRegister;
#elif defined(W7500)

#endif
	};

	COPY_DMA.lock();
	COPY_DMA.transfer(dmaInfo, des, size);
	COPY_DMA.unlock();
}

void memsethwd(void* des, uint16_t data, uint32_t size)
{
	Dma::dmaInfo_t dmaInfo = 
	{
#if defined(STM32F030xC)
		(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		 // uint32_t controlRegister1
		(define::dma::size::HALF_WORD << DMA_CCR_MSIZE_Pos) |
		(define::dma::size::HALF_WORD << DMA_CCR_PSIZE_Pos) |
		DMA_CCR_MINC_Msk | 
		DMA_CCR_TCIE_Msk | 
		DMA_CCR_TEIE_Msk | 
		DMA_CCR_MEM2MEM_Msk |
		DMA_CCR_EN_Msk ,
		0xF << (4 * 4),												// uint32_t controlRegister2
		0x0 << (4 * 4),												// uint32_t controlRegister3
		&data														//void *dataRegister;
#elif defined(STM32F7)
		(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) |		// uint32_t controlRegister1
		(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
		(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
		(define::dma::size::HALF_WORD << DMA_SxCR_MSIZE_Pos) |
		(define::dma::size::HALF_WORD << DMA_SxCR_PSIZE_Pos) |
		DMA_SxCR_MINC_Msk | 
		(define::dma::dir::MEM_TO_MEM << DMA_SxCR_DIR_Pos) | 
		DMA_SxCR_TCIE_Msk | 
		DMA_SxCR_TEIE_Msk | 
		DMA_SxCR_EN_Msk,
		0x03,														// uint32_t controlRegister2
		0,															// uint32_t controlRegister3
		&data,														//void *dataRegister;
#endif
	};

	COPY_DMA.lock();
	COPY_DMA.transfer(dmaInfo, des, size);
	COPY_DMA.unlock();
}

void memsetwd(void* des, uint32_t data, uint32_t size)
{
	Dma::dmaInfo_t dmaInfo = 
	{
#if defined(STM32F030xC)
		(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		 // uint32_t controlRegister1
		(define::dma::size::WORD << DMA_CCR_MSIZE_Pos) |
		(define::dma::size::WORD << DMA_CCR_PSIZE_Pos) |
		DMA_CCR_MINC_Msk | 
		DMA_CCR_TCIE_Msk | 
		DMA_CCR_TEIE_Msk | 
		DMA_CCR_MEM2MEM_Msk |
		DMA_CCR_EN_Msk ,
		0xF << (4 * 4),												// uint32_t controlRegister2
		0x0 << (4 * 4),												// uint32_t controlRegister3
		&data														//void *dataRegister;
#elif defined(STM32F7)
		(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) |		// uint32_t controlRegister1
		(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
		(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
		(define::dma::size::WORD << DMA_SxCR_MSIZE_Pos) |
		(define::dma::size::WORD << DMA_SxCR_PSIZE_Pos) |
		DMA_SxCR_MINC_Msk | 
		(define::dma::dir::MEM_TO_MEM << DMA_SxCR_DIR_Pos) | 
		DMA_SxCR_TCIE_Msk | 
		DMA_SxCR_TEIE_Msk | 
		DMA_SxCR_EN_Msk,
		0x03,														// uint32_t controlRegister2
		0,															// uint32_t controlRegister3
		&data,														//void *dataRegister;
#endif
	};

	COPY_DMA.lock();
	COPY_DMA.transfer(dmaInfo, des, size);
	COPY_DMA.unlock();
}

#endif


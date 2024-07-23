/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F7)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/st/bitfield.h>

#if QUADSPI_ENABLE && defined(QUADSPI)
static uint32_t getAhbClockFrequency(void)
{
	return clock.getAhbClockFrequency();
}

static void enableQuadspiClock(bool en)
{
	clock.lock();
    clock.enableAhb3Clock(RCC_AHB3ENR_QSPIEN_Pos, en);
	clock.unlock();
}

static void enableQuadspiInterrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(QUADSPI_IRQn, en);
	nvic.unlock();
}

static void resetQuadspi(void)
{
	clock.lock();
    clock.resetAhb3(RCC_AHB3RSTR_QSPIRST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvQuadspiSetup = 
{
	enableQuadspiClock,		//void (*clockFunc)(bool en);
	enableQuadspiInterrupt,	//void (*nvicFunc)(bool en);
	resetQuadspi,			//void (*resetFunc)(void);
	getAhbClockFrequency,	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gQuadspiTxDmaInfo = 
{
	(define::dma2::stream7::QUADSPI_DMA << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
//	DMA_SxCR_PFCTRL_Msk |
	DMA_SxCR_EN_Msk,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&QUADSPI->DR,										// void *dataRegister;
};

static const Dma::dmaInfo_t gQuadspiRxDmaInfo = 
{
	(define::dma2::stream7::QUADSPI_DMA << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
//	DMA_SxCR_PFCTRL_Msk |
	DMA_SxCR_EN_Msk,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&QUADSPI->DR,										//void *dataRegister;
};

static const Quadspi::setup_t gQuadSetup = 
{
	QUADSPI,			//YSS_QUADSPI_Peri *peri;
	dmaChannel16,		//Dma &txDma;
	gQuadspiTxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel16,		//Dma &rxDma;
	gQuadspiRxDmaInfo,	//Dma::dmaInfo_t rxDmaInfo;
};

Quadspi quadspi(gDrvQuadspiSetup, gQuadSetup);

#endif

#endif


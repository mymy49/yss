/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4) || defined(STM32F7)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#endif

#if SAI1_ENABLE && defined(SAI1)
static uint32_t getSai1ClockFrequency(void)
{
	return clock.getSai1ClockFrequency();
}

static void enableSai1Clock(bool en)
{
	clock.lock();
	clock.enableApb2Clock(RCC_APB2ENR_SAI1EN_Pos, en);
	clock.unlock();
}

static void enableSai1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SAI1_IRQn, en);
	nvic.unlock();
}

static void resetSai1(void)
{
	clock.lock();
	clock.resetApb1(RCC_APB2RSTR_SAI1RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvSai1Config
{
	enableSai1Clock,		// void (*clockFunc)(bool en);
	enableSai1Interrupt,	// void (*nvicFunc)(bool en);
	resetSai1,				// void (*resetFunc)(void);
	getSai1ClockFrequency		// uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gSai1ATxDmaInfo = 
{
	(define::dma2::stream1::SAI1_A << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::HALF_WORD << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::HALF_WORD << DMA_SxCR_PSIZE_Pos) |
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_MINC_Msk | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_HTIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_CIRC_Msk | 
	DMA_SxCR_EN_Msk ,
	DMA_SxFCR_DMDIS_Msk,					// uint32_t controlRegister2
	0,										// uint32_t controlRegister3
	(void*)&SAI1_Block_A->DR				//void *dataRegister;
};

static Dma::dmaInfo_t gSai1ARxDmaInfo = 
{
	(define::dma2::stream1::SAI1_A << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::HALF_WORD << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::HALF_WORD << DMA_SxCR_PSIZE_Pos) |
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_MINC_Msk | 
//	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_HTIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_CIRC_Msk | 
	DMA_SxCR_EN_Msk ,
	DMA_SxFCR_DMDIS_Msk,					// uint32_t controlRegister2
	0,										// uint32_t controlRegister3
	(void*)&SAI1_Block_A->DR				//void *dataRegister;
};

static Sai::Config gSai1AConfig
{
	(YSS_SAI_Peri*)SAI1,				//YSS_SAI_Peri *peri;
	(YSS_SAI_Block_Peri*)SAI1_Block_A,	//YSS_SAI_Block_Peri *block;
	dmaChannel10,						//Dma &txDma;
	gSai1ATxDmaInfo,					//Dma::dmaInfo_t txDmaInfo;
	dmaChannel10,						//Dma &txDma;
	gSai1ARxDmaInfo						//Dma::dmaInfo_t txDmaInfo;
};

Sai sai1A(gDrvSai1Config, gSai1AConfig);

static const Dma::dmaInfo_t gSai1BTxDmaInfo = 
{
	(define::dma2::stream5::SAI1_B << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::HALF_WORD << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::HALF_WORD << DMA_SxCR_PSIZE_Pos) |
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_MINC_Msk | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_HTIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_CIRC_Msk | 
	DMA_SxCR_EN_Msk ,
	DMA_SxFCR_DMDIS_Msk,					// uint32_t controlRegister2
	0,										// uint32_t controlRegister3
	(void*)&SAI1_Block_B->DR				// void *dataRegister;
};

static const Dma::dmaInfo_t gSai1BRxDmaInfo = 
{
	(define::dma2::stream5::SAI1_B << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::HALF_WORD << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::HALF_WORD << DMA_SxCR_PSIZE_Pos) |
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_MINC_Msk | 
//	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_HTIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_CIRC_Msk | 
	DMA_SxCR_EN_Msk ,
	DMA_SxFCR_DMDIS_Msk,					// uint32_t controlRegister2
	0,										// uint32_t controlRegister3
	(void*)&SAI1_Block_B->DR				//void *dataRegister;
};

static const Sai::Config gSai1BConfig
{
	(YSS_SAI_Peri*)SAI1,				//YSS_SAI_Peri *peri;
	(YSS_SAI_Block_Peri*)SAI1_Block_B,	//YSS_SAI_Block_Peri *block;
	dmaChannel14,						//Dma &txDma;
	gSai1BTxDmaInfo,					//Dma::dmaInfo_t txDmaInfo;
	dmaChannel14,						//Dma &txDma;
	gSai1BRxDmaInfo						//Dma::dmaInfo_t txDmaInfo;
};

Sai sai1B(gDrvSai1Config, gSai1BConfig);
#endif

#endif


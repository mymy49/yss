/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/nuvoton/bitfield_m48x.h>



#if SPI0_ENABLE && defined(SPI0)
static void enableSpi0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_SPI0CKEN_Pos, en);
}

static void enableSpi0Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI0_IRQn, en);
	nvic.unlock();
}

static void resetSpi0(void)
{
}

static uint32_t getSpi0ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL2 & CLK_CLKSEL2_SPI0SEL_Msk) >> CLK_CLKSEL2_SPI0SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // PCLK1
		clk = clock.getApb1ClockFrequency();
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}
	
	return clk;
}

static const Drv::setup_t gDrvSpi0Setup = 
{
	enableSpi0Clock,		//void (*clockFunc)(bool en);
	enableSpi0Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi0,				//void (*resetFunc)(void);
	getSpi0ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi0TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI0_TX,		// uint8_t src;
	(void*)&SPI0->TX,	// void *cpar;
};

static const Dma::dmaInfo_t gSpi0RxDmaInfo = 
{
	PDMA_DIR_PERI_TO_MEM |
	PDMA_WIDTH_8 |
	PDMA_SAR_FIX |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_INC | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI0_RX,		// uint8_t src;
	(void*)&SPI0->RX,	// void *cpar;
};

static const Spi::setup_t gSpi0Setup = 
{
	SPI0,			//YSS_SPI_Peri *peri;
	gSpi0TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi0RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

Spi spi0(gDrvSpi0Setup, gSpi0Setup);

extern "C"
{
	void SPI0_IRQHandler(void)
	{
		spi0.isr();
	}
}
#endif



#if SPI1_ENABLE && defined(SPI1)
static void enableSpi1Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_SPI1CKEN_Pos, en);
}

static void enableSpi1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI1_IRQn, en);
	nvic.unlock();
}

static void resetSpi1(void)
{
}

static uint32_t getSpi1ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL2 & CLK_CLKSEL2_SPI1SEL_Msk) >> CLK_CLKSEL2_SPI1SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // PCLK0
		clk = clock.getApb0ClockFrequency();
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}
	
	return clk;
}

static const Drv::setup_t gDrvSpi1Setup = 
{
	enableSpi1Clock,		//void (*clockFunc)(bool en);
	enableSpi1Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi1,				//void (*resetFunc)(void);
	getSpi1ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi1TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI1_TX,		// uint8_t src;
	(void*)&SPI1->TX,	// void *cpar;
};

static const Dma::dmaInfo_t gSpi1RxDmaInfo = 
{
	PDMA_DIR_PERI_TO_MEM |
	PDMA_WIDTH_8 |
	PDMA_SAR_FIX |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_INC | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI1_RX,		// uint8_t src;
	(void*)&SPI1->RX,	// void *cpar;
};

static const Spi::setup_t gSpi1Setup = 
{
	SPI1,			//YSS_SPI_Peri *peri;
	gSpi1TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi1RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

Spi spi1(gDrvSpi1Setup, gSpi1Setup);

extern "C"
{
	void SPI1_IRQHandler(void)
	{
		spi1.isr();
	}
}
#endif



#if SPI2_ENABLE && defined(SPI2)
static void enableSpi2Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_SPI2CKEN_Pos, en);
}

static void enableSpi2Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI2_IRQn, en);
	nvic.unlock();
}

static void resetSpi2(void)
{
}

static uint32_t getSpi2ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL2 & CLK_CLKSEL2_SPI2SEL_Msk) >> CLK_CLKSEL2_SPI2SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // PCLK1
		clk = clock.getApb1ClockFrequency();
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}
	
	return clk;
}

static const Drv::setup_t gDrvSpi2Setup = 
{
	enableSpi2Clock,		//void (*clockFunc)(bool en);
	enableSpi2Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi2,				//void (*resetFunc)(void);
	getSpi2ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi2TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI2_TX,		// uint8_t src;
	(void*)&SPI2->TX,	// void *cpar;
};

static const Dma::dmaInfo_t gSpi2RxDmaInfo = 
{
	PDMA_DIR_PERI_TO_MEM |
	PDMA_WIDTH_8 |
	PDMA_SAR_FIX |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_INC | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI2_RX,		// uint8_t src;
	(void*)&SPI2->RX,	// void *cpar;
};

static const Spi::setup_t gSpi2Setup = 
{
	SPI2,			//YSS_SPI_Peri *peri;
	gSpi2TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi2RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

Spi spi2(gDrvSpi2Setup, gSpi2Setup);

extern "C"
{
	void SPI2_IRQHandler(void)
	{
		spi2.isr();
	}
}
#endif

#if SPI3_ENABLE && defined(SPI3)
static void enableSpi3Clock(bool en)
{
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_SPI3EN_Pos, en);
#else
    clock.enableApb1Clock(RCC_APB1ENR_SPI3EN_Pos, en);
#endif
	clock.unlock();
}

static void enableSpi3Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI3_IRQn, en);
	nvic.unlock();
}

static void resetSpi3(void)
{
	clock.lock();
#if defined(STM32G4)
    clock.resetApb1_1(RCC_APB1RSTR1_SPI3RST_Pos);
#else
    clock.resetApb1(RCC_APB1RSTR_SPI3RST_Pos);
#endif
	clock.unlock();
}

static const Drv::setup_t gDrvSpi3Setup = 
{
	enableSpi3Clock,		//void (*clockFunc)(bool en);
	enableSpi3Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi3,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi3TxDmaInfo = 
{
#if defined(STM32F1) || defined(GD32F1)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		// uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk ,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&SPI3[SPI_REG::DR],									//void *dataRegister;
#elif defined(STM32G4)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |			// uint32_t ccr;
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk,
	define::dmamux::input::SPI3_TX << DMAMUX_CxCR_DMAREQ_ID_Pos,	// uint32_t muxccr;
	(void*)&SPI3->DR												// void *cpar;
#elif defined(STM32F4) || defined(STM32F7)
	(define::dma1::stream5::SPI3_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&SPI3->DR,											//void *dataRegister;
#endif
};

static const Dma::dmaInfo_t gSpi3RxDmaInfo = 
{
#if defined(STM32F1) || defined(GD32F1)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		// uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk ,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&SPI3[SPI_REG::DR],									//void *dataRegister;
#elif defined(STM32G4)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |			// uint32_t ccr;
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk,
	define::dmamux::input::SPI3_RX << DMAMUX_CxCR_DMAREQ_ID_Pos,	// uint32_t muxccr;
	(void*)&SPI3->DR												// void *cpar;
#elif defined(STM32F4) || defined(STM32F7)
	(define::dma1::stream0::SPI3_RX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&SPI3->DR,											//void *dataRegister;
#endif
};

static const Spi::setup_t gSpi3Setup = 
{
#if defined(STM32G4)
	SPI3,			//YSS_SPI_Peri *peri;
	gSpi3TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi3RxDmaInfo,	//Dma::dmaInfo_t rxDmaInfo;
#else
	SPI3,			//YSS_SPI_Peri *peri;
	dmaChannel6,	//Dma &txDma;
	gSpi3TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel1,	//Dma &rxDma;
	gSpi3RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
#endif
};

Spi spi3(gDrvSpi3Setup, gSpi3Setup);

extern "C"
{
	void SPI3_IRQHandler(void)
	{
		spi3.isr();
	}
}
#endif



#if SPI4_ENABLE && defined(SPI4)
static void enableSpi4Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB2ENR_SPI4EN_Pos, en);
	clock.unlock();
}

static void enableSpi4Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI4_IRQn, en);
	nvic.unlock();
}

static void resetSpi4(void)
{
	clock.lock();
    clock.resetApb2(RCC_APB2RSTR_SPI4RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvSpi4Setup = 
{
	enableSpi4Clock,		//void (*clockFunc)(bool en);
	enableSpi4Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi4,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi4TxDmaInfo = 
{
	(define::dma2::stream1::SPI4_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)SPI4->DR,											//void *dataRegister;
};

static const Dma::dmaInfo_t gSpi4RxDmaInfo = 
{
	(define::dma2::stream0::SPI4_RX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS,											// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&SPI4->DR,											//void *dataRegister;
};

static const Spi::setup_t gSpi4Setup = 
{
	SPI4,			//YSS_SPI_Peri *peri;
	dmaChannel10,	//Dma &txDma;
	gSpi4TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel9,	//Dma &rxDma;
	gSpi4RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

Spi spi4(gDrvSpi4Setup, gSpi4Setup);

extern "C"
{
	void SPI4_IRQHandler(void)
	{
		spi4.isr();
	}
}
#endif



#if SPI5_ENABLE && defined(SPI5)
static void enableSpi5Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_SPI5EN_Pos, en);
	clock.unlock();
}

static void enableSpi5Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI5_IRQn, en);
	nvic.unlock();
}

static void resetSpi5(void)
{
	clock.lock();
    clock.resetApb2(RCC_APB2RSTR_SPI5RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvSpi5Setup = 
{
	enableSpi5Clock,		//void (*clockFunc)(bool en);
	enableSpi5Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi5,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi5TxDmaInfo = 
{
	(define::dma2::stream4::SPI5_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&SPI5->DR,											//void *dataRegister;
};

static const Dma::dmaInfo_t gSpi5RxDmaInfo = 
{
	(define::dma2::stream3::SPI5_RX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&SPI5->DR,											//void *dataRegister;
};

static const Spi::setup_t gSpi5Setup = 
{
	SPI5,			//YSS_SPI_Peri *peri;
	dmaChannel13,	//Dma &txDma;
	gSpi5TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel12,	//Dma &rxDma;
	gSpi5RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

Spi spi5(gDrvSpi5Setup, gSpi5Setup);

extern "C"
{
	void SPI5_IRQHandler(void)
	{
		spi5.isr();
	}
}
#endif

#endif


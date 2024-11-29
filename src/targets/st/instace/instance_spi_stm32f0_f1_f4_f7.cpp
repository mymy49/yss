/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32F0) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/st/bitfield.h>

#if SPI2_ENABLE || SPI3_ENABLE
static uint32_t getApb1ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}
#endif

#if SPI1_ENABLE || SPI4_ENABLE || SPI5_ENABLE || SPI6_ENABLE
static uint32_t getApb2ClockFrequency(void)
{
	return clock.getApb2ClockFrequency();
}
#endif

#if SPI1_ENABLE && defined(SPI1)
static void enableSpi1Clock(bool en)
{
	clock.lock();
    clock.enableApb2Clock(RCC_APB2ENR_SPI1EN_Pos, en);
	clock.unlock();
}

static void enableSpi1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI1_IRQn, en);
	nvic.unlock();
}

static void resetSpi1(void)
{
	clock.lock();
    clock.resetApb2(RCC_APB2RSTR_SPI1RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvSpi1Setup = 
{
	enableSpi1Clock,		//void (*clockFunc)(bool en);
	enableSpi1Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi1,				//void (*resetFunc)(void);
	getApb2ClockFrequency,	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi1TxDmaInfo = 
{
#if defined(STM32F1) || defined(GD32F1)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |	 // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&SPI1->DR,											// void *dataRegister;
#elif defined(STM32G4)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |			// uint32_t ccr;
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk,
	define::dmamux::input::SPI1_TX << DMAMUX_CxCR_DMAREQ_ID_Pos,	// uint32_t muxccr;
	(void*)&SPI1->DR												// void *cpar;
#elif defined(STM32F4) || defined(STM32F7)
	(define::dma2::stream3::SPI1_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
	(void*)&SPI1->DR,											// void *dataRegister;
#endif
};

static const Dma::dmaInfo_t gSpi1RxDmaInfo = 
{
#if defined(STM32F1) || defined(GD32F1)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		// uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&SPI1->DR,											// void *dataRegister;
#elif defined(STM32G4)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |			// uint32_t ccr;
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk,
	define::dmamux::input::SPI1_RX << DMAMUX_CxCR_DMAREQ_ID_Pos,	// uint32_t muxccr;
	(void*)&SPI1->DR												// void *cpar;
#elif defined(STM32F4) || defined(STM32F7)
	(define::dma2::stream0::SPI1_RX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
	(void*)&SPI1->DR,											//void *dataRegister;
#endif
};

static const Spi::setup_t gSpi1Setup = 
{
#if defined(STM32F0) || defined(STM32F1)
	SPI1,			//YSS_SPI_Peri *peri;
	dmaChannel3,	//Dma &txDma;
	gSpi1TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel2,	//Dma &rxDma;
	gSpi1RxDmaInfo,	//Dma::dmaInfo_t rxDmaInfo;
#elif defined(STM32G4)
	SPI1,			//YSS_SPI_Peri *peri;
	gSpi1TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi1RxDmaInfo,	//Dma::dmaInfo_t rxDmaInfo;
#else
	SPI1,			//YSS_SPI_Peri *peri;
	dmaChannel12,	//Dma &txDma;
	gSpi1TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel9,	//Dma &rxDma;
	gSpi1RxDmaInfo,	//Dma::dmaInfo_t rxDmaInfo;
	
#endif
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
	clock.lock();
#if defined(STM32G4)
    clock.enableApb1_1Clock(RCC_APB1ENR1_SPI2EN_Pos, en);
#else
    clock.enableApb1Clock(RCC_APB1ENR_SPI2EN_Pos, en);
#endif
	clock.unlock();
}

static void enableSpi2Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI2_IRQn, en);
	nvic.unlock();
}

static void resetSpi2(void)
{
	clock.lock();
#if defined(STM32G4)
    clock.resetApb1_1(RCC_APB1RSTR1_SPI2RST_Pos);
#else
    clock.resetApb1(RCC_APB1RSTR_SPI2RST_Pos);
#endif
	clock.unlock();
}

static const Drv::setup_t gDrvSpi2Setup = 
{
	enableSpi2Clock,		//void (*clockFunc)(bool en);
	enableSpi2Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi2,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi2TxDmaInfo = 
{
#if defined(STM32F1) || defined(STM32F0) || defined(GD32F1)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		 // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk ,
	0x0F << (4 * 4),											// uint32_t controlRegister2
	0x03 << (4 * 4),											// uint32_t controlRegister3
	(void*)&SPI2->DR,											//void *dataRegister;
#elif defined(STM32F4) || defined(STM32F7)
	(define::dma1::stream4::SPI2_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
	(void*)&SPI2->DR,											//void *dataRegister;
#elif defined(STM32G4)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |			// uint32_t ccr;
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk,
	define::dmamux::input::SPI2_TX << DMAMUX_CxCR_DMAREQ_ID_Pos,	// uint32_t muxccr;
	(void*)&SPI2->DR												// void *cpar;
#endif
};

static const Dma::dmaInfo_t gSpi2RxDmaInfo = 
{
#if defined(STM32F1) || defined(STM32F0) || defined(GD32F1)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		// uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk ,
	0x0F << (4 * 3),											// uint32_t controlRegister2
	0x03 << (4 * 3),											// uint32_t controlRegister3
	(void*)&SPI2->DR,											//void *dataRegister;
#elif defined(STM32F4) || defined(STM32F7)
	(define::dma1::stream3::SPI2_RX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
	(void*)&SPI2->DR,											//void *dataRegister;
#elif defined(STM32G4)
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |			// uint32_t ccr;
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk,
	define::dmamux::input::SPI2_RX << DMAMUX_CxCR_DMAREQ_ID_Pos,	// uint32_t muxccr;
	(void*)&SPI2->DR												// void *cpar;
#endif
};

static const Spi::setup_t gSpi2Setup = 
{
#if defined(STM32G4)
	SPI2,			//YSS_SPI_Peri *peri;
	gSpi2TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi2RxDmaInfo,	//Dma::dmaInfo_t rxDmaInfo;
#else
	SPI2,			//YSS_SPI_Peri *peri;
	dmaChannel5,	//Dma &txDma;
	gSpi2TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel4,	//Dma &rxDma;
	gSpi2RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
#endif
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


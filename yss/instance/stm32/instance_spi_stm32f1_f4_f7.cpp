////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>
#include <yss/instance.h>
#include <config.h>

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7)

using namespace define::dma;

static int getApb2ClkFreq(void)
{
	return clock.getApb2ClkFreq();
}

static int getApb1ClkFreq(void)
{
	return clock.getApb1ClkFreq();
}

#if defined(SPI1_ENABLE) && defined(SPI1)
static void setSpi1ClockEn(bool en)
{
	clock.peripheral.setSpi1En(en);
}

void setSpi1InterruptEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(SPI1_IRQn);
	else
		NVIC_DisableIRQ(SPI1_IRQn);
}

static void resetSpi1(void)
{
	clock.peripheral.resetSpi1();
}

static const Drv::Config gDrvSpi1Config
{
	setSpi1ClockEn,		//void (*clockFunc)(bool en);
	setSpi1InterruptEn,	//void (*nvicFunc)(bool en);
	resetSpi1,			//void (*resetFunc)(void);
	getApb2ClkFreq,		//unsigned int (*getClockFreq)(void);
};

#if defined(STM32F1)
static const Dma::DmaInfo gSpi1TxDmaInfo = 
{
	(priorityLevel::LOW << DMA_CCR_PL_Pos) | // unsigned int controlRegister1
	(size::BYTE << DMA_CCR_MSIZE_Pos) |
	(size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI1->DR,									//void *dataRegister;
};

static const Dma::DmaInfo gSpi1RxDmaInfo = 
{
	(priorityLevel::LOW << DMA_CCR_PL_Pos) | // unsigned int controlRegister1
	(size::BYTE << DMA_CCR_MSIZE_Pos) |
	(size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(dir::PERI_TO_MEM << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI1->DR,									//void *dataRegister;
};

static const Spi::Config gSpi1Config
{
	SPI1,			//YSS_SPI_Peri *peri;
	dmaChannel3,	//Dma &txDma;
	gSpi1TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel2,	//Dma &rxDma;
	gSpi1RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
};

#else
static const Dma::DmaInfo gSpi1TxDmaInfo = 
{
	(define::dma2::stream3::SPI1_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI1->DR,											//void *dataRegister;
};

static const Dma::DmaInfo gSpi1RxDmaInfo = 
{
	(define::dma2::stream0::SPI1_RX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI1->DR,											//void *dataRegister;
};

static const Spi::Config gSpi1Config
{
	SPI1,			//YSS_SPI_Peri *peri;
	dmaChannel12,	//Dma &txDma;
	gSpi1TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel9,	//Dma &rxDma;
	gSpi1RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};
#endif

Spi spi1(gDrvSpi1Config, gSpi1Config);

extern "C"
{
void SPI1_IRQHandler(void)
{
	spi1.isr();
}
}
#endif



#if defined(SPI2_ENABLE) && defined(SPI2)
static void setSpi2ClockEn(bool en)
{
	clock.peripheral.setSpi2En(en);
}

void setSpi2InterruptEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(SPI2_IRQn);
	else
		NVIC_DisableIRQ(SPI2_IRQn);
}

static void resetSpi2(void)
{
	clock.peripheral.resetSpi2();
}

static const Drv::Config gDrvSpi2Config
{
	setSpi2ClockEn,		//void (*clockFunc)(bool en);
	setSpi2InterruptEn,	//void (*nvicFunc)(bool en);
	resetSpi2,			//void (*resetFunc)(void);
	getApb1ClkFreq		//unsigned int (*getClockFreq)(void);
};

#if defined(STM32F1)
static const Dma::DmaInfo gSpi2TxDmaInfo = 
{
	(priorityLevel::LOW << DMA_CCR_PL_Pos) | // unsigned int controlRegister1
	(size::BYTE << DMA_CCR_MSIZE_Pos) |
	(size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI2->DR,									//void *dataRegister;
};

static const Dma::DmaInfo gSpi2RxDmaInfo = 
{
	(priorityLevel::LOW << DMA_CCR_PL_Pos) | // unsigned int controlRegister1
	(size::BYTE << DMA_CCR_MSIZE_Pos) |
	(size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(dir::PERI_TO_MEM << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI2->DR,									//void *dataRegister;
};

static const Spi::Config gSpi2Config
{
	SPI2,			//YSS_SPI_Peri *peri;
	dmaChannel5,	//Dma &txDma;
	gSpi2TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel4,	//Dma &rxDma;
	gSpi2RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
};
#else
static const Dma::DmaInfo gSpi2TxDmaInfo = 
{
	(define::dma1::stream4::SPI2_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI2->DR,											//void *dataRegister;
};

static const Dma::DmaInfo gSpi2RxDmaInfo = 
{
	(define::dma1::stream3::SPI2_RX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI2->DR,											//void *dataRegister;
};

static const Spi::Config gSpi2Config
{
	SPI2,			//YSS_SPI_Peri *peri;
	dmaChannel5,	//Dma &txDma;
	gSpi2TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel4,	//Dma &rxDma;
	gSpi2RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};
#endif

Spi spi2(gDrvSpi2Config, gSpi2Config);

extern "C"
{
void SPI2_IRQHandler(void)
{
	spi2.isr();
}
}
#endif



#if defined(SPI3_ENABLE) && defined(SPI3)
static void setSpi3ClockEn(bool en)
{
	clock.peripheral.setSpi3En(en);
}

static void resetSpi3(void)
{
	clock.peripheral.resetSpi3();
}

void setSpi3InterruptEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(SPI3_IRQn);
	else
		NVIC_DisableIRQ(SPI3_IRQn);
}

static const Drv::Config gDrvSpi3Config
{
	setSpi3ClockEn,		//void (*clockFunc)(bool en);
	setSpi3InterruptEn,	//void (*nvicFunc)(bool en);
	resetSpi3,			//void (*resetFunc)(void);
	getApb1ClkFreq,		//unsigned int (*getClockFreq)(void);
};

#if defined(STM32F1)
static const Dma::DmaInfo gSpi3TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // unsigned int controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI3->DR,									//void *dataRegister;
};

static const Dma::DmaInfo gSpi3RxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // unsigned int controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI3->DR,									//void *dataRegister;
};

static const Spi::Config gSpi3Config
{
	SPI3,			//YSS_SPI_Peri *peri;
	dmaChannel9,	//Dma &txDma;
	gSpi3TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel8,	//Dma &rxDma;
	gSpi3RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};
#else
static const Dma::DmaInfo gSpi3TxDmaInfo = 
{
	(define::dma1::stream5::SPI3_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI3->DR											//void *dataRegister;
};

static const Dma::DmaInfo gSpi3RxDmaInfo = 
{
	(define::dma1::stream0::SPI3_RX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI3->DR											//void *dataRegister;
};

static const Spi::Config gSpi3Config
{
	SPI3,			//YSS_SPI_Peri *peri;
	dmaChannel6,	//Dma &txDma;
	gSpi3TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel1,	//Dma &rxDma;
	gSpi3RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};
#endif

Spi spi3(gDrvSpi3Config, gSpi3Config);

extern "C"
{
void SPI3_IRQHandler(void)
{
	spi3.isr();
}
}
#endif



#if defined(SPI4_ENABLE) && defined(SPI4)
static void setSpi4ClockEn(bool en)
{
	clock.peripheral.setSpi4En(en);
}

void setSpi4InterruptEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(SPI4_IRQn);
	else
		NVIC_DisableIRQ(SPI4_IRQn);
}

static void resetSpi4(void)
{
	clock.peripheral.resetSpi4();
}

static const Drv::Config gDrvSpi4Config
{
	setSpi4ClockEn,		//void (*clockFunc)(bool en);
	setSpi4InterruptEn,	//void (*nvicFunc)(bool en);
	resetSpi4,			//void (*resetFunc)(void);
	getApb2ClkFreq		//unsigned int (*getClockFreq)(void);
};

static const Dma::DmaInfo gSpi4TxDmaInfo = 
{
	(define::dma2::stream1::SPI4_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI4->DR											//void *dataRegister;
};

static const Dma::DmaInfo gSpi4RxDmaInfo = 
{
	(define::dma2::stream0::SPI4_RX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI4->DR,											//void *dataRegister;
};

static const Spi::Config gSpi4Config
{
	SPI4,			//YSS_SPI_Peri *peri;
	dmaChannel10,	//Dma &txDma;
	gSpi4TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel9,	//Dma &rxDma;
	gSpi4RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};

Spi spi4(gDrvSpi4Config, gSpi4Config);

extern "C"
{
void SPI4_IRQHandler(void)
{
	spi4.isr();
}
}
#endif



#if defined(SPI5_ENABLE) && defined(SPI5)
static void setSpi5ClockEn(bool en)
{
	clock.peripheral.setSpi5En(en);
}

void setSpi5InterruptEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(SPI5_IRQn);
	else
		NVIC_DisableIRQ(SPI5_IRQn);
}

static void resetSpi5(void)
{
	clock.peripheral.resetSpi5();
}

static const Drv::Config gDrvSpi5Config
{
	setSpi5ClockEn,		//void (*clockFunc)(bool en);
	setSpi5InterruptEn,	//void (*nvicFunc)(bool en);
	resetSpi5,			//void (*resetFunc)(void);
	getApb2ClkFreq		//unsigned int (*getClockFreq)(void);
};

static const Dma::DmaInfo gSpi5TxDmaInfo = 
{
	(define::dma2::stream4::SPI5_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI5->DR,											//void *dataRegister;
};

static const Dma::DmaInfo gSpi5RxDmaInfo = 
{
	(define::dma2::stream3::SPI5_RX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI5->DR,											//void *dataRegister;
};

static const Spi::Config gSpi5Config
{
	SPI5,			//YSS_SPI_Peri *peri;
	dmaChannel13,	//Dma &txDma;
	gSpi5TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel12,	//Dma &rxDma;
	gSpi5RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};

Spi spi5(gDrvSpi5Config, gSpi5Config);

extern "C"
{
void SPI5_IRQHandler(void)
{
	spi5.isr();
}
}
#endif



#if defined(SPI6_ENABLE) && defined(SPI6)
static void setSpi6ClockEn(bool en)
{
	clock.peripheral.setSpi6En(en);
}

static void resetSpi6(void)
{
	clock.peripheral.resetSpi6();
}

void setSpi6InterruptEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(SPI6_IRQn);
	else
		NVIC_DisableIRQ(SPI6_IRQn);
}

static const Drv::Config gDrvSpi6Config
{
	setSpi6ClockEn,		//void (*clockFunc)(bool en);
	setSpi6InterruptEn,	//void (*nvicFunc)(bool en);
	resetSpi6,			//void (*resetFunc)(void);
	getApb2ClkFreq,		//unsigned int (*getClockFreq)(void);
};

static const Dma::DmaInfo gSpi6TxDmaInfo = 
{
	(define::dma2::stream5::SPI6_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI6->DR,											//void *dataRegister;
};

static const Dma::DmaInfo gSpi6RxDmaInfo = 
{
	(define::dma2::stream6::SPI6_RX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
	(void*)&SPI6->DR,											//void *dataRegister;
};

static const Spi::Config gSpi6Config
{
	SPI6,			//YSS_SPI_Peri *peri;
	dmaChannel14,	//Dma &txDma;
	gSpi6TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel15,	//Dma &rxDma;
	gSpi6RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};

Spi spi6(gDrvSpi6Config, gSpi6Config);

extern "C"
{
void SPI6_IRQHandler(void)
{
	spi6.isr();
}
}
#endif

#endif


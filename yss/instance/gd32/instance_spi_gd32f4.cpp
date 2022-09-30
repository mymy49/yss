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
#include <yss.h>

#if defined(GD32F4)

#define PERIEN_POS		25
#define MBURST_Pos		23
#define PBURST_Pos		21
#define PRIO_POS		16
#define MWIDTH_POS		13
#define PWIDTH_POS		11
#define DIR_POS			6

#if defined(SPI0_ENABLE) && defined(SPI0)
static void enableSpi0Clock(bool en)
{
	clock.lock();
	clock.enableApb2Clock(12, en);
	clock.unlock();
}

static void enableSpi0Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI0_IRQn, en);
	nvic.unlock();
}

static void resetSpi0(void)
{
	clock.lock();
	clock.resetApb2(12);
	clock.unlock();
}

static const Drv::Config gDrvSpi0Config
{
	enableSpi0Clock,		// void (*clockFunc)(bool en);
	enableSpi0Interrupt,	// void (*nvicFunc)(bool en);
	resetSpi0,				// void (*resetFunc)(void);
	getApb2ClockFrequency	// uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gSpi0TxDmaInfo = 
{
	(define::dma2::stream3::SPI0_TX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI0->DTR									//void *dataRegister;
};

static const Dma::DmaInfo gSpi0RxDmaInfo = 
{
	(define::dma2::stream0::SPI0_RX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI0->DTR									//void *dataRegister;
};

static const Spi::Config gSpi0Config
{
	(YSS_SPI_Peri*)SPI0,	//YSS_SPI_Peri *peri;
	dmaChannel12,			//Dma &txDma;
	gSpi0TxDmaInfo,			//Dma::DmaInfo txDmaInfo;
	dmaChannel9,			//Dma &rxDma;
	gSpi0RxDmaInfo			//Dma::DmaInfo rxDmaInfo;
};

Spi spi0(gDrvSpi0Config, gSpi0Config);

extern "C"
{
	void SPI0_IRQHandler(void)
	{
		spi0.isr();
	}
}
#endif



#if defined(SPI1_ENABLE) && defined(SPI1)
#if defined(I2S1_ENABLE)
#error "SPI1, I2S1은 동시에 활성화 될 수 없습니다."
#endif
static void enableSpi1Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(14, en);
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
	clock.resetApb1(14);
	clock.unlock();
}

static const Drv::Config gDrvSpi1Config
{
	enableSpi1Clock,		// void (*clockFunc)(bool en);
	enableSpi1Interrupt,	// void (*nvicFunc)(bool en);
	resetSpi1,				// void (*resetFunc)(void);
	getApb1ClockFrequency	// uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gSpi1TxDmaInfo = 
{
	(define::dma1::stream4::SPI1_TX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI1->DTR									//void *dataRegister;
};

static const Dma::DmaInfo gSpi1RxDmaInfo = 
{
	(define::dma1::stream3::SPI1_RX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI1->DTR									//void *dataRegister;
};

static const Spi::Config gSpi1Config
{
	(YSS_SPI_Peri*)SPI1,	//YSS_SPI_Peri *peri;
	dmaChannel5,			//Dma &txDma;
	gSpi1TxDmaInfo,			//Dma::DmaInfo txDmaInfo;
	dmaChannel4,			//Dma &rxDma;
	gSpi1RxDmaInfo			//Dma::DmaInfo rxDmaInfo;
};

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
#if defined(I2S2_ENABLE)
#error "SPI2, I2S2는 동시에 활성화 될 수 없습니다."
#endif
static void enableSpi2Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(15, en);
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
	clock.resetApb1(15);
	clock.unlock();
}

static const Drv::Config gDrvSpi2Config
{
	enableSpi2Clock,		// void (*clockFunc)(bool en);
	enableSpi2Interrupt,	// void (*nvicFunc)(bool en);
	resetSpi2,				// void (*resetFunc)(void);
	getApb1ClockFrequency	// uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gSpi2TxDmaInfo = 
{
	(define::dma1::stream5::SPI2_TX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI2->DTR									//void *dataRegister;
};

static const Dma::DmaInfo gSpi2RxDmaInfo = 
{
	(define::dma1::stream0::SPI2_RX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI2->DTR									//void *dataRegister;
};

static const Spi::Config gSpi2Config
{
	(YSS_SPI_Peri*)SPI2,	//YSS_SPI_Peri *peri;
	dmaChannel6,			//Dma &txDma;
	gSpi2TxDmaInfo,			//Dma::DmaInfo txDmaInfo;
	dmaChannel1,			//Dma &rxDma;
	gSpi2RxDmaInfo			//Dma::DmaInfo rxDmaInfo;
};

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
static void enableSpi3Clock(bool en)
{
	clock.lock();
	clock.enableApb2Clock(13, en);
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
	clock.resetApb2(13);
	clock.unlock();
}

static const Drv::Config gDrvSpi3Config
{
	enableSpi3Clock,		// void (*clockFunc)(bool en);
	enableSpi3Interrupt,	// void (*nvicFunc)(bool en);
	resetSpi3,				// void (*resetFunc)(void);
	getApb2ClockFrequency	// uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gSpi3TxDmaInfo = 
{
	(define::dma2::stream1::SPI3_TX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI3->DTR									//void *dataRegister;
};

static const Dma::DmaInfo gSpi3RxDmaInfo = 
{
	(define::dma2::stream0::SPI3_RX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI3->DTR									//void *dataRegister;
};

static const Spi::Config gSpi3Config
{
	(YSS_SPI_Peri*)SPI3,	//YSS_SPI_Peri *peri;
	dmaChannel10,			//Dma &txDma;
	gSpi3TxDmaInfo,			//Dma::DmaInfo txDmaInfo;
	dmaChannel9,			//Dma &rxDma;
	gSpi3RxDmaInfo			//Dma::DmaInfo rxDmaInfo;
};

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
static void enableSpi4Clock(bool en)
{
	clock.lock();
	clock.enableApb2Clock(20, en);
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
	clock.resetApb2(20);
	clock.unlock();
}

static const Drv::Config gDrvSpi4Config
{
	enableSpi4Clock,		// void (*clockFunc)(bool en);
	enableSpi4Interrupt,	// void (*nvicFunc)(bool en);
	resetSpi4,				// void (*resetFunc)(void);
	getApb2ClockFrequency	// uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gSpi4TxDmaInfo = 
{
	(define::dma2::stream4::SPI4_TX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI4->DTR									//void *dataRegister;
};

static const Dma::DmaInfo gSpi4RxDmaInfo = 
{
	(define::dma2::stream3::SPI4_RX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI4->DTR									// void *dataRegister;
};

static const Spi::Config gSpi4Config
{
	(YSS_SPI_Peri*)SPI4,	//YSS_SPI_Peri *peri;
	dmaChannel13,			//Dma &txDma;
	gSpi4TxDmaInfo,			//Dma::DmaInfo txDmaInfo;
	dmaChannel12,			//Dma &rxDma;
	gSpi4RxDmaInfo			//Dma::DmaInfo rxDmaInfo;
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
static void enableSpi5Clock(bool en)
{
	clock.lock();
	clock.enableApb2Clock(21, en);
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
	clock.resetApb2(21);
	clock.unlock();
}

static const Drv::Config gDrvSpi5Config
{
	enableSpi5Clock,		// void (*clockFunc)(bool en);
	enableSpi5Interrupt,	// void (*nvicFunc)(bool en);
	resetSpi5,				// void (*resetFunc)(void);
	getApb2ClockFrequency	// uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gSpi5TxDmaInfo = 
{
	(define::dma2::stream5::SPI5_TX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI5->DTR									//void *dataRegister;
};

static const Dma::DmaInfo gSpi5RxDmaInfo = 
{
	(define::dma2::stream6::SPI5_RX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CHXCTL_MNAGA | 
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI5->DTR									//void *dataRegister;
};

static const Spi::Config gSpi5Config
{
	(YSS_SPI_Peri*)SPI5,	//YSS_SPI_Peri *peri;
	dmaChannel14,			//Dma &txDma;
	gSpi5TxDmaInfo,			//Dma::DmaInfo txDmaInfo;
	dmaChannel15,			//Dma &rxDma;
	gSpi5RxDmaInfo			//Dma::DmaInfo rxDmaInfo;
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

#endif


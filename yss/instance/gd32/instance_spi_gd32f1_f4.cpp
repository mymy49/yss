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

#if defined(GD32F1) || defined(GD32F450)

#define PRIORITY_POS	12
#define MWIDTH_POS		10
#define PWIDTH_POS		8
#define DIR_POS			4

static unsigned int getApb2ClkFreq(void)
{
	return clock.getApb2ClkFreq();
}

static unsigned int getApb1ClkFreq(void)
{
	return clock.getApb1ClkFreq();
}

#if defined(SPI1_ENABLE) && defined(SPI1)
static void setSpi1ClockEn(bool en)
{
	clock.peripheral.setSpi1En(en);
}

static void resetSpi1(void)
{
	clock.peripheral.resetSpi1();
}

static const Drv::Config gDrvSpi1Config
{
	setSpi1ClockEn,		//void (*clockFunc)(bool en);
	0			,		//void (*nvicFunc)(bool en);
	resetSpi1			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gSpi1TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << PRIORITY_POS) | // unsigned int controlRegister1
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CTLR_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CTLR_TCIE | 
	DMA_CTLR_ERRIE | 
	DMA_CTLR_CHEN ,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI1->DTR,									//void *dataRegister;
};

static const drv::Dma::DmaInfo gSpi1RxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << PRIORITY_POS) | // unsigned int controlRegister1
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CTLR_MNAGA | 
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CTLR_TCIE | 
	DMA_CTLR_ERRIE | 
	DMA_CTLR_CHEN ,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI1->DTR,									//void *dataRegister;
};

static const drv::Spi::Config gSpi1Config
{
	SPI1,			//YSS_SPI_Peri *peri;
	dmaChannel3,	//Dma &txDma;
	gSpi1TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel2,	//Dma &rxDma;
	gSpi1RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
	getApb2ClkFreq,	//unsigned int (*getClockFreq)(void);
};

drv::Spi spi1(gDrvSpi1Config, gSpi1Config);
#endif

#if defined(SPI2_ENABLE) && defined(SPI2)
static void setSpi2ClockEn(bool en)
{
	clock.peripheral.setSpi2En(en);
}

static void resetSpi2(void)
{
	clock.peripheral.resetSpi2();
}

static const Drv::Config gDrvSpi2Config
{
	setSpi2ClockEn,		//void (*clockFunc)(bool en);
	0			,		//void (*nvicFunc)(bool en);
	resetSpi2			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gSpi2TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << PRIORITY_POS) | // unsigned int controlRegister1
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CTLR_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CTLR_TCIE | 
	DMA_CTLR_ERRIE | 
	DMA_CTLR_CHEN ,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI2->DTR,									//void *dataRegister;
};

static const drv::Dma::DmaInfo gSpi2RxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << PRIORITY_POS) | // unsigned int controlRegister1
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CTLR_MNAGA | 
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CTLR_TCIE | 
	DMA_CTLR_ERRIE | 
	DMA_CTLR_CHEN ,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI2->DTR,									//void *dataRegister;
};

static const drv::Spi::Config gSpi2Config
{
	SPI2,			//YSS_SPI_Peri *peri;
	dmaChannel5,	//Dma &txDma;
	gSpi2TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel4,	//Dma &rxDma;
	gSpi2RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
	getApb1ClkFreq,	//unsigned int (*getClockFreq)(void);
};

drv::Spi spi2(gDrvSpi2Config, gSpi2Config);
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

static const Drv::Config gDrvSpi3Config
{
	setSpi3ClockEn,		//void (*clockFunc)(bool en);
	0			,		//void (*nvicFunc)(bool en);
	resetSpi3			//void (*resetFunc)(void);
};

static const drv::Dma::DmaInfo gSpi3TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << PRIORITY_POS) | // unsigned int controlRegister1
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CTLR_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CTLR_TCIE | 
	DMA_CTLR_ERRIE | 
	DMA_CTLR_CHEN ,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI3->DTR,									//void *dataRegister;
};

static const drv::Dma::DmaInfo gSpi3RxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << PRIORITY_POS) | // unsigned int controlRegister1
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CTLR_MNAGA | 
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CTLR_TCIE | 
	DMA_CTLR_ERRIE | 
	DMA_CTLR_CHEN ,
	0,													// unsigned int controlRegister2
	0,													// unsigned int controlRegister3
	(void*)&SPI3->DTR,									//void *dataRegister;
};

static const drv::Spi::Config gSpi3Config
{
	SPI3,			//YSS_SPI_Peri *peri;
	dmaChannel9,	//Dma &txDma;
	gSpi3TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel8,	//Dma &rxDma;
	gSpi3RxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
	getApb1ClkFreq,	//unsigned int (*getClockFreq)(void);
};

drv::Spi spi3(gDrvSpi3Config, gSpi3Config);
#endif

#endif


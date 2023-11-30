////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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
    clock.enableApb2Clock(RCC_AHB3ENR_QSPIEN_Pos, en);
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

static const Drv::Setup gDrvQuadspiSetup = 
{
	enableQuadspiClock,		//void (*clockFunc)(bool en);
	enableQuadspiInterrupt,	//void (*nvicFunc)(bool en);
	resetQuadspi,			//void (*resetFunc)(void);
	getAhbClockFrequency,	//uint32_t (*getClockFreq)(void);
};

static const Dma::DmaInfo gQuadspiTxDmaInfo = 
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
	DMA_SxCR_EN_Msk,
	0,															// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&QUADSPI->DR,										// void *dataRegister;
};

static const Dma::DmaInfo gQuadspiRxDmaInfo = 
{
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
	(void*)&QUADSPI->DR,										//void *dataRegister;
};

static const Quadspi::Setup gQuadSetup = 
{
	QUADSPI,			//YSS_QUADSPI_Peri *peri;
	dmaChannel16,		//Dma &txDma;
	gQuadspiTxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel16,		//Dma &rxDma;
	gQuadspiRxDmaInfo,	//Dma::DmaInfo rxDmaInfo;
};

Quadspi quadspi(gDrvQuadspiSetup, gQuadSetup);

#endif

#endif


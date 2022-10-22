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

#if defined(GD32F1) || defined(GD32F4) || defined(STM32F1)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <cmsis/mcu/common/dma_stm32_gd32f1.h>
#include <cmsis/mcu/common/rcc_stm32_gd32f1.h>
#include <cmsis/mcu/common/sdmmc_stm32_gd32f1.h>

#if defined(GD32F1)
#elif defined(GD32F4)
#define PERIEN_POS		25
#define MBURST_Pos		23
#define PBURST_Pos		21
#define PRIO_POS		16
#define MWIDTH_POS		13
#define PWIDTH_POS		11
#define DIR_POS			6
#endif

#if defined(SDMMC_ENABLE) && defined(SDIO)
static void setClockEn(bool en)
{
	clock.lock();
#if defined(GD32F4)
	if(en)
		RCU_APB2EN |= RCU_APB2EN_SDIOEN;
	else
		RCU_APB2EN &= ~RCU_APB2EN_SDIOEN;
#elif defined(GD32F1) || defined(STM32F1)
	clock.enableAhb1Clock(RCC_AHBENR_SDIOEN_Pos, en);
#endif
	clock.unlock();
}

static void reset(void)
{
	clock.lock();
#if defined(GD32F4)
	RCU_APB2RST |= RCU_APB2RST_SDIORST;
	RCU_APB2RST &= ~RCU_APB2RST_SDIORST;
#elif defined(GD32F1)
#endif
	clock.unlock();
}

static uint32_t getClockFrequency(void)
{
#if defined(GD32F1)
	return getApb2ClockFrequency();
#elif defined(GD32F4)
	return getAhbClockFrequency() / 4;
#endif
}

static const Drv::Config gDrvConfig
{
	setClockEn,				//void (*clockFunc)(bool en);
	0,						//void (*nvicFunc)(bool en);
	reset,					//void (*resetFunc)(void);
	getClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(GD32F1)
static const Dma::DmaInfo gRxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::WORD << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::WORD << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0,													// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SDIO[SDMMC_REG::FIFO],									//void *dataRegister;
};

static const Dma::DmaInfo gTxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::WORD << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::WORD << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0,													// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SDIO[SDMMC_REG::FIFO],						//void *dataRegister;
};

static const Sdmmc::Config gConfig
{
	(volatile uint32_t*)SDIO,	//YSS_SDMMC_Peri *peri;
	dmaChannel11,	//Dma &txDma;
	gTxDmaInfo,		//Dma::DmaInfo txDmaInfo;
	dmaChannel11,	//Dma &rxDma;
	gRxDmaInfo		//Dma::DmaInfo rxDmaInfo;
};
#elif defined(GD32F4)
static const Dma::DmaInfo gRxDmaInfo = 
{
	(define::dma2::stream3::SDIO_DMA << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::INCR4 << MBURST_Pos) | 
	(define::dma::burst::INCR4 << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::WORD << MWIDTH_POS) |
	(define::dma::size::WORD << PWIDTH_POS) |
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CHXCTL_MNAGA | 
	DMA_CHXCTL_TFCS |
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN |									// uint32_t controlRegister2
	DMA_CHXFCTL_FCCV,
	0,													// uint32_t controlRegister3
	(void*)&SDIO->FIFO,									//void *dataRegister;
};

static const Dma::DmaInfo gTxDmaInfo = 
{
	(define::dma2::stream3::SDIO_DMA << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::INCR4 << MBURST_Pos) | 
	(define::dma::burst::INCR4 << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::WORD << MWIDTH_POS) |
	(define::dma::size::WORD << PWIDTH_POS) |
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CHXCTL_MNAGA | 
	DMA_CHXCTL_TFCS |
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN |									// uint32_t controlRegister2
	DMA_CHXFCTL_FCCV,
	0,													// uint32_t controlRegister3
	(void*)&SDIO->FIFO,									//void *dataRegister;
};

static const Sdmmc::Config gConfig
{
	(volatile uint32_t*)SDIO,	//YSS_SDMMC_Peri *peri;
	dmaChannel12,	//Dma &txDma;
	gTxDmaInfo,		//Dma::DmaInfo txDmaInfo;
	dmaChannel12,	//Dma &rxDma;
	gRxDmaInfo		//Dma::DmaInfo rxDmaInfo;
};
#endif

Sdmmc sdmmc(gDrvConfig, gConfig);
#endif

#endif

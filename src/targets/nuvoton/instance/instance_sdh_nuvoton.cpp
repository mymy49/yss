////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonSdh.h>
#include <config.h>
#include <yss.h>
#include <yss/reg.h>

/*---------------------------------------------------------------------------------------------------------*/
/*  Transfer Direction Definitions                                                                         */
/**
 * @file instance_sdh_nuvoton.cpp
 * @brief Global driver instances initialization for Nuvoton SDH peripheral.
 */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_DIR_MEM_TO_PERI 0x00004000UL            /*!<DMA Single Request  \hideinitializer */
#define PDMA_DIR_PERI_TO_MEM 0x00000000UL            /*!<DMA Burst Request  \hideinitializer */

#if SDH0_ENABLE && defined(SDH0)
static void setSdh0ClockEn(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableApb0Clock().
	clock.enableAhb0Clock(CLK_AHBCLK0_SDH0CKEN_Pos, en);
}

static void enableSdh0Interrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(SDH0_IRQn, en);
}

static void resetSdh0(void)
{
}

static uint32_t getSdh0ClockFrequency(void)
{
	uint32_t src = (CLK->CLKSEL0 & CLK_CLKSEL0_SDH0SEL_Msk) >> CLK_CLKSEL0_SDH0SEL_Pos;

	switch(src)
	{
	case 0 : // HXT
		return clock.getHxtFrequency();
	
	case 1 : // PLL / 2
		return clock.getPllFrequency() / 2;

	case 2 : // HCLK
		return clock.getHclkClockFrequency();

	case 3 : // HIRC
		return clock.getHircFrequency();
	
	default :
		return 0;
	}
}

static void setSdh0ClockFrequency(uint32_t freq)
{
	uint32_t clk = getSdh0ClockFrequency();
	uint32_t div;

	div = clk / freq - 1;
	setFieldData(CLK->CLKDIV0, CLK_CLKDIV0_SDH0DIV_Msk, div, CLK_CLKDIV0_SDH0DIV_Pos);
}

static const Drv::setup_t gDrvSdh0Setup
{
	setSdh0ClockEn,			//void (*clockFunc)(bool en);
	enableSdh0Interrupt,	//void (*nvicFunc)(bool en);
	resetSdh0,				//void (*resetFunc)(void);
	getSdh0ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const NuvotonSdh::setup_t gSdh0Setup = 
{
	SDH0,					// SDH_T *peri;
	setSdh0ClockFrequency	// void (*setSdhClockFrequency)(uint32_t freq);
};

NuvotonSdh sdh0(gDrvSdh0Setup, gSdh0Setup);

#endif

#endif

#if defined(STM32F7) || defined(STM32F4)

#if SDMMC_ENABLE && (defined(SDMMC1) || defined(SDIO))
static void setClockEn(bool en)
{
	clock.lock();
#if defined(STM32F7)
	clock.enableApb2Clock(RCC_APB2ENR_SDMMC1EN_Pos, en);
#elif defined(STM32F4)
	clock.enableApb2Clock(RCC_APB2ENR_SDIOEN_Pos, en);
#endif
	clock.unlock();
}

static void reset(void)
{
	clock.lock();
#if defined(STM32F7)
	clock.resetApb2(RCC_APB2RSTR_SDMMC1RST_Pos);
#elif defined(STM32F4)
	clock.resetApb2(RCC_APB2RSTR_SDIORST_Pos);
#endif
	clock.unlock();
}

static uint32_t getClockFrequency(void)
{
#if defined(STM32F7)
	return clock.getSdmmcClockFrequency();
#elif defined(GD32F4)
	return getAhbClockFrequency() / 4;
#elif defined(STM32F4)
	return clock.getSdmmcClockFrequency();
#else
	return 0;
#endif
}

static const Drv::setup_t gDrvConfig
{
	setClockEn,				//void (*clockFunc)(bool en);
	0,						//void (*nvicFunc)(bool en);
	reset,					//void (*resetFunc)(void);
	getClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(GD32F1)
static const Dma::dmaInfo_t gRxDmaInfo = 
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

static const Dma::dmaInfo_t gTxDmaInfo = 
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
	gTxDmaInfo,		//Dma::dmaInfo_t txDmaInfo;
	dmaChannel11,	//Dma &rxDma;
	gRxDmaInfo		//Dma::dmaInfo_t rxDmaInfo;
};
#elif defined(STM32F7) || defined(STM32F4)
static const Dma::dmaInfo_t gRxDmaInfo = 
{
#if SDMMC_DMA_TRX == DMA2_CH3
	(define::dma2::stream3::SDIO_DMA << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
#elif SDMMC_DMA_TRX == DMA2_CH6
	(define::dma2::stream6::SDIO_DMA << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
#endif
	(define::dma::burst::INCR4 << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::INCR4 << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::WORD << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::WORD << DMA_SxCR_PSIZE_Pos) |
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_MINC_Msk | 
	DMA_SxCR_PFCTRL_Msk |
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk ,
	DMA_SxFCR_DMDIS_Msk |			// uint32_t controlRegister2
	DMA_SxFCR_FTH_Msk,
	0,								// uint32_t controlRegister3
#if defined(STM32F4)
	(void*)&SDIO->FIFO				//void *dataRegister;
#else
	(void*)&SDMMC1->FIFO			//void *dataRegister;
#endif
};

static const Dma::dmaInfo_t gTxDmaInfo = 
{
	(define::dma2::stream3::SDIO_DMA << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::INCR4 << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::INCR4 << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::WORD << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::WORD << DMA_SxCR_PSIZE_Pos) |
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_MINC_Msk | 
	DMA_SxCR_PFCTRL_Msk |
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk ,
	DMA_SxFCR_DMDIS_Msk |			// uint32_t controlRegister2
	DMA_SxFCR_FTH_Msk,
	0,								// uint32_t controlRegister3
#if defined(STM32F4)
	(void*)&SDIO->FIFO				//void *dataRegister;
#else
	(void*)&SDMMC1->FIFO			//void *dataRegister;
#endif
};

static const Sdmmc::Config gConfig
{
#if defined(STM32F4)
	SDIO,			//YSS_SDMMC_Peri *peri;
#else
	SDMMC1,			//YSS_SDMMC_Peri *peri;
#endif
	dmaChannel12,	//Dma &txDma;
	gTxDmaInfo,		//Dma::dmaInfo_t txDmaInfo;
	dmaChannel12,	//Dma &rxDma;
	gRxDmaInfo		//Dma::dmaInfo_t rxDmaInfo;
};
#endif

Sdmmc sdmmc(gDrvConfig, gConfig);
#endif

#endif

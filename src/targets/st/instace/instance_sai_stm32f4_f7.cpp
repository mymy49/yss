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

static const Drv::Setup_t gDrvSai1Config
{
	enableSai1Clock,		// void (*clockFunc)(bool en);
	enableSai1Interrupt,	// void (*nvicFunc)(bool en);
	resetSai1,				// void (*resetFunc)(void);
	getSai1ClockFrequency		// uint32_t (*getClockFunc)(void);
};

static Dma::DmaInfo gSai1ATxDmaInfo = 
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

static Dma::DmaInfo gSai1ARxDmaInfo = 
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
	gSai1ATxDmaInfo,					//Dma::DmaInfo txDmaInfo;
	dmaChannel10,						//Dma &txDma;
	gSai1ARxDmaInfo						//Dma::DmaInfo txDmaInfo;
};

Sai sai1A(gDrvSai1Config, gSai1AConfig);

static const Dma::DmaInfo gSai1BTxDmaInfo = 
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

static const Dma::DmaInfo gSai1BRxDmaInfo = 
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
	gSai1BTxDmaInfo,					//Dma::DmaInfo txDmaInfo;
	dmaChannel14,						//Dma &txDma;
	gSai1BRxDmaInfo						//Dma::DmaInfo txDmaInfo;
};

Sai sai1B(gDrvSai1Config, gSai1BConfig);
#endif

#endif


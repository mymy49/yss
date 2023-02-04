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
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(GD32F4) || defined(STM32F7)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#include <targets/st_gigadevice/rcc_stm32_gd32f4_f7.h>
#include <targets/st_gigadevice/spi_stm32_gd32f0_f1_f4.h>
#include <targets/st_gigadevice/dma_stm32_gd32f4_f7.h>

#define PERIEN_POS		25
#define MBURST_Pos		23
#define PBURST_Pos		21
#define PRIO_POS		16
#define MWIDTH_POS		13
#define PWIDTH_POS		11
#define DIR_POS			6

static uint32_t getClockFrequency(void)
{
	return clock.getI2sClockFrequency();
}

#if defined(I2S2_ENABLE) && defined(I2S2)
#if defined(SPI2_ENABLE)
#error "SPI2, I2S2은 동시에 활성화 될 수 없습니다."
#endif
static void enableI2s2Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(RCC_APB1ENR_SPI2EN_Pos, en);
	clock.unlock();
}

static void enableI2s2Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI2_IRQn, en);
	nvic.unlock();
}

static void resetI2s2(void)
{
	clock.lock();
	clock.resetApb1(RCC_APB1RSTR_SPI2RST_Pos);
	clock.unlock();
}

static const Drv::Config gDrvI2s2Config
{
	enableI2s2Clock,		// void (*clockFunc)(bool en);
	enableI2s2Interrupt,	// void (*nvicFunc)(bool en);
	resetI2s2,				// void (*resetFunc)(void);
	getClockFrequency	// uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gI2s2TxDmaInfo = 
{
	(define::dma1::stream4::SPI2_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,			// uint32_t controlRegister2
	0,								// uint32_t controlRegister3
	(void*)&I2S2[SPI_REG::DR]		//void *dataRegister;
};

static const Dma::DmaInfo gI2s2RxDmaInfo = 
{
	(define::dma1::stream3::SPI2_RX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
	DMA_SxFCR_DMDIS_Msk,			// uint32_t controlRegister2
	0,								// uint32_t controlRegister3
	(void*)&I2S2[SPI_REG::DR]		//void *dataRegister;
};

static const I2s::Config gI2s2Config
{
	(YSS_I2S_Peri*)I2S2,	//YSS_SPI_Peri *peri;
	dmaChannel5,			//Dma &txDma;
	gI2s2TxDmaInfo,			//Dma::DmaInfo txDmaInfo;
	dmaChannel4,			//Dma &rxDma;
	gI2s2RxDmaInfo			//Dma::DmaInfo rxDmaInfo;
};

I2s i2s2(gDrvI2s2Config, gI2s2Config);

extern "C"
{
	void SPI2_IRQHandler(void)
	{
		i2s2.isr();
	}
}
#endif

#endif


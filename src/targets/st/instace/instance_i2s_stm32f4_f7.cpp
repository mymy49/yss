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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(STM32F4) || defined(STM32F7)

#include <config.h>
#include <yss.h>
#include <targets/st/bitfield.h>

#if I2S2_ENABLE && defined(I2S2)
#if SPI2_ENABLE
#error "SPI2, I2S2은 동시에 활성화 될 수 없습니다."
#endif
static uint32_t getI2s2ClockFrequency(void)
{
	return clock.getI2s2ClockFrequency();
}

static void enableI2s2Clock(bool en)
{
	clock.lock();
#if defined(STM32F446xx)
	clock.enableApb1Clock(RCC_APB1ENR_SPI2EN_Pos, en);
#endif
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

static const Drv::setup_t gDrvI2s2Config
{
	enableI2s2Clock,		// void (*clockFunc)(bool en);
	enableI2s2Interrupt,	// void (*nvicFunc)(bool en);
	resetI2s2,				// void (*resetFunc)(void);
	getI2s2ClockFrequency	// uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gI2s2TxDmaInfo = 
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
	(void*)&I2S2->DR				//void *dataRegister;
};

static const Dma::dmaInfo_t gI2s2RxDmaInfo = 
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
	(void*)&I2S2->DR				//void *dataRegister;
};

static const I2s::Config gI2s2Config
{
	(YSS_I2S_Peri*)I2S2,	//YSS_SPI_Peri *peri;
	dmaChannel5,			//Dma &txDma;
	gI2s2TxDmaInfo,			//Dma::dmaInfo_t txDmaInfo;
	dmaChannel4,			//Dma &rxDma;
	gI2s2RxDmaInfo			//Dma::dmaInfo_t rxDmaInfo;
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


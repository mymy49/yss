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


#if defined(I2S1_ENABLE) && defined(I2S1)
#if defined(SPI1_ENABLE)
#error "SPI1, I2S1은 동시에 활성화 될 수 없습니다."
#endif
static void enableI2s1Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(14, en);
	clock.unlock();
}

static void enableI2s1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(SPI1_IRQn, en);
	nvic.unlock();
}

static void resetI2s1(void)
{
	clock.lock();
	clock.resetApb1(14);
	clock.unlock();
}

static uint32_t getClockFrequency(void)
{
	return clock.getI2sClockFrequency();
}

static const Drv::Config gDrvI2s1Config
{
	enableI2s1Clock,		// void (*clockFunc)(bool en);
	enableI2s1Interrupt,	// void (*nvicFunc)(bool en);
	resetI2s1,				// void (*resetFunc)(void);
	getClockFrequency	// uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gSpi1TxDmaInfo = 
{
	(define::dma1::stream4::SPI1_TX << PERIEN_POS) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << MBURST_Pos) | 
	(define::dma::burst::SINGLE << PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << PRIO_POS) |
	(define::dma::size::HALF_WORD << MWIDTH_POS) |
	(define::dma::size::HALF_WORD << PWIDTH_POS) |
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CHXCTL_MNAGA | 
//	DMA_CHXCTL_TFCS |
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_HTFIE |
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CMEN | 
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
	(define::dma::dir::PERI_TO_MEM << DIR_POS) | 
	DMA_CHXCTL_MNAGA | 
	DMA_CHXCTL_FTFIE | 
	DMA_CHXCTL_TAEIE | 
	DMA_CHXCTL_CHEN ,
	DMA_CHXFCTL_MDMEN,									// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&SPI1->DTR									//void *dataRegister;
};

static const I2s::Config gI2s1Config
{
	(YSS_I2S_Peri*)SPI1,	//YSS_SPI_Peri *peri;
	dmaChannel5,			//Dma &txDma;
	gSpi1TxDmaInfo,			//Dma::DmaInfo txDmaInfo;
	dmaChannel4,			//Dma &rxDma;
	gSpi1RxDmaInfo			//Dma::DmaInfo rxDmaInfo;
};

I2s i2s1(gDrvI2s1Config, gI2s1Config);

extern "C"
{
	void SPI1_IRQHandler(void)
	{
		i2s1.isr();
	}
}
#endif

#endif


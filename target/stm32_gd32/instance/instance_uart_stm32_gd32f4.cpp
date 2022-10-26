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

#if defined(GD32F4) || defined(STM32F4)

#include <yss/instance.h>
#include <yss.h>
#include <config.h>
#include <yss/reg.h>
#include <cmsis/mcu/st_gigadevice/dma_stm32_gd32f4.h>
#include <cmsis/mcu/st_gigadevice/rcc_stm32_gd32f4.h>
#include <cmsis/mcu/st_gigadevice/uart_stm32_gd32f1_f4.h>

#define PERIEN_POS		25
#define MBURST_Pos		23
#define PBURST_Pos		21
#define PRIO_POS		16
#define MWIDTH_POS		13
#define PWIDTH_POS		11
#define DIR_POS			6

#if defined(USART1) && defined(UART1_ENABLE)
static void enableUart1Clock(bool en)
{
	clock.lock();
	clock.enableApb2Clock(RCC_APB2ENR_USART1EN_Pos, en);
	clock.unlock();
}

static void enableUart1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(USART1_IRQn, en);
	nvic.unlock();
}

static void resetUart1(void)
{
	clock.lock();
	clock.resetApb2(RCC_APB2RSTR_USART1RST_Pos);
	clock.unlock();
}

static const Drv::Config gDrvUart1Config
{
	enableUart1Clock,		//void (*clockFunc)(bool en);
	enableUart1Interrupt,	//void (*nvicFunc)(bool en);
	resetUart1,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart1TxDmaInfo = 
{
	(define::dma2::stream7::USART1_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk ,
	DMA_SxFCR_DMDIS_Msk,			// uint32_t controlRegister2
	0,								// uint32_t controlRegister3
	(void*)&USART1[UART_REG::DR],	//void *dataRegister;
};

static const Uart::Config gUart1Config
{
	(YSS_USART_Peri*)USART1,	//YSS_USART_Peri *peri;
	dmaChannel16,				//Dma &txDma;
	gUart1TxDmaInfo,			//Dma::DmaInfo txDmaInfo;
};

Uart uart1(gDrvUart1Config, gUart1Config);

extern "C"
{
	void USART1_IRQHandler(void)
	{
		uart1.isr();
	}
}
#endif



#if defined(USART2) && defined(UART2_ENABLE)
static void enableUart2Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(RCC_APB1ENR_USART2EN_Pos, en);
	clock.unlock();
}

static void enableUart2Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(USART2_IRQn, en);
	nvic.unlock();
}

static void resetUart2(void)
{
	clock.lock();
	clock.resetApb1(RCC_APB1RSTR_USART2RST_Pos);
	clock.unlock();
}

static const Drv::Config gDrvUart2Config
{
	enableUart2Clock,		//void (*clockFunc)(bool en);
	enableUart2Interrupt,	//void (*nvicFunc)(bool en);
	resetUart2,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart2TxDmaInfo = 
{
	(define::dma1::stream6::USART2_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk ,
	DMA_SxFCR_DMDIS_Msk,			// uint32_t controlRegister2
	0,								// uint32_t controlRegister3
	(void*)&USART2[UART_REG::DR],	//void *dataRegister;
};

static const Uart::Config gUart2Config
{
	(YSS_USART_Peri*)USART2,	//YSS_USART_Peri *peri;
	dmaChannel7,				//Dma &txDma;
	gUart2TxDmaInfo				//Dma::DmaInfo txDmaInfo;
};

Uart uart2(gDrvUart2Config, gUart2Config);

extern "C"
{
	void USART2_IRQHandler(void)
	{
		uart2.isr();
	}
}
#endif

#if defined(USART3) && defined(UART3_ENABLE)
static void setUart2ClockEn(bool en)
{
	clock.lock();
	clock.enableApb1Clock(18, en);
	clock.unlock();
}

static void setUart2IntEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(USART2_IRQn, en);
	nvic.unlock();
}

static void resetUart2(void)
{
	clock.peripheral.resetUart2();
}

static const Drv::Config gDrvUart2Config
{
	setUart2ClockEn,	//void (*clockFunc)(bool en);
	setUart2IntEn,		//void (*nvicFunc)(bool en);
	resetUart2,			//void (*resetFunc)(void);
	getApb1ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart2TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << PRIORITY_POS) | // uint32_t controlRegister1
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CTLR_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CTLR_TCIE | 
	DMA_CTLR_ERRIE | 
	DMA_CTLR_CHEN ,
	0,													// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&USART2->DR,									//void *dataRegister;
};

static const Uart::Config gUart2Config
{
	USART2,			//YSS_SPI_Peri *peri;
	dmaChannel7,	//Dma &txDma;
	gUart2TxDmaInfo,//Dma::DmaInfo txDmaInfo;
	getApb1ClkFreq,	//uint32_t (*getClockFreq)(void);
};

Uart uart2(gDrvUart2Config, gUart2Config);

extern "C"
{
	void USART2_IRQHandler(void)
	{
		uart2.isr();
	}
}

#endif

#if defined(USART4) && defined(UART4_ENABLE)
static void setUart3ClockEn(bool en)
{
	clock.lock();
	clock.enableApb1Clock(19, en);
	clock.unlock();
}

static void setUart3IntEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(UART3_IRQn, en);
	nvic.unlock();
}

static void resetUart3(void)
{
	clock.peripheral.resetUart3();
}

static const Drv::Config gDrvUart3Config
{
	setUart3ClockEn,	//void (*clockFunc)(bool en);
	setUart3IntEn,		//void (*nvicFunc)(bool en);
	resetUart3,			//void (*resetFunc)(void);
	getApb1ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart3TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << PRIORITY_POS) | // uint32_t controlRegister1
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CTLR_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CTLR_TCIE | 
	DMA_CTLR_ERRIE | 
	DMA_CTLR_CHEN ,
	0,													// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&USART3->DR,									//void *dataRegister;
};

static const Uart::Config gUart3Config
{
	USART3,			//YSS_SPI_Peri *peri;
	dmaChannel2,	//Dma &txDma;
	gUart3TxDmaInfo,//Dma::DmaInfo txDmaInfo;
	getApb1ClkFreq,	//uint32_t (*getClockFreq)(void);
};

Uart uart3(gDrvUart3Config, gUart3Config);

extern "C"
{
	void USART3_IRQHandler(void)
	{
		uart3.isr();
	}
}

#endif

#if defined(UART5) && defined(UART5_ENABLE)
static void setUart4ClockEn(bool en)
{
	clock.lock();
	clock.enableApb1Clock(20, en);
	clock.unlock();
}

static void setUart4IntEn(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(USART4_IRQn, en);
	nvic.unlock();
}

static void resetUart4(void)
{
	clock.peripheral.resetUart4();
}

static const Drv::Config gDrvUart4Config
{
	setUart4ClockEn,	//void (*clockFunc)(bool en);
	setUart4IntEn,		//void (*nvicFunc)(bool en);
	resetUart4,			//void (*resetFunc)(void);
	getApb1ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart4TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << PRIORITY_POS) | // uint32_t controlRegister1
	(define::dma::size::BYTE << MWIDTH_POS) |
	(define::dma::size::BYTE << PWIDTH_POS) |
	DMA_CTLR_MNAGA | 
	(define::dma::dir::MEM_TO_PERI << DIR_POS) | 
	DMA_CTLR_TCIE | 
	DMA_CTLR_ERRIE | 
	DMA_CTLR_CHEN ,
	0,													// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&UART4->DR,									//void *dataRegister;
};

static const Uart::Config gUart4Config
{
	USART4,			//YSS_SPI_Peri *peri;
	dmaChannel12,	//Dma &txDma;
	gUart4TxDmaInfo,//Dma::DmaInfo txDmaInfo;
	getApb1ClkFreq,	//uint32_t (*getClockFreq)(void);
};

Uart uart4(gDrvUart4Config, gUart4Config);

extern "C"
{
	void UART4_IRQHandler(void)
	{
		uart4.isr();
	}
}
#endif

#endif


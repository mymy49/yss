/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <yss/instance.h>
#include <config.h>

#if defined(NRF_UART0) && defined(UART0_ENABLE)
static void enableInterruptUart0(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(UARTE0_UART0_IRQn, en);
	nvic.unlock();
}

static const Drv::setup_t gDrvUart0Config
{
	0,						//void (*clockFunc)(bool en);
	enableInterruptUart0,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	0						//uint32_t (*getClockFunc)(void);
};

static const Uart::Config gUart0Config
{
	NRF_UART0,			//YSS_SPI_Peri *peri;
};

Uart uart0(gDrvUart0Config, gUart0Config);

extern "C"
{
	void UARTE0_UART0_IRQHandler(void)
	{
		uart0.isr();
	}
}
#endif



#if defined(USART1) && defined(UART1_ENABLE)
static void setUart1ClockEn(bool en)
{
	clock.peripheral.setUart1En(en);
}

static void setUart1IntEn(bool en)
{
	nvic.setUart1En(en);
}

static void resetUart1(void)
{
	clock.peripheral.resetUart1();
}

static const Drv::setup_t gDrvUart1Config
{
	setUart1ClockEn,	//void (*clockFunc)(bool en);
	setUart1IntEn,		//void (*nvicFunc)(bool en);
	resetUart1,			//void (*resetFunc)(void);
	getApb2ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const drv::Dma::dmaInfo_t gUart1TxDmaInfo = 
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
	(void*)&USART1->DR,									//void *dataRegister;
};

static const drv::Uart::Config gUart1Config
{
	USART1,			//YSS_SPI_Peri *peri;
	dmaChannel4,	//Dma &txDma;
	gUart1TxDmaInfo,//Dma::dmaInfo_t txDmaInfo;
	getApb2ClkFreq,	//uint32_t (*getClockFreq)(void);
};

drv::Uart uart1(gDrvUart1Config, gUart1Config);

extern "C"
{
	void USART1_IRQHandler(void)
	{
		uart1.isr();
	}
}
#endif

#if defined(USART2) && defined(UART2_ENABLE)
static void setUart2ClockEn(bool en)
{
	clock.peripheral.setUart2En(en);
}

static void setUart2IntEn(bool en)
{
	nvic.setUart2En(en);
}

static void resetUart2(void)
{
	clock.peripheral.resetUart2();
}

static const Drv::setup_t gDrvUart2Config
{
	setUart2ClockEn,	//void (*clockFunc)(bool en);
	setUart2IntEn,		//void (*nvicFunc)(bool en);
	resetUart2,			//void (*resetFunc)(void);
	getApb1ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const drv::Dma::dmaInfo_t gUart2TxDmaInfo = 
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

static const drv::Uart::Config gUart2Config
{
	USART2,			//YSS_SPI_Peri *peri;
	dmaChannel7,	//Dma &txDma;
	gUart2TxDmaInfo,//Dma::dmaInfo_t txDmaInfo;
	getApb1ClkFreq,	//uint32_t (*getClockFreq)(void);
};

drv::Uart uart2(gDrvUart2Config, gUart2Config);

extern "C"
{
	void USART2_IRQHandler(void)
	{
		uart2.isr();
	}
}

#endif

#if defined(USART3) && defined(UART3_ENABLE)
static void setUart3ClockEn(bool en)
{
	clock.peripheral.setUart3En(en);
}

static void setUart3IntEn(bool en)
{
	nvic.setUart3En(en);
}

static void resetUart3(void)
{
	clock.peripheral.resetUart3();
}

static const Drv::setup_t gDrvUart3Config
{
	setUart3ClockEn,	//void (*clockFunc)(bool en);
	setUart3IntEn,		//void (*nvicFunc)(bool en);
	resetUart3,			//void (*resetFunc)(void);
	getApb1ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const drv::Dma::dmaInfo_t gUart3TxDmaInfo = 
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

static const drv::Uart::Config gUart3Config
{
	USART3,			//YSS_SPI_Peri *peri;
	dmaChannel2,	//Dma &txDma;
	gUart3TxDmaInfo,//Dma::dmaInfo_t txDmaInfo;
	getApb1ClkFreq,	//uint32_t (*getClockFreq)(void);
};

drv::Uart uart3(gDrvUart3Config, gUart3Config);

extern "C"
{
	void USART3_IRQHandler(void)
	{
		uart3.isr();
	}
}

#endif

#if defined(UART4) && defined(UART4_ENABLE)
static void setUart4ClockEn(bool en)
{
	clock.peripheral.setUart4En(en);
}

static void setUart4IntEn(bool en)
{
	nvic.setUart4En(en);
}

static void resetUart4(void)
{
	clock.peripheral.resetUart4();
}

static const Drv::setup_t gDrvUart4Config
{
	setUart4ClockEn,	//void (*clockFunc)(bool en);
	setUart4IntEn,		//void (*nvicFunc)(bool en);
	resetUart4,			//void (*resetFunc)(void);
	getApb1ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const drv::Dma::dmaInfo_t gUart4TxDmaInfo = 
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

static const drv::Uart::Config gUart4Config
{
	UART4,			//YSS_SPI_Peri *peri;
	dmaChannel12,	//Dma &txDma;
	gUart4TxDmaInfo,//Dma::dmaInfo_t txDmaInfo;
	getApb1ClkFreq,	//uint32_t (*getClockFreq)(void);
};

drv::Uart uart4(gDrvUart4Config, gUart4Config);

extern "C"
{
	void UART4_IRQHandler(void)
	{
		uart4.isr();
	}
}
#endif

#endif



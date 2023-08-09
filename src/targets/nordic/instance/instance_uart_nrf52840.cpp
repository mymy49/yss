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

static const Drv::Config gDrvUart0Config
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

static const Drv::Config gDrvUart1Config
{
	setUart1ClockEn,	//void (*clockFunc)(bool en);
	setUart1IntEn,		//void (*nvicFunc)(bool en);
	resetUart1,			//void (*resetFunc)(void);
	getApb2ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const drv::Dma::DmaInfo gUart1TxDmaInfo = 
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
	gUart1TxDmaInfo,//Dma::DmaInfo txDmaInfo;
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

static const Drv::Config gDrvUart2Config
{
	setUart2ClockEn,	//void (*clockFunc)(bool en);
	setUart2IntEn,		//void (*nvicFunc)(bool en);
	resetUart2,			//void (*resetFunc)(void);
	getApb1ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const drv::Dma::DmaInfo gUart2TxDmaInfo = 
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
	gUart2TxDmaInfo,//Dma::DmaInfo txDmaInfo;
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

static const Drv::Config gDrvUart3Config
{
	setUart3ClockEn,	//void (*clockFunc)(bool en);
	setUart3IntEn,		//void (*nvicFunc)(bool en);
	resetUart3,			//void (*resetFunc)(void);
	getApb1ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const drv::Dma::DmaInfo gUart3TxDmaInfo = 
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
	gUart3TxDmaInfo,//Dma::DmaInfo txDmaInfo;
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

static const Drv::Config gDrvUart4Config
{
	setUart4ClockEn,	//void (*clockFunc)(bool en);
	setUart4IntEn,		//void (*nvicFunc)(bool en);
	resetUart4,			//void (*resetFunc)(void);
	getApb1ClkFreq		//uint32_t (*getClockFunc)(void);
};

static const drv::Dma::DmaInfo gUart4TxDmaInfo = 
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
	gUart4TxDmaInfo,//Dma::DmaInfo txDmaInfo;
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



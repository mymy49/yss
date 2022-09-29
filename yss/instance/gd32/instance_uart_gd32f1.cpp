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

#if defined(GD32F1)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#define PRIORITY_POS	12
#define MWIDTH_POS		10
#define PWIDTH_POS		8
#define DIR_POS			4

#if defined(USART1) && defined(UART1_ENABLE)
static void setUart1ClockEn(bool en)
{
	clock.lock();
#if defined(GD32F1)
	setBitData(RCC->APB2CCR, en, 14);
#endif
	clock.unlock();
}

static void setUart1IntEn(bool en)
{
#if defined(GD32F1)
	if(en)
		NVIC_EnableIRQ(USART1_IRQn);
	else
		NVIC_DisableIRQ(USART1_IRQn);
#endif
}

static void resetUart1(void)
{
	clock.lock();
#if defined(GD32F1)
	setBitData(RCC->APB2RCR, true, 14);
	setBitData(RCC->APB2RCR, false, 14);
#endif
	clock.unlock();
}

static const Drv::Config gDrvUart1Config
{
	setUart1ClockEn,	//void (*clockFunc)(bool en);
	setUart1IntEn,		//void (*nvicFunc)(bool en);
	resetUart1,			//void (*resetFunc)(void);
	getApb2ClockFrequency		//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart1TxDmaInfo = 
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

static const Uart::Config gUart1Config
{
	(YSS_USART_Peri*)USART1,	//YSS_SPI_Peri *peri;
	dmaChannel4,				//Dma &txDma;
	gUart1TxDmaInfo				//Dma::DmaInfo txDmaInfo;
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
static void setUart2ClockEn(bool en)
{
	clock.lock();
#if defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 17);
#endif
	clock.unlock();
}

static void setUart2IntEn(bool en)
{
#if defined(GD32F1)
	if(en)
		NVIC_EnableIRQ(USART2_IRQn);
	else
		NVIC_DisableIRQ(USART2_IRQn);
#endif
}

static void resetUart2(void)
{
	clock.lock();
#if defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 17);
	setBitData(RCC->APB1RCR, false, 17);
#endif
	clock.unlock();
}

static const Drv::Config gDrvUart2Config
{
	setUart2ClockEn,	//void (*clockFunc)(bool en);
	setUart2IntEn,		//void (*nvicFunc)(bool en);
	resetUart2,			//void (*resetFunc)(void);
	getApb1ClockFrequency		//uint32_t (*getClockFunc)(void);
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
	(YSS_USART_Peri*)USART2,	//YSS_SPI_Peri *peri;
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
static void setUart3ClockEn(bool en)
{
	clock.lock();
#if defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 18);
#endif
	clock.unlock();
}

static void setUart3IntEn(bool en)
{
#if defined(GD32F1)
	if(en)
		NVIC_EnableIRQ(USART3_IRQn);
	else
		NVIC_DisableIRQ(USART3_IRQn);
#endif
}

static void resetUart3(void)
{
	clock.lock();
#if defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 18);
	setBitData(RCC->APB1RCR, false, 18);
#endif
	clock.unlock();
}

static const Drv::Config gDrvUart3Config
{
	setUart3ClockEn,	//void (*clockFunc)(bool en);
	setUart3IntEn,		//void (*nvicFunc)(bool en);
	resetUart3,			//void (*resetFunc)(void);
	getApb1ClockFrequency		//uint32_t (*getClockFunc)(void);
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
	(YSS_USART_Peri*)USART3,	//YSS_SPI_Peri *peri;
	dmaChannel2,				//Dma &txDma;
	gUart3TxDmaInfo				//Dma::DmaInfo txDmaInfo;
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

#if defined(UART4) && defined(UART4_ENABLE)
static void setUart4ClockEn(bool en)
{
	clock.lock();
#if defined(GD32F1)
	setBitData(RCC->APB1CCR, en, 19);
#endif
	clock.unlock();
}

static void setUart4IntEn(bool en)
{
#if defined(GD32F1)
	if(en)
		NVIC_EnableIRQ(UART4_IRQn);
	else
		NVIC_DisableIRQ(UART4_IRQn);
#endif
}

static void resetUart4(void)
{
	clock.lock();
#if defined(GD32F1)
	setBitData(RCC->APB1RCR, true, 19);
	setBitData(RCC->APB1RCR, false, 19);
#endif
	clock.unlock();
}

static const Drv::Config gDrvUart4Config
{
	setUart4ClockEn,	//void (*clockFunc)(bool en);
	setUart4IntEn,		//void (*nvicFunc)(bool en);
	resetUart4,			//void (*resetFunc)(void);
	getApb1ClockFrequency		//uint32_t (*getClockFunc)(void);
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
	(YSS_USART_Peri*)UART4,	//YSS_SPI_Peri *peri;
	dmaChannel12,			//Dma &txDma;
	gUart4TxDmaInfo			//Dma::DmaInfo txDmaInfo;
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


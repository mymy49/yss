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

#if defined(STM32F1_N)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/st/bitfield_stm32f103xx.h>

#define YSS_USART1_IRQHandler		USART1_IRQHandler
#define YSS_USART2_IRQHandler		USART2_IRQHandler
#define YSS_USART3_IRQHandler		USART3_IRQHandler
#define YSS_UART4_IRQHandler		UART4_IRQHandler

static uint32_t getApb1ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}

static uint32_t getApb2ClockFrequency(void)
{
	return clock.getApb2ClockFrequency();
}

#if defined(USART1) && defined(UART1_ENABLE)
static void enableUart1Clock(bool en)
{
	clock.lock();
	clock.enableApb2Clock(14, en);
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
	clock.resetApb2(14);
	clock.unlock();
}

static const Drv::Setup gDrvUart1Setup = 
{
	enableUart1Clock,		//void (*clockFunc)(bool en);
	enableUart1Interrupt,	//void (*nvicFunc)(bool en);
	resetUart1,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart1TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk ,
	0,													// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&USART1->DR									//void *dataRegister;
};

static const Uart::Setup gUart1Setup = 
{
	(YSS_USART_Peri*)USART1,	//YSS_SPI_Peri *peri;
	dmaChannel4,				//Dma &txDma;
	gUart1TxDmaInfo				//Dma::DmaInfo txDmaInfo;
};

Usart usart1(gDrvUart1Setup, gUart1Setup);

extern "C"
{
	void YSS_USART1_IRQHandler(void)
	{
		usart1.isr();
	}
}
#endif

#if defined(USART2) && defined(UART2_ENABLE)
static void enableUart2Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(17, en);
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
	clock.resetApb1(17);
	clock.unlock();
}

static const Drv::Setup gDrvUart2Setup = 
{
	enableUart2Clock,		//void (*clockFunc)(bool en);
	enableUart2Interrupt,	//void (*nvicFunc)(bool en);
	resetUart2,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart2TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk ,
	0,													// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&USART2->DR									//void *dataRegister;
};

static const Uart::Setup gUart2Setup = 
{
	(YSS_USART_Peri*)USART2,	//YSS_SPI_Peri *peri;
	dmaChannel7,				//Dma &txDma;
	gUart2TxDmaInfo				//Dma::DmaInfo txDmaInfo;
};

Usart usart2(gDrvUart2Setup, gUart2Setup);

extern "C"
{
	void YSS_USART2_IRQHandler(void)
	{
		usart2.isr();
	}
}

#endif

#if defined(USART3) && defined(UART3_ENABLE)
static void enableUart3Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(18, en);
	clock.unlock();
}

static void enableUart3Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(USART3_IRQn, en);
	nvic.unlock();
}

static void resetUart3(void)
{
	clock.lock();
	clock.resetApb1(18);
	clock.unlock();
}

static const Drv::Setup gDrvUart3Setup = 
{
	enableUart3Clock,		//void (*clockFunc)(bool en);
	enableUart3Interrupt,	//void (*nvicFunc)(bool en);
	resetUart3,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart3TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk ,
	0,													// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&USART3->DR,									//void *dataRegister;
};

static const Uart::Setup gUart3Setup = 
{
	(YSS_USART_Peri*)USART3,	//YSS_SPI_Peri *peri;
	dmaChannel2,				//Dma &txDma;
	gUart3TxDmaInfo				//Dma::DmaInfo txDmaInfo;
};

Usart usart3(gDrvUart3Setup, gUart3Setup);

extern "C"
{
	void YSS_USART3_IRQHandler(void)
	{
		usart3.isr();
	}
}

#endif

#if defined(UART4) && defined(UART4_ENABLE)
static void enableUart4Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(19, en);
	clock.unlock();
}

static void enableUart4Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(UART4_IRQn, en);
	nvic.unlock();
}

static void resetUart4(void)
{
	clock.lock();
	clock.resetApb1(19);
	clock.unlock();
}

static const Drv::Config gDrvUart4Config
{
	enableUart4Clock,		//void (*clockFunc)(bool en);
	enableUart4Interrupt,	//void (*nvicFunc)(bool en);
	resetUart4,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart4TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk ,
	0,													// uint32_t controlRegister2
	0,													// uint32_t controlRegister3
	(void*)&UART4[UART_REG::DR]							//void *dataRegister;
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
	void YSS_UART4_IRQHandler(void)
	{
		uart4.isr();
	}
}
#endif

#endif


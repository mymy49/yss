/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(GD32F1)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/st_gigadevice/dma_stm32_gd32f1.h>
#include <targets/st_gigadevice/uart_stm32_gd32f1_f4.h>

#if defined(__SEGGER_LINKER)
#define YSS_USART1_IRQHandler		USART0_IRQHandler
#define YSS_USART2_IRQHandler		USART1_IRQHandler
#define YSS_USART3_IRQHandler		USART2_IRQHandler
#define YSS_UART4_IRQHandler		UART3_IRQHandler
#else
#define YSS_USART1_IRQHandler		USART1_IRQHandler
#define YSS_USART2_IRQHandler		USART2_IRQHandler
#define YSS_USART3_IRQHandler		USART3_IRQHandler
#define YSS_UART4_IRQHandler		UART4_IRQHandler
#endif

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

static const Drv::setup_t gDrvUart1Setup
{
	enableUart1Clock,		//void (*clockFunc)(bool en);
	enableUart1Interrupt,	//void (*nvicFunc)(bool en);
	resetUart1,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gUart1TxDmaInfo = 
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

static const Uart::Setup gUart1Setup
{
	(YSS_USART_Typedef*)USART1,	//YSS_SPI_Peri *peri;
	dmaChannel4,				//Dma &txDma;
	gUart1TxDmaInfo				//Dma::dmaInfo_t txDmaInfo;
};

Uart uart1(gDrvUart1Setup, gUart1Setup);

extern "C"
{
	void YSS_USART1_IRQHandler(void)
	{
		uart1.isr();
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

static const Drv::setup_t gDrvUart2Setup
{
	enableUart2Clock,		//void (*clockFunc)(bool en);
	enableUart2Interrupt,	//void (*nvicFunc)(bool en);
	resetUart2,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gUart2TxDmaInfo = 
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

static const Uart::Setup gUart2Setup
{
	(YSS_USART_Typedef*)USART2,	//YSS_SPI_Peri *peri;
	dmaChannel7,				//Dma &txDma;
	gUart2TxDmaInfo				//Dma::dmaInfo_t txDmaInfo;
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

static const Drv::setup_t gDrvUart3Setup
{
	enableUart3Clock,		//void (*clockFunc)(bool en);
	enableUart3Interrupt,	//void (*nvicFunc)(bool en);
	resetUart3,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gUart3TxDmaInfo = 
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

static const Uart::Setup gUart3Setup
{
	(YSS_USART_Typedef*)USART3,	//YSS_SPI_Peri *peri;
	dmaChannel2,				//Dma &txDma;
	gUart3TxDmaInfo				//Dma::dmaInfo_t txDmaInfo;
};

Uart uart3(gDrvUart3Setup, gUart3Setup);

extern "C"
{
	void YSS_USART3_IRQHandler(void)
	{
		uart3.isr();
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

static const Drv::setup_t gDrvUart4Setup
{
	enableUart4Clock,		//void (*clockFunc)(bool en);
	enableUart4Interrupt,	//void (*nvicFunc)(bool en);
	resetUart4,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gUart4TxDmaInfo = 
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

static const Uart::Setup gUart4Setup
{
	(YSS_USART_Typedef*)UART4,	//YSS_SPI_Peri *peri;
	dmaChannel12,			//Dma &txDma;
	gUart4TxDmaInfo			//Dma::dmaInfo_t txDmaInfo;
};

Uart uart4(gDrvUart4Setup, gUart4Setup);

extern "C"
{
	void YSS_UART4_IRQHandler(void)
	{
		uart4.isr();
	}
}
#endif

#endif


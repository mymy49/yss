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

#if defined(GD32F4) || defined(STM32F4) || defined(STM32F7) || defined(STM32F0)

#include <yss/instance.h>
#include <yss.h>
#include <config.h>
#include <yss/reg.h>
#if defined(STM32F0)
#include <targets/st_gigadevice/dma_stm32_gd32f1.h>
#include <targets/st_gigadevice/rcc_stm32f0.h>
#elif defined(GD32F4) || defined(STM32F4) || defined(STM32F7)
#include <targets/st_gigadevice/dma_stm32_gd32f4_f7.h>
#include <targets/st_gigadevice/rcc_stm32_gd32f4_f7.h>
#endif

#if defined(STM32F7) || defined(STM32F0)
#include <targets/st_gigadevice/uart_stm32f0_f7.h>
#elif defined(STM32F4)
#include <targets/st_gigadevice/uart_stm32_gd32f1_f4.h>
#endif

#if defined(STM32F4) || defined(STM32F7)
#define YSS_USART1_IRQHandler		USART1_IRQHandler
#define YSS_USART2_IRQHandler		USART2_IRQHandler
#define YSS_USART3_IRQHandler		USART3_IRQHandler
#define YSS_UART4_IRQHandler		UART4_IRQHandler
#define YSS_UART5_IRQHandler		UART5_IRQHandler
#define YSS_USART6_IRQHandler		USART6_IRQHandler
#elif defined(GD32F4)
#define YSS_USART1_IRQHandler		USART0_IRQHandler
#define YSS_USART2_IRQHandler		USART1_IRQHandler
#define YSS_USART3_IRQHandler		USART2_IRQHandler
#define YSS_UART4_IRQHandler		UART3_IRQHandler
#define YSS_UART5_IRQHandler		UART4_IRQHandler
#define YSS_USART6_IRQHandler		USART5_IRQHandler
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
#if defined(STM32F7)
	(void*)&USART1[UART_REG::TDR],	//void *dataRegister;
#else
	(void*)&USART1->DR,					//void *dataRegister;
#endif
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

static const Drv::Config gDrvUart2Config = 
{
	enableUart2Clock,		//void (*clockFunc)(bool en);
	enableUart2Interrupt,	//void (*nvicFunc)(bool en);
	resetUart2,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(STM32F0)
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
	0x0F << (4 * 1),									// uint32_t controlRegister2
	0x09 << (4 * 1),									// uint32_t controlRegister3
	(void*)&USART2[UART_REG::TDR],						//void *dataRegister;
};
#else
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
#if defined(STM32F7)
	(void*)&USART2[UART_REG::TDR],	//void *dataRegister;
#else
	(void*)&USART2->DR,					//void *dataRegister;
#endif
};
#endif

static const Uart::Config gUart2Config = 
{
	(YSS_USART_Peri*)USART2,	//YSS_USART_Peri *peri;
	dmaChannel7,				//Dma &txDma;
	gUart2TxDmaInfo				//Dma::DmaInfo txDmaInfo;
};

Uart uart2(gDrvUart2Config, gUart2Config);

extern "C"
{
	void YSS_USART2_IRQHandler(void)
	{
		uart2.isr();
	}
}
#endif

#if defined(USART3) && defined(UART3_ENABLE)
static void enableUart3Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(RCC_APB1ENR_USART3EN_Pos, en);
	clock.unlock();
}

static void enableUart3Interrupt(bool en)
{
	nvic.lock();
#if defined(STM32F0)
	nvic.enableInterrupt(USART3_4_IRQn, en);
#else
	nvic.enableInterrupt(USART3_IRQn, en);
#endif
	nvic.unlock();
}

static void resetUart3(void)
{
	clock.lock();
	clock.resetApb1(RCC_APB1RSTR_USART3RST_Pos);
	clock.unlock();
}

static const Drv::Config gDrvUart3Config
{
	enableUart3Clock,		//void (*clockFunc)(bool en);
	enableUart3Interrupt,	//void (*nvicFunc)(bool en);
	resetUart3,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(STM32F0)
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
	0x0F << (4 * 3),									// uint32_t controlRegister2
	0x0A << (4 * 3),									// uint32_t controlRegister3
	(void*)&USART3[UART_REG::TDR],						//void *dataRegister;
};
#else
static const Dma::DmaInfo gUart3TxDmaInfo = 
{
	(define::dma1::stream3::USART3_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
#if defined(STM32F7)
	(void*)&USART3[UART_REG::TDR],	//void *dataRegister;
#else
	(void*)&USART3->DR,					//void *dataRegister;
#endif
};
#endif

static const Uart::Config gUart3Config
{
	USART3,			//YSS_SPI_Peri *peri;
	dmaChannel4,	//Dma &txDma;
	gUart3TxDmaInfo,//Dma::DmaInfo txDmaInfo;
};

Uart uart3(gDrvUart3Config, gUart3Config);

#if !defined(STM32F0)
extern "C"
{
	void YSS_USART3_IRQHandler(void)
	{
		uart3.isr();
	}
}
#endif

#endif



#if (defined(UART4) || defined(USART4)) && defined(UART4_ENABLE)
static void enableUart4Clock(bool en)
{
	clock.lock();
#if defined(STM32F0)
	clock.enableApb1Clock(RCC_APB1ENR_USART4EN_Pos, en);
#else
	clock.enableApb1Clock(RCC_APB1ENR_UART4EN_Pos, en);
#endif
	clock.unlock();
}

static void enableUart4Interrupt(bool en)
{
	nvic.lock();
#if defined(STM32F0)
	nvic.enableInterrupt(USART3_4_IRQn, en);
#else
	nvic.enableInterrupt(UART4_IRQn, en);
#endif
	nvic.unlock();
}

static void resetUart4(void)
{
	clock.lock();
#if defined(STM32F0)
	clock.resetApb1(RCC_APB1RSTR_USART4RST_Pos);
#else
	clock.resetApb1(RCC_APB1RSTR_UART4RST_Pos);
#endif
	clock.unlock();
}

static const Drv::Config gDrvUart4Config = 
{
	enableUart4Clock,		//void (*clockFunc)(bool en);
	enableUart4Interrupt,	//void (*nvicFunc)(bool en);
	resetUart4,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(STM32F0)
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
	0x0F << (4 * 3),									// uint32_t controlRegister2
	0x0B << (4 * 3),									// uint32_t controlRegister3
	(void*)&USART4[UART_REG::TDR],						//void *dataRegister;
};
#else
static const Dma::DmaInfo gUart4TxDmaInfo = 
{
	(define::dma1::stream4::UART4_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
#if defined(STM32F7)
	(void*)&UART4[UART_REG::TDR],	//void *dataRegister;
#else
	(void*)&UART4->DR,						//void *dataRegister;
#endif
};
#endif

static const Uart::Config gUart4Config = 
{
#if defined(STM32F0)
	USART4,			//YSS_SPI_Peri *peri;
	dmaChannel4,	//Dma &txDma;
#else
	UART4,			//YSS_SPI_Peri *peri;
	dmaChannel5,	//Dma &txDma;
#endif
	gUart4TxDmaInfo	//Dma::DmaInfo txDmaInfo;
};

Uart uart4(gDrvUart4Config, gUart4Config);

#if !defined(STM32F0)
extern "C"
{
	void YSS_UART4_IRQHandler(void)
	{
		uart4.isr();
	}
}
#endif

#endif

#if defined(UART5) && defined(UART5_ENABLE)
static void enableUart5Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(RCC_APB1ENR_UART5EN_Pos, en);
	clock.unlock();
}

static void enableUart5Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(UART5_IRQn, en);
	nvic.unlock();
}

static void resetUart5(void)
{
	clock.lock();
	clock.resetApb1(RCC_APB1RSTR_UART5RST_Pos);
	clock.unlock();
}

static const Drv::Config gDrvUart5Config
{
	enableUart5Clock,		//void (*clockFunc)(bool en);
	enableUart5Interrupt,	//void (*nvicFunc)(bool en);
	resetUart5,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart5TxDmaInfo = 
{
	(define::dma1::stream7::UART5_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
#if defined(STM32F7)
	(void*)&UART5[UART_REG::TDR],	//void *dataRegister;
#else
	(void*)&UART5->DR,						//void *dataRegister;
#endif
};

static const Uart::Config gUart5Config
{
	UART5,			//YSS_SPI_Peri *peri;
	dmaChannel8,	//Dma &txDma;
	gUart5TxDmaInfo	//Dma::DmaInfo txDmaInfo;
};

Uart uart5(gDrvUart5Config, gUart5Config);

extern "C"
{
	void YSS_UART5_IRQHandler(void)
	{
		uart5.isr();
	}
}
#endif



#if defined(USART6) && defined(UART6_ENABLE)
static void enableUart6Clock(bool en)
{
	clock.lock();
	clock.enableApb2Clock(RCC_APB2ENR_USART6EN_Pos, en);
	clock.unlock();
}

static void enableUart6Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(USART6_IRQn, en);
	nvic.unlock();
}

static void resetUart6(void)
{
	clock.lock();
	clock.resetApb2(RCC_APB2RSTR_USART6RST_Pos);
	clock.unlock();
}

static const Drv::Config gDrvUart6Config
{
	enableUart6Clock,		//void (*clockFunc)(bool en);
	enableUart6Interrupt,	//void (*nvicFunc)(bool en);
	resetUart6,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart6TxDmaInfo = 
{
	(define::dma2::stream6::USART6_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
#if defined(STM32F7)
	(void*)&USART6[UART_REG::TDR],	//void *dataRegister;
#else
	(void*)&USART6->DR,						//void *dataRegister;
#endif
};

static const Uart::Config gUart6Config
{
	USART6,			//YSS_SPI_Peri *peri;
	dmaChannel15,	//Dma &txDma;
	gUart6TxDmaInfo	//Dma::DmaInfo txDmaInfo;
};

Uart uart6(gDrvUart6Config, gUart6Config);

extern "C"
{
	void YSS_USART6_IRQHandler(void)
	{
		uart6.isr();
	}
}
#endif

#if defined(STM32F0)
extern "C"
{
	void USART3_6_IRQHandler(void)
	{
#if defined(USART3) && defined(UART3_ENABLE)
		if(USART3[UART_REG::ISR] & (USART_ISR_RXNE_Msk | USART_ISR_FE_Msk | USART_ISR_ORE_Msk | USART_ISR_FE_Msk))
			uart3.isr();
#endif
#if defined(UART4) || defined(USART4) && defined(UART4_ENABLE)
		if(USART4[UART_REG::ISR] & (USART_ISR_RXNE_Msk | USART_ISR_FE_Msk | USART_ISR_ORE_Msk | USART_ISR_FE_Msk))
			uart4.isr();
#endif
#if defined(UART5) && defined(UART5_ENABLE)
		if(USART5[UART_REG::ISR] & USART_ISR_RXNE_Msk)
			uart5.isr();
#endif
#if defined(USART6) && defined(UART6_ENABLE)
		if(USART6[UART_REG::ISR] & USART_ISR_RXNE_Msk)
			uart6.isr();
#endif
	}
}
#endif

#endif


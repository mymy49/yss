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

#include <drv/mcu.h>

#if defined(STM32F4_N) || defined(STM32F030xC) || defined(STM32F7_N)

#include <yss/instance.h>
#include <yss.h>
#include <config.h>
#include <yss/reg.h>

#if defined(STM32F4_N)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#elif defined(STM32F030xC)
#include <targets/st/bitfield_stm32f030xx.h>
#endif

#if defined(STM32F4_N) || defined(STM32F7_N)
#define YSS_USART1_IRQHandler		USART1_IRQHandler
#define YSS_USART2_IRQHandler		USART2_IRQHandler
#define YSS_USART3_IRQHandler		USART3_IRQHandler
#define YSS_UART4_IRQHandler		UART4_IRQHandler
#define YSS_UART5_IRQHandler		UART5_IRQHandler
#define YSS_USART6_IRQHandler		USART6_IRQHandler
#define YSS_UART7_IRQHandler		UART7_IRQHandler
#define YSS_UART8_IRQHandler		UART8_IRQHandler
#elif defined(STM32F030xC)
#define YSS_USART1_IRQHandler		USART1_IRQHandler
#define YSS_USART2_IRQHandler		USART2_IRQHandler
#define YSS_USART3_6_IRQHandler		USART3_6_IRQHandler
#endif

static uint32_t getApb1ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}

static uint32_t getApb2ClockFrequency(void)
{
	return clock.getApb2ClockFrequency();
}

#if defined(USART1) && USART1_ENABLE
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

static const Drv::Setup gDrvUart1Setup
{
	enableUart1Clock,		//void (*clockFunc)(bool en);
	enableUart1Interrupt,	//void (*nvicFunc)(bool en);
	resetUart1,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(STM32F030xC)
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
#if (UART1_DMA_TX == DMA_CH2)
	0x0F << (4 * 1),									// uint32_t controlRegister2
	0x08 << (4 * 1),									// uint32_t controlRegister3
#elif (UART1_DMA_TX == DMA_CH4)
	0x0F << (4 * 3),									// uint32_t controlRegister2
	0x08 << (4 * 3),									// uint32_t controlRegister3
#endif
	(void*)&USART2->TDR,								//void *dataRegister;
};
#else
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
#if defined(STM32F7_N)
	(void*)&USART1->TDR,	//void *dataRegister;
#else
	(void*)&USART1->DR,					//void *dataRegister;
#endif
};
#endif

static const Uart::Setup gUart1Setup
{
	USART1,	//YSS_USART_Peri *peri;
#if defined(STM32F030xC)
#if (USART1_DMA_TX == DMA_CH2)
	dmaChannel2,				//Dma &txDma;
#elif (USART1_DMA_TX == DMA_CH4)
	dmaChannel4,				//Dma &txDma;
#endif
#else
	dmaChannel16,				//Dma &txDma;
#endif
	gUart1TxDmaInfo,			//Dma::DmaInfo txDmaInfo;
};

Usart usart1(gDrvUart1Setup, gUart1Setup);

extern "C"
{
	void USART1_IRQHandler(void)
	{
		usart1.isr();
	}
}
#endif



#if defined(USART2) && USART2_ENABLE
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

static const Drv::Setup gDrvUart2Setup= 
{
	enableUart2Clock,		//void (*clockFunc)(bool en);
	enableUart2Interrupt,	//void (*nvicFunc)(bool en);
	resetUart2,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(STM32F030xC)
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
#if (UART2_DMA_TX == DMA_CH2)
	0x0F << (4 * 1),									// uint32_t controlRegister2
	0x09 << (4 * 1),									// uint32_t controlRegister3
#elif (UART2_DMA_TX == DMA_CH4)
	0x0F << (4 * 3),									// uint32_t controlRegister2
	0x09 << (4 * 3),									// uint32_t controlRegister3
#endif

	(void*)&USART2->TDR,								//void *dataRegister;
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
	DMA_SxFCR_DMDIS_Msk,		// uint32_t controlRegister2
	0,							// uint32_t controlRegister3
#if defined(STM32F7_N)
	(void*)&USART2->TDR,		//void *dataRegister;
#else
	(void*)&USART2->DR,			//void *dataRegister;
#endif
};
#endif

static const Uart::Setup gUart2Setup = 
{
	(YSS_USART_Peri*)USART2,	//YSS_USART_Peri *peri;
#if defined(STM32F030xC)
#if (UART2_DMA_TX == DMA_CH2)
	dmaChannel2,				//Dma &txDma;
#elif (UART2_DMA_TX == DMA_CH4)
	dmaChannel4,				//Dma &txDma;
#endif
#else
	dmaChannel7,				//Dma &txDma;
#endif
	gUart2TxDmaInfo				//Dma::DmaInfo txDmaInfo;
};

Usart usart2(gDrvUart2Setup, gUart2Setup);

extern "C"
{
	void USART2_IRQHandler(void)
	{
		usart2.isr();
	}
}
#endif

#if defined(USART3) && USART3_ENABLE
static void enableUart3Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(RCC_APB1ENR_USART3EN_Pos, en);
	clock.unlock();
}

static void enableUart3Interrupt(bool en)
{
	nvic.lock();
#if defined(STM32F030xC)
	nvic.enableInterrupt(USART3_6_IRQn, en);
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

static const Drv::Setup gDrvUart3Setup
{
	enableUart3Clock,		//void (*clockFunc)(bool en);
	enableUart3Interrupt,	//void (*nvicFunc)(bool en);
	resetUart3,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(STM32F030xC)
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
#if (UART3_DMA_TX == DMA_CH2)
	0x0F << (4 * 1),									// uint32_t controlRegister2
	0x0A << (4 * 1),									// uint32_t controlRegister3
#elif (UART3_DMA_TX == DMA_CH4)
	0x0F << (4 * 3),									// uint32_t controlRegister2
	0x0A << (4 * 3),									// uint32_t controlRegister3
#endif
	(void*)&USART3->TDR,								//void *dataRegister;
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
#if defined(STM32F7_N)
	(void*)&USART3->TDR,	//void *dataRegister;
#else
	(void*)&USART3->DR,					//void *dataRegister;
#endif
};
#endif

static const Uart::Setup gUart3Setup
{
	USART3,			//YSS_SPI_Peri *peri;
#if defined(STM32F030xC)
#if (UART3_DMA_TX == DMA_CH2)
	dmaChannel2,				//Dma &txDma;
#elif (UART3_DMA_TX == DMA_CH4)
	dmaChannel4,				//Dma &txDma;
#endif
#else
	dmaChannel4,	//Dma &txDma;
#endif
	gUart3TxDmaInfo,//Dma::DmaInfo txDmaInfo;
};

Usart usart3(gDrvUart3Setup, gUart3Setup);

#if !defined(STM32F030xC)
extern "C"
{
	void USART3_IRQHandler(void)
	{
		usart3.isr();
	}
}
#endif

#endif



#if (defined(UART4) || defined(USART4)) && (UART4_ENABLE || USART4_ENABLE)
static void enableUart4Clock(bool en)
{
	clock.lock();
#if defined(USART4)
	clock.enableApb1Clock(RCC_APB1ENR_USART4EN_Pos, en);
#else
	clock.enableApb1Clock(RCC_APB1ENR_UART4EN_Pos, en);
#endif
	clock.unlock();
}

static void enableUart4Interrupt(bool en)
{
	nvic.lock();
#if defined(STM32F030xC)
	nvic.enableInterrupt(USART3_6_IRQn, en);
#else
	nvic.enableInterrupt(UART4_IRQn, en);
#endif
	nvic.unlock();
}

static void resetUart4(void)
{
	clock.lock();
#if defined(USART4)
	clock.resetApb1(RCC_APB1RSTR_USART4RST_Pos);
#else
	clock.resetApb1(RCC_APB1RSTR_UART4RST_Pos);
#endif
	clock.unlock();
}

static const Drv::Setup gDrvUart4Setup = 
{
	enableUart4Clock,		//void (*clockFunc)(bool en);
	enableUart4Interrupt,	//void (*nvicFunc)(bool en);
	resetUart4,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(STM32F030xC)
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
#if (UART4_DMA_TX == DMA_CH2)
	0x0F << (4 * 1),									// uint32_t controlRegister2
	0x0B << (4 * 1),									// uint32_t controlRegister3
#elif (UART4_DMA_TX == DMA_CH4)
	0x0F << (4 * 3),									// uint32_t controlRegister2
	0x0B << (4 * 3),									// uint32_t controlRegister3
#endif
	(void*)&USART4->TDR,								//void *dataRegister;
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
#if defined(STM32F7_N)
	(void*)&UART4->TDR,				//void *dataRegister;
#else
	(void*)&UART4->DR,						//void *dataRegister;
#endif
};
#endif

static const Uart::Setup gUart4Setup = 
{
#if defined(STM32F030xC)
	USART4,			//YSS_SPI_Peri *peri;
#if (UART4_DMA_TX == DMA_CH2)
	dmaChannel2,				//Dma &txDma;
#elif (UART4_DMA_TX == DMA_CH4)
	dmaChannel4,				//Dma &txDma;
#endif
#else
	UART4,			//YSS_SPI_Peri *peri;
	dmaChannel5,	//Dma &txDma;
#endif
	gUart4TxDmaInfo	//Dma::DmaInfo txDmaInfo;
};

#if defined(USART4)
Usart usart4(gDrvUart4Setup, gUart4Setup);
#else
Uart uart4(gDrvUart4Setup, gUart4Setup);
#endif

#if !defined(STM32F030xC)
extern "C"
{
	void UART4_IRQHandler(void)
	{
		uart4.isr();
	}
}
#endif

#endif

#if (defined(UART5) || defined(USART5)) && (UART5_ENABLE || USART5_ENABLE)
static void enableUart5Clock(bool en)
{
	clock.lock();
#if defined(USART5)
	clock.enableApb1Clock(RCC_APB1ENR_USART5EN_Pos, en);
#else
	clock.enableApb1Clock(RCC_APB1ENR_UART5EN_Pos, en);
#endif
	clock.unlock();
}

static void enableUart5Interrupt(bool en)
{
	nvic.lock();
#if defined(STM32F030xC)
	nvic.enableInterrupt(USART3_6_IRQn, en);
#else
	nvic.enableInterrupt(UART5_IRQn, en);
#endif
	nvic.unlock();
}

static void resetUart5(void)
{
	clock.lock();
#if defined(USART5)
	clock.resetApb1(RCC_APB1RSTR_USART5RST_Pos);
#else
	clock.resetApb1(RCC_APB1RSTR_UART5RST_Pos);
#endif
	clock.unlock();
}

static const Drv::Setup gDrvUart5Setup
{
	enableUart5Clock,		//void (*clockFunc)(bool en);
	enableUart5Interrupt,	//void (*nvicFunc)(bool en);
	resetUart5,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(STM32F030xC)
static const Dma::DmaInfo gUart5TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk ,
#if (UART5_DMA_TX == DMA_CH2)
	0x0F << (4 * 1),									// uint32_t controlRegister2
	0x0C << (4 * 1),									// uint32_t controlRegister3
#elif (UART5_DMA_TX == DMA_CH4)
	0x0F << (4 * 3),									// uint32_t controlRegister2
	0x0C << (4 * 3),									// uint32_t controlRegister3
#endif
	(void*)&USART5->TDR,								//void *dataRegister;
};
#else
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
#if defined(STM32F7_N)
	(void*)&UART5->TDR,				//void *dataRegister;
#else
	(void*)&UART5->DR,						//void *dataRegister;
#endif
};
#endif

static const Uart::Setup gUart5Setup
{
#if defined(STM32F030xC)
	USART5,			//YSS_SPI_Peri *peri;
#if (UART5_DMA_TX == DMA_CH2)
	dmaChannel2,	//Dma &txDma;
#elif (UART5_DMA_TX == DMA_CH4)
	dmaChannel4,	//Dma &txDma;
#endif
#else
	UART5,			//YSS_SPI_Peri *peri;
	dmaChannel8,	//Dma &txDma;
#endif
	gUart5TxDmaInfo	//Dma::DmaInfo txDmaInfo;
};

#if defined(STM32F030xC)
Usart usart5(gDrvUart5Setup, gUart5Setup);
#else
Uart uart5(gDrvUart5Setup, gUart5Setup);
#endif

extern "C"
{
#if !defined(STM32F030xC)
	void UART5_IRQHandler(void)
	{
		uart5.isr();
	}
#endif
}
#endif



#if defined(USART6) && USART6_ENABLE
static void enableUart6Clock(bool en)
{
	clock.lock();
	clock.enableApb2Clock(RCC_APB2ENR_USART6EN_Pos, en);
	clock.unlock();
}

static void enableUart6Interrupt(bool en)
{
	nvic.lock();
#if defined(STM32F030xC)
	nvic.enableInterrupt(USART3_6_IRQn, en);
#else
	nvic.enableInterrupt(USART6_IRQn, en);
#endif
	nvic.unlock();
}

static void resetUart6(void)
{
	clock.lock();
	clock.resetApb2(RCC_APB2RSTR_USART6RST_Pos);
	clock.unlock();
}

static const Drv::Setup gDrvUart6Setup
{
	enableUart6Clock,		//void (*clockFunc)(bool en);
	enableUart6Interrupt,	//void (*nvicFunc)(bool en);
	resetUart6,				//void (*resetFunc)(void);
	getApb2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

#if defined(STM32F030xC)
static const Dma::DmaInfo gUart6TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk ,
#if (UART6_DMA_TX == DMA_CH2)
	0x0F << (4 * 1),									// uint32_t controlRegister2
	0x0D << (4 * 1),									// uint32_t controlRegister3
#elif (UART6_DMA_TX == DMA_CH4)
	0x0F << (4 * 3),									// uint32_t controlRegister2
	0x0D << (4 * 3),									// uint32_t controlRegister3
#endif
	(void*)&USART6->TDR,								//void *dataRegister;
};
#else
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
#if defined(STM32F7_N)
	(void*)&USART6->TDR,			//void *dataRegister;
#else
	(void*)&USART6->DR,						//void *dataRegister;
#endif
};
#endif

static const Uart::Setup gUart6Setup
{
	USART6,			//YSS_SPI_Peri *peri;
#if defined(STM32F030xC)
#if (UART6_DMA_TX == DMA_CH2)
	dmaChannel2,	//Dma &txDma;
#else (UART6_DMA_TX == DMA_CH4)
	dmaChannel4,	//Dma &txDma;
#endif
#else
	dmaChannel15,	//Dma &txDma;
#endif
	gUart6TxDmaInfo	//Dma::DmaInfo txDmaInfo;
};

Usart usart6(gDrvUart6Setup, gUart6Setup);

extern "C"
{
	void USART6_IRQHandler(void)
	{
		usart6.isr();
	}
}
#endif



#if (defined(UART7) || defined(USART7)) && UART7_ENABLE
static void enableUart7Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(RCC_APB1ENR_UART7EN_Pos, en);
	clock.unlock();
}

static void enableUart7Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(UART7_IRQn, en);
	nvic.unlock();
}

static void resetUart7(void)
{
	clock.lock();
	clock.resetApb1(RCC_APB1RSTR_UART7RST_Pos);
	clock.unlock();
}

static const Drv::Setup gDrvUart7Setup
{
	enableUart7Clock,		//void (*clockFunc)(bool en);
	enableUart7Interrupt,	//void (*nvicFunc)(bool en);
	resetUart7,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart7TxDmaInfo = 
{
	(define::dma1::stream1::UART7_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
#if defined(STM32F7_N)
	(void*)&UART7->TDR,			//void *dataRegister;
#else
	(void*)&UART7->DR,						//void *dataRegister;
#endif
};

static const Uart::Setup gUart7Setup
{
	UART7,			//YSS_SPI_Peri *peri;
	dmaChannel2,	//Dma &txDma;
	gUart7TxDmaInfo	//Dma::DmaInfo txDmaInfo;
};

Uart uart7(gDrvUart7Setup, gUart7Setup);

extern "C"
{
	void YSS_UART7_IRQHandler(void)
	{
		uart7.isr();
	}
}
#endif



#if (defined(UART8) || defined(USART8)) && UART8_ENABLE
static void enableUart8Clock(bool en)
{
	clock.lock();
	clock.enableApb1Clock(RCC_APB1ENR_UART8EN_Pos, en);
	clock.unlock();
}

static void enableUart8Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(UART8_IRQn, en);
	nvic.unlock();
}

static void resetUart8(void)
{
	clock.lock();
	clock.resetApb1(RCC_APB1RSTR_UART7RST_Pos);
	clock.unlock();
}

static const Drv::Setup gDrvUart8Setup
{
	enableUart8Clock,		//void (*clockFunc)(bool en);
	enableUart8Interrupt,	//void (*nvicFunc)(bool en);
	resetUart8,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart8TxDmaInfo = 
{
	(define::dma1::stream0::UART8_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
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
#if defined(STM32F7_N)
	(void*)&UART8->TDR,			//void *dataRegister;
#else
	(void*)&UART8->DR,						//void *dataRegister;
#endif
};

static const Uart::Setup gUart8Setup
{
	UART8,			//YSS_SPI_Peri *peri;
	dmaChannel1,	//Dma &txDma;
	gUart8TxDmaInfo	//Dma::DmaInfo txDmaInfo;
};

Uart uart8(gDrvUart8Setup, gUart8Setup);

extern "C"
{
	void YSS_UART8_IRQHandler(void)
	{
		uart8.isr();
	}
}
#endif



#if defined(STM32F030xC)
extern "C"
{
	void USART3_6_IRQHandler(void)
	{
#if defined(USART3) && USART3_ENABLE
		if(USART3->ISR & (USART_ISR_RXNE_Msk | USART_ISR_FE_Msk | USART_ISR_ORE_Msk | USART_ISR_FE_Msk))
			usart3.isr();
#endif
#if (defined(UART4) || defined(USART4)) && USART4_ENABLE
		if(USART4->ISR & (USART_ISR_RXNE_Msk | USART_ISR_FE_Msk | USART_ISR_ORE_Msk | USART_ISR_FE_Msk))
			usart4.isr();
#endif
#if (defined(UART5) || defined(USART5)) && USART5_ENABLE
		if(USART5->ISR & (USART_ISR_RXNE_Msk | USART_ISR_FE_Msk | USART_ISR_ORE_Msk | USART_ISR_FE_Msk))
			usart5.isr();
#endif
#if defined(USART6) && USART6_ENABLE
		if(USART6->ISR & (USART_ISR_RXNE_Msk | USART_ISR_FE_Msk | USART_ISR_ORE_Msk | USART_ISR_FE_Msk))
			usart6.isr();
#endif
	}
}
#endif

#endif


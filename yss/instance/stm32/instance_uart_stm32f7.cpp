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

#if defined(STM32F7) || defined(STM32F4)

#include <config.h>

static int getApb2ClkFreq(void)
{
	return clock.getApb2ClkFreq();
}

static int getApb1ClkFreq(void)
{
	return clock.getApb1ClkFreq();
}



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
	getApb2ClkFreq		//unsigned int (*getClockFunc)(void);
};

static const Dma::DmaInfo gUart1DmaInfoTx = 
{
	(define::dma2::stream7::USART1_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
#if defined(STM32F4)
	(void*)&USART1->DR,											//void *dataRegister;
#else
	(void*)&USART1->TDR,										//void *dataRegister;
#endif
};

static const Uart::Config gUart1Config
{
	USART1,				//YSS_USART_Peri *peri;
	dmaChannel16,		//Dma txDma;
	gUart1DmaInfoTx		//Dma::DmaInfo txDmaInfo;
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
	resetUart2			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gUart2DmaInfoTx = 
{
	(define::dma1::stream6::USART2_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
#if defined(STM32F4)
	(void*)&USART2->DR,											//void *dataRegister;
#else
	(void*)&USART2->TDR,										//void *dataRegister;
#endif
};

static const Uart::Config gUart2Config
{
	USART2,				//YSS_USART_Peri *peri;
	dmaChannel7,		//Dma txDma;
	gUart2DmaInfoTx		//Dma::DmaInfo txDmaInfo;
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
	resetUart3			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gUart3DmaInfoTx = 
{
	(define::dma1::stream3::USART3_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
#if defined(STM32F4)
	(void*)&USART3->DR,											//void *dataRegister;
#else
	(void*)&USART3->TDR,										//void *dataRegister;
#endif
};

static const Uart::Config gUart3Config
{
	USART3,				//YSS_USART_Peri *peri;
	dmaChannel4,		//Dma txDma;
	gUart3DmaInfoTx		//Dma::DmaInfo txDmaInfo;
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
	resetUart4			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gUart4DmaInfoTx = 
{
	(define::dma1::stream4::UART4_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
#if defined(STM32F4)
	(void*)&UART4->DR,											//void *dataRegister;
#else
	(void*)&UART4->TDR,											//void *dataRegister;
#endif
};

static const Uart::Config gUart4Config
{
	UART4,				//YSS_USART_Peri *peri;
	dmaChannel5,		//Dma txDma;
	gUart4DmaInfoTx		//Dma::DmaInfo txDmaInfo;
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



#if defined(UART5) && defined(UART5_ENABLE)
static void setUart5ClockEn(bool en)
{
	clock.peripheral.setUart5En(en);
}

static void setUart5IntEn(bool en)
{
	nvic.setUart5En(en);
}

static void resetUart5(void)
{
	clock.peripheral.resetUart5();
}

static const Drv::Config gDrvUart5Config
{
	setUart5ClockEn,	//void (*clockFunc)(bool en);
	setUart5IntEn,		//void (*nvicFunc)(bool en);
	resetUart5			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gUart5DmaInfoTx = 
{
	(define::dma1::stream7::UART5_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
#if defined(STM32F4)
	(void*)&UART5->DR,											//void *dataRegister;
#else
	(void*)&UART5->TDR,											//void *dataRegister;
#endif
};

static const Uart::Config gUart5Config
{
	UART5,				//YSS_USART_Peri *peri;
	dmaChannel8,		//Dma txDma;
	gUart5DmaInfoTx		//Dma::DmaInfo txDmaInfo;
};

Uart uart5(gDrvUart5Config, gUart5Config);

extern "C"
{
	void UART5_IRQHandler(void)
	{
		uart5.isr();
	}
}
#endif



#if defined(USART6) && defined(UART6_ENABLE)
static void setUart6ClockEn(bool en)
{
	clock.peripheral.setUart6En(en);
}

static void setUart6IntEn(bool en)
{
	nvic.setUart6En(en);
}

static void resetUart6(void)
{
	clock.peripheral.resetUart6();
}

static const Drv::Config gDrvUart6Config
{
	setUart6ClockEn,	//void (*clockFunc)(bool en);
	setUart6IntEn,		//void (*nvicFunc)(bool en);
	resetUart6			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gUart6DmaInfoTx = 
{
	(define::dma2::stream6::USART6_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
#if defined(STM32F4)
	(void*)&USART6->DR,											//void *dataRegister;
#else
	(void*)&USART6->TDR,										//void *dataRegister;
#endif
};

static const Uart::Config gUart6Config
{
	USART6,				//YSS_USART_Peri *peri;
	dmaChannel15,		//Dma txDma;
	gUart6DmaInfoTx		//Dma::DmaInfo txDmaInfo;
};

Uart uart6(gDrvUart6Config, gUart6Config);

extern "C"
{
	void USART6_IRQHandler(void)
	{
		uart6.isr();
	}
}
#endif



#if defined(UART7) && defined(UART7_ENABLE)
static void setUart7ClockEn(bool en)
{
	clock.peripheral.setUart7En(en);
}

static void setUart7IntEn(bool en)
{
	nvic.setUart7En(en);
}

static void resetUart7(void)
{
	clock.peripheral.resetUart7();
}

static const Drv::Config gDrvUart7Config = 
{
	setUart7ClockEn,	//void (*clockFunc)(bool en);
	setUart7IntEn,		//void (*nvicFunc)(bool en);
	resetUart7			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gUart7DmaInfoTx = 
{
	(define::dma1::stream1::UART7_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
#if defined(STM32F4)
	(void*)&UART7->DR,											//void *dataRegister;
#else
	(void*)&UART7->TDR,											//void *dataRegister;
#endif
};

static const Uart::Config gUart7Config = 
{
	UART7,				//YSS_USART_Peri *peri;
	dmaChannel8,		//Dma txDma;
	gUart7DmaInfoTx		//Dma::DmaInfo txDmaInfo;
};

Uart uart7(gDrvUart7Config, gUart7Config);

extern "C"
{
	void UART7_IRQHandler(void)
	{
		uart7.isr();
	}
}
#endif

#if defined(UART8) && defined(UART8_ENABLE)
static void setUart8ClockEn(bool en)
{
	clock.peripheral.setUart8En(en);
}

static void setUart8IntEn(bool en)
{
	nvic.setUart8En(en);
}

static void resetUart8(void)
{
	clock.peripheral.resetUart8();
}

static const Drv::Config gDrvUart8Config = 
{
	setUart8ClockEn,	//void (*clockFunc)(bool en);
	setUart8IntEn,		//void (*nvicFunc)(bool en);
	resetUart8			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gUart8DmaInfoTx = 
{
	(define::dma1::stream0::UART8_TX << DMA_SxCR_CHSEL_Pos) |	// unsigned int controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// unsigned int controlRegister2
	0,															// unsigned int controlRegister3
#if defined(STM32F4)
	(void*)&UART8->DR,											//void *dataRegister;
#else
	(void*)&UART8->TDR,											//void *dataRegister;
#endif
};

static const Uart::Config gUart8Config = 
{
	UART8,				//YSS_USART_Peri *peri;
	dmaChannel8,		//Dma txDma;
	gUart7DmaInfoTx		//Dma::DmaInfo txDmaInfo;
};

Uart uart8(gDrvUart8Config, gUart8Config);

extern "C"
{
	void UART8_IRQHandler(void)
	{
		uart8.isr();
	}
}
#endif

#endif


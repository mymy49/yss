/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

/*---------------------------------------------------------------------------------------------------------*/
/*  Transfer Direction Definitions                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_DIR_MEM_TO_PERI 0x00004000UL            /*!<DMA Single Request  \hideinitializer */
#define PDMA_DIR_PERI_TO_MEM 0x00000000UL            /*!<DMA Burst Request  \hideinitializer */

#if defined(UART0) && UART0_ENABLE
static void enableUart0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_UART0CKEN_Pos, en);
}

static void enableUart0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART0_IRQn, en);
}

static void resetUart0(void)
{
	__disable_irq();
	setBitData(SYS->IPRST1, true, SYS_IPRST1_UART0RST_Pos);
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	setBitData(SYS->IPRST1, false, SYS_IPRST1_UART0RST_Pos);
	__enable_irq();
}

static uint32_t getUart0ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL1 & CLK_CLKSEL1_UART0SEL_Msk) >> CLK_CLKSEL1_UART0SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;

	case 4 : // PCLK0
		clk = clock.getApb0ClockFrequency();
		break;
	
	case 5 : // LIRC
		clk = clock.getLircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV0 & CLK_CLKDIV0_UART0DIV_Msk) >> CLK_CLKDIV0_UART0DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart0Setup = 
{
	enableUart0Clock,		//void (*clockFunc)(bool en);
	enableUart0Interrupt,	//void (*nvicFunc)(bool en);
	resetUart0,				//void (*resetFunc)(void);
	getUart0ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart0TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART0_TX,		// uint8_t src;
	(void*)&UART0->DAT,	// void *cpar;
};

static const NuvotonUart::setup_t gUart0Setup = 
{
	UART0,				// YSS_SPI_Peri *peri;
	gUart0TxDmaInfo		// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUart uart0(gDrvUart0Setup, gUart0Setup);

extern "C"
{
	void UART0_IRQHandler(void)
	{
		uart0.isr();
	}
}
#endif



#if defined(UART1) && UART1_ENABLE
static void enableUart1Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_UART1CKEN_Pos, en);
}

static void enableUart1Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART1_IRQn, en);
}

static void resetUart1(void)
{
	__disable_irq();
	setBitData(SYS->IPRST1, true, SYS_IPRST1_UART1RST_Pos);
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	setBitData(SYS->IPRST1, false, SYS_IPRST1_UART1RST_Pos);
	__enable_irq();
}

static uint32_t getUart1ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL1 & CLK_CLKSEL1_UART1SEL_Msk) >> CLK_CLKSEL1_UART1SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	
	case 4 : // PCLK1
		clk = clock.getApb1ClockFrequency();
		break;
	
	case 5 : // LIRC
		clk = clock.getLircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV0 & CLK_CLKDIV0_UART1DIV_Msk) >> CLK_CLKDIV0_UART1DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart1Setup = 
{
	enableUart1Clock,		//void (*clockFunc)(bool en);
	enableUart1Interrupt,	//void (*nvicFunc)(bool en);
	resetUart1,				//void (*resetFunc)(void);
	getUart1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart1TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART1_TX,		// uint8_t src;
	(void*)&UART1->DAT,	// void *cpar;
};

static const NuvotonUart::setup_t gUart1Setup = 
{
	UART1,	// YSS_SPI_Peri *peri;
	gUart1TxDmaInfo				// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUart uart1(gDrvUart1Setup, gUart1Setup);

extern "C"
{
	void UART1_IRQHandler(void)
	{
		uart1.isr();
	}
}
#endif



#if defined(UART2) && UART2_ENABLE
static void enableUart2Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_UART2CKEN_Pos, en);
}

static void enableUart2Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART2_IRQn, en);
}

static void resetUart2(void)
{
	__disable_irq();
	setBitData(SYS->IPRST1, true, SYS_IPRST1_UART2RST_Pos);
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	setBitData(SYS->IPRST1, false, SYS_IPRST1_UART2RST_Pos);
	__enable_irq();
}

static uint32_t getUart2ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL3 & CLK_CLKSEL3_UART2SEL_Msk) >> CLK_CLKSEL3_UART2SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;

	case 4 : // PCLK0
		clk = clock.getApb0ClockFrequency();
		break;
	
	case 5 : // LIRC
		clk = clock.getLircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV4 & CLK_CLKDIV4_UART2DIV_Msk) >> CLK_CLKDIV4_UART2DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart2Setup = 
{
	enableUart2Clock,		//void (*clockFunc)(bool en);
	enableUart2Interrupt,	//void (*nvicFunc)(bool en);
	resetUart2,				//void (*resetFunc)(void);
	getUart2ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart2TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART2_TX,		// uint8_t src;
	(void*)&UART2->DAT,	// void *cpar;
};

static const NuvotonUart::setup_t gUart2Setup = 
{
	UART2,	// YSS_SPI_Peri *peri;
	gUart2TxDmaInfo				// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUart uart2(gDrvUart2Setup, gUart2Setup);

extern "C"
{
	void UART2_IRQHandler(void)
	{
		uart2.isr();
	}
}
#endif



#if defined(UART3) && UART3_ENABLE
static void enableUart3Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_UART3CKEN_Pos, en);
}

static void enableUart3Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART3_IRQn, en);
}

static void resetUart3(void)
{
	__disable_irq();
	setBitData(SYS->IPRST1, true, SYS_IPRST1_UART3RST_Pos);
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	setBitData(SYS->IPRST1, false, SYS_IPRST1_UART3RST_Pos);
	__enable_irq();
}

static uint32_t getUart3ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL3 & CLK_CLKSEL3_UART3SEL_Msk) >> CLK_CLKSEL3_UART3SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;

	case 4 : // PCLK1
		clk = clock.getApb1ClockFrequency();
		break;
	
	case 5 : // LIRC
		clk = clock.getLircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV4 & CLK_CLKDIV4_UART3DIV_Msk) >> CLK_CLKDIV4_UART3DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart3Setup = 
{
	enableUart3Clock,		//void (*clockFunc)(bool en);
	enableUart3Interrupt,	//void (*nvicFunc)(bool en);
	resetUart3,				//void (*resetFunc)(void);
	getUart3ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart3TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART3_TX,		// uint8_t src;
	(void*)&UART3->DAT,	// void *cpar;
};

static const NuvotonUart::setup_t gUart3Setup = 
{
	UART3,	// YSS_SPI_Peri *peri;
	gUart3TxDmaInfo				// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUart uart3(gDrvUart3Setup, gUart3Setup);

extern "C"
{
	void UART3_IRQHandler(void)
	{
		uart3.isr();
	}
}
#endif



#if defined(UART4) && UART4_ENABLE
static void enableUart4Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_UART4CKEN_Pos, en);
}

static void enableUart4Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART4_IRQn, en);
}

static void resetUart4(void)
{
	__disable_irq();
	setBitData(SYS->IPRST1, true, SYS_IPRST1_UART4RST_Pos);
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	setBitData(SYS->IPRST1, false, SYS_IPRST1_UART4RST_Pos);
	__enable_irq();
}

static uint32_t getUart4ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL3 & CLK_CLKSEL3_UART4SEL_Msk) >> CLK_CLKSEL3_UART4SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV4 & CLK_CLKDIV4_UART4DIV_Msk) >> CLK_CLKDIV4_UART4DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart4Setup = 
{
	enableUart4Clock,		//void (*clockFunc)(bool en);
	enableUart4Interrupt,	//void (*nvicFunc)(bool en);
	resetUart4,				//void (*resetFunc)(void);
	getUart4ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart4TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART4_TX,		// uint8_t src;
	(void*)&UART4->DAT,	// void *cpar;
};

static const NuvotonUart::setup_t gUart4Setup = 
{
	UART4,	// YSS_SPI_Peri *peri;
	gUart4TxDmaInfo				// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUart uart4(gDrvUart4Setup, gUart4Setup);

extern "C"
{
	void UART4_IRQHandler(void)
	{
		uart4.isr();
	}
}
#endif



#if defined(UART5) && UART5_ENABLE
static void enableUart5Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_UART5CKEN_Pos, en);
}

static void enableUart5Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART5_IRQn, en);
}

static void resetUart5(void)
{
	__disable_irq();
	setBitData(SYS->IPRST1, true, SYS_IPRST1_UART5RST_Pos);
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	setBitData(SYS->IPRST1, false, SYS_IPRST1_UART5RST_Pos);
	__enable_irq();
}

static uint32_t getUart5ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL3 & CLK_CLKSEL3_UART5SEL_Msk) >> CLK_CLKSEL3_UART5SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV4 & CLK_CLKDIV4_UART5DIV_Msk) >> CLK_CLKDIV4_UART5DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart5Setup = 
{
	enableUart5Clock,		//void (*clockFunc)(bool en);
	enableUart5Interrupt,	//void (*nvicFunc)(bool en);
	resetUart5,				//void (*resetFunc)(void);
	getUart5ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart5TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART5_TX,		// uint8_t src;
	(void*)&UART5->DAT,	// void *cpar;
};

static const NuvotonUart::setup_t gUart5Setup = 
{
	UART5,				// YSS_SPI_Peri *peri;
	gUart5TxDmaInfo		// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUart uart5(gDrvUart5Setup, gUart5Setup);

extern "C"
{
	void UART5_IRQHandler(void)
	{
		uart5.isr();
	}
}
#endif



#if defined(UART6) && UART6_ENABLE
static void enableUart6Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_UART6CKEN_Pos, en);
}

static void enableUart6Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART6_IRQn, en);
}

static void resetUart6(void)
{
	__disable_irq();
	setBitData(SYS->IPRST1, true, SYS_IPRST1_UART6RST_Pos);
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	setBitData(SYS->IPRST1, false, SYS_IPRST1_UART6RST_Pos);
	__enable_irq();
}

static uint32_t getUart6ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL3 & CLK_CLKSEL3_UART6SEL_Msk) >> CLK_CLKSEL3_UART6SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV4 & CLK_CLKDIV4_UART6DIV_Msk) >> CLK_CLKDIV4_UART6DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart6Setup = 
{
	enableUart6Clock,		//void (*clockFunc)(bool en);
	enableUart6Interrupt,	//void (*nvicFunc)(bool en);
	resetUart6,				//void (*resetFunc)(void);
	getUart6ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart6TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART6_TX,		// uint8_t src;
	(void*)&UART6->DAT,	// void *cpar;
};

static const NuvotonUart::setup_t gUart6Setup = 
{
	UART6,				// YSS_SPI_Peri *peri;
	gUart6TxDmaInfo		// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUart uart6(gDrvUart6Setup, gUart6Setup);

extern "C"
{
	void UART6_IRQHandler(void)
	{
		uart6.isr();
	}
}
#endif



#if defined(UART7) && UART7_ENABLE
static void enableUart7Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_UART7CKEN_Pos, en);
}

static void enableUart7Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART7_IRQn, en);
}

static void resetUart7(void)
{
	__disable_irq();
	setBitData(SYS->IPRST1, true, SYS_IPRST1_UART7RST_Pos);
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	setBitData(SYS->IPRST1, false, SYS_IPRST1_UART7RST_Pos);
	__enable_irq();
}

static uint32_t getUart7ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL3 & CLK_CLKSEL3_UART7SEL_Msk) >> CLK_CLKSEL3_UART7SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV4 & CLK_CLKDIV4_UART7DIV_Msk) >> CLK_CLKDIV4_UART7DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart7Setup = 
{
	enableUart7Clock,		//void (*clockFunc)(bool en);
	enableUart7Interrupt,	//void (*nvicFunc)(bool en);
	resetUart7,				//void (*resetFunc)(void);
	getUart7ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart7TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART7_TX,		// uint8_t src;
	(void*)&UART7->DAT,	// void *cpar;
};

static const NuvotonUart::setup_t gUart7Setup = 
{
	UART7,				// YSS_SPI_Peri *peri;
	gUart7TxDmaInfo		// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUart uart7(gDrvUart7Setup, gUart7Setup);

extern "C"
{
	void UART7_IRQHandler(void)
	{
		uart7.isr();
	}
}
#endif



#if defined(UART8) && UART8_ENABLE
static void enableUart8Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb2Clock(CLK_APBCLK2_UART8CKEN_Pos, en);
}

static void enableUart8Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART8_IRQn, en);
}

static uint32_t getUart8ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL2 & CLK_CLKSEL2_UART8SEL_Msk) >> CLK_CLKSEL2_UART8SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV5 & CLK_CLKDIV5_UART8DIV_Msk) >> CLK_CLKDIV5_UART8DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart8Setup = 
{
	enableUart8Clock,		//void (*clockFunc)(bool en);
	enableUart8Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getUart8ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart8TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART8_TX,		// uint8_t src;
	(void*)&UART8->DAT,	// void *cpar;
};

static const NuvotonUart::setup_t gUart8Setup = 
{
	UART8,				// YSS_SPI_Peri *peri;
	gUart8TxDmaInfo		// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUart uart8(gDrvUart8Setup, gUart8Setup);

extern "C"
{
	void UART8_IRQHandler(void)
	{
		uart8.isr();
	}
}
#endif



#if defined(UART9) && UART9_ENABLE
static void enableUart9Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb2Clock(CLK_APBCLK2_UART9CKEN_Pos, en);
}

static void enableUart9Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART9_IRQn, en);
}

static uint32_t getUart9ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL2 & CLK_CLKSEL2_UART9SEL_Msk) >> CLK_CLKSEL2_UART9SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV5 & CLK_CLKDIV5_UART9DIV_Msk) >> CLK_CLKDIV5_UART9DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart9Setup = 
{
	enableUart9Clock,		//void (*clockFunc)(bool en);
	enableUart9Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getUart9ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart9TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART9_TX,		// uint8_t src;
	(void*)&UART9->DAT,	// void *cpar;
};

static const NuvotonUart::setup_t gUart9Setup = 
{
	UART9,				// YSS_SPI_Peri *peri;
	gUart7TxDmaInfo		// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUart uart9(gDrvUart7Setup, gUart7Setup);

extern "C"
{
	void UART9_IRQHandler(void)
	{
		uart9.isr();
	}
}
#endif

#endif


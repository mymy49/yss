/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/nuvoton/bitfield_m4xx.h>

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
	}

	return clk / (((CLK->CLKDIV0 & CLK_CLKDIV0_UART0DIV_Msk) >> CLK_CLKDIV0_UART0DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart0Setup = 
{
	enableUart0Clock,		//void (*clockFunc)(bool en);
	enableUart0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
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

static const Uart::setup_t gUart0Setup = 
{
	(YSS_USART_Typedef*)UART0,	// YSS_SPI_Peri *peri;
	gUart0TxDmaInfo				// Dma::dmaInfo_t txDmaInfo;
};

Uart uart0(gDrvUart0Setup, gUart0Setup);

extern "C"
{
	void UART0_IRQHandler(void)
	{
		uart0.isr();
	}
}
#endif

#endif


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

#if defined(UUART0) && UUART0_ENABLE
static void enableUuart0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb1Clock(CLK_APBCLK1_USCI0CKEN_Pos, en);
}

static void enableUuart0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(USCI0_IRQn, en);
}

static uint32_t getUuart0ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}

static const Drv::setup_t gDrvUuart0Setup = 
{
	enableUuart0Clock,		//void (*clockFunc)(bool en);
	enableUuart0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getUuart0ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUuart0TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,			// uint32_t ctl;
	PDMA_USCI0_TX,			// uint8_t src;
	(void*)&UUART0->TXDAT,	// void *cpar;
};

static const NuvotonUuart::setup_t gUuart0Setup = 
{
	UUART0,					// YSS_SPI_Peri *peri;
	gUuart0TxDmaInfo		// Dma::dmaInfo_t txDmaInfo;
};

NuvotonUuart uuart0(gDrvUuart0Setup, gUuart0Setup);

extern "C"
{
	void USCI0_IRQHandler(void)
	{
		uuart0.isr();
	}
}
#endif

#endif


/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M251_SUBFAMILY__)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

/*---------------------------------------------------------------------------------------------------------*/
/*  Transfer Direction Definitions                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_DIR_MEM_TO_PERI 0x00004000UL            /*!<DMA Single Request  \hideinitializer */
#define PDMA_DIR_PERI_TO_MEM 0x00000000UL            /*!<DMA Burst Request  \hideinitializer */

#if defined(QSPI0) && QSPI0_ENABLE
static void enableQuadspi0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_QSPI0CKEN_Pos, en);
}

static void enableQuadspi0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(QSPI0_IRQn, en);
}

static uint32_t getQuadspi0ClockFrequency(void)
{
	switch((CLK->CLKSEL2 & CLK_CLKSEL2_QSPI0SEL_Msk) >> CLK_CLKSEL2_QSPI0SEL_Pos)
	{
	case 0 : // HXT
		return clock.getHxtFrequency();
	
	case 1 : // PLL
		return clock.getPllFrequency() / 2;

	case 2 : // PCLK
		return clock.getApb0ClockFrequency();
	
	case 3 : // HIRC
		return clock.getHircFrequency();
	
	default :
		return 0;
	}
}

static const Drv::setup_t gDrvQuadspi0Setup = 
{
	enableQuadspi0Clock,		//void (*clockFunc)(bool en);
	enableQuadspi0Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	getQuadspi0ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gQuadspi0TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_32 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_QSPI0_TX,		// uint8_t src;
	(void*)&QSPI0->TX,	// void *cpar;
};

static Dma::dmaInfo_t gQuadspi0RxDmaInfo = 
{
	PDMA_DIR_PERI_TO_MEM |
	PDMA_WIDTH_8 |
	PDMA_SAR_FIX |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_INC | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_QSPI0_RX,		// uint8_t src;
	(void*)&QSPI0->RX,	// void *cpar;
};

static const NuvotonQuadspi::setup_t gQuadspi0Setup = 
{
	QSPI0,				// YSS_SPI_Peri *peri;
	gQuadspi0TxDmaInfo,	// Dma::dmaInfo_t txDmaInfo;
	gQuadspi0RxDmaInfo	// Dma::dmaInfo_t rxDmaInfo;
};

NuvotonQuadspi qspi0(gDrvQuadspi0Setup, gQuadspi0Setup);

extern "C"
{
	void QSPI0_IRQHandler(void)
	{
		qspi0.isr();
	}
}
#endif

#endif


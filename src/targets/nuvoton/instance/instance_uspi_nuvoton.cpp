/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)

#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonUspi.h>
#include <config.h>
#include <yss.h>

/*---------------------------------------------------------------------------------------------------------*/
/*  Transfer Direction Definitions                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#define PDMA_DIR_MEM_TO_PERI 0x00004000UL            /*!<DMA Single Request  \hideinitializer */
#define PDMA_DIR_PERI_TO_MEM 0x00000000UL            /*!<DMA Burst Request  \hideinitializer */

//#if (1 < I2S0_ENABLE + SPI0_ENABLE)
//	#error "같은 장치 번호의 SPI 또는 I2S의 중복 사용을 금지합니다. 두 장치는 같은 장치 입니다."
//#endif

//#if (1 < I2S1_ENABLE + SPI1_ENABLE)
//	#error "같은 장치 번호의 SPI 또는 I2S의 중복 사용을 금지합니다. 두 장치는 같은 장치 입니다."
//#endif

//#if (1 < I2S2_ENABLE + SPI2_ENABLE)
//	#error "같은 장치 번호의 SPI 또는 I2S의 중복 사용을 금지합니다. 두 장치는 같은 장치 입니다."
//#endif

//#if (1 < I2S3_ENABLE + SPI3_ENABLE)
//	#error "같은 장치 번호의 SPI 또는 I2S의 중복 사용을 금지합니다. 두 장치는 같은 장치 입니다."
//#endif

#if USPI0_ENABLE && defined(USPI0)
static void enableUsci0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb1Clock(CLK_APBCLK1_USCI0CKEN_Pos, en);
}

static void enableUsci0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(USCI0_IRQn, en);
}

static void resetUsci0(void)
{
}

static uint32_t getUsci0ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}

static const Drv::setup_t gDrvUsci0Setup = 
{
	enableUsci0Clock,		//void (*clockFunc)(bool en);
	enableUsci0Interrupt,	//void (*nvicFunc)(bool en);
	resetUsci0,				//void (*resetFunc)(void);
	getUsci0ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gUsci0TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,			// uint32_t ctl;
	PDMA_USCI0_TX,			// uint8_t src;
	(void*)&USPI0->TXDAT,	// void *cpar;
};

static const Dma::dmaInfo_t gUsci0RxDmaInfo = 
{
	PDMA_DIR_PERI_TO_MEM |
	PDMA_WIDTH_8 |
	PDMA_SAR_FIX |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_INC | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,			// uint32_t ctl;
	PDMA_USCI0_RX,			// uint8_t src;
	(void*)&USPI0->RXDAT,	// void *cpar;
};

static const NuvotonUspi::setup_t gUsci0Setup = 
{
	USPI0,				//USPI_T *dev;
	gUsci0TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gUsci0RxDmaInfo		//Dma::dmaInfo_t rxDmaInfo;
};

NuvotonUspi uspi0(gDrvUsci0Setup, gUsci0Setup);

extern "C"
{
	void USCI0_IRQHandler(void)
	{
		uspi0.isr();
	}
}
#endif



#if USPI1_ENABLE && defined(USPI1)
static void enableSpi1Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_SPI1CKEN_Pos, en);
}

static void enableSpi1Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(SPI1_IRQn, en);
}

static void resetSpi1(void)
{
}

static uint32_t getSpi1ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL2 & CLK_CLKSEL2_SPI1SEL_Msk) >> CLK_CLKSEL2_SPI1SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // PCLK0
		clk = clock.getApb0ClockFrequency();
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}
	
	return clk;
}

static const Drv::setup_t gDrvSpi1Setup = 
{
	enableSpi1Clock,		//void (*clockFunc)(bool en);
	enableSpi1Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi1,				//void (*resetFunc)(void);
	getSpi1ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi1TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI1_TX,		// uint8_t src;
	(void*)&SPI1->TX,	// void *cpar;
};

static const Dma::dmaInfo_t gSpi1RxDmaInfo = 
{
	PDMA_DIR_PERI_TO_MEM |
	PDMA_WIDTH_8 |
	PDMA_SAR_FIX |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_INC | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI1_RX,		// uint8_t src;
	(void*)&SPI1->RX,	// void *cpar;
};

static const NuvotonSpi::setup_t gSpi1Setup = 
{
	SPI1,			//YSS_SPI_Peri *peri;
	gSpi1TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi1RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

NuvotonSpi spi1(gDrvSpi1Setup, gSpi1Setup);

extern "C"
{
	void SPI1_IRQHandler(void)
	{
		spi1.isr();
	}
}
#endif



#if SPI2_ENABLE && defined(SPI2)
static void enableSpi2Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_SPI2CKEN_Pos, en);
}

static void enableSpi2Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(SPI2_IRQn, en);
}

static void resetSpi2(void)
{
}

static uint32_t getSpi2ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL2 & CLK_CLKSEL2_SPI2SEL_Msk) >> CLK_CLKSEL2_SPI2SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // PCLK1
		clk = clock.getApb1ClockFrequency();
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}
	
	return clk;
}

static const Drv::setup_t gDrvSpi2Setup = 
{
	enableSpi2Clock,		//void (*clockFunc)(bool en);
	enableSpi2Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi2,				//void (*resetFunc)(void);
	getSpi2ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi2TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI2_TX,		// uint8_t src;
	(void*)&SPI2->TX,	// void *cpar;
};

static const Dma::dmaInfo_t gSpi2RxDmaInfo = 
{
	PDMA_DIR_PERI_TO_MEM |
	PDMA_WIDTH_8 |
	PDMA_SAR_FIX |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_INC | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI2_RX,		// uint8_t src;
	(void*)&SPI2->RX,	// void *cpar;
};

static const Spi::setup_t gSpi2Setup = 
{
	SPI2,			//YSS_SPI_Peri *peri;
	gSpi2TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi2RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

Spi spi2(gDrvSpi2Setup, gSpi2Setup);

extern "C"
{
	void SPI2_IRQHandler(void)
	{
		spi2.isr();
	}
}
#endif



#if SPI3_ENABLE && defined(SPI3)
static void enableSpi3Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb1Clock(CLK_APBCLK1_SPI3CKEN_Pos, en);
}

static void enableSpi3Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(SPI3_IRQn, en);
}

static void resetSpi3(void)
{
}

static uint32_t getSpi3ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL2 & CLK_CLKSEL2_SPI3SEL_Msk) >> CLK_CLKSEL2_SPI3SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // PCLK1
		clk = clock.getApb1ClockFrequency();
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}
	
	return clk;
}

static const Drv::setup_t gDrvSpi3Setup = 
{
	enableSpi3Clock,		//void (*clockFunc)(bool en);
	enableSpi3Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi3,				//void (*resetFunc)(void);
	getSpi3ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi3TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI3_TX,		// uint8_t src;
	(void*)&SPI3->TX,	// void *cpar;
};

static const Dma::dmaInfo_t gSpi3RxDmaInfo = 
{
	PDMA_DIR_PERI_TO_MEM |
	PDMA_WIDTH_8 |
	PDMA_SAR_FIX |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_INC | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI3_RX,		// uint8_t src;
	(void*)&SPI3->RX,	// void *cpar;
};

static const Spi::setup_t gSpi3Setup = 
{
	SPI3,			//YSS_SPI_Peri *peri;
	gSpi3TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi3RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

Spi spi3(gDrvSpi3Setup, gSpi3Setup);

extern "C"
{
	void SPI3_IRQHandler(void)
	{
		spi3.isr();
	}
}
#endif

#endif


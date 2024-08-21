/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/nuvoton/bitfield_m48x.h>



#if I2S0_ENABLE && defined(SPI0)
static void enableSpi0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_SPI0CKEN_Pos, en);
}

static void enableSpi0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(SPI0_IRQn, en);
}

static void resetSpi0(void)
{
}

static uint32_t getSpi0ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL2 & CLK_CLKSEL2_SPI0SEL_Msk) >> CLK_CLKSEL2_SPI0SEL_Pos)
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

static const Drv::setup_t gDrvSpi0Setup = 
{
	enableSpi0Clock,		//void (*clockFunc)(bool en);
	enableSpi0Interrupt,	//void (*nvicFunc)(bool en);
	resetSpi0,				//void (*resetFunc)(void);
	getSpi0ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const Dma::dmaInfo_t gSpi0TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI0_TX,		// uint8_t src;
	(void*)&SPI0->TX,	// void *cpar;
};

static const Dma::dmaInfo_t gSpi0RxDmaInfo = 
{
	PDMA_DIR_PERI_TO_MEM |
	PDMA_SAR_FIX |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_INC | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI0_RX,		// uint8_t src;
	(void*)&SPI0->RX,	// void *cpar;
};

static const I2s::setup_t gSpi0Setup = 
{
	SPI0,			//YSS_SPI_Peri *peri;
	gSpi0TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi0RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

I2s i2s0(gDrvSpi0Setup, gSpi0Setup);

#endif



#if I2S2_ENABLE && defined(SPI2)
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
	PDMA_SAR_FIX |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_INC | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_SPI2_RX,		// uint8_t src;
	(void*)&SPI2->RX,	// void *cpar;
};

static const I2s::setup_t gSpi2Setup = 
{
	SPI2,			//YSS_SPI_Peri *peri;
	gSpi2TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	gSpi2RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

I2s i2s2(gDrvSpi2Setup, gSpi2Setup);

#endif

#endif

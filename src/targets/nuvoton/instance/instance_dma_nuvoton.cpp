/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <targets/nuvoton/bitfield_m4xx.h>

Dma *gDmaChannel[YSS__NUM_OF_DMA_CH] = {&dmaChannel1, &dmaChannel2, &dmaChannel3, &dmaChannel4};

static void enableDma1Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableAhbClock(CLK_AHBCLK_PDMACKEN_Pos, en);
}

static void enableDma1Stream0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(PDMA_IRQn, en);
}

const Drv::setup_t gDrvDmaChannel1Setup = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream0Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0,							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma1Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[0]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Setup, gDma1Setup);



const Drv::setup_t gDrvDmaDummySetup = 
{
	0,		//void (*clockFunc)(bool en);
	0,		//void (*nvicFunc)(bool en);
	0,		//void (*resetFunc)(void);
	0,		//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma2Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[1]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel2 dmaChannel2(gDrvDmaDummySetup, gDma2Setup);



const Dma::setup_t gDma3Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[2]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel3 dmaChannel3(gDrvDmaDummySetup, gDma3Setup);



const Dma::setup_t gDma4Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[3]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel4 dmaChannel4(gDrvDmaDummySetup, gDma4Setup);

extern "C"
{
	void PDMA_IRQHandler(void)
	{
		if(PDMA->INTSTS & PDMA_INTSTS_TDIF_Msk)
		{
			if(PDMA->TDSTS & PDMA_TDSTS_TDIF0_Msk)
			{
				dmaChannel1.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF0_Msk;
			}

			if(PDMA->TDSTS & PDMA_TDSTS_TDIF1_Msk)
			{
				dmaChannel2.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF1_Msk;
			}

			if(PDMA->TDSTS & PDMA_TDSTS_TDIF2_Msk)
			{
				dmaChannel3.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF2_Msk;
			}

			if(PDMA->TDSTS & PDMA_TDSTS_TDIF3_Msk)
			{
				dmaChannel4.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF3_Msk;
			}
		}
	}
}

#endif


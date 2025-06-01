/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
#include <targets/nuvoton/bitfield_m4xx.h>
#elif defined(__M2xx_FAMILY)
#include <targets/nuvoton/bitfield_m2xx.h>
#endif

#if defined(__M480_FAMILY)
Dma *gDmaChannel[YSS__NUM_OF_DMA_CH] = {&dmaChannel1, &dmaChannel2, &dmaChannel3, &dmaChannel4, &dmaChannel5, &dmaChannel6, &dmaChannel7, &dmaChannel8, &dmaChannel9, &dmaChannel10, &dmaChannel11, &dmaChannel12, &dmaChannel13, &dmaChannel14, &dmaChannel15, &dmaChannel16};
#elif defined(__M4xx_FAMILY)
Dma *gDmaChannel[YSS__NUM_OF_DMA_CH] = {&dmaChannel1, &dmaChannel2, &dmaChannel3, &dmaChannel4, &dmaChannel5, &dmaChannel6, &dmaChannel7, &dmaChannel8, &dmaChannel9};
#elif defined(__M2xx_FAMILY)
Dma *gDmaChannel[YSS__NUM_OF_DMA_CH] = {&dmaChannel1, &dmaChannel2, &dmaChannel3, &dmaChannel4, &dmaChannel5, &dmaChannel6, &dmaChannel7, &dmaChannel8};
#endif

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



#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
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
#endif



#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
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
#endif



#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
const Dma::setup_t gDma3Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[2]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel3 dmaChannel3(gDrvDmaDummySetup, gDma3Setup);
#endif



#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
const Dma::setup_t gDma4Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[3]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel4 dmaChannel4(gDrvDmaDummySetup, gDma4Setup);
#endif



#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
const Dma::setup_t gDma5Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[4]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel5 dmaChannel5(gDrvDmaDummySetup, gDma5Setup);
#endif



#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
const Dma::setup_t gDma6Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[5]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel6 dmaChannel6(gDrvDmaDummySetup, gDma6Setup);
#endif



#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
const Dma::setup_t gDma7Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[6]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel7 dmaChannel7(gDrvDmaDummySetup, gDma7Setup);
#endif



#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
const Dma::setup_t gDma8Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[7]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel8 dmaChannel8(gDrvDmaDummySetup, gDma8Setup);
#endif



#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
const Dma::setup_t gDma9Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[8]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel9 dmaChannel9(gDrvDmaDummySetup, gDma9Setup);
#endif



#if defined(__M480_FAMILY)
const Dma::setup_t gDma10Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[9]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel10 dmaChannel10(gDrvDmaDummySetup, gDma10Setup);
#endif



#if defined(__M480_FAMILY)
const Dma::setup_t gDma11Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[10]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel11 dmaChannel11(gDrvDmaDummySetup, gDma11Setup);
#endif



#if defined(__M480_FAMILY)
const Dma::setup_t gDma12Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[11]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel12 dmaChannel12(gDrvDmaDummySetup, gDma12Setup);
#endif



#if defined(__M480_FAMILY)
const Dma::setup_t gDma13Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[12]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel13 dmaChannel13(gDrvDmaDummySetup, gDma13Setup);
#endif



#if defined(__M480_FAMILY)
const Dma::setup_t gDma14Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[13]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel14 dmaChannel14(gDrvDmaDummySetup, gDma14Setup);
#endif



#if defined(__M480_FAMILY)
const Dma::setup_t gDma15Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[14]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel15 dmaChannel15(gDrvDmaDummySetup, gDma15Setup);
#endif



#if defined(__M480_FAMILY)
const Dma::setup_t gDma16Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[15]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel16 dmaChannel16(gDrvDmaDummySetup, gDma16Setup);
#endif

extern "C"
{
	void PDMA_IRQHandler(void)
	{
		uint32_t tdsts = PDMA->TDSTS;

		if(PDMA->INTSTS & PDMA_INTSTS_TDIF_Msk)
		{
#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF0_Msk)
			{
				dmaChannel1.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF0_Msk;
			}
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF1_Msk)
			{
				dmaChannel2.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF1_Msk;
			}
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF2_Msk)
			{
				dmaChannel3.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF2_Msk;
			}
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF3_Msk)
			{
				dmaChannel4.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF3_Msk;
			}
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF4_Msk)
			{
				dmaChannel5.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF4_Msk;
			}
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF5_Msk)
			{
				dmaChannel6.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF5_Msk;
			}
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF6_Msk)
			{
				dmaChannel7.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF6_Msk;
			}
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF7_Msk)
			{
				dmaChannel8.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF7_Msk;
			}
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF8_Msk)
			{
				dmaChannel9.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF8_Msk;
			}
#endif

#if defined(__M480_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF9_Msk)
			{
				dmaChannel10.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF9_Msk;
			}
#endif

#if defined(__M480_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF10_Msk)
			{
				dmaChannel11.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF10_Msk;
			}
#endif

#if defined(__M480_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF11_Msk)
			{
				dmaChannel12.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF11_Msk;
			}
#endif

#if defined(__M480_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF12_Msk)
			{
				dmaChannel13.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF12_Msk;
			}
#endif

#if defined(__M480_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF13_Msk)
			{
				dmaChannel14.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF13_Msk;
			}
#endif

#if defined(__M480_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF14_Msk)
			{
				dmaChannel15.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF14_Msk;
			}
#endif

#if defined(__M480_FAMILY)
			if(tdsts & PDMA_TDSTS_TDIF15_Msk)
			{
				dmaChannel16.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF15_Msk;
			}
#endif
		}
	}
}

#endif


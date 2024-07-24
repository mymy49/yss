/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(STM32F0)

#include <targets/st/bitfield_stm32f030xx.h>

static void enableDma1Clock(bool en)
{
	clock.lock();
	clock.enableAhb1Clock(RCC_AHBENR_DMAEN_Pos, en);
	clock.unlock();
}

static void enableDma1Stream0Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Ch1_IRQn, en);
	nvic.unlock();
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
	(YSS_DMA_Peri*)DMA1,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Channel1	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Setup, gDma1Setup);

extern "C"
{
	void DMA1_Channel1_IRQHandler(void)
	{
		dmaChannel1.isr();
	}
}



static void enableDma1Stream1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Ch2_3_DMA2_Ch1_2_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel2Setup = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream1Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0,							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma2Setup = 
{
	(YSS_DMA_Peri*)DMA1,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Channel2	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel2 dmaChannel2(gDrvDmaChannel2Setup, gDma2Setup);



static void enableDma1Stream2Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Ch2_3_DMA2_Ch1_2_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel3Setup = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream2Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0,							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma3Setup = 
{
	(YSS_DMA_Peri*)DMA1,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Channel3	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel3 dmaChannel3(gDrvDmaChannel3Setup, gDma3Setup);

extern "C"
{
	void DMA1_Channel2_3_IRQHandler(void)
	{
		if(DMA1->ISR & (DMA_ISR_GIF2_Msk | DMA_ISR_TCIF2_Msk | DMA_ISR_HTIF2_Msk | DMA_ISR_TEIF2_Msk))
			dmaChannel2.isr();

		if(DMA1->ISR & (DMA_ISR_GIF3_Msk | DMA_ISR_TCIF3_Msk | DMA_ISR_HTIF3_Msk | DMA_ISR_TEIF3_Msk))
			dmaChannel3.isr();
	}
}



static void enableDma1Stream3Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Ch4_7_DMA2_Ch3_5_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel4Setup = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream3Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0,							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma4Setup = 
{
	(YSS_DMA_Peri*)DMA1,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Channel4	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel4 dmaChannel4(gDrvDmaChannel4Setup, gDma4Setup);



static void enableDma1Stream4Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Ch4_7_DMA2_Ch3_5_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel5Setup = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream4Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0,							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma5Setup = 
{
	(YSS_DMA_Peri*)DMA1,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Channel5	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel5 dmaChannel5(gDrvDmaChannel5Setup, gDma5Setup);

extern "C"
{
	void DMA1_Channel4_5_IRQHandler(void)
	{
		if(DMA1->ISR & (DMA_ISR_GIF4_Msk | DMA_ISR_TCIF4_Msk | DMA_ISR_HTIF4_Msk | DMA_ISR_TEIF4_Msk))
			dmaChannel4.isr();

		if(DMA1->ISR & (DMA_ISR_GIF5_Msk | DMA_ISR_TCIF5_Msk | DMA_ISR_HTIF5_Msk | DMA_ISR_TEIF5_Msk))
			dmaChannel5.isr();
	}
}

#endif


/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(STM32F1)

#include <targets/st/bitfield.h>

#define YSS_DMA1_Channel1_IRQHandler		DMA1_Channel1_IRQHandler
#define YSS_DMA1_Channel2_IRQHandler		DMA1_Channel2_IRQHandler
#define YSS_DMA1_Channel3_IRQHandler		DMA1_Channel3_IRQHandler
#define YSS_DMA1_Channel4_IRQHandler		DMA1_Channel4_IRQHandler
#define YSS_DMA1_Channel5_IRQHandler		DMA1_Channel5_IRQHandler
#define YSS_DMA1_Channel6_IRQHandler		DMA1_Channel6_IRQHandler
#define YSS_DMA1_Channel7_IRQHandler		DMA1_Channel7_IRQHandler
#define YSS_DMA2_Channel1_IRQHandler		DMA2_Channel1_IRQHandler
#define YSS_DMA2_Channel2_IRQHandler		DMA2_Channel2_IRQHandler
#define YSS_DMA2_Channel3_IRQHandler		DMA2_Channel3_IRQHandler
#define YSS_DMA2_Channel4_5_IRQHandler		DMA2_Channel4_5_IRQHandler

#if defined(DMA1)
static void enableDma1Clock(bool en)
{
	clock.lock();
    clock.enableAhbClock(RCC_AHBENR_DMA1EN_Pos, en);
	clock.unlock();
}

#if defined(DMA1_CHANNEL1) || defined(DMA1_Channel1)
static void enableDma1Channel1Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA1_Channel1_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel1Setup = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel1Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma1Setup = 
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Channel1	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Setup, gDma1Setup);

extern "C"
{
	void YSS_DMA1_Channel1_IRQHandler(void)
	{
		dmaChannel1.isr();
	}
}
#endif



#if defined(DMA1_CHANNEL2) || defined(DMA1_Channel2)
static void enableDma1Channel2Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA1_Channel2_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel2Setup = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel2Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma2Setup = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel2	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel2 dmaChannel2(gDrvDmaChannel2Setup, gDma2Setup);

extern "C"
{
	void YSS_DMA1_Channel2_IRQHandler(void)
	{
		dmaChannel2.isr();
	}
}
#endif



#if defined(DMA1_CHANNEL3) || defined(DMA1_Channel3)
static void enableDma1Channel3Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA1_Channel3_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel3Setup = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel3Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma3Setup = 
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Channel3	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel3 dmaChannel3(gDrvDmaChannel3Setup, gDma3Setup);

extern "C"
{
	void YSS_DMA1_Channel3_IRQHandler(void)
	{
		dmaChannel3.isr();
	}
}
#endif



#if defined(DMA1_CHANNEL4) || defined(DMA1_Channel4)
static void enableDma1Channel4Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA1_Channel4_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel4Setup = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel4Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma4Setup = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel4	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel4 dmaChannel4(gDrvDmaChannel4Setup, gDma4Setup);

extern "C"
{
	void YSS_DMA1_Channel4_IRQHandler(void)
	{
		dmaChannel4.isr();
	}
}
#endif



#if defined(DMA1_CHANNEL5) || defined(DMA1_Channel5)
static void enableDma1Channel5Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA1_Channel5_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel5Setup = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel5Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma5Setup = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel5	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel5 dmaChannel5(gDrvDmaChannel5Setup, gDma5Setup);

extern "C"
{
	void YSS_DMA1_Channel5_IRQHandler(void)
	{
		dmaChannel5.isr();
	}
}
#endif



#if defined(DMA1_CHANNEL6) || defined(DMA1_Channel6)
static void enableDma1Channel6Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA1_Channel6_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel6Setup = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel6Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma6Setup = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel6	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel6 dmaChannel6(gDrvDmaChannel6Setup, gDma6Setup);

extern "C"
{
	void YSS_DMA1_Channel6_IRQHandler(void)
	{
		dmaChannel6.isr();
	}
}
#endif



#if defined(DMA1_CHANNEL7) || defined(DMA1_Channel7)
static void enableDma1Channel7Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA1_Channel7_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel7Setup = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel7Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma7Setup = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel7	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel7 dmaChannel7(gDrvDmaChannel7Setup, gDma7Setup);

extern "C"
{
	void YSS_DMA1_Channel7_IRQHandler(void)
	{
		dmaChannel7.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL1) || defined(DMA2_Channel1)
static void enableDma2Clock(bool en)
{
	clock.lock();
    clock.enableAhbClock(RCC_AHBENR_DMA2EN_Pos, en);
	clock.unlock();
}

static void enableDma2Channel1Interrupt(bool en)
{
    nvic.lock();	
	nvic.enableInterrupt(DMA2_Channel1_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel8Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel1Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma8Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel1	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel8 dmaChannel8(gDrvDmaChannel8Config, gDma8Config);

extern "C"
{
	void YSS_DMA2_Channel1_IRQHandler(void)
	{
		dmaChannel8.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL2) || defined(DMA2_Channel2)
static void enableDma2Channel2Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA2_Channel2_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel9Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel2Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma9Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel2	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel9 dmaChannel9(gDrvDmaChannel9Config, gDma9Config);

extern "C"
{
	void YSS_DMA2_Channel2_IRQHandler(void)
	{
		dmaChannel9.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL3) || defined(DMA2_Channel3)
static void enableDma2Channel3Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA2_Channel3_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel10Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel3Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma10Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel3	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel10 dmaChannel10(gDrvDmaChannel10Config, gDma10Config);

extern "C"
{
	void YSS_DMA2_Channel3_IRQHandler(void)
	{
		dmaChannel10.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL4) || defined(DMA2_Channel4)
static void enableDma2Channel4Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA2_Channel4_5_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel11Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel4Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma11Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel4	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel11 dmaChannel11(gDrvDmaChannel11Config, gDma11Config);

#endif



#if defined(DMA2_CHANNEL5) || defined(DMA2_Channel5)
static void enableDma2Channel5Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA2_Channel4_5_IRQn, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel12Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel5Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma12Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel5	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel12 dmaChannel12(gDrvDmaChannel12Config, gDma12Config);

extern "C"
{
	void YSS_DMA2_Channel4_5_IRQHandler(void)
	{
		uint32_t ifr = DMA2->ISR;

		if(ifr & DMA_ISR_GIF4_Msk || ifr & DMA_ISR_TCIF4_Msk)
			dmaChannel11.isr();

		if(ifr & DMA_ISR_GIF5_Msk || ifr & DMA_ISR_TCIF5_Msk)
			dmaChannel12.isr();
	}
}
#endif

#endif

#endif

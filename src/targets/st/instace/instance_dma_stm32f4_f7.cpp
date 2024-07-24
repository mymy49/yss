/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(STM32F4) || defined(STM32F7)

#include <targets/st/bitfield.h>

static void enableDma1Clock(bool en)
{
	clock.lock();
	clock.enableAhb1Clock(RCC_AHB1ENR_DMA1EN_Pos, en);
	clock.unlock();
}

static void enableDma2Clock(bool en)
{
	clock.lock();
	clock.enableAhb1Clock(RCC_AHB1ENR_DMA2EN_Pos, en);
	clock.unlock();
}


#if defined(DMA1_Stream0)
static void enableDma1Stream0Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Stream0_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel1Setup
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream0Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma1Setup
{
	(YSS_DMA_Peri*)DMA1,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Stream0	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Setup, gDma1Setup);

extern "C"
{
	void DMA1_Stream0_IRQHandler(void)
	{
		dmaChannel1.isr();
	}
}
#endif



#if defined(DMA1_Stream1)
static void enableDma1Stream1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Stream1_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel2Setup
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream1Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma2Setup
{
	(YSS_DMA_Peri*)DMA1,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Stream1	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel2 dmaChannel2(gDrvDmaChannel2Setup, gDma2Setup);

extern "C"
{
	void DMA1_Stream1_IRQHandler(void)
	{
		dmaChannel2.isr();
	}
}
#endif



#if defined(DMA1_Stream2)
static void enableDma1Stream2Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Stream2_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel3Setup
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream2Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma3Setup
{
	(YSS_DMA_Peri*)DMA1,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Stream2	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel3 dmaChannel3(gDrvDmaChannel3Setup, gDma3Setup);

extern "C"
{
	void DMA1_Stream2_IRQHandler(void)
	{
		dmaChannel3.isr();
	}
}
#endif



#if defined(DMA1_Stream3)
static void enableDma1Stream3Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Stream3_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel4Setup
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream3Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma4Setup
{
	(YSS_DMA_Peri*)DMA1,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Stream3	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel4 dmaChannel4(gDrvDmaChannel4Setup, gDma4Setup);

extern "C"
{
	void DMA1_Stream3_IRQHandler(void)
	{
		dmaChannel4.isr();
	}
}
#endif



#if defined(DMA1_Stream4)
static void enableDma1Stream4Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Stream4_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel5Setup
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream4Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma5Setup
{
	(YSS_DMA_Peri*)DMA1,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Stream4	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel5 dmaChannel5(gDrvDmaChannel5Setup, gDma5Setup);

extern "C"
{
	void DMA1_Stream4_IRQHandler(void)
	{
		dmaChannel5.isr();
	}
}



#if defined(DMA1_Stream5)
static void enableDma1Stream5Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Stream5_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel6Setup
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream5Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma6Setup
{
	(YSS_DMA_Peri*)DMA1,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Stream5	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel6 dmaChannel6(gDrvDmaChannel6Setup, gDma6Setup);

extern "C"
{
	void DMA1_Stream5_IRQHandler(void)
	{
		dmaChannel6.isr();
	}
}
#endif



#if defined(DMA1_Stream6)
static void enableDma1Stream6Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Stream6_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel7Setup
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream6Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma7Setup
{
	(YSS_DMA_Peri*)DMA1,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Stream6	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel7 dmaChannel7(gDrvDmaChannel7Setup, gDma7Setup);

extern "C"
{
	void DMA1_Stream6_IRQHandler(void)
	{
		dmaChannel7.isr();
	}
}
#endif



#if defined(DMA1_Stream7)
static void enableDma1Stream7Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Stream7_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel8Setup
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream7Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma8Setup
{
	(YSS_DMA_Peri*)DMA1,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Stream7	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel8 dmaChannel8(gDrvDmaChannel8Setup, gDma8Setup);

extern "C"
{
	void DMA1_Stream7_IRQHandler(void)
	{
		dmaChannel8.isr();
	}
}
#endif


// dma ch9 작성 시작
#if defined(DMA2_Stream0)
static void enableDma2Stream0Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA2_Stream0_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel9Setup
{
	enableDma2Clock,			//void (*clockFunc)(bool en);
	enableDma2Stream0Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma9Setup
{
	(YSS_DMA_Peri*)DMA2,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA2_Stream0	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel9 dmaChannel9(gDrvDmaChannel9Setup, gDma9Setup);

extern "C"
{
	void DMA2_Stream0_IRQHandler(void)
	{
		dmaChannel9.isr();
	}
}
#endif



#if defined(DMA2_Stream1)
static void enableDma2Stream1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA2_Stream1_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel10Setup
{
	enableDma2Clock,			//void (*clockFunc)(bool en);
	enableDma2Stream1Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma10Setup
{
	(YSS_DMA_Peri*)DMA2,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA2_Stream1	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel10 dmaChannel10(gDrvDmaChannel10Setup, gDma10Setup);

extern "C"
{
	void DMA2_Stream1_IRQHandler(void)
	{
		dmaChannel10.isr();
	}
}
#endif



#if defined(DMA2_Stream2)
static void enableDma2Stream2Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA2_Stream2_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel11Setup
{
	enableDma2Clock,			//void (*clockFunc)(bool en);
	enableDma2Stream2Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma11Setup
{
	(YSS_DMA_Peri*)DMA2,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA2_Stream2	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel11 dmaChannel11(gDrvDmaChannel11Setup, gDma11Setup);

extern "C"
{
	void DMA2_Stream2_IRQHandler(void)
	{
		dmaChannel11.isr();
	}
}
#endif



#if defined(DMA2_Stream3)
static void enableDma2Stream3Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA2_Stream3_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel12Setup
{
	enableDma2Clock,			//void (*clockFunc)(bool en);
	enableDma2Stream3Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma12Setup
{
	(YSS_DMA_Peri*)DMA2,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA2_Stream3	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel12 dmaChannel12(gDrvDmaChannel12Setup, gDma12Setup);

extern "C"
{
	void DMA2_Stream3_IRQHandler(void)
	{
		dmaChannel12.isr();
	}
}
#endif



#if defined(DMA2_Stream4)
static void enableDma2Stream4Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA2_Stream4_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel13Setup
{
	enableDma2Clock,			//void (*clockFunc)(bool en);
	enableDma2Stream4Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma13Setup
{
	(YSS_DMA_Peri*)DMA2,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA2_Stream4	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel13 dmaChannel13(gDrvDmaChannel13Setup, gDma13Setup);

extern "C"
{
	void DMA2_Stream4_IRQHandler(void)
	{
		dmaChannel13.isr();
	}
}
#endif



#if defined(DMA2_Stream5)
static void enableDma2Stream5Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA2_Stream5_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel14Setup
{
	enableDma2Clock,			//void (*clockFunc)(bool en);
	enableDma2Stream5Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma14Setup
{
	(YSS_DMA_Peri*)DMA2,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA2_Stream5	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel14 dmaChannel14(gDrvDmaChannel14Setup, gDma14Setup);

extern "C"
{
	void DMA2_Stream5_IRQHandler(void)
	{
		dmaChannel14.isr();
	}
}
#endif



#if defined(DMA2_Stream6)
static void enableDma2Stream6Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA2_Stream6_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel15Setup
{
	enableDma2Clock,			//void (*clockFunc)(bool en);
	enableDma2Stream6Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma15Setup
{
	(YSS_DMA_Peri*)DMA2,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA2_Stream6	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel15 dmaChannel15(gDrvDmaChannel15Setup, gDma15Setup);

extern "C"
{
	void DMA2_Stream6_IRQHandler(void)
	{
		dmaChannel15.isr();
	}
}
#endif



#if defined(DMA2_Stream7)
static void enableDma2Stream7Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA2_Stream7_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel16Setup
{
	enableDma2Clock,			//void (*clockFunc)(bool en);
	enableDma2Stream7Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma16Setup
{
	(YSS_DMA_Peri*)DMA2,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA2_Stream7	//YSS_DMA_Channel_Peri *peri;	
};

DmaChannel16 dmaChannel16(gDrvDmaChannel16Setup, gDma16Setup);

extern "C"
{
	void DMA2_Stream7_IRQHandler(void)
	{
		dmaChannel16.isr();
	}
}
#endif

#endif

#endif




////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(STM32F1_N)

#include <targets/st/bitfield_stm32f103xx.h>

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
    clock.enableAhb1Clock(RCC_AHBENR_DMA1EN_Pos, en);
	clock.unlock();
}

static void enableDma2Clock(bool en)
{
	clock.lock();
    clock.enableAhb1Clock(RCC_AHBENR_DMA2EN_Pos, en);
	clock.unlock();
}

#if defined(DMA1_CHANNEL1) || defined(DMA1_Channel1)
static void enableDma1Channel1Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA1_Channel1_IRQn, en);
    nvic.unlock();
}

const Drv::Config gDrvDmaChannel1Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel1Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma1Config = 
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Channel1	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel1::Config gDmaChannel1 = 
{
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Config, gDma1Config, gDmaChannel1);

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

const Drv::Config gDrvDmaChannel2Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel2Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma2Config = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel2	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel2::Config gDmaChannel2 = 
{
};

DmaChannel2 dmaChannel2(gDrvDmaChannel2Config, gDma2Config, gDmaChannel2);

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

const Drv::Config gDrvDmaChannel3Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel3Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma3Config = 
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Channel3	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel3::Config gDmaChannel3 = 
{
};

DmaChannel3 dmaChannel3(gDrvDmaChannel3Config, gDma3Config, gDmaChannel3);

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

const Drv::Config gDrvDmaChannel4Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel4Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma4Config = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel4	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel4::Config gDmaChannel4 = 
{
};

DmaChannel4 dmaChannel4(gDrvDmaChannel4Config, gDma4Config, gDmaChannel4);

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

const Drv::Config gDrvDmaChannel5Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel5Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma5Config = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel5	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel5::Config gDmaChannel5 = 
{
};

DmaChannel5 dmaChannel5(gDrvDmaChannel5Config, gDma5Config, gDmaChannel5);

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

const Drv::Config gDrvDmaChannel6Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel6Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma6Config = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel6	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel6::Config gDmaChannel6 = 
{
};

DmaChannel6 dmaChannel6(gDrvDmaChannel6Config, gDma6Config, gDmaChannel6);

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

const Drv::Config gDrvDmaChannel7Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel7Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma7Config = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel7	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel7::Config gDmaChannel7 = 
{
};

DmaChannel7 dmaChannel7(gDrvDmaChannel7Config, gDma7Config, gDmaChannel7);

extern "C"
{
	void YSS_DMA1_Channel7_IRQHandler(void)
	{
		dmaChannel7.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL1) || defined(DMA2_Channel1)
static void enableDma2Channel1Interrupt(bool en)
{
    nvic.lock();	
	nvic.enableInterrupt(DMA2_Channel1_IRQn, en);
    nvic.unlock();
}

const Drv::Config gDrvDmaChannel8Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel1Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma8Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel1	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel8::Config gDmaChannel8 = 
{
};

DmaChannel8 dmaChannel8(gDrvDmaChannel8Config, gDma8Config, gDmaChannel8);

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

const Drv::Config gDrvDmaChannel9Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel2Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma9Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel2	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel9::Config gDmaChannel9 = 
{
};

DmaChannel9 dmaChannel9(gDrvDmaChannel9Config, gDma9Config, gDmaChannel9);

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

const Drv::Config gDrvDmaChannel10Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel3Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma10Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel3	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel10::Config gDmaChannel10 = 
{
};

DmaChannel10 dmaChannel10(gDrvDmaChannel10Config, gDma10Config, gDmaChannel10);

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

const Drv::Config gDrvDmaChannel11Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel4Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma11Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel4	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel11::Config gDmaChannel11 = 
{
};

DmaChannel11 dmaChannel11(gDrvDmaChannel11Config, gDma11Config, gDmaChannel11);

#endif



#if defined(DMA2_CHANNEL5) || defined(DMA2_Channel5)
static void enableDma2Channel5Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA2_Channel4_5_IRQn, en);
    nvic.unlock();
}

const Drv::Config gDrvDmaChannel12Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel5Interrupt,	//void (*nvicFunc)(bool en);
	0								//void (*resetFunc)(void);
};

const Dma::Config gDma12Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel5	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel12::Config gDmaChannel12 = 
{
};

DmaChannel12 dmaChannel12(gDrvDmaChannel12Config, gDma12Config, gDmaChannel12);

extern "C"
{
	void YSS_DMA2_Channel4_5_IRQHandler(void)
	{
		uint32_t ifr = DMA2->IFCR;

		if(ifr & (DMA_IFCR_CGIF4_Msk | DMA_IFCR_CTEIF4_Msk))
			dmaChannel11.isr();

		if(ifr & (DMA_IFCR_CGIF5_Msk | DMA_IFCR_CTEIF5_Msk))
			dmaChannel12.isr();
	}
}
#endif

#endif

#endif

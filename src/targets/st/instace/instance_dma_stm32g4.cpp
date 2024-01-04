////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(STM32G4)

#include <targets/st/bitfield.h>

Dma *dmaChannelList[DMA_COUNT] = 
{
	&dmaChannel1, &dmaChannel2, &dmaChannel3, &dmaChannel4, &dmaChannel5, &dmaChannel6, &dmaChannel7, &dmaChannel8, 
	&dmaChannel9, &dmaChannel10, &dmaChannel11, &dmaChannel12, &dmaChannel13, &dmaChannel14, &dmaChannel15, &dmaChannel16, 
};


#if defined(DMA1)
static void enableDma1Clock(bool en)
{
	clock.lock();
    clock.enableAhb1Clock(RCC_AHB1ENR_DMA1EN_Pos, en);
    clock.enableAhb1Clock(RCC_AHB1ENR_DMAMUX1EN_Pos, en);
	clock.unlock();
}

#if defined(DMA1_CHANNEL1) || defined(DMA1_Channel1)
static void enableDma1Channel1Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA1_Channel1_IRQn, en);
    nvic.unlock();
}

const Drv::Setup_t gDrvDmaChannel1Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel1Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma1Config = 
{
	DMA1,				// YSS_DMA_Peri *dma;
	DMA1_Channel1,		// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel0	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Config, gDma1Config);

extern "C"
{
	void DMA1_Channel1_IRQHandler(void)
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

const Drv::Setup_t gDrvDmaChannel2Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel2Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma2Config = 
{
	DMA1,				//YSS_DMA_Peri *dma;
	DMA1_Channel2,		// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel1	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel2 dmaChannel2(gDrvDmaChannel2Config, gDma2Config);

extern "C"
{
	void DMA1_Channel2_IRQHandler(void)
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

const Drv::Setup_t gDrvDmaChannel3Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel3Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma3Config = 
{
	DMA1,				//YSS_DMA_Peri *dma;
	DMA1_Channel3,		// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel2	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel3 dmaChannel3(gDrvDmaChannel3Config, gDma3Config);

extern "C"
{
	void DMA1_Channel3_IRQHandler(void)
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

const Drv::Setup_t gDrvDmaChannel4Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel4Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma4Config = 
{
	DMA1,				// YSS_DMA_Peri *dma;
	DMA1_Channel4,		// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel3	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel4 dmaChannel4(gDrvDmaChannel4Config, gDma4Config);

extern "C"
{
	void DMA1_Channel4_IRQHandler(void)
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

const Drv::Setup_t gDrvDmaChannel5Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel5Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma5Config = 
{
	DMA1,	//YSS_DMA_Peri *dma;
	DMA1_Channel5,	//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel4	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel5 dmaChannel5(gDrvDmaChannel5Config, gDma5Config);

extern "C"
{
	void DMA1_Channel5_IRQHandler(void)
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

const Drv::Setup_t gDrvDmaChannel6Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel6Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma6Config = 
{
	DMA1,				// YSS_DMA_Peri *dma;
	DMA1_Channel6,		// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel5	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel6 dmaChannel6(gDrvDmaChannel6Config, gDma6Config);

extern "C"
{
	void DMA1_Channel6_IRQHandler(void)
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

const Drv::Setup_t gDrvDmaChannel7Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel7Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma7Config = 
{
	DMA1,				// YSS_DMA_Peri *dma;
	DMA1_Channel7,		// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel6	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel7 dmaChannel7(gDrvDmaChannel7Config, gDma7Config);

extern "C"
{
	void DMA1_Channel7_IRQHandler(void)
	{
		dmaChannel7.isr();
	}
}
#endif



#if defined(DMA1_CHANNEL8) || defined(DMA1_Channel8)
static void enableDma1Channel8Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA1_Channel8_IRQn, en);
    nvic.unlock();
}

const Drv::Setup_t gDrvDmaChannel8Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel8Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma8Config = 
{
	DMA1,				// YSS_DMA_Peri *dma;
	DMA1_Channel8,		// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel7	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel8 dmaChannel8(gDrvDmaChannel8Config, gDma8Config);

extern "C"
{
	void DMA1_Channel8_IRQHandler(void)
	{
		dmaChannel8.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL1) || defined(DMA2_Channel1)
static void enableDma2Clock(bool en)
{
	clock.lock();
    clock.enableAhb1Clock(RCC_AHB1ENR_DMA2EN_Pos, en);
	clock.unlock();
}

static void enableDma2Channel1Interrupt(bool en)
{
    nvic.lock();	
	nvic.enableInterrupt(DMA2_Channel1_IRQn, en);
    nvic.unlock();
}

const Drv::Setup_t gDrvDmaChannel9Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel1Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma9Config = 
{
	DMA2,				//YSS_DMA_Peri *dma;
	DMA2_Channel1,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel8	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel9 dmaChannel9(gDrvDmaChannel9Config, gDma9Config);

extern "C"
{
	void DMA2_Channel1_IRQHandler(void)
	{
		dmaChannel9.isr();
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

const Drv::Setup_t gDrvDmaChannel10Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel2Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma10Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel2,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel9	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel10 dmaChannel10(gDrvDmaChannel10Config, gDma10Config);

extern "C"
{
	void DMA2_Channel2_IRQHandler(void)
	{
		dmaChannel10.isr();
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

const Drv::Setup_t gDrvDmaChannel11Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel3Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma11Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel3,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel10	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel11 dmaChannel11(gDrvDmaChannel11Config, gDma11Config);

extern "C"
{
	void DMA2_Channel3_IRQHandler(void)
	{
		dmaChannel11.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL4) || defined(DMA2_Channel4)
static void enableDma2Channel4Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA2_Channel4_IRQn, en);
    nvic.unlock();
}

const Drv::Setup_t gDrvDmaChannel12Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel4Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma12Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel4,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel11	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel12 dmaChannel12(gDrvDmaChannel12Config, gDma12Config);

extern "C"
{
	void DMA2_Channel4_IRQHandler(void)
	{
		dmaChannel12.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL5) || defined(DMA2_Channel5)
static void enableDma2Channel5Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA2_Channel5_IRQn, en);
    nvic.unlock();
}

const Drv::Setup_t gDrvDmaChannel13Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel5Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma13Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel5,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel12	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel13 dmaChannel13(gDrvDmaChannel13Config, gDma13Config);

extern "C"
{
	void DMA2_Channel5_IRQHandler(void)
	{
		dmaChannel13.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL6) || defined(DMA2_Channel6)
static void enableDma2Channel6Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA2_Channel6_IRQn, en);
    nvic.unlock();
}

const Drv::Setup_t gDrvDmaChannel14Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel6Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma14Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel6,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel13	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel14 dmaChannel14(gDrvDmaChannel14Config, gDma14Config);

extern "C"
{
	void DMA2_Channel6_IRQHandler(void)
	{
		dmaChannel14.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL7) || defined(DMA2_Channel7)
static void enableDma2Channel7Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA2_Channel7_IRQn, en);
    nvic.unlock();
}

const Drv::Setup_t gDrvDmaChannel15Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel7Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma15Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel7,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel14	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel15 dmaChannel15(gDrvDmaChannel15Config, gDma15Config);

extern "C"
{
	void DMA2_Channel7_IRQHandler(void)
	{
		dmaChannel15.isr();
	}
}
#endif



#if defined(DMA2_CHANNEL8) || defined(DMA2_Channel8)
static void enableDma2Channel8Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA2_Channel8_IRQn, en);
    nvic.unlock();
}

const Drv::Setup_t gDrvDmaChannel16Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel8Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::Setup_t gDma16Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Channel8,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel15	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel16 dmaChannel16(gDrvDmaChannel16Config, gDma16Config);

extern "C"
{
	void DMA2_Channel8_IRQHandler(void)
	{
		dmaChannel16.isr();
	}
}
#endif

#endif

#endif

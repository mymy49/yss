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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(STM32G4)

#include <targets/st/bitfield.h>

#if defined(STM32G431xx)
Dma *dmaChannelList[DMA_COUNT] = 
{
	&dmaChannel1, &dmaChannel2, &dmaChannel3, &dmaChannel4, &dmaChannel5, &dmaChannel6, &dmaChannel7, &dmaChannel8, 
	&dmaChannel9, &dmaChannel10, &dmaChannel11, &dmaChannel12,
};

#define DMA_CH1			DMA1_Channel1
#define DMA_CH2			DMA1_Channel2
#define DMA_CH3			DMA1_Channel3
#define DMA_CH4			DMA1_Channel4
#define DMA_CH5			DMA1_Channel5
#define DMA_CH6			DMA1_Channel6
#define DMA_CH7			DMA2_Channel1
#define DMA_CH8			DMA2_Channel2
#define DMA_CH9			DMA2_Channel3
#define DMA_CH10		DMA2_Channel4
#define DMA_CH11		DMA2_Channel5
#define DMA_CH12		DMA2_Channel6

#define DMA_IRQ1		DMA1_Channel1_IRQn
#define DMA_IRQ2		DMA1_Channel2_IRQn
#define DMA_IRQ3		DMA1_Channel3_IRQn
#define DMA_IRQ4		DMA1_Channel4_IRQn
#define DMA_IRQ5		DMA1_Channel5_IRQn
#define DMA_IRQ6		DMA1_Channel6_IRQn
#define DMA_IRQ7		DMA2_Channel1_IRQn
#define DMA_IRQ8		DMA2_Channel2_IRQn
#define DMA_IRQ9		DMA2_Channel3_IRQn
#define DMA_IRQ10		DMA2_Channel4_IRQn
#define DMA_IRQ11		DMA2_Channel5_IRQn
#define DMA_IRQ12		DMA2_Channel6_IRQn

#define DMA_ISR1		DMA1_Channel1_IRQHandler
#define DMA_ISR2		DMA1_Channel2_IRQHandler
#define DMA_ISR3		DMA1_Channel3_IRQHandler
#define DMA_ISR4		DMA1_Channel4_IRQHandler
#define DMA_ISR5		DMA1_Channel5_IRQHandler
#define DMA_ISR6		DMA1_Channel6_IRQHandler
#define DMA_ISR7		DMA2_Channel1_IRQHandler
#define DMA_ISR8		DMA2_Channel2_IRQHandler
#define DMA_ISR9		DMA2_Channel3_IRQHandler
#define DMA_ISR10		DMA2_Channel4_IRQHandler
#define DMA_ISR11		DMA2_Channel5_IRQHandler
#define DMA_ISR12		DMA2_Channel6_IRQHandler

#elif defined(STM32G474xx)
Dma *dmaChannelList[DMA_COUNT] = 
{
	&dmaChannel1, &dmaChannel2, &dmaChannel3, &dmaChannel4, &dmaChannel5, &dmaChannel6, &dmaChannel7, &dmaChannel8, 
	&dmaChannel9, &dmaChannel10, &dmaChannel11, &dmaChannel12, &dmaChannel13, &dmaChannel14, &dmaChannel15, &dmaChannel16, 
};

#define DMA_CH1			DMA1_Channel1
#define DMA_CH2			DMA1_Channel2
#define DMA_CH3			DMA1_Channel3
#define DMA_CH4			DMA1_Channel4
#define DMA_CH5			DMA1_Channel5
#define DMA_CH6			DMA1_Channel6
#define DMA_CH7			DMA1_Channel7
#define DMA_CH8			DMA1_Channel8
#define DMA_CH9			DMA2_Channel1
#define DMA_CH10		DMA2_Channel2
#define DMA_CH11		DMA2_Channel3
#define DMA_CH12		DMA2_Channel4
#define DMA_CH13		DMA2_Channel5
#define DMA_CH14		DMA2_Channel6
#define DMA_CH15		DMA2_Channel7
#define DMA_CH16		DMA2_Channel8

#define DMA_IRQ1		DMA1_Channel1_IRQn
#define DMA_IRQ2		DMA1_Channel2_IRQn
#define DMA_IRQ3		DMA1_Channel3_IRQn
#define DMA_IRQ4		DMA1_Channel4_IRQn
#define DMA_IRQ5		DMA1_Channel5_IRQn
#define DMA_IRQ6		DMA1_Channel6_IRQn
#define DMA_IRQ7		DMA1_Channel7_IRQn
#define DMA_IRQ8		DMA1_Channel8_IRQn
#define DMA_IRQ9		DMA2_Channel1_IRQn
#define DMA_IRQ10		DMA2_Channel2_IRQn
#define DMA_IRQ11		DMA2_Channel3_IRQn
#define DMA_IRQ12		DMA2_Channel4_IRQn
#define DMA_IRQ13		DMA2_Channel5_IRQn
#define DMA_IRQ14		DMA2_Channel6_IRQn
#define DMA_IRQ15		DMA2_Channel7_IRQn
#define DMA_IRQ16		DMA2_Channel8_IRQn

#define DMA_ISR1		DMA1_Channel1_IRQHandler
#define DMA_ISR2		DMA1_Channel2_IRQHandler
#define DMA_ISR3		DMA1_Channel3_IRQHandler
#define DMA_ISR4		DMA1_Channel4_IRQHandler
#define DMA_ISR5		DMA1_Channel5_IRQHandler
#define DMA_ISR6		DMA1_Channel6_IRQHandler
#define DMA_ISR7		DMA1_Channel7_IRQHandler
#define DMA_ISR8		DMA1_Channel8_IRQHandler
#define DMA_ISR9		DMA2_Channel1_IRQHandler
#define DMA_ISR10		DMA2_Channel2_IRQHandler
#define DMA_ISR11		DMA2_Channel3_IRQHandler
#define DMA_ISR12		DMA2_Channel4_IRQHandler
#define DMA_ISR13		DMA2_Channel5_IRQHandler
#define DMA_ISR14		DMA2_Channel6_IRQHandler
#define DMA_ISR15		DMA2_Channel7_IRQHandler
#define DMA_ISR16		DMA2_Channel8_IRQHandler
#endif

#if defined(DMA1)
static void enableDma1Clock(bool en)
{
	clock.lock();
    clock.enableAhb1Clock(RCC_AHB1ENR_DMA1EN_Pos, en);
    clock.enableAhb1Clock(RCC_AHB1ENR_DMAMUX1EN_Pos, en);
	clock.unlock();
}

#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableInterrupt1(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ1, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel1Config = 
{
	enableDma1Clock,	//void (*clockFunc)(bool en);
	enableInterrupt1,	//void (*nvicFunc)(bool en);
	0,					//void (*resetFunc)(void);
	0					//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma1Config = 
{
	DMA1,				// YSS_DMA_Peri *dma;
	DMA_CH1,			// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel0	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Config, gDma1Config);

extern "C"
{
	void DMA_ISR1(void)
	{
		dmaChannel1.isr();
	}
}
#endif



#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableInterrupt2(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ2, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel2Config = 
{
	enableDma1Clock,	//void (*clockFunc)(bool en);
	enableInterrupt2,	//void (*nvicFunc)(bool en);
	0,					//void (*resetFunc)(void);
	0					//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma2Config = 
{
	DMA1,				//YSS_DMA_Peri *dma;
	DMA_CH2,			// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel1	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel2 dmaChannel2(gDrvDmaChannel2Config, gDma2Config);

extern "C"
{
	void DMA_ISR2(void)
	{
		dmaChannel2.isr();
	}
}
#endif



#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableInterrupt3(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ3, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel3Config = 
{
	enableDma1Clock,	//void (*clockFunc)(bool en);
	enableInterrupt3,	//void (*nvicFunc)(bool en);
	0,					//void (*resetFunc)(void);
	0					//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma3Config = 
{
	DMA1,				//YSS_DMA_Peri *dma;
	DMA_CH3,			// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel2	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel3 dmaChannel3(gDrvDmaChannel3Config, gDma3Config);

extern "C"
{
	void DMA_ISR3(void)
	{
		dmaChannel3.isr();
	}
}
#endif



#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableDma1Channel4Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ4, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel4Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel4Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma4Config = 
{
	DMA1,				// YSS_DMA_Peri *dma;
	DMA_CH4,			// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel3	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel4 dmaChannel4(gDrvDmaChannel4Config, gDma4Config);

extern "C"
{
	void DMA_ISR4(void)
	{
		dmaChannel4.isr();
	}
}
#endif



#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableDma1Channel5Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ5, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel5Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel5Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma5Config = 
{
	DMA1,				//YSS_DMA_Peri *dma;
	DMA_CH5,			//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel4	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel5 dmaChannel5(gDrvDmaChannel5Config, gDma5Config);

extern "C"
{
	void DMA_ISR5(void)
	{
		dmaChannel5.isr();
	}
}
#endif



#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableDma1Channel6Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ6, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel6Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel6Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma6Config = 
{
	DMA1,				// YSS_DMA_Peri *dma;
	DMA_CH6,			// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel5	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel6 dmaChannel6(gDrvDmaChannel6Config, gDma6Config);

extern "C"
{
	void DMA_ISR6(void)
	{
		dmaChannel6.isr();
	}
}
#endif


#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableDma1Channel7Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ7, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel7Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel7Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma7Config = 
{
	DMA1,				// YSS_DMA_Peri *dma;
	DMA_CH7,		// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel6	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel7 dmaChannel7(gDrvDmaChannel7Config, gDma7Config);

extern "C"
{
	void DMA_ISR7(void)
	{
		dmaChannel7.isr();
	}
}
#endif



#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableDma1Channel8Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ8, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel8Config = 
{
	enableDma1Clock,				//void (*clockFunc)(bool en);
	enableDma1Channel8Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma8Config = 
{
	DMA1,				// YSS_DMA_Peri *dma;
	DMA_CH8,			// YSS_DMA_Channel_Peri *peri;
	DMAMUX1_Channel7	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel8 dmaChannel8(gDrvDmaChannel8Config, gDma8Config);

extern "C"
{
	void DMA_ISR8(void)
	{
		dmaChannel8.isr();
	}
}
#endif



#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableDma2Clock(bool en)
{
	clock.lock();
    clock.enableAhb1Clock(RCC_AHB1ENR_DMA2EN_Pos, en);
	clock.unlock();
}

static void enableDma2Channel1Interrupt(bool en)
{
    nvic.lock();	
	nvic.enableInterrupt(DMA_IRQ9, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel9Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel1Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma9Config = 
{
	DMA2,				//YSS_DMA_Peri *dma;
	DMA_CH9,			//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel8	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel9 dmaChannel9(gDrvDmaChannel9Config, gDma9Config);

extern "C"
{
	void DMA_ISR9(void)
	{
		dmaChannel9.isr();
	}
}
#endif



#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableDma2Channel2Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ10, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel10Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel2Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma10Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA_CH10,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel9	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel10 dmaChannel10(gDrvDmaChannel10Config, gDma10Config);

extern "C"
{
	void DMA_ISR10(void)
	{
		dmaChannel10.isr();
	}
}
#endif



#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableDma2Channel3Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ11, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel11Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel3Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma11Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA_CH11,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel10	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel11 dmaChannel11(gDrvDmaChannel11Config, gDma11Config);

extern "C"
{
	void DMA_ISR11(void)
	{
		dmaChannel11.isr();
	}
}
#endif



#if defined(STM32G431xx) || defined(STM32G474xx)
static void enableDma2Channel4Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ12, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel12Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel4Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma12Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA_CH12,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel11	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel12 dmaChannel12(gDrvDmaChannel12Config, gDma12Config);

extern "C"
{
	void DMA_ISR12(void)
	{
		dmaChannel12.isr();
	}
}
#endif



#if defined(STM32G474xx)
static void enableDma2Channel5Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ13, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel13Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel5Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma13Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA_CH13,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel12	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel13 dmaChannel13(gDrvDmaChannel13Config, gDma13Config);

extern "C"
{
	void DMA_ISR13(void)
	{
		dmaChannel13.isr();
	}
}
#endif



#if defined(STM32G474xx)
static void enableDma2Channel6Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ14, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel14Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel6Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma14Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA_CH14,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel13	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel14 dmaChannel14(gDrvDmaChannel14Config, gDma14Config);

extern "C"
{
	void DMA_ISR14(void)
	{
		dmaChannel14.isr();
	}
}
#endif



#if defined(STM32G474xx)
static void enableDma2Channel7Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ15, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel15Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel7Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma15Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA_CH15,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel14	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel15 dmaChannel15(gDrvDmaChannel15Config, gDma15Config);

extern "C"
{
	void DMA_ISR15(void)
	{
		dmaChannel15.isr();
	}
}
#endif



#if defined(STM32G474xx)
static void enableDma2Channel8Interrupt(bool en)
{
    nvic.lock();
	nvic.enableInterrupt(DMA_IRQ16, en);
    nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel16Config = 
{
	enableDma2Clock,				//void (*clockFunc)(bool en);
	enableDma2Channel8Interrupt,	//void (*nvicFunc)(bool en);
	0,								//void (*resetFunc)(void);
	0								//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma16Config = 
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA_CH16,		//YSS_DMA_Channel_Peri *peri;	
	DMAMUX1_Channel15	// YSS_DMAMUX_Channel_Peri *dmamux;
};

DmaChannel16 dmaChannel16(gDrvDmaChannel16Config, gDma16Config);

extern "C"
{
	void DMA_ISR16(void)
	{
		dmaChannel16.isr();
	}
}
#endif

#endif

#endif

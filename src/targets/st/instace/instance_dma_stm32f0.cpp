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

#if defined(STM32F0_N)

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

const Drv::Config gDrvDmaChannel1Config = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream0Interrupt,	//void (*nvicFunc)(bool en);
	0							//void (*resetFunc)(void);
};

const Dma::Config gDma1Config = 
{
	(YSS_DMA_Peri*)DMA1,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Channel1	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel1::Config gDmaChannel1 = 
{
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Config, gDma1Config, gDmaChannel1);

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

const Drv::Config gDrvDmaChannel2Config = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream1Interrupt,	//void (*nvicFunc)(bool en);
	0							//void (*resetFunc)(void);
};

const Dma::Config gDma2Config = 
{
	(YSS_DMA_Peri*)DMA1,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Channel2	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel2::Config gDmaChannel2 = 
{
};

DmaChannel2 dmaChannel2(gDrvDmaChannel2Config, gDma2Config, gDmaChannel2);



static void enableDma1Stream2Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Ch2_3_DMA2_Ch1_2_IRQn, en);
	nvic.unlock();
}

const Drv::Config gDrvDmaChannel3Config = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream2Interrupt,	//void (*nvicFunc)(bool en);
	0							//void (*resetFunc)(void);
};

const Dma::Config gDma3Config = 
{
	(YSS_DMA_Peri*)DMA1,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Channel3	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel3::Config gDmaChannel3 = 
{
};

DmaChannel3 dmaChannel3(gDrvDmaChannel3Config, gDma3Config, gDmaChannel3);

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

const Drv::Config gDrvDmaChannel4Config = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream3Interrupt,	//void (*nvicFunc)(bool en);
	0							//void (*resetFunc)(void);
};

const Dma::Config gDma4Config = 
{
	(YSS_DMA_Peri*)DMA1,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Channel4	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel4::Config gDmaChannel4 = 
{
};

DmaChannel4 dmaChannel4(gDrvDmaChannel4Config, gDma4Config, gDmaChannel4);



static void enableDma1Stream4Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA1_Ch4_7_DMA2_Ch3_5_IRQn, en);
	nvic.unlock();
}

const Drv::Config gDrvDmaChannel5Config = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream4Interrupt,	//void (*nvicFunc)(bool en);
	0							//void (*resetFunc)(void);
};

const Dma::Config gDma5Config = 
{
	(YSS_DMA_Peri*)DMA1,				//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)DMA1_Channel5	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel5::Config gDmaChannel5 = 
{
};

DmaChannel5 dmaChannel5(gDrvDmaChannel5Config, gDma5Config, gDmaChannel5);

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





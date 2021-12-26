////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2021.02.11 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(STM32F4) || defined(STM32F7)

static void setDmaClockEn(bool en)
{
	clock.peripheral.setDmaEn(en);
}

static void setDma1IntEn(bool en)
{
#if defined(DMA1_Stream0)
	nvic.setDma1Stream0En(en);
#endif
#if defined(DMA1_Stream1)
	nvic.setDma1Stream1En(en);
#endif
#if defined(DMA1_Stream2)
	nvic.setDma1Stream2En(en);
#endif
#if defined(DMA1_Stream3)
	nvic.setDma1Stream3En(en);
#endif
#if defined(DMA1_Stream4)
	nvic.setDma1Stream4En(en);
#endif
#if defined(DMA1_Stream5)
	nvic.setDma1Stream5En(en);
#endif
#if defined(DMA1_Stream6)
	nvic.setDma1Stream6En(en);
#endif
#if defined(DMA1_Stream7)
	nvic.setDma1Stream7En(en);
#endif

#if defined(DMA2_Stream0)
	nvic.setDma2Stream0En(en);
#endif
#if defined(DMA2_Stream1)
	nvic.setDma2Stream1En(en);
#endif
#if defined(DMA2_Stream2)
	nvic.setDma2Stream2En(en);
#endif
#if defined(DMA2_Stream3)
	nvic.setDma2Stream3En(en);
#endif
#if defined(DMA2_Stream4)
	nvic.setDma2Stream4En(en);
#endif
#if defined(DMA2_Stream5)
	nvic.setDma2Stream5En(en);
#endif
#if defined(DMA2_Stream6)
	nvic.setDma2Stream6En(en);
#endif
#if defined(DMA2_Stream7)
	nvic.setDma2Stream7En(en);
#endif
}

//static const Drv::Config gDmaDrvConfig
//{
//	setDmaClockEn,		//void (*clockFunc)(bool en) = 0;
//	setDmaIntEn,		//void (*nvicFunc)(bool en) = 0;
//	0					//void (*resetFunc)(void) = 0;
//};

//static const drv::Dma::Config gDmaConfig = 
//{
//	DMA1,
//	DMA2
//};

//drv::Dma dma(gDmaDrvConfig, gDmaConfig);



#if defined(DMA1_Stream0)
static void setDma1Stream0IntEn(bool en)
{
	nvic.setDma1Stream0En(en);
}

drv::Stream dma1Stream0(DMA1, DMA1_Stream0, 0, setDma1Stream0IntEn, 0);

const Drv::Config gDrvDmaChannel0Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream0IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma1Config
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Stream0	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel1::Config gDma1Channel1
{
};

drv::DmaChannel1 dmaChannel1(gDrvDmaChannel0Config, gDma1Config, gDma1Channel1);

extern "C"
{

#if defined(STM32F7) || defined(STM32F4)
	void DMA1_Stream0_IRQHandler(void)
	{
		dma1Stream0.isr0();
	}
#endif
}
#endif



#if defined(DMA1_Stream1)
static void setDma1Stream1IntEn(bool en)
{
	nvic.setDma1Stream1En(en);
}

drv::Stream dma1Stream1(DMA1, DMA1_Stream1, 0, setDma1Stream1IntEn, 1);

extern "C"
{
	void DMA1_Stream1_IRQHandler(void)
	{
		dma1Stream1.isr1();
	}
}
#endif



#if defined(DMA1_Stream2)
static void setDma1Stream2IntEn(bool en)
{
	nvic.setDma1Stream2En(en);
}

drv::Stream dma1Stream2(DMA1, DMA1_Stream2, 0, setDma1Stream2IntEn, 2);

extern "C"
{
	void DMA1_Stream2_IRQHandler(void)
	{
		dma1Stream2.isr2();
	}
}
#endif



#if defined(DMA1_Stream3)
static void setDma1Stream3IntEn(bool en)
{
	nvic.setDma1Stream3En(en);
}

drv::Stream dma1Stream3(DMA1, DMA1_Stream3, 0, setDma1Stream3IntEn, 3);

extern "C"
{
	void DMA1_Stream3_IRQHandler(void)
	{
		dma1Stream3.isr3();
	}
}
#endif



#if defined(DMA1_Stream4)
static void setDma1Stream4IntEn(bool en)
{
	nvic.setDma1Stream4En(en);
}

drv::Stream dma1Stream4(DMA1, DMA1_Stream4, 0, setDma1Stream4IntEn, 4);

extern "C"
{
	void DMA1_Stream4_IRQHandler(void)
	{
		dma1Stream4.isr4();
	}
}



#if defined(DMA1_Stream5)
static void setDma1Stream5IntEn(bool en)
{
	nvic.setDma1Stream5En(en);
}

drv::Stream dma1Stream5(DMA1, DMA1_Stream5, 0, setDma1Stream5IntEn, 5);

extern "C"
{
	void DMA1_Stream5_IRQHandler(void)
	{
		dma1Stream5.isr5();
	}
}
#endif



#if defined(DMA1_Stream6)
static void setDma1Stream6IntEn(bool en)
{
	nvic.setDma1Stream6En(en);
}

drv::Stream dma1Stream6(DMA1, DMA1_Stream6, 0, setDma1Stream6IntEn, 6);

extern "C"
{
	void DMA1_Stream6_IRQHandler(void)
	{
		dma1Stream6.isr6();
	}
}
#endif



#if defined(DMA1_Stream7)
static void setDma1Stream7IntEn(bool en)
{
	nvic.setDma1Stream7En(en);
}

drv::Stream dma1Stream7(DMA1, DMA1_Stream7, 0, setDma1Stream7IntEn, 7);

extern "C"
{
	void DMA1_Stream7_IRQHandler(void)
	{
		dma1Stream7.isr7();
	}
}
#endif



#if defined(DMA2_Stream0)
static void setDma2Stream0IntEn(bool en)
{
	nvic.setDma2Stream0En(en);
}

drv::Stream dma2Stream0(DMA2, DMA2_Stream0, 0, setDma2Stream0IntEn, 0);

extern "C"
{
	void DMA2_Stream0_IRQHandler(void)
	{
		dma2Stream0.isr0();
	}
}
#endif



#if defined(DMA2_Stream1)
static void setDma2Stream1IntEn(bool en)
{
	nvic.setDma2Stream1En(en);
}

drv::Stream dma2Stream1(DMA2, DMA2_Stream1, 0, setDma2Stream1IntEn, 1);

extern "C"
{
	void DMA2_Stream1_IRQHandler(void)
	{
		dma2Stream1.isr1();
	}
}
#endif



#if defined(DMA2_Stream2)
static void setDma2Stream2IntEn(bool en)
{
	nvic.setDma2Stream2En(en);
}

drv::Stream dma2Stream2(DMA2, DMA2_Stream2, 0, setDma2Stream2IntEn, 2);

extern "C"
{
	void DMA2_Stream2_IRQHandler(void)
	{
		dma2Stream2.isr2();
	}
}
#endif



#if defined(DMA2_Stream3)
static void setDma2Stream3IntEn(bool en)
{
	nvic.setDma2Stream3En(en);
}

drv::Stream dma2Stream3(DMA2, DMA2_Stream3, 0, setDma2Stream3IntEn, 3);

extern "C"
{
	void DMA2_Stream3_IRQHandler(void)
	{
		dma2Stream3.isr3();
	}
}
#endif



#if defined(DMA2_Stream4)
static void setDma2Stream4IntEn(bool en)
{
	nvic.setDma2Stream4En(en);
}

drv::Stream dma2Stream4(DMA2, DMA2_Stream4, 0, setDma2Stream4IntEn, 4);

extern "C"
{
	void DMA2_Stream4_IRQHandler(void)
	{
		dma2Stream4.isr4();
	}
}
#endif



#if defined(DMA2_Stream5)
static void setDma2Stream5IntEn(bool en)
{
	nvic.setDma2Stream5En(en);
}

drv::Stream dma2Stream5(DMA2, DMA2_Stream5, 0, setDma2Stream5IntEn, 5);

extern "C"
{
	void DMA2_Stream5_IRQHandler(void)
	{
		dma2Stream5.isr5();
	}
}
#endif



#if defined(DMA2_Stream6)
static void setDma2Stream6IntEn(bool en)
{
	nvic.setDma2Stream6En(en);
}

drv::Stream dma2Stream6(DMA2, DMA2_Stream6, 0, setDma2Stream6IntEn, 6);

extern "C"
{
	void DMA2_Stream6_IRQHandler(void)
	{
		dma2Stream6.isr6();
	}
}
#endif



#if defined(DMA2_Stream7)
static void setDma2Stream7IntEn(bool en)
{
	nvic.setDma2Stream7En(en);
}

drv::Stream dma2Stream7(DMA2, DMA2_Stream7, 0, setDma2Stream7IntEn, 7);

extern "C"
{
	void DMA2_Stream7_IRQHandler(void)
	{
		dma2Stream7.isr7();
	}
}
#endif

#endif

#endif




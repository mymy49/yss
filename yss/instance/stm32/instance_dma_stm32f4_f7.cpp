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



#if defined(DMA1_Stream0)
static void setDma1Stream0IntEn(bool en)
{
	nvic.setDmaChannel1En(en);
}

drv::Stream dma1Stream0(DMA1, DMA1_Stream0, 0, setDma1Stream0IntEn, 0);

const Drv::Config gDrvDmaChannel1Config
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

const drv::DmaChannel1::Config gDmaChannel1
{
};

drv::DmaChannel1 dmaChannel1(gDrvDmaChannel1Config, gDma1Config, gDmaChannel1);

extern "C"
{
	void DMA1_Stream0_IRQHandler(void)
	{
		dmaChannel1.isr();
	}
}
#endif



#if defined(DMA1_Stream1)
static void setDma1Stream1IntEn(bool en)
{
	nvic.setDmaChannel2En(en);
}

drv::Stream dma1Stream1(DMA1, DMA1_Stream1, 0, setDma1Stream1IntEn, 1);

const Drv::Config gDrvDmaChannel2Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream1IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma2Config
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Stream1	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel2::Config gDmaChannel2
{
};

drv::DmaChannel2 dmaChannel2(gDrvDmaChannel2Config, gDma2Config, gDmaChannel2);

extern "C"
{
	void DMA1_Stream1_IRQHandler(void)
	{
		dmaChannel2.isr();
	}
}
#endif



#if defined(DMA1_Stream2)
static void setDma1Stream2IntEn(bool en)
{
	nvic.setDmaChannel3En(en);
}

drv::Stream dma1Stream2(DMA1, DMA1_Stream2, 0, setDma1Stream2IntEn, 2);

const Drv::Config gDrvDmaChannel3Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream2IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma3Config
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Stream2	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel3::Config gDmaChannel3
{
};

drv::DmaChannel3 dmaChannel3(gDrvDmaChannel3Config, gDma3Config, gDmaChannel3);

extern "C"
{
	void DMA1_Stream2_IRQHandler(void)
	{
		dmaChannel3.isr();
	}
}
#endif



#if defined(DMA1_Stream3)
static void setDma1Stream3IntEn(bool en)
{
	nvic.setDmaChannel4En(en);
}

drv::Stream dma1Stream3(DMA1, DMA1_Stream3, 0, setDma1Stream3IntEn, 3);

const Drv::Config gDrvDmaChannel4Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream3IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma4Config
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Stream3	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel4::Config gDmaChannel4
{
};

drv::DmaChannel4 dmaChannel4(gDrvDmaChannel4Config, gDma4Config, gDmaChannel4);

extern "C"
{
	void DMA1_Stream3_IRQHandler(void)
	{
		dmaChannel4.isr();
	}
}
#endif



#if defined(DMA1_Stream4)
static void setDma1Stream4IntEn(bool en)
{
	nvic.setDmaChannel5En(en);
}

drv::Stream dma1Stream4(DMA1, DMA1_Stream4, 0, setDma1Stream4IntEn, 4);

const Drv::Config gDrvDmaChannel5Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream4IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma5Config
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Stream4	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel5::Config gDmaChannel5
{
};

drv::DmaChannel5 dmaChannel5(gDrvDmaChannel5Config, gDma5Config, gDmaChannel5);

extern "C"
{
	void DMA1_Stream4_IRQHandler(void)
	{
		dmaChannel5.isr();
	}
}



#if defined(DMA1_Stream5)
static void setDma1Stream5IntEn(bool en)
{
	nvic.setDmaChannel6En(en);
}

drv::Stream dma1Stream5(DMA1, DMA1_Stream5, 0, setDma1Stream5IntEn, 5);

const Drv::Config gDrvDmaChannel6Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream5IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma6Config
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Stream5	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel6::Config gDmaChannel6
{
};

drv::DmaChannel6 dmaChannel6(gDrvDmaChannel6Config, gDma6Config, gDmaChannel6);

extern "C"
{
	void DMA1_Stream5_IRQHandler(void)
	{
		dmaChannel6.isr();
	}
}
#endif



#if defined(DMA1_Stream6)
static void setDma1Stream6IntEn(bool en)
{
	nvic.setDmaChannel7En(en);
}

drv::Stream dma1Stream6(DMA1, DMA1_Stream6, 0, setDma1Stream6IntEn, 6);

const Drv::Config gDrvDmaChannel7Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream6IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma7Config
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Stream6	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel7::Config gDmaChannel7
{
};

drv::DmaChannel7 dmaChannel7(gDrvDmaChannel7Config, gDma7Config, gDmaChannel7);

extern "C"
{
	void DMA1_Stream6_IRQHandler(void)
	{
		dmaChannel7.isr();
	}
}
#endif



#if defined(DMA1_Stream7)
static void setDma1Stream7IntEn(bool en)
{
	nvic.setDmaChannel8En(en);
}

drv::Stream dma1Stream7(DMA1, DMA1_Stream7, 0, setDma1Stream7IntEn, 7);


const Drv::Config gDrvDmaChannel8Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream7IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma8Config
{
	DMA1,			//YSS_DMA_Peri *dma;
	DMA1_Stream7	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel8::Config gDmaChannel8
{
};

drv::DmaChannel8 dmaChannel8(gDrvDmaChannel8Config, gDma8Config, gDmaChannel8);

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
static void setDma2Stream0IntEn(bool en)
{
	nvic.setDmaChannel9En(en);
}

drv::Stream dma2Stream0(DMA2, DMA2_Stream0, 0, setDma2Stream0IntEn, 0);

const Drv::Config gDrvDmaChannel9Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream0IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma9Config
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Stream0	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel9::Config gDmaChannel9
{
};

drv::DmaChannel9 dmaChannel9(gDrvDmaChannel9Config, gDma9Config, gDmaChannel9);

extern "C"
{
	void DMA2_Stream0_IRQHandler(void)
	{
		dmaChannel9.isr();
	}
}
#endif



#if defined(DMA2_Stream1)
static void setDma2Stream1IntEn(bool en)
{
	nvic.setDmaChannel10En(en);
}

drv::Stream dma2Stream1(DMA2, DMA2_Stream1, 0, setDma2Stream1IntEn, 1);

const Drv::Config gDrvDmaChannel10Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream1IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma10Config
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Stream1	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel10::Config gDmaChannel10
{
};

drv::DmaChannel10 dmaChannel10(gDrvDmaChannel10Config, gDma10Config, gDmaChannel10);

extern "C"
{
	void DMA2_Stream1_IRQHandler(void)
	{
		dmaChannel10.isr();
	}
}
#endif



#if defined(DMA2_Stream2)
static void setDma2Stream2IntEn(bool en)
{
	nvic.setDmaChannel11En(en);
}

drv::Stream dma2Stream2(DMA2, DMA2_Stream2, 0, setDma2Stream2IntEn, 2);

const Drv::Config gDrvDmaChannel11Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream2IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma11Config
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Stream2	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel11::Config gDmaChannel11
{
};

drv::DmaChannel11 dmaChannel11(gDrvDmaChannel11Config, gDma11Config, gDmaChannel11);

extern "C"
{
	void DMA2_Stream2_IRQHandler(void)
	{
		dmaChannel11.isr();
	}
}
#endif



#if defined(DMA2_Stream3)
static void setDma2Stream3IntEn(bool en)
{
	nvic.setDmaChannel12En(en);
}

drv::Stream dma2Stream3(DMA2, DMA2_Stream3, 0, setDma2Stream3IntEn, 3);

const Drv::Config gDrvDmaChannel12Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream3IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma12Config
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Stream3	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel12::Config gDmaChannel12
{
};

drv::DmaChannel12 dmaChannel12(gDrvDmaChannel12Config, gDma12Config, gDmaChannel12);

extern "C"
{
	void DMA2_Stream3_IRQHandler(void)
	{
		dmaChannel12.isr();
	}
}
#endif



#if defined(DMA2_Stream4)
static void setDma2Stream4IntEn(bool en)
{
	nvic.setDmaChannel13En(en);
}

drv::Stream dma2Stream4(DMA2, DMA2_Stream4, 0, setDma2Stream4IntEn, 4);

const Drv::Config gDrvDmaChannel13Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream4IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma13Config
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Stream4	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel13::Config gDmaChannel13
{
};

drv::DmaChannel13 dmaChannel13(gDrvDmaChannel13Config, gDma13Config, gDmaChannel13);

extern "C"
{
	void DMA2_Stream4_IRQHandler(void)
	{
		dmaChannel13.isr();
	}
}
#endif



#if defined(DMA2_Stream5)
static void setDma2Stream5IntEn(bool en)
{
	nvic.setDmaChannel14En(en);
}

drv::Stream dma2Stream5(DMA2, DMA2_Stream5, 0, setDma2Stream5IntEn, 5);

const Drv::Config gDrvDmaChannel14Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream5IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma14Config
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Stream5	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel14::Config gDmaChannel14
{
};

drv::DmaChannel14 dmaChannel14(gDrvDmaChannel14Config, gDma14Config, gDmaChannel14);

extern "C"
{
	void DMA2_Stream5_IRQHandler(void)
	{
		dmaChannel14.isr();
	}
}
#endif



#if defined(DMA2_Stream6)
static void setDma2Stream6IntEn(bool en)
{
	nvic.setDmaChannel15En(en);
}

drv::Stream dma2Stream6(DMA2, DMA2_Stream6, 0, setDma2Stream6IntEn, 6);

const Drv::Config gDrvDmaChannel15Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream6IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma15Config
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Stream6	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel15::Config gDmaChannel15
{
};

drv::DmaChannel15 dmaChannel15(gDrvDmaChannel15Config, gDma15Config, gDmaChannel15);

extern "C"
{
	void DMA2_Stream6_IRQHandler(void)
	{
		dmaChannel15.isr();
	}
}
#endif



#if defined(DMA2_Stream7)
static void setDma2Stream7IntEn(bool en)
{
	nvic.setDmaChannel16En(en);
}

drv::Stream dma2Stream7(DMA2, DMA2_Stream7, 0, setDma2Stream7IntEn, 7);

const Drv::Config gDrvDmaChannel16Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream7IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const drv::Dma::Config gDma16Config
{
	DMA2,			//YSS_DMA_Peri *dma;
	DMA2_Stream7	//YSS_DMA_Channel_Peri *peri;	
};

const drv::DmaChannel16::Config gDmaChannel16
{
};

drv::DmaChannel16 dmaChannel16(gDrvDmaChannel16Config, gDma16Config, gDmaChannel16);

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




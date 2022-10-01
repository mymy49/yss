////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(GD32F4)

static void setDmaClockEn(bool en)
{
	clock.lock();
	clock.enableAhb1Clock(21, en);
	clock.enableAhb1Clock(22, en);
	clock.unlock();
}



#if defined(DMA1_Stream0)
static void setDma1Stream0IntEn(bool en)
{
	nvic.lock();
	nvic.setDmaChannel1En(en);
	nvic.unlock();
}

const Drv::Config gDrvDmaChannel1Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream0IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma1Config
{
	(YSS_DMA_Peri*)DMA0,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA0, DMA_CH0)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel1::Config gDmaChannel1
{
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Config, gDma1Config, gDmaChannel1);

extern "C"
{
	void DMA0_Channel0_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel2Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream1IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma2Config
{
	(YSS_DMA_Peri*)DMA0,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA0, DMA_CH1)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel2::Config gDmaChannel2
{
};

DmaChannel2 dmaChannel2(gDrvDmaChannel2Config, gDma2Config, gDmaChannel2);

extern "C"
{
	void DMA0_Channel1_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel3Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream2IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma3Config
{
	(YSS_DMA_Peri*)DMA0,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA0, DMA_CH2)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel3::Config gDmaChannel3
{
};

DmaChannel3 dmaChannel3(gDrvDmaChannel3Config, gDma3Config, gDmaChannel3);

extern "C"
{
	void DMA0_Channel2_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel4Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream3IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma4Config
{
	(YSS_DMA_Peri*)DMA0,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA0, DMA_CH3)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel4::Config gDmaChannel4
{
};

DmaChannel4 dmaChannel4(gDrvDmaChannel4Config, gDma4Config, gDmaChannel4);

extern "C"
{
	void DMA0_Channel3_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel5Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream4IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma5Config
{
	(YSS_DMA_Peri*)DMA0,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA0, DMA_CH4)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel5::Config gDmaChannel5
{
};

DmaChannel5 dmaChannel5(gDrvDmaChannel5Config, gDma5Config, gDmaChannel5);

extern "C"
{
	void DMA0_Channel4_IRQHandler(void)
	{
		dmaChannel5.isr();
	}
}



#if defined(DMA1_Stream5)
static void setDma1Stream5IntEn(bool en)
{
	nvic.setDmaChannel6En(en);
}

const Drv::Config gDrvDmaChannel6Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream5IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma6Config
{
	(YSS_DMA_Peri*)DMA0,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA0, DMA_CH5)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel6::Config gDmaChannel6
{
};

DmaChannel6 dmaChannel6(gDrvDmaChannel6Config, gDma6Config, gDmaChannel6);

extern "C"
{
	void DMA0_Channel5_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel7Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream6IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma7Config
{
	(YSS_DMA_Peri*)DMA0,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA0, DMA_CH6)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel7::Config gDmaChannel7
{
};

DmaChannel7 dmaChannel7(gDrvDmaChannel7Config, gDma7Config, gDmaChannel7);

extern "C"
{
	void DMA0_Channel6_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel8Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma1Stream7IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma8Config
{
	(YSS_DMA_Peri*)DMA0,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA0, DMA_CH7)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel8::Config gDmaChannel8
{
};

DmaChannel8 dmaChannel8(gDrvDmaChannel8Config, gDma8Config, gDmaChannel8);

extern "C"
{
	void DMA0_Channel7_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel9Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream0IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma9Config
{
	(YSS_DMA_Peri*)DMA1,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA1, DMA_CH0)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel9::Config gDmaChannel9
{
};

DmaChannel9 dmaChannel9(gDrvDmaChannel9Config, gDma9Config, gDmaChannel9);

extern "C"
{
	void DMA1_Channel0_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel10Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream1IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma10Config
{
	(YSS_DMA_Peri*)DMA1,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA1, DMA_CH1)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel10::Config gDmaChannel10
{
};

DmaChannel10 dmaChannel10(gDrvDmaChannel10Config, gDma10Config, gDmaChannel10);

extern "C"
{
	void DMA1_Channel1_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel11Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream2IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma11Config
{
	(YSS_DMA_Peri*)DMA1,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA1, DMA_CH2)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel11::Config gDmaChannel11
{
};

DmaChannel11 dmaChannel11(gDrvDmaChannel11Config, gDma11Config, gDmaChannel11);

extern "C"
{
	void DMA1_Channel2_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel12Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream3IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma12Config
{
	(YSS_DMA_Peri*)DMA1,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA1, DMA_CH3)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel12::Config gDmaChannel12
{
};

DmaChannel12 dmaChannel12(gDrvDmaChannel12Config, gDma12Config, gDmaChannel12);

extern "C"
{
	void DMA1_Channel3_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel13Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream4IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma13Config
{
	(YSS_DMA_Peri*)DMA1,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA1, DMA_CH4)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel13::Config gDmaChannel13
{
};

DmaChannel13 dmaChannel13(gDrvDmaChannel13Config, gDma13Config, gDmaChannel13);

extern "C"
{
	void DMA1_Channel4_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel14Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream5IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma14Config
{
	(YSS_DMA_Peri*)DMA1,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA1, DMA_CH5)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel14::Config gDmaChannel14
{
};

DmaChannel14 dmaChannel14(gDrvDmaChannel14Config, gDma14Config, gDmaChannel14);

extern "C"
{
	void DMA1_Channel5_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel15Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream6IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma15Config
{
	(YSS_DMA_Peri*)DMA1,								//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA1, DMA_CH6)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel15::Config gDmaChannel15
{
};

DmaChannel15 dmaChannel15(gDrvDmaChannel15Config, gDma15Config, gDmaChannel15);

extern "C"
{
	void DMA1_Channel6_IRQHandler(void)
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

const Drv::Config gDrvDmaChannel16Config
{
	setDmaClockEn,			//void (*clockFunc)(bool en);
	setDma2Stream7IntEn,	//void (*nvicFunc)(bool en);
	0						//void (*resetFunc)(void);
};

const Dma::Config gDma16Config
{
	(YSS_DMA_Peri*)DMA1,							//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&DMA_CHCTL(DMA1, DMA_CH7)	//YSS_DMA_Channel_Peri *peri;	
};

const DmaChannel16::Config gDmaChannel16
{
};

DmaChannel16 dmaChannel16(gDrvDmaChannel16Config, gDma16Config, gDmaChannel16);

extern "C"
{
	void DMA1_Channel7_IRQHandler(void)
	{
		dmaChannel16.isr();
	}
}
#endif

#endif

#endif




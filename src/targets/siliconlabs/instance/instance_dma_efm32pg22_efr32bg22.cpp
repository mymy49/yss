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

#if defined(EFM32PG22) || defined(EFR32BG22)

#if defined(EFM32PG22)
#include <targets/siliconlabs/efm32pg22_cmu.h>
#elif defined(EFR32BG22)
#include <targets/siliconlabs/efm32pg22_cmu.h>
#endif

Dma *dmaChannelList[8] = {&dmaChannel1, &dmaChannel2, &dmaChannel3, &dmaChannel4, &dmaChannel5, &dmaChannel6, &dmaChannel7, &dmaChannel8};

static void enableDmaClock(bool en)
{
	clock.lock();
	clock.enableApb0Clock(_CMU_CLKEN0_LDMA_SHIFT, en);
	clock.enableApb0Clock(_CMU_CLKEN0_LDMAXBAR_SHIFT, en);
	clock.unlock();
}

static void enableDmaInterrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(LDMA_IRQn, en);
	nvic.unlock();
}

const Drv::Config gDrvDmaChannel1Config
{
	enableDmaClock,		//void (*clockFunc)(bool en);
	enableDmaInterrupt,	//void (*nvicFunc)(bool en);
	0					//void (*resetFunc)(void);
};

const Dma::Config gDma1Config
{
	(YSS_DMA_Peri*)LDMA_S,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&LDMA_S->CH[0],	//YSS_DMA_Channel_Peri *peri;
	(YSS_DMA_Channel_Src*)&LDMAXBAR_S[0],
	0
};

const DmaChannel1::Config gDmaChannel1
{
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Config, gDma1Config, gDmaChannel1);



const Drv::Config gDrvDmaChannel2Config
{
	enableDmaClock,		//void (*clockFunc)(bool en);
	enableDmaInterrupt,	//void (*nvicFunc)(bool en);
	0					//void (*resetFunc)(void);
};

const Dma::Config gDma2Config
{
	(YSS_DMA_Peri*)LDMA_S,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&LDMA_S->CH[1],	//YSS_DMA_Channel_Peri *peri;
	(YSS_DMA_Channel_Src*)&LDMAXBAR_S[1],
	1
};

const DmaChannel2::Config gDmaChannel2
{
};

DmaChannel2 dmaChannel2(gDrvDmaChannel2Config, gDma2Config, gDmaChannel2);



const Drv::Config gDrvDmaChannel3Config
{
	enableDmaClock,		//void (*clockFunc)(bool en);
	enableDmaInterrupt,	//void (*nvicFunc)(bool en);
	0					//void (*resetFunc)(void);
};

const Dma::Config gDma3Config
{
	(YSS_DMA_Peri*)LDMA_S,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&LDMA_S->CH[2],	//YSS_DMA_Channel_Peri *peri;
	(YSS_DMA_Channel_Src*)&LDMAXBAR_S[2],
	2
};

const DmaChannel3::Config gDmaChannel3
{
};

DmaChannel3 dmaChannel3(gDrvDmaChannel3Config, gDma3Config, gDmaChannel3);



const Drv::Config gDrvDmaChannel4Config
{
	enableDmaClock,		//void (*clockFunc)(bool en);
	enableDmaInterrupt,	//void (*nvicFunc)(bool en);
	0					//void (*resetFunc)(void);
};

const Dma::Config gDma4Config
{
	(YSS_DMA_Peri*)LDMA_S,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&LDMA_S->CH[3],	//YSS_DMA_Channel_Peri *peri;
	(YSS_DMA_Channel_Src*)&LDMAXBAR_S[3],
	3
};

const DmaChannel4::Config gDmaChannel4
{
};

DmaChannel4 dmaChannel4(gDrvDmaChannel4Config, gDma4Config, gDmaChannel4);



const Drv::Config gDrvDmaChannel5Config
{
	enableDmaClock,		//void (*clockFunc)(bool en);
	enableDmaInterrupt,	//void (*nvicFunc)(bool en);
	0					//void (*resetFunc)(void);
};

const Dma::Config gDma5Config
{
	(YSS_DMA_Peri*)LDMA_S,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&LDMA_S->CH[4],	//YSS_DMA_Channel_Peri *peri;
	(YSS_DMA_Channel_Src*)&LDMAXBAR_S[4],
	4
};

const DmaChannel5::Config gDmaChannel5
{
};

DmaChannel5 dmaChannel5(gDrvDmaChannel5Config, gDma5Config, gDmaChannel5);



const Drv::Config gDrvDmaChannel6Config
{
	enableDmaClock,		//void (*clockFunc)(bool en);
	enableDmaInterrupt,	//void (*nvicFunc)(bool en);
	0					//void (*resetFunc)(void);
};

const Dma::Config gDma6Config
{
	(YSS_DMA_Peri*)LDMA_S,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&LDMA_S->CH[5],	//YSS_DMA_Channel_Peri *peri;
	(YSS_DMA_Channel_Src*)&LDMAXBAR_S[5],
	5
};

const DmaChannel6::Config gDmaChannel6
{
};

DmaChannel6 dmaChannel6(gDrvDmaChannel6Config, gDma6Config, gDmaChannel6);



const Drv::Config gDrvDmaChannel7Config
{
	enableDmaClock,		//void (*clockFunc)(bool en);
	enableDmaInterrupt,	//void (*nvicFunc)(bool en);
	0					//void (*resetFunc)(void);
};

const Dma::Config gDma7Config
{
	(YSS_DMA_Peri*)LDMA_S,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&LDMA_S->CH[6],	//YSS_DMA_Channel_Peri *peri;
	(YSS_DMA_Channel_Src*)&LDMAXBAR_S[6],
	6
};

const DmaChannel7::Config gDmaChannel7
{
};

DmaChannel7 dmaChannel7(gDrvDmaChannel7Config, gDma7Config, gDmaChannel7);



const Drv::Config gDrvDmaChannel8Config
{
	enableDmaClock,		//void (*clockFunc)(bool en);
	enableDmaInterrupt,	//void (*nvicFunc)(bool en);
	0					//void (*resetFunc)(void);
};

const Dma::Config gDma8Config
{
	(YSS_DMA_Peri*)LDMA_S,					//YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&LDMA_S->CH[7],	//YSS_DMA_Channel_Peri *peri;
	(YSS_DMA_Channel_Src*)&LDMAXBAR_S[7],
	7
};

const DmaChannel8::Config gDmaChannel8
{
};

DmaChannel8 dmaChannel8(gDrvDmaChannel8Config, gDma8Config, gDmaChannel8);

extern "C"
{
	void LDMA_IRQHandler(void)
	{
		if(LDMA_S->IF & 0x01)
			dmaChannel1.isr();
	}
}

#endif




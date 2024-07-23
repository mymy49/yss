/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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

const Drv::setup_t gDrvDmaChannel1Config
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



const Drv::setup_t gDrvDmaChannel2Config
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



const Drv::setup_t gDrvDmaChannel3Config
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



const Drv::setup_t gDrvDmaChannel4Config
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



const Drv::setup_t gDrvDmaChannel5Config
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



const Drv::setup_t gDrvDmaChannel6Config
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



const Drv::setup_t gDrvDmaChannel7Config
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



const Drv::setup_t gDrvDmaChannel8Config
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




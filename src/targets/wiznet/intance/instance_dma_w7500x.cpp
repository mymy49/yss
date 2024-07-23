/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(W7500)

#include <targets/wiznet/bitfield_w7500x.h>

static Dma::dmaChannelData_t gDmaChannelData[12] __attribute__((aligned(0x100)));

static void enableDma1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA_IRQn, en);
	nvic.unlock();
}

const Drv::setup_t gDrvDmaChannel1Setup = 
{
	0,							//void (*clockFunc)(bool en);
	enableDma1Interrupt,		//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0,							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma1Setup = 
{
	(YSS_DMA_Peri*)DMA,		//YSS_DMA_Peri *dma;
	&gDmaChannelData[0],	//dmaChannelData_t *primary;
	&gDmaChannelData[6],	//dmaChannelData_t *alternate;
	0,						//uint8_t channelNumber;
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Setup, gDma1Setup);



const Drv::setup_t gDrvDmaChannelSetup = 
{
	0,							//void (*clockFunc)(bool en);
	0,							//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0,							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma2Setup = 
{
	(YSS_DMA_Peri*)DMA,		//YSS_DMA_Peri *dma;
	&gDmaChannelData[1],	//dmaChannelData_t *primary;
	&gDmaChannelData[7],	//dmaChannelData_t *alternate;
	1,						//uint8_t channelNumber;
};



DmaChannel2 dmaChannel2(gDrvDmaChannelSetup, gDma2Setup);



const Dma::setup_t gDma3Setup = 
{
	(YSS_DMA_Peri*)DMA,		//YSS_DMA_Peri *dma;
	&gDmaChannelData[2],	//dmaChannelData_t *primary;
	&gDmaChannelData[8],	//dmaChannelData_t *alternate;
	2,						//uint8_t channelNumber;
};

DmaChannel3 dmaChannel3(gDrvDmaChannelSetup, gDma3Setup);



const Dma::setup_t gDma4Setup = 
{
	(YSS_DMA_Peri*)DMA,		//YSS_DMA_Peri *dma;
	&gDmaChannelData[3],	//dmaChannelData_t *primary;
	&gDmaChannelData[9],	//dmaChannelData_t *alternate;
	3,						//uint8_t channelNumber;
};

DmaChannel4 dmaChannel4(gDrvDmaChannelSetup, gDma4Setup);



const Dma::setup_t gDma5Setup = 
{
	(YSS_DMA_Peri*)DMA,		//YSS_DMA_Peri *dma;
	&gDmaChannelData[4],	//dmaChannelData_t *primary;
	&gDmaChannelData[10],	//dmaChannelData_t *alternate;
	4,						//uint8_t channelNumber;
};

DmaChannel5 dmaChannel5(gDrvDmaChannelSetup, gDma5Setup);



const Dma::setup_t gDma6Setup = 
{
	(YSS_DMA_Peri*)DMA,		//YSS_DMA_Peri *dma;
	&gDmaChannelData[5],	//dmaChannelData_t *primary;
	&gDmaChannelData[11],	//dmaChannelData_t *alternate;
	5,						//uint8_t channelNumber;
};

DmaChannel6 dmaChannel6(gDrvDmaChannelSetup, gDma6Setup);

extern "C"
{
	void DMA1_Channel1_IRQHandler(void)
	{
		dmaChannel1.isr();
	}
}

#endif


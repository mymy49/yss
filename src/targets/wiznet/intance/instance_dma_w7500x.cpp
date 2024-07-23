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


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

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <targets/nuvoton/bitfield_m48x.h>

Dma *gDmaChannel[YSS__NUM_OF_DMA_CH] = {&dmaChannel1, &dmaChannel2, &dmaChannel3, &dmaChannel4};

static void enableDma1Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableAhbClock(CLK_AHBCLK_PDMACKEN_Pos, en);
}

static void enableDma1Stream0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(PDMA_IRQn, en);
}

const Drv::setup_t gDrvDmaChannel1Setup = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream0Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0,							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma1Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[0]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Setup, gDma1Setup);



const Drv::setup_t gDrvDmaDummySetup = 
{
	0,		//void (*clockFunc)(bool en);
	0,		//void (*nvicFunc)(bool en);
	0,		//void (*resetFunc)(void);
	0,		//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma2Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[1]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel2 dmaChannel2(gDrvDmaDummySetup, gDma2Setup);



const Dma::setup_t gDma3Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[2]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel3 dmaChannel3(gDrvDmaDummySetup, gDma3Setup);



const Dma::setup_t gDma4Setup = 
{
	(YSS_DMA_Peri*)PDMA,					// YSS_DMA_Peri *dma;
	(YSS_DMA_Channel_Peri*)&PDMA->DSCT[3]	// YSS_DMA_Channel_Peri *peri;
};

DmaChannel4 dmaChannel4(gDrvDmaDummySetup, gDma4Setup);

extern "C"
{
	void PDMA_IRQHandler(void)
	{
		if(PDMA->INTSTS & PDMA_INTSTS_TDIF_Msk)
		{
			if(PDMA->TDSTS & PDMA_TDSTS_TDIF0_Msk)
			{
				dmaChannel1.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF0_Msk;
			}

			if(PDMA->TDSTS & PDMA_TDSTS_TDIF1_Msk)
			{
				dmaChannel2.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF1_Msk;
			}

			if(PDMA->TDSTS & PDMA_TDSTS_TDIF2_Msk)
			{
				dmaChannel3.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF2_Msk;
			}

			if(PDMA->TDSTS & PDMA_TDSTS_TDIF3_Msk)
			{
				dmaChannel4.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF3_Msk;
			}
		}
	}
}

#endif


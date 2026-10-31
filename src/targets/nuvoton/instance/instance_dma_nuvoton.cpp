/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
/**
 * @file instance_dma_nuvoton.cpp
 * @brief Global driver instances initialization for Nuvoton DMA peripheral.
 */

#include <yss/instance.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY) || defined(__MA35H0_FAMILY)

Dma *gDmaChannel[YSS__NUM_OF_DMA_CH] = {
#if YSS__NUM_OF_DMA_CH >= 1
	&dmaChannel1
#endif
#if YSS__NUM_OF_DMA_CH >= 2
	, &dmaChannel2
#endif
#if YSS__NUM_OF_DMA_CH >= 3
	, &dmaChannel3
#endif
#if YSS__NUM_OF_DMA_CH >= 4
	, &dmaChannel4
#endif
#if YSS__NUM_OF_DMA_CH >= 5
	, &dmaChannel5
#endif
#if YSS__NUM_OF_DMA_CH >= 6
	, &dmaChannel6
#endif
#if YSS__NUM_OF_DMA_CH >= 7
	, &dmaChannel7
#endif
#if YSS__NUM_OF_DMA_CH >= 8
	, &dmaChannel8
#endif
#if YSS__NUM_OF_DMA_CH >= 9
	, &dmaChannel9
#endif
#if YSS__NUM_OF_DMA_CH >= 10
	, &dmaChannel10
#endif
#if YSS__NUM_OF_DMA_CH >= 11
	, &dmaChannel11
#endif
#if YSS__NUM_OF_DMA_CH >= 12
	, &dmaChannel12
#endif
#if YSS__NUM_OF_DMA_CH >= 13
	, &dmaChannel13
#endif
#if YSS__NUM_OF_DMA_CH >= 14
	, &dmaChannel14
#endif
#if YSS__NUM_OF_DMA_CH >= 15
	, &dmaChannel15
#endif
#if YSS__NUM_OF_DMA_CH >= 16
	, &dmaChannel16
#endif
#if YSS__NUM_OF_DMA_CH >= 17
	, &dmaChannel17
#endif
#if YSS__NUM_OF_DMA_CH >= 18
	, &dmaChannel18
#endif
#if YSS__NUM_OF_DMA_CH >= 19
	, &dmaChannel19
#endif
#if YSS__NUM_OF_DMA_CH >= 20
	, &dmaChannel20
#endif
#if YSS__NUM_OF_DMA_CH >= 21
	, &dmaChannel21
#endif
#if YSS__NUM_OF_DMA_CH >= 22
	, &dmaChannel22
#endif
#if YSS__NUM_OF_DMA_CH >= 23
	, &dmaChannel23
#endif
#if YSS__NUM_OF_DMA_CH >= 24
	, &dmaChannel24
#endif
#if YSS__NUM_OF_DMA_CH >= 25
	, &dmaChannel25
#endif
#if YSS__NUM_OF_DMA_CH >= 26
	, &dmaChannel26
#endif
#if YSS__NUM_OF_DMA_CH >= 27
	, &dmaChannel27
#endif
#if YSS__NUM_OF_DMA_CH >= 28
	, &dmaChannel28
#endif
#if YSS__NUM_OF_DMA_CH >= 29
	, &dmaChannel29
#endif
#if YSS__NUM_OF_DMA_CH >= 30
	, &dmaChannel30
#endif
#if YSS__NUM_OF_DMA_CH >= 31
	, &dmaChannel31
#endif
#if YSS__NUM_OF_DMA_CH >= 32
	, &dmaChannel32
#endif
#if YSS__NUM_OF_DMA_CH >= 33
	, &dmaChannel33
#endif
#if YSS__NUM_OF_DMA_CH >= 34
	, &dmaChannel34
#endif
#if YSS__NUM_OF_DMA_CH >= 35
	, &dmaChannel35
#endif
#if YSS__NUM_OF_DMA_CH >= 36
	, &dmaChannel36
#endif
#if YSS__NUM_OF_DMA_CH >= 37
	, &dmaChannel37
#endif
#if YSS__NUM_OF_DMA_CH >= 38
	, &dmaChannel38
#endif
#if YSS__NUM_OF_DMA_CH >= 39
	, &dmaChannel39
#endif
#if YSS__NUM_OF_DMA_CH >= 40
	, &dmaChannel40
#endif
};

static void enableDma1Clock(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableApb0Clock().

#if defined(__M46x_SUBFAMILY)
	clock.enableAhb0Clock(CLK_AHBCLK0_PDMA0CKEN_Pos, en);
	clock.enableAhb0Clock(CLK_AHBCLK0_PDMA1CKEN_Pos, en);
#elif defined(__MA35H0_FAMILY)
	clock.lock();
	clock.enableSystem1Clock(CLK_SYSCLK1_PDMA0EN_Pos, en);
	clock.enableSystem1Clock(CLK_SYSCLK1_PDMA1EN_Pos, en);
	clock.enableSystem1Clock(CLK_SYSCLK1_PDMA2EN_Pos, en);
	clock.enableSystem1Clock(CLK_SYSCLK1_PDMA3EN_Pos, en);
	clock.unlock();
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	clock.enableAhb0Clock(CLK_AHBCLK_PDMACKEN_Pos, en);
#endif
}

static void enableDma1Stream0Interrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().

#if defined(__M46x_SUBFAMILY)
	nvic.enableInterrupt(PDMA0_IRQn, en);
	nvic.enableInterrupt(PDMA1_IRQn, en);
#elif defined(__MA35H0_FAMILY)
	nvic.lock();
	nvic.enableInterrupt(PDMA0_IRQn, en);
	nvic.enableInterrupt(PDMA1_IRQn, en);
	nvic.enableInterrupt(PDMA2_IRQn, en);
	nvic.enableInterrupt(PDMA3_IRQn, en);
	nvic.unlock();
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	nvic.enableInterrupt(PDMA_IRQn, en);
#endif

}



#if YSS__NUM_OF_DMA_CH >= 1
const Drv::setup_t gDrvDmaChannel1Setup = 
{
	enableDma1Clock,			//void (*clockFunc)(bool en);
	enableDma1Stream0Interrupt,	//void (*nvicFunc)(bool en);
	0,							//void (*resetFunc)(void);
	0,							//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma1Setup = 
{
#if defined(__M46x_SUBFAMILY) || defined(__MA35H0_FAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[0]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[0]	// YSS_DMA_Channel_Peri *peri; 
#endif
};

DmaChannel1 dmaChannel1(gDrvDmaChannel1Setup, gDma1Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 2
const Drv::setup_t gDrvDmaDummySetup = 
{
	0,		//void (*clockFunc)(bool en);
	0,		//void (*nvicFunc)(bool en);
	0,		//void (*resetFunc)(void);
	0,		//uint32_t (*getClockFunc)(void);
};

const Dma::setup_t gDma2Setup = 
{
#if defined(__M46x_SUBFAMILY) || defined(__MA35H0_FAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[1]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[1]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel2 dmaChannel2(gDrvDmaDummySetup, gDma2Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 3
const Dma::setup_t gDma3Setup = 
{
#if defined(__M46x_SUBFAMILY) || defined(__MA35H0_FAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[2]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[2]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel3 dmaChannel3(gDrvDmaDummySetup, gDma3Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 4
const Dma::setup_t gDma4Setup = 
{
#if defined(__M46x_SUBFAMILY) || defined(__MA35H0_FAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[3]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[3]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel4 dmaChannel4(gDrvDmaDummySetup, gDma4Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 5
const Dma::setup_t gDma5Setup = 
{
#if defined(__M46x_SUBFAMILY) || defined(__MA35H0_FAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[4]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[4]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel5 dmaChannel5(gDrvDmaDummySetup, gDma5Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 6
const Dma::setup_t gDma6Setup = 
{
#if defined(__M46x_SUBFAMILY) || defined(__MA35H0_FAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[5]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[5]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel6 dmaChannel6(gDrvDmaDummySetup, gDma6Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 7
const Dma::setup_t gDma7Setup = 
{
#if defined(__M46x_SUBFAMILY) || defined(__MA35H0_FAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[6]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[6]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel7 dmaChannel7(gDrvDmaDummySetup, gDma7Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 8
const Dma::setup_t gDma8Setup = 
{
#if defined(__M46x_SUBFAMILY) || defined(__MA35H0_FAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[7]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[7]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel8 dmaChannel8(gDrvDmaDummySetup, gDma8Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 9
const Dma::setup_t gDma9Setup = 
{
#if defined(__M46x_SUBFAMILY) || defined(__MA35H0_FAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[8]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[8]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel9 dmaChannel9(gDrvDmaDummySetup, gDma9Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 10
const Dma::setup_t gDma10Setup = 
{
#if defined(__M46x_SUBFAMILY) || defined(__MA35H0_FAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[9]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[9]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel10 dmaChannel10(gDrvDmaDummySetup, gDma10Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 11
const Dma::setup_t gDma11Setup = 
{
#if defined(__M46x_SUBFAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[10]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__MA35H0_FAMILY)
	PDMA1,					// YSS_DMA_Peri *dma;
	&PDMA1->DSCT[0]			// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[10]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel11 dmaChannel11(gDrvDmaDummySetup, gDma11Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 12
const Dma::setup_t gDma12Setup = 
{
#if defined(__M46x_SUBFAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[11]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__MA35H0_FAMILY)
	PDMA1,					// YSS_DMA_Peri *dma;
	&PDMA1->DSCT[1]			// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[11]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel12 dmaChannel12(gDrvDmaDummySetup, gDma12Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 13
const Dma::setup_t gDma13Setup = 
{
#if defined(__M46x_SUBFAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[12]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__MA35H0_FAMILY)
	PDMA1,					// YSS_DMA_Peri *dma;
	&PDMA1->DSCT[2]			// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[12]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel13 dmaChannel13(gDrvDmaDummySetup, gDma13Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 14
const Dma::setup_t gDma14Setup = 
{
#if defined(__M46x_SUBFAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[13]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__MA35H0_FAMILY)
	PDMA1,					// YSS_DMA_Peri *dma;
	&PDMA1->DSCT[3]			// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[13]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel14 dmaChannel14(gDrvDmaDummySetup, gDma14Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 15
const Dma::setup_t gDma15Setup = 
{
#if defined(__M46x_SUBFAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[14]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__MA35H0_FAMILY)
	PDMA1,					// YSS_DMA_Peri *dma;
	&PDMA1->DSCT[4]			// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[14]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel15 dmaChannel15(gDrvDmaDummySetup, gDma15Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 16
const Dma::setup_t gDma16Setup = 
{
#if defined(__M46x_SUBFAMILY)
	PDMA0,					// YSS_DMA_Peri *dma;
	&PDMA0->DSCT[15]	// YSS_DMA_Channel_Peri *peri;
#elif defined(__MA35H0_FAMILY)
	PDMA1,					// YSS_DMA_Peri *dma;
	&PDMA1->DSCT[5]			// YSS_DMA_Channel_Peri *peri;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	PDMA,					// YSS_DMA_Peri *dma;
	&PDMA->DSCT[15]	// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel16 dmaChannel16(gDrvDmaDummySetup, gDma16Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 17
const Dma::setup_t gDma17Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA1,					// YSS_DMA_Peri *dma;
	&PDMA1->DSCT[6]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel17 dmaChannel17(gDrvDmaDummySetup, gDma17Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 18
const Dma::setup_t gDma18Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA1,					// YSS_DMA_Peri *dma;
	&PDMA1->DSCT[7]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel18 dmaChannel18(gDrvDmaDummySetup, gDma18Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 19
const Dma::setup_t gDma19Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA1,					// YSS_DMA_Peri *dma;
	&PDMA1->DSCT[8]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel19 dmaChannel19(gDrvDmaDummySetup, gDma19Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 20
const Dma::setup_t gDma20Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA1,					// YSS_DMA_Peri *dma;
	&PDMA1->DSCT[9]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel20 dmaChannel20(gDrvDmaDummySetup, gDma20Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 21
const Dma::setup_t gDma21Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA2,					// YSS_DMA_Peri *dma;
	&PDMA2->DSCT[0]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel21 dmaChannel21(gDrvDmaDummySetup, gDma21Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 22
const Dma::setup_t gDma22Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA2,					// YSS_DMA_Peri *dma;
	&PDMA2->DSCT[1]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel22 dmaChannel22(gDrvDmaDummySetup, gDma22Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 23
const Dma::setup_t gDma23Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA2,					// YSS_DMA_Peri *dma;
	&PDMA2->DSCT[2]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel23 dmaChannel23(gDrvDmaDummySetup, gDma23Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 24
const Dma::setup_t gDma24Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA2,					// YSS_DMA_Peri *dma;
	&PDMA2->DSCT[3]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel24 dmaChannel24(gDrvDmaDummySetup, gDma24Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 25
const Dma::setup_t gDma25Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA2,					// YSS_DMA_Peri *dma;
	&PDMA2->DSCT[4]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel25 dmaChannel25(gDrvDmaDummySetup, gDma25Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 26
const Dma::setup_t gDma26Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA2,					// YSS_DMA_Peri *dma;
	&PDMA2->DSCT[5]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel26 dmaChannel26(gDrvDmaDummySetup, gDma26Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 27
const Dma::setup_t gDma27Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA2,					// YSS_DMA_Peri *dma;
	&PDMA2->DSCT[6]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel27 dmaChannel27(gDrvDmaDummySetup, gDma27Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 28
const Dma::setup_t gDma28Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA2,					// YSS_DMA_Peri *dma;
	&PDMA2->DSCT[7]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel28 dmaChannel28(gDrvDmaDummySetup, gDma28Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 29
const Dma::setup_t gDma29Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA2,					// YSS_DMA_Peri *dma;
	&PDMA2->DSCT[8]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel29 dmaChannel29(gDrvDmaDummySetup, gDma29Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 30
const Dma::setup_t gDma30Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA2,					// YSS_DMA_Peri *dma;
	&PDMA2->DSCT[9]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel30 dmaChannel30(gDrvDmaDummySetup, gDma30Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 31
const Dma::setup_t gDma31Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA3,					// YSS_DMA_Peri *dma;
	&PDMA3->DSCT[0]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel31 dmaChannel31(gDrvDmaDummySetup, gDma31Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 32
const Dma::setup_t gDma32Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA3,					// YSS_DMA_Peri *dma;
	&PDMA3->DSCT[1]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel32 dmaChannel32(gDrvDmaDummySetup, gDma32Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 33
const Dma::setup_t gDma33Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA3,					// YSS_DMA_Peri *dma;
	&PDMA3->DSCT[2]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel33 dmaChannel33(gDrvDmaDummySetup, gDma33Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 34
const Dma::setup_t gDma34Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA3,					// YSS_DMA_Peri *dma;
	&PDMA3->DSCT[3]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel34 dmaChannel34(gDrvDmaDummySetup, gDma34Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 35
const Dma::setup_t gDma35Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA3,					// YSS_DMA_Peri *dma;
	&PDMA3->DSCT[4]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel35 dmaChannel35(gDrvDmaDummySetup, gDma35Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 36
const Dma::setup_t gDma36Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA3,					// YSS_DMA_Peri *dma;
	&PDMA3->DSCT[5]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel36 dmaChannel36(gDrvDmaDummySetup, gDma36Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 37
const Dma::setup_t gDma37Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA3,					// YSS_DMA_Peri *dma;
	&PDMA3->DSCT[6]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel37 dmaChannel37(gDrvDmaDummySetup, gDma37Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 38
const Dma::setup_t gDma38Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA3,					// YSS_DMA_Peri *dma;
	&PDMA3->DSCT[7]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel38 dmaChannel38(gDrvDmaDummySetup, gDma38Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 39
const Dma::setup_t gDma39Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA3,					// YSS_DMA_Peri *dma;
	&PDMA3->DSCT[8]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel39 dmaChannel39(gDrvDmaDummySetup, gDma39Setup);
#endif



#if YSS__NUM_OF_DMA_CH >= 40
const Dma::setup_t gDma40Setup = 
{
#if defined(__MA35H0_FAMILY)
	PDMA3,					// YSS_DMA_Peri *dma;
	&PDMA3->DSCT[9]			// YSS_DMA_Channel_Peri *peri;
#endif
};

DmaChannel40 dmaChannel40(gDrvDmaDummySetup, gDma40Setup);
#endif

extern "C"
{
#if defined(__M46x_SUBFAMILY)
	void PDMA0_IRQHandler(void)
	{
		uint32_t tdsts = PDMA0->TDSTS;

		if(PDMA0->INTSTS & PDMA_INTSTS_TDIF_Msk)
		{
			if(tdsts & PDMA_TDSTS_TDIF0_Msk)
			{
				dmaChannel1.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF0_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF1_Msk)
			{
				dmaChannel2.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF1_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF2_Msk)
			{
				dmaChannel3.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF2_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF3_Msk)
			{
				dmaChannel4.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF3_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF4_Msk)
			{
				dmaChannel5.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF4_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF5_Msk)
			{
				dmaChannel6.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF5_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF6_Msk)
			{
				dmaChannel7.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF6_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF7_Msk)
			{
				dmaChannel8.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF7_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF8_Msk)
			{
				dmaChannel9.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF8_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF9_Msk)
			{
				dmaChannel10.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF9_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF10_Msk)
			{
				dmaChannel11.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF10_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF11_Msk)
			{
				dmaChannel12.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF11_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF12_Msk)
			{
				dmaChannel13.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF12_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF13_Msk)
			{
				dmaChannel14.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF13_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF14_Msk)
			{
				dmaChannel15.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF14_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF15_Msk)
			{
				dmaChannel16.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF15_Msk;
			}
		}
	}
#elif defined(__MA35H0_FAMILY)
	void PDMA0_IRQHandler(void)
	{
		uint32_t tdsts = PDMA0->TDSTS;

		if(PDMA0->INTSTS & PDMA_INTSTS_TDIF_Msk)
		{
			if(tdsts & PDMA_TDSTS_TDIF0_Msk)
			{
				dmaChannel1.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF0_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF1_Msk)
			{
				dmaChannel2.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF1_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF2_Msk)
			{
				dmaChannel3.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF2_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF3_Msk)
			{
				dmaChannel4.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF3_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF4_Msk)
			{
				dmaChannel5.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF4_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF5_Msk)
			{
				dmaChannel6.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF5_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF6_Msk)
			{
				dmaChannel7.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF6_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF7_Msk)
			{
				dmaChannel8.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF7_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF8_Msk)
			{
				dmaChannel9.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF8_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF9_Msk)
			{
				dmaChannel10.isr();
				PDMA0->TDSTS = PDMA_TDSTS_TDIF9_Msk;
			}
		}
	}

	void PDMA1_IRQHandler(void)
	{
		uint32_t tdsts = PDMA1->TDSTS;

		if(PDMA1->INTSTS & PDMA_INTSTS_TDIF_Msk)
		{
			if(tdsts & PDMA_TDSTS_TDIF0_Msk)
			{
				dmaChannel11.isr();
				PDMA1->TDSTS = PDMA_TDSTS_TDIF0_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF1_Msk)
			{
				dmaChannel12.isr();
				PDMA1->TDSTS = PDMA_TDSTS_TDIF1_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF2_Msk)
			{
				dmaChannel13.isr();
				PDMA1->TDSTS = PDMA_TDSTS_TDIF2_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF3_Msk)
			{
				dmaChannel14.isr();
				PDMA1->TDSTS = PDMA_TDSTS_TDIF3_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF4_Msk)
			{
				dmaChannel15.isr();
				PDMA1->TDSTS = PDMA_TDSTS_TDIF4_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF5_Msk)
			{
				dmaChannel16.isr();
				PDMA1->TDSTS = PDMA_TDSTS_TDIF5_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF6_Msk)
			{
				dmaChannel17.isr();
				PDMA1->TDSTS = PDMA_TDSTS_TDIF6_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF7_Msk)
			{
				dmaChannel18.isr();
				PDMA1->TDSTS = PDMA_TDSTS_TDIF7_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF8_Msk)
			{
				dmaChannel19.isr();
				PDMA1->TDSTS = PDMA_TDSTS_TDIF8_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF9_Msk)
			{
				dmaChannel20.isr();
				PDMA1->TDSTS = PDMA_TDSTS_TDIF9_Msk;
			}
		}
	}

	void PDMA2_IRQHandler(void)
	{
		uint32_t tdsts = PDMA2->TDSTS;

		if(PDMA2->INTSTS & PDMA_INTSTS_TDIF_Msk)
		{
			if(tdsts & PDMA_TDSTS_TDIF0_Msk)
			{
				dmaChannel21.isr();
				PDMA2->TDSTS = PDMA_TDSTS_TDIF0_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF1_Msk)
			{
				dmaChannel22.isr();
				PDMA2->TDSTS = PDMA_TDSTS_TDIF1_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF2_Msk)
			{
				dmaChannel23.isr();
				PDMA2->TDSTS = PDMA_TDSTS_TDIF2_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF3_Msk)
			{
				dmaChannel24.isr();
				PDMA2->TDSTS = PDMA_TDSTS_TDIF3_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF4_Msk)
			{
				dmaChannel25.isr();
				PDMA2->TDSTS = PDMA_TDSTS_TDIF4_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF5_Msk)
			{
				dmaChannel26.isr();
				PDMA2->TDSTS = PDMA_TDSTS_TDIF5_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF6_Msk)
			{
				dmaChannel27.isr();
				PDMA2->TDSTS = PDMA_TDSTS_TDIF6_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF7_Msk)
			{
				dmaChannel28.isr();
				PDMA2->TDSTS = PDMA_TDSTS_TDIF7_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF8_Msk)
			{
				dmaChannel29.isr();
				PDMA2->TDSTS = PDMA_TDSTS_TDIF8_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF9_Msk)
			{
				dmaChannel30.isr();
				PDMA2->TDSTS = PDMA_TDSTS_TDIF9_Msk;
			}
		}
	}

	void PDMA3_IRQHandler(void)
	{
		uint32_t tdsts = PDMA3->TDSTS;

		if(PDMA3->INTSTS & PDMA_INTSTS_TDIF_Msk)
		{
			if(tdsts & PDMA_TDSTS_TDIF0_Msk)
			{
				dmaChannel31.isr();
				PDMA3->TDSTS = PDMA_TDSTS_TDIF0_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF1_Msk)
			{
				dmaChannel32.isr();
				PDMA3->TDSTS = PDMA_TDSTS_TDIF1_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF2_Msk)
			{
				dmaChannel33.isr();
				PDMA3->TDSTS = PDMA_TDSTS_TDIF2_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF3_Msk)
			{
				dmaChannel34.isr();
				PDMA3->TDSTS = PDMA_TDSTS_TDIF3_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF4_Msk)
			{
				dmaChannel35.isr();
				PDMA3->TDSTS = PDMA_TDSTS_TDIF4_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF5_Msk)
			{
				dmaChannel36.isr();
				PDMA3->TDSTS = PDMA_TDSTS_TDIF5_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF6_Msk)
			{
				dmaChannel37.isr();
				PDMA3->TDSTS = PDMA_TDSTS_TDIF6_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF7_Msk)
			{
				dmaChannel38.isr();
				PDMA3->TDSTS = PDMA_TDSTS_TDIF7_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF8_Msk)
			{
				dmaChannel39.isr();
				PDMA3->TDSTS = PDMA_TDSTS_TDIF8_Msk;
			}

			if(tdsts & PDMA_TDSTS_TDIF9_Msk)
			{
				dmaChannel40.isr();
				PDMA3->TDSTS = PDMA_TDSTS_TDIF9_Msk;
			}
		}
	}

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
	void PDMA_IRQHandler(void)
	{
		uint32_t tdsts = PDMA->TDSTS;

		if(PDMA->INTSTS & PDMA_INTSTS_TDIF_Msk)
		{
#if YSS__NUM_OF_DMA_CH >= 1
			if(tdsts & PDMA_TDSTS_TDIF0_Msk)
			{
				dmaChannel1.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF0_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 2
			if(tdsts & PDMA_TDSTS_TDIF1_Msk)
			{
				dmaChannel2.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF1_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 3
			if(tdsts & PDMA_TDSTS_TDIF2_Msk)
			{
				dmaChannel3.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF2_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 4
			if(tdsts & PDMA_TDSTS_TDIF3_Msk)
			{
				dmaChannel4.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF3_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 5
			if(tdsts & PDMA_TDSTS_TDIF4_Msk)
			{
				dmaChannel5.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF4_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 6
			if(tdsts & PDMA_TDSTS_TDIF5_Msk)
			{
				dmaChannel6.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF5_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 7
			if(tdsts & PDMA_TDSTS_TDIF6_Msk)
			{
				dmaChannel7.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF6_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 8
			if(tdsts & PDMA_TDSTS_TDIF7_Msk)
			{
				dmaChannel8.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF7_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 9
			if(tdsts & PDMA_TDSTS_TDIF8_Msk)
			{
				dmaChannel9.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF8_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 10
			if(tdsts & PDMA_TDSTS_TDIF9_Msk)
			{
				dmaChannel10.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF9_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 11
			if(tdsts & PDMA_TDSTS_TDIF10_Msk)
			{
				dmaChannel11.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF10_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 12
			if(tdsts & PDMA_TDSTS_TDIF11_Msk)
			{
				dmaChannel12.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF11_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 13
			if(tdsts & PDMA_TDSTS_TDIF12_Msk)
			{
				dmaChannel13.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF12_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 14
			if(tdsts & PDMA_TDSTS_TDIF13_Msk)
			{
				dmaChannel14.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF13_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 15
			if(tdsts & PDMA_TDSTS_TDIF14_Msk)
			{
				dmaChannel15.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF14_Msk;
			}
#endif

#if YSS__NUM_OF_DMA_CH >= 16
			if(tdsts & PDMA_TDSTS_TDIF15_Msk)
			{
				dmaChannel16.isr();
				PDMA->TDSTS = PDMA_TDSTS_TDIF15_Msk;
			}
#endif
		}
	}
#endif
}

#endif


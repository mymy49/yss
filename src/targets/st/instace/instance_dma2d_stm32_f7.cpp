/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>
#include <config.h>

#if defined(STM32F7) || defined(STM32F4)

#if defined(DMA2D) && defined(DMA2D_ENABLE) && USE_GUI

#include <targets/st/bitfield.h>

static void enableClock(bool en)
{
	clock.lock();
    clock.enableAhb1Clock(RCC_AHB1ENR_DMA2DEN_Pos, en);
	clock.unlock();
}

static void enableInterrup(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(DMA2D_IRQn, en);
	nvic.unlock();
}

static void reset(void)
{
	clock.lock();
    clock.resetAhb1(RCC_AHB1RSTR_DMA2DRST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvConfig
{
	enableClock,	//void (*clockFunc)(bool en);
	enableInterrup,	//void (*nvicFunc)(bool en);
	reset,			//void (*resetFunc)(void);
	0				//uint32_t (*getClockFunc)(void);
};

static const Dma2d::setup_t gConfig
{
	(YSS_DMA2D_Peri*)DMA2D	//YSS_DMA2D_Peri *peri;
};

Dma2d dma2d(gDrvConfig, gConfig);

extern "C"
{
	void DMA2D_IRQHandler(void)
	{
		dma2d.isr();
	}
}

#endif

#endif

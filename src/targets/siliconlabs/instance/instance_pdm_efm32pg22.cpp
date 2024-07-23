/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(EFM32PG22)

#include <drv/peripheral.h>
#include <yss/instance.h>
#include <config.h>
#include <targets/siliconlabs/efm32pg22_cmu.h>

static uint32_t getClockFreqeuncy(void)
{
	return clock.getApb0Frequency();
}

#if PDM_COUNT >= 1 && defined(PDM0_ENABLE)
static void enableClockPdm0(bool en)
{
	clock.lock();
	clock.enableApb0Clock(_CMU_CLKEN0_PDM_SHIFT, en);
	clock.unlock();
}

static void enableInterruptPdm0(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(PDM_IRQn, en);
	nvic.unlock();
}

static const Drv::setup_t gDrvPdm0Setup
{
	enableClockPdm0,		//void (*clockFunc)(bool en);
	enableInterruptPdm0,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getClockFreqeuncy		//uint32_t (*getClockFunc)(void);
};

static const Pdm::Setup gPdm0Setup
{
	PDM_S,			//YSS_PDM_Peri *dev;
};

Pdm pdm0(gDrvPdm0Setup, gPdm0Setup);

extern "C"
{
	void PDM_IRQHandler(void)
	{
		pdm0.isr();
	}
}
#endif

#endif


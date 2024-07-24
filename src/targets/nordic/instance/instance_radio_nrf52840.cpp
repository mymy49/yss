/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#define PRIORITY_POS	12
#define MWIDTH_POS		10
#define PWIDTH_POS		8
#define DIR_POS			4

#include <drv/mcu.h>
#include <yss/instance.h>
#include <config.h>

#if defined(NRF_RADIO) && defined(RADIO_ENABLE)
static void enableInterruptRadio(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(RADIO_IRQn, en);
	nvic.unlock();
}

static const Drv::setup_t gDrvConfig
{
	0,						//void (*clockFunc)(bool en);
	enableInterruptRadio,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	0						//uint32_t (*getClockFunc)(void);
};

Radio radio(NRF_RADIO, gDrvConfig);

extern "C"
{
	void RADIO_IRQHandler(void)
	{
		uart0.isr();
	}
}
#endif

#endif


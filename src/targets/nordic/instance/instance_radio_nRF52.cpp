/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(NRF_RADIO) && RADIO_ENABLE
static void enableInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(RADIO_IRQn, en);
}


static const Drv::setup_t gDrSetup = 
{
	0,					//void (*clockFunc)(bool en);
	enableInterrupt,	//void (*nvicFunc)(bool en);
	0,					//void (*resetFunc)(void);
	0					//uint32_t (*getClockFunc)(void);
};

static const nRF52_Radio::setup_t gSetup = 
{
	NRF_RADIO,				// NRF_RADIO_Type *dev;
};

nRF52_Radio radio(gDrSetup, gSetup);

extern "C"
{
	void RADIO_IRQHandler(void)
	{
		radio.isr();
	}
}
#endif




#endif


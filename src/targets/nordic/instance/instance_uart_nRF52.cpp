/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(NRF52840_XXAA)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#pragma GCC optimize("O1")

static uint32_t getUartClockFrequency(void)
{
	return 64000000;
}

#if defined(NRF_UARTE0) && UART0_ENABLE
static void enableUart0Interrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(UARTE0_UART0_IRQn, en);
}


static const Drv::setup_t gDrvUart0Setup = 
{
	0,						//void (*clockFunc)(bool en);
	enableUart0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getUartClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const nRF52_Uart::setup_t gUart0Setup = 
{
	NRF_UARTE0,				// NRF_UARTE_Type *dev;
};

nRF52_Uart uart0(gDrvUart0Setup, gUart0Setup);

extern "C"
{
	void UARTE0_UART0_IRQHandler(void)
	{
		uart0.isr();
	}
}
#endif




#endif


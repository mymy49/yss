/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__MA35H0_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(EMAC0) && EMAC0_ENABLE
static void enableEmac0Clock(bool en)
{
	clock.lock();
	clock.enableSystem0Clock(CLK_SYSCLK0_EMAC0EN_Pos, en);
	clock.unlock();
}

static void enableEmac0Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(EMAC0_IRQn, en);
	nvic.unlock();
}

static void resetEmac0()
{
	SYS->RLKTZS = 0x59;
	SYS->RLKTZS = 0x16;
	SYS->RLKTZS = 0x88;
	
	SYS->IPRST0 |= SYS_IPRST0_EMAC0RST_Msk;
	SYS->IPRST0 &= ~SYS_IPRST0_EMAC0RST_Msk;

	SYS->RLKTZS = 0x00;
}

static uint32_t getEmac0ClockFrequency(void)
{
	uint32_t clk = clock.getSysclk0ClockFrequency();
	return clk;
}

static const Drv::setup_t gDrvEmac0Setup = 
{
	enableEmac0Clock,		//void (*clockFunc)(bool en);
	enableEmac0Interrupt,	//void (*nvicFunc)(bool en);
	resetEmac0,				//void (*resetFunc)(void);
	getEmac0ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const NuvotonEmac::setup_t gEmac0Setup = 
{
	EMAC0
};

NuvotonEmac emac0(gDrvEmac0Setup, gEmac0Setup);

#endif

#endif


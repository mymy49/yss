/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M46x_SUBFAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(CANFD0) && CANFD0_ENABLE
static void enableCanfd0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableAhb1Clock(CLK_AHBCLK1_CANFD0CKEN_Pos, en);
}

static void enableCanfd0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(CANFD00_IRQn, en);
}

static uint32_t getCanfd0ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL0 & CLK_CLKSEL0_CANFD0SEL_Msk) >> CLK_CLKSEL0_CANFD0SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency() / 2;
		break;

	case 2 : // LXT
		clk = clock.getHclkClockFrequency();
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV5 & CLK_CLKDIV5_CANFD0DIV_Msk) >> CLK_CLKDIV5_CANFD0DIV_Pos) + 1);
}

static const Drv::setup_t gDrvCanfd0Setup = 
{
	enableCanfd0Clock,		//void (*clockFunc)(bool en);
	enableCanfd0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getCanfd0ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const NuvotonCanFd::setup_t gCanfd0Setup = 
{
	CANFD0		// CANFD_T *dev;
};

NuvotonCanFd canfd0(gDrvCanfd0Setup, gCanfd0Setup);

extern "C"
{
	void CANFD00_IRQHandler(void)
	{
		canfd0.isr0();
	}
}
#endif

#endif


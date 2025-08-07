/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_SUBFAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
#include <targets/nuvoton/bitfield_m4xx.h>
#elif defined(__M25x_SUBFAMILY)
#include <targets/nuvoton/bitfield_m2xx.h>
#endif

#if defined(USBD) && USBD_ENABLE
static void enableUsbdClock(bool en)
{
	uint32_t clk;

	if(en)
	{
#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		clk = clock.getPllFrequency();
		if(clk % 48000000 == 0)
		{
			CLK->CLKSEL0 |= CLK_CLKSEL0_USBSEL_Msk;
			clk /= 48000000;
			if(clk > 0)
				clk--;
			setFieldData(CLK->CLKDIV0, CLK_CLKDIV0_USBDIV_Msk, clk, CLK_CLKDIV0_USBDIV_Pos);
		}
		else
			CLK->CLKSEL0 &= ~CLK_CLKSEL0_USBSEL_Msk;
#elif defined(__M25x_SUBFAMILY)

#endif
	}
	else
	{

	}

	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_USBDCKEN_Pos, en);
}

static void enableUsbdInterrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(USBD_IRQn, en);
}

static uint32_t getUsbdClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL1 & CLK_CLKSEL1_UART0SEL_Msk) >> CLK_CLKSEL1_UART0SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV0 & CLK_CLKDIV0_UART0DIV_Msk) >> CLK_CLKDIV0_UART0DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUsbdSetup = 
{
	enableUsbdClock,		//void (*clockFunc)(bool en);
	enableUsbdInterrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getUsbdClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Usbd::setup_t gUsbdSetup = 
{
	USBD						// YSS_SPI_Peri *peri;
};

Usbd usbd(gDrvUsbdSetup, gUsbdSetup);

extern "C"
{
	void USBD_IRQHandler(void)
	{
		usbd.isr();
	}
}
#endif

#endif


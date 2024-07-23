/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(W7500)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/wiznet/bitfield_w7500x.h>


#if defined(UART0) && UART0_ENABLE
static void enableUart0Clock(bool en)
{
	clock.lock();
	CRG->UARTCLK_SSR = 1;
	clock.unlock();
}

static void enableUart0Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(UART0_IRQn, en);
	nvic.unlock();
}

static uint32_t getUart0ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM0CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->UARTCLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvUart0Setup = 
{
	enableUart0Clock,		//void (*clockFunc)(bool en);
	enableUart0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getUart0ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Uart::setup_t gUart0Setup = 
{
	(YSS_USART_Typedef*)UART0	//YSS_SPI_Peri *peri;
};

Uart uart0(gDrvUart0Setup, gUart0Setup);

extern "C"
{
	void UART0_IRQHandler(void)
	{
		uart0.isr();
	}
}
#endif


#if defined(UART1) && UART1_ENABLE
static void enableUart1Clock(bool en)
{
	clock.lock();
	CRG->UARTCLK_SSR = 1;
	clock.unlock();
}

static void enableUart1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(UART1_IRQn, en);
	nvic.unlock();
}

static uint32_t getUart1ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM0CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->UARTCLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvUart1Setup = 
{
	enableUart1Clock,		//void (*clockFunc)(bool en);
	enableUart1Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getUart1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Uart::setup_t gUart1Setup = 
{
	(YSS_USART_Typedef*)UART1,	//YSS_SPI_Peri *peri;
};

Uart uart1(gDrvUart1Setup, gUart1Setup);

extern "C"
{
	void UART1_IRQHandler(void)
	{
		uart1.isr();
	}
}
#endif

#endif


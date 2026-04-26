/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <config.h>
#include <yss/instance.h>

#if defined(__M46x_SUBFAMILY)
#define FBDIV_VALUE		43
#elif defined(__M480_FAMILY)
#define FBDIV_VALUE		46
#elif defined(__M4xx_FAMILY)
#define FBDIV_VALUE		34
#endif

void __WEAK initializeSystem(void)
{
	uint32_t srcClk, reg;

	// 외부 고속 클럭 활성화
#if defined(HSE_CLOCK_FREQ)
	clock.enableHxt(HSE_CLOCK_FREQ);
	srcClk = HSE_CLOCK_FREQ;
#else
	srcClk = clock.getHircFrequency();
#endif

	clock.enablePll
	(
#if defined(HSE_CLOCK_FREQ)
		Clock::PLL_SRC_HXT,
#else
		Clock::PLL_SRC_HIRC,
#endif
		srcClk / 4000000 - 1,
		FBDIV_VALUE,
		1
	);

	clock.setHclkClockSource(Clock::HCLK_SRC_PLL, 0, 1, 1); 
	
	// UART0의 클럭 소스를 PLL로 변경
#if defined(UART0)
	setFieldData(CLK->CLKSEL1, CLK_CLKSEL1_UART0SEL_Msk, 1, CLK_CLKSEL1_UART0SEL_Pos);
#endif
#if defined(UART1)
	setFieldData(CLK->CLKSEL1, CLK_CLKSEL1_UART1SEL_Msk, 1, CLK_CLKSEL1_UART1SEL_Pos);
#endif
#if defined(UART2)
	setFieldData(CLK->CLKSEL3, CLK_CLKSEL3_UART2SEL_Msk, 1, CLK_CLKSEL3_UART2SEL_Pos);
#endif
#if defined(UART3)
	setFieldData(CLK->CLKSEL3, CLK_CLKSEL3_UART3SEL_Msk, 1, CLK_CLKSEL3_UART3SEL_Pos);
#endif
#if defined(UART4)
	setFieldData(CLK->CLKSEL3, CLK_CLKSEL3_UART4SEL_Msk, 1, CLK_CLKSEL3_UART4SEL_Pos);
#endif
#if defined(UART5)
	setFieldData(CLK->CLKSEL3, CLK_CLKSEL3_UART5SEL_Msk, 1, CLK_CLKSEL3_UART5SEL_Pos);
#endif
#if defined(UART6)
	setFieldData(CLK->CLKSEL3, CLK_CLKSEL3_UART6SEL_Msk, 1, CLK_CLKSEL3_UART6SEL_Pos);
#endif
#if defined(UART7)
	setFieldData(CLK->CLKSEL3, CLK_CLKSEL3_UART7SEL_Msk, 1, CLK_CLKSEL3_UART7SEL_Pos);
#endif
#if defined(UART8)
	setFieldData(CLK->CLKSEL2, CLK_CLKSEL2_UART8SEL_Msk, 1, CLK_CLKSEL2_UART8SEL_Pos);
#endif
#if defined(UART9)
	setFieldData(CLK->CLKSEL2, CLK_CLKSEL2_UART9SEL_Msk, 1, CLK_CLKSEL2_UART9SEL_Pos);
#endif

	// TIMER0, TIMER1, TIMER2, TIMER3의 클럭 소스를 PCLK로 변경
	reg = CLK->CLKSEL1;
	reg &= ~(CLK_CLKSEL1_TMR0SEL_Msk | CLK_CLKSEL1_TMR1SEL_Msk | CLK_CLKSEL1_TMR2SEL_Msk | CLK_CLKSEL1_TMR3SEL_Msk);
	reg |= (2 << CLK_CLKSEL1_TMR0SEL_Pos) | (2 << CLK_CLKSEL1_TMR1SEL_Pos) | (2 << CLK_CLKSEL1_TMR2SEL_Pos) | (2 << CLK_CLKSEL1_TMR3SEL_Pos);
	CLK->CLKSEL1 = reg;
	
	// CAN FD의 클럭 소스를 HCLK로 변경
	// unlock	
#if defined(CANFD0) || defined(CANFD1) || defined(CANFD2) || defined(CANFD3)
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;
#endif
#if defined(CANFD0)
	setFieldData(CLK->CLKSEL0, CLK_CLKSEL0_CANFD0SEL_Msk, 2, CLK_CLKSEL0_CANFD0SEL_Pos);
#endif

#if defined(CANFD1)
	setFieldData(CLK->CLKSEL0, CLK_CLKSEL0_CANFD1SEL_Msk, 2, CLK_CLKSEL0_CANFD1SEL_Pos);
#endif

#if defined(CANFD2)
	setFieldData(CLK->CLKSEL0, CLK_CLKSEL0_CANFD2SEL_Msk, 2, CLK_CLKSEL0_CANFD2SEL_Pos);
#endif

#if defined(CANFD3)
	setFieldData(CLK->CLKSEL0, CLK_CLKSEL0_CANFD3SEL_Msk, 2, CLK_CLKSEL0_CANFD3SEL_Pos);
#endif
#if defined(CANFD0) || defined(CANFD1) || defined(CANFD2) || defined(CANFD3)
	// lock
	SYS->REGLCTL = 0x00;
#endif

	// SPI0, SPI1, SPI2, SPI3의 클럭 소스를 PLL로 변경
#if defined(__M46x_SUBFAMILY)

#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	reg = CLK->CLKSEL2;
	reg &= ~(CLK_CLKSEL2_SPI0SEL_Msk | CLK_CLKSEL2_SPI1SEL_Msk | CLK_CLKSEL2_SPI2SEL_Msk | CLK_CLKSEL2_SPI3SEL_Msk);
	reg |= (1 << CLK_CLKSEL2_SPI0SEL_Pos) | (1 << CLK_CLKSEL2_SPI1SEL_Pos) | (1 << CLK_CLKSEL2_SPI2SEL_Pos) | (1 << CLK_CLKSEL2_SPI3SEL_Pos);
	CLK->CLKSEL2 = reg;
#endif

	// GPIO 활성화
#if defined(__M46x_SUBFAMILY)
	CLK->AHBCLK0 |= CLK_AHBCLK0_GPACKEN_Msk | CLK_AHBCLK0_GPBCKEN_Msk | CLK_AHBCLK0_GPCCKEN_Msk | CLK_AHBCLK0_GPDCKEN_Msk | CLK_AHBCLK0_GPECKEN_Msk | CLK_AHBCLK0_GPFCKEN_Msk | CLK_AHBCLK0_GPGCKEN_Msk | CLK_AHBCLK0_GPHCKEN_Msk;
	CLK->AHBCLK1 |= CLK_AHBCLK1_GPICKEN_Msk | CLK_AHBCLK1_GPJCKEN_Msk;
#endif
}

void initializeDma(void)
{
	// DMA1
	dmaChannel1.enableClock();
	dmaChannel1.initialize();
	dmaChannel1.enableInterrupt();
}

extern "C"
{
	void SystemCoreClockUpdate(void)
	{

	}
}

#if defined(HSE_CLOCK_FREQ) && (HSE_CLOCK_FREQ % 4000000) != 0
#error "크리스탈은 반드시 4MHz의 배수를 사용해야 합니다."
#endif

#endif


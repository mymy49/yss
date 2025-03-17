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
#include <targets/nuvoton/bitfield_m4xx.h>

#if defined(__M480_FAMILY)
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
	
	// UART0, UART1의 클럭 소스를 PLL로 변경
	reg = CLK->CLKSEL1;
	reg &= ~(CLK_CLKSEL1_UART0SEL_Msk | CLK_CLKSEL1_UART1SEL_Msk);
	reg |= (1 << CLK_CLKSEL1_UART0SEL_Pos) | (1 << CLK_CLKSEL1_UART1SEL_Pos);
	CLK->CLKSEL1 = reg;

	// UART2, UART3의 클럭 소스를 PLL로 변경
	reg = CLK->CLKSEL3;
	reg &= ~(CLK_CLKSEL3_UART2SEL_Msk | CLK_CLKSEL3_UART3SEL_Msk);
	reg |= (1 << CLK_CLKSEL3_UART2SEL_Pos) | (1 << CLK_CLKSEL3_UART3SEL_Pos);
	CLK->CLKSEL3 = reg;

	// TIMER0, TIMER1, TIMER2, TIMER3의 클럭 소스를 PCLK로 변경
	reg = CLK->CLKSEL1;
	reg &= ~(CLK_CLKSEL1_TMR0SEL_Msk | CLK_CLKSEL1_TMR1SEL_Msk | CLK_CLKSEL1_TMR2SEL_Msk | CLK_CLKSEL1_TMR3SEL_Msk);
	reg |= (2 << CLK_CLKSEL1_TMR0SEL_Pos) | (2 << CLK_CLKSEL1_TMR1SEL_Pos) | (2 << CLK_CLKSEL1_TMR2SEL_Pos) | (2 << CLK_CLKSEL1_TMR3SEL_Pos);
	CLK->CLKSEL1 = reg;

	// SPI0, SPI1, SPI2, SPI3의 클럭 소스를 PLL로 변경
	reg = CLK->CLKSEL2;
	reg &= ~(CLK_CLKSEL2_SPI0SEL_Msk | CLK_CLKSEL2_SPI1SEL_Msk | CLK_CLKSEL2_SPI2SEL_Msk | CLK_CLKSEL2_SPI3SEL_Msk);
	reg |= (1 << CLK_CLKSEL2_SPI0SEL_Pos) | (1 << CLK_CLKSEL2_SPI1SEL_Pos) | (1 << CLK_CLKSEL2_SPI2SEL_Pos) | (1 << CLK_CLKSEL2_SPI3SEL_Pos);
	CLK->CLKSEL2 = reg;
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


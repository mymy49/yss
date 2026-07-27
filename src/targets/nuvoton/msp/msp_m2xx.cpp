/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file msp_m2xx.cpp
 * @brief MCU Support Package (MSP) system/peripheral clock configuration for Nuvoton M2xx.
 */

#include <drv/peripheral.h>

#if defined(__M25x_FAMILY)

#include <config.h>
#include <yss/instance.h>

#if defined(__M251_SUBFAMILY)
#define FBDIV_VALUE		(24)
#define EADC_MAX_CLK	(14000000)
#endif

void __WEAK initializeSystem(void)
{
	uint32_t srcClk, reg;

	// Enable External High-Speed Crystal clock (HXT)
#if defined(HXT_CLOCK_FREQ)
	clock.enableHxt(HXT_CLOCK_FREQ);
	srcClk = HXT_CLOCK_FREQ;
#else
	srcClk = clock.getHircFrequency() / 4;
#endif

	clock.enablePll
	(
#if defined(HXT_CLOCK_FREQ)
		Clock::PLL_SRC_HXT,
#else
		Clock::PLL_SRC_HIRC,
#endif
		srcClk / 4000000,
		FBDIV_VALUE,
		1
	);

	clock.setHclkClockSource(Clock::HCLK_SRC_PLL, 0, 1, 1); 

	// Change clock source of UART0 and UART1 to PLL
	setTwoFieldsData(CLK->CLKSEL1,	CLK_CLKSEL1_UART0SEL_Msk, 1, CLK_CLKSEL1_UART0SEL_Pos, 
									CLK_CLKSEL1_UART1SEL_Msk, 1, CLK_CLKSEL1_UART1SEL_Pos);

	// Change clock source of UART2 and UART3 to PLL
	setTwoFieldsData(CLK->CLKSEL3,	CLK_CLKSEL3_UART2SEL_Msk, 1, CLK_CLKSEL3_UART2SEL_Pos, 
									CLK_CLKSEL3_UART3SEL_Msk, 1, CLK_CLKSEL3_UART3SEL_Pos);

	// Change EADC clock frequency below the maximum operating frequency
	srcClk = clock.getApb0ClockFrequency();
	srcClk = (srcClk + EADC_MAX_CLK - 1) / EADC_MAX_CLK;
	if(srcClk > 0)
		srcClk--;

	setFieldData(CLK->CLKDIV0, CLK_CLKDIV0_EADCDIV_Msk, srcClk, CLK_CLKDIV0_EADCDIV_Pos);
	

	// Change clock source of TIMER0, TIMER1, TIMER2, and TIMER3 to PCLK
	setTwoFieldsData(CLK->CLKSEL1,	CLK_CLKSEL1_TMR0SEL_Msk, 2, CLK_CLKSEL1_TMR0SEL_Pos, 
									CLK_CLKSEL1_TMR1SEL_Msk, 2, CLK_CLKSEL1_TMR1SEL_Pos);
	setTwoFieldsData(CLK->CLKSEL1,	CLK_CLKSEL1_TMR2SEL_Msk, 2, CLK_CLKSEL1_TMR2SEL_Pos, 
									CLK_CLKSEL1_TMR3SEL_Msk, 2, CLK_CLKSEL1_TMR3SEL_Pos);
/*
	// Change clock source of SPI0, SPI1, SPI2, and SPI3 to PLL
	reg = CLK->CLKSEL2;
	reg &= ~(CLK_CLKSEL2_SPI0SEL_Msk | CLK_CLKSEL2_SPI1SEL_Msk | CLK_CLKSEL2_SPI2SEL_Msk | CLK_CLKSEL2_SPI3SEL_Msk);
	reg |= (1 << CLK_CLKSEL2_SPI0SEL_Pos) | (1 << CLK_CLKSEL2_SPI1SEL_Pos) | (1 << CLK_CLKSEL2_SPI2SEL_Pos) | (1 << CLK_CLKSEL2_SPI3SEL_Pos);
	CLK->CLKSEL2 = reg;
*/
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

#if defined(HXT_CLOCK_FREQ) && (HXT_CLOCK_FREQ % 4000000) != 0
#error "The crystal frequency must be a multiple of 4MHz."
#endif

#endif


/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__MA35H0_FAMILY)

#include <targets/nuvoton/NuvotonClock.h>
#include <yss/reg.h>
#include <drv/peripheral.h>

/**
 * @file drv_clock_nuvoton.cpp
 * @brief Clock controller target-specific driver source file for Nuvoton.
 */

#include <util/runtime.h>
#if defined(__MA35H0_FAMILY)
#define MAX_HCLK_FREQ	200000000
#define MAX_PCLK0_FREQ	100000000
#define MAX_PCLK1_FREQ	100000000
#define HXT_CLK_FREQ	 24000000
#define HIRC_CLK_FREQ	 12000000
#define LIRC_CLK_FREQ	    10000
#define FVCO_MIN_FREQ	200000000
#define FVCO_MAX_FREQ	500000000
#define FOUT_MIN_FREQ	 50000000
#define FOUT_MAX_FREQ	500000000
#endif

uint32_t Clock::getHircFrequency(void)
{
	return HIRC_CLK_FREQ;
}

uint32_t Clock::getHxtFrequency(void)
{
	return HXT_CLK_FREQ;
}

uint32_t Clock::getLircFrequency(void)
{
	return LIRC_CLK_FREQ;
}
#if 0

error_t Clock::setHclkClockSource(hclkSrc_t src, uint8_t hclkDiv, uint8_t pclk0Div, uint8_t pclk1Div)
{
	uint32_t clk, buf;
	volatile uint32_t reg;

	if(hclkDiv > 15 || pclk0Div > 15 || pclk1Div > 15)
		return error_t::WRONG_CONFIG;

	switch(src)
	{
	case HCLK_SRC_HIRC :
		clk = HIRC_CLK_FREQ;
		break;

	case HCLK_SRC_HXT :
		clk = gHxtFreq;
		break;
	
	case HCLK_SRC_PLL :
		clk = getPllFrequency();
		if(hclkDiv != 0)
			return error_t::WRONG_CONFIG;
		break;
#if defined(__M251_SUBFAMILY)
	case HCLK_SRC_MIRC :
		clk = getMircFrequency();
		break;
#endif
	case HCLK_SRC_LRIC :
		clk = getLircFrequency();
		break;
	
	case HCLK_SRC_LXT :
		clk = getLircFrequency();
		break;

	default :
		return error_t::WRONG_CONFIG;
	}
	
	clk /= hclkDiv + 1;
	if(clk > MAX_HCLK_FREQ)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	buf = clk / (1 << pclk0Div);
	if(buf > MAX_PCLK0_FREQ)
		return error_t::WRONG_CLOCK_FREQUENCY;

	buf = clk / (1 << pclk1Div);
	if(buf > MAX_PCLK1_FREQ)
		return error_t::WRONG_CLOCK_FREQUENCY;

	// Register Unlock sequence
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;

#if defined(__M480_FAMILY)
	FMC->CYCCTL = clk / 27000000 + 1;
#elif defined(__M46x_SUBFAMILY)
	FMC->CYCCTL = clk / 25000000;
#elif defined(__M25x_FAMILY)
	if(clk < 19000000)
		FMC->CYCCTL = 1;
	else if(clk < 33000000)
		FMC->CYCCTL = 2;
	else
		FMC->CYCCTL = 3;
#endif

	reg = CLK->CLKDIV0;
	reg &= ~(CLK_CLKDIV0_HCLKDIV_Msk);
	reg |= hclkDiv << CLK_CLKDIV0_HCLKDIV_Pos;
	CLK->CLKDIV0 = reg;
	
	reg = CLK->PCLKDIV;
	reg &= ~(CLK_PCLKDIV_APB0DIV_Msk | CLK_PCLKDIV_APB1DIV_Msk);
	reg |= (pclk0Div << CLK_PCLKDIV_APB0DIV_Pos) | (pclk1Div << CLK_PCLKDIV_APB1DIV_Pos);
	CLK->PCLKDIV = reg;

	reg = CLK->CLKSEL0;
	reg &= ~CLK_CLKSEL0_HCLKSEL_Msk;
	reg |= src << CLK_CLKSEL0_HCLKSEL_Pos;
	CLK->CLKSEL0 = reg;

	// Register Lock
	SYS->REGLCTL = 0x00;
		
	return error_t::ERROR_NONE;
}

void Clock::enableAhb0Clock(uint32_t position, bool en)
{
#if defined(__M46x_SUBFAMILY)
	__disable_irq();	
	if(en)
		CLK->AHBCLK0 |= 1 << position;
	else
		CLK->AHBCLK0 &= ~(1 << position);		
	__enable_irq();
#elif defined(__M480_FAMILY) || defined(__M43x_SUBFAMILY) || defined(__M25x_FAMILY)
	__disable_irq();	
	if(en)
		CLK->AHBCLK |= 1 << position;
	else
		CLK->AHBCLK &= ~(1 << position);		
	__enable_irq();
#endif
}

void Clock::enableAhb1Clock(uint32_t position, bool en)
{
#if defined(__M46x_SUBFAMILY)
	__disable_irq();	
	if(en)
		CLK->AHBCLK1 |= 1 << position;
	else
		CLK->AHBCLK1 &= ~(1 << position);		
	__enable_irq();
#elif defined(__M480_FAMILY) || defined(__M43x_SUBFAMILY) || defined(__M25x_FAMILY)
#endif
}

void Clock::enableApb0Clock(uint32_t position, bool en)
{
	__disable_irq();	
	if(en)
		CLK->APBCLK0 |= 1 << position;
	else
		CLK->APBCLK0 &= ~(1 << position);		
	__enable_irq();
}

void Clock::enableApb1Clock(uint32_t position, bool en)
{
	__disable_irq();	
	if(en)
		CLK->APBCLK1 |= 1 << position;
	else
		CLK->APBCLK1 &= ~(1 << position);		
	__enable_irq();
}

void Clock::enableApb2Clock(uint32_t position, bool en)
{
#if defined(__M46x_SUBFAMILY)
	__disable_irq();	
	if(en)
		CLK->APBCLK2 |= 1 << position;
	else
		CLK->APBCLK2 &= ~(1 << position);		
	__enable_irq();
#endif
}

uint32_t Clock::getHclkClockFrequency(void)
{
	uint32_t clk;

	switch((CLK->CLKSEL0 & CLK_CLKSEL0_HCLKSEL_Msk) >> CLK_CLKSEL0_HCLKSEL_Pos)
	{
	case 0 : // HXT
		clk = gHxtFreq;
		break;
	
	case 1 : // LXT
		// Currently not supported.
		return 0;
		break;
	
	case 2 : // PLL
		clk = getPllFrequency();
		break;
	
	case 3 : // LIRC
		clk = LIRC_CLK_FREQ;
		break;
#if defined(__M251_SUBFAMILY)	
	case 5 : // MIRC
		clk = getMircFrequency();
		break;
#endif
	case 7 : // HIRC
		clk = HIRC_CLK_FREQ;
		break;
	
	default :
		return 0;
	}

	clk /= ((CLK->CLKDIV0 & CLK_CLKDIV0_HCLKDIV_Msk) >> CLK_CLKDIV0_HCLKDIV_Pos) + 1;

	return clk;
}

uint32_t Clock::getApb0ClockFrequency(void)
{
	uint32_t clk = getHclkClockFrequency();

	clk /= 1 << ((CLK->PCLKDIV & CLK_PCLKDIV_APB0DIV_Msk) >> CLK_PCLKDIV_APB0DIV_Pos);

	return clk;
}

uint32_t Clock::getApb1ClockFrequency(void)
{
	uint32_t clk = getHclkClockFrequency();

	clk /= 1 << ((CLK->PCLKDIV & CLK_PCLKDIV_APB1DIV_Msk) >> CLK_PCLKDIV_APB1DIV_Pos);

	return clk;
}

void Clock::enterIdleMode(void)
{
	CLK->PWRCTL &= ~CLK_PWRCTL_PDEN_Msk;
	SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

	runtime::stop();
	__WFI();
	runtime::start();

	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

void Clock::enterPowerDownMode(void)
{
	CLK->PWRCTL |= CLK_PWRCTL_PDEN_Msk;
	SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
	
	runtime::stop();
	__WFI();
	runtime::start();
}

error_t Clock::enableLirc(bool en)
{
	// Register Unlock sequence
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;
	
	setBitData(CLK->PWRCTL, en, CLK_PWRCTL_LIRCEN_Pos);
	
	// Register Lock
	SYS->REGLCTL = 0x00;
	
	if(en)
	{
		while(~CLK->STATUS & CLK_STATUS_LIRCSTB_Msk)
			;
	}

	return error_t::ERROR_NONE;
}

#if defined(__M251_SUBFAMILY)
error_t Clock::enableMirc(bool en)
{
	// Register Unlock sequence
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;
	
	setBitData(CLK->PWRCTL, en, CLK_PWRCTL_MIRCEN_Pos);
	
	// Register Lock
	SYS->REGLCTL = 0x00;
	
	if(en)
	{
		while(~CLK->STATUS & CLK_STATUS_MIRCSTB_Msk)
			;
	}

	return error_t::ERROR_NONE;
}
#endif

error_t Clock::enableHirc(bool en)
{
	// Register Unlock sequence
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;
	
	setBitData(CLK->PWRCTL, en, CLK_PWRCTL_HIRCEN_Pos);
	
	// Register Lock
	SYS->REGLCTL = 0x00;
	
	if(en)
	{
		while(~CLK->STATUS & CLK_STATUS_HIRCSTB_Msk)
			;
	}

	return error_t::ERROR_NONE;
}
#endif

#endif


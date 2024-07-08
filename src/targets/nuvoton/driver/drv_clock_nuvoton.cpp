////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m48x.h>

#if defined(__M480_FAMILY)
#define MAX_HCLK_FREQ	192000000
#define MAX_PCLK0_FREQ	96000000
#define MAX_PCLK1_FREQ	96000000
#elif defined(__M43x_FAMILY)
#define MAX_HCLK_FREQ	144000000
#define MAX_PCLK0_FREQ	72000000
#define MAX_PCLK1_FREQ	72000000
#endif

static uint32_t gHxtFreq __attribute__((section(".non_init")));

error_t Clock::enableHxt(uint32_t hseHz)
{
	gHxtFreq = hseHz;
	
	// PF 2, 3번 핀을 입력으로 전환
	PF->MODE &= ~(GPIO_MODE_MODE2_Msk | GPIO_MODE_MODE3_Msk);	
	
	// unlock	
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;

	// HXT 활성화
	CLK->PWRCTL |= CLK_PWRCTL_HXTEN_Msk;

	for (uint32_t i = 0; i < 1000000; i++)
	{
		if (CLK->STATUS & CLK_STATUS_HXTSTB_Msk)
		{
			// lock
			SYS->REGLCTL = 0x00;
			return error_t::ERROR_NONE;
		}
	}

	// lock
	SYS->REGLCTL = 0x00;
	return error_t::TIMEOUT;
}

uint32_t Clock::getHircFrequency(void)
{
	return 12000000;
}

uint32_t Clock::getHxtFrequency(void)
{
	return gHxtFreq;
}

error_t Clock::enablePll(pllSrc_t src, uint8_t indiv, uint16_t fbdiv, uint8_t outdiv)
{
	uint32_t clk, reg = CLK->PLLCTL;

	if(indiv > 63 || fbdiv > 511 || outdiv > 3)
		return error_t::WRONG_CONFIG;
	
	switch(src)
	{
	case PLL_SRC_HIRC :
		clk = getHircFrequency();
		reg |= CLK_PLLCTL_PLLSRC_Msk;
		break;
	
	case PLL_SRC_HXT :
		clk = gHxtFreq;
		reg &= ~CLK_PLLCTL_PLLSRC_Msk;
		break;
	
	default :
		return error_t::WRONG_CONFIG;
	}

	// STBSEL 설정
	if(clk <= 12000000)
		reg &= ~CLK_PLLCTL_STBSEL_Msk;
	else
		reg |= CLK_PLLCTL_STBSEL_Msk;
	
	// FREF 범위 확인
	clk = clk / (indiv + 1);
	if(4000000 > clk || clk > 8000000)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	// FVCO 범위 확인
	clk = clk * 2 * (fbdiv + 2);
	if(200000000 > clk || clk > 500000000)
		return error_t::WRONG_CLOCK_FREQUENCY;

	// FOUT 범위 확인
	switch(outdiv)
	{
	case 1 :
	case 2 :
		clk /= 2;
		break;
	case 3 :
		clk /= 4;
		break;	
	}
	if(50000000 > clk || clk > 500000000)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	// unlock	
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;
	
	reg &= ~(CLK_PLLCTL_BP_Msk | CLK_PLLCTL_OE_Msk | CLK_PLLCTL_OUTDIV_Msk | CLK_PLLCTL_INDIV_Msk | CLK_PLLCTL_FBDIV_Msk);
	reg |= (indiv << CLK_PLLCTL_INDIV_Pos) | (fbdiv << CLK_PLLCTL_FBDIV_Pos) | (outdiv << CLK_PLLCTL_OUTDIV_Pos);

	CLK->PLLCTL = reg;
	CLK->PLLCTL &= ~(CLK_PLLCTL_PD_Msk);
	
	for (uint32_t i = 0; i < 1000000; i++)
	{
		if (CLK->STATUS & CLK_STATUS_PLLSTB_Msk)
		{
			// lock
			SYS->REGLCTL = 0x00;
			return error_t::ERROR_NONE;
		}
	}

	// lock
	SYS->REGLCTL = 0x00;
	return error_t::TIMEOUT;
}

uint32_t Clock::getPllFrequency(void)
{
	uint32_t clk;

	switch((CLK->PLLCTL & CLK_PLLCTL_PLLSRC_Msk) >> CLK_PLLCTL_PLLSRC_Pos)
	{
	case PLL_SRC_HIRC :
		clk = getHircFrequency();
		break;		
	
	case PLL_SRC_HXT :
		clk = gHxtFreq;
		break;
	}
	
	clk /= ((CLK->PLLCTL & CLK_PLLCTL_INDIV_Msk) >> CLK_PLLCTL_INDIV_Pos) + 1;
	clk *= (((CLK->PLLCTL & CLK_PLLCTL_FBDIV_Msk) >> CLK_PLLCTL_FBDIV_Pos) + 2) * 2;

	switch((CLK->PLLCTL & CLK_PLLCTL_OUTDIV_Msk) >> CLK_PLLCTL_OUTDIV_Pos)
	{
	case 1 :
	case 2 :
		clk /= 2;
		break;
	
	case 3 :
		clk /= 4;
		break;
	}

	return clk;
}

error_t Clock::setHclkClockSource(hclkSrc_t src, uint8_t hclkDiv, uint8_t pclk0Div, uint8_t pclk1Div)
{
	uint32_t clk, buf;
	volatile uint32_t reg;

	if(hclkDiv > 15 || pclk0Div > 15 || pclk1Div > 15)
		return error_t::WRONG_CONFIG;

	switch(src)
	{
	case HCLK_SRC_HXT :
		clk = gHxtFreq;
		break;
	
	case HCLK_SRC_PLL :
		clk = getPllFrequency();
		if(hclkDiv != 0)
			return error_t::WRONG_CONFIG;
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

	// unlock	
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;

	FMC->CYCCTL = clk / 27000000 + 1;
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

	// lock
	SYS->REGLCTL = 0x00;
		
	return error_t::ERROR_NONE;
}

void Clock::enableAhbClock(uint32_t position, bool en)
{
	__disable_irq();	
	if(en)
		CLK->AHBCLK |= 1 << position;
	else
		CLK->AHBCLK &= ~(1 << position);		
	__enable_irq();
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

#endif


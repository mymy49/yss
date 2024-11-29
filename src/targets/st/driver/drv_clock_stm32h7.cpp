/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32H7)

#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

#if defined(STM32H723xx)
// HSE
#define HSI_FREQ					64000000
#define CSI_FREQ					4000000
#define HSE_MIN_FREQ				4000000
#define HSE_MAX_FREQ				50000000
#define PLL_M_MAX					63
#define PLL_N_MIN					3
#define PLL_N_MAX					511
#define PLL_DIV_MAX					127
#define VCO_WIDE_MIN_FREQ			192000000
#define VCO_WIDE_MAX_FREQ			836000000
#define VCO_MED_MIN_FREQ			150000000
#define VCO_MED_MAX_FREQ			420000000
#define PLL_WIDE_VOS0_MAX_FREQ		550000000
#define PLL_WIDE_VOS1_MAX_FREQ		400000000
#define PLL_WIDE_VOS2_MAX_FREQ		300000000
#define PLL_WIDE_VOS3_MAX_FREQ		170000000
#define PLL_MED_VOS0_MAX_FREQ		210000000
#define PLL_MED_VOS1_MAX_FREQ		210000000
#define PLL_MED_VOS2_MAX_FREQ		210000000
#define PLL_MED_VOS3_MAX_FREQ		200000000
#endif

uint32_t Clock::mHseFreq __attribute__((section(".non_init")));
//static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
//static const uint32_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

error_t Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	mHseFreq = hseHz;

	if (hseHz < HSE_MIN_FREQ && HSE_MAX_FREQ < hseHz)
		return error_t::WRONG_CLOCK_FREQUENCY;

	if (useOsc)
		RCC->CR |= RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk;
	else
		RCC->CR |= RCC_CR_HSEON_Msk;

	for (uint32_t i = 0; i < 1000000; i++)
	{
		if (RCC->CR & RCC_CR_HSERDY_Msk)
			return error_t::ERROR_NONE;
	}

	return error_t::TIMEOUT;
}

error_t Clock::setVoltageScaling(vos_t vos)
{
	uint32_t reg = PWR->D3CR;
	reg &= ~PWR_D3CR_VOS_Msk;
	reg |= vos << PWR_D3CR_VOS_Pos;
	PWR->D3CR = reg;

	for (uint32_t i = 0; i < 1000000; i++)
	{
		if(PWR->CSR1 & PWR_CSR1_ACTVOSRDY)
			return error_t::ERROR_NONE;
	}

	return error_t::TIMEOUT;
}

error_t Clock::setPllSource(pllsrc_t pllsrc)
{
	switch(pllsrc)
	{
	case PLL_SRC_HSI :
		if(~RCC->CR & RCC_CR_HSIRDY_Msk)
			return error_t::CLK_SRC_NOT_ABLE;
		break;
	
	case PLL_SRC_HSE :
		if(~RCC->CR & RCC_CR_HSERDY_Msk)
			return error_t::CLK_SRC_NOT_ABLE;
		break;
	
	case PLL_SRC_CSI :
		if(~RCC->CR & RCC_CR_CSIRDY_Msk)
			return error_t::CLK_SRC_NOT_ABLE;
		break;

	default :
		return  error_t::WRONG_CONFIG;
	}

	uint32_t reg = RCC->PLLCKSELR;
	reg &= ~RCC_PLLCKSELR_PLLSRC_Msk;
	reg |= pllsrc << RCC_PLLCKSELR_PLLSRC_Pos;
	RCC->PLLCKSELR = reg;
}

error_t Clock::enablePll1(uint8_t m, uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	// 현재 SysClk 소스가 PLL인이 확인
	if (getFieldData(RCC->CFGR, RCC_CFGR_SWS_Msk, RCC_CFGR_SWS_Pos) == RCC_CFGR_SWS_PLL1)
		return error_t::SYSCLK_SRC_IS_PLL;

	if (m > PLL_M_MAX || m == 0)
		return error_t::WRONG_CONFIG;

	if (PLL_N_MIN > n || n > PLL_N_MAX)
		return error_t::WRONG_CONFIG;

	if (pDiv > PLL_DIV_MAX || qDiv > PLL_DIV_MAX || rDiv > PLL_DIV_MAX)
		return error_t::WRONG_CONFIG;

	uint32_t vco, pFreq, qFreq, rFreq, max, vos, reg;

	switch((RCC->PLLCKSELR & RCC_PLLCKSELR_PLLSRC_Msk) >> RCC_PLLCKSELR_PLLSRC_Pos)
	{
	case PLL_SRC_HSI :
		vco = HSI_FREQ;
		break;
	
	case PLL_SRC_HSE :
		vco = mHseFreq;
		break;
	
	case PLL_SRC_CSI :
		vco = CSI_FREQ;
		break;

	default :
		return  error_t::WRONG_CONFIG;
	}

	vco /= m;
	vco *= n + 1;
	if(vco < VCO_MED_MIN_FREQ || vco > VCO_WIDE_MAX_FREQ)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	vos = (PWR->D3CR & PWR_D3CR_VOS_Msk) >> (PWR_D3CR_VOS_Pos - 1);

	// VCOSEL 설정
	if(vco < VCO_MED_MAX_FREQ)
	{
		RCC->PLLCFGR |= RCC_PLLCFGR_PLL1VCOSEL_Msk;
		vos |= 1;
	}
	else
		RCC->PLLCFGR &= ~RCC_PLLCFGR_PLL1VCOSEL_Msk;

	pFreq = vco / (pDiv + 1);
	qFreq = vco / (qDiv + 1);
	rFreq = vco / (rDiv + 1);

	switch(vos)
	{
	case 0 : // VOS = 0, VCOSEL = WIDE
		max = PLL_WIDE_VOS0_MAX_FREQ;
		break;

	case 1 : // VOS = 0, VCOSEL = MED
		max = PLL_MED_VOS0_MAX_FREQ;
		break;

	case 2 : // VOS = 3, VCOSEL = WIDE
		max = PLL_WIDE_VOS3_MAX_FREQ;
		break;

	case 3 : // VOS = 3, VCOSEL = MED
		max = PLL_MED_VOS3_MAX_FREQ;
		break;

	case 4 : // VOS = 2, VCOSEL = WIDE
		max = PLL_WIDE_VOS2_MAX_FREQ;
		break;

	case 5 : // VOS = 2, VCOSEL = MED
		max = PLL_MED_VOS2_MAX_FREQ;
		break;

	case 6 : // VOS = 1, VCOSEL = WIDE
		max = PLL_WIDE_VOS1_MAX_FREQ;
		break;

	case 7 : // VOS = 1, VCOSEL = MED
		max = PLL_MED_VOS1_MAX_FREQ;
		break;

	default :
		return error_t::UNKNOWN;
	}

	if(pFreq > max || qFreq > max || rFreq > max)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	setFieldData(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM1_Msk, m, RCC_PLLCKSELR_DIVM1_Pos);
	setFourFieldData(RCC->PLL1DIVR, RCC_PLL1DIVR_R1_Msk, rDiv, RCC_PLL1DIVR_R1_Pos, 
									RCC_PLL1DIVR_Q1_Msk, qDiv, RCC_PLL1DIVR_Q1_Pos, 
									RCC_PLL1DIVR_P1_Msk, pDiv, RCC_PLL1DIVR_P1_Pos, 
									RCC_PLL1DIVR_N1_Msk, n, RCC_PLL1DIVR_N1_Pos);

	setBitData(RCC->CR, true, RCC_CR_PLL1ON_Pos); 

	for (uint32_t i = 0; i < 1000000; i++)
	{
		if (RCC->CR & RCC_CR_PLL1RDY_Msk)
			return error_t::ERROR_NONE;
	}

	return error_t::ERROR_NONE;
}


#endif


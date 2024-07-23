/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(W7500)

#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/wiznet/bitfield_w7500x.h>

static uint32_t gHseFreq __attribute__((section(".non_init")));

error_t Clock::enableOsc(uint32_t hseHz)
{
	gHseFreq = hseHz;

	CRG->OSC_PDR &= ~CRG_OSC_PDR_OSCPD;

	return error_t::ERROR_NONE;
}

uint32_t Clock::getRclkFrequency(void)
{
	return 8000000;
}

uint32_t Clock::getOclkFrequency(void)
{
	return gHseFreq;
}

uint32_t Clock::getMclkFrequency(void)
{
	uint32_t clk, od;

	// PLL 출력 활성화 확인
	if(~CRG->PLL_OER & CRG_PLL_OER_PLLOEN)
		return 0;
	
	// PLL 소스 확인
	if(CRG->PLL_IFSR & CRG_PLL_IFSR_PLLIS)
		clk = getOclkFrequency();
	else
		clk = getRclkFrequency();
	
	// PLL 출력이 바이패스 설정되어 있는지 확인
	if(CRG->PLL_BPR & CRG_PLL_BPR_PLLBP)
		return clk;
	
	od = ((CRG->PLL_FCR & CRG_PLL_FCR_OD) >> CRG_PLL_FCR_OD_Pos);
	od = 1 << od;
	clk = clk * ((CRG->PLL_FCR & CRG_PLL_FCR_M) >> CRG_PLL_FCR_M_Pos) / ((CRG->PLL_FCR & CRG_PLL_FCR_N) >> CRG_PLL_FCR_N_Pos) / od;

	return clk;
}

uint32_t Clock::getFclkFrequency(void)
{
	uint32_t clk = 0;

	switch(CRG->FCLK_SSR & CRG_FCLK_SSR_FCKSRC)
	{
	case 0 :
	case 1 :
		clk = getMclkFrequency();
		break;

	case 2 :
		clk = getRclkFrequency();
		break;

	case 3 :
		clk = getOclkFrequency();
		break;
	}

	return clk >> (CRG->FCLK_PVSR & CRG_FCLK_PVSR_FCKPRE);
}

error_t Clock::setPllFrequency(pllSrc_t src, uint8_t m, uint8_t n, uint8_t od)
{
	uint32_t clk, odVal;

	if(2 > m || m > 63 || 1 > n || n > 63 || od > 3)
		return error_t::WRONG_CONFIG;
	
	switch(src)
	{
	case PLL_SRC_RCLK :
		clk = getRclkFrequency();
		break;
	
	case PLL_SRC_OCLK :
		clk = getOclkFrequency();
		break;
	
	default :
		return error_t::WRONG_CONFIG;
	}

	odVal = 1 << od;
	clk = clk * m / n / odVal;

	if(clk > 48000000)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	CRG->PLL_FCR = 2 << CRG_PLL_FCR_M_Pos | 2 << CRG_PLL_FCR_N_Pos | 0 << CRG_PLL_FCR_M_Pos;
	CRG->PLL_IFSR = src;
	CRG->PLL_FCR = m << CRG_PLL_FCR_M_Pos | n << CRG_PLL_FCR_N_Pos | od << CRG_PLL_FCR_M_Pos;

	return error_t::ERROR_NONE;
}

#endif


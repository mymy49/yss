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


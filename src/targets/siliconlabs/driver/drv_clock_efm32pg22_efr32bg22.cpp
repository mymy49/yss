////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.1
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(EFM32PG22) || defined(EFR32BG22)

#include <drv/peripheral.h>
#include <drv/Clock.h>
#include <yss/reg.h>

#if defined(EFM32PG22)
#include <targets/siliconlabs/efm32pg22_hfxo.h>
#include <targets/siliconlabs/efm32pg22_cmu.h>
#include <targets/siliconlabs/efm32pg22_emu.h>
#include <targets/siliconlabs/efm32pg22_hfrco.h>
#include <targets/siliconlabs/efm32pg22_dpll.h>
#elif defined(EFR32BG22)
#include <targets/siliconlabs/efr32bg22_hfxo.h>
#include <targets/siliconlabs/efr32bg22_cmu.h>
#include <targets/siliconlabs/efr32bg22_emu.h>
#include <targets/siliconlabs/efr32bg22_hfrco.h>
#include <targets/siliconlabs/efr32bg22_dpll.h>
#endif

void Clock::initialize(void)
{
	mHfxoFrequency = 0;
}

error Clock::enableHfxo(uint16_t capacitorValue, uint16_t biasCurrent, uint32_t frequency)
{
	mHfxoFrequency = frequency;
	setThreeFieldData(HFXO0->XTALCTRL,	_HFXO_XTALCTRL_CTUNEXIANA_MASK, capacitorValue / 80, _HFXO_XTALCTRL_CTUNEXIANA_SHIFT,
										_HFXO_XTALCTRL_CTUNEXOANA_MASK,	capacitorValue / 80, _HFXO_XTALCTRL_CTUNEXOANA_SHIFT,
										_HFXO_XTALCTRL_COREBIASANA_MASK, biasCurrent / 10, _HFXO_XTALCTRL_COREBIASANA_SHIFT);

	setBitData(HFXO0->CTRL, true, _HFXO_CTRL_FORCEEN_SHIFT);

	for(uint32_t i=0;i<1000000;i++)
	{
		if(getBitData(HFXO0->STATUS, _HFXO_STATUS_RDY_SHIFT))
			return error::ERROR_NONE;
	}

	return error::TIMEOUT;
}

void Clock::enableApb0Clock(uint32_t position, bool enable)
{
	setBitData(CMU->CLKEN0, enable, position);
}

bool Clock::getApb0ClockEnabled(uint32_t position)
{
	return getBitData(CMU->CLKEN0, position);
}

uint32_t Clock::getApb0Frequency(void)
{
	uint32_t clk = getCoreClockFrequency();
	
	clk /= getBitData(CMU->SYSCLKCTRL, _CMU_SYSCLKCTRL_PCLKPRESC_SHIFT) + 1;

	return clk;
}

void Clock::enableApb1Clock(uint32_t position, bool enable)
{
	setBitData(CMU->CLKEN1, enable, position);
}

bool Clock::getApb1ClockEnabled(uint32_t position)
{
	return getBitData(CMU->CLKEN1, position);
}

uint32_t Clock::getApb1Frequency(void)
{
	uint32_t clk = getCoreClockFrequency();
	
	clk /= getBitData(CMU->SYSCLKCTRL, _CMU_SYSCLKCTRL_PCLKPRESC_SHIFT) + 1;

	return clk;
}

static const struct HfrcoCalTableElement{
  uint32_t  minFreq;
  uint32_t  maxFreq;
  uint32_t  value;
} gHfrcoCalTable[] =
{
  //  minFreq   maxFreq    HFRCOCAL value
  {  900000UL, 1080000UL, 0x82401F00UL},
  { 1080000UL, 1300000UL, 0xA2411F3AUL},
  { 1300000UL, 1530000UL, 0xA2421F3AUL},
  { 1530000UL, 1800000UL, 0xB6439F3AUL},
  { 1800000UL, 2150000UL, 0x81401F00UL},
  { 2150000UL, 2600000UL, 0xA1411F3AUL},
  { 2600000UL, 3050000UL, 0xA1421F3AUL},
  { 3050000UL, 3600000UL, 0xB5439F3AUL},
  { 3600000UL, 4300000UL, 0x80401F00UL},
  { 4300000UL, 5200000UL, 0xA0411F3AUL},
  { 5200000UL, 6100000UL, 0xA0421F3AUL},
  { 6100000UL, 7800000UL, 0xB4439F00UL},
  { 7800000UL, 9800000UL, 0xB4449F3AUL},
  { 9800000UL, 11800000UL, 0xB4459F3AUL},
  { 11800000UL, 14400000UL, 0xB4669F00UL},
  { 14400000UL, 17200000UL, 0xB4679F00UL},
  { 17200000UL, 19700000UL, 0xA8689F00UL},
  { 19700000UL, 23800000UL, 0xB8899F3AUL},
  { 23800000UL, 28700000UL, 0xB88A9F00UL},
  { 28700000UL, 34800000UL, 0xB8AB9F00UL},
  { 34800000UL, 42800000UL, 0xA8CC9F00UL},
  { 42800000UL, 51600000UL, 0xACED9F00UL},
  { 51600000UL, 60500000UL, 0xBCEE9F00UL},
  { 60500000UL, 72600000UL, 0xBCEF9F00UL},
  { 72600000UL, 80000000UL, 0xCCF09F00UL},
  { 80000000UL, 100000000UL, 0xCCF19F00UL}
};

#define HFRCOCALTABLE_ENTRIES (sizeof(gHfrcoCalTable) / sizeof(struct HfrcoCalTableElement))

error Clock::enableDpll(uint8_t dpllref, uint16_t n, uint16_t m)
{
	uint64_t clk;

	switch(dpllref)
	{
	case DPLLREF::DISABLED :
		return error::WRONG_CONFIG;
	
	case DPLLREF::HFXO :
		if(!getBitData(HFXO0->STATUS, _HFXO_STATUS_RDY_SHIFT))
			return error::HSE_NOT_READY;

		clk = mHfxoFrequency;
		break;
	
	case DPLLREF::LFXO_ :
		// 현재 이 설정은 지원 안됨
		return error::WRONG_CONFIG;
	
	case DPLLREF::CLKIN0 :
		// 현재 이 설정은 지원 안됨
		return error::WRONG_CONFIG;
	}

	n--;
	m--;

	if(n <= 300 || n >= 4096 || m >= 4096)
		return error::WRONG_CONFIG;

	clk = clk * (n + 1) / (m + 1);
	switch(getFieldData(EMU->STATUS, _EMU_STATUS_VSCALE_MASK, _EMU_STATUS_VSCALE_SHIFT))
	{
	case 0 : // VSCALE0
		// 현재 이 설정은 지원 안됨
		return error::WRONG_CONFIG;
	
	case 1 : // VSCALE1
		if(clk > 40000000)
			return error::WRONG_CLOCK_FREQUENCY;
	
	case 2 : // VSCALE2		
		if(clk > 76800000)
			return error::WRONG_CLOCK_FREQUENCY;
	}
	
	// DPLL을 활성화 시키기 전에, HFRCO0의 교정 값이 미리 설정되어 있어야 함.
	if(!getApb0ClockEnabled(_CMU_CLKEN0_HFRCO0_SHIFT) || !getBitData(HFRCO0->STATUS, _HFRCO_STATUS_RDY_SHIFT))
	{
		enableApb0Clock(_CMU_CLKEN0_HFRCO0_SHIFT, true);
		HFRCO0->CTRL_SET = _HFRCO_CTRL_FORCEEN_MASK;
		for(uint32_t i=0;i<HFRCOCALTABLE_ENTRIES;i++)
		{
			if(gHfrcoCalTable[i].minFreq <= clk && gHfrcoCalTable[i].maxFreq >= clk)
			{
				HFRCO0->CAL = gHfrcoCalTable[i].value;
			}
		}
	}

	enableApb0Clock(_CMU_CLKEN0_DPLL0_SHIFT, true);
	setFieldData(CMU->DPLLREFCLKCTRL, _CMU_DPLLREFCLKCTRL_MASK, dpllref, _CMU_DPLLREFCLKCTRL_CLKSEL_SHIFT);
	setTwoFieldData(DPLL0->CFG1, _DPLL_CFG1_N_MASK, n, _DPLL_CFG1_N_SHIFT, _DPLL_CFG1_M_MASK, m, _DPLL_CFG1_M_SHIFT);	
	DPLL0->EN_SET = _DPLL_EN_EN_MASK;

	for(uint32_t i=0;i<1000000;i++)
	{
		if(getBitData(DPLL0->STATUS, _DPLL_STATUS_RDY_SHIFT))
			return error::ERROR_NONE;
	}
	
	return error::TIMEOUT;
}

error Clock::setSysclk(uint8_t sysclkSel, uint8_t hclkDiv, uint8_t pclkDiv)
{
	hclkDiv--;
	pclkDiv--;

	if(hclkDiv > 15 || pclkDiv > 1)
		return error::WRONG_CONFIG;

	setThreeFieldData(CMU->SYSCLKCTRL,	_CMU_SYSCLKCTRL_HCLKPRESC_MASK, hclkDiv, _CMU_SYSCLKCTRL_HCLKPRESC_SHIFT,
										_CMU_SYSCLKCTRL_PCLKPRESC_MASK, pclkDiv, _CMU_SYSCLKCTRL_PCLKPRESC_SHIFT,
										_CMU_SYSCLKCTRL_CLKSEL_MASK, sysclkSel, _CMU_SYSCLKCTRL_CLKSEL_SHIFT);

	return error::ERROR_NONE;
}

uint32_t Clock::getCoreClockFrequency(void)
{
	uint64_t clk = 0, n, m;

	switch(getFieldData(CMU->SYSCLKCTRL, _CMU_SYSCLKCTRL_CLKSEL_MASK, _CMU_SYSCLKCTRL_CLKSEL_SHIFT))
	{
	case 1 : // FSRCO
		clk = 20000000;
		break;
	
	case 2 : // HFRCODPLL
		if(getApb0ClockEnabled(_CMU_CLKEN0_DPLL0_SHIFT) && getBitData(DPLL0->STATUS, _DPLL_STATUS_RDY_SHIFT))
		{
			n = getFieldData(DPLL0->CFG1, _DPLL_CFG1_N_MASK, _DPLL_CFG1_N_SHIFT) + 1;
			m = getFieldData(DPLL0->CFG1, _DPLL_CFG1_M_MASK, _DPLL_CFG1_M_SHIFT) + 1;
			clk = mHfxoFrequency * n / m;
		}
		else if(getApb0ClockEnabled(_CMU_CLKEN0_HFRCO0_SHIFT) && getBitData(HFRCO0->STATUS, _HFRCO_STATUS_RDY_SHIFT))
		{
			clk = getFieldData(HFRCO0->CAL, _HFRCO_CAL_FREQRANGE_MASK, _HFRCO_CAL_FREQRANGE_SHIFT);
//			clk = 
		}
		break;

	default :
		return 0;
	}
	
	m = getFieldData(CMU->SYSCLKCTRL, _CMU_SYSCLKCTRL_HCLKPRESC_MASK, _CMU_SYSCLKCTRL_HCLKPRESC_SHIFT) + 1;
	clk /= m;
		
	return clk;
}

#endif
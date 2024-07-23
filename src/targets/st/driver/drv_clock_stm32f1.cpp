/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(GD32F1) || defined(STM32F1)

#include <drv/peripheral.h>
#include <drv/Clock.h>
#include <yss/reg.h>

int32_t  gHseFreq __attribute__((section(".non_init")));
int32_t  gLseFreq __attribute__((section(".non_init")));

static const int16_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const int16_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

#if defined(STM32F103xB) || defined(STM32F103xE)

#include <targets/st/bitfield_stm32f103xx.h>

#define HSI_FREQ			8000000

#define AHB_MAX_FREQ		72000000
#define APB1_MAX_FREQ		36000000
#define APB2_MAX_FREQ		72000000
#define ADC_MAX_FREQ		14000000

#define HSE_MIN_FREQ		1000000
#define HSE_MAX_FREQ		25000000

#define PLL_IN_MIN_FREQ		1000000
#define PLL_IN_MAX_FREQ		25000000
#define PLL_OUT_MIN_FREQ	16000000
#define PLL_OUT_MAX_FREQ	72000000
#define PLL_SRC_MAX			1
#define PLL_MUL_MAX			14
#define PLL_XTPRE_MAX		1

#elif defined(GD32F1)

#include <targets/gigadevice/bitfield_gd32f10x.h>

#define HSI_FREQ			8000000

#define AHB_MAX_FREQ		108000000
#define APB1_MAX_FREQ		54000000
#define APB2_MAX_FREQ		108000000
#define ADC_MAX_FREQ		14000000

#define HSE_MIN_FREQ		1000000
#define HSE_MAX_FREQ		25000000

#define PLL_IN_MIN_FREQ		1000000
#define PLL_IN_MAX_FREQ		25000000
#define PLL_OUT_MIN_FREQ	32000000
#define PLL_OUT_MAX_FREQ	216000000
#define PLL_SRC_MAX			1
#define PLL_MUL_MAX			13
#define PLL_XTPRE_MAX		1

#endif

error_t Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	gHseFreq = hseHz;

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

error_t Clock::enableMainPll(pllSrc_t src, pllXtpre_t xtpre, uint8_t mul)
{
	uint32_t pll;

	using namespace define::clock::pll;
	
	// 현재 SysClk 소스가 PLL인이 확인
	if (getFieldData(RCC->CFGR, RCC_CFGR_SWS_Msk, RCC_CFGR_SWS_Pos) == define::clock::sysclk::src::PLL)
		goto error;

	if (src > PLL_SRC_MAX)
		goto error;

	if (xtpre > PLL_XTPRE_MAX)
		goto error;

	if (mul > PLL_MUL_MAX)
		goto error;

	if (src == pllSrc_t::PLL_SRC_HSE)
	{
		// HSE 활성화 확인
		if (getBitData(RCC->CR, RCC_CR_HSERDY_Pos))
			pll = gHseFreq;
		else
			goto error;

		if (xtpre == pllXtpre_t::PLL_XTPRE_DIV2)
			pll >>= 1;
	}
	else
		pll = HSI_FREQ / 2;

	if (pll < PLL_IN_MIN_FREQ || PLL_IN_MAX_FREQ < pll)
		goto error;

	if (mul > PLL_MUL_MAX)
		mul = PLL_MUL_MAX;

	pll *= (mul + 2);
	if (pll < PLL_OUT_MIN_FREQ || PLL_OUT_MAX_FREQ < pll)
		goto error;
		
	// PLL Factor 설정
#if defined(GD32F1)
#if defined(GD32F10X_CL)
	if(mul & 0x10)
		setBitData(RCC->CFGR, true, 29);
	else
		setBitData(RCC->CFGR, false, 29);
#else
	if(mul & 0x10)
		setBitData(RCC->CFGR, true, 27);
	else
		setBitData(RCC->CFGR, false, 27);
#endif
#endif

	setFieldData(RCC->CFGR, RCC_CFGR_PLLMULL_Msk, mul, RCC_CFGR_PLLMULL_Pos);

	setBitData(RCC->CFGR, xtpre, RCC_CFGR_PLLXTPRE_Pos);
	setBitData(RCC->CFGR, src, RCC_CFGR_PLLSRC_Pos);

	// PLL 활성화
	setBitData(RCC->CR, true, RCC_CR_PLLON_Pos);
	for (uint16_t i = 0; i < 10000; i++)
	{
		// PLL 활성화 확인
		if (getBitData(RCC->CR, RCC_CR_PLLRDY_Pos))
			return error_t::ERROR_NONE;
	}

	return error_t::TIMEOUT;

error:
	return error_t::WRONG_CLOCK_FREQUENCY;
}

error_t Clock::setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2)
{
	uint32_t clk, ahbClk, apb1Clk, apb2Clk, adcClk;
	uint8_t buf;

	using namespace define::clock::sysclk::src;
	switch (sysclkSrc)
	{
	case HSI:
		clk = HSI_FREQ;
		break;

	case HSE:
		// HSE 활성화 점검
		if (getBitData(RCC->CR, RCC_CR_HSERDY_Pos) == false)
			return error_t::HSE_NOT_READY;
		clk = gHseFreq;
		break;

	case PLL:
		// PLL 활성화 점검
		if (getBitData(RCC->CR, RCC_CR_PLLRDY_Pos) == false)
			return error_t::PLL_NOT_READY;
		clk = getMainPllFrequency();
		break;

	default:
		return error_t::WRONG_CONFIG;
	}

	ahbClk = clk / gHpreDiv[ahb];
	if (ahbClk > AHB_MAX_FREQ)
		return error_t::WRONG_CLOCK_FREQUENCY;

	apb1Clk = ahbClk / gPpreDiv[apb1];
	if (apb1Clk > APB1_MAX_FREQ)
		return error_t::WRONG_CLOCK_FREQUENCY;

	apb2Clk = ahbClk / gPpreDiv[apb2];
	if (apb2Clk > APB2_MAX_FREQ)
		return error_t::WRONG_CLOCK_FREQUENCY;

	adcClk = apb2Clk / (ADC_MAX_FREQ / 1000);
	if (adcClk >= 1000)
	{
		adcClk /= 1000;
		adcClk += 1;
		buf = adcClk / 2 - 1;
		
		// ADC 프리스케일러 설정
#if defined(GD32F1)
		if(buf & 0x04)
			setBitData(RCC->CFGR, true, RCC_CFGR_ADCPRE2_Pos);
		else
			setBitData(RCC->CFGR, false, RCC_CFGR_ADCPRE2_Pos);
#endif
		setFieldData(RCC->CFGR, RCC_CFGR_ADCPRE_Msk, buf, RCC_CFGR_ADCPRE_Pos);
	}
	
	// 버스 클럭 프리스케일러 설정
	setThreeFieldData(RCC->CFGR, RCC_CFGR_PPRE2_Msk, apb2, RCC_CFGR_PPRE2_Pos, RCC_CFGR_PPRE1_Msk, apb1, RCC_CFGR_PPRE1_Pos, RCC_CFGR_HPRE_Msk, ahb, RCC_CFGR_HPRE_Pos);
	
	// 클럭 소스 변경
	setFieldData(RCC->CFGR, RCC_CFGR_SW_Msk, sysclkSrc, RCC_CFGR_SW_Pos);

	return error_t::ERROR_NONE;
}

uint32_t Clock::getMainPllFrequency(void)
{
	using namespace define::clock::pll;

	if(getBitData(RCC->CFGR, RCC_CFGR_PLLSRC_Pos) == pllSrc_t::PLL_SRC_HSE)
		return gHseFreq / (((RCC->CFGR & RCC_CFGR_PLLXTPRE_Msk) >> RCC_CFGR_PLLXTPRE_Pos) + 1) * (((RCC->CFGR & RCC_CFGR_PLLMULL_Msk) >> RCC_CFGR_PLLMULL_Pos) + 2); 
	else
		return (HSI_FREQ / 2) / (((RCC->CFGR & RCC_CFGR_PLLXTPRE_Msk) >> RCC_CFGR_PLLXTPRE_Pos) + 1) * (((RCC->CFGR & RCC_CFGR_PLLMULL_Msk) >> RCC_CFGR_PLLMULL_Pos) + 2); 
}

uint32_t Clock::getSysclkFrequency(void)
{
	using namespace define::clock::sysclk;

	switch((RCC->CFGR & RCC_CFGR_SWS_Msk) >> RCC_CFGR_SWS_Pos)
	{
	case src::HSI :
		return HSI_FREQ;
		break;
	
	case src::HSE :
		return gHseFreq;
		break;
	
	case src::PLL :
		return getMainPllFrequency();
		break;

	default :
		return 0;
	}
}

uint32_t Clock::getAhbClockFrequency(void)
{
	return getSysclkFrequency() / gHpreDiv[((RCC->CFGR & RCC_CFGR_HPRE_Msk) >> RCC_CFGR_HPRE_Pos)];
}

uint32_t Clock::getApb1ClockFrequency(void)
{
	return getSysclkFrequency() / gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos)];
}

uint32_t Clock::getApb2ClockFrequency(void)
{
	return getSysclkFrequency() / gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos)];
}

void Clock::enableAhbClock(uint32_t position, bool en)
{
	setBitData(RCC->AHBENR, en, position);
}

void Clock::enableApb1Clock(uint32_t position, bool en)
{
	setBitData(RCC->APB1ENR, en, position);
}

void Clock::enableApb2Clock(uint32_t position, bool en)
{
	setBitData(RCC->APB2ENR, en, position);
}

void Clock::resetAhb(uint32_t position)
{
	(void)position;
}

void Clock::resetApb1(uint32_t position)
{
	setBitData(RCC->APB1RSTR, true, position);
	setBitData(RCC->APB1RSTR, false, position);
}

void Clock::resetApb2(uint32_t position)
{
	setBitData(RCC->APB2RSTR, true, position);
	setBitData(RCC->APB2RSTR, false, position);
}

#endif


/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F4)

#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

static uint32_t gHseFreq __attribute__((section(".non_init")));
static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const uint32_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

#if defined(SET_I2S_CKIN_FREQ_USE)
static uint32_t gI2sCkinFreq __attribute__((section(".non_init")));
#endif

#if defined(STM32F446xx)
// HSE
#define HSI_FREQ				16000000
#define HSE_MIN_FREQ			1000000
#define HSE_MAX_FREQ			50000000

// AHB
#define AHB_MAX_FREQ_SCALE1		180000000
#define AHB_MAX_FREQ_SCALE1_OVR	168000000
#define AHB_MAX_FREQ_SCALE2		168000000
#define AHB_MAX_FREQ_SCALE2_OVR	144000000
#define AHB_MAX_FREQ_SCALE3		120000000
#define AHB_MAX_FREQ_SCALE3_OVR	120000000

// Main PLL
#define PLL_VCO_MIN_FREQ		100000000
#define PLL_VCO_MAX_FREQ		432000000
#define PLL_P_MAX_FREQ			180000000
#define PLL_Q_MAX_FREQ			75000000
#define PLL_R_MAX_FREQ			180000000
#define PLL_M_MIN				2
#define PLL_M_MAX				63
#define PLL_N_MIN				50
#define PLL_N_MAX				432
#define PLL_P_MAX				3
#define PLL_Q_MIN				2
#define PLL_Q_MAX				15
#define PLL_R_MIN				2
#define PLL_R_MAX				7

#define I2SPLL_VCO_MIN_FREQ		100000000
#define I2SPLL_VCO_MAX_FREQ		432000000
#define I2SPLL_P_MAX_FREQ		216000000
#define I2SPLL_Q_MAX_FREQ		216000000
#define I2SPLL_R_MAX_FREQ		216000000
#define I2SPLL_N_MIN			50
#define I2SPLL_N_MAX			432
#define I2SPLL_M_MIN			2
#define I2SPLL_M_MAX			63
#define I2SPLL_P_MAX			3
#define I2SPLL_Q_MIN			2
#define I2SPLL_Q_MAX			15
#define I2SPLL_R_MIN			2
#define I2SPLL_R_MAX			7

#define SAIPLL_VCO_MIN_FREQ		100000000
#define SAIPLL_VCO_MAX_FREQ		432000000
#define SAIPLL_P_MAX_FREQ		216000000
#define SAIPLL_Q_MAX_FREQ		216000000
#define SAIPLL_N_MIN			50
#define SAIPLL_N_MAX			432
#define SAIPLL_P_MAX			3
#define SAIPLL_Q_MIN			2
#define SAIPLL_Q_MAX			15
#elif defined(STM32F407xx)
// HSE
#define HSI_FREQ				16000000
#define HSE_MIN_FREQ			1000000
#define HSE_MAX_FREQ			50000000

// AHB
#define AHB_MAX_FREQ_SCALE1		168000000
#define AHB_MAX_FREQ_SCALE2		144000000

// Main PLL
#define PLL_VCO_MIN_FREQ		100000000
#define PLL_VCO_MAX_FREQ		432000000
#define PLL_P_MAX_FREQ			180000000
#define PLL_Q_MAX_FREQ			75000000
#define PLL_R_MAX_FREQ			180000000
#define PLL_M_MIN				2
#define PLL_M_MAX				63
#define PLL_N_MIN				50
#define PLL_N_MAX				432
#define PLL_P_MAX				3
#define PLL_Q_MIN				2
#define PLL_Q_MAX				15
#define PLL_R_MIN				2
#define PLL_R_MAX				7

#define I2SPLL_VCO_MIN_FREQ		100000000
#define I2SPLL_VCO_MAX_FREQ		432000000
#define I2SPLL_P_MAX_FREQ		216000000
#define I2SPLL_Q_MAX_FREQ		216000000
#define I2SPLL_R_MAX_FREQ		216000000
#define I2SPLL_N_MIN			50
#define I2SPLL_N_MAX			432
#define I2SPLL_R_MIN			2
#define I2SPLL_R_MAX			7

#define SAIPLL_VCO_MIN_FREQ		100000000
#define SAIPLL_VCO_MAX_FREQ		432000000
#define SAIPLL_P_MAX_FREQ		216000000
#define SAIPLL_Q_MAX_FREQ		216000000
#define SAIPLL_N_MIN			50
#define SAIPLL_N_MAX			432
#define SAIPLL_P_MAX			3
#define SAIPLL_Q_MIN			2
#define SAIPLL_Q_MAX			15
#elif defined(STM32F429xx)
// HSE
#define HSI_FREQ				16000000
#define HSE_MIN_FREQ			1000000
#define HSE_MAX_FREQ			50000000

#define AHB_MAX_FREQ			180000000
#define APB1_MAX_FREQ			45000000
#define APB2_MAX_FREQ			90000000

// Main PLL
#define PLL_VCO_MIN_FREQ		100000000
#define PLL_VCO_MAX_FREQ		432000000
#define PLL_P_MAX_FREQ			180000000
#define PLL_Q_MAX_FREQ			75000000
#define PLL_R_MAX_FREQ			180000000
#define PLL_M_MIN				2
#define PLL_M_MAX				63
#define PLL_N_MIN				50
#define PLL_N_MAX				432
#define PLL_P_MAX				3
#define PLL_Q_MIN				2
#define PLL_Q_MAX				15
#define PLL_R_MIN				2
#define PLL_R_MAX				7

#define I2SPLL_VCO_MIN_FREQ		100000000
#define I2SPLL_VCO_MAX_FREQ		432000000
#define I2SPLL_P_MAX_FREQ		216000000
#define I2SPLL_Q_MAX_FREQ		216000000
#define I2SPLL_R_MAX_FREQ		216000000
#define I2SPLL_N_MIN			50
#define I2SPLL_N_MAX			432
#define I2SPLL_M_MIN			2
#define I2SPLL_M_MAX			63
#define I2SPLL_P_MAX			3
#define I2SPLL_Q_MIN			2
#define I2SPLL_Q_MAX			15
#define I2SPLL_R_MIN			2
#define I2SPLL_R_MAX			7

#define SAIPLL_VCO_MIN_FREQ		100000000
#define SAIPLL_VCO_MAX_FREQ		432000000
#define SAIPLL_P_MAX_FREQ		216000000
#define SAIPLL_Q_MAX_FREQ		216000000
#define SAIPLL_R_MAX_FREQ		216000000
#define SAIPLL_N_MIN			50
#define SAIPLL_N_MAX			432
#define SAIPLL_P_MAX			3
#define SAIPLL_Q_MIN			2
#define SAIPLL_Q_MAX			15
#define SAIPLL_R_MIN			2
#define SAIPLL_R_MAX			7

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

bool Clock::enableMainPll(uint8_t src, uint8_t m, uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
#if defined(PLL_P_USE)
	uint32_t p;
#else
	(void)pDiv;
#endif
#if defined(PLL_Q_USE)
	uint32_t q;
#else
	(void)qDiv;
#endif
#if defined(PLL_R_USE)
	uint32_t r;
#else
	(void)rDiv;
#endif
	uint32_t vco, buf;
 
	// 현재 SysClk 소스가 PLL인지 확인
	if (getFieldData(RCC->CFGR, RCC_CFGR_SWS_Msk, RCC_CFGR_SWS_Pos) == RCC_CFGR_SWS_PLL)
		goto error_t;

	if (PLL_M_MIN > m || m > PLL_M_MAX)
		goto error_t;

	if (PLL_N_MIN > n || n > PLL_N_MAX)
		goto error_t;

#if defined(PLL_P_USE)
	if (pDiv > PLL_P_MAX)
		goto error_t;
#endif

#if defined(PLL_Q_USE)
	if (PLL_Q_MIN > qDiv || qDiv > PLL_Q_MAX)
		goto error_t;
#endif

#if defined(PLL_R_USE)
	if (PLL_R_MIN > rDiv || rDiv > PLL_R_MAX)
		goto error_t;
#endif

	using namespace define::clock;
	switch (src)
	{
	case pll::src::HSI :
		vco = HSI_FREQ;
		break;

	case pll::src::HSE :
		if (~RCC->CR & RCC_CR_HSERDY_Msk)
			goto error_t;
		vco = (uint32_t)gHseFreq;
		break;

	default:
		goto error_t;
	}
	
	buf = getFieldData(RCC->CFGR, RCC_CFGR_SWS_Msk, RCC_CFGR_SWS_Pos);
#if defined(STM32F429xx) || defined(STM32F407xx)
	if (RCC->CR & RCC_CR_PLLRDY_Msk && buf  == sysclk::src::PLL)
		goto error_t;
#elif defined(STM32F446xx)
	if (RCC->CR & RCC_CR_PLLRDY_Msk && (buf  == sysclk::src::PLL || buf  == sysclk::src::PLL_R))
		goto error_t;
#endif

	vco = vco / m * n;
	if (vco < PLL_VCO_MIN_FREQ || PLL_VCO_MAX_FREQ < vco)
		goto error_t;

#if defined(PLL_P_USE)
	p = vco / (2 << pDiv);
	if (p > PLL_P_MAX_FREQ)
		goto error_t;
#else
	qDiv = getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLP_Msk, RCC_PLLCFGR_PLLP_Pos);
#endif

#if defined(PLL_Q_USE)
	q = vco / qDiv;
	if (q > PLL_Q_MAX_FREQ)
		goto error_t;
#else
	qDiv = getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLQ_Msk, RCC_PLLCFGR_PLLQ_Pos);
#endif

#if defined(PLL_R_USE)
	r = vco / rDiv;
	if (r > PLL_R_MAX_FREQ)
		goto error_t;
#else
	rDiv = 0;
#endif
	RCC->PLLCFGR = (qDiv << RCC_PLLCFGR_PLLQ_Pos) | (src << RCC_PLLCFGR_PLLSRC_Pos) | (pDiv << RCC_PLLCFGR_PLLP_Pos) | (n << RCC_PLLCFGR_PLLN_Pos) | m;
	RCC->CR |= RCC_CR_PLLON_Msk;

	for (uint32_t i = 0; i < 1000000; i++)
	{
		// PLL 활성화 확인
		if (RCC->CR & RCC_CR_PLLRDY_Msk)
			return true;
	}

error_t:
	return false;
}

#if defined(PLL_P_USE)
uint32_t Clock::getMainPllPFrequency(void)
{
	uint8_t src = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC_Msk) >> RCC_PLLCFGR_PLLSRC_Pos;
	uint32_t clk = gHseFreq;

	using namespace define::clock;
	switch (src)
	{
	case pll::src::HSI :
		clk = HSI_FREQ;
		break;

	case pll::src::HSE :
		clk = (uint32_t)gHseFreq;
		break;

	default:
		return 0;
	}
	
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN_Msk) >> RCC_PLLCFGR_PLLN_Pos);
	clk /= 2  * (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP_Msk) >> RCC_PLLCFGR_PLLP_Pos ) + 1);
	return clk;
}
#endif

#if defined(PLL_Q_USE)
uint32_t Clock::getMainPllQFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN_Msk) >> RCC_PLLCFGR_PLLN_Pos);
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLQ_Msk) >> RCC_PLLCFGR_PLLQ_Pos);
	return clk;
}
#endif

#if defined(PLL_R_USE)
uint32_t Clock::getMainPllRFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN_Msk) >> RCC_PLLCFGR_PLLN_Pos);
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLR_Msk) >> RCC_PLLCFGR_PLLR_Pos);
	return clk;
}
#endif

uint32_t Clock::getSystemClockFrequency(void)
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
		return getMainPllPFrequency();
		break;

	default :
		return 0;
	}
}

uint32_t Clock::getCoreClockFrequency(void)
{
	return getSystemClockFrequency() / gHpreDiv[((RCC->CFGR & RCC_CFGR_HPRE_Msk) >> RCC_CFGR_HPRE_Pos)];
}

uint32_t Clock::getAhbClockFrequency(void)
{
	return getCoreClockFrequency();
}

uint32_t Clock::getApb1ClockFrequency(void)
{
	return getSystemClockFrequency() / gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos)];
}

uint32_t Clock::getApb2ClockFrequency(void)
{
	return getSystemClockFrequency() / gPpreDiv[((RCC->CFGR & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos)];
}

uint8_t Clock::getPowerScale(void)
{
#if defined(STM32F407xx)
	return getBitData(PWR->CR, PWR_CR_VOS_Pos);
#else
	return getFieldData(PWR->CR, PWR_CR_VOS_Msk, PWR_CR_VOS_Pos);
#endif
}

error_t Clock::setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2, uint8_t vcc)
{
	(void)vcc;

	int32_t  clk, ahbClk, apb1Clk, apb2Clk, ahbMax, apb1Max, apb2Max;
#if defined(OVER_DRVIE_USE)
	int32_t ahbOvr;
	bool ovrFlag = false;
#endif

	using namespace define::clock::sysclk::src;
	switch (sysclkSrc)
	{
	case HSI:
		clk = HSI_FREQ;
		break;
	case HSE:
		// HSE 활성화 점검
		if (~RCC->CR & RCC_CR_HSERDY_Msk)
			return error_t::HSE_NOT_READY;
		clk = gHseFreq;
		break;
	case PLL:
		// PLL 활성화 점검
		if (~RCC->CR & RCC_CR_PLLRDY_Msk)
			return error_t::PLL_NOT_READY;
		clk = getMainPllPFrequency();
		break;
	default:
		return error_t::CLK_SRC_NOT_ABLE;
	}

	switch(getPowerScale())
	{
	default :
	case define::clock::powerScale::SCALE1_MODE :
#if defined(OVER_DRVIE_USE)
		ahbOvr = AHB_MAX_FREQ_SCALE1_OVR;
#endif
		ahbMax = AHB_MAX_FREQ_SCALE1;
		break;

	case define::clock::powerScale::SCALE2_MODE :
#if defined(OVER_DRVIE_USE)
		ahbOvr = AHB_MAX_FREQ_SCALE2_OVR;
#endif
		ahbMax = AHB_MAX_FREQ_SCALE2;
		break;
#if defined(STM32F446xx) || defined(STM32F429xx)
	case define::clock::powerScale::SCALE3_MODE :
#if defined(OVER_DRVIE_USE)
		ahbOvr = AHB_MAX_FREQ_SCALE3_OVR;
#endif
		ahbMax = AHB_MAX_FREQ_SCALE3;
		break;
#endif
	}


	ahbClk = clk / gHpreDiv[ahb];
#if defined(OVER_DRVIE_USE)
	if(ahbClk > ahbOvr)
	{
		ovrFlag = true;
		apb1Max = ahbMax / 4;
		apb2Max = ahbMax / 2;
	}
	else
	{
		ovrFlag = false;
		ahbMax = ahbOvr;
		apb1Max = ahbOvr / 4;
		apb2Max = ahbOvr / 2;
	}
#else
	apb1Max = ahbMax / 4;
	apb2Max = ahbMax / 2;
#endif

	if (ahbClk > ahbMax)
		return error_t::WRONG_CLOCK_FREQUENCY;

	apb1Clk = ahbClk / gPpreDiv[apb1];
	if (apb1Clk > apb1Max)
		return error_t::WRONG_CLOCK_FREQUENCY;

	apb2Clk = ahbClk / gPpreDiv[apb2];
	if (apb2Clk > apb2Max)
		return error_t::WRONG_CLOCK_FREQUENCY;

#if defined(OVER_DRVIE_USE)
	if(ovrFlag)
	{
		setBitData(PWR->CR, true, PWR_CR_ODEN_Pos);
		while(!getBitData(PWR->CSR, PWR_CSR_ODRDY_Pos))
			;		
		setBitData(PWR->CR, true, PWR_CR_ODSWEN_Pos);
		while(!getBitData(PWR->CSR, PWR_CSR_ODSWRDY_Pos))
			;		
	}
#endif
	// 버스 클럭 프리스케일러 설정
	setThreeFieldData(RCC->CFGR, RCC_CFGR_PPRE2_Msk, apb2, RCC_CFGR_PPRE2_Pos, RCC_CFGR_PPRE1_Msk, apb1, RCC_CFGR_PPRE1_Pos, RCC_CFGR_HPRE_Msk, ahb, RCC_CFGR_HPRE_Pos);
	
	// 클럭 소스 변경
	setFieldData(RCC->CFGR, RCC_CFGR_SW_Msk, sysclkSrc, RCC_CFGR_SW_Pos);

	for (uint32_t i = 0; i < 1000000; i++)
	{
		// PLL 활성화 확인
		if (getFieldData(RCC->CFGR, RCC_CFGR_SW_Msk, RCC_CFGR_SW_Pos) == getFieldData(RCC->CFGR, RCC_CFGR_SWS_Msk, RCC_CFGR_SWS_Pos))
			return error_t::ERROR_NONE;
	}
	
	return error_t::SYSCLK_WAS_NOT_CHANGED;
}

void Clock::enableAhb1Clock(uint32_t position, bool en)
{
	setBitData(RCC->AHB1ENR, en, position);
}

void Clock::enableAhb2Clock(uint32_t position, bool en)
{
	setBitData(RCC->AHB2ENR, en, position);
}

void Clock::enableAhb3Clock(uint32_t position, bool en)
{
	setBitData(RCC->AHB3ENR, en, position);
}

void Clock::enableApb1Clock(uint32_t position, bool en)
{
	setBitData(RCC->APB1ENR, en, position);
}

void Clock::enableApb2Clock(uint32_t position, bool en)
{
	setBitData(RCC->APB2ENR, en, position);
}

void Clock::resetAhb1(uint32_t position)
{
	setBitData(RCC->AHB1RSTR, true, position);
	setBitData(RCC->AHB1RSTR, false, position);
}

void Clock::resetAhb2(uint32_t position)
{
	setBitData(RCC->AHB2RSTR, true, position);
	setBitData(RCC->AHB2RSTR, false, position);
}

void Clock::resetAhb3(uint32_t position)
{
	setBitData(RCC->AHB3RSTR, true, position);
	setBitData(RCC->AHB3RSTR, false, position);
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

#if defined(FMC_Bank5_6)
void Clock::enableSdram(bool en)
{
	enableAhb3Clock(RCC_AHB3ENR_FMCEN_Pos, en);
}
#endif

#if defined(GD32F4) || defined(STM32F429xx)
void Clock::setLtdcDivisionFactor(uint8_t div)
{
	setFieldData(RCC[RCC_REG::DCKCFGR], RCC_DCKCFGR_PLLSAIDIVR_Msk, div, RCC_DCKCFGR_PLLSAIDIVR_Pos);
}

uint32_t Clock::getLtdcClockFrequency(void)
{
#if defined(STM32F429xx)
	uint32_t div = getFieldData(RCC->DCKCFGR, RCC_DCKCFGR_PLLSAIDIVR_Msk, RCC_DCKCFGR_PLLSAIDIVR_Pos);
#endif
	return getSaiPllRFrequency() / (2 << div);
}
#endif

#if defined(SAIPLL_USE)
bool Clock::enableSaiPll(uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	uint32_t vco, buf;

	if (~RCC->CR & RCC_CR_PLLRDY_Msk)
		goto error_t;

	if (SAIPLL_N_MIN > n || n > SAIPLL_N_MAX)
		goto error_t;

#if defined(SAIPLL_P_USE)
	uint32_t p;
	if (pDiv > SAIPLL_P_MAX)
		goto error_t;
#endif

#if defined(SAIPLL_Q_USE)
	uint32_t q;
	if (SAIPLL_Q_MIN > qDiv || qDiv > SAIPLL_Q_MAX)
		goto error_t;
#endif

#if defined(SAIPLL_R_USE)
	uint32_t r;
	if (SAIPLL_R_MIN > rDiv || rDiv > SAIPLL_R_MAX)
		goto error_t;
#endif

	switch (getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Msk, RCC_PLLCFGR_PLLSRC_Pos))
	{
	case define::clock::pll::src::HSI:
		buf = HSI_FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (~RCC->CR & RCC_CR_HSERDY_Msk)
			goto error_t;
		buf = (uint32_t)gHseFreq;
		break;
	default:
		goto error_t;
	}
	vco = buf / getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLM_Msk, RCC_PLLCFGR_PLLM_Pos) * n;

	if (vco < SAIPLL_VCO_MIN_FREQ || SAIPLL_VCO_MAX_FREQ < vco)
		goto error_t;

#if defined(SAIPLL_P_USE)
	p = vco / (2 << pDiv);
	if (SAIPLL_P_MAX_FREQ < p)
		goto error_t;
#else
	pDiv = 0;
#define RCC_PLLSAICFGR_PLLSAIP_Pos	16
#endif

#if defined(SAIPLL_Q_USE)
	q = vco / qDiv;
	if (SAIPLL_Q_MAX_FREQ < q)
		goto error_t;
#else
	qDiv = 0;
#define RCC_PLLSAICFGR_PLLSAIQ_Pos	24
#endif

#if defined(SAIPLL_R_USE)
	r = vco / rDiv;
	if (SAIPLL_R_MAX_FREQ < r)
		goto error_t;
#else
	rDiv = 0;
#define RCC_PLLSAICFGR_PLLSAIR_Pos	28
#endif
	
	RCC->PLLSAICFGR = rDiv << RCC_PLLSAICFGR_PLLSAIR_Pos | qDiv << RCC_PLLSAICFGR_PLLSAIQ_Pos | pDiv << RCC_PLLSAICFGR_PLLSAIP_Pos | n << RCC_PLLSAICFGR_PLLSAIN_Pos;
	setBitData(RCC->CR, true, RCC_CR_PLLSAION_Pos);

	for (uint16_t i = 0; i < 10000; i++)
	{
		if (RCC->CR & RCC_CR_PLLSAIRDY_Msk)
		{
			return true;
		}
	}

error_t:
	return false;
}

#if defined(GET_SAI1A_FREQ_USE)
	void setSai1AClockSource(uint8_t src)
	{
#if defined(STM32F429xx)
		setFieldData(RCC->DCKCFGR, RCC_DCKCFGR_SAI1ASRC_Msk, src, RCC_DCKCFGR_SAI1ASRC_Pos);
#endif
	}

	uint32_t getSai1AClockFrequency(void);
#endif

#if defined(GET_SAI1B_FREQ_USE)
	void setSai1BClockSource(uint8_t src)
	{
#if defined(STM32F429xx)
		setFieldData(RCC->DCKCFGR, RCC_DCKCFGR_SAI1BSRC_Msk, src, RCC_DCKCFGR_SAI1BSRC_Pos);
#endif
	}
	uint32_t getSai1BClockFrequency(void);
#endif

#if defined(GET_SAI1_FREQ_USE)
	void Clock::setSai1ClockSource(uint8_t src)
	{
#if defined(STM32F446xx)
		setFieldData(RCC->DCKCFGR, RCC_DCKCFGR_SAI1SRC_Msk, src, RCC_DCKCFGR_SAI1SRC_Pos);
#elif defined(STM32F429xx)
		setFieldData(RCC->DCKCFGR, RCC_DCKCFGR_SAI1ASRC_Msk, src, RCC_DCKCFGR_SAI1ASRC_Pos);
#endif
	}

	uint32_t Clock::getSai1ClockFrequency(void)
	{
#if defined(STM32F446xx)
		switch(getFieldData(RCC->DCKCFGR, RCC_DCKCFGR_SAI1SRC_Msk, RCC_DCKCFGR_SAI1SRC_Pos))
#elif defined(STM32F429xx)
		switch(getFieldData(RCC->DCKCFGR, RCC_DCKCFGR_SAI1ASRC_Msk, RCC_DCKCFGR_SAI1ASRC_Pos))
#endif
		{
		case 0 : // PLLI2S_R
			return getI2sPllRFrequency();

		case 1 : // I2S_CKIN
			return gI2sCkinFreq;
	
		case 2 : // PLL_R
			return getMainPllRFrequency();
	
		case 3 : // PLL_SRC
			switch (getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Msk, RCC_PLLCFGR_PLLSRC_Pos))
			{
			case define::clock::pll::src::HSI:
				return HSI_FREQ;
			case define::clock::pll::src::HSE:
				return gHseFreq;
			}
		}

		return 0;
	}
#endif

#if defined(GET_SAI2_FREQ_USE)
	void Clock::setSai2ClockSource(uint8_t src)
	{
		setFieldData(RCC->DCKCFGR, RCC_DCKCFGR_SAI2SRC_Msk, src, RCC_DCKCFGR_SAI2SRC_Pos);
	}

	uint32_t Clock::getSai2ClockFrequency(void)
	{
		switch(getFieldData(RCC->DCKCFGR, RCC_DCKCFGR_SAI2SRC_Msk, RCC_DCKCFGR_SAI2SRC_Pos))
		{
		case 0 : // PLLI2S_R
			return getI2sPllRFrequency();

		case 1 : // I2S_CKIN
			return gI2sCkinFreq;
	
		case 2 : // PLL_R
			return getMainPllRFrequency();
	
		case 3 : // PLL_SRC
			switch (getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Msk, RCC_PLLCFGR_PLLSRC_Pos))
			{
			case define::clock::pll::src::HSI:
				return HSI_FREQ;
			case define::clock::pll::src::HSE:
				return gHseFreq;
			}
		}

		return 0;
	}
#endif

#if defined(SAIPLL_P_USE)
uint32_t Clock::getSaiPllPFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC->PLLSAICFGR & RCC_PLLSAICFGR_PLLSAIN_Msk) >> RCC_PLLSAICFGR_PLLSAIN_Pos);
	clk /= 2  * (((RCC->PLLSAICFGR & RCC_PLLSAICFGR_PLLSAIP_Msk) >> RCC_PLLSAICFGR_PLLSAIP_Pos ) + 1);
	return clk;
}
#endif

#if defined(SAIPLL_Q_USE)
uint32_t Clock::getSaiPllQFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC->PLLSAICFGR & RCC_PLLSAICFGR_PLLSAIN_Msk) >> RCC_PLLSAICFGR_PLLSAIN_Pos);
	clk /= ((RCC->PLLSAICFGR & RCC_PLLSAICFGR_PLLSAIQ_Msk) >> RCC_PLLSAICFGR_PLLSAIQ_Pos);
	return clk;
}
#endif

#if defined(SAIPLL_R_USE)
uint32_t Clock::getSaiPllRFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC->PLLSAICFGR & RCC_PLLSAICFGR_PLLSAIN_Msk) >> RCC_PLLSAICFGR_PLLSAIN_Pos);
	clk /= ((RCC->PLLSAICFGR & RCC_PLLSAICFGR_PLLSAIR_Msk) >> RCC_PLLSAICFGR_PLLSAIR_Pos);
	return clk;
}
#endif
#endif

#if defined(I2SPLL_USE)
bool Clock::enableI2sPll(uint16_t n, uint8_t m, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	uint32_t vco, p, q, r, buf;

	if (~RCC->CR & RCC_CR_PLLRDY_Msk)
		goto error_handler;

	if (I2SPLL_N_MIN > n || n > I2SPLL_N_MAX)
		goto error_handler;

#if !defined(STM32F407xx)
	if (I2SPLL_M_MIN > m || m > I2SPLL_M_MAX)
		goto error_handler;
#endif
	
#if defined(I2SPLL_P_USE)
	if (pDiv > I2SPLL_P_MAX)
		goto error_handler_t;
#endif

#if defined(I2SPLL_Q_USE)
	if (I2SPLL_Q_MIN > qDiv || qDiv > I2SPLL_Q_MAX)
		goto error_handler_t;
#endif

#if defined(I2SPLL_R_USE)
	if (I2SPLL_R_MIN > rDiv || rDiv > I2SPLL_R_MAX)
		goto error_handler;
#endif

	switch (getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Msk, RCC_PLLCFGR_PLLSRC_Pos))
	{
	case define::clock::pll::src::HSI:
		buf = HSI_FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (~RCC->CR & RCC_CR_HSERDY_Msk)
			goto error_handler;
		buf = (uint32_t)gHseFreq;
		break;
	default:
		goto error_handler;
	}
	vco = buf * n / m;

	if (vco < I2SPLL_VCO_MIN_FREQ || I2SPLL_VCO_MAX_FREQ < vco)
		goto error_handler;

#if defined(I2SPLL_P_USE)
	p = vco / (2 << pDiv);
	if (I2SPLL_P_MAX_FREQ < p)
		goto error_handler;
#else
#if defined(STM32F407xx)
	pDiv = 0;
#else
	pDiv = getFieldData(RCC->PLLI2SCFGR, RCC_PLLI2SCFGR_PLLI2SP_Msk, RCC_PLLI2SCFGR_PLLI2SP_Pos);
#endif
#endif

#if defined(I2SPLL_Q_USE)
	q = vco / qDiv;
	if (I2SPLL_Q_MAX_FREQ < q)
		goto error_handler;
#else
#if defined(STM32F407xx)
	qDiv = 0;
#else
	qDiv = getFieldData(RCC->PLLI2SCFGR, RCC_PLLI2SCFGR_PLLI2SQ_Msk, RCC_PLLI2SCFGR_PLLI2SQ_Pos);
#endif
#endif

#if defined(I2SPLL_R_USE)
	r = vco / rDiv;
	if (I2SPLL_R_MAX_FREQ < r)
		goto error_handler;
#else
	rDiv = getFieldData(RCC->PLLI2SCFGR, RCC_PLLI2SCFGR_PLLI2SR_Msk, RCC_PLLI2SCFGR_PLLI2SR_Pos);
#endif
	
#if defined(STM32F407xx)
	RCC->PLLI2SCFGR = rDiv << RCC_PLLI2SCFGR_PLLI2SR_Pos | n << RCC_PLLI2SCFGR_PLLI2SN_Pos;
#else
	RCC->PLLI2SCFGR = rDiv << RCC_PLLI2SCFGR_PLLI2SR_Pos | qDiv << RCC_PLLI2SCFGR_PLLI2SQ_Pos | pDiv << RCC_PLLI2SCFGR_PLLI2SP_Pos | n << RCC_PLLI2SCFGR_PLLI2SN_Pos | m << RCC_PLLI2SCFGR_PLLI2SM_Pos;
#endif
	setBitData(RCC->CR, true, RCC_CR_PLLI2SON_Pos);

	for (uint16_t i = 0; i < 10000; i++)
	{
		if (RCC->CR & RCC_CR_PLLI2SRDY_Msk)
		{
			return true;
		}
	}

error_handler :
	return false;
}

#if defined(I2SPLL_P_USE)

void Clock::setI2s1ClockSource(uint8_t src)
{
	setFieldData(RCC->DCKCFGR, RCC_DCKCFGR_I2S1SRC_Msk, src, RCC_DCKCFGR_I2S1SRC_Pos);
}

uint32_t Clock::getI2sPllPFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC->PLLI2SCFGR & RCC_PLLI2SCFGR_PLLI2SN_Msk) >> RCC_PLLI2SCFGR_PLLI2SN_Pos);
	clk /= 2  * (((RCC->PLLI2SCFGR & RCC_PLLI2SCFGR_PLLI2SP_Msk) >> RCC_PLLI2SCFGR_PLLI2SP_Pos ) + 1);
	return clk;
}
#endif

#if defined(GET_I2S_FREQ_USE)
void Clock::setI2sCkinClockFrequency(uint32_t freq)
{
	gI2sCkinFreq = freq;
}

void Clock::setI2sClockSource(i2sSrc_t src)
{
	setFieldData(RCC->CFGR, RCC_CFGR_I2SSRC_Msk, src, RCC_CFGR_I2SSRC_Pos);
}

uint32_t Clock::getI2sClockFrequency(void)
{
#if defined(STM32F407xx)
	switch(getFieldData(RCC->CFGR, RCC_CFGR_I2SSRC_Msk, RCC_CFGR_I2SSRC_Pos))
	{
	case 0 : // PLLI2S_R
		return getI2sPllRFrequency();

	case 1 : // I2S_CKIN
		return gI2sCkinFreq;
	}
#endif

	return 0;
}
#endif

#if defined(GET_I2S1_FREQ_USE)
uint32_t Clock::getI2s1ClockFrequency(void)
{
	switch(getFieldData(RCC->DCKCFGR, RCC_DCKCFGR_I2S1SRC_Msk, RCC_DCKCFGR_I2S1SRC_Pos))
	{
	case 0 : // PLLI2S_R
		return getI2sPllRFrequency();

	case 1 : // I2S_CKIN
		return gI2sCkinFreq;
	
	case 2 : // PLL_R
		return getMainPllRFrequency();
	
	case 3 : // PLL_SRC
		switch (getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Msk, RCC_PLLCFGR_PLLSRC_Pos))
		{
		case define::clock::pll::src::HSI:
			return HSI_FREQ;
		case define::clock::pll::src::HSE:
			return gHseFreq;
		}
	}

	return 0;
}
#endif

#if defined(GET_I2S2_FREQ_USE)
void Clock::setI2s2ClockSource(uint8_t src)
{
	setFieldData(RCC->DCKCFGR, RCC_DCKCFGR_I2S2SRC_Msk, src, RCC_DCKCFGR_I2S2SRC_Pos);
}

uint32_t Clock::getI2s2ClockFrequency(void)
{
	switch(getFieldData(RCC->DCKCFGR, RCC_DCKCFGR_I2S2SRC_Msk, RCC_DCKCFGR_I2S2SRC_Pos))
	{
	case 0 : // PLLI2S_R
		return getI2sPllRFrequency();

	case 1 : // I2S_CKIN
		return gI2sCkinFreq;
	
	case 2 : // PLL_R
		return getMainPllRFrequency();
	
	case 3 : // PLL_SRC
		switch (getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Msk, RCC_PLLCFGR_PLLSRC_Pos))
		{
		case define::clock::pll::src::HSI:
			return HSI_FREQ;
		case define::clock::pll::src::HSE:
			return gHseFreq;
		}
	}

	return 0;
}
#endif

#if defined(GET_I2S2_FREQ_USE)
	uint32_t getI2s2ClockFrequency(void)
	{
		// 임시로 0 리턴
		return 0;
	}
#endif

#if defined(I2SPLL_Q_USE)
uint32_t Clock::getI2sPllQFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC->PLLI2SCFGR & RCC_PLLI2SCFGR_PLLI2SN_Msk) >> RCC_PLLI2SCFGR_PLLI2SN_Pos);
	clk /= ((RCC->PLLI2SCFGR & RCC_PLLI2SCFGR_PLLI2SQ_Msk) >> RCC_PLLI2SCFGR_PLLI2SQ_Pos);
	return clk;
}
#endif

#if defined(I2SPLL_R_USE)
uint32_t Clock::getI2sPllRFrequency(void)
{
	uint8_t src = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC_Msk) >> RCC_PLLCFGR_PLLSRC_Pos;
	uint32_t clk;

	using namespace define::clock;
	switch (src)
	{
	case pll::src::HSI :
		clk = HSI_FREQ;
		break;

	case pll::src::HSE :
		clk = (uint32_t)gHseFreq;
		break;

	default:
		return 0;
	}
	
	clk /= ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC->PLLI2SCFGR & RCC_PLLI2SCFGR_PLLI2SN_Msk) >> RCC_PLLI2SCFGR_PLLI2SN_Pos);
	clk /= ((RCC->PLLI2SCFGR & RCC_PLLI2SCFGR_PLLI2SR_Msk) >> RCC_PLLI2SCFGR_PLLI2SR_Pos);

	return clk;
}
#endif
#endif

#endif


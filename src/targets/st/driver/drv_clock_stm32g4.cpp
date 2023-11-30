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
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(STM32G4)

#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

static uint32_t gHseFreq __attribute__((section(".non_init")));
static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const uint32_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

#if defined(STM32G474xx)
// HSE
#define HSI_FREQ				16000000
#define HSE_MAX_FREQ_SCALE1		48000000
#define HSE_MAX_FREQ_SCALE2		26000000

// AHB
#define AHB_MAX_FREQ_SCALE1			170000000
#define AHB_MAX_FREQ_SCALE1_BOOST	150000000
#define AHB_MAX_FREQ_SCALE2			26000000
#define AHB_MAX_FREQ_SCALE2_BOOST	26000000

// Main PLL
#define PLL_VCO_MIN_FREQ			96000000
#define PLL_VCO_MAX_FREQ_SCALE1		344000000
#define PLL_VCO_MAX_FREQ_SCALE2		26000000
#define PLL_P_MAX_FREQ_SCALE1		170000000
#define PLL_P_MAX_FREQ_SCALE2		26000000
#define PLL_P_MIN_FREQ				8000000
#define PLL_Q_MAX_FREQ_SCALE1		170000000
#define PLL_Q_MAX_FREQ_SCALE2		26000000
#define PLL_Q_MIN_FREQ				8000000
#define PLL_R_MAX_FREQ_SCALE1		170000000
#define PLL_R_MAX_FREQ_SCALE2		26000000
#define PLL_R_MIN_FREQ				8000000
#define PLL_M_MIN					1
#define PLL_M_MAX					16
#define PLL_N_MIN					8
#define PLL_N_MAX					127
#define PLL_P_MIN					2
#define PLL_P_MAX					31
#define PLL_Q_MAX					3
#define PLL_R_MAX					3
#endif

error Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	uint32_t maxFreq;
#if defined(STM32G474xx)
	switch(getPowerScale())
	{
	case define::clock::powerScale::SCALE1_MODE :
		maxFreq = HSE_MAX_FREQ_SCALE1;
		break;
	case define::clock::powerScale::SCALE2_MODE :		
		maxFreq = HSE_MAX_FREQ_SCALE2;
		break;
	}
#else
#error "반드시 Power Scale에 따른 클럭 범위가 정상인지 확인하도록 코드를 추가하시오."
#endif
	if (maxFreq < hseHz)
		return error::WRONG_CLOCK_FREQUENCY;

	gHseFreq = hseHz;

	if (useOsc)
		RCC->CR |= RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk;
	else
		RCC->CR |= RCC_CR_HSEON_Msk;

	for (uint32_t i = 0; i < 1000000; i++)
	{
		if (RCC->CR & RCC_CR_HSERDY_Msk)
			return error::ERROR_NONE;
	}

	return error::TIMEOUT;
}

uint8_t Clock::getPowerScale(void)
{
	return getFieldData(PWR->CR1, PWR_CR1_VOS_Msk, PWR_CR1_VOS_Pos);
}

error Clock::setPowerScale(uint8_t scale)
{
#if defined(STM32G474xx)
	if(scale < 1 || 2 < scale)
		return error::WRONG_CONFIG;		 
#else
#error "반드시 Power Scale의 설정 범위가 정상인지 확인하도록 코드를 추가하시오."
#endif
		
	setFieldData(PWR->CR1, PWR_CR1_VOS_Msk, scale, PWR_CR1_VOS_Pos);	
	
	return error::ERROR_NONE;
}

void Clock::enableAhb1Clock(uint32_t position, bool en)
{
	setBitData(RCC->AHB1ENR, en, position);
}

void Clock::resetAhb1(uint32_t position)
{
	setBitData(RCC->AHB1RSTR, true, position);
	setBitData(RCC->AHB1RSTR, false, position);	
}

void Clock::enableAhb2Clock(uint32_t position, bool en)
{
	setBitData(RCC->AHB2ENR, en, position);
}

void Clock::resetAhb2(uint32_t position)
{
	setBitData(RCC->AHB2RSTR, true, position);
	setBitData(RCC->AHB2RSTR, false, position);	
}

void Clock::enableAhb3Clock(uint32_t position, bool en)
{
	setBitData(RCC->AHB3ENR, en, position);
}

void Clock::resetAhb3(uint32_t position)
{
	setBitData(RCC->AHB3RSTR, true, position);
	setBitData(RCC->AHB3RSTR, false, position);	
}

uint32_t Clock::getAhbClockFrequency(void)
{
	return getSystemClockFrequency() / gHpreDiv[getFieldData(RCC->CFGR, RCC_CFGR_HPRE_Msk, RCC_CFGR_HPRE_Pos)];
}

void Clock::enableApb1_1Clock(uint32_t position, bool en)
{
	setBitData(RCC->APB1ENR1, en, position);
}

void Clock::resetApb1_1(uint32_t position)
{
	setBitData(RCC->APB1RSTR1, true, position);
	setBitData(RCC->APB1RSTR1, false, position);	
}

void Clock::enableApb1_2Clock(uint32_t position, bool en)
{
	setBitData(RCC->APB1ENR2, en, position);
}

void Clock::resetApb1_2(uint32_t position)
{
	setBitData(RCC->APB1RSTR2, true, position);
	setBitData(RCC->APB1RSTR2, false, position);	
}

uint32_t Clock::getApb1ClockFrequency(void)
{
	return getAhbClockFrequency() / gPpreDiv[getFieldData(RCC->CFGR, RCC_CFGR_PPRE1_Msk, RCC_CFGR_PPRE1_Pos)];
}

void Clock::enableApb2Clock(uint32_t position, bool en)
{
	setBitData(RCC->APB2ENR, en, position);
}

void Clock::resetApb2(uint32_t position)
{
	setBitData(RCC->APB2RSTR, true, position);
	setBitData(RCC->APB2RSTR, false, position);	
}

uint32_t Clock::getApb2ClockFrequency(void)
{
	return getAhbClockFrequency() / gPpreDiv[getFieldData(RCC->CFGR, RCC_CFGR_PPRE2_Msk, RCC_CFGR_PPRE2_Pos)];
}

#if defined(PLL_USE)
error Clock::enableMainPll(uint8_t src, uint8_t m, uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	using namespace define::clock;

	uint32_t vco, buf, vcoMin, vcoMax;

#if defined(PLL_P_USE)
	uint32_t p, pMin, pMax;
#else
	(void)pDiv;
#endif

#if defined(PLL_Q_USE)
	uint32_t q, qMin, qMax;
#else
	(void)qDiv;
#endif

#if defined(PLL_R_USE)
	uint32_t r, rMin, rMax;
#else
	(void)rDiv;
#endif

	// 현재 SysClk 소스가 PLL인이 확인
	buf = getFieldData(RCC->CFGR, RCC_CFGR_SWS_Msk, RCC_CFGR_SWS_Pos);
	if (RCC->CR & RCC_CR_PLLRDY_Msk && buf == sysclk::src::PLL)
		return error::SYSCLK_SRC_IS_PLL;
	
	// 설정값의 정상 범위여부 확인
	if (PLL_M_MIN > m || m > PLL_M_MAX)
		return error::WRONG_CONFIG;

	if (PLL_N_MIN > n || n > PLL_N_MAX)
		return error::WRONG_CONFIG;

#if defined(PLL_P_USE)
	if (PLL_P_MIN > pDiv || pDiv > PLL_P_MAX)
		return error::WRONG_CONFIG;
#endif

#if defined(PLL_Q_USE)
	if (qDiv > PLL_Q_MAX)
		return error::WRONG_CONFIG;
#endif

#if defined(PLL_R_USE)
	if (rDiv > PLL_R_MAX)
		return error::WRONG_CONFIG;
#endif
	
	// 클럭 소스의 주파수 얻어오기
	switch (src)
	{
	case pll::src::HSI16 :
		vco = HSI_FREQ;
		break;

	case pll::src::HSE :
		if (~RCC->CR & RCC_CR_HSERDY_Msk)
			return error::HSE_NOT_READY;
		vco = (uint32_t)gHseFreq;
		break;

	default:
		return error::WRONG_CONFIG;
	}
	
	// 스케일에 따른 동작 클럭 설정
	switch(getPowerScale())
	{
	case powerScale::SCALE1_MODE :
		pMin = PLL_P_MIN_FREQ;
		pMax = PLL_P_MAX_FREQ_SCALE1;
		qMin = PLL_Q_MIN_FREQ;
		qMax = PLL_Q_MAX_FREQ_SCALE1;
		rMin = PLL_R_MIN_FREQ;
		rMax = PLL_R_MAX_FREQ_SCALE1;
		vcoMin = PLL_VCO_MIN_FREQ;
		vcoMax = PLL_VCO_MAX_FREQ_SCALE1;
		break;

	case powerScale::SCALE2_MODE :
		pMin = PLL_P_MIN_FREQ;
		pMax = PLL_P_MAX_FREQ_SCALE2;
		qMin = PLL_Q_MIN_FREQ;
		qMax = PLL_Q_MAX_FREQ_SCALE2;
		rMin = PLL_R_MIN_FREQ;
		rMax = PLL_R_MAX_FREQ_SCALE2;
		vcoMin = PLL_VCO_MIN_FREQ;
		vcoMax = PLL_VCO_MAX_FREQ_SCALE2;
		break;
	}

	vco = vco / m * n;
	if (vco < vcoMin || vcoMax < vco)
		return error::WRONG_CONFIG;

#if defined(PLL_P_USE)
	p = vco / pDiv;
	if (p > pMax || p < pMin)
		return error::WRONG_CONFIG;
#else
	qDiv = getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLP_Msk, RCC_PLLCFGR_PLLP_Pos);
#endif

#if defined(PLL_Q_USE)
	q = vco / (2 * (qDiv + 1));
	if (q > qMax || q < qMin)
		return error::WRONG_CONFIG;
#else
	qDiv = getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLQ_Msk, RCC_PLLCFGR_PLLQ_Pos);
#endif

#if defined(PLL_R_USE)
	r = vco / (2 * (rDiv + 1));
	if (r > rMax || r < rMin)
		return error::WRONG_CONFIG;
#else
	rDiv = getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLR_Msk, RCC_PLLCFGR_PLLR_Pos);
#endif
	
	RCC->PLLCFGR = (src << RCC_PLLCFGR_PLLSRC_Pos) | (pDiv << RCC_PLLCFGR_PLLPDIV_Pos) | (qDiv << RCC_PLLCFGR_PLLQ_Pos) | (rDiv << RCC_PLLCFGR_PLLR_Pos) | (n << RCC_PLLCFGR_PLLN_Pos) | (m << RCC_PLLCFGR_PLLM_Pos) | RCC_PLLCFGR_PLLPEN_Msk | RCC_PLLCFGR_PLLQEN_Msk | RCC_PLLCFGR_PLLREN_Msk;
	RCC->CR |= RCC_CR_PLLON_Msk;

	for (uint32_t i = 0; i < 100000; i++)
	{
		// PLL 활성화 확인
		if (RCC->CR & RCC_CR_PLLRDY_Msk)
			return error::ERROR_NONE;
	}

	return error::TIMEOUT;
}

inline uint32_t getPllVcoFreq(void)
{
	uint32_t clk;

	switch(getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Msk, RCC_PLLCFGR_PLLSRC_Pos))
	{
	case define::clock::pll::src::HSI16 :
		clk = HSI_FREQ;
		break;
	case define::clock::pll::src::HSE :
		clk = gHseFreq;
		break;
	default :
		return 0;
	}

	clk /= getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLM_Msk, RCC_PLLCFGR_PLLM_Pos);
	clk *= getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLN_Msk, RCC_PLLCFGR_PLLN_Pos);

	return clk;
}

#if defined(PLL_P_USE)
uint32_t Clock::getMainPllPFrequency(void)
{
	return getPllVcoFreq() / getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLPDIV_Msk, RCC_PLLCFGR_PLLPDIV_Pos);
}
#endif

#if defined(PLL_Q_USE)
uint32_t Clock::getMainPllQFrequency(void)
{
	return getPllVcoFreq() / (2 * (getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLQ_Msk, RCC_PLLCFGR_PLLQ_Pos) + 1));
}
#endif

#if defined(PLL_R_USE)
uint32_t Clock::getMainPllRFrequency(void)
{
	return getPllVcoFreq() / (2 * (getFieldData(RCC->PLLCFGR, RCC_PLLCFGR_PLLR_Msk, RCC_PLLCFGR_PLLR_Pos) + 1));
}
#endif
#endif

error Clock::setSysclk(uint8_t sysclkSrc, uint8_t ahbDiv, uint8_t apb1Div, uint8_t apb2Div)
{
	using namespace define::clock::sysclk::src;
	using namespace define::clock;

	int32_t clk, ahbClk, apb1Clk, apb2Clk, ahbMax, ahbBoost, apb1Max, apb2Max, div, powerScale;
	bool boostFlag = false;
	
	// 클럭 소스의 주파수 얻기
	switch (sysclkSrc)
	{
	case HSI16 :
		clk = HSI_FREQ;
		break;
	case HSE :
		// HSE 활성화 점검
		if (~RCC->CR & RCC_CR_HSERDY_Msk)
			return error::HSE_NOT_READY;
		clk = gHseFreq;
		break;
	case PLL :
		// PLL 활성화 점검
		if (~RCC->CR & RCC_CR_PLLRDY_Msk)
			return error::PLL_NOT_READY;
		clk = getMainPllPFrequency();
		break;
	default:
		return error::CLK_SRC_NOT_ABLE;
	}
	
	powerScale = getPowerScale();
	switch(powerScale)
	{
	default :
	case powerScale::SCALE1_MODE :
		ahbBoost = AHB_MAX_FREQ_SCALE1_BOOST;
		ahbMax = AHB_MAX_FREQ_SCALE1;
		break;

	case define::clock::powerScale::SCALE2_MODE :
		ahbBoost = AHB_MAX_FREQ_SCALE2_BOOST;
		ahbMax = AHB_MAX_FREQ_SCALE2;
		break;
	}

	ahbClk = clk / gHpreDiv[ahbDiv];
	if(ahbClk > ahbBoost)
	{
		if(powerScale == powerScale::SCALE1_MODE)
		{
			boostFlag = true;
			apb1Max = ahbMax;
			apb2Max = ahbMax;
		}
		else
			return error::WRONG_CONFIG;
	}
	else
	{
		boostFlag = false;
		ahbMax = ahbBoost;
		apb1Max = ahbBoost;
		apb2Max = ahbBoost;
	}

	if (ahbClk > ahbMax)
		return error::WRONG_CONFIG;

	apb1Clk = ahbClk / gPpreDiv[apb1Div];
	if (apb1Clk > apb1Max)
		return error::WRONG_CONFIG;

	apb2Clk = ahbClk / gPpreDiv[apb2Div];
	if (apb2Clk > apb2Max)
		return error::WRONG_CONFIG;

	// FLASH LATENCY 설정
	if(boostFlag)
	{
		setBitData(PWR->CR5, false, PWR_CR5_R1MODE_Pos);
		div = 34000000;
	}
	else
	{
		if(powerScale == powerScale::SCALE1_MODE)
			div = 30000000;
		else
			div = 12000000;
	}
	div = (ahbClk - 1) / div;
	setFieldData(FLASH->ACR, FLASH_ACR_LATENCY_Msk, div, FLASH_ACR_LATENCY_Pos);
	
	// 버스 클럭 프리스케일러 설정
	setThreeFieldData(RCC->CFGR, RCC_CFGR_PPRE2_Msk, apb2Div, RCC_CFGR_PPRE2_Pos, RCC_CFGR_PPRE1_Msk, apb1Div, RCC_CFGR_PPRE1_Pos, RCC_CFGR_HPRE_Msk, ahbDiv, RCC_CFGR_HPRE_Pos);

	// 클럭 소스 변경
	setFieldData(RCC->CFGR, RCC_CFGR_SW_Msk, sysclkSrc, RCC_CFGR_SW_Pos);

	return error::ERROR_NONE;
}

uint32_t Clock::getSystemClockFrequency(void)
{
	using namespace define::clock::sysclk::src;

	uint32_t clk;

	// 클럭 소스의 주파수 얻기
	switch (getFieldData(RCC->CFGR, RCC_CFGR_SW_Msk, RCC_CFGR_SW_Pos))
	{
	case HSI16 :
		return HSI_FREQ;

	case HSE :
		// HSE 활성화 점검
		if (~RCC->CR & RCC_CR_HSERDY_Msk)
			return error::HSE_NOT_READY;
		return gHseFreq;

	case PLL :
		// PLL 활성화 점검
		if (~RCC->CR & RCC_CR_PLLRDY_Msk)
			return error::PLL_NOT_READY;
		return getMainPllPFrequency();

	default:
		return 0;
	}
}


#endif


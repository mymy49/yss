////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32G4)

#include <drv/peripheral.h>
#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/rcc_stm32g4.h>

#define HSI_FREQ				16000000

#define HSE_RANGE1_MAX_FREQ		48000000
#define HSE_RANGE2_MAX_FREQ		26000000

#define VCO_RANGE1_MIN_FREQ		96000000
#define VCO_RANGE1_MAX_FREQ		344000000
#define VCO_RANGE2_MIN_FREQ		96000000
#define VCO_RANGE2_MAX_FREQ		344000000

#define PLL_RANGE1_MAX_FREQ		150000000
#define PLL_RANGE2_MAX_FREQ		26000000

#define PLL_M_MAX				15
#define PLL_N_MIN				8
#define PLL_N_MAX				127
#define PLL_P_MIN				2
#define PLL_P_MAX				31
#define PLL_Q_MAX				3
#define PLL_R_MAX				3


static uint32_t gHseFreq __attribute__((section(".non_init")));

static const int16_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const int16_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

void Clock::setVoltageScale(uint8_t scale)
{
	setFieldData(PWR[PWR_REG::CR1], PWR_CR1_VOS_Msk, scale, PWR_CR1_VOS_Pos);
	while(getBitData(PWR[PWR_REG::SR2], PWR_SR2_VOSF_Pos));

}

bool Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	gHseFreq = hseHz;
	
	switch(getFieldData(PWR[PWR_REG::CR1], PWR_CR1_VOS_Msk, PWR_CR1_VOS_Pos))
	{
	case define::clock::voltageScale::RANGE1 :
		if (HSE_RANGE1_MAX_FREQ < hseHz)
			return false;
		break;

	case define::clock::voltageScale::RANGE2 :
		if (HSE_RANGE2_MAX_FREQ < hseHz)
			return false;
		break;
	}

	if (useOsc)
		RCC[RCC_REG::CR] |= RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk;
	else
		RCC[RCC_REG::CR] |= RCC_CR_HSEON_Msk;

	for (uint32_t i = 0; i < 1000000; i++)
	{
		if (RCC[RCC_REG::CR] & RCC_CR_HSERDY_Msk)
			return true;
	}

	return false;
}

bool Clock::enableMainPll(uint8_t src, uint8_t m, uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	uint32_t vco, p, q, r, buf;
	uint8_t range = getFieldData(PWR[PWR_REG::CR1], PWR_CR1_VOS_Msk, PWR_CR1_VOS_Pos);

	using namespace define::clock::sysclk;
	
	// 현재 SysClk 소스가 PLL인이 확인
	if (getFieldData(RCC[RCC_REG::CFGR], RCC_CFGR_SWS_Msk, RCC_CFGR_SWS_Pos) == src::PLL)
		goto error;

	if (m > PLL_M_MAX)
		goto error;

	if (PLL_N_MIN > n || n > PLL_N_MAX)
		goto error;

#if defined(PLL_P_USE)
	if (pDiv < PLL_P_MIN || pDiv > PLL_P_MAX)
		goto error;
#endif

#if defined(PLL_Q_USE)
	if (qDiv > PLL_Q_MAX)
		goto error;
#endif

#if defined(PLL_R_USE)
	if (qDiv > PLL_R_MAX)
		goto error;
#endif

	switch (src)
	{
	case define::clock::pll::src::HSI16 :
		buf = HSI_FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (~RCC[RCC_REG::CR] & RCC_CR_HSERDY_Msk)
			goto error;
		buf = (uint32_t)gHseFreq;
		break;
	default:
		goto error;
	}

	using namespace define::clock::sysclk;
	if (RCC[RCC_REG::CR] & RCC_CR_PLLRDY_Msk && (RCC[RCC_REG::CFGR] & RCC_CFGR_SWS_Msk) >> RCC_CFGR_SWS_Pos == src::PLL)
		goto error;
	
	vco = buf / m * n;
	switch(range)
	{
	case define::clock::voltageScale::RANGE1 :
		if (vco < VCO_RANGE1_MIN_FREQ || VCO_RANGE1_MAX_FREQ < vco)
			goto error;
		break;

	case define::clock::voltageScale::RANGE2 :
		if (vco < VCO_RANGE2_MIN_FREQ || VCO_RANGE2_MAX_FREQ < vco)
			goto error;
		break;
	}

#if defined(PLL_P_USE)
	p = vco / pDiv;
	switch(range)
	{
	case define::clock::voltageScale::RANGE1 :
		if (p > PLL_RANGE1_MAX_FREQ)
			goto error;
		break;

	case define::clock::voltageScale::RANGE2 :
		if (p > PLL_RANGE2_MAX_FREQ)
			goto error;
		break;
	}

#else
	qDiv = getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLP_Msk, RCC_PLLCFGR_PLLP_Pos);
#endif

#if defined(PLL_Q_USE)
	q = vco / (2 * qDiv + 1);
	switch(range)
	{
	case define::clock::voltageScale::RANGE1 :
		if (q > PLL_RANGE1_MAX_FREQ)
			goto error;
		break;

	case define::clock::voltageScale::RANGE2 :
		if (q > PLL_RANGE2_MAX_FREQ)
			goto error;
		break;
	}
#else
	qDiv = getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLQ_Msk, RCC_PLLCFGR_PLLQ_Pos);
#endif

#if defined(PLL_R_USE)
	r = vco / (2 * rDiv + 1);
	switch(range)
	{
	case define::clock::voltageScale::RANGE1 :
		if (r > PLL_RANGE1_MAX_FREQ)
			goto error;
		break;

	case define::clock::voltageScale::RANGE2 :
		if (r > PLL_RANGE2_MAX_FREQ)
			goto error;
		break;
	}
#else
	rDiv = getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLR_Msk, RCC_PLLCFGR_PLLR_Pos);
#endif
	RCC[RCC_REG::PLLCFGR] = (qDiv << RCC_PLLCFGR_PLLQ_Pos) | (src << RCC_PLLCFGR_PLLSRC_Pos) | (pDiv << RCC_PLLCFGR_PLLP_Pos) | (n << RCC_PLLCFGR_PLLN_Pos) | (m << RCC_PLLCFGR_PLLM_Pos);
	RCC[RCC_REG::PLLCFGR] |= RCC_PLLCFGR_PLLPEN_Msk | RCC_PLLCFGR_PLLQEN_Msk | RCC_PLLCFGR_PLLREN_Msk;
	RCC[RCC_REG::CR] |= RCC_CR_PLLON_Msk;

	for (uint16_t i = 0; i < 10000; i++)
	{
		// PLL 활성화 확인
		if (RCC[RCC_REG::CR] & RCC_CR_PLLRDY_Msk)
			return true;
	}

error:
	return false;
}

#if defined(PLL_P_USE)
uint32_t Clock::getMainPllPFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLN_Msk) >> RCC_PLLCFGR_PLLN_Pos);
	clk /= 2  * (((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLP_Msk) >> RCC_PLLCFGR_PLLP_Pos ) + 1);
	return clk;
}
#endif

#if defined(PLL_Q_USE)
uint32_t Clock::getMainPllQFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLN_Msk) >> RCC_PLLCFGR_PLLN_Pos);
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLQ_Msk) >> RCC_PLLCFGR_PLLQ_Pos);
	return clk;
}
#endif

#if defined(PLL_R_USE)
uint32_t Clock::getMainPllRFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLN_Msk) >> RCC_PLLCFGR_PLLN_Pos);
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLR_Msk) >> RCC_PLLCFGR_PLLR_Pos);
	return clk;
}
#endif

uint32_t Clock::getSystemClockFrequency(void)
{
	uint32_t clk;

	switch((RCC[RCC_REG::CFGR] & RCC_CFGR_SWS_Msk) >> RCC_CFGR_SWS_Pos)
	{
	case RCC_CFGR_SW_HSI :
		return HSI_FREQ;
		break;
	
	case RCC_CFGR_SW_HSE :
		return gHseFreq;
		break;
	
	case RCC_CFGR_SW_PLL :
		return getMainPllPFrequency();
		return 0;
		break;

	default :
		return 0;
	}
}

bool Clock::setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2, uint8_t vcc)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	uint32_t clk, ahbClk, apb1Clk, apb2Clk, adcClk;
	uint8_t buf;
	uint8_t range = getFieldData(PWR[PWR_REG::CR1], PWR_CR1_VOS_Msk, PWR_CR1_VOS_Pos);

	using namespace define::clock::sysclk::src;
	switch (sysclkSrc)
	{
	case HSI:
		clk = HSI_FREQ;
		break;
	case HSE:
		// HSE 활성화 점검
		if (getBitData(peri[RCC_REG::CR], RCC_CR_HSERDY_Pos) == false)
			return false;
		clk = gHseFreq;
		break;
	case PLL:
		// PLL 활성화 점검
		if (getBitData(peri[RCC_REG::CR], RCC_CR_PLLRDY_Pos) == false)
			return false;
		clk = getMainPllPFrequency();
		break;
	default:
		return false;
	}

	switch(range)
	{
	case define::clock::voltageScale::RANGE1 :
		if (ahbClk > PLL_RANGE1_MAX_FREQ)
			return false;

	case define::clock::voltageScale::RANGE2 :
		if (ahbClk > PLL_RANGE2_MAX_FREQ)
			return false;
	}

	apb1Clk = ahbClk / gPpreDiv[apb1];
	switch(range)
	{
	case define::clock::voltageScale::RANGE1 :
		if (apb1Clk > PLL_RANGE1_MAX_FREQ)
			return false;

	case define::clock::voltageScale::RANGE2 :
		if (apb1Clk > PLL_RANGE2_MAX_FREQ)
			return false;
	}

	apb2Clk = ahbClk / gPpreDiv[apb2];
	switch(range)
	{
	case define::clock::voltageScale::RANGE1 :
		if (apb2Clk > PLL_RANGE1_MAX_FREQ)
			return false;

	case define::clock::voltageScale::RANGE2 :
		if (apb2Clk > PLL_RANGE2_MAX_FREQ)
			return false;
	}

	// 버스 클럭 프리스케일러 설정
	setThreeFieldData(peri[RCC_REG::CFGR], RCC_CFGR_PPRE1_Msk, apb1, RCC_CFGR_PPRE1_Pos, RCC_CFGR_PPRE2_Msk, apb2, RCC_CFGR_PPRE2_Pos, RCC_CFGR_HPRE_Msk, ahb, RCC_CFGR_HPRE_Pos);
	
	// 클럭 소스 변경
	setFieldData(peri[RCC_REG::CFGR], RCC_CFGR_SW_Msk, sysclkSrc, RCC_CFGR_SW_Pos);

	return true;
}

uint32_t Clock::getApb1ClockFrequency(void)
{
	return getSystemClockFrequency() / gPpreDiv[((RCC[RCC_REG::CFGR] & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos)];
}

uint32_t Clock::getApb2ClockFrequency(void)
{
	return getSystemClockFrequency() / gPpreDiv[((RCC[RCC_REG::CFGR] & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos)];
}

void Clock::enableAhb1Clock(uint32_t position, bool en)
{
	setBitData(RCC[RCC_REG::AHB1ENR], en, position);
}

void Clock::enableAhb2Clock(uint32_t position, bool en)
{
	setBitData(RCC[RCC_REG::AHB2ENR], en, position);
}

void Clock::enableAhb3Clock(uint32_t position, bool en)
{
	setBitData(RCC[RCC_REG::AHB3ENR], en, position);
}

void Clock::enableApb1_1Clock(uint32_t position, bool en)
{
	setBitData(RCC[RCC_REG::APB1ENR1], en, position);
}

void Clock::enableApb1_2Clock(uint32_t position, bool en)
{
	setBitData(RCC[RCC_REG::APB1ENR2], en, position);
}

void Clock::enableApb2Clock(uint32_t position, bool en)
{
	setBitData(RCC[RCC_REG::APB2ENR], en, position);
}

void Clock::resetAhb1(uint32_t position)
{
}

void Clock::resetApb1(uint32_t position)
{
}

void Clock::resetApb2(uint32_t position)
{
}

#endif


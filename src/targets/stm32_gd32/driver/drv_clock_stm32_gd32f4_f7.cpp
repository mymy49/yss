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

#if defined(GD32F4) || defined(STM32F4) || defined(STM32F7)

#include <drv/peripheral.h>
#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/rcc_stm32_gd32f4_f7.h>
#include <targets/st_gigadevice/flash_stm32_gd32f4_f7.h>

static uint32_t gHseFreq __attribute__((section(".non_init")));
static const uint32_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const uint32_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

#if defined(STM32F7)
enum I2SPLL
{
	VCO_MIN_FREQ = 100000000,
	VCO_MAX_FREQ = 432000000,
	P_MAX_FREQ = 216000000,
	Q_MAX_FREQ = 216000000,
	R_MAX_FREQ = 216000000,
	N_MIN = 2,
	N_MAX = 432,
	P_MAX = 3,
	Q_MIN = 2,
	Q_MAX = 15,
	R_MIN = 2,
	R_MAX = 7
};
#endif

bool Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	gHseFreq = hseHz;

	if (hseHz < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hseHz)
		return false;

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
	uint32_t vco, p, q, buf;

	using namespace define::clock::sysclk;
	
	// 현재 SysClk 소스가 PLL인이 확인
	if (getFieldData(RCC[RCC_REG::CFGR], RCC_CFGR_SWS_Msk, RCC_CFGR_SWS_Pos) == src::PLL)
		goto error;

	using namespace ec::clock;
	if (pll::M_MIN > m || m > pll::M_MAX)
		goto error;

	if (pll::N_MIN > n || n > pll::N_MAX)
		goto error;

#if defined(PLL_P_USE)
	if (pDiv > pll::P_MAX)
		goto error;
#endif

#if defined(PLL_Q_USE)
	if (pll::Q_MIN > qDiv || qDiv > pll::Q_MAX)
		goto error;
#endif

#if defined(PLL_R_USE)
	if (pll::R_MIN > qDiv || qDiv > pll::R_MAX)
		goto error;
#endif

	switch (src)
	{
	case define::clock::pll::src::HSI :
		buf = ec::clock::hsi::FREQ;
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
	using namespace ec::clock::pll;
	if (vco < pll::VCO_MIN_FREQ || pll::VCO_MAX_FREQ < vco)
		goto error;

#if defined(PLL_P_USE)
	p = vco / (2 << pDiv);
	using namespace ec::clock;
	if (p > pll::P_MAX_FREQ)
		goto error;
#else
	qDiv = getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLP_Msk, RCC_PLLCFGR_PLLP_Pos);
#endif

#if defined(PLL_Q_USE)
	q = vco / qDiv;
	if (q > pll::Q_MAX_FREQ)
		goto error;
#else
	qDiv = getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLQ_Msk, RCC_PLLCFGR_PLLQ_Pos);
#endif

#if defined(PLL_R_USE)
	r = vco / rDiv;
	if (r > pll::R_MAX_FREQ)
		goto error;
#else
	rDiv = getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLR_Msk, RCC_PLLCFGR_PLLR_Pos);
#endif
	RCC[RCC_REG::PLLCFGR] = (qDiv << RCC_PLLCFGR_PLLQ_Pos) | (src << RCC_PLLCFGR_PLLSRC_Pos) | (pDiv << RCC_PLLCFGR_PLLP_Pos) | (n << RCC_PLLCFGR_PLLN_Pos) | m;
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

	using namespace define::clock::sysclk;
	switch((RCC[RCC_REG::CFGR] & RCC_CFGR_SWS_Msk) >> RCC_CFGR_SWS_Pos)
	{
	case src::HSI :
		return ec::clock::hsi::FREQ;
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
	return getSystemClockFrequency() / gHpreDiv[((RCC[RCC_REG::CFGR] & RCC_CFGR_HPRE_Msk) >> RCC_CFGR_HPRE_Pos)];
}

uint32_t Clock::getAhbClockFrequency(void)
{
	return getCoreClockFrequency();
}

uint32_t Clock::getApb1ClockFrequency(void)
{
	return getSystemClockFrequency() / gPpreDiv[((RCC[RCC_REG::CFGR] & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos)];
}

uint32_t Clock::getApb2ClockFrequency(void)
{
	return getSystemClockFrequency() / gPpreDiv[((RCC[RCC_REG::CFGR] & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos)];
}

bool Clock::setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2, uint8_t vcc)
{
	int32_t  clk, ahbClk, apb1Clk, apb2Clk, adcClk;
	int8_t buf;

	using namespace define::clock::sysclk::src;
	switch (sysclkSrc)
	{
	case HSI:
		clk = ec::clock::hsi::FREQ;
		break;
	case HSE:
		// HSE 활성화 점검
		if (~RCC[RCC_REG::CR] & RCC_CR_HSERDY_Msk)
			return false;
		clk = gHseFreq;
		break;
	case PLL:
		// PLL 활성화 점검
		if (~RCC[RCC_REG::CR] & RCC_CR_PLLRDY_Msk)
			return false;
		clk = getMainPllPFrequency();
		break;
	default:
		return false;
	}

	ahbClk = clk / gHpreDiv[ahb];
	if (ahbClk > ec::clock::sysclk::MAX_FREQ)
		return false;

	apb1Clk = ahbClk / gPpreDiv[apb1];
	if (apb1Clk > ec::clock::apb1::MAX_FREQ)
		return false;

	apb2Clk = ahbClk / gPpreDiv[apb2];
	if (apb2Clk > ec::clock::apb2::MAX_FREQ)
		return false;

	// 버스 클럭 프리스케일러 설정
	setThreeFieldData(RCC[RCC_REG::CFGR], RCC_CFGR_PPRE2_Msk, apb2, RCC_CFGR_PPRE2_Pos, RCC_CFGR_PPRE1_Msk, apb1, RCC_CFGR_PPRE1_Pos, RCC_CFGR_HPRE_Msk, ahb, RCC_CFGR_HPRE_Pos);
	
	// 클럭 소스 변경
	setFieldData(RCC[RCC_REG::CFGR], RCC_CFGR_SW_Msk, sysclkSrc, RCC_CFGR_SW_Pos);

	return true;
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

void Clock::enableApb1Clock(uint32_t position, bool en)
{
	setBitData(RCC[RCC_REG::APB1ENR], en, position);
}

void Clock::enableApb2Clock(uint32_t position, bool en)
{
	setBitData(RCC[RCC_REG::APB2ENR], en, position);
}

void Clock::resetAhb1(uint32_t position)
{
	setBitData(RCC[RCC_REG::AHB1RSTR], true, position);
	setBitData(RCC[RCC_REG::AHB1RSTR], false, position);
}

void Clock::resetAhb2(uint32_t position)
{
	setBitData(RCC[RCC_REG::AHB2RSTR], true, position);
	setBitData(RCC[RCC_REG::AHB2RSTR], false, position);
}

void Clock::resetAhb3(uint32_t position)
{
	setBitData(RCC[RCC_REG::AHB3RSTR], true, position);
	setBitData(RCC[RCC_REG::AHB3RSTR], false, position);
}

void Clock::resetApb1(uint32_t position)
{
	setBitData(RCC[RCC_REG::APB1RSTR], true, position);
	setBitData(RCC[RCC_REG::APB1RSTR], false, position);
}

void Clock::resetApb2(uint32_t position)
{
	setBitData(RCC[RCC_REG::APB2RSTR], true, position);
	setBitData(RCC[RCC_REG::APB2RSTR], false, position);
}

#if defined(GD32F4) || defined(STM32F4) || defined(STM32F7)
void Clock::enableSdram(bool en)
{
	enableAhb3Clock(RCC_AHB3ENR_FMCEN_Pos);
}
#endif

#if defined(GD32F4) || defined(STM32F429xx) || defined(STM32F7)
void Clock::setLtdcDivisionFactor(uint8_t div)
{
#if defined(GD32F4) || defined(GD32F4)
	setFieldData(RCC[RCC_REG::DCKCFGR], RCC_DCKCFGR_PLLSAIDIVR_Msk, div, RCC_DCKCFGR_PLLSAIDIVR_Pos);
#elif defined(STM32F7)
	setFieldData(RCC[RCC_REG::DCKCFGR1], RCC_DCKCFGR1_PLLSAIDIVR_Msk, div, RCC_DCKCFGR1_PLLSAIDIVR_Pos);
#endif
}

uint32_t Clock::getLtdcClockFrequency(void)
{
#if defined(GD32F4) || defined(STM32F4)
	uint32_t div = getFieldData(RCC[RCC_REG::DCKCFGR], RCC_DCKCFGR_PLLSAIDIVR_Msk, RCC_DCKCFGR_PLLSAIDIVR_Pos);
#elif defined(STM32F7)
	uint32_t div = getFieldData(RCC[RCC_REG::DCKCFGR1], RCC_DCKCFGR1_PLLSAIDIVR_Msk, RCC_DCKCFGR1_PLLSAIDIVR_Pos);
#endif
	return getSaiPllRFrequency() / (2 << div);
}
#endif

#if defined(GD32F4) || defined(STM32F429xx) || defined(STM32F7)
bool Clock::enableSaiPll(uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	uint32_t vco, p, q, r, buf, m;

	using namespace ec::clock;

	if (~RCC[RCC_REG::CR] & RCC_CR_PLLRDY_Msk)
		goto error;

	if (saipll::N_MIN > n || n > saipll::N_MAX)
		goto error;

#if defined(SAIPLL_P_USE)
	if (pDiv > saipll::P_MAX)
		goto error;
#endif

#if defined(SAIPLL_Q_USE)
	if (saipll::Q_MIN > qDiv || qDiv > saipll::Q_MAX)
		goto error;
#endif

#if defined(SAIPLL_R_USE)
	if (saipll::R_MIN > rDiv || rDiv > saipll::R_MAX)
		goto error;
#endif

	switch (getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLSRC_Msk, RCC_PLLCFGR_PLLSRC_Pos))
	{
	case define::clock::pll::src::HSI:
		buf = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (~RCC[RCC_REG::CR] & RCC_CR_HSERDY_Msk)
			goto error;
		buf = (uint32_t)gHseFreq;
		break;
	default:
		goto error;
	}
	vco = buf / getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLM_Msk, RCC_PLLCFGR_PLLM_Pos) * n;
	using namespace ec::clock;
	if (vco < saipll::VCO_MIN_FREQ || saipll::VCO_MAX_FREQ < vco)
		goto error;

#if defined(SAIPLL_P_USE)
	p = vco / (2 << pDiv);
	if (saipll::P_MAX_FREQ < p)
		goto error;
#else
	pDiv = getFieldData(RCC[RCC_REG::PLLSAICFGR], RCC_PLLSAICFGR_PLLSAIP_Msk, RCC_PLLSAICFGR_PLLSAIP_Pos);
#endif

#if defined(SAIPLL_Q_USE)
	q = vco / qDiv;
	if (saipll::Q_MAX_FREQ < q)
		goto error;
#else
	qDiv = getFieldData(RCC[RCC_REG::PLLSAICFGR], RCC_PLLSAICFGR_PLLSAIQ_Msk, RCC_PLLSAICFGR_PLLSAIQ_Pos);
#endif

#if defined(SAIPLL_R_USE)
	r = vco / rDiv;
	if (saipll::R_MAX_FREQ < r)
		goto error;
#else
	rDiv = getFieldData(RCC[RCC_REG::PLLSAICFGR], RCC_PLLSAICFGR_PLLSAIR_Msk, RCC_PLLSAICFGR_PLLSAIR_Pos);
#endif
	
	RCC[RCC_REG::PLLSAICFGR] = rDiv << RCC_PLLSAICFGR_PLLSAIR_Pos | qDiv << RCC_PLLSAICFGR_PLLSAIQ_Pos | pDiv << RCC_PLLSAICFGR_PLLSAIP_Pos | n << RCC_PLLSAICFGR_PLLSAIN_Pos;
	setBitData(RCC[RCC_REG::CR], true, RCC_CR_PLLSAION_Pos);

	for (uint16_t i = 0; i < 10000; i++)
	{
		if (RCC[RCC_REG::CR] & RCC_CR_PLLSAIRDY_Msk)
		{
			return true;
		}
	}

error:
	return false;
}

#if defined(STM32F7)
uint32_t Clock::getI2sClockFrequency(void)
{
	if(RCC[RCC_REG::CFGR] & RCC_CFGR_I2SSRC_Msk)
#warning  "외부 클럭에 대한 설정이 가능하도록 업데이트 해야 함"
		return 0;
	else
		return getI2sPllRFrequency();
}
#endif

#if defined(SAIPLL_P_USE)
uint32_t Clock::getSaiPllPFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC[RCC_REG::PLLSAICFGR] & RCC_PLLSAICFGR_PLLSAIN_Msk) >> RCC_PLLSAICFGR_PLLSAIN_Pos);
	clk /= 2  * (((RCC[RCC_REG::PLLSAICFGR] & RCC_PLLSAICFGR_PLLSAIP_Msk) >> RCC_PLLSAICFGR_PLLSAIP_Pos ) + 1);
	return clk;
}
#endif

#if defined(SAIPLL_Q_USE)
uint32_t Clock::getSaiPllQFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC[RCC_REG::PLLSAICFGR] & RCC_PLLSAICFGR_PLLSAIN_Msk) >> RCC_PLLSAICFGR_PLLSAIN_Pos);
	clk /= ((RCC[RCC_REG::PLLSAICFGR] & RCC_PLLSAICFGR_PLLSAIQ_Msk) >> RCC_PLLSAICFGR_PLLSAIQ_Pos);
	return clk;
}
#endif

#if defined(SAIPLL_R_USE)
uint32_t Clock::getSaiPllRFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC[RCC_REG::PLLSAICFGR] & RCC_PLLSAICFGR_PLLSAIN_Msk) >> RCC_PLLSAICFGR_PLLSAIN_Pos);
	clk /= ((RCC[RCC_REG::PLLSAICFGR] & RCC_PLLSAICFGR_PLLSAIR_Msk) >> RCC_PLLSAICFGR_PLLSAIR_Pos);
	return clk;
}
#endif
#endif

#if defined(STM32F7)
bool Clock::enableI2sPll(uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	uint32_t vco, p, q, r, buf, m;

	if (~RCC[RCC_REG::CR] & RCC_CR_PLLRDY_Msk)
		goto error;

	if (I2SPLL::N_MIN > n || n > I2SPLL::N_MAX)
		goto error;

#if defined(I2SPLL_P_USE)
	if (pDiv > I2SPLL::P_MAX)
		goto error;
#endif

#if defined(I2SPLL_Q_USE)
	if (I2SPLL::Q_MIN > qDiv || qDiv > I2SPLL::Q_MAX)
		goto error;
#endif

#if defined(I2SPLL_R_USE)
	if (I2SPLL::R_MIN > rDiv || rDiv > I2SPLL::R_MAX)
		goto error;
#endif

	switch (getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLSRC_Msk, RCC_PLLCFGR_PLLSRC_Pos))
	{
	case define::clock::pll::src::HSI:
		buf = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE:
		if (~RCC[RCC_REG::CR] & RCC_CR_HSERDY_Msk)
			goto error;
		buf = (uint32_t)gHseFreq;
		break;
	default:
		goto error;
	}
	vco = buf / getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLM_Msk, RCC_PLLCFGR_PLLM_Pos) * n;

	if (vco < I2SPLL::VCO_MIN_FREQ || I2SPLL::VCO_MAX_FREQ < vco)
		goto error;

#if defined(I2SPLL_P_USE)
	p = vco / (2 << pDiv);
	if (I2SPLL::P_MAX_FREQ < p)
		goto error;
#else
	pDiv = getFieldData(RCC[RCC_REG::PLLSAICFGR], RCC_PLLSAICFGR_PLLSAIP_Msk, RCC_PLLSAICFGR_PLLSAIP_Pos);
#endif

#if defined(I2SPLL_Q_USE)
	q = vco / qDiv;
	if (I2SPLL::Q_MAX_FREQ < q)
		goto error;
#else
	qDiv = getFieldData(RCC[RCC_REG::PLLSAICFGR], RCC_PLLSAICFGR_PLLSAIQ_Msk, RCC_PLLSAICFGR_PLLSAIQ_Pos);
#endif

#if defined(I2SPLL_R_USE)
	r = vco / rDiv;
	if (I2SPLL::R_MAX_FREQ < r)
		goto error;
#else
	rDiv = getFieldData(RCC[RCC_REG::PLLSAICFGR], RCC_PLLSAICFGR_PLLSAIR_Msk, RCC_PLLSAICFGR_PLLSAIR_Pos);
#endif
	
	RCC[RCC_REG::PLLI2SCFGR] = rDiv << RCC_PLLI2SCFGR_PLLI2SR_Pos | qDiv << RCC_PLLI2SCFGR_PLLI2SQ_Pos | pDiv << RCC_PLLI2SCFGR_PLLI2SP_Pos | n << RCC_PLLI2SCFGR_PLLI2SN_Pos;
	setBitData(RCC[RCC_REG::CR], true, RCC_CR_PLLI2SON_Pos);

	for (uint16_t i = 0; i < 10000; i++)
	{
		if (RCC[RCC_REG::CR] & RCC_CR_PLLI2SRDY_Msk)
		{
			return true;
		}
	}

error:
	return false;
}

#if defined(I2SPLL_P_USE)
uint32_t Clock::getI2sPllPFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC[RCC_REG::PLLI2SCFGR] & RCC_PLLI2SCFGR_PLLI2SN_Msk) >> RCC_PLLI2SCFGR_PLLI2SN_Pos);
	clk /= 2  * (((RCC[RCC_REG::PLLI2SCFGR] & RCC_PLLI2SCFGR_PLLI2SP_Msk) >> RCC_PLLI2SCFGR_PLLI2SP_Pos ) + 1);
	return clk;
}
#endif

#if defined(I2SPLL_Q_USE)
uint32_t Clock::getI2sPllQFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC[RCC_REG::PLLI2SCFGR] & RCC_PLLI2SCFGR_PLLI2SN_Msk) >> RCC_PLLI2SCFGR_PLLI2SN_Pos);
	clk /= ((RCC[RCC_REG::PLLI2SCFGR] & RCC_PLLI2SCFGR_PLLI2SQ_Msk) >> RCC_PLLI2SCFGR_PLLI2SQ_Pos);
	return clk;
}
#endif

#if defined(I2SPLL_R_USE)
uint32_t Clock::getI2sPllRFrequency(void)
{
	uint32_t clk = gHseFreq;
	clk /= ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos);
	clk *= ((RCC[RCC_REG::PLLI2SCFGR] & RCC_PLLI2SCFGR_PLLI2SN_Msk) >> RCC_PLLI2SCFGR_PLLI2SN_Pos);
	clk /= ((RCC[RCC_REG::PLLI2SCFGR] & RCC_PLLI2SCFGR_PLLI2SR_Msk) >> RCC_PLLI2SCFGR_PLLI2SR_Pos);
	return clk;
}
#endif
#endif

#endif


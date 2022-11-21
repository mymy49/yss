////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
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

bool Clock::enableHse(uint32_t hseHz, bool useOsc)
{
	gHseFreq = hseHz;

	if (hseHz < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hseHz)
		return false;

	if (useOsc)
		RCC[RCC_REG::CR] |= RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk;
	else
		RCC[RCC_REG::CR] |= RCC_CR_HSEON_Msk;

	for (uint32_t i = 0; i < 10000; i++)
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

	using namespace ec::clock::pll;
	if (M_MIN > m || m > M_MAX)
		goto error;

	if (N_MIN > n || n > N_MAX)
		goto error;

	if (pDiv > P_MAX)
		goto error;

	if (Q_MIN > qDiv || qDiv > Q_MAX)
		goto error;

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
	if (vco < VCO_MIN_FREQ || VCO_MAX_FREQ < vco)
		goto error;

	p = vco / (2 << pDiv);
	using namespace ec::clock;
	if (p > pll::P_MAX_FREQ)
		goto error;

	q = vco / qDiv;
	if (q > pll::Q_MAX_FREQ)
		goto error;
	
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

uint32_t Clock::getMainPllFrequency(void)
{
	return gHseFreq / ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos) * ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLN_Msk) >> RCC_PLLCFGR_PLLN_Pos) / (2 << ((RCC[RCC_REG::PLLCFGR] & RCC_PLLCFGR_PLLP_Msk) >> RCC_PLLCFGR_PLLP_Pos));
}

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
		return getMainPllFrequency();
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

void Clock::enableSdram(bool en)
{
	enableAhb3Clock(RCC_AHB3ENR_FMCEN_Pos);
}

#if !defined(STM32F411xE)
bool Clock::enableSaiPll(uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	uint32_t vco, q, r, p, lcd, sai, buf, m;

	using namespace ec::clock;

	if (~RCC[RCC_REG::CR] & RCC_CR_PLLRDY_Msk)
		goto error;

	if (saipll::N_MIN > n || n > saipll::N_MAX)
		goto error;

	if (pDiv > saipll::P_MAX)
		goto error;

#if defined(STM32F4) || defined(STM32F7)
	if (saipll::Q_MIN > qDiv || qDiv > saipll::Q_MAX)
		goto error;
#endif

	if (saipll::R_MIN > rDiv || rDiv > saipll::R_MAX)
		goto error;

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

#if defined(STM32F7)
	p = vco / (2 << pDiv);
	if (saipll::P_MAX_FREQ < p)
		goto error;
#endif

	sai = vco / qDiv;
	if (saipll::Q_MAX_FREQ < sai)
		goto error;

	lcd = vco / rDiv;
	if (saipll::R_MAX_FREQ < lcd)
		goto error;
	
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
#endif

#if !(defined(STM32F4) || defined(STM32F7))
bool Clock::enableI2sPll(uint16_t n, uint8_t pDiv, uint8_t qDiv, uint8_t rDiv)
{
	uint32_t vco, r, i2s, buf, m;

	using namespace ec::clock::i2spll;

	if (~RCC[RCC_REG::CR] & RCC_CR_PLLRDY_Msk)
		goto error;

	if (N_MIN > n || n > N_MAX)
		goto error;

#if defined(STM32F4) || defined(STM32F7)
	if (pDiv > saipll::P_MAX)
		goto error;

	if (saipll::Q_MIN > qDiv || qDiv > saipll::Q_MAX)
		goto error;
#endif

	if (R_MIN > rDiv || rDiv > R_MAX)
		goto error;

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

	if (vco < VCO_MIN_FREQ || VCO_MAX_FREQ < vco)
		goto error;

	i2s = vco / rDiv;
	if (I2S_MAX_FREQ < i2s)
		goto error;
	
	RCC[RCC_REG::PLLI2SCFGR] = rDiv << RCC_PLLI2SCFGR_PLLI2SR_Pos | qDiv << RCC_PLLI2SCFGR_PLLI2SQ_Pos | n << RCC_PLLI2SCFGR_PLLI2SN_Pos;
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
#endif

#if !(defined(STM32F4) || defined(STM32F7))
uint32_t Clock::getLtdcFrequency(void)
{
	return gHseFreq / getFieldData(RCC[RCC_REG::PLLCFGR], RCC_PLLCFGR_PLLM_Msk, RCC_PLLCFGR_PLLM_Pos) * getFieldData(RCC[RCC_REG::PLLSAICFGR], RCC_PLLSAICFGR_PLLSAIN_Msk, RCC_PLLSAICFGR_PLLSAIN_Pos) / getFieldData(RCC[RCC_REG::PLLSAICFGR], RCC_PLLSAICFGR_PLLSAIR_Msk, RCC_PLLSAICFGR_PLLSAIR_Pos) / (2 << getFieldData(RCC[RCC_REG::DCKCFGR], RCC_DCKCFGR_PLLSAIDIVR_Msk, RCC_DCKCFGR_PLLSAIDIVR_Pos));
}
#endif 

#if defined(GD32F4)
uint32_t Clock::getI2sClockFrequency(void)
{
	return 0;
//	return gI2sPllFreq;
}
#endif

#if !(defined(STM32F4) || defined(STM32F7))
void Clock::setLtdcDivisionFactor(uint8_t div)
{
	setFieldData(RCC[RCC_REG::DCKCFGR], RCC_DCKCFGR_PLLSAIDIVR_Msk, div, RCC_DCKCFGR_PLLSAIDIVR_Pos);
}
#endif

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
		clk = getMainPllFrequency();
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


/*
void Clock::enableSdram(bool en)
{
	if(en)
		RCU_AHB3EN |= RCU_AHB3EN_EXMCEN;
	else
		RCU_AHB3EN &= ~RCU_AHB3EN_EXMCEN;
}

*/
#endif


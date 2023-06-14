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

#if defined(STM32L1)

#include <drv/peripheral.h>
#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/rcc_stm32l1.h>
#include <targets/st_gigadevice/pwr_stm32l1.h>

int32_t  gHseFreq __attribute__((section(".non_init")));
int32_t  gLseFreq __attribute__((section(".non_init")));

static const int16_t gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const int16_t gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

void Clock::setVoltageScale(uint8_t scale)
{
	setFieldData(PWR[PWR_REG::CR], PWR_CR_VOS_Msk, scale, PWR_CR_VOS_Pos);
}

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

error Clock::enableMainPll(uint8_t src, uint8_t div, uint8_t mul)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;

	uint32_t pll;

	using namespace define::clock::sysclk;
	
	// 현재 SysClk 소스가 PLL인이 확인
	if (getFieldData(peri[RCC_REG::CFGR], RCC_CFGR_SWS_Msk, RCC_CFGR_SWS_Pos) == src::PLL)
		return error::SYSCLK_SRC_IS_PLL;

	using namespace ec::clock::pll;
	if (src > PLL_SRC_MAX)
		return error::WRONG_CONFIG;

	if (PLL_DIV_MIN > div || div > PLL_DIV_MAX)
		return error::WRONG_CONFIG;

	if (mul > PLL_MUL_MAX)
		return error::WRONG_CONFIG;

	if (src == src::HSE)
	{
		// HSE 활성화 확인
		if (getBitData(peri[RCC_REG::CR], RCC_CR_HSERDY_Pos))
			pll = gHseFreq;
		else
			return error::HSE_NOT_READY;
	}
	else
		pll = ec::clock::hsi::FREQ;

	if (pll < PLL_IN_MIN_FREQ || PLL_IN_MAX_FREQ < pll)
		return error::WRONG_CLOCK_FREQUENCY;
	
	if(mul & 0x01)
		pll *= 4 << (mul >> 1);
	else
		pll *= 3 << (mul >> 1);
	
	pll /= (div + 1);

	if (pll < PLL_OUT_MIN_FREQ || PLL_OUT_MAX_FREQ < pll)
		return error::WRONG_CLOCK_FREQUENCY;
		
	setFieldData(peri[RCC_REG::CFGR], RCC_CFGR_PLLMUL_Msk, mul, RCC_CFGR_PLLMUL_Pos);
	setFieldData(peri[RCC_REG::CFGR], RCC_CFGR_PLLDIV_Msk, div, RCC_CFGR_PLLDIV_Pos);
	setBitData(peri[RCC_REG::CFGR], src, RCC_CFGR_PLLSRC_Pos);

	// PLL 활성화
	setBitData(peri[RCC_REG::CR], true, RCC_CR_PLLON_Pos);
	for (uint16_t i = 0; i < 10000; i++)
	{
		// PLL 활성화 확인
		if (getBitData(peri[RCC_REG::CR], RCC_CR_PLLRDY_Pos))
			return true;
	}

error:
	return false;
}

bool Clock::setSysclk(uint8_t sysclkSrc, uint8_t ahb, uint8_t apb1, uint8_t apb2, uint8_t vcc)
{
	uint32_t clk, ahbClk, apb1Clk, apb2Clk;
	uint8_t buf;

	using namespace define::clock::sysclk::src;
	switch (sysclkSrc)
	{
	case HSI:
		clk = ec::clock::hsi::FREQ;
		break;
	case HSE:
		// HSE 활성화 점검
		if (getBitData(RCC[RCC_REG::CR], RCC_CR_HSERDY_Pos) == false)
			return false;
		clk = gHseFreq;
		break;
	case PLL:
		// PLL 활성화 점검
		if (getBitData(RCC[RCC_REG::CR], RCC_CR_PLLRDY_Pos) == false)
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

uint32_t Clock::getMainPllFrequency(void)
{
	uint32_t mul = getFieldData(RCC[RCC_REG::CFGR], RCC_CFGR_PLLMUL_Msk, RCC_CFGR_PLLMUL_Pos), clk;

	switch(getBitData(RCC[RCC_REG::CFGR], RCC_CFGR_PLLSRC_Pos))
	{
	case define::clock::pll::src::HSI :
		clk = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE :
		clk = gHseFreq;
		break;
	default :
		return 0;
	}

	if(mul & 0x01)
		clk *= 4 << (mul >> 1);
	else
		clk *= 3 << (mul >> 1);
	
	return clk / (getFieldData(RCC[RCC_REG::CFGR], RCC_CFGR_PLLDIV_Msk, RCC_CFGR_PLLDIV_Pos) + 1);
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

void Clock::setClockOutput(uint8_t source, uint8_t div)
{
	setFieldData(RCC[RCC_REG::CFGR], RCC_CFGR_MCOPRE_Msk, div, RCC_CFGR_MCOPRE_Pos);
	setFieldData(RCC[RCC_REG::CFGR], RCC_CFGR_MCOSEL_Msk, source, RCC_CFGR_MCOSEL_Pos);
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

void Clock::enableAhb1Clock(uint32_t position, bool en)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[RCC_REG::AHBENR], en, position);
}

void Clock::enableApb1Clock(uint32_t position, bool en)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[RCC_REG::APB1ENR], en, position);
}

void Clock::enableApb2Clock(uint32_t position, bool en)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[RCC_REG::APB2ENR], en, position);
}

void Clock::resetAhb1(uint32_t position)
{
#if defined(GD32F1)
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[RCC_REG::AHBRSTR], true, position);
	setBitData(peri[RCC_REG::AHBRSTR], false, position);
#endif
}

void Clock::resetApb1(uint32_t position)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[RCC_REG::APB1RSTR], true, position);
	setBitData(peri[RCC_REG::APB1RSTR], false, position);
}

void Clock::resetApb2(uint32_t position)
{
	volatile uint32_t* peri = (volatile uint32_t*)RCC;
	setBitData(peri[RCC_REG::APB2RSTR], true, position);
	setBitData(peri[RCC_REG::APB2RSTR], false, position);
}

#endif


////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || \
	defined(STM32L496xx) || defined(STM32L4A6xx)

#include <__cross_studio_io.h>

#include <config.h>
#include <drv/peripherals.h>

#if defined(RCC)
drv::Clock clock;
#endif

namespace drv
{
unsigned char gHseFreq __attribute__((section(".non_init")));
unsigned int gPllFreq __attribute__((section(".non_init")));
unsigned int gSaiPllFreq __attribute__((section(".non_init")));
unsigned int gLcdPllFreq __attribute__((section(".non_init")));

static const unsigned int gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const unsigned int gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

bool Clock::setVosRange(unsigned char range)
{
	if (range < 1 || 2 < range)
		return false;

	unsigned int reg;

	if (~RCC->APB1ENR1 & RCC_APB1ENR1_PWREN_Msk)
		RCC->APB1ENR1 |= RCC_APB1ENR1_PWREN_Msk;
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	while (PWR->SR2 & PWR_SR2_VOSF_Msk)
		;
	reg = PWR->CR1;
	reg = (reg & ~PWR_CR1_VOS_Msk) | (range << PWR_CR1_VOS_Pos);
	PWR->CR1 = reg;
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	while (PWR->SR2 & PWR_SR2_VOSF_Msk)
		;

	return true;
}

unsigned char Clock::getVosRange(void)
{
	return (PWR->CR1 & PWR_CR1_VOS_Msk) >> PWR_CR1_VOS_Pos;
}

bool Clock::enableHse(unsigned char hseMhz, bool useOsc)
{
	unsigned int hse = (unsigned int)hseMhz * 1000000, maxHse;
	gHseFreq = hseMhz;

#if defined(YSS_PERI_REPORT)
	debug_printf("\n########## HSE 장치 설정 ##########\n\n");
	debug_printf("외부 크리스탈 클럭 = %d MHz\n", hseMhz);
#endif
	switch (getVosRange())
	{
	case 1: // RANGE1
		maxHse = ec::clock::hse::RANGE1_HSE_MAX_FREQ;
		break;
	case 2: // RANGE2
		maxHse = ec::clock::hse::RANGE2_HSE_MAX_FREQ;
		break;
	default:
		return false;
	}

	if (maxHse < hse)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("HSE 클럭이 입력 허용 범위를 초과했습니다. %d kHz(user) < %d kHz(max).\n", hse / 1000, maxHse / 1000);
#endif
		return false;
	}

	if (useOsc)
	{
		RCC->CR |= RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk;
	}
	else
		RCC->CR |= RCC_CR_HSEON_Msk;

	for (unsigned int i = 0; i < 100000; i++)
	{
		if (RCC->CR & RCC_CR_HSERDY_Msk)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 완료.\n");
#endif
			return true;
		}
	}

#if defined(YSS_PERI_REPORT)
	debug_printf("장치 설정 실패.\n");
	debug_printf("활성화 대기 시간을 초과했습니다.\n");
#endif
	return false;
}

unsigned int Mainpll::getPClk(void)
{
	return mPClk;
}

unsigned int Mainpll::getQClk(void)
{
	return mQClk;
}

unsigned int Mainpll::getRClk(void)
{
	return mRClk;
}

void Mainpll::setPEn(bool en)
{
	if(en)
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLPEN_Msk;
	else
		RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLPEN_Msk;
}

void Mainpll::setQEn(bool en)
{
	if(en)
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLQEN_Msk;
	else
		RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLQEN_Msk;
}

void Mainpll::setREn(bool en)
{
	if(en)
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN_Msk;
	else
		RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLREN_Msk;
}

bool Mainpll::enable(unsigned char src, unsigned int vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv)
{
	signed int m = -1;
	unsigned int vco, pClk, qClk, rClk, n, clk, buf, reg, min, max;
	unsigned char range = clock.getVosRange();

#if defined(YSS_PERI_REPORT)
	debug_printf("\n########## Main PLL 장치 설정 ##########\n\n");
#endif

	switch (src)
	{
	case define::clock::pll::src::HSI:
#if defined(YSS_PERI_REPORT)
		debug_printf("클럭 소스 = HSI 내부 RC 16MHz\n");
#endif
		clk = ec::clock::hsi::FREQ;
		break;
	case define::clock::pll::src::HSE:
#if defined(YSS_PERI_REPORT)
		debug_printf("클럭 소스 = HSE 외부 크리스탈\n");
#endif
		reg = RCC->CR;
		if (~reg & RCC_CR_HSERDY_Msk && ~reg & (RCC_CR_HSEBYP_Msk | RCC_CR_HSEON_Msk))
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("HSE 클럭이 활성화되지 않았습니다.\n");
#endif
			goto error;
		}
		clk = (unsigned long)gHseFreq * 1000000;
		break;
	default:
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("클럭 소스의 선택 범위를 초과했습니다.\n");
#endif
		goto error;
	}

	using namespace ec::clock::pll;

	switch (range)
	{
	case 1:
		min = RANGE1_VCO_MIN_FREQ;
		max = RANGE1_VCO_MAX_FREQ;
		break;
	case 2:
		min = RANGE2_VCO_MIN_FREQ;
		max = RANGE2_VCO_MAX_FREQ;
		break;
	default:
		goto error;
		break;
	}

	vco = vcoMhz * 1000000;
	if (vco < min || max < vco)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("VCO 클럭이 허용 범위를 벗어났습니다. %d kHz(min) < %d kHz(user) < %d kHz(max).\n", min / 1000, vco / 1000, max / 1000);
#endif
		goto error;
	}

	using namespace define::clock::sysclk;
	if (RCC->CR & RCC_CR_PLLRDY_Msk == true)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("장치가 이미 활성화되어 있습니다.\n");
#endif
		goto error;
	}

	for (int i = 0; i <= M_MAX; i++)
	{
		buf = clk / (i + 1);
		if((buf < INPUT_MIN_FREQ) && (buf > INPUT_MAX_FREQ))
			continue;

		if(vco % buf)
			continue;

		n = vco / buf;
		if (N_MIN > n || n > N_MAX)
			continue;

		m = i;
		break;
	}

	if (m < 0)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("N, M 계산에 실패 했습니다.\n");
#endif
		goto error;
	}

	if (P_MIN > pDiv || pDiv > P_MAX)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("인자 pDiv의 설정이 허용 범위를 초과했습니다. %d(min) < %d(user) < %d(max).\n", P_MIN, pDiv, P_MAX);
#endif
		goto error;
	}

	if (qDiv > Q_MAX)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("인자 qDiv의 설정이 허용 범위를 벗어났습니다. %d(user) < %d(max).\n", qDiv, Q_MAX);
#endif
		goto error;
	}

#if defined(STM32L496xx) || defined(STM32L4A6xx)
	pClk = vco / pDiv;
#elif defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx)
	if(pDiv)
		pClk = vco / 7;
	else
		pClk = vco / 17;
#endif
	using namespace ec::clock::pll;

	switch (range)
	{
	case 1:
		min = RANGE1_P_MIN_FREQ;
		max = RANGE1_P_MAX_FREQ;
		break;
	case 2:
		min = RANGE1_P_MIN_FREQ;
		max = RANGE2_P_MAX_FREQ;
		break;
	}

	if (min > pClk || pClk > max)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("Main PLLP의 설정 주파수가 허용 범위를 초과했습니다. %d kHz(min) < %d kHz(user) < %d kHz(max).\n", min / 1000, pClk / 1000, max / 1000);
#endif
		goto error;
	}

	qClk = vco / (2 * (qDiv + 1));

	switch (range)
	{
	case 1:
		min = RANGE1_Q_MIN_FREQ;
		max = RANGE1_Q_MAX_FREQ;
		break;
	case 2:
		min = RANGE1_Q_MIN_FREQ;
		max = RANGE2_Q_MAX_FREQ;
		break;
	}

	if (min > qClk || qClk > max)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("Main PLLQ의 설정 주파수가 허용 범위를 초과했습니다. %d kHz(min) < %d kHz(user) < %d kHz(max).\n", min / 1000, qClk / 1000, max / 1000);
#endif
		goto error;
	}

	rClk = vco / (2 * (rDiv + 1));

	switch (range)
	{
	case 1:
		min = RANGE1_R_MIN_FREQ;
		max = RANGE1_R_MAX_FREQ;
		break;
	case 2:
		min = RANGE1_R_MIN_FREQ;
		max = RANGE2_R_MAX_FREQ;
		break;
	}

	if (min > rClk || rClk > max)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("Main PLLR의 설정 주파수가 허용 범위를 초과했습니다. %d kHz(min) < %d kHz(user) < %d kHz(max).\n", min / 1000, rClk / 1000, max / 1000);
#endif
		goto error;
	}

	reg = RCC->PLLCFGR;
#if defined(STM32L496xx) || defined(STM32L4A6xx)
	reg &= ~(RCC_PLLCFGR_PLLM_Msk | (0x1F << 27) | RCC_PLLCFGR_PLLQ_Msk | RCC_PLLCFGR_PLLR_Msk | RCC_PLLCFGR_PLLN_Msk | RCC_PLLCFGR_PLLSRC_Msk);
	reg |= (m << RCC_PLLCFGR_PLLM_Pos) | (pDiv << 27) | (qDiv << RCC_PLLCFGR_PLLQ_Pos) | (rDiv << RCC_PLLCFGR_PLLR_Pos) | (n << RCC_PLLCFGR_PLLN_Pos) | (src << RCC_PLLCFGR_PLLSRC_Pos);
#elif defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx)
	reg &= ~(RCC_PLLCFGR_PLLM_Msk | RCC_PLLCFGR_PLLP_Msk | RCC_PLLCFGR_PLLQ_Msk | RCC_PLLCFGR_PLLR_Msk | RCC_PLLCFGR_PLLN_Msk | RCC_PLLCFGR_PLLSRC_Msk);
	reg |= (m << RCC_PLLCFGR_PLLM_Pos) | (pDiv << RCC_PLLCFGR_PLLP_Pos) | (qDiv << RCC_PLLCFGR_PLLQ_Pos) | (rDiv << RCC_PLLCFGR_PLLR_Pos) | (n << RCC_PLLCFGR_PLLN_Pos) | (src << RCC_PLLCFGR_PLLSRC_Pos);
#endif
	RCC->PLLCFGR = reg;

	RCC->CR |= RCC_CR_PLLON_Msk;

	for (unsigned short i = 0; i < 10000; i++)
	{
		if (RCC->CR & RCC_CR_PLLRDY_Msk)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("PLL P = %d kHz\n", pClk / 1000);
			debug_printf("PLL Q = %d kHz\n", qClk / 1000);
			debug_printf("PLL R = %d kHz\n", rClk / 1000);
			debug_printf("장치 설정 완료.\n");
#endif
			mPClk = pClk;
			mQClk = qClk;
			mRClk = rClk;
			return true;
		}
	}

#if defined(YSS_PERI_REPORT)
	debug_printf("장치 설정 실패.\n");
	debug_printf("활성화 대기 시간을 초과했습니다.\n");
#endif
error:
	mPClk = 0;
	mQClk = 0;
	mRClk = 0;
	return false;
}

bool Clock::setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2)
{
	unsigned int clk, ahbClk, apb1Clk, apb2Clk, adcClk, min, max, reg;
	unsigned char range = clock.getVosRange();

#if defined(YSS_PERI_REPORT)
	debug_printf("\n##########  시스템 클럭 설정 ##########\n\n");
#endif

	using namespace define::clock::sysclk::src;
	switch (sysclkSrc)
	{
	case HSI:
#if defined(YSS_PERI_REPORT)
		debug_printf("클럭 소스 = HSI 내부 RC 16MHz\n");
#endif
		clk = ec::clock::hsi::FREQ;
		break;
	case HSE:
#if defined(YSS_PERI_REPORT)
		debug_printf("클럭 소스 = HSE 외부 크리스탈\n");
#endif
		if (~RCC->CR & RCC_CR_HSERDY_Msk)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("외부 크리스탈이 현재 동작중이 아닙니다. 먼저 외부 크리스탈을 활성화 해주세요.\n");
#endif
			return false;
		}
		clk = gHseFreq * 1000000;
		break;
	case PLL:
#if defined(YSS_PERI_REPORT)
		debug_printf("클럭 소스 = PLL\n");
#endif
		if (~RCC->CR & RCC_CR_PLLRDY_Msk)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("PLL이 현재 동작중이 아닙니다. 먼저 PLL을 활성화 해주세요.\n");
#endif
			return false;
		}

		if(~RCC->PLLCFGR & RCC_PLLCFGR_PLLREN_Msk)
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("장치 설정 실패.\n");
			debug_printf("PLLR이 활성화가 안되어 있습니다. 먼저 PLLR을 활성화 해주세요.\n");
#endif
			return false;
		}
		clk = pll.getRClk();
		break;
	default:
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("지정된 클럭 소스가 유효하지 않습니다.\n");
#endif
		return false;
	}

	switch (range)
	{
	case 1:
		max = ec::clock::sysclk::RANGE1_MAX_FREQ;
		break;
	case 2:
		max = ec::clock::sysclk::RANGE2_MAX_FREQ;
		break;
	}

	ahbClk = clk / gHpreDiv[ahb];
	if (ahbClk > max)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("Sysclk 주파수가 허용 범위를 초과했습니다. %d(user) < %d(max).\n", ahbClk, max);
#endif
		return false;
	}

	switch (range)
	{
	case 1:
		max = ec::clock::apb1::RANGE1_MAX_FREQ;
		break;
	case 2:
		max = ec::clock::apb1::RANGE2_MAX_FREQ;
		break;
	}

	apb1Clk = ahbClk / gPpreDiv[apb1];
	if (apb1Clk > max)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("APB1 주파수가 허용 범위를 초과했습니다. %d(user) < %d(max).\n", apb1Clk, max);
#endif
		return false;
	}

	switch (range)
	{
	case 1:
		max = ec::clock::apb2::RANGE1_MAX_FREQ;
		break;
	case 2:
		max = ec::clock::apb2::RANGE2_MAX_FREQ;
		break;
	}

	apb2Clk = ahbClk / gPpreDiv[apb2];
	if (apb2Clk > max)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("APB2 주파수가 허용 범위를 초과했습니다. %d(user) < %d(max).\n", apb2Clk, max);
		return false;
#endif
	}

	reg = RCC->CFGR;
	reg &= ~(RCC_CFGR_PPRE1_Msk | RCC_CFGR_PPRE2_Msk | RCC_CFGR_HPRE_Msk);
	reg |= (apb1 << RCC_CFGR_PPRE1_Pos) | (apb2 << RCC_CFGR_PPRE2_Pos) | (ahb << RCC_CFGR_HPRE_Pos);
	RCC->CFGR = reg;

	flash.setLatency(ahbClk);

	reg &= ~RCC_CFGR_SW_Msk;
	reg |= sysclkSrc << RCC_CFGR_SW_Pos;
	RCC->CFGR = reg;

#if defined(YSS_PERI_REPORT)
	debug_printf("Sysclk = %d kHz\n", ahbClk / 1000);
	debug_printf("APB1 = %d kHz\n", apb1Clk / 1000);
	debug_printf("APB2 = %d kHz\n", apb2Clk / 1000);
	debug_printf("장치 설정 완료.\n");
#endif

	return true;
}

unsigned int Clock::getSysClkFreq(void)
{
	unsigned int clk;

	switch ((RCC->CFGR & RCC_CFGR_SWS_Msk) >> RCC_CFGR_SWS_Pos)
	{
	case define::clock::sysclk::src::HSI:
		clk = ec::clock::hsi::FREQ;
		break;
	case define::clock::sysclk::src::HSE:
		clk = gHseFreq * 1000000;
		break;
	case define::clock::sysclk::src::PLL:
		clk = gPllFreq;
		break;
	}

	clk /= gHpreDiv[(RCC->CFGR & RCC_CFGR_HPRE_Msk) >> RCC_CFGR_HPRE_Pos];

	return clk;
}

unsigned int Clock::getApb1ClkFreq(void)
{
	return getSysClkFreq() / gPpreDiv[(RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos];
}

unsigned int Clock::getApb2ClkFreq(void)
{
	return getSysClkFreq() / gPpreDiv[(RCC->CFGR & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos];
}

unsigned int Clock::getTimerApb1ClkFreq(void)
{
	unsigned int div = gPpreDiv[(RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos];
	unsigned int clk = clock.getSysClkFreq() / div;
	if (div > 1)
		clk <<= 1;
	return clk;
}

unsigned int Clock::getTimerApb2ClkFreq(void)
{
	unsigned int div = gPpreDiv[(RCC->CFGR & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos];
	unsigned int clk = clock.getSysClkFreq() / div;
	if (div > 1)
		clk <<= 1;
	return clk;
}
/*
bool Saipll::enable(unsigned long vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv)
{
#if defined(YSS_PERI_REPORT)
	debug_printf("\n########## SAI PLL 장치 설정 ##########\n\n");
#endif

	unsigned long vco, sai, lcd, n, buf, m;
	bool able = getRccMainPllReady();

	if (!able)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("Main PLL을 먼저 설정해야 합니다.\n");
#endif
		goto error;
	}
	vco = vcoMhz * 1000000;
	using namespace ec::clock::saipll;
	if (vco < VCO_MIN_FREQ && VCO_MAX_FREQ < vco)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("VCO 클럭이 허용 범위를 초과했습니다. %d kHz(min) < %d kHz(user) < %d kHz(max).\n", VCO_MIN_FREQ / 1000, vco / 1000, VCO_MAX_FREQ / 1000);
#endif
		goto error;
	}

	m = getRccMainPllm();
	buf = gHseFreq;
	buf *= 1000000;
	buf /= m;

	n = vco / buf;
	if (N_MIN > n || n > N_MAX)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("계산 값 N이 허용 범위를 초과했습니다. 인자 vcoMhz의 값을 확인해주세요. %d(min) < %d(user) < %d(max).\n", N_MIN, n, N_MAX);
#endif
		goto error;
	}

	if (Q_MIN > qDiv || qDiv > Q_MAX)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("인자 qDiv의 설정이 허용 범위를 초과했습니다. %d(min) < %d(user) < %d(max).\n", Q_MIN, qDiv, Q_MAX);
#endif
		goto error;
	}

	if (R_MIN > rDiv || rDiv > R_MAX)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("인자 rDiv의 설정이 허용 범위를 초과했습니다. %d(min) < %d(user) < %d(max).\n", R_MIN, rDiv, R_MAX);
#endif
		goto error;
	}

	sai = vco / qDiv;
	if (SAI_MAX_FREQ < sai)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("SAI를 위한 SAI PLL의 설정 주파수가 허용 범위를 초과했습니다. %d kHz(user) < %d kHz(max).\n", sai / 1000, SAI_MAX_FREQ / 1000);
#endif
		goto error;
	}

	lcd = vco / rDiv;
	if (SAI_MAX_FREQ < lcd)
	{
#if defined(YSS_PERI_REPORT)
		debug_printf("장치 설정 실패.\n");
		debug_printf("TFT LCD를 위한 SAI PLL의 설정 주파수가 허용 범위를 초과했습니다. %d kHz(user) < %d kHz(max).\n", lcd / 1000, SAI_MAX_FREQ / 1000);
#endif
		goto error;
	}

	setRccSaiPlln(n);
	setRccSaiPllq(qDiv);
	setRccSaiPllr(rDiv);

	setRccSaiPllOn(true);

	for (unsigned short i = 0; i < 10000; i++)
	{
		if (getRccSaiPllReady())
		{
#if defined(YSS_PERI_REPORT)
			debug_printf("PLL Q(SAI) = %d kHz\n", sai / 1000);
			debug_printf("PLL R(TFT LCD) = %d kHz\n", lcd / 1000);
			debug_printf("장치 설정 완료.\n");
#endif
			gLcdPllFreq = lcd;
			gSaiPllFreq = sai;
			return true;
		}
	}

#if defined(YSS_PERI_REPORT)
	debug_printf("장치 설정 실패.\n");
	debug_printf("활성화 대기 시간을 초과했습니다.\n");
#endif

error:
	gLcdPllFreq = 0;
	gSaiPllFreq = 0;
	return false;
}
*/
}

#endif
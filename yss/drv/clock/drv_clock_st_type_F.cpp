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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || \
    defined(STM32L496xx) || defined(STM32L4A6xx)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
//#include <drv/clock/drv_st_clock_type_C_register.h>
//#include <drv/clock/drv_st_power_type_C_register.h>

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
	if(range < 1 || 2 < range)
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
	switch(getVosRange())
	{
	case 1 : // RANGE1
		maxHse = ec::clock::hse::RANGE1_HSE_MAX_FREQ;
		break;
	case 2 : // RANGE2
		maxHse = ec::clock::hse::RANGE2_HSE_MAX_FREQ;
		break;
	default :
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
	
	if(useOsc)
	{
		RCC->CR |= RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk;	
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 완료.\n");
#endif
		return true;
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

bool Mainpll::enable(unsigned char src, unsigned int vcoMhz, unsigned char pDiv, unsigned char qDiv, unsigned char rDiv)
{
    signed int vco, pll, pll48, n, clk, buf, m = -1, reg, min, max;
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

	switch(range)
	{
	case 1 :
		min = RANGE1_VCO_MIN_FREQ;
		max = RANGE1_VCO_MAX_FREQ;
		break;
	case 2 :
		min = RANGE2_VCO_MIN_FREQ;
		max = RANGE2_VCO_MAX_FREQ;
		break;
	default :
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
    if(RCC->CR & RCC_CR_PLLRDY_Msk == true)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("장치가 이미 활성화되어 있습니다.\n");
#endif
        goto error;
    }

	for(int i=N_MIN;i<=N_MAX;i++)
	{
		buf = vco / i;
		if((vco % i == 0) && (buf >= INPUT_MIN_FREQ) && (buf <= INPUT_MAX_FREQ))
		{
			n = i;
			m = vco / clk / n;
			break;
		}
	}
	
	if(m <= 0)
	{
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("N, M 계산에 실패 했습니다.\n");
#endif
		goto error;
	}

	m--;

    using namespace ec::clock::pll;
    if (m > M_MAX)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("계산 값 M이 허용 범위를 초과했습니다. 입력 소스의 클럭이 정확한지 확인해주세요. %d(user) < %d(max).\n", m, M_MAX);
#endif
        goto error;
    }

    if (N_MIN > n || n > N_MAX)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("계산 값 N이 허용 범위를 초과했습니다. 인자 vcoMhz의 값을 확인해주세요. %d(min) < %d(user) < %d(max).\n", N_MIN, n, N_MAX);
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

    pll = vco / pDiv;

    using namespace ec::clock;

	switch(range)
	{
	case 1 :
		max = sysclk::RANGE1_MAX_FREQ;
		break;
	case 2 :
		max = sysclk::RANGE2_MAX_FREQ;
		break;
	}

    if (pll > max)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("Main PLL의 설정 주파수가 허용 범위를 초과했습니다. %d kHz(user) < %d kHz(max).\n", pll / 1000, max / 1000);
#endif
        goto error;
    }

/*
    pll48 = vco / qDiv;
    if (pll48 > pll::USB48_MAX_FREQ)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("Main PLL의 48MHz 출력 설정 주파수가 허용 범위를 초과했습니다. %d kHz(user) < %d kHz(max).\n", pll48 / 1000, pll::USB48_MAX_FREQ / 1000);
#endif
        goto error;
    }

    setRccMainPllSrc(src);
    setRccMainPllm(m);
    setRccMainPlln(n);
    setRccMainPllp(pDiv);
    setRccMainPllq(qDiv);

    setRccMainPllOn(true);

    for (unsigned short i = 0; i < 10000; i++)
    {
        if (getRccMainPllReady())
        {
#if defined(YSS_PERI_REPORT)
            debug_printf("PLL P(SYSCLK) = %d kHz\n", pll / 1000);
            debug_printf("PLL Q(PLL48CK) = %d kHz\n", pll48 / 1000);
            debug_printf("장치 설정 완료.\n");
#endif

            gPllFreq = pll;
            return true;
        }
    }
*/
#if defined(YSS_PERI_REPORT)
    debug_printf("장치 설정 실패.\n");
    debug_printf("활성화 대기 시간을 초과했습니다.\n");
#endif
error:
    gPllFreq = 0;
    return false;
}

/*
bool Clock::setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2, unsigned char vcc)
{
    unsigned long clk, ahbClk, apb1Clk, apb2Clk, adcClk;

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
        if (getRccHseReady() == false)
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
        if (getRccMainPllReady() == false)
        {
#if defined(YSS_PERI_REPORT)
            debug_printf("장치 설정 실패.\n");
            debug_printf("PLL이 현재 동작중이 아닙니다. 먼저 PLL을 활성화 해주세요.\n");
#endif
            return false;
        }
        clk = gPllFreq;
        break;
    default:
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("지정된 클럭 소스가 유효하지 않습니다.\n");
#endif
        return false;
    }

    ahbClk = clk / gHpreDiv[ahb];
    if (ahbClk > ec::clock::sysclk::MAX_FREQ)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("Sysclk 주파수가 허용 범위를 초과했습니다. %d(user) < %d(max).\n", ahbClk, ec::clock::sysclk::MAX_FREQ);
#endif
        return false;
    }

    apb1Clk = ahbClk / gPpreDiv[apb1];
    if (apb1Clk > ec::clock::apb1::MAX_FREQ)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("APB1 주파수가 허용 범위를 초과했습니다. %d(user) < %d(max).\n", apb1Clk, ec::clock::apb1::MAX_FREQ);
#endif
        return false;
    }

    apb2Clk = ahbClk / gPpreDiv[apb2];
    if (apb2Clk > ec::clock::apb2::MAX_FREQ)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("APB2 주파수가 허용 범위를 초과했습니다. %d(user) < %d(max).\n", apb2Clk, ec::clock::apb2::MAX_FREQ);
        return false;
#endif
    }

    if (ahbClk > ec::clock::sysclk::OVER_DRIVE_FREQ)
    {
        setRccPwrEn(true);
        setPwrOverdriveEn(true);
        while (!getPwrOverdriveReady())
            ;
        setPwrOverdriveSwitchEn(true);
        while (!getPwrOverdriveSwitchReady())
            ;
#if defined(YSS_PERI_REPORT)
        debug_printf("오버 드라이브 모드가 활성화 됐습니다.\n");
#endif
    }

    setRccHpre(ahb);
    setRccPpre1(apb1);
    setRccPpre2(apb2);

    flash.setLatency(ahbClk, vcc);
    setRccSysclkSw(sysclkSrc);

#if defined(YSS_PERI_REPORT)
    debug_printf("Sysclk = %d kHz\n", ahbClk / 1000);
    debug_printf("APB1 = %d kHz\n", apb1Clk / 1000);
    debug_printf("APB2 = %d kHz\n", apb2Clk / 1000);
    debug_printf("장치 설정 완료.\n");
#endif

    return true;
}

unsigned long Clock::getSysClkFreq(void)
{
    unsigned long clk;

    switch (getRccSysclkSw())
    {
    case define::clock::sysclk::src::HSI:
        clk = ec::clock::hsi::FREQ;
        break;
    case define::clock::sysclk::src::HSE:
        clk = gHseFreq;
        break;
    case define::clock::sysclk::src::PLL:
        clk = gPllFreq;
        break;
    }

    clk /= gHpreDiv[getRccHpre()];

    return clk;
}

unsigned long Clock::getApb1ClkFreq(void)
{
    return (unsigned long)(getSysClkFreq() / gPpreDiv[getRccPpre1()]);
}

unsigned long Clock::getApb2ClkFreq(void)
{
    return (unsigned long)(getSysClkFreq() / gPpreDiv[getRccPpre2()]);
}

unsigned long Clock::getTimerApb1ClkFreq(void)
{
    unsigned char pre = getRccPpre1();
    unsigned long clk = getSysClkFreq() / gPpreDiv[pre];
    if (gPpreDiv[pre] > 1)
        clk <<= 1;
    return clk;
}

unsigned long Clock::getTimerApb2ClkFreq(void)
{
    unsigned char pre = getRccPpre2();
    unsigned long clk = getSysClkFreq() / gPpreDiv[pre];
    if (gPpreDiv[pre] > 1)
        clk <<= 1;
    return clk;
}

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
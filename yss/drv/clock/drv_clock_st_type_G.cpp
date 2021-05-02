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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.04.22 ~ 현재
//  부담당자 :
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/mcu.h>

#if defined(STM32F0)

#if defined(STM32F030x6) || defined(STM32F030x8) || \
    defined(STM32F031x6) || defined(STM32F038xx)
//    defined (STM32F042x6) || defined (STM32F048xx) || \
//    defined (STM32F051x8) || defined (STM32F058xx) || \

#define SMALL_DEVICE

#endif

#include <__cross_studio_io.h>
#include <drv/clock/drv_st_clock_type_G.h>

namespace drv
{
unsigned char gHseFreq __attribute__((section(".non_init")));
unsigned int gPllFreq __attribute__((section(".non_init")));

static const unsigned int gPpreDiv[8] = {1, 1, 1, 1, 2, 4, 8, 16};
static const unsigned int gHpreDiv[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

bool Clock::enableHse(unsigned char hseMhz)
{
    unsigned int hse = (unsigned int)hseMhz * 1000000;
    gHseFreq = hseMhz;

#if defined(YSS_PERI_REPORT)
    debug_printf("\n########## HSE 장치 설정 ##########\n\n");
    debug_printf("외부 크리스탈 클럭 = %d MHz\n", hseMhz);
#endif

    if (hse < ec::clock::hse::HSE_MIN_FREQ && ec::clock::hse::HSE_MAX_FREQ < hse)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("HSE 클럭이 입력 허용 범위를 초과했습니다. %d kHz(min) < %d kHz(user) < %d kHz(max).\n", ec::clock::hse::HSE_MIN_FREQ / 1000, hse / 1000, ec::clock::hse::HSE_MAX_FREQ / 1000);
#endif
        return false;
    }

    RCC->CR |= RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk;

    for (unsigned int i = 0; i < 10000; i++)
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

bool Mainpll::enable(unsigned char src, unsigned char mul, unsigned char div)
{
    register unsigned int pll, vco, reg;

#if defined(YSS_PERI_REPORT)
    debug_printf("\n########## Main PLL 장치 설정 ##########\n\n");
#endif

    using namespace define::clock::sysclk;
    if (((RCC->CFGR & RCC_CFGR_SWS_Msk) >> RCC_CFGR_SWS_Pos) == src::PLL)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("장치가 이미 활성화되어 시스템 클럭으로 설정되어 있습니다.\n");
#endif
        goto error;
    }

    using namespace ec::clock::pll;
    if (src > PLL_SRC_MAX)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("클럭 소스의 선택 범위를 초과했습니다.\n");
#endif
        goto error;
    }

    if (mul > PLL_MUL_MAX)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("인자 mul의 설정이 허용 범위를 초과했습니다. %d(user) < %d(max).\n", mul, PLL_MUL_MAX);
#endif
        goto error;
    }

    if (src == define::clock::pll::src::HSE)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("클럭 소스 = HSE 외부 크리스탈\n");
#endif
        if (RCC->CR & RCC_CR_HSERDY_Msk)
            vco = (unsigned long)gHseFreq * 1000000;
        else
        {
#if defined(YSS_PERI_REPORT)
            debug_printf("장치 설정 실패.\n");
            debug_printf("HSE 클럭이 활성화되지 않았습니다.\n");
#endif
            goto error;
        }

#if defined(SMALL_DEVICE)
        vco /= (div + 1);
#endif
    }
    else
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("클럭 소스 = HSI 내부 RC 8MHz\n");
#endif
#if defined(SMALL_DEVICE)
        vco = ec::clock::hsi::FREQ / 2;
#else
        vco = ec::clock::hsi::FREQ;
#endif
    }

    if (vco < PLL_IN_MIN_FREQ || PLL_IN_MAX_FREQ < vco)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("Main PLL의 입력 주파수가 허용 범위를 벗어났습니다. %d(min) < %d(user) < %d(max).\n", PLL_IN_MIN_FREQ, pll, PLL_IN_MAX_FREQ);
#endif
        goto error;
    }

    vco *= mul;
    if (VCO_MAX_FREQ < vco)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("Main PLL의 vco 설정 주파수가 허용 범위를 벗어났습니다. %d(user) < %d(max).\n", vco, VCO_MAX_FREQ);
#endif
        goto error;
    }

    pll = vco / (div + 1);
    if (pll < PLL_OUT_MIN_FREQ || PLL_OUT_MAX_FREQ < pll)
    {
#if defined(YSS_PERI_REPORT)
        debug_printf("장치 설정 실패.\n");
        debug_printf("Main PLL의 설정 주파수가 허용 범위를 벗어났습니다. %d(min) < %d(user) < %d(max).\n", PLL_OUT_MIN_FREQ, pll, PLL_OUT_MAX_FREQ);
#endif
        goto error;
    }

    reg = RCC->CFGR;
    reg = (reg & ~(RCC_CFGR_PLLSRC_Msk | RCC_CFGR_PLLMUL_Msk)) | ((src << RCC_CFGR_PLLSRC_Pos) | ((mul-2) << RCC_CFGR_PLLMUL_Pos));
    RCC->CFGR = reg;

    reg = RCC->CFGR2;
    reg = (reg & ~(RCC_CFGR2_PREDIV_Msk)) | (div << RCC_CFGR2_PREDIV_Pos);
    RCC->CFGR2 = reg;

    RCC->CR |= RCC_CR_PLLON_Msk;

    for (unsigned short i = 0; i < 10000; i++)
    {
        if (RCC->CR & RCC_CR_PLLRDY_Msk)
        {
#if defined(YSS_PERI_REPORT)
            debug_printf("PLL = %d kHz\n", pll / 1000);
            debug_printf("장치 설정 완료.\n");
#endif
            gPllFreq = pll;
            return true;
        }
    }

#if defined(YSS_PERI_REPORT)
    debug_printf("장치 설정 실패.\n");
    debug_printf("활성화 대기 시간을 초과했습니다.\n");
#endif

error:
    gPllFreq = 0;
    return false;
}

void Clock::setLatency(unsigned int freq)
{
	if (freq > 24000000)
		FLASH->ACR |= 1 << FLASH_ACR_LATENCY_Pos;
	else
		FLASH->ACR &= ~(1 << FLASH_ACR_LATENCY_Pos);
}

bool Clock::setSysclk(unsigned char sysclkSrc, unsigned char ahb, unsigned char apb1, unsigned char apb2)
{
    unsigned int clk, ahbClk, apb1Clk, apb2Clk, reg;

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
#endif
        return false;
    }

    setLatency(ahbClk);
    reg = RCC->CFGR;
    reg = (reg & ~RCC_CFGR_SW_Msk) | (sysclkSrc << RCC_CFGR_SW_Pos);
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

    using namespace define::clock::sysclk::src;
    switch ((RCC->CFGR & RCC_CFGR_SWS_Msk) >> RCC_CFGR_SWS_Pos)
    {
    case HSI:
        clk = ec::clock::hsi::FREQ;
        break;
    case HSE:
        clk = gHseFreq * 1000000;
        break;
    case PLL:
        clk = gPllFreq;
        break;
    }

    clk /= gHpreDiv[(RCC->CFGR & RCC_CFGR_HPRE_Msk) >> RCC_CFGR_HPRE_Pos];

    return clk;
}

unsigned int Clock::getApb1ClkFreq(void)
{
    return getSysClkFreq() / gPpreDiv[(RCC->CFGR & RCC_CFGR_PPRE_Msk) >> RCC_CFGR_PPRE_Pos];
}

unsigned int Clock::getApb2ClkFreq(void)
{
    return getSysClkFreq() / gPpreDiv[(RCC->CFGR & RCC_CFGR_PPRE_Msk) >> RCC_CFGR_PPRE_Pos];
}

unsigned int Clock::getTimerApb1ClkFreq(void)
{
    unsigned int div = gPpreDiv[(RCC->CFGR & RCC_CFGR_PPRE_Msk) >> RCC_CFGR_PPRE_Pos];
    unsigned int clk = getSysClkFreq() / div;
    if (div > 1)
        clk <<= 1;
    return clk;
}

unsigned int Clock::getTimerApb2ClkFreq(void)
{
    unsigned int div = gPpreDiv[(RCC->CFGR & RCC_CFGR_PPRE_Msk) >> RCC_CFGR_PPRE_Pos];
    unsigned int clk = getSysClkFreq() / div;
    if (div > 1)
        clk <<= 1;
    return clk;
}

/*
bool Clock::enableHsi(bool div, bool en)
{
#if defined(YSS_PERI_REPORT)
    debug_printf("\n########## HSI 장치 설정 ##########\n\n");
    if (div)
        debug_printf("내부 클럭 = %d MHz\n", ec::clock::hsi::FREQ / 4000000);
    else
        debug_printf("내부 클럭 = %d MHz\n", ec::clock::hsi::FREQ / 1000000);
#endif

    if (div)
        RCC->CR |= RCC_CR_HSIDIVEN_Msk;
    else
        RCC->CR &= ~RCC_CR_HSIDIVEN_Msk;

    if (en)
        RCC->CR |= RCC_CR_HSION_Msk;
    else
        RCC->CR &= ~RCC_CR_HSION_Msk;

    for (unsigned int i = 0; i < 10000; i++)
    {
        if (RCC->CR & RCC_CR_HSIRDY_Msk)
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


bool Clock::setVosRange(unsigned char range)
{
    unsigned int reg;

    if (~RCC->APB1ENR & RCC_APB1ENR_PWREN_Msk)
        RCC->APB1ENR |= RCC_APB1ENR_PWREN_Msk;
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    while (PWR->CSR & PWR_CSR_VOSF_Msk)
        ;
    reg = PWR->CR;
    reg = (reg & ~PWR_CR_VOS_Msk) | (range << PWR_CR_VOS_Pos);
    PWR->CR = reg;
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    while (PWR->CSR & PWR_CSR_VOSF_Msk)
        ;

    return true;
}




*/
}

#endif
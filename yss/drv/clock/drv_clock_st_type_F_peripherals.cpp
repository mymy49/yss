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

namespace drv
{
// ################################### AHB2ENR 시작 ########################################
#if defined(GPIOA)
void Peripheral::setGpioAEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOAEN_Msk;
}

void Peripheral::resetGpioA(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOARST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOARST_Msk;
}
#endif

#if defined(GPIOB)
void Peripheral::setGpioBEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOBEN_Msk;
}

void Peripheral::resetGpioB(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOBRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOBRST_Msk;
}
#endif

#if defined(GPIOC)
void Peripheral::setGpioCEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOCEN_Msk;
}

void Peripheral::resetGpioC(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOCRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOCRST_Msk;
}
#endif

#if defined(GPIOD)
void Peripheral::setGpioDEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIODEN_Msk;
}

void Peripheral::resetGpioD(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIODRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIODRST_Msk;
}
#endif

#if defined(GPIOE)
void Peripheral::setGpioEEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOEEN_Msk;
}

void Peripheral::resetGpioE(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOERST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOERST_Msk;
}
#endif

#if defined(GPIOF)
void Peripheral::setGpioFEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOFEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOFEN_Msk;
}

void Peripheral::resetGpioF(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOFRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOFRST_Msk;
}
#endif

#if defined(GPIOG)
void Peripheral::setGpioGEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOGEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOGEN_Msk;
}

void Peripheral::resetGpioG(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOGRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOGRST_Msk;
}
#endif

#if defined(GPIOH)
void Peripheral::setGpioHEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOHEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOHEN_Msk;
}

void Peripheral::resetGpioH(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOHRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOHRST_Msk;
}
#endif

#if defined(GPIOI)
void Peripheral::setGpioIEn(bool en)
{
    if (en)
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOIEN_Msk;
    else
        RCC->AHB2ENR &= ~RCC_AHB2ENR_GPIOIEN_Msk;
}

void Peripheral::resetGpioI(void)
{
    RCC->AHB2RSTR |= RCC_AHB2RSTR_GPIOIRST_Msk;
    RCC->AHB2RSTR &= ~RCC_AHB2RSTR_GPIOIRST_Msk;
}
#endif

// ################################### AHB2ENR 끝 ########################################

// ################################### APB1ENR1 시작 ########################################

#if defined(TIM2)
void Peripheral::setTimer2En(bool en)
{
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM2EN_Msk;
}

void Peripheral::resetTimer2(void)
{
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM2RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM2RST_Msk;
}
#endif

#if defined(TIM3)
void Peripheral::setTimer3En(bool en)
{
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM3EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM3EN_Msk;
}

void Peripheral::resetTimer3(void)
{
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM3RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM3RST_Msk;
}
#endif

#if defined(TIM4)
void Peripheral::setTimer4En(bool en)
{
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM4EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM4EN_Msk;
}

void Peripheral::resetTimer4(void)
{
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM4RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM4RST_Msk;
}
#endif

#if defined(TIM5)
void Peripheral::setTimer5En(bool en)
{
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM5EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM5EN_Msk;
}

void Peripheral::resetTimer5(void)
{
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM5RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM5RST_Msk;
}
#endif

#if defined(TIM6)
void Peripheral::setTimer6En(bool en)
{
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM6EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM6EN_Msk;
}

void Peripheral::resetTimer6(void)
{
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM6RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM6RST_Msk;
}
#endif

#if defined(TIM7)
void Peripheral::setTimer7En(bool en)
{
    if (en)
        RCC->APB1ENR1 |= RCC_APB1ENR1_TIM7EN_Msk;
    else
        RCC->APB1ENR1 &= ~RCC_APB1ENR1_TIM7EN_Msk;
}

void Peripheral::resetTimer7(void)
{
    RCC->APB1RSTR1 |= RCC_APB1RSTR1_TIM7RST_Msk;
    RCC->APB1RSTR1 &= ~RCC_APB1RSTR1_TIM7RST_Msk;
}
#endif

// ################################### APB1ENR1 끝 ########################################

// ################################### APB2ENR 시작 ########################################

#if defined(SYSCFG)
void Peripheral::setSyscfgEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGEN_Msk;
}

void Peripheral::resetSyscfg(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_SYSCFGRST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_SYSCFGRST_Msk;
}
#endif

#if defined(TIM1)
void Peripheral::setTimer1En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM1EN_Msk;
}

void Peripheral::resetTimer1(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM1RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST_Msk;
}
#endif

#if defined(TIM8)
void Peripheral::setTimer8En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM8EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM8EN_Msk;
}

void Peripheral::resetTimer8(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM8RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM8RST_Msk;
}
#endif

#if defined(TIM15)
void Peripheral::setTimer15En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM15EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM15EN_Msk;
}

void Peripheral::resetTimer15(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM15RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM15RST_Msk;
}
#endif

#if defined(TIM16)
void Peripheral::setTimer16En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM16EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM16EN_Msk;
}

void Peripheral::resetTimer16(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM16RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM16RST_Msk;
}
#endif

#if defined(TIM17)
void Peripheral::setTimer17En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM17EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM17EN_Msk;
}

void Peripheral::resetTimer17(void)
{
    RCC->APB2RSTR |= RCC_APB2RSTR_TIM17RST_Msk;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM17RST_Msk;
}
#endif

// ################################### APB2ENR 시작 ########################################

}

#endif
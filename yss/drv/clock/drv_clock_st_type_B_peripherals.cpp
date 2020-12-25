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

#if defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <drv/clock/drv_st_clock_type_B_register.h>
#include <drv/clock/drv_st_power_type_B_register.h>

namespace drv
{
// ################################### AHBENR 시작 ########################################

#if defined(DMA1)
void Peripheral::setDmaEn(bool en)
{
    if (en)
        RCC->AHBENR |= RCC_AHBENR_DMA1EN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_DMA1EN_Msk;
#if defined(DMA2)
    if (en)
        RCC->AHBENR |= RCC_AHBENR_DMA2EN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_DMA2EN_Msk;
#endif
}
#endif

void Peripheral::setSramEn(bool en)
{
    if (en)
        RCC->AHBENR |= RCC_AHBENR_SRAMEN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_SRAMEN_Msk;
}

void Peripheral::setFlitfEn(bool en)
{
    if (en)
        RCC->AHBENR |= RCC_AHBENR_FLITFEN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_FLITFEN_Msk;
}

#if defined(CRC)
void Peripheral::setCrcEn(bool en)
{
    if (en)
        RCC->AHBENR |= RCC_AHBENR_CRCEN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_CRCEN_Msk;
}
#endif

#if defined(FSMC_Bank1)
void Peripheral::setFsmcEn(bool en)
{
    if (en)
        RCC->AHBENR |= RCC_AHBENR_FSMCEN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_FSMCEN_Msk;
}
#endif

#if defined(SDIO)
void Peripheral::setSdioEn(bool en)
{
    if (en)
        RCC->AHBENR |= RCC_AHBENR_SDIOEN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_SDIOEN_Msk;
}
#endif

// ################################### AHBENR 끝 ########################################

// ################################### APB1ENR 시작 ########################################

#if defined(TIM2)
void Peripheral::setTimer2En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN_Msk;
}

void Peripheral::resetTimer2(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM2RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM2RST_Msk;
}
#endif

#if defined(TIM3)
void Peripheral::setTimer3En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM3EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM3EN_Msk;
}

void Peripheral::resetTimer3(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM3RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM3RST_Msk;
}
#endif

#if defined(TIM4)
void Peripheral::setTimer4En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM4EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM4EN_Msk;
}

void Peripheral::resetTimer4(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM4RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM4RST_Msk;
}
#endif

#if defined(TIM5)
void Peripheral::setTimer5En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM5EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM5EN_Msk;
}

void Peripheral::resetTimer5(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM5RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM5RST_Msk;
}
#endif

#if defined(TIM6)
void Peripheral::setTimer6En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM6EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM6EN_Msk;
}

void Peripheral::resetTimer6(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM6RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM6RST_Msk;
}
#endif

#if defined(TIM7)
void Peripheral::setTimer7En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM7EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM7EN_Msk;
}

void Peripheral::resetTimer2(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM7RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM7RST_Msk;
}
#endif

#if defined(TIM12)
void Peripheral::setTimer12En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM12EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM12EN_Msk;
}

void Peripheral::resetTimer12(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM12RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM12RST_Msk;
}
#endif

#if defined(TIM13)
void Peripheral::setTimer13En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM13EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM13EN_Msk;
}

void Peripheral::resetTimer13(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM13RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM13RST_Msk;
}
#endif

#if defined(TIM14)
void Peripheral::setTimer14En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM14EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM14EN_Msk;
}

void Peripheral::resetTimer14(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM14RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM14RST_Msk;
}
#endif

#if defined(WWDG)
void Peripheral::setWwdgEn(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_WWDGEN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_WWDGEN_Msk;
}

void Peripheral::resetWwdg(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_WWDGRST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_WWDGRST_Msk;
}
#endif

#if defined(SPI2)
void Peripheral::setSpi2En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_SPI2EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_SPI2EN_Msk;
}

void Peripheral::resetSpi2(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_SPI2RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI2RST_Msk;
}
#endif

#if defined(SPI3)
void Peripheral::setSpi3En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_SPI3EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_SPI3EN_Msk;
}

void Peripheral::resetSpi3(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_SPI3RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI3RST_Msk;
}
#endif

#if defined(USART2)
void Peripheral::setUart2En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN_Msk;
}

void Peripheral::resetUart2(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST_Msk;
}
#endif

#if defined(USART3)
void Peripheral::setUart3En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_USART3EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_USART3EN_Msk;
}

void Peripheral::resetUart3(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST_Msk;
}
#endif

#if defined(UART4)
void Peripheral::setUart4En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_UART4EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_UART4EN_Msk;
}

void Peripheral::resetUart4(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_UART4RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_UART4RST_Msk;
}
#endif

#if defined(UART5)
void Peripheral::setUart5En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_UART5EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_UART5EN_Msk;
}

void Peripheral::resetUart5(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_UART5RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_UART5RST_Msk;
}
#endif

#if defined(I2C1)
void Peripheral::setI2c1En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_I2C1EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_I2C1EN_Msk;
}

void Peripheral::resetI2c1(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_I2C1RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C1RST_Msk;
}
#endif

#if defined(I2C2)
void Peripheral::setI2c2En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_I2C2EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_I2C2EN_Msk;
}

void Peripheral::resetI2c2(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_I2C2RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C2RST_Msk;
}
#endif

#if defined(USB)
void Peripheral::setUsbEn(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_USBEN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_USBEN_Msk;
}

void Peripheral::resetUsb(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_USBRST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USBRST_Msk;
}
#endif

#if defined(CAN1)
void Peripheral::setCan1En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_CAN1EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_CAN1EN_Msk;
}

void Peripheral::resetCan1(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_CAN1RST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN1RST_Msk;
}
#endif

#if defined(BKP)
void Peripheral::setBkpEn(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_BKPEN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_BKPEN_Msk;
}

void Peripheral::resetBkp(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_BKPRST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_BKPRST_Msk;
}
#endif

#if defined(PWR)
void Peripheral::setPwrEn(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_PWREN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_PWREN_Msk;
}

void Peripheral::resetPwr(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_PWRRST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_PWRRST_Msk;
}
#endif

#if defined(DAC)
void Peripheral::setDacEn(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_DACEN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_DACEN_Msk;
}

void Peripheral::resetDac(void)
{
    RCC->APB1RSTR |= RCC_APB1RSTR_DACRST_Msk;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_DACRST_Msk;
}
#endif

// ################################### APB1ENR 끝 ########################################

#if defined(AFIO)
void Peripheral::setAfioEn(bool en)
{
    setRccAfioEn(en);
}
#endif

#if defined(GPIOA)
void Peripheral::setGpioAEn(bool en)
{
    setRccGpioAEn(en);
}
#endif

#if defined(GPIOB)
void Peripheral::setGpioBEn(bool en)
{
    setRccGpioBEn(en);
}
#endif

#if defined(GPIOC)
void Peripheral::setGpioCEn(bool en)
{
    setRccGpioCEn(en);
}
#endif

#if defined(GPIOD)
void Peripheral::setGpioDEn(bool en)
{
    setRccGpioDEn(en);
}
#endif

#if defined(GPIOE)
void Peripheral::setGpioEEn(bool en)
{
    setRccGpioEEn(en);
}
#endif

#if defined(GPIOF)
void Peripheral::setGpioFEn(bool en)
{
    setRccGpioFEn(en);
}
#endif

#if defined(GPIOG)
void Peripheral::setGpioGEn(bool en)
{
    setRccGpioGEn(en);
}
#endif

#if defined(TIM1)
void Peripheral::setTimer1En(bool en)
{
    setRccTim1En(en);
}
#endif

#if defined(TIM8)
void Peripheral::setTimer8En(bool en)
{
    setRccTim8En(en);
}
#endif

#if defined(TIM9)
void Peripheral::setTimer9En(bool en)
{
    setRccTim9En(en);
}
#endif

#if defined(TIM10)
void Peripheral::setTimer10En(bool en)
{
    setRccTim10En(en);
}
#endif

#if defined(TIM11)
void Peripheral::setTimer11En(bool en)
{
    setRccTim11En(en);
}
#endif

#if defined(USART1)
void Peripheral::setUart1En(bool en)
{
    setRccUsart1En(en);
}
#endif

#if defined(ADC1)
void Peripheral::setAdc1En(bool en)
{
    setRccAdc1En(en);
}
#endif

#if defined(ADC2)
void Peripheral::setAdc2En(bool en)
{
    setRccAdc2En(en);
}
#endif

#if defined(CAN2)
void Peripheral::setCan2En(bool en)
{
    setRccCan2En(en);
}

void Peripheral::resetCan2(void)
{
    resetRccCan2(true);
    resetRccCan2(false);
}
#endif

#if defined(SPI1)
void Peripheral::setSpi1En(bool en)
{
    setRccSpi1En(en);
}
#endif

}

#endif
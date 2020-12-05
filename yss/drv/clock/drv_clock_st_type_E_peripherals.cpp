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

#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

#include <__cross_studio_io.h>

#include <drv/clock/drv_st_clock_type_B_register.h>
#include <drv/clock/drv_st_power_type_B_register.h>
#include <drv/peripherals.h>

namespace drv
{
#if defined(GPIOA)
void Peripheral::setGpioAEn(bool en)
{
    if (en)
        RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
    else
        RCC->IOPENR &= ~RCC_IOPENR_GPIOAEN;
}
#endif

#if defined(GPIOB)
void Peripheral::setGpioBEn(bool en)
{
    if (en)
        RCC->IOPENR |= RCC_IOPENR_GPIOBEN;
    else
        RCC->IOPENR &= ~RCC_IOPENR_GPIOBEN;
}
#endif

#if defined(GPIOC)
void Peripheral::setGpioCEn(bool en)
{
    if (en)
        RCC->IOPENR |= RCC_IOPENR_GPIOCEN;
    else
        RCC->IOPENR &= ~RCC_IOPENR_GPIOCEN;
}
#endif

#if defined(GPIOD)
void Peripheral::setGpioDEn(bool en)
{
    if (en)
        RCC->IOPENR |= RCC_IOPENR_GPIODEN;
    else
        RCC->IOPENR &= ~RCC_IOPENR_GPIODEN;
}
#endif

#if defined(GPIOE)
void Peripheral::setGpioEEn(bool en)
{
    if (en)
        RCC->IOPENR |= RCC_IOPENR_GPIOEEN;
    else
        RCC->IOPENR &= ~RCC_IOPENR_GPIOEEN;
}
#endif

#if defined(GPIOH)
void Peripheral::setGpioHEn(bool en)
{
    if (en)
        RCC->IOPENR |= RCC_IOPENR_GPIOHEN;
    else
        RCC->IOPENR &= ~RCC_IOPENR_GPIOHEN;
}
#endif

#if defined(TIM2)
void Peripheral::setTimer2En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN_Msk;
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
#endif

#if defined(TIM6)
void Peripheral::setTimer6En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_TIM6EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_TIM6EN_Msk;
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
#endif

#if defined(TIM21)
void Peripheral::setTimer21En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM21EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM21EN_Msk;
}
#endif

#if defined(TIM22)
void Peripheral::setTimer22En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_TIM22EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_TIM22EN_Msk;
}
#endif

#if defined(DMA1)
void Peripheral::setDmaEn(bool en)
{
    if (en)
        RCC->AHBENR |= RCC_AHBENR_DMAEN_Msk;
    else
        RCC->AHBENR &= ~RCC_AHBENR_DMAEN_Msk;
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

#if defined(USART1)
void Peripheral::setUart1En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_USART1EN_Msk;
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
#endif

#if defined(USART4)
void Peripheral::setUart4En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_USART4EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_USART4EN_Msk;
}
#endif

#if defined(USART5)
void Peripheral::setUart5En(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_USART5EN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_USART5EN_Msk;
}
#endif

#if defined(ADC1)
void Peripheral::setAdc1En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_ADCEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_ADCEN_Msk;
}
#endif

#if defined(SPI1)
void Peripheral::setSpi1En(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SPI1EN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SPI1EN_Msk;
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
#endif

#if defined(DAC)
void Peripheral::setDacEn(bool en)
{
    if (en)
        RCC->APB1ENR |= RCC_APB1ENR_DACEN_Msk;
    else
        RCC->APB1ENR &= ~RCC_APB1ENR_DACEN_Msk;
}
#endif

#if defined(SYSCFG)
void Peripheral::setSyscfgEn(bool en)
{
    if (en)
        RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN_Msk;
    else
        RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGEN_Msk;
}
#endif

}

#endif
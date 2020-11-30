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

#if defined(TIM2)
void Peripheral::setTimer2En(bool en)
{
    setRccTim2En(en);
}
#endif

#if defined(TIM3)
void Peripheral::setTimer3En(bool en)
{
    setRccTim3En(en);
}
#endif

#if defined(TIM4)
void Peripheral::setTimer4En(bool en)
{
    setRccTim4En(en);
}
#endif

#if defined(TIM5)
void Peripheral::setTimer5En(bool en)
{
    setRccTim5En(en);
}
#endif

#if defined(TIM6)
void Peripheral::setTimer6En(bool en)
{
    setRccTim6En(en);
}
#endif

#if defined(TIM7)
void Peripheral::setTimer7En(bool en)
{
    setRccTim7En(en);
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

#if defined(TIM12)
void Peripheral::setTimer12En(bool en)
{
    setRccTim12En(en);
}
#endif

#if defined(TIM13)
void Peripheral::setTimer13En(bool en)
{
    setRccTim13En(en);
}
#endif

#if defined(TIM14)
void Peripheral::setTimer14En(bool en)
{
    setRccTim14En(en);
}
#endif

#if defined(DMA1)
void Peripheral::setDmaEn(bool en)
{
    setRccDma1En(en);
#if defined(DMA2)
    setRccDma2En(en);
#endif
}
#endif

#if defined(I2C1)
void Peripheral::setI2c1En(bool en)
{
    setRccI2c1En(en);
}

void Peripheral::resetI2c1(void)
{
    resetRccI2c1(true);
    resetRccI2c1(false);
}
#endif

#if defined(I2C2)
void Peripheral::setI2c2En(bool en)
{
    setRccI2c2En(en);
}

void Peripheral::resetI2c2(void)
{
    resetRccI2c2(true);
    resetRccI2c2(false);
}
#endif

#if defined(USART1)
void Peripheral::setUart1En(bool en)
{
    setRccUsart1En(en);
}
#endif

#if defined(USART2)
void Peripheral::setUart2En(bool en)
{
    setRccUsart2En(en);
}
#endif

#if defined(USART3)
void Peripheral::setUart3En(bool en)
{
    setRccUsart3En(en);
}
#endif

#if defined(UART4)
void Peripheral::setUart4En(bool en)
{
    setRccUart4En(en);
}
#endif

#if defined(UART5)
void Peripheral::setUart5En(bool en)
{
    setRccUart5En(en);
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

#if defined(CAN1)
void Peripheral::setCan1En(bool en)
{
    setRccCan1En(en);
}

void Peripheral::resetCan1(void)
{
    resetRccCan1(true);
    resetRccCan1(false);
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

#if defined(SPI2)
void Peripheral::setSpi2En(bool en)
{
    setRccSpi2En(en);
}
#endif

#if defined(SPI3)
void Peripheral::setSpi3En(bool en)
{
    setRccSpi3En(en);
}
#endif

#if defined(DAC)
void Peripheral::setDacEn(bool en)
{
    setRccDacEn(en);
}
#endif
}

#endif
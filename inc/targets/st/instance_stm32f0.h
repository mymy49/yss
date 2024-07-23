/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE_STM32F0__H_
#define YSS_INSTANCE_STM32F0__H_

#include <drv/peripheral.h>

#if defined(ADC1)
extern Adc adc1;
#endif

#if defined(ADC2)
extern Adc adc2;
#endif

#if defined(ADC3)
extern Adc adc3;
#endif

#if defined(RCC)
extern Clock clock;
#endif

#if defined(DMA1_Channel1)
extern DmaChannel1 dmaChannel1;
#endif

#if defined(DMA1_Channel2)
extern DmaChannel2 dmaChannel2;
#endif

#if defined(DMA1_Channel3)
extern DmaChannel3 dmaChannel3;
#endif

#if defined(DMA1_Channel4)
extern DmaChannel4 dmaChannel4;
#endif

#if defined(DMA1_Channel5)
extern DmaChannel5 dmaChannel5;
#endif

#if defined(EXTI)
extern Exti exti;
#endif

#if defined(FLASH)
extern Flash flash;
#endif

#if defined(GPIOA)
extern Gpio gpioA;
#endif

#if defined(GPIOB)
extern Gpio gpioB;
#endif

#if defined(GPIOC)
extern Gpio gpioC;
#endif

#if defined(GPIOD)
extern Gpio gpioD;
#endif

#if defined(GPIOE)
extern Gpio gpioE;
#endif

#if defined(GPIOF)
extern Gpio gpioF;
#endif

#if defined(GPIOG)
extern Gpio gpioG;
#endif

#if defined(GPIOH)
extern Gpio gpioH;
#endif

#if defined(I2C1)
extern I2c i2c1;
#endif

#if defined(I2C2)
extern I2c i2c2;
#endif

#if defined(I2C3)
extern I2c i2c3;
#endif

#if defined(SPI1)
extern Spi spi1;
#endif

#if defined(SPI2)
extern Spi spi2;
#endif

#if defined(SPI3)
extern Spi spi3;
#endif

#if defined(SPI4)
extern Spi spi4;
#endif

#if defined(TIM1)
extern Timer timer1;
#endif

#if defined(TIM2)
extern Timer timer2;
#endif

#if defined(TIM3)
extern Timer timer3;
#endif

#if defined(TIM4)
extern Timer timer4;
#endif

#if defined(TIM5)
extern Timer timer5;
#endif

#if defined(TIM6)
extern Timer timer6;
#endif

#if defined(TIM7)
extern Timer timer7;
#endif

#if defined(TIM8)
extern Timer timer8;
#endif

#if defined(TIM9)
extern Timer timer9;
#endif

#if defined(TIM10)
extern Timer timer10;
#endif

#if defined(TIM11)
extern Timer timer11;
#endif

#if defined(TIM12)
extern Timer timer12;
#endif

#if defined(TIM13)
extern Timer timer13;
#endif

#if defined(TIM14)
extern Timer timer14;
#endif

#if defined(USART1)
extern Usart usart1;
#endif

#if defined(USART2)
extern Usart usart2;
#endif

#if defined(USART3)
extern Usart usart3;
#endif

#if defined(USART4)
extern Usart usart4;
#endif

#if defined(USART5)
extern Usart usart5;
#endif

#if defined(USART6)
extern Usart usart6;
#endif

#endif


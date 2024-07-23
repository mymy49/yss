/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE_STM32G4__H_
#define YSS_INSTANCE_STM32G4__H_

#include <drv/peripheral.h>

#if defined(RCC)
extern Clock clock;
#endif

extern DmaChannel1 dmaChannel1;
extern DmaChannel2 dmaChannel2;
extern DmaChannel3 dmaChannel3;
extern DmaChannel4 dmaChannel4;
extern DmaChannel5 dmaChannel5;
extern DmaChannel6 dmaChannel6;
extern DmaChannel7 dmaChannel7;
extern DmaChannel8 dmaChannel8;
extern DmaChannel9 dmaChannel9;
extern DmaChannel10 dmaChannel10;
extern DmaChannel11 dmaChannel11;
extern DmaChannel12 dmaChannel12;
#if defined(STM32G431xx)
#define DMA_COUNT			12
#elif defined(STM32G474xx)
#define DMA_COUNT			16
extern DmaChannel13 dmaChannel13;
extern DmaChannel14 dmaChannel14;
extern DmaChannel15 dmaChannel15;
extern DmaChannel16 dmaChannel16;
#endif
extern Dma *dmaChannelList[DMA_COUNT];

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

#if defined(SPI2)
extern I2s i2s2;
#endif

#if defined(SPI3)
extern I2s i2s3;
#endif

#if defined(TIM1)
extern PwmCh1 pwm1Ch1;
extern PwmCh2 pwm1Ch2;
extern PwmCh3 pwm1Ch3;
extern PwmCh4 pwm1Ch4;
#endif

#if defined(TIM2)
extern PwmCh1 pwm2Ch1;
extern PwmCh2 pwm2Ch2;
extern PwmCh3 pwm2Ch3;
extern PwmCh4 pwm2Ch4;
#endif

#if defined(TIM3)
extern PwmCh1 pwm3Ch1;
extern PwmCh2 pwm3Ch2;
extern PwmCh3 pwm3Ch3;
extern PwmCh4 pwm3Ch4;
#endif

#if defined(TIM4)
extern PwmCh1 pwm4Ch1;
extern PwmCh2 pwm4Ch2;
extern PwmCh3 pwm4Ch3;
extern PwmCh4 pwm4Ch4;
#endif

#if defined(TIM5)
extern PwmCh1 pwm5Ch1;
extern PwmCh2 pwm5Ch2;
extern PwmCh3 pwm5Ch3;
extern PwmCh4 pwm5Ch4;
#endif

#if defined(TIM8)
extern PwmCh1 pwm8Ch1;
extern PwmCh2 pwm8Ch2;
extern PwmCh3 pwm8Ch3;
extern PwmCh4 pwm8Ch4;
#endif

#if defined(TIM15)
extern PwmCh1 pwm15Ch1;
extern PwmCh2 pwm15Ch2;
#endif

#if defined(TIM16)
extern PwmCh1 pwm16Ch1;
#endif

#if defined(TIM17)
extern PwmCh1 pwm17Ch1;
#endif

#if defined(TIM20)
extern PwmCh1 pwm20Ch1;
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

#if defined(TIM15)
extern Timer timer15;
#endif

#if defined(TIM16)
extern Timer timer16;
#endif

#if defined(TIM17)
extern Timer timer17;
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

#if defined(UART4)
extern Uart uart4;
#endif

#if defined(UART5)
extern Uart uart5;
#endif

#endif


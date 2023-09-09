////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

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
extern I2s i2s1;
#endif

#if defined(SPI2)
extern I2s i2s2;
#endif

#if defined(SPI3)
extern I2s i2s3;
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


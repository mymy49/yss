////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_INSTANCE_STM32F446__H_
#define YSS_INSTANCE_STM32F446__H_

#include <drv/peripheral.h>

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

#if defined(FLASH)
	extern Flash flash;
#endif

#if defined(DMA1_Stream0)
	extern DmaChannel1 dmaChannel1;
#endif

#if defined(DMA1_Stream1)
	extern DmaChannel2 dmaChannel2;
#endif

#if defined(DMA1_Stream2)
	extern DmaChannel3 dmaChannel3;
#endif

#if defined(DMA1_Stream3)
	extern DmaChannel4 dmaChannel4;
#endif

#if defined(DMA1_Stream4)
	extern DmaChannel5 dmaChannel5;
#endif

#if defined(DMA1_Stream5)
	extern DmaChannel6 dmaChannel6;
#endif

#if defined(DMA1_Stream6)
	extern DmaChannel7 dmaChannel7;
#endif

#if defined(DMA1_Stream7)
	extern DmaChannel8 dmaChannel8;
#endif

#if defined(DMA2_Stream0)
	extern DmaChannel9 dmaChannel9;
#endif

#if defined(DMA2_Stream1)
	extern DmaChannel10 dmaChannel10;
#endif

#if defined(DMA2_Stream2)
	extern DmaChannel11 dmaChannel11;
#endif

#if defined(DMA2_Stream3)
	extern DmaChannel12 dmaChannel12;
#endif

#if defined(DMA2_Stream4)
	extern DmaChannel13 dmaChannel13;
#endif

#if defined(DMA2_Stream5)
	extern DmaChannel14 dmaChannel14;
#endif

#if defined(DMA2_Stream6)
	extern DmaChannel15 dmaChannel15;
#endif

#if defined(DMA2_Stream7)
	extern DmaChannel16 dmaChannel16;
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

#if defined(USART1)
	extern Uart uart1;
#endif

#if defined(USART2)
	extern Uart uart2;
#endif

#if defined(USART3)
	extern Uart uart3;
#endif

#if defined(UART4)
	extern Uart uart4;
#endif

#if defined(UART5)
	extern Uart uart5;
#endif

#if defined(USART6)
	extern Uart uart6;
#endif

#if defined(ADC1)
extern Adc adc1;
#endif

#if defined(ADC2)
extern Adc adc2;
#endif

#if defined(ADC3)
extern Adc adc3;
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

#if defined(SAI1)
extern Sai sai1A;
extern Sai sai1B;
#endif

#if defined(SAI2)
extern Sai sai2A;
extern Sai sai2B;
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

#if defined(SPI5)
extern Spi spi5;
#endif

#if defined(LTDC)
extern Ltdc ltdc;
#endif

#if defined(DMA2D)
extern Dma2d dma2d;
#endif

#if defined(FMC_Bank5_6)
extern Sdram sdram;
#endif

#endif


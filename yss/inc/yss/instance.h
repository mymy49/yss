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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.02.06 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_INSTANCE__H_
#define YSS_INSTANCE__H_

#include <drv/peripheral.h>

#include <drv/Adc.h>
#include <drv/Can.h>
#include <drv/Clock.h>
#include <drv/Dac.h>
#include <drv/Dma.h>
#include <drv/Exti.h>
#include <drv/Flash.h>
#include <drv/Nvic.h>
#include <drv/Gpio.h>
#include <drv/I2c.h>
#include <drv/Rtc.h>
#include <drv/Spi.h>
#include <drv/Timer.h>
#include <drv/Uart.h>
#include <drv/Usbd.h>
#include <drv/Wdog.h>


// ADC
#if defined(ADC1) || defined(ADC)
extern drv::Adc adc1;
#endif

#if defined(ADC2)
extern drv::Adc adc2;
#endif

#if defined(ADC3)
extern drv::Adc adc3;
#endif


// CAN
#if defined(CAN1) || defined(FDCAN1)
extern drv::Can can1;
#endif

#if defined(CAN2) || defined(FDCAN2)
extern drv::Can can2;
#endif


// CLOCK
extern drv::Clock clock;


// DAC
#if defined(DAC) || defined(DAC1)
extern drv::Dac dac1;
#endif


// DMA
#if defined(DMA1)
extern drv::Dma dma;
#endif

#if defined(DMA1_Stream0)
extern drv::Stream	dma1Stream0;
#endif

#if defined(DMA1_Stream1) || defined(DMA1_Channel1)
extern drv::Stream	dma1Stream1;
#endif

#if defined(DMA1_Stream2) || defined(DMA1_Channel2)
extern drv::Stream	dma1Stream2;
#endif

#if defined(DMA1_Stream3) || defined(DMA1_Channel3)
extern drv::Stream	dma1Stream3;
#endif

#if defined(DMA1_Stream4) || defined(DMA1_Channel4)
extern drv::Stream	dma1Stream4;
#endif

#if defined(DMA1_Stream5) || defined(DMA1_Channel5)
extern drv::Stream	dma1Stream5;
#endif

#if defined(DMA1_Stream6) || defined(DMA1_Channel6)
extern drv::Stream	dma1Stream6;
#endif

#if defined(DMA1_Stream7) || defined(DMA1_Channel7)
extern drv::Stream	dma1Stream7;
#endif

#if defined(DMA2_Stream0)
extern drv::Stream	dma2Stream0;
#endif

#if defined(DMA2_Stream1) || defined(DMA2_Channel1)
extern drv::Stream	dma2Stream1;
#endif

#if defined(DMA2_Stream2) || defined(DMA2_Channel2)
extern drv::Stream	dma2Stream2;
#endif

#if defined(DMA2_Stream3) || defined(DMA2_Channel3)
extern drv::Stream	dma2Stream3;
#endif

#if defined(DMA2_Stream4) || defined(DMA2_Channel4)
extern drv::Stream	dma2Stream4;
#endif

#if defined(DMA2_Stream5) || defined(DMA2_Channel5)
extern drv::Stream	dma2Stream5;
#endif

#if defined(DMA2_Stream6) || defined(DMA2_Channel6)
extern drv::Stream	dma2Stream6;
#endif

#if defined(DMA2_Stream7) || defined(DMA2_Channel7)
extern drv::Stream	dma2Stream7;
#endif

#if defined(EXTI) || defined(EIC)
extern drv::Exti exti;
#endif

#if defined(FLASH)
extern drv::Flash flash;
#endif

#if defined(GPIOA) || defined(PORT_PA00)
extern drv::Gpio gpioA;
#endif

#if defined(GPIOB) || defined(PORT_PB00)
extern drv::Gpio gpioB;
#endif

#if defined(GPIOC)
extern drv::Gpio gpioC;
#endif

#if defined(GPIOD)
extern drv::Gpio gpioD;
#endif

#if defined(GPIOE)
extern drv::Gpio gpioE;
#endif

#if defined(GPIOF)
extern drv::Gpio gpioF;
#endif

#if defined(GPIOG)
extern drv::Gpio gpioG;
#endif

#if defined(GPIOH)
extern drv::Gpio gpioH;
#endif

#if defined(GPIOI)
extern drv::Gpio gpioI;
#endif

#if defined(GPIOJ)
extern drv::Gpio gpioJ;
#endif

#if defined(GPIOK)
extern drv::Gpio gpioK;
#endif

#if defined(I2C1)
extern drv::I2c i2c1;
#endif

#if defined(I2C2)
extern drv::I2c i2c2;
#endif

#if defined(I2C3)
extern drv::I2c i2c3;
#endif

#if defined(I2C4)
extern drv::I2c i2c4;
#endif

#if defined(NVIC)
extern drv::Nvic nvic;
#endif

#if defined(RTC)
extern drv::Rtc rtc;
#endif


#if defined(SPI1)
extern drv::Spi spi1;
#endif

#if defined(SPI2)
extern drv::Spi spi2;
#endif

#if defined(SPI3)
extern drv::Spi spi3;
#endif

#if defined(SPI4)
extern drv::Spi spi4;
#endif

#if defined(SPI5)
extern drv::Spi spi5;
#endif

#if defined(SPI6)
extern drv::Spi spi6;
#endif


#if defined(TIM1)
extern drv::Timer timer1;
#endif

#if defined(TIM2)
extern drv::Timer timer2;
#endif

#if defined(TIM3)
extern drv::Timer timer3;
#endif

#if defined(TIM4)
extern drv::Timer timer4;
#endif

#if defined(TIM5)
extern drv::Timer timer5;
#endif

#if defined(TIM6)
extern drv::Timer timer6;
#endif

#if defined(TIM7)
extern drv::Timer timer7;
#endif

#if defined(TIM8)
extern drv::Timer timer8;
#endif

#if defined(TIM9)
extern drv::Timer timer9;
#endif

#if defined(TIM10)
extern drv::Timer timer10;
#endif

#if defined(TIM11)
extern drv::Timer timer11;
#endif

#if defined(TIM12)
extern drv::Timer timer12;
#endif

#if defined(TIM13)
extern drv::Timer timer13;
#endif

#if defined(TIM14)
extern drv::Timer timer14;
#endif

#if defined(TIM15)
extern drv::Timer timer15;
#endif

#if defined(TIM16)
extern drv::Timer timer16;
#endif

#if defined(TIM17)
extern drv::Timer timer17;
#endif


#if defined(USART1)
extern drv::Uart uart1;
#endif

#if defined(USART2)
extern drv::Uart uart2;
#endif

#if defined(USART3)
extern drv::Uart uart3;
#endif

#if defined(UART4)
extern drv::Uart uart4;
#endif

#if defined(UART5)
extern drv::Uart uart5;
#endif

#if defined(UsART6)
extern drv::Uart uart6;
#endif

#if defined(UART7)
extern drv::Uart uart7;
#endif

#if defined(UART8)
extern drv::Uart uart8;
#endif

#if defined(USB)
extern drv::Usbd usbd;
#endif

#if defined(IWDG)
extern drv::Wdog wdog;
#endif

#include <instance/instance_dma2d.h>
#include <instance/instance_ltdc.h>
#include <instance/instance_sdmmc.h>
#include <instance/instance_sdram.h>
#include <instance/instance_syscfg.h>

#endif


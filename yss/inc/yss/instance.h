////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_INSTANCE__H_
#define YSS_INSTANCE__H_

#include <drv/peripheral.h>

#include <drv/Adc.h>
#include <drv/Can.h>
#include <drv/Capture.h>
#include <drv/Clock.h>
#include <drv/Dac.h>
#include <drv/Dma.h>
#include <drv/Dma2d.h>
#include <drv/Exti.h>
#include <drv/Flash.h>
#include <drv/Ltdc.h>
#include <drv/Pwm.h>
#include <drv/Quadspi.h>
#include <drv/Nvic.h>
#include <drv/Gpio.h>
#include <drv/I2c.h>
#include <drv/Rtc.h>
#include <drv/Sdram.h>
#include <drv/Sdmmc.h>
#include <drv/Sai.h>
#include <drv/Spi.h>
#include <drv/Syscfg.h>
#include <drv/Timer.h>
#include <drv/Uart.h>
#include <drv/Usbd.h>
#include <drv/Wdog.h>


// ADC
#ifndef YSS_DRV_ADC_UNSUPPORTED
#if defined(ADC1) || defined(ADC)
extern drv::Adc adc1;
#endif

#if defined(ADC2)
extern drv::Adc adc2;
#endif

#if defined(ADC3)
extern drv::Adc adc3;
#endif
#endif

// CAN
#ifndef YSS_DRV_CAN_UNSUPPORTED
#if defined(CAN1) || defined(FDCAN1)
extern drv::Can can1;
#endif

#if defined(CAN2) || defined(FDCAN2)
extern drv::Can can2;
#endif
#endif

// CLOCK
#ifndef YSS_DRV_CLOCK_UNSUPPORTED
extern drv::Clock clock;
#endif

// DAC
#ifndef YSS_DRV_DAC_UNSUPPORTED
#if defined(DAC) || defined(DAC1)
extern drv::Dac dac1;
#endif
#endif


// DMA
#ifndef YSS_DRV_DMA_UNSUPPORTED
#if defined(DMA1)
//extern drv::Dma dma;
#endif

#if defined(DMA1_Stream0) || defined(DMA1_Channel1) || defined(DMA1_CHANNEL1)
extern drv::DmaChannel1 dmaChannel1;
extern drv::Stream	dma1Stream0;
#endif

#if defined(DMA1_Stream1) || defined(DMA1_Channel2) || defined(DMA1_CHANNEL2)
extern drv::DmaChannel2 dmaChannel2;
extern drv::Stream	dma1Stream1;
#endif

#if defined(DMA1_Stream2) || defined(DMA1_Channel3) || defined(DMA1_CHANNEL3)
extern drv::DmaChannel3 dmaChannel3;
extern drv::Stream	dma1Stream2;
#endif

#if defined(DMA1_Stream3) || defined(DMA1_Channel4) || defined(DMA1_CHANNEL4)
extern drv::DmaChannel4 dmaChannel4;
extern drv::Stream	dma1Stream3;
#endif

#if defined(DMA1_Stream4) || defined(DMA1_Channel5) || defined(DMA1_CHANNEL5)
extern drv::DmaChannel5 dmaChannel5;
extern drv::Stream	dma1Stream4;
#endif

#if defined(DMA1_Stream5) || defined(DMA1_Channel6) || defined(DMA1_CHANNEL6)
extern drv::DmaChannel6 dmaChannel6;
extern drv::Stream	dma1Stream5;
#endif

#if defined(DMA1_Stream6) || defined(DMA1_Channel7) || defined(DMA1_CHANNEL7)
extern drv::DmaChannel7 dmaChannel7;
extern drv::Stream	dma1Stream6;
#endif

#if defined(DMA1_Stream7) || defined(DMA2_Channel1) || defined(DMA2_CHANNEL1)
extern drv::DmaChannel8 dmaChannel8;
extern drv::Stream	dma1Stream7;
#endif

#if defined(DMA2_Stream0) || defined(DMA2_Channel2) || defined(DMA2_CHANNEL2)
extern drv::DmaChannel9 dmaChannel9;
extern drv::Stream	dma2Stream0;
#endif

#if defined(DMA2_Stream1) || defined(DMA2_Channel3) || defined(DMA2_CHANNEL3)
extern drv::DmaChannel10 dmaChannel10;
extern drv::Stream	dma2Stream1;
#endif

#if defined(DMA2_Stream2) || defined(DMA2_Channel4) || defined(DMA2_CHANNEL4)
extern drv::DmaChannel11 dmaChannel11;
extern drv::Stream	dma2Stream2;
#endif

#if defined(DMA2_Stream3) || defined(DMA2_Channel5) || defined(DMA2_CHANNEL5)
extern drv::DmaChannel12 dmaChannel12;
extern drv::Stream	dma2Stream3;
#endif

#if defined(DMA2_Stream4) || defined(DMA2_Channel6) || defined(DMA2_CHANNEL6)
extern drv::DmaChannel13 dmaChannel13;
extern drv::Stream	dma2Stream4;
#endif

#if defined(DMA2_Stream5) || defined(DMA2_Channel7) || defined(DMA2_CHANNEL7)
extern drv::DmaChannel14 dmaChannel14;
extern drv::Stream	dma2Stream5;
#endif

#if defined(DMA2_Stream6)
extern drv::DmaChannel15 dmaChannel15;
extern drv::Stream	dma2Stream6;
#endif

#if defined(DMA2_Stream7)
extern drv::DmaChannel16 dmaChannel16;
extern drv::Stream	dma2Stream7;
#endif
#endif


#ifndef YSS_DRV_DMA2D_UNSUPPORTED
#if USE_GUI == true && defined(DMA2D)
extern drv::Dma2d dma2d;
#endif
#endif


#ifndef YSS_DRV_EXTI_UNSUPPORTED
#if defined(EXTI) || defined(EIC)
extern drv::Exti exti;
#endif
#endif


#ifndef YSS_DRV_FLASH_UNSUPPORTED
#if defined(FLASH) || defined (FMC)
extern drv::Flash flash;
#endif
#endif


#ifndef YSS_DRV_LTDC_UNSUPPORTED
#if defined(LTDC)
extern drv::Ltdc ltdc;
#endif
#endif


#ifndef YSS_DRV_QUADSPI_UNSUPPORTED
#if defined(QUADSPI)
extern drv::Quadspi quadspi;
#endif
#endif

#ifndef YSS_DRV_GPIO_UNSUPPORTED
#if defined(GPIOA) || defined(PORT_PA00) || defined(NRF_P0)
extern drv::Gpio gpioA;
#endif

#if defined(GPIOB) || defined(PORT_PB00) || defined(NRF_P1)
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
#endif


#ifndef YSS_DRV_I2C_UNSUPPORTED
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
#endif

#ifndef YSS_DRV_NVIC_UNSUPPORTED
#if defined(NVIC)
extern drv::Nvic nvic;
#endif
#endif


#ifndef YSS_DRV_RTC_UNSUPPORTED
#if defined(RTC)
extern drv::Rtc rtc;
#endif
#endif


#ifndef YSS_DRV_SDRAM_UNSUPPORTED
#if defined(FMC_Bank5_6)
extern drv::Sdram sdram;
#endif
#endif

#ifndef YSS_DRV_SDMMC_UNSUPPORTED
#if defined(SDMMC1) || defined(SDIO)
extern drv::Sdmmc sdmmc;
#endif
#endif


#ifndef YSS_DRV_SAI_UNSUPPORTED
#if defined(SAI1)
extern drv::Sai sai1;
#endif

#if defined(SAI2)
extern drv::Sai sai2;
#endif
#endif


#ifndef YSS_DRV_SPI_UNSUPPORTED
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
#endif


#ifndef YSS_DRV_SYSCFG_UNSUPPORTED
#if defined(SYSCFG)
extern drv::Syscfg syscfg;
#endif
#endif


#ifndef YSS_DRV_TIMER_UNSUPPORTED
#if defined(NRF_TIMER0)
extern drv::Timer timer0;
#endif

#if defined(TIM1) || defined(TIMER1) || defined(NRF_TIMER1)
extern drv::Timer timer1;
#endif

#if defined(TIM2) || defined(TIMER2) || defined(NRF_TIMER2)
extern drv::Timer timer2;
#endif

#if defined(TIM3) || defined(TIMER3) || defined(NRF_TIMER3)
extern drv::Timer timer3;
#endif

#if defined(TIM4) || defined(TIMER4) || defined(NRF_TIMER4)
extern drv::Timer timer4;
#endif

#if defined(TIM5) || defined(TIMER5)
extern drv::Timer timer5;
#endif

#if defined(TIM6) || defined(TIMER6)
extern drv::Timer timer6;
#endif

#if defined(TIM7) || defined(TIMER7)
extern drv::Timer timer7;
#endif

#if defined(TIM8) || defined(TIMER8)
extern drv::Timer timer8;
#endif

#if defined(TIM9) || defined(TIMER9)
extern drv::Timer timer9;
#endif

#if defined(TIM10) || defined(TIMER10)
extern drv::Timer timer10;
#endif

#if defined(TIM11) || defined(TIMER11)
extern drv::Timer timer11;
#endif

#if defined(TIM12) || defined(TIMER12)
extern drv::Timer timer12;
#endif

#if defined(TIM13) || defined(TIMER13)
extern drv::Timer timer13;
#endif

#if defined(TIM14) || defined(TIMER14)
extern drv::Timer timer14;
#endif

#if defined(TIM15) || defined(TIMER15)
extern drv::Timer timer15;
#endif

#if defined(TIM16) || defined(TIMER16)
extern drv::Timer timer16;
#endif

#if defined(TIM17) || defined(TIMER17)
extern drv::Timer timer17;
#endif
#endif

#if !defined(YSS_DRV_CAPTURE_UNSUPPORTED)

#if defined(GD32F10X_XD) || defined(STM32F1) || defined(GD32F10X_HD)
#if defined(TIM1) || defined(TIMER1)
extern drv::CaptureCh1 capture1Ch1;
extern drv::CaptureCh2 capture1Ch2;
extern drv::CaptureCh3 capture1Ch3;
extern drv::CaptureCh4 capture1Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(STM32F1) || defined(GD32F10X_HD)
#if defined(TIM2) || defined(TIMER2)
extern drv::CaptureCh1 capture2Ch1;
extern drv::CaptureCh2 capture2Ch2;
extern drv::CaptureCh3 capture2Ch3;
extern drv::CaptureCh4 capture2Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM3) || defined(TIMER3)
extern drv::CaptureCh1 capture3Ch1;
extern drv::CaptureCh2 capture3Ch2;
extern drv::CaptureCh3 capture3Ch3;
extern drv::CaptureCh4 capture3Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM4) || defined(TIMER4)
extern drv::CaptureCh1 capture4Ch1;
extern drv::CaptureCh2 capture4Ch2;
extern drv::CaptureCh3 capture4Ch3;
extern drv::CaptureCh4 capture4Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM5) || defined(TIMER5)
extern drv::CaptureCh1 capture5Ch1;
extern drv::CaptureCh2 capture5Ch2;
extern drv::CaptureCh3 capture5Ch3;
extern drv::CaptureCh4 capture5Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM8) || defined(TIMER8)
extern drv::CaptureCh1 capture8Ch1;
extern drv::CaptureCh2 capture8Ch2;
extern drv::CaptureCh3 capture8Ch3;
extern drv::CaptureCh4 capture8Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM9) || defined(TIMER9)
extern drv::CaptureCh1 capture9Ch1;
extern drv::CaptureCh2 capture9Ch2;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM10) || defined(TIMER10)
extern drv::CaptureCh1 capture10Ch1;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM11) || defined(TIMER11)
extern drv::CaptureCh1 capture11Ch1;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM12) || defined(TIMER12)
extern drv::CaptureCh1 capture12Ch1;
extern drv::CaptureCh2 capture12Ch2;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM13) || defined(TIMER13)
extern drv::CaptureCh1 capture13Ch1;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM14) || defined(TIMER14)
extern drv::CaptureCh1 capture14Ch1;
#endif
#endif

#endif


#if !defined(YSS_DRV_PWM_UNSUPPORTED)

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM1) || defined(TIMER1)
extern drv::PwmCh1 pwm1Ch1;
extern drv::PwmCh2 pwm1Ch2;
extern drv::PwmCh3 pwm1Ch3;
extern drv::PwmCh4 pwm1Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM2) || defined(TIMER2)
extern drv::PwmCh1 pwm2Ch1;
extern drv::PwmCh2 pwm2Ch2;
extern drv::PwmCh3 pwm2Ch3;
extern drv::PwmCh4 pwm2Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM3) || defined(TIMER3)
extern drv::PwmCh1 pwm3Ch1;
extern drv::PwmCh2 pwm3Ch2;
extern drv::PwmCh3 pwm3Ch3;
extern drv::PwmCh4 pwm3Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM4) || defined(TIMER4)
extern drv::PwmCh1 pwm4Ch1;
extern drv::PwmCh2 pwm4Ch2;
extern drv::PwmCh3 pwm4Ch3;
extern drv::PwmCh4 pwm4Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM5) || defined(TIMER5)
extern drv::PwmCh1 pwm5Ch1;
extern drv::PwmCh2 pwm5Ch2;
extern drv::PwmCh3 pwm5Ch3;
extern drv::PwmCh4 pwm5Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM8) || defined(TIMER8)
extern drv::PwmCh1 pwm8Ch1;
extern drv::PwmCh2 pwm8Ch2;
extern drv::PwmCh3 pwm8Ch3;
extern drv::PwmCh4 pwm8Ch4;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM9) || defined(TIMER9)
extern drv::PwmCh1 pwm9Ch1;
extern drv::PwmCh2 pwm9Ch2;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM10) || defined(TIMER10)
extern drv::PwmCh1 pwm10Ch1;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM11) || defined(TIMER11)
extern drv::PwmCh1 pwm11Ch1;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM12) || defined(TIMER12)
extern drv::PwmCh1 pwm12Ch1;
extern drv::PwmCh2 pwm12Ch2;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM13) || defined(TIMER13)
extern drv::PwmCh1 pwm13Ch1;
#endif
#endif

#if defined(GD32F10X_XD) || defined(GD32F10X_HD) || defined(STM32F1)
#if defined(TIM14) || defined(TIMER14)
extern drv::PwmCh1 pwm14Ch1;
#endif
#endif

#endif



#ifndef YSS_DRV_UART_UNSUPPORTED
#if defined(USART0)
extern drv::Uart uart0;
#endif

#if defined(USART1)
extern drv::Uart uart1;
#endif

#if defined(USART2)
extern drv::Uart uart2;
#endif

#if defined(USART3) || defined(UART3)
extern drv::Uart uart3;
#endif

#if defined(UART4)
extern drv::Uart uart4;
#endif

#if defined(UART5) || defined(USART5)
extern drv::Uart uart5;
#endif

#if defined(USART6) || defined(UART6)
extern drv::Uart uart6;
#endif

#if defined(UART7)
extern drv::Uart uart7;
#endif

#if defined(UART8)
extern drv::Uart uart8;
#endif
#endif


#ifndef YSS_DRV_USBD_UNSUPPORTED
#if defined(USB)
extern drv::Usbd usbd;
#endif
#endif

#ifndef YSS_DRV_WDOG_UNSUPPORTED
#if defined(IWDG)
extern drv::Wdog wdog;
#endif
#endif

#endif


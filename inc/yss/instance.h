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

#ifndef YSS_INSTANCE__H_
#define YSS_INSTANCE__H_

#include <drv/peripheral.h>
#include <drv/Adc.h>
#include <drv/Sai.h>
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
#include <drv/Spi.h>
#include <drv/Timer.h>
#include <drv/Uart.h>
#include <drv/Usart.h>
#include <drv/Usbd.h>
#include <drv/Wdog.h>
#include <drv/Crc32.h>
#include <drv/I2s.h>
#include <drv/Radio.h>
#include <drv/Pdm.h>
#include <drv/Pbus.h>

// CLOCK
extern Clock clock;

// NVIC
extern Nvic nvic;

// EXTI
#ifndef YSS_DRV_EXTI_UNSUPPORTED
extern Exti exti;
#endif

#if defined(STM32F1) || defined(STM32F0) || defined(STM32F7) || defined(GD32F4) || defined(STM32F4) || defined(NRF52840_XXAA)

// ADC
#ifndef YSS_DRV_ADC_UNSUPPORTED
#if defined(ADC1) || defined(ADC)
extern Adc adc1;
#endif

#if defined(ADC2)
extern Adc adc2;
#endif

#if defined(ADC3)
extern Adc adc3;
#endif
#endif

// CAN
#ifndef YSS_DRV_CAN_UNSUPPORTED
#if defined(CAN1) || defined(FDCAN1)
extern Can can1;
#endif

#if defined(CAN2) || defined(FDCAN2)
extern Can can2;
#endif
#endif


// DAC
#ifndef YSS_DRV_DAC_UNSUPPORTED
#if defined(DAC) || defined(DAC1)
extern Dac dac1;
#endif
#endif


// DMA
#ifndef YSS_DRV_DMA_UNSUPPORTED
#if defined(DMA1)
//extern Dma dma;
#endif

#if defined(DMA1_Stream0) || defined(DMA1_Channel1) || defined(DMA1_CHANNEL1)
extern DmaChannel1 dmaChannel1;
#endif

#if defined(DMA1_Stream1) || defined(DMA1_Channel2) || defined(DMA1_CHANNEL2)
extern DmaChannel2 dmaChannel2;
#endif

#if defined(DMA1_Stream2) || defined(DMA1_Channel3) || defined(DMA1_CHANNEL3)
extern DmaChannel3 dmaChannel3;
#endif

#if defined(DMA1_Stream3) || defined(DMA1_Channel4) || defined(DMA1_CHANNEL4)
extern DmaChannel4 dmaChannel4;
#endif

#if defined(DMA1_Stream4) || defined(DMA1_Channel5) || defined(DMA1_CHANNEL5)
extern DmaChannel5 dmaChannel5;
#endif

#if defined(DMA1_Stream5) || defined(DMA1_Channel6) || defined(DMA1_CHANNEL6)
extern DmaChannel6 dmaChannel6;
#endif

#if defined(DMA1_Stream6) || defined(DMA1_Channel7) || defined(DMA1_CHANNEL7)
extern DmaChannel7 dmaChannel7;
#endif

#if defined(DMA1_Stream7) || defined(DMA2_Channel1) || defined(DMA2_CHANNEL1)
extern DmaChannel8 dmaChannel8;
#endif

#if defined(DMA2_Stream0) || defined(DMA2_Channel2) || defined(DMA2_CHANNEL2)
extern DmaChannel9 dmaChannel9;
#endif

#if defined(DMA2_Stream1) || defined(DMA2_Channel3) || defined(DMA2_CHANNEL3)
extern DmaChannel10 dmaChannel10;
#endif

#if defined(DMA2_Stream2) || defined(DMA2_Channel4) || defined(DMA2_CHANNEL4)
extern DmaChannel11 dmaChannel11;
#endif

#if defined(DMA2_Stream3) || defined(DMA2_Channel5) || defined(DMA2_CHANNEL5)
extern DmaChannel12 dmaChannel12;
#endif

#if defined(DMA2_Stream4) || defined(DMA2_Channel6) || defined(DMA2_CHANNEL6)
extern DmaChannel13 dmaChannel13;
#endif

#if defined(DMA2_Stream5) || defined(DMA2_Channel7) || defined(DMA2_CHANNEL7)
extern DmaChannel14 dmaChannel14;
#endif

#if defined(DMA2_Stream6)
extern DmaChannel15 dmaChannel15;
#endif

#if defined(DMA2_Stream7)
extern DmaChannel16 dmaChannel16;
#endif
#endif


#ifndef YSS_DRV_DMA2D_UNSUPPORTED
#if defined(DMA2D) || defined(IPA)
extern Dma2d dma2d;
#endif
#endif


#ifndef YSS_DRV_EXTI_UNSUPPORTED
extern Exti exti;
#endif


#ifndef YSS_DRV_FLASH_UNSUPPORTED
#if defined(FLASH) || defined (FMC)
extern Flash flash;
#endif
#endif


#ifndef YSS_DRV_LTDC_UNSUPPORTED
#if defined(LTDC) || defined(TLI)
extern Ltdc ltdc;
#endif
#endif


#ifndef YSS_DRV_QUADSPI_UNSUPPORTED
#if defined(QUADSPI)
extern Quadspi quadspi;
#endif
#endif

#ifndef YSS_DRV_GPIO_UNSUPPORTED
#if defined(GPIOA) || defined(PORT_PA00)
extern Gpio gpioA;
#elif defined(NRF_P0)
extern Gpio gpio0;
#endif

#if defined(GPIOB) || defined(PORT_PB00)
extern Gpio gpioB;
#elif defined(NRF_P1)
extern Gpio gpio1;
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

#if defined(GPIOI)
extern Gpio gpioI;
#endif

#if defined(GPIOJ)
extern Gpio gpioJ;
#endif

#if defined(GPIOK)
extern Gpio gpioK;
#endif
#endif


#ifndef YSS_DRV_I2C_UNSUPPORTED
#if defined(I2C1)
extern I2c i2c1;
#endif

#if defined(I2C2)
extern I2c i2c2;
#endif

#if defined(I2C3)
extern I2c i2c3;
#endif

#if defined(I2C4)
extern I2c i2c4;
#endif
#endif

#ifndef YSS_DRV_RTC_UNSUPPORTED
#if defined(RTC)
extern Rtc rtc;
#endif
#endif


#ifndef YSS_DRV_SDRAM_UNSUPPORTED
#if defined(FMC_Bank5_6)
extern Sdram sdram;
#endif
#endif

#ifndef YSS_DRV_SDMMC_UNSUPPORTED
#if defined(SDMMC1) || defined(SDIO)
extern Sdmmc sdmmc;
#endif
#endif


#ifndef YSS_DRV_SAI_UNSUPPORTED
#if defined(SAI1)
extern Sai sai1A;
extern Sai sai1B;
#endif

#if defined(SAI2)
extern Sai sai2A;
extern Sai sai2B;
#endif
#endif


#ifndef YSS_DRV_SPI_UNSUPPORTED
#if defined(SPI0)
extern Spi spi0;
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

#if defined(SPI6)
extern Spi spi6;
#endif
#endif


#ifndef YSS_DRV_TIMER_UNSUPPORTED
#if defined(NRF_TIMER0) || defined(TIMER0)
extern Timer timer0;
#endif

#if defined(TIM1) || defined(TIMER1) || defined(NRF_TIMER1)
extern Timer timer1;
#endif

#if defined(TIM2) || defined(TIMER2) || defined(NRF_TIMER2)
extern Timer timer2;
#endif

#if defined(TIM3) || defined(TIMER3) || defined(NRF_TIMER3)
extern Timer timer3;
#endif

#if defined(TIM4) || defined(TIMER4) || defined(NRF_TIMER4)
extern Timer timer4;
#endif

#if defined(TIM5) || defined(TIMER5)
extern Timer timer5;
#endif

#if defined(TIM6) || defined(TIMER6)
extern Timer timer6;
#endif

#if defined(TIM7) || defined(TIMER7)
extern Timer timer7;
#endif

#if defined(TIM8) || defined(TIMER8)
extern Timer timer8;
#endif

#if defined(TIM9) || defined(TIMER9)
extern Timer timer9;
#endif

#if defined(TIM10) || defined(TIMER10)
extern Timer timer10;
#endif

#if defined(TIM11) || defined(TIMER11)
extern Timer timer11;
#endif

#if defined(TIM12) || defined(TIMER12)
extern Timer timer12;
#endif

#if defined(TIM13) || defined(TIMER13)
extern Timer timer13;
#endif

#if defined(TIM14) || defined(TIMER14)
extern Timer timer14;
#endif

#if defined(TIM15) || defined(TIMER15)
extern Timer timer15;
#endif

#if defined(TIM16) || defined(TIMER16)
extern Timer timer16;
#endif

#if defined(TIM17) || defined(TIMER17)
extern Timer timer17;
#endif
#endif

#if !defined(YSS_DRV_CAPTURE_UNSUPPORTED)

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM1) || defined(TIMER1)
extern CaptureCh1 capture1Ch1;
extern CaptureCh2 capture1Ch2;
extern CaptureCh3 capture1Ch3;
extern CaptureCh4 capture1Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM2) || defined(TIMER2)
extern CaptureCh1 capture2Ch1;
extern CaptureCh2 capture2Ch2;
extern CaptureCh3 capture2Ch3;
extern CaptureCh4 capture2Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM3) || defined(TIMER3)
extern CaptureCh1 capture3Ch1;
extern CaptureCh2 capture3Ch2;
extern CaptureCh3 capture3Ch3;
extern CaptureCh4 capture3Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM4) || defined(TIMER4)
extern CaptureCh1 capture4Ch1;
extern CaptureCh2 capture4Ch2;
extern CaptureCh3 capture4Ch3;
extern CaptureCh4 capture4Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM5) || defined(TIMER5)
extern CaptureCh1 capture5Ch1;
extern CaptureCh2 capture5Ch2;
extern CaptureCh3 capture5Ch3;
extern CaptureCh4 capture5Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM8) || defined(TIMER8)
extern CaptureCh1 capture8Ch1;
extern CaptureCh2 capture8Ch2;
extern CaptureCh3 capture8Ch3;
extern CaptureCh4 capture8Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM9) || defined(TIMER9)
extern CaptureCh1 capture9Ch1;
extern CaptureCh2 capture9Ch2;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM10) || defined(TIMER10)
extern CaptureCh1 capture10Ch1;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM11) || defined(TIMER11)
extern CaptureCh1 capture11Ch1;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM12) || defined(TIMER12)
extern CaptureCh1 capture12Ch1;
extern CaptureCh2 capture12Ch2;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM13) || defined(TIMER13)
extern CaptureCh1 capture13Ch1;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM14) || defined(TIMER14)
extern CaptureCh1 capture14Ch1;
#endif
#endif

#endif


#if !defined(YSS_DRV_PWM_UNSUPPORTED)

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM1) || defined(TIMER1)
extern PwmCh1 pwm1Ch1;
extern PwmCh2 pwm1Ch2;
extern PwmCh3 pwm1Ch3;
extern PwmCh4 pwm1Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM2) || defined(TIMER2)
extern PwmCh1 pwm2Ch1;
extern PwmCh2 pwm2Ch2;
extern PwmCh3 pwm2Ch3;
extern PwmCh4 pwm2Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM3) || defined(TIMER3)
extern PwmCh1 pwm3Ch1;
extern PwmCh2 pwm3Ch2;
extern PwmCh3 pwm3Ch3;
extern PwmCh4 pwm3Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM4) || defined(TIMER4)
extern PwmCh1 pwm4Ch1;
extern PwmCh2 pwm4Ch2;
extern PwmCh3 pwm4Ch3;
extern PwmCh4 pwm4Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM5) || defined(TIMER5)
extern PwmCh1 pwm5Ch1;
extern PwmCh2 pwm5Ch2;
extern PwmCh3 pwm5Ch3;
extern PwmCh4 pwm5Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM8) || defined(TIMER8)
extern PwmCh1 pwm8Ch1;
extern PwmCh2 pwm8Ch2;
extern PwmCh3 pwm8Ch3;
extern PwmCh4 pwm8Ch4;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM9) || defined(TIMER9)
extern PwmCh1 pwm9Ch1;
extern PwmCh2 pwm9Ch2;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM10) || defined(TIMER10)
extern PwmCh1 pwm10Ch1;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM11) || defined(TIMER11)
extern PwmCh1 pwm11Ch1;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM12) || defined(TIMER12)
extern PwmCh1 pwm12Ch1;
extern PwmCh2 pwm12Ch2;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM13) || defined(TIMER13)
extern PwmCh1 pwm13Ch1;
#endif
#endif

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F4)
#if defined(TIM14) || defined(TIMER14)
extern PwmCh1 pwm14Ch1;
#endif
#endif

#endif



#ifndef YSS_DRV_UART_UNSUPPORTED
#if defined(NRF_UART0) || defined(USART0)
extern Uart uart0;
#endif

#if defined(USART1)
extern Uart uart1;
#endif

#if defined(USART2)
extern Uart uart2;
#endif

#if defined(USART3) || defined(UART3)
extern Uart uart3;
#endif

#if defined(UART4) || defined(USART4)
extern Uart uart4;
#endif

#if defined(UART5) || defined(USART5)
extern Uart uart5;
#endif

#if defined(USART6) || defined(UART6)
extern Uart uart6;
#endif

#if defined(UART7)
extern Uart uart7;
#endif

#if defined(UART8)
extern Uart uart8;
#endif
#endif


#ifndef YSS_DRV_USBD_UNSUPPORTED
//#if defined(USB)
//extern Usbd usbd;
//#endif
#endif

#ifndef YSS_DRV_WDOG_UNSUPPORTED
#if defined(IWDG)
extern Wdog wdog;
#endif
#endif

#ifndef YSS_DRV_CRC32_UNSUPPORTED
#if defined(CRC)
extern Crc32 crc32;
#endif
#endif

#ifndef YSS_DRV_I2S_UNSUPPORTED
#if defined(I2S1)
extern I2s i2s1;
#endif

#if defined(I2S2)
extern I2s i2s2;
#endif

#if defined(I2S3)
extern I2s i2s3;
#endif
#endif

#if !defined(YSS_DRV_RADIO_UNSUPPORTED)
#if defined(NRF_RADIO)
extern Radio radio;
#endif
#endif

#elif defined(STM32F446xx)

#include <targets/st/instance_stm32f446xx.h>

#elif defined(STM32F429xx)

#include <targets/st/instance_stm32f429xx.h>

#elif defined(STM32F767xx)

#include <targets/st/instance_stm32f767xx.h>

#elif defined(STM32F746xx)

#include <targets/st/instance_stm32f746xx.h>

#elif defined(EFM32PG22)

#include <targets/siliconlabs/instance_efm32pg22.h>

#elif defined(STM32F1_N) || defined(GD32F1)

#include <targets/st/instance_stm32f103xx.h>

#elif defined(STM32F0_N)

#include <targets/st/instance_stm32f030xx.h>

#elif defined(EFR32BG22)

#include <targets/siliconlabs/instance_efr32bg22.h>

#endif

#endif


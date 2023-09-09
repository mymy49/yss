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

#ifndef YSS_INSTANCE_STM32F103__H_
#define YSS_INSTANCE_STM32F103__H_

#include <drv/peripheral.h>

#if defined(RCC)
extern Clock clock;
#endif

#if defined(EXTI)
extern Exti exti;
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

#if defined(TIM9)
extern PwmCh1 pwm9Ch1;
extern PwmCh2 pwm9Ch2;
#endif

#if defined(TIM10)
extern PwmCh1 pwm10Ch1;
#endif

#if defined(TIM11)
extern PwmCh1 pwm11Ch1;
#endif

#if defined(TIM12)
extern PwmCh1 pwm12Ch1;
extern PwmCh2 pwm12Ch2;
#endif

#if defined(TIM13)
extern PwmCh1 pwm13Ch1;
#endif

#if defined(TIM14)
extern PwmCh1 pwm14Ch1;
#endif

#if defined(TIM1)
extern CaptureCh1 capture1Ch1;
extern CaptureCh2 capture1Ch2;
extern CaptureCh3 capture1Ch3;
extern CaptureCh4 capture1Ch4;
#endif

#if defined(TIM2)
extern CaptureCh1 capture2Ch1;
extern CaptureCh2 capture2Ch2;
extern CaptureCh3 capture2Ch3;
extern CaptureCh4 capture2Ch4;
#endif

#if defined(TIM3)
extern CaptureCh1 capture3Ch1;
extern CaptureCh2 capture3Ch2;
extern CaptureCh3 capture3Ch3;
extern CaptureCh4 capture3Ch4;
#endif

#if defined(TIM4)
extern CaptureCh1 capture4Ch1;
extern CaptureCh2 capture4Ch2;
extern CaptureCh3 capture4Ch3;
extern CaptureCh4 capture4Ch4;
#endif

#if defined(TIM5)
extern CaptureCh1 capture5Ch1;
extern CaptureCh2 capture5Ch2;
extern CaptureCh3 capture5Ch3;
extern CaptureCh4 capture5Ch4;
#endif

#if defined(TIM8)
extern CaptureCh1 capture8Ch1;
extern CaptureCh2 capture8Ch2;
extern CaptureCh3 capture8Ch3;
extern CaptureCh4 capture8Ch4;
#endif

#if defined(TIM9)
extern CaptureCh1 capture9Ch1;
extern CaptureCh2 capture9Ch2;
#endif

#if defined(TIM10)
extern CaptureCh1 capture10Ch1;
#endif

#if defined(TIM11)
extern CaptureCh1 capture11Ch1;
#endif

#if defined(TIM12)
extern CaptureCh1 capture12Ch1;
extern CaptureCh2 capture12Ch2;
#endif

#if defined(TIM13)
extern CaptureCh1 capture13Ch1;
#endif

#if defined(TIM14)
extern CaptureCh1 capture14Ch1;
#endif

#if defined(FLASH)
	extern Flash flash;
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

#if defined(DMA1_Channel6)
	extern DmaChannel6 dmaChannel6;
#endif

#if defined(DMA1_Channel7)
	extern DmaChannel7 dmaChannel7;
#endif

#if defined(DMA2_Channel1)
	extern DmaChannel8 dmaChannel8;
#endif

#if defined(DMA2_Channel2)
	extern DmaChannel9 dmaChannel9;
#endif

#if defined(DMA2_Channel3)
	extern DmaChannel10 dmaChannel10;
#endif

#if defined(DMA2_Channel4)
	extern DmaChannel11 dmaChannel11;
#endif

#if defined(DMA2_Channel5)
	extern DmaChannel12 dmaChannel12;
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

#if defined(ADC1)
extern Adc adc1;
#endif

#if defined(ADC2)
extern Adc adc2;
#endif

#if defined(ADC3)
extern Adc adc3;
#endif

#if defined(CAN1)
extern Can can1;
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


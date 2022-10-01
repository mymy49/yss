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

#ifndef YSS_DRV_NVIC__H_
#define YSS_DRV_NVIC__H_

#include "peripheral.h"

#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || \
	defined(STM32L4) || defined(STM32L0) || defined(STM32F0) || \
	defined(__SAM_L_FAMILY) || \
	defined(GD32F1) || \
	defined(NRF52840_XXAA)
#elif defined(GD32F4)

#include <drv/dma/define_dma_gd32f4.h>

#else
#define YSS_DRV_NVIC_NOT_SUPPORT
#endif

#include <drv/Drv.h>

class Nvic : public Drv
{
  public:
	Nvic(void (*clockFunc)(bool en), void (*nvicFunc)(bool en));
	void enableInterrupt(IRQn_Type position, bool en);

#if defined(DMA1_Stream0) || defined(DMA1_Channel1) || defined(DMA1_CHANNEL1)
#define YSS_NVIC_DMA_CHANNEL_1
	void setDmaChannel1En(bool en);
#endif
#if defined(DMA1_Stream1) || defined(DMA1_Channel2) || defined(DMA1_CHANNEL2)
#define YSS_NVIC_DMA_CHANNEL_2
	void setDmaChannel2En(bool en);
#endif
#if defined(DMA1_Stream2) || defined(DMA1_Channel3) || defined(DMA1_CHANNEL3)
#define YSS_NVIC_DMA_CHANNEL_3
	void setDmaChannel3En(bool en);
#endif
#if defined(DMA1_Stream3) || defined(DMA1_Channel4) || defined(DMA1_CHANNEL4)
#define YSS_NVIC_DMA_CHANNEL_4
	void setDmaChannel4En(bool en);
#endif
#if defined(DMA1_Stream4) || defined(DMA1_Channel5) || defined(DMA1_CHANNEL5)
#define YSS_NVIC_DMA_CHANNEL_5
	void setDmaChannel5En(bool en);
#endif
#if defined(DMA1_Stream5) || defined(DMA1_Channel6) || defined(DMA1_CHANNEL6)
#define YSS_NVIC_DMA_CHANNEL_6
	void setDmaChannel6En(bool en);
#endif
#if defined(DMA1_Stream6) || defined(DMA1_Channel7) || defined(DMA1_CHANNEL7)
#define YSS_NVIC_DMA_CHANNEL_7
	void setDmaChannel7En(bool en);
#endif
#if defined(DMA1_Stream7) || defined(DMA2_Channel1) || defined(DMA2_CHANNEL1)
#define YSS_NVIC_DMA_CHANNEL_8
	void setDmaChannel8En(bool en);
#endif

#if defined(DMA2_Stream0) || defined(DMA2_Channel2) || defined(DMA2_CHANNEL2)
#define YSS_NVIC_DMA_CHANNEL_9
	void setDmaChannel9En(bool en);
#endif
#if defined(DMA2_Stream1) || defined(DMA2_Channel3) || defined(DMA2_CHANNEL3)
#define YSS_NVIC_DMA_CHANNEL_10
	void setDmaChannel10En(bool en);
#endif
#if defined(DMA2_Stream2) || defined(DMA2_Channel4) || defined(DMA2_CHANNEL4)
#define YSS_NVIC_DMA_CHANNEL_11
	void setDmaChannel11En(bool en);
#endif
#if defined(DMA2_Stream3) || defined(DMA2_Channel5) || defined(DMA2_CHANNEL5)
#define YSS_NVIC_DMA_CHANNEL_12
	void setDmaChannel12En(bool en);
#endif
#if defined(DMA2_Stream4) || defined(DMA2_Channel6) || defined(DMA2_CHANNEL6)
#define YSS_NVIC_DMA_CHANNEL_13
	void setDmaChannel13En(bool en);
#endif
#if defined(DMA2_Stream5) || defined(DMA2_Channel7) || defined(DMA2_CHANNEL7)
#define YSS_NVIC_DMA_CHANNEL_14
	void setDmaChannel14En(bool en);
#endif
#if defined(DMA2_Stream6)
#define YSS_NVIC_DMA_CHANNEL_15
	void setDmaChannel15En(bool en);
#endif
#if defined(DMA2_Stream7)
#define YSS_NVIC_DMA_CHANNEL_16
	void setDmaChannel16En(bool en);
#endif

#if defined(TC0) || defined(MXC_TMR0) || defined(TIMER0)
	void setTimer0En(bool en);
#endif
#if defined(TIM1) || defined(TC1) || defined(MXC_TMR1) || defined(TIMER1)
	void setTimer1En(bool en);
#endif
#if defined(TIM2) || defined(TC2) || defined(MXC_TMR2) || defined(TIMER2)
	void setTimer2En(bool en);
#endif
#if defined(TIM3) || defined(TC3) || defined(TIMER3)
	void setTimer3En(bool en);
#endif
#if defined(TIM4) || defined(TC4) || defined(TIMER4)
	void setTimer4En(bool en);
#endif
#if defined(TIM5) || defined(TIMER5)
	void setTimer5En(bool en);
#endif
#if defined(TIM6) || defined(TIMER6)
	void setTimer6En(bool en);
#endif
#if defined(TIM7) || defined(TIMER7)
	void setTimer7En(bool en);
#endif
#if defined(TIM8) || defined(TIMER8)
	void setTimer8En(bool en);
#endif
#if defined(TIM9) || defined(TIMER9)
	void setTimer9En(bool en);
#endif
#if defined(TIM10) || defined(TIMER10)
	void setTimer10En(bool en);
#endif
#if defined(TIM11) || defined(TIMER11)
	void setTimer11En(bool en);
#endif
#if defined(TIM12) || defined(TIMER12)
	void setTimer12En(bool en);
#endif
#if defined(TIM13) || defined(TIMER13)
	void setTimer13En(bool en);
#endif
#if defined(TIM14) || defined(TIMER14)
	void setTimer14En(bool en);
#endif

#if defined(SERCOM0) || defined(MXC_UART0) || defined(USART0)  || defined(NRF_UART0)
	void setUart0En(bool en);
#endif
#if defined(USART1) || defined(SERCOM1) || defined(MXC_UART1)
	void setUart1En(bool en);
#endif
#if defined(USART2) || defined(SERCOM2)
	void setUart2En(bool en);
#endif
#if defined(USART3) || defined(SERCOM3)
	void setUart3En(bool en);
#endif
#if defined(UART4) || defined(SERCOM4)
	void setUart4En(bool en);
#endif
#if defined(UART5) || defined(SERCOM5)
	void setUart5En(bool en);
#endif
#if defined(USART6)
	void setUart6En(bool en);
#endif
#if defined(UART7)
	void setUart7En(bool en);
#endif
#if defined(UART8)
	void setUart8En(bool en);
#endif

#if defined(I2C1)
	void setI2c1En(bool en);
#endif
#if defined(I2C2)
	void setI2c2En(bool en);
#endif
#if defined(I2C3)
	void setI2c3En(bool en);
#endif
#if defined(I2C4)
	void setI2c4En(bool en);
#endif

#if defined(EXTI) || defined(EIC)
	void setExtiEn(bool en);
#endif

#if defined(USB_OTG_FS)
	void setUsbdFsEn(bool en);
#endif

#if defined(USB_OTG_HS)
	void setUsbdHsEn(bool en);
#endif

#if defined(CAN1) || defined(FDCAN1)
	void setCan1En(bool en);
#endif

#if defined(CAN2) || defined(FDCAN2)
	void setCan2En(bool en);
#endif

#if defined(ADC1) || defined(ADC)
	void setAdc1En(bool en);
#endif

#if defined(ADC2)
	void setAdc2En(bool en);
#endif

#if defined(ADC3)
	void setAdc3En(bool en);
#endif

#if defined(DMA2D)
	void setDma2dEn(bool en);
#endif

#if defined(DAC1) || defined(DAC)
	void setDac1En(bool en);
#endif

#if defined(USB)
void setUsbd1En(bool en);
#endif

#if defined(SAI1)
	void setSai1En(bool en);
#endif

#if defined(SAI2)
	void setSai2En(bool en);
#endif

#if defined(SPI1)
	void setSpi1En(bool en);
#endif

#if defined(SPI2)
	void setSpi2En(bool en);
#endif

};

#endif
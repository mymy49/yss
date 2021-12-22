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
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/Nvic.h>

namespace drv
{
inline void setNvicIntEn(unsigned char num, bool en)
{
	NVIC->ISER[num >> 5] = 1 << (num & 0x1f);
}

inline void setNvicIpr(unsigned char num, unsigned char priority)
{
	priority &= 0xf;
	priority <<= 4;
	NVIC->IP[num] = priority;
}

Nvic::Nvic(void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
{
}

void Nvic::setInterruptEn(unsigned long position, bool en)
{
	setNvicIntEn(position, en);
}

#ifdef DMA1
#if defined(DMA1_Stream0)
void Nvic::setDma1Stream0En(bool en)
{
	setNvicIntEn(DMA1_Stream0_IRQn, en);
}
#endif
#if defined(DMA1_Stream1) || defined(DMA1_Channel1) || defined(DMA1_CHANNEL1)
void Nvic::setDma1Stream1En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA1_Stream1_IRQn, en);
#elif defined(STM32F1) || defined(GD32F10X_XD)
	setNvicIntEn(DMA1_Channel1_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(DMA1_Channel1_IRQn, en);
#elif defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(DMA1_Channel1_IRQn, en);
#endif
}
#endif
#if defined(DMA1_Stream2) || defined(DMA1_Channel2) || defined(DMA1_CHANNEL2)
void Nvic::setDma1Stream2En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA1_Stream2_IRQn, en);
#elif defined(STM32F1) || defined(GD32F10X_XD)
	setNvicIntEn(DMA1_Channel2_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(DMA1_Channel2_IRQn, en);
#elif defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(DMA1_Channel2_3_IRQn, en);
#endif
}
#endif
#if defined(DMA1_Stream3) || defined(DMA1_Channel3) || defined(DMA1_CHANNEL3)
void Nvic::setDma1Stream3En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA1_Stream3_IRQn, en);
#elif defined(STM32F1) || defined(GD32F10X_XD)
	setNvicIntEn(DMA1_Channel3_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(DMA1_Channel3_IRQn, en);
#elif defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(DMA1_Channel2_3_IRQn, en);
#endif
}
#endif
#if defined(DMA1_Stream4) || defined(DMA1_Channel4) || defined(DMA1_CHANNEL4)
void Nvic::setDma1Stream4En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA1_Stream4_IRQn, en);
#elif defined(STM32F1) || defined(GD32F10X_XD)
	setNvicIntEn(DMA1_Channel4_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(DMA1_Channel4_IRQn, en);
#elif defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(DMA1_Channel4_5_6_7_IRQn, en);
#endif
}
#endif
#if defined(DMA1_Stream5) || defined(DMA1_Channel5) || defined(DMA1_CHANNEL5)
void Nvic::setDma1Stream5En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA1_Stream5_IRQn, en);
#elif defined(STM32F1) || defined(GD32F10X_XD)
	setNvicIntEn(DMA1_Channel5_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(DMA1_Channel5_IRQn, en);
#elif defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(DMA1_Channel4_5_6_7_IRQn, en);
#endif
}
#endif
#if defined(DMA1_Stream6) || defined(DMA1_Channel6) || defined(DMA1_CHANNEL6)
void Nvic::setDma1Stream6En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA1_Stream6_IRQn, en);
#elif defined(STM32F1) || defined(GD32F10X_XD)
	setNvicIntEn(DMA1_Channel6_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(DMA1_Channel6_IRQn, en);
#elif defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(DMA1_Channel4_5_6_7_IRQn, en);
#endif
}
#endif
#if defined(DMA1_Stream7) || defined(DMA1_Channel7) || defined(DMA1_CHANNEL7)
void Nvic::setDma1Stream7En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA1_Stream7_IRQn, en);
#elif defined(STM32F1) || defined(GD32F10X_XD)
	setNvicIntEn(DMA1_Channel7_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(DMA1_Channel7_IRQn, en);
#elif defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(DMA1_Channel4_5_6_7_IRQn, en);
#endif
}
#endif
#endif

#ifdef DMA2
#if defined(DMA2_Stream0)
void Nvic::setDma2Stream0En(bool en)
{
	setNvicIntEn(DMA2_Stream0_IRQn, en);
}
#endif
#if defined(DMA2_Stream1) || defined(DMA2_Channel1) || defined(DMA2_CHANNEL1)
void Nvic::setDma2Stream1En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA2_Stream1_IRQn, en);
#elif defined(STM32F1) || defined(STM32G4) || defined(GD32F10X_XD)
	setNvicIntEn(DMA2_Channel1_IRQn, en);
#endif
}
#endif
#if defined(DMA2_Stream2) || defined(DMA2_Channel2) || defined(DMA2_CHANNEL2)
void Nvic::setDma2Stream2En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA2_Stream2_IRQn, en);
#elif defined(STM32F1) || defined(STM32G4) || defined(GD32F10X_XD)
	setNvicIntEn(DMA2_Channel2_IRQn, en);
#endif
}
#endif
#if defined(DMA2_Stream3) || defined(DMA2_Channel3) || defined(DMA2_CHANNEL3)
void Nvic::setDma2Stream3En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA2_Stream3_IRQn, en);
#elif defined(STM32F1) || defined(STM32G4) || defined(GD32F10X_XD)
	setNvicIntEn(DMA2_Channel3_IRQn, en);
#endif
}
#endif
#if defined(DMA2_Stream4) || defined(DMA2_Channel4) || defined(DMA2_CHANNEL4)
void Nvic::setDma2Stream4En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA2_Stream4_IRQn, en);
#elif defined(STM32F1) || defined(STM32G4)
	setNvicIntEn(DMA2_Channel4_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(DMA2_Channel4_5_IRQn, en);
#endif
}
#endif
#if defined(DMA2_Stream5) || defined(DMA2_Channel5) || defined(DMA2_CHANNEL5)
void Nvic::setDma2Stream5En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA2_Stream5_IRQn, en);
#elif defined(STM32F1)
	setNvicIntEn(DMA2_Channel4_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(DMA2_Channel5_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(DMA2_Channel4_5_IRQn, en);
#endif
}
#endif
#if defined(DMA2_Stream6) || defined(DMA2_Channel6) || defined(DMA2_CHANNEL6)
void Nvic::setDma2Stream6En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA2_Stream6_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(DMA2_Channel6_IRQn, en);
#endif
}
#endif
#if defined(DMA2_Stream7) || defined(DMA2_Channel7) || defined(DMA2_CHANNEL7)
void Nvic::setDma2Stream7En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(DMA2_Stream7_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(DMA2_Channel7_IRQn, en);
#else
#endif
}
#endif
#endif

#if defined(TC0) || defined(MXC_TMR0)
void Nvic::setTimer0En(bool en)
{
#if defined(__SAM_L_FAMILY)
	setNvicIntEn(TC0_IRQn, en);
#elif defined(YSS_DRV_NVIC_MAX32660)
	setNvicIntEn(TMR0_IRQn, en);
#endif
}
#endif

#if defined(TIM1) || defined(TC1) || defined(MXC_TMR1) || defined(TIMER1)
void Nvic::setTimer1En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(TIM1_UP_TIM10_IRQn, en);
#elif defined(STM32F1)
	setNvicIntEn(TIM1_UP_TIM10_IRQn, en);
	setNvicIntEn(TIM1_CC_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(TIM1_UP_TIM16_IRQn, en);
#elif defined(STM32F0)
	setNvicIntEn(TIM1_BRK_UP_TRG_COM_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(TC1_IRQn, en);
#elif defined(YSS_DRV_NVIC_MAX32660)
	setNvicIntEn(TMR1_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER1_UP_TIMER10_IRQn, en);
#endif
}
#endif

#if defined(TIM2) || defined(TC2) || defined(MXC_TMR2) || defined(TIMER2)
void Nvic::setTimer2En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM2_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(TC2_IRQn, en);
#elif defined(YSS_DRV_NVIC_MAX32660)
	setNvicIntEn(TMR2_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER2_IRQn, en);
#endif
}
#endif

#if defined(TIM3) || defined(TC3) || defined(TIMER3)
void Nvic::setTimer3En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM3_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(TC3_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER3_IRQn, en);
#endif
}
#endif

#if defined(TIM4) || defined(TC4) || defined(TIMER4)
void Nvic::setTimer4En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM4_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(TC4_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER4_IRQn, en);
#endif
}
#endif

#if defined(TIM5) || defined(TIMER5)
void Nvic::setTimer5En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM5_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER5_IRQn, en);
#endif
}
#endif

#if defined(TIM6) || defined(TIMER6)
void Nvic::setTimer6En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM6_DAC_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER6_IRQn, en);
#endif
}
#endif

#if defined(TIM7) || defined(TIMER7)
void Nvic::setTimer7En(bool en)
{
#if defined(STM32G4)
	setNvicIntEn(TIM7_DAC_IRQn, en);
#elif defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM7_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER7_IRQn, en);
#endif
}
#endif

#if defined(TIM8) || defined(TIMER8)
void Nvic::setTimer8En(bool en)
{
#if defined(STM32G4)
	setNvicIntEn(TIM8_CC_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER8_UP_TIMER13_IRQn, en);
#endif
}
#endif

#if defined(TIM9) || defined(TIMER9)
void Nvic::setTimer9En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM1_BRK_TIM9_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER1_BRK_TIMER9_IRQn, en);
#endif
}
#endif

#if defined(TIM10) || defined(TIMER10)
void Nvic::setTimer10En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM1_UP_TIM10_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER1_UP_TIMER10_IRQn, en);
#endif
}
#endif

#if defined(TIM11) || defined(TIMER11)
void Nvic::setTimer11En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM1_TRG_COM_TIM11_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER1_TRG_COM_TIMER11_IRQn, en);
#endif
}
#endif

#if defined(TIM12) || defined(TIMER12)
void Nvic::setTimer12En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM8_BRK_TIM12_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER8_BRK_TIMER12_IRQn, en);
#endif
}
#endif

#if defined(TIM13) || defined(TIMER13)
void Nvic::setTimer13En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(TIM8_UP_TIM13_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER8_UP_TIMER13_IRQn, en);
#endif
}
#endif

#if defined(TIM14) || defined(TIMER14)
void Nvic::setTimer14En(bool en)
{
#if defined(STM32F0)
	setNvicIntEn(TIM14_IRQn, en);
#elif defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0)
	setNvicIntEn(TIM8_TRG_COM_TIM14_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(TIMER8_TRG_COM_TIMER14_IRQn, en);
#endif
}
#endif

#if defined(SERCOM0) || defined(MXC_UART0)
void Nvic::setUart0En(bool en)
{
#if defined(__SAM_L_FAMILY)
	setNvicIntEn(SERCOM0_IRQn, en);
#elif defined(YSS_DRV_NVIC_MAX32660)
	setNvicIntEn(UART0_IRQn, en);
#endif
}
#endif

#if defined(USART1) || defined(SERCOM1) || defined(MXC_UART1)
void Nvic::setUart1En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(USART1_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(SERCOM1_IRQn, en);
#elif defined(YSS_DRV_NVIC_MAX32660)
	setNvicIntEn(UART1_IRQn, en);
#endif
}
#endif

#if defined(USART2) || defined(SERCOM2)
void Nvic::setUart2En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4) || defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(USART2_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(SERCOM2_IRQn, en);
#endif
}
#endif

#if defined(USART3) || defined(SERCOM3)
void Nvic::setUart3En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4)
	setNvicIntEn(USART3_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(SERCOM3_IRQn, en);
#endif
}
#endif

#if defined(UART4) || defined(SERCOM4)
void Nvic::setUart4En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4)
	setNvicIntEn(UART4_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(SERCOM4_IRQn, en);
#endif
}
#endif

#if defined(UART5) || defined(SERCOM5)
void Nvic::setUart5En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4)
	setNvicIntEn(UART5_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(SERCOM5_IRQn, en);
#endif
}
#endif

#if defined(USART6)
void Nvic::setUart6En(bool en)
{
	setNvicIntEn(USART6_IRQn, en);
}
#endif

#if defined(UART7)
void Nvic::setUart7En(bool en)
{
	setNvicIntEn(UART7_IRQn, en);
}
#endif

#if defined(UART8)
void Nvic::setUart8En(bool en)
{
	setNvicIntEn(UART8_IRQn, en);
}
#endif

#if defined(I2C1)
void Nvic::setI2c1En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4)
	setNvicIntEn(I2C1_EV_IRQn, en);
#elif defined(STM32L0)
	setNvicIntEn(I2C1_IRQn, en);
#endif
}
#endif

#if defined(I2C2)
void Nvic::setI2c2En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4)
	setNvicIntEn(I2C2_EV_IRQn, en);
#elif defined(STM32L0)
	setNvicIntEn(I2C2_IRQn, en);
#endif
}
#endif

#if defined(I2C3)
void Nvic::setI2c3En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32F1)
	setNvicIntEn(I2C3_EV_IRQn, en);
#elif defined(STM32L0)
	setNvicIntEn(I2C3_IRQn, en);
#endif
}
#endif

#if defined(I2C4)
void Nvic::setI2c4En(bool en)
{
	setNvicIntEn(I2C4_EV_IRQn, en);
}
#endif

#if defined(ADC1) || defined(ADC)
void Nvic::setAdc1En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(ADC_IRQn, en);
#elif defined(STM32F1) || defined(STM32G4)
	setNvicIntEn(ADC1_2_IRQn, en);
#elif defined(STM32L0) || defined(STM32F0)
	setNvicIntEn(ADC1_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(ADC_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(ADC1_2_IRQn, en);
#endif
}
#endif

#if defined(ADC2)
void Nvic::setAdc2En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(ADC_IRQn, en);
#elif defined(STM32F1) || defined(STM32G4)
	setNvicIntEn(ADC1_2_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(ADC1_2_IRQn, en);
#endif
}
#endif

#if defined(ADC3)
void Nvic::setAdc3En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(ADC_IRQn, en);
#elif defined(STM32F1) || defined(STM32G4)
	setNvicIntEn(ADC1_2_IRQn, en);
#endif
}
#endif

#if defined(EXTI) || defined(EIC)
void Nvic::setExtiEn(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32G4)
	setNvicIntEn(EXTI0_IRQn, en);
	setNvicIntEn(EXTI1_IRQn, en);
	setNvicIntEn(EXTI2_IRQn, en);
	setNvicIntEn(EXTI3_IRQn, en);
	setNvicIntEn(EXTI4_IRQn, en);
	setNvicIntEn(EXTI9_5_IRQn, en);
	setNvicIntEn(EXTI15_10_IRQn, en);
#elif defined(STM32L0)
	setNvicIntEn(EXTI0_1_IRQn, en);
	setNvicIntEn(EXTI2_3_IRQn, en);
	setNvicIntEn(EXTI4_15_IRQn, en);
#elif defined(STM32F0)
	setNvicIntEn(EXTI0_1_IRQn, en);
	setNvicIntEn(EXTI2_3_IRQn, en);
	setNvicIntEn(EXTI4_15_IRQn, en);
#elif defined(__SAM_L_FAMILY)
	setNvicIntEn(EIC_IRQn, en);
#endif
}
#endif

#if defined(DMA2D)
void Nvic::setDma2dEn(bool en)
{
	setNvicIntEn(DMA2D_IRQn, en);
}
#endif

#if defined(USB_OTG_FS)
void Nvic::setUsbdFsEn(bool en)
{
	setNvicIntEn(OTG_FS_IRQn, en);
}
#endif

#if defined(USB_OTG_HS)
void Nvic::setUsbdHsEn(bool en)
{
	setNvicIntEn(OTG_HS_IRQn, en);
}
#endif

#if defined(CAN1) || defined(FDCAN1)
void Nvic::setCan1En(bool en)
{
#if defined(STM32F4) || defined(STM32F7) || defined(STM32F1) || defined(STM32L0)
	setNvicIntEn(CAN1_RX0_IRQn, en);
	setNvicIntEn(CAN1_RX1_IRQn, en);
#elif defined(STM32G4)
	setNvicIntEn(FDCAN1_IT0_IRQn, en);
	setNvicIntEn(FDCAN1_IT1_IRQn, en);
#elif defined(GD32F10X_XD)
	setNvicIntEn(USB_LP_CAN1_RX0_IRQn, en);
	setNvicIntEn(CAN1_RX1_IRQn, en);
#endif
}
#endif

#if defined(CAN2) || defined(FDCAN2)
void Nvic::setCan2En(bool en)
{
#if defined(STM32G4)
	setNvicIntEn(FDCAN2_IT0_IRQn, en);
	setNvicIntEn(FDCAN2_IT1_IRQn, en);
#elif defined(STM32F4) || defined(STM32F7) || defined(STM32F1)
	setNvicIntEn(CAN2_RX0_IRQn, en);
	setNvicIntEn(CAN2_RX1_IRQn, en);
#endif
}
#endif

#if defined(DAC1) || defined(DAC)
void Nvic::setDac1En(bool en)
{
#if defined(STM32F4) || defined(STM32F7)
	setNvicIntEn(TIM6_DAC_IRQn, en);
#endif
}
#endif

#if defined(USB)
void Nvic::setUsbd1En(bool en)
{
#if defined(STM32F1)
	setNvicIntEn(USB_LP_CAN1_RX0_IRQn, en);
#endif
}
#endif

#if defined(SAI1)
void Nvic::setSai1En(bool en)
{
#if defined(STM32F7)
	setNvicIntEn(SAI1_IRQn, en);
#endif
}
#endif

#if defined(SAI2)
void Nvic::setSai2En(bool en)
{
#if defined(STM32F7)
	setNvicIntEn(SAI2_IRQn, en);
#endif
}
#endif

}
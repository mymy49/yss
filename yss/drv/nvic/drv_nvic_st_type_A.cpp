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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <__cross_studio_io.h>

#include <config.h>
#include <drv/peripherals.h>
#include <drv/nvic/drv_st_nvic_type_A_register.h>

#if defined(NVIC)
drv::Nvic nvic(0, 0);
#endif

namespace drv
{
	Nvic::Nvic(void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) :  Drv(clockFunc, nvicFunc)
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
#if defined(DMA1_Stream1)
	void Nvic::setDma1Stream1En(bool en)
	{
		setNvicIntEn(DMA1_Stream1_IRQn, en);
	}
#endif
#if defined(DMA1_Stream2)
	void Nvic::setDma1Stream2En(bool en)
	{
		setNvicIntEn(DMA1_Stream2_IRQn, en);
	}
#endif
#if defined(DMA1_Stream3)
	void Nvic::setDma1Stream3En(bool en)
	{
		setNvicIntEn(DMA1_Stream3_IRQn, en);
	}
#endif
#if defined(DMA1_Stream4)
	void Nvic::setDma1Stream4En(bool en)
	{
		setNvicIntEn(DMA1_Stream4_IRQn, en);
	}
#endif
#if defined(DMA1_Stream5)
	void Nvic::setDma1Stream5En(bool en)
	{
		setNvicIntEn(DMA1_Stream5_IRQn, en);
	}
#endif
#if defined(DMA1_Stream6)
	void Nvic::setDma1Stream6En(bool en)
	{
		setNvicIntEn(DMA1_Stream6_IRQn, en);
	}
#endif
#if defined(DMA1_Stream7)
	void Nvic::setDma1Stream7En(bool en)
	{
		setNvicIntEn(DMA1_Stream7_IRQn, en);
	}
#endif
#endif

#ifdef DMA2
#if defined(DMA2_Stream1)
	void Nvic::setDma2Stream0En(bool en)
	{
		setNvicIntEn(DMA2_Stream0_IRQn, en);
	}
#endif
#if defined(DMA2_Stream1)
	void Nvic::setDma2Stream1En(bool en)
	{
		setNvicIntEn(DMA2_Stream1_IRQn, en);
	}
#endif
#if defined(DMA2_Stream2)
	void Nvic::setDma2Stream2En(bool en)
	{
		setNvicIntEn(DMA2_Stream2_IRQn, en);
	}
#endif
#if defined(DMA2_Stream3)
	void Nvic::setDma2Stream3En(bool en)
	{
		setNvicIntEn(DMA2_Stream3_IRQn, en);
	}
#endif
#if defined(DMA2_Stream4)
	void Nvic::setDma2Stream4En(bool en)
	{
		setNvicIntEn(DMA2_Stream4_IRQn, en);
	}
#endif
#if defined(DMA2_Stream5)
	void Nvic::setDma2Stream5En(bool en)
	{
		setNvicIntEn(DMA2_Stream5_IRQn, en);
	}
#endif
#if defined(DMA2_Stream6)
	void Nvic::setDma2Stream6En(bool en)
	{
		setNvicIntEn(DMA2_Stream6_IRQn, en);
	}
#endif
#if defined(DMA2_Stream7)
	void Nvic::setDma2Stream7En(bool en)
	{
		setNvicIntEn(DMA2_Stream7_IRQn, en);
	}
#endif
#endif

#if defined(TIM1)
	void Nvic::setTimer1En(bool en)
	{
		setNvicIntEn(TIM1_UP_TIM10_IRQn, en);
	}
#endif

#if defined(TIM2)
	void Nvic::setTimer2En(bool en)
	{
		setNvicIntEn(TIM2_IRQn, en);
	}
#endif

#if defined(TIM3)
	void Nvic::setTimer3En(bool en)
	{
		setNvicIntEn(TIM3_IRQn, en);
	}
#endif

#if defined(TIM4)
	void Nvic::setTimer4En(bool en)
	{
		setNvicIntEn(TIM4_IRQn, en);
	}
#endif

#if defined(TIM5)
	void Nvic::setTimer5En(bool en)
	{
		setNvicIntEn(TIM5_IRQn, en);
	}
#endif

#if defined(TIM6)
	void Nvic::setTimer6En(bool en)
	{
		setNvicIntEn(TIM6_DAC_IRQn, en);
	}
#endif

#if defined(TIM7)
	void Nvic::setTimer7En(bool en)
	{
		setNvicIntEn(TIM7_IRQn, en);
	}
#endif

#if defined(TIM8)
	void Nvic::setTimer8En(bool en)
	{
		setNvicIntEn(TIM8_UP_TIM13_IRQn, en);
	}
#endif

#if defined(TIM9)
	void Nvic::setTimer9En(bool en)
	{
		setNvicIntEn(TIM1_BRK_TIM9_IRQn, en);
	}
#endif

#if defined(TIM10)
	void Nvic::setTimer10En(bool en)
	{
		setNvicIntEn(TIM1_UP_TIM10_IRQn, en);
	}
#endif

#if defined(TIM11)
	void Nvic::setTimer11En(bool en)
	{
		setNvicIntEn(TIM1_TRG_COM_TIM11_IRQn, en);
	}
#endif

#if defined(TIM12)
	void Nvic::setTimer12En(bool en)
	{
		setNvicIntEn(TIM8_BRK_TIM12_IRQn, en);
	}
#endif

#if defined(TIM13)
	void Nvic::setTimer13En(bool en)
	{
		setNvicIntEn(TIM8_UP_TIM13_IRQn, en);
	}
#endif

#if defined(TIM14)
	void Nvic::setTimer14En(bool en)
	{
		setNvicIntEn(TIM8_TRG_COM_TIM14_IRQn, en);
	}
#endif

#if defined(USART1)
	void Nvic::setUart1En(bool en)
	{
		setNvicIntEn(USART1_IRQn, en);
	}
#endif

#if defined(USART2)
	void Nvic::setUart2En(bool en)
	{
		setNvicIntEn(USART2_IRQn, en);
	}
#endif

#if defined(USART3)
	void Nvic::setUart3En(bool en)
	{
		setNvicIntEn(USART3_IRQn, en);
	}
#endif

#if defined(UART4)
	void Nvic::setUart4En(bool en)
	{
		setNvicIntEn(UART4_IRQn, en);
	}
#endif

#if defined(UART5)
	void Nvic::setUart5En(bool en)
	{
		setNvicIntEn(UART5_IRQn, en);
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

	void Nvic::setI2c1En(bool en)
	{
#ifdef I2C1
		setNvicIntEn(I2C1_EV_IRQn, en);
#endif
	}

	void Nvic::setI2c2En(bool en)
	{
#ifdef I2C2
		setNvicIntEn(I2C2_EV_IRQn, en);
#endif
	}

	void Nvic::setI2c3En(bool en)
	{
#ifdef I2C3
		setNvicIntEn(I2C3_EV_IRQn, en);
#endif
	}

	void Nvic::setI2c4En(bool en)
	{
#ifdef I2C4
		setNvicIntEn(I2C4_EV_IRQn, en);
#endif
	}

#ifdef ADC1
	void Nvic::setAdc1En(bool en)
	{
		setNvicIntEn(ADC_IRQn, en);
	}
#endif

#ifdef ADC2
	void Nvic::setAdc2En(bool en)
	{
		setNvicIntEn(ADC_IRQn, en);
	}
#endif

#ifdef ADC3
	void Nvic::setAdc3En(bool en)
	{
		setNvicIntEn(ADC_IRQn, en);
	}
#endif

#if defined(EXTI)
	void Nvic::setExtiEn(bool en)
	{
		setNvicIntEn(EXTI0_IRQn, en);
		setNvicIntEn(EXTI1_IRQn, en);
		setNvicIntEn(EXTI2_IRQn, en);
		setNvicIntEn(EXTI3_IRQn, en);
		setNvicIntEn(EXTI4_IRQn, en);
		setNvicIntEn(EXTI9_5_IRQn, en);
		setNvicIntEn(EXTI15_10_IRQn, en);
	}
#endif

#ifdef DMA2D
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
		setNvicIntEn(CAN1_RX0_IRQn, en);
		setNvicIntEn(CAN1_RX1_IRQn, en);
	}
#endif

#if defined(CAN2) || defined(FDCAN2)
	void Nvic::setCan2En(bool en)
	{
		setNvicIntEn(CAN2_RX0_IRQn, en);
		setNvicIntEn(CAN2_RX1_IRQn, en);
	}
#endif

}
#endif


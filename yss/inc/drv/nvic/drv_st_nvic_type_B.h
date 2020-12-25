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

#ifndef	YSS_DRV_NVIC_ST_TYPE_B__H_
#define	YSS_DRV_NVIC_ST_TYPE_B__H_

#if defined(STM32F100xB) || defined(STM32F100xE) ||                                               \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC) ||                                                                         \
    defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

#include <yss/mcu.h>
#include <config.h>

namespace drv
{
	class Nvic
	{
	public :
		void setInterruptEn(unsigned long position,	bool en);

#if defined(DMA1_Channel1)
		void setDma1Stream1En(bool en);
#endif
#if defined(DMA1_Channel2)
		void setDma1Stream2En(bool en);
#endif
#if defined(DMA1_Channel3)
		void setDma1Stream3En(bool en);
#endif
#if defined(DMA1_Channel4)
		void setDma1Stream4En(bool en);
#endif
#if defined(DMA1_Channel5)
		void setDma1Stream5En(bool en);
#endif
#if defined(DMA1_Channel6)
		void setDma1Stream6En(bool en);
#endif
#if defined(DMA1_Channel7)
		void setDma1Stream7En(bool en);
#endif

#if defined(DMA2_Channel1)
		void setDma2Stream1En(bool en);
#endif
#if defined(DMA2_Channel2)
		void setDma2Stream2En(bool en);
#endif
#if defined(DMA2_Channel3)
		void setDma2Stream3En(bool en);
#endif
#if defined(DMA2_Channel4)
		void setDma2Stream4En(bool en);
#endif
#if defined(DMA2_Channel5)
		void setDma2Stream5En(bool en);
#endif

#if defined(TIM1)
		void setTimer1En(bool en);
#endif
#if defined(TIM2)
		void setTimer2En(bool en);
#endif
#if defined(TIM3)
		void setTimer3En(bool en);
#endif
#if defined(TIM4)
		void setTimer4En(bool en);
#endif
#if defined(TIM5)
		void setTimer5En(bool en);
#endif
#if defined(TIM6)
		void setTimer6En(bool en);
#endif
#if defined(TIM7)
		void setTimer7En(bool en);
#endif
#if defined(TIM8)
		void setTimer8En(bool en);
#endif
#if defined(TIM9)
		void setTimer9En(bool en);
#endif
#if defined(TIM10)
		void setTimer10En(bool en);
#endif
#if defined(TIM11)
		void setTimer11En(bool en);
#endif
#if defined(TIM12)
		void setTimer12En(bool en);
#endif
#if defined(TIM13)
		void setTimer13En(bool en);
#endif
#if defined(TIM14)
		void setTimer14En(bool en);
#endif

#if defined(EXTI)
		void setExtiEn(bool en);
#endif

#if defined(USART1)
		void setUart1En(bool en);
#endif
#if defined(USART2)
		void setUart2En(bool en);
#endif
#if defined(USART3)
		void setUart3En(bool en);
#endif
#if defined(UART4)
		void setUart4En(bool en);
#endif

#if defined(ADC1)
	void setAdc1En(bool en);
#endif

#if defined(ADC2)
	void setAdc2En(bool en);
#endif

#if defined(CAN1)
	void setCan1En(bool en);
#endif

#if defined(CAN2)
	void setCan2En(bool en);
#endif

#if defined(I2C1)
	void setI2c1En(bool	en);
#endif

#if defined(I2C2)
	void setI2c2En(bool	en);
#endif

#if defined(I2C3)
	void setI2c3En(bool	en);
#endif

#if defined(I2C4)
	void setI2c4En(bool	en);
#endif
	};
}

#if	defined(NVIC)
extern drv::Nvic nvic;
#endif

#endif

#endif

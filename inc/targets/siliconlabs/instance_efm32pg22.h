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

#ifndef YSS_INSTANCE_EFM32PG22__H_
#define YSS_INSTANCE_EFM32PG22__H_

#include "em_device.h"

#if defined(TIMER_PRESENT)
	#if TIMER_COUNT >= 1
		extern Timer timer0;
	#endif

	#if TIMER_COUNT >= 2
		extern Timer timer1;
	#endif

	#if TIMER_COUNT >= 3
		extern Timer timer2;
	#endif

	#if TIMER_COUNT >= 4
		extern Timer timer3;
	#endif

	#if TIMER_COUNT >= 5
		extern Timer timer4;
	#endif
#endif

#if defined(GPIO_PRESENT)
	#if defined(GPIO_PA_INDEX)
		extern Gpio gpioA;
	#endif

	#if defined(GPIO_PB_INDEX)
		extern Gpio gpioB;
	#endif

	#if defined(GPIO_PC_INDEX)
		extern Gpio gpioC;
	#endif

	#if defined(GPIO_PD_INDEX)
		extern Gpio gpioD;
	#endif
#endif

#if defined(USART_PRESENT)
	#if USART_COUNT >= 1
		extern Uart uart0;
		extern Spi spi0;
	#endif

	#if USART_COUNT >= 2
		extern Uart uart1;
		extern Spi spi1;
	#endif
#endif

#if defined(PDM_PRESENT)
	#if PDM_COUNT >= 1
		extern Pdm pdm0;
	#endif
#endif

extern DmaChannel1 dmaChannel1;
extern DmaChannel2 dmaChannel2;
extern DmaChannel3 dmaChannel3;
extern DmaChannel4 dmaChannel4;
extern DmaChannel5 dmaChannel5;
extern DmaChannel6 dmaChannel6;
extern DmaChannel7 dmaChannel7;
extern DmaChannel8 dmaChannel8;
extern Dma *dmaChannelList[8];

#endif


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

#if defined(NRF52840_XXAA)

#include <yss/instance.h>
#include <drv/Exti.h>

static void enableInterrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(GPIOTE_IRQn, en);
	nvic.unlock();
}

Exti exti(0, enableInterrupt);

extern "C"
{
	void GPIOTE_IRQHandler(void)
	{
		if(NRF_GPIOTE->EVENTS_IN[0])
		{
			NRF_GPIOTE->EVENTS_IN[0] = 0;
			exti.isr(0);
		}

		if(NRF_GPIOTE->EVENTS_IN[1])
		{
			NRF_GPIOTE->EVENTS_IN[1] = 0;
			exti.isr(1);
		}

		if(NRF_GPIOTE->EVENTS_IN[2])
		{
			NRF_GPIOTE->EVENTS_IN[2] = 0;
			exti.isr(2);
		}

		if(NRF_GPIOTE->EVENTS_IN[3])
		{
			NRF_GPIOTE->EVENTS_IN[3] = 0;
			exti.isr(3);
		}

		if(NRF_GPIOTE->EVENTS_IN[4])
		{
			NRF_GPIOTE->EVENTS_IN[4] = 0;
			exti.isr(4);
		}

		if(NRF_GPIOTE->EVENTS_IN[5])
		{
			NRF_GPIOTE->EVENTS_IN[5] = 0;
			exti.isr(5);
		}

		if(NRF_GPIOTE->EVENTS_IN[6])
		{
			NRF_GPIOTE->EVENTS_IN[6] = 0;
			exti.isr(6);
		}

		if(NRF_GPIOTE->EVENTS_IN[7])
		{
			NRF_GPIOTE->EVENTS_IN[7] = 0;
			exti.isr(7);
		}
	}
}

#endif


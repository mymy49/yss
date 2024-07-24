/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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


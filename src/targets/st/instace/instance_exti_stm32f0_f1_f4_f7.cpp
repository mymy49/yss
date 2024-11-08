/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4) || defined(STM32F7) || defined (GD32F1) || defined(STM32F0) || defined(STM32F1)

#include <targets/st/bitfield.h>
#include <drv/Exti.h>
#include <yss/instance.h>

static void enableInterrupt(bool en)
{
	nvic.lock();
#if defined(STM32F0)
	nvic.enableInterrupt(EXTI0_1_IRQn, en);
	nvic.enableInterrupt(EXTI2_3_IRQn, en);
	nvic.enableInterrupt(EXTI4_15_IRQn, en);
#else
	nvic.enableInterrupt(EXTI0_IRQn, en);
	nvic.enableInterrupt(EXTI1_IRQn, en);
	nvic.enableInterrupt(EXTI2_IRQn, en);
	nvic.enableInterrupt(EXTI3_IRQn, en);
	nvic.enableInterrupt(EXTI4_IRQn, en);
	nvic.enableInterrupt(EXTI9_5_IRQn, en);
	nvic.enableInterrupt(EXTI15_10_IRQn, en);
#endif
	nvic.unlock();
}

Exti exti(0, enableInterrupt);

extern "C"
{
#if defined(STM32F0)
	void EXTI0_1_IRQHandler(void)
	{
		uint32_t imr = EXTI->IMR;
		uint32_t pd = EXTI->PR;

		if (imr & 1 << 0 && pd & 1 << 0)
		{
			exti.isr(0);
			EXTI->PR = 1 << 0;
		}

		if (imr & 1 << 1 && pd & 1 << 1)
		{
			exti.isr(1);
			EXTI->PR = 1 << 1;
		}
	}

	void EXTI2_3_IRQHandler(void)
	{
		uint32_t imr = EXTI->IMR;
		uint32_t pd = EXTI->PR;

		if (imr & 1 << 2 && pd & 1 << 2)
		{
			exti.isr(2);
			EXTI->PR = 1 << 2;
		}

		if (imr & 1 << 3 && pd & 1 << 3)
		{
			exti.isr(3);
			EXTI->PR = 1 << 3;
		}
	}

	void EXTI4_15_IRQHandler(void)
	{
		uint32_t imr = EXTI->IMR;
		uint32_t pd = EXTI->PR;

		if (imr & 1 << 4 && pd & 1 << 4)
		{
			exti.isr(4);
			EXTI->PR = 1 << 4;
		}

		if (imr & 1 << 5 && pd & 1 << 5)
		{
			exti.isr(5);
			EXTI->PR = 1 << 5;
		}

		if (imr & 1 << 6 && pd & 1 << 6)
		{
			exti.isr(6);
			EXTI->PR = 1 << 6;
		}

		if (imr & 1 << 7&& pd & 1 << 8)
		{
			exti.isr(7);
			EXTI->PR = 1 << 7;
		}

		if (imr & 1 << 8 && pd & 1 << 8)
		{
			exti.isr(8);
			EXTI->PR = 1 << 8;
		}

		if (imr & 1 << 9 && pd & 1 << 9)
		{
			exti.isr(9);
			EXTI->PR = 1 << 9;
		}

		if (imr & 1 << 10 && pd & 1 << 10)
		{
			exti.isr(10);
			EXTI->PR = 1 << 10;
		}

		if (imr & 1 << 11 && pd & 1 << 11)
		{
			exti.isr(11);
			EXTI->PR = 1 << 11;
		}

		if (imr & 1 << 12 && pd & 1 << 12)
		{
			exti.isr(12);
			EXTI->PR = 1 << 12;
		}

		if (imr & 1 << 13 && pd & 1 << 13)
		{
			exti.isr(13);
			EXTI->PR = 1 << 13;
		}

		if (imr & 1 << 14 && pd & 1 << 14)
		{
			exti.isr(14);
			EXTI->PR = 1 << 14;
		}

		if (imr & 1 << 15 && pd & 1 << 15)
		{
			exti.isr(15);
			EXTI->PR = 1 << 15;
		}
	}
#else
	void EXTI0_IRQHandler(void)
	{
		exti.isr(0);
		EXTI->PR = 1 << 0;
	}

	void EXTI1_IRQHandler(void)
	{
		exti.isr(1);
		EXTI->PR = 1 << 1;
	}

	void EXTI2_IRQHandler(void)
	{
		exti.isr(2);
		EXTI->PR = 1 << 2;
	}

	void EXTI3_IRQHandler(void)
	{
		exti.isr(3);
		EXTI->PR = 1 << 3;
	}

	void EXTI4_IRQHandler(void)
	{
		exti.isr(4);
		EXTI->PR = 1 << 4;
	}

	void EXTI9_5_IRQHandler(void)
	{
		uint32_t imr = EXTI->IMR;
		uint32_t pd = EXTI->PR;

		if (imr & 1 << 5 && pd & 1 << 5)
		{
			exti.isr(5);
			EXTI->PR = 1 << 5;
		}

		if (imr & 1 << 6 && pd & 1 << 6)
		{
			exti.isr(6);
			EXTI->PR = 1 << 6;
		}

		if (imr & 1 << 7 && pd & 1 << 7)
		{
			exti.isr(7);
			EXTI->PR = 1 << 7;
		}

		if (imr & 1 << 8 && pd & 1 << 8)
		{
			exti.isr(8);
			EXTI->PR = 1 << 8;
		}

		if (imr & 1 << 9 && pd & 1 << 9)
		{
			exti.isr(9);
			EXTI->PR = 1 << 9;
		}
	}

	void EXTI15_10_IRQHandler(void)
	{
		uint32_t imr = EXTI->IMR;
		uint32_t pd = EXTI->PR;
		
		if (imr & 1 << 10 && pd & 1 << 10)
		{
			exti.isr(10);
			EXTI->PR = 1 << 10;
		}

		if (imr & 1 << 11 && pd & 1 << 11)
		{
			exti.isr(11);
			EXTI->PR = 1 << 11;
		}

		if (imr & 1 << 12 && pd & 1 << 12)
		{
			exti.isr(12);
			EXTI->PR = 1 << 12;
		}

		if (imr & 1 << 13 && pd & 1 << 13)
		{
			exti.isr(13);
			EXTI->PR = 1 << 13;
		}

		if (imr & 1 << 14 && pd & 1 << 14)
		{
			exti.isr(14);
			EXTI->PR = 1 << 14;
		}

		if (imr & 1 << 15 && pd & 1 << 15)
		{
			exti.isr(15);
			EXTI->PR = 1 << 15;
		}
	}
#endif
}

#endif


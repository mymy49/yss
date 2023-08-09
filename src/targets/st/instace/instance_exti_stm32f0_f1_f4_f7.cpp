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

#include <drv/mcu.h>

#if defined(STM32F4_N) || defined(STM32F7_N) || defined (GD32F1) || defined(STM32F0_N)

#if defined(STM32F446xx)
#include <targets/st_gigadevice/exti_stm32_gd32f1_f4_f7.h>
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#elif defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#elif defined(GD32F1)
#include <targets/st/bitfield_stm32f103xx.h>
#elif defined(STM32F0_N)
#include <targets/st/bitfield_stm32f030xx.h>
#endif

#include <drv/Exti.h>
#include <yss/instance.h>

#if defined(GD32F1)
#if defined(__SEGGER_LINKER)

#else

#endif
#elif defined(STM32F4) || defined(STM32F7)

#elif defined(GD32F4)
#define EXTI15_10_IRQHandler	EXTI10_15_IRQHandler
#define EXTI9_5_IRQHandler		EXTI5_9_IRQHandler
#endif


static void enableInterrupt(bool en)
{
	nvic.lock();
#if defined(STM32F0_N)
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
#if defined(STM32F0_N)
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
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		exti.isr(0);
		EXTI->PR = 1 << 0;
	}

	void EXTI1_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		exti.isr(1);
		EXTI->PR = 1 << 1;
	}

	void EXTI2_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		exti.isr(2);
		EXTI->PR = 1 << 2;
	}

	void EXTI3_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		exti.isr(3);
		EXTI->PR = 1 << 3;
	}

	void EXTI4_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		exti.isr(4);
		EXTI->PR = 1 << 4;
	}

	void EXTI9_5_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
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
	}

	void EXTI15_10_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
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


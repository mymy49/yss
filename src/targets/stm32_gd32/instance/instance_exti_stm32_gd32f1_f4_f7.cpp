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

#include <drv/mcu.h>

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7) || defined(GD32F4)

#include <targets/st_gigadevice/exti_stm32_gd32f1_f4_f7.h>
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
	nvic.enableInterrupt(EXTI0_IRQn, en);
	nvic.enableInterrupt(EXTI1_IRQn, en);
	nvic.enableInterrupt(EXTI2_IRQn, en);
	nvic.enableInterrupt(EXTI3_IRQn, en);
	nvic.enableInterrupt(EXTI4_IRQn, en);
	nvic.enableInterrupt(EXTI9_5_IRQn, en);
	nvic.enableInterrupt(EXTI15_10_IRQn, en);
	nvic.unlock();
}

Exti exti(0, enableInterrupt);

extern "C"
{
	void EXTI0_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		exti.isr(0);
		peri[EXTI_REG::PR] = 1 << 0;
	}

	void EXTI1_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		exti.isr(1);
		peri[EXTI_REG::PR] = 1 << 1;
	}

	void EXTI2_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		exti.isr(2);
		peri[EXTI_REG::PR] = 1 << 2;
	}

	void EXTI3_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		exti.isr(3);
		peri[EXTI_REG::PR] = 1 << 3;
	}

	void EXTI4_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		exti.isr(4);
		peri[EXTI_REG::PR] = 1 << 4;
	}

	void EXTI9_5_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		uint32_t imr = peri[EXTI_REG::IMR];
		uint32_t pd = peri[EXTI_REG::PR];

		if (imr & 1 << 5 && pd & 1 << 5)
		{
			exti.isr(5);
			peri[EXTI_REG::PR] = 1 << 5;
		}

		if (imr & 1 << 6 && pd & 1 << 6)
		{
			exti.isr(6);
			peri[EXTI_REG::PR] = 1 << 6;
		}

		if (imr & 1 << 7&& pd & 1 << 8)
		{
			exti.isr(7);
			peri[EXTI_REG::PR] = 1 << 7;
		}

		if (imr & 1 << 8 && pd & 1 << 8)
		{
			exti.isr(8);
			peri[EXTI_REG::PR] = 1 << 8;
		}

		if (imr & 1 << 9 && pd & 1 << 9)
		{
			exti.isr(9);
			peri[EXTI_REG::PR] = 1 << 9;
		}
	}

	void EXTI15_10_IRQHandler(void)
	{
		volatile uint32_t *peri = (volatile uint32_t*)EXTI;
		uint32_t imr = peri[EXTI_REG::IMR];
		uint32_t pd = peri[EXTI_REG::PR];
		
		if (imr & 1 << 10 && pd & 1 << 10)
		{
			exti.isr(10);
			peri[EXTI_REG::PR] = 1 << 10;
		}

		if (imr & 1 << 11 && pd & 1 << 11)
		{
			exti.isr(11);
			peri[EXTI_REG::PR] = 1 << 11;
		}

		if (imr & 1 << 12 && pd & 1 << 12)
		{
			exti.isr(12);
			peri[EXTI_REG::PR] = 1 << 12;
		}

		if (imr & 1 << 13 && pd & 1 << 13)
		{
			exti.isr(13);
			peri[EXTI_REG::PR] = 1 << 13;
		}

		if (imr & 1 << 14 && pd & 1 << 14)
		{
			exti.isr(14);
			peri[EXTI_REG::PR] = 1 << 14;
		}

		if (imr & 1 << 15 && pd & 1 << 15)
		{
			exti.isr(15);
			peri[EXTI_REG::PR] = 1 << 15;
		}
	}
}

#endif


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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.02.11 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7)

static void setIntEn(bool en)
{
	nvic.setExtiEn(en);
}

drv::Exti exti(0, setIntEn);

extern "C"
{
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
		if (EXTI->IMR & 1 << 5 && EXTI->PR & 1 << 5)
		{
			exti.isr(5);
			EXTI->PR = 1 << 5;
		}

		if (EXTI->IMR & 1 << 6 && EXTI->PR & 1 << 6)
		{
			exti.isr(6);
			EXTI->PR = 1 << 6;
		}

		if (EXTI->IMR & 1 << 7&& EXTI->PR & 1 << 8)
		{
			exti.isr(7);
			EXTI->PR = 1 << 7;
		}

		if (EXTI->IMR & 1 << 8 && EXTI->PR & 1 << 8)
		{
			exti.isr(8);
			EXTI->PR = 1 << 8;
		}

		if (EXTI->IMR & 1 << 9&& EXTI->PR & 1 << 9)
		{
			exti.isr(9);
			EXTI->PR = 1 << 9;
		}
	}

	void EXTI15_10_IRQHandler(void)
	{
		if (EXTI->IMR & 1 << 10 && EXTI->PR & 1 << 10)
		{
			exti.isr(10);
			EXTI->PR = 1 << 10;
		}

		if (EXTI->IMR & 1 << 11 && EXTI->PR & 1 << 11)
		{
			exti.isr(11);
			EXTI->PR = 1 << 11;
		}

		if (EXTI->IMR & 1 << 12 && EXTI->PR & 1 << 12)
		{
			exti.isr(12);
			EXTI->PR = 1 << 12;
		}

		if (EXTI->IMR & 1 << 13 && EXTI->PR & 1 << 13)
		{
			exti.isr(13);
			EXTI->PR = 1 << 13;
		}

		if (EXTI->IMR & 1 << 14 && EXTI->PR & 1 << 14)
		{
			exti.isr(14);
			EXTI->PR = 1 << 14;
		}

		if (EXTI->IMR & 1 << 15 && EXTI->PR & 1 << 15)
		{
			exti.isr(15);
			EXTI->PR = 1 << 15;
		}
	}
}

#endif


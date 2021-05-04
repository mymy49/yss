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

#include <drv/nvic/nvic.h>
#include <instance/instance_clock.h>
#include <instance/instance_exti.h>
#include <instance/instance_nvic.h>

#if defined(EXTI) || defined(EIC)

#if defined(__SAM_L_FAMILY)
static void setClockEn(bool en)
{
    clock.peripheral.setExtiEn(en);
}
#endif

static void setIntEn(bool en)
{
    nvic.setExtiEn(en);
}

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1) || defined(STM32L0) || defined(STM32F0) || defined(STM32G4)
drv::Exti exti(0, setIntEn);
#elif defined(__SAM_L_FAMILY)
drv::Exti exti(setClockEn, setIntEn);
#endif

extern "C"
{
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1)
    void EXTI0_IRQHandler(void)
    {
        exti.isr(0);
    }

    void EXTI1_IRQHandler(void)
    {
        exti.isr(1);
    }

    void EXTI2_IRQHandler(void)
    {
        exti.isr(2);
    }

    void EXTI3_IRQHandler(void)
    {
        exti.isr(3);
    }

    void EXTI4_IRQHandler(void)
    {
        exti.isr(4);
    }

    void EXTI9_5_IRQHandler(void)
    {
        exti.isr(5);
        exti.isr(6);
        exti.isr(7);
        exti.isr(8);
        exti.isr(9);
    }

    void EXTI15_10_IRQHandler(void)
    {
        exti.isr(10);
        exti.isr(11);
        exti.isr(12);
        exti.isr(13);
        exti.isr(14);
        exti.isr(15);
    }
#elif defined(STM32F0)
	void EXTI0_1_IRQHandler(void)
	{
		if(EXTI->IMR & EXTI_IMR_IM0 && EXTI->PR & EXTI_PR_PIF0)
		{
			EXTI->PR = EXTI_PR_PIF0;
			exti.isr(0);
		}

		if(EXTI->IMR & EXTI_IMR_IM1 && EXTI->PR & EXTI_PR_PIF1)
		{
			EXTI->PR = EXTI_PR_PIF1;
			exti.isr(1);
		}
	}

	void EXTI2_3_IRQHandler(void)
	{
		if(EXTI->IMR & EXTI_IMR_IM2 && EXTI->PR & EXTI_PR_PIF2)
		{
			EXTI->PR = EXTI_PR_PIF2;
			exti.isr(2);
		}

		if(EXTI->IMR & EXTI_IMR_IM3 && EXTI->PR & EXTI_PR_PIF3)
		{
			EXTI->PR = EXTI_PR_PIF3;
			exti.isr(3);
		}
	}

	void EXTI4_15_IRQHandler(void)
	{
		if(EXTI->IMR & EXTI_IMR_IM4 && EXTI->PR & EXTI_PR_PIF4)
		{
			EXTI->PR = EXTI_PR_PIF4;
			exti.isr(4);
		}

		if(EXTI->IMR & EXTI_IMR_IM5 && EXTI->PR & EXTI_PR_PIF5)
		{
			EXTI->PR = EXTI_PR_PIF5;
			exti.isr(5);
		}

		if(EXTI->IMR & EXTI_IMR_IM6 && EXTI->PR & EXTI_PR_PIF6)
		{
			EXTI->PR = EXTI_PR_PIF6;
			exti.isr(6);
		}

		if(EXTI->IMR & EXTI_IMR_IM7 && EXTI->PR & EXTI_PR_PIF7)
		{
			EXTI->PR = EXTI_PR_PIF7;
			exti.isr(7);
		}

		if(EXTI->IMR & EXTI_IMR_IM8 && EXTI->PR & EXTI_PR_PIF8)
		{
			EXTI->PR = EXTI_PR_PIF8;
			exti.isr(8);
		}

		if(EXTI->IMR & EXTI_IMR_IM9 && EXTI->PR & EXTI_PR_PIF9)
		{
			EXTI->PR = EXTI_PR_PIF9;
			exti.isr(9);
		}

		if(EXTI->IMR & EXTI_IMR_IM10 && EXTI->PR & EXTI_PR_PIF10)
		{
			EXTI->PR = EXTI_PR_PIF10;
			exti.isr(10);
		}

		if(EXTI->IMR & EXTI_IMR_IM11 && EXTI->PR & EXTI_PR_PIF11)
		{
			EXTI->PR = EXTI_PR_PIF11;
			exti.isr(11);
		}

		if(EXTI->IMR & EXTI_IMR_IM12 && EXTI->PR & EXTI_PR_PIF12)
		{
			EXTI->PR = EXTI_PR_PIF12;
			exti.isr(12);
		}

		if(EXTI->IMR & EXTI_IMR_IM13 && EXTI->PR & EXTI_PR_PIF13)
		{
			EXTI->PR = EXTI_PR_PIF13;
			exti.isr(13);
		}

		if(EXTI->IMR & EXTI_IMR_IM14 && EXTI->PR & EXTI_PR_PIF14)
		{
			EXTI->PR = EXTI_PR_PIF14;
			exti.isr(14);
		}

		if(EXTI->IMR & EXTI_IMR_IM15 && EXTI->PR & EXTI_PR_PIF15)
		{
			EXTI->PR = EXTI_PR_PIF15;
			exti.isr(15);
		}
	}
#elif defined(__SAM_L_FAMILY)
	void EIC_Handler(void)
	{
		exti.isr();
	}
#endif
}


#endif
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
// 주담당자 : 아이구 (mymy49@nate.com) 2021.03.10 ~ 현재
// 부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || defined(STM32G4) || defined(STM32F0)

static unsigned int getTimerApb2ClkFreq(void)
{
    return clock.getTimerApb2ClkFreq();
}

static unsigned int getTimerApb1ClkFreq(void)
{
    return clock.getTimerApb1ClkFreq();
}

#elif defined(__SAM_L_FAMILY)

#endif

//********** Timer1 구성 설정 및 변수 선언 **********
#if defined(TIM1_ENABLE) && defined(TIM1)
static void setTim1ClockEn(bool en)
{
    clock.peripheral.setTimer1En(en);
}

static void setTim1IntEn(bool en)
{
    nvic.setTimer1En(en);
}

static void resetTim1(void)
{
//    clock.peripheral.resetTimer1();
}

drv::Timer timer1(TIM1, setTim1ClockEn, setTim1IntEn, resetTim1, getTimerApb2ClkFreq);

extern "C"
{
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F1)
    void TIM1_UP_TIM10_IRQHandler(void)
#elif defined(STM32G4) || defined(STM32L4)
    void TIM1_UP_TIM16_IRQHandler(void)
#elif defined(STM32F0)
    void TIM1_BRK_UP_TRG_COM_IRQHandler(void)
#endif
    {
        if (TIM1->DIER & TIM_DIER_UIE_Msk && TIM1->SR & TIM_SR_UIF_Msk)
        {
            TIM1->SR = ~TIM_SR_UIF_Msk;
            timer1.isrUpdate();
        }

#if defined(TIM1_CC1_ENABLE)
        if (TIM1->DIER & TIM_DIER_CC1IE_Msk && TIM1->SR & TIM_SR_CC1IF_Msk)
        {
            TIM1->SR = ~TIM_SR_CC1IF_Msk;
            timer1.isrCC1(true);
        }
#endif
#if defined(TIM1_CC2_ENABLE)
        if (TIM1->DIER & TIM_DIER_CC2IE_Msk && TIM1->SR & TIM_SR_CC2IF_Msk)
        {
            TIM1->SR = ~TIM_SR_CC2IF_Msk;
            timer1.isrCC2(true);
        }
#endif
#if defined(TIM1_CC3_ENABLE)
        if (TIM1->DIER & TIM_DIER_CC3IE_Msk && TIM1->SR & TIM_SR_CC3IF_Msk)
        {
            TIM1->SR = ~TIM_SR_CC3IF_Msk;
            timer1.isrCC3(true);
        }
#endif
#if defined(TIM1_CC4_ENABLE)
        if (TIM1->DIER & TIM_DIER_CC4IE_Msk && TIM1->SR & TIM_SR_CC4IF_Msk)
        {
            TIM1->SR = ~TIM_SR_CC4IF_Msk;
            timer1.isrCC4(true);
        }
#endif

#if defined(TIM10_ENABLE) && defined(TIM10)
#define TIM10_ISR_USED
#if defined(TIM10_CC1_ENABLE) || defined(TIM10_CC2_ENABLE) || defined(TIM10_CC3_ENABLE) || defined(TIM10_CC4_ENABLE)
        bool event10 = false;
#endif

        if (TIM10->DIER & TIM_DIER_UIE_Msk && TIM10->SR & TIM_SR_UIF_Msk)
        {
            TIM10->SR = ~TIM_SR_UIF_Msk;
            timer10.isrUpdate();
#if defined(TIM10_CC1_ENABLE) || defined(TIM10_CC2_ENABLE) || defined(TIM10_CC3_ENABLE) || defined(TIM10_CC4_ENABLE)
            event10 = true;
#endif
        }
#if defined(TIM10_CC1_ENABLE)
        if (TIM10->DIER & TIM_DIER_CC1IE_Msk && TIM10->SR & TIM_SR_CC1IF_Msk)
        {
            TIM10->SR = ~TIM_SR_CC1IF_Msk;
            timer10.isrCC1(event10);
        }
#endif
#if defined(TIM10_CC2_ENABLE)
        if (TIM10->DIER & TIM_DIER_CC2IE_Msk && TIM10->SR & TIM_SR_CC2IF_Msk)
        {
            TIM10->SR = ~TIM_SR_CC2IF_Msk;
            timer10.isrCC2(event10);
        }
#endif
#if defined(TIM10_CC3_ENABLE)
        if (TIM10->DIER & TIM_DIER_CC3IE_Msk && TIM10->SR & TIM_SR_CC3IF_Msk)
        {
            TIM10->SR = ~TIM_SR_CC3IF_Msk;
            timer10.isrCC3(event10);
        }
#endif
#if defined(TIM10_CC4_ENABLE)
        if (TIM10->DIER & TIM_DIER_CC4IE_Msk && TIM10->SR & TIM_SR_CC4IF_Msk)
        {
            TIM10->SR = ~TIM_SR_CC4IF_Msk;
            timer10.isrCC4(event10);
        }
#endif
#endif
    }

    void TIM1_CC_IRQHandler(void)
    {
#if defined(TIM1_CC1_ENABLE)
        if (TIM1->DIER & TIM_DIER_CC1IE_Msk && TIM1->SR & TIM_SR_CC1IF_Msk)
        {
            TIM1->SR = ~TIM_SR_CC1IF_Msk;
            timer1.isrCC1(false);
        }
#endif
#if defined(TIM1_CC2_ENABLE)
        if (TIM1->DIER & TIM_DIER_CC2IE_Msk && TIM1->SR & TIM_SR_CC2IF_Msk)
        {
            TIM1->SR = ~TIM_SR_CC2IF_Msk;
            timer1.isrCC2(false);
        }
#endif
#if defined(TIM1_CC3_ENABLE)
        if (TIM1->DIER & TIM_DIER_CC3IE_Msk && TIM1->SR & TIM_SR_CC3IF_Msk)
        {
            TIM1->SR = ~TIM_SR_CC3IF_Msk;
            timer1.isrCC3(false);
        }
#endif
#if defined(TIM1_CC4_ENABLE)
        if (TIM1->DIER & TIM_DIER_CC4IE_Msk && TIM1->SR & TIM_SR_CC4IF_Msk)
        {
            TIM1->SR = ~TIM_SR_CC4IF_Msk;
            timer1.isrCC4(false);
        }
#endif
    }
}
#endif

//********** Timer2 구성 설정 및 변수 선언 **********
#if defined(TIM2_ENABLE) && defined(TIM2)
static void setTim2ClockEn(bool en)
{
    clock.peripheral.setTimer2En(en);
}

static void setTim2IntEn(bool en)
{
    nvic.setTimer2En(en);
}

static void resetTim2(void)
{
//    clock.peripheral.resetTimer2();
}

drv::Timer timer2(TIM2, setTim2ClockEn, setTim2IntEn, resetTim2, getTimerApb1ClkFreq);

extern "C"
{
    void TIM2_IRQHandler(void)
    {
#if defined(TIM2_CC1_ENABLE) || defined(TIM2_CC2_ENABLE) || defined(TIM2_CC3_ENABLE) || defined(TIM2_CC4_ENABLE)
        bool event = false;
#endif

        if (TIM2->DIER & TIM_DIER_UIE_Msk && TIM2->SR & TIM_SR_UIF_Msk)
        {
            TIM2->SR = ~TIM_SR_UIF_Msk;
            timer2.isrUpdate();
#if defined(TIM2_CC1_ENABLE) || defined(TIM2_CC2_ENABLE) || defined(TIM2_CC3_ENABLE) || defined(TIM2_CC4_ENABLE)
            event = true;
#endif
        }
#if defined(TIM2_CC1_ENABLE)
        if (TIM2->DIER & TIM_DIER_CC1IE_Msk && TIM2->SR & TIM_SR_CC1IF_Msk)
        {
            TIM2->SR = ~TIM_SR_CC1IF_Msk;
            timer2.isrCC1(event);
        }
#endif
#if defined(TIM2_CC2_ENABLE)
        if (TIM2->DIER & TIM_DIER_CC2IE_Msk && TIM2->SR & TIM_SR_CC2IF_Msk)
        {
            TIM2->SR = ~TIM_SR_CC2IF_Msk;
            timer2.isrCC2(event);
        }
#endif
#if defined(TIM2_CC3_ENABLE)
        if (TIM2->DIER & TIM_DIER_CC3IE_Msk && TIM2->SR & TIM_SR_CC3IF_Msk)
        {
            TIM2->SR = ~TIM_SR_CC3IF_Msk;
            timer2.isrCC3(event);
        }
#endif
#if defined(TIM2_CC4_ENABLE)
        if (TIM2->DIER & TIM_DIER_CC4IE_Msk && TIM2->SR & TIM_SR_CC4IF_Msk)
        {
            TIM2->SR = ~TIM_SR_CC4IF_Msk;
            timer2.isrCC4(event);
        }
#endif
    }
}

#endif

#if defined(TIM3_ENABLE) && defined(TIM3)
static void setTim3ClockEn(bool en)
{
    clock.peripheral.setTimer3En(en);
}

static void setTim3IntEn(bool en)
{
    nvic.setTimer3En(en);
}

static void resetTim3(void)
{
//    clock.peripheral.resetTimer3();
}

drv::Timer timer3(TIM3, setTim3ClockEn, setTim3IntEn, resetTim3, getTimerApb1ClkFreq);

extern "C"
{
    void TIM3_IRQHandler(void)
    {
#if defined(TIM3_CC1_ENABLE) || defined(TIM3_CC2_ENABLE) || defined(TIM3_CC3_ENABLE) || defined(TIM3_CC4_ENABLE)
        bool event = false;
#endif
        if (TIM3->DIER & TIM_DIER_UIE_Msk && TIM3->SR & TIM_SR_UIF_Msk)
        {
            TIM3->SR = ~TIM_SR_UIF_Msk;
            timer3.isrUpdate();
#if defined(TIM3_CC1_ENABLE) || defined(TIM3_CC2_ENABLE) || defined(TIM3_CC3_ENABLE) || defined(TIM3_CC4_ENABLE)
            event = true;
#endif
        }
#if defined(TIM3_CC1_ENABLE)
        if (TIM3->DIER & TIM_DIER_CC1IE_Msk && TIM3->SR & TIM_SR_CC1IF_Msk)
        {
            TIM3->SR = ~TIM_SR_CC1IF_Msk;
            timer3.isrCC1(event);
        }
#endif
#if defined(TIM3_CC2_ENABLE)
        if (TIM3->DIER & TIM_DIER_CC2IE_Msk && TIM3->SR & TIM_SR_CC2IF_Msk)
        {
            TIM3->SR = ~TIM_SR_CC2IF_Msk;
            timer3.isrCC2(event);
        }
#endif
#if defined(TIM3_CC3_ENABLE)
        if (TIM3->DIER & TIM_DIER_CC3IE_Msk && TIM3->SR & TIM_SR_CC3IF_Msk)
        {
            TIM3->SR = ~TIM_SR_CC3IF_Msk;
            timer3.isrCC3(event);
        }
#endif
#if defined(TIM3_CC4_ENABLE)
        if (TIM3->DIER & TIM_DIER_CC4IE_Msk && TIM3->SR & TIM_SR_CC4IF_Msk)
        {
            TIM3->SR = ~TIM_SR_CC4IF_Msk;
            timer3.isrCC4(event);
        }
#endif
    }
}

#endif

#if defined(TIM4_ENABLE) && defined(TIM4)
static void setTim4ClockEn(bool en)
{
    clock.peripheral.setTimer4En(en);
}

static void setTim4IntEn(bool en)
{
    nvic.setTimer4En(en);
}

static void resetTim4(void)
{
//    clock.peripheral.resetTimer4();
}

drv::Timer timer4(TIM4, setTim4ClockEn, setTim4IntEn, resetTim4, getTimerApb1ClkFreq);

extern "C"
{
    void TIM4_IRQHandler(void)
    {
#if defined(TIM4_CC1_ENABLE) || defined(TIM4_CC2_ENABLE) || defined(TIM4_CC3_ENABLE) || defined(TIM4_CC4_ENABLE)
        bool event = false;
#endif

        if (TIM4->DIER & TIM_DIER_UIE_Msk && TIM4->SR & TIM_SR_UIF_Msk)
        {
            TIM4->SR = ~TIM_SR_UIF_Msk;
            timer4.isrUpdate();
#if defined(TIM4_CC1_ENABLE) || defined(TIM4_CC2_ENABLE) || defined(TIM4_CC3_ENABLE) || defined(TIM4_CC4_ENABLE)
            event = true;
#endif
        }
#if defined(TIM4_CC1_ENABLE)
        if (TIM4->DIER & TIM_DIER_CC1IE_Msk && TIM4->SR & TIM_SR_CC1IF_Msk)
        {
            TIM4->SR = ~TIM_SR_CC1IF_Msk;
            timer4.isrCC1(event);
        }
#endif
#if defined(TIM4_CC2_ENABLE)
        if (TIM4->DIER & TIM_DIER_CC2IE_Msk && TIM4->SR & TIM_SR_CC2IF_Msk)
        {
            TIM4->SR = ~TIM_SR_CC2IF_Msk;
            timer4.isrCC2(event);
        }
#endif
#if defined(TIM4_CC3_ENABLE)
        if (TIM4->DIER & TIM_DIER_CC3IE_Msk && TIM4->SR & TIM_SR_CC3IF_Msk)
        {
            TIM4->SR = ~TIM_SR_CC3IF_Msk;
            timer4.isrCC3(event);
        }
#endif
#if defined(TIM4_CC4_ENABLE)
        if (TIM4->DIER & TIM_DIER_CC4IE_Msk && TIM4->SR & TIM_SR_CC4IF_Msk)
        {
            TIM4->SR = ~TIM_SR_CC4IF_Msk;
            timer4.isrCC4(event);
        }
#endif
    }
}

#endif

#if defined(TIM5_ENABLE) && defined(TIM5)
static void setTim5ClockEn(bool en)
{
    clock.peripheral.setTimer5En(en);
}

static void setTim5IntEn(bool en)
{
    nvic.setTimer5En(en);
}

static void resetTim5(void)
{
//    clock.peripheral.resetTimer5();
}

drv::Timer timer5(TIM5, setTim5ClockEn, setTim5IntEn, resetTim5, getTimerApb1ClkFreq);

extern "C"
{
    void TIM5_IRQHandler(void)
    {
#if defined(TIM5_CC1_ENABLE) || defined(TIM5_CC2_ENABLE) || defined(TIM5_CC3_ENABLE) || defined(TIM5_CC4_ENABLE)
        bool event5 = false;
#endif

        if (TIM5->DIER & TIM_DIER_UIE_Msk && TIM5->SR & TIM_SR_UIF_Msk)
        {
            TIM5->SR = ~TIM_SR_UIF_Msk;
            timer5.isrUpdate();
#if defined(TIM5_CC1_ENABLE) || defined(TIM5_CC2_ENABLE) || defined(TIM5_CC3_ENABLE) || defined(TIM5_CC4_ENABLE)
			event5 = true;
#endif
        }
#if defined(TIM5_CC1_ENABLE)
        if (TIM5->DIER & TIM_DIER_CC1IE_Msk && TIM5->SR & TIM_SR_CC1IF_Msk)
        {
            TIM5->SR = ~TIM_SR_CC1IF_Msk;
            timer5.isrCC1();
        }
#endif
#if defined(TIM5_CC2_ENABLE)
        if (TIM5->DIER & TIM_DIER_CC2IE_Msk && TIM5->SR & TIM_SR_CC2IF_Msk)
        {
            TIM5->SR = ~TIM_SR_CC2IF_Msk;
            timer5.isrCC2();
        }
#endif
#if defined(TIM5_CC3_ENABLE)
        if (TIM5->DIER & TIM_DIER_CC3IE_Msk && TIM5->SR & TIM_SR_CC3IF_Msk)
        {
            TIM5->SR = ~TIM_SR_CC3IF_Msk;
            timer5.isrCC3();
        }
#endif
#if defined(TIM5_CC4_ENABLE)
        if (TIM5->DIER & TIM_DIER_CC4IE_Msk && TIM5->SR & TIM_SR_CC4IF_Msk)
        {
            TIM5->SR = ~TIM_SR_CC4IF_Msk;
            timer5.isrCC4(event5);
        }
#endif
    }
}

#endif

#if defined(TIM6_ENABLE) && defined(TIM6)
static void setTim6ClockEn(bool en)
{
    clock.peripheral.setTimer6En(en);
}

static void setTim6IntEn(bool en)
{
    nvic.setTimer6En(en);
}

static void resetTim6(void)
{
//    clock.peripheral.resetTimer6();
}

drv::Timer timer6(TIM6, setTim6ClockEn, setTim6IntEn, resetTim6, getTimerApb1ClkFreq);

extern "C"
{
    void TIM6_DAC_IRQHandler(void)
    {
        if (TIM6->DIER & TIM_DIER_UIE_Msk && TIM6->SR & TIM_SR_UIF_Msk)
        {
            TIM6->SR = ~TIM_SR_UIF_Msk;
            timer6.isrUpdate();
        }
#if defined(TIM6_CC1_ENABLE)
        if (TIM6->DIER & TIM_DIER_CC1IE_Msk && TIM6->SR & TIM_SR_CC1IF_Msk)
        {
            TIM6->SR = ~TIM_SR_CC1IF_Msk;
            timer2.isrCC1();
        }
#endif
#if defined(TIM6_CC2_ENABLE)
        if (TIM6->DIER & TIM_DIER_CC2IE_Msk && TIM6->SR & TIM_SR_CC2IF_Msk)
        {
            TIM6->SR = ~TIM_SR_CC2IF_Msk;
            timer6.isrCC2();
        }
#endif
#if defined(TIM6_CC3_ENABLE)
        if (TIM6->DIER & TIM_DIER_CC3IE_Msk && TIM6->SR & TIM_SR_CC3IF_Msk)
        {
            TIM6->SR = ~TIM_SR_CC3IF_Msk;
            timer6.isrCC3();
        }
#endif
#if defined(TIM6_CC4_ENABLE)
        if (TIM6->DIER & TIM_DIER_CC4IE_Msk && TIM6->SR & TIM_SR_CC4IF_Msk)
        {
            TIM6->SR = ~TIM_SR_CC4IF_Msk;
            timer6.isrCC4();
        }
#endif
    }
}

#endif

#if defined(TIM7_ENABLE) && defined(TIM7)
static void setTim7ClockEn(bool en)
{
    clock.peripheral.setTimer7En(en);
}

static void setTim7IntEn(bool en)
{
    nvic.setTimer7En(en);
}

static void resetTim7(void)
{
//    clock.peripheral.resetTimer7();
}

drv::Timer timer7(TIM7, setTim7ClockEn, setTim7IntEn, resetTim7, getTimerApb1ClkFreq);

extern "C"
{
    void TIM7_IRQHandler(void)
    {
        if (TIM7->DIER & TIM_DIER_UIE_Msk && TIM7->SR & TIM_SR_UIF_Msk)
        {
            TIM7->SR = ~TIM_SR_UIF_Msk;
            timer7.isrUpdate();
        }
#if defined(TIM7_CC1_ENABLE)
        if (TIM7->DIER & TIM_DIER_CC1IE_Msk && TIM7->SR & TIM_SR_CC1IF_Msk)
        {
            TIM7->SR = ~TIM_SR_CC1IF_Msk;
            timer7.isrCC1();
        }
#endif
#if defined(TIM7_CC2_ENABLE)
        if (TIM7->DIER & TIM_DIER_CC2IE_Msk && TIM7->SR & TIM_SR_CC2IF_Msk)
        {
            TIM7->SR = ~TIM_SR_CC2IF_Msk;
            timer7.isrCC2();
        }
#endif
#if defined(TIM7_CC3_ENABLE)
        if (TIM7->DIER & TIM_DIER_CC3IE_Msk && TIM7->SR & TIM_SR_CC3IF_Msk)
        {
            TIM7->SR = ~TIM_SR_CC3IF_Msk;
            timer7.isrCC3();
        }
#endif
#if defined(TIM7_CC4_ENABLE)
        if (TIM7->DIER & TIM_DIER_CC4IE_Msk && TIM7->SR & TIM_SR_CC4IF_Msk)
        {
            TIM7->SR = ~TIM_SR_CC4IF_Msk;
            timer7.isrCC4();
        }
#endif
    }
}

#endif

#if defined(TIM8_ENABLE) && defined(TIM8)
static void setTim8ClockEn(bool en)
{
    clock.peripheral.setTimer8En(en);
}

static void setTim8IntEn(bool en)
{
    nvic.setTimer8En(en);
}

static void resetTim8(void)
{
//    clock.peripheral.resetTimer8();
}

drv::Timer timer8(TIM8, setTim8ClockEn, setTim8IntEn, resetTim8, getTimerApb2ClkFreq);

extern "C"
{
    void TIM8_UP_TIM13_IRQHandler(void)
    {
        if (TIM8->DIER & TIM_DIER_UIE_Msk && TIM8->SR & TIM_SR_UIF_Msk)
        {
            TIM8->SR = ~TIM_SR_UIF_Msk;
            timer8.isrUpdate();
        }
#if defined(TIM8_CC1_ENABLE)
        if (TIM8->DIER & TIM_DIER_CC1IE_Msk && TIM8->SR & TIM_SR_CC1IF_Msk)
        {
            TIM8->SR = ~TIM_SR_CC1IF_Msk;
            timer8.isrCC1();
        }
#endif
#if defined(TIM8_CC2_ENABLE)
        if (TIM8->DIER & TIM_DIER_CC2IE_Msk && TIM8->SR & TIM_SR_CC2IF_Msk)
        {
            TIM8->SR = ~TIM_SR_CC2IF_Msk;
            timer8.isrCC2();
        }
#endif
#if defined(TIM8_CC3_ENABLE)
        if (TIM8->DIER & TIM_DIER_CC3IE_Msk && TIM8->SR & TIM_SR_CC3IF_Msk)
        {
            TIM8->SR = ~TIM_SR_CC3IF_Msk;
            timer8.isrCC3();
        }
#endif
#if defined(TIM8_CC4_ENABLE)
        if (TIM8->DIER & TIM_DIER_CC4IE_Msk && TIM8->SR & TIM_SR_CC4IF_Msk)
        {
            TIM8->SR = ~TIM_SR_CC4IF_Msk;
            timer8.isrCC4();
        }
#endif

#if defined(TIM13_ENABLE) && defined(TIM13)
#define TIM13_ISR_USED
        if (TIM13->DIER & TIM_DIER_UIE_Msk && TIM13->SR & TIM_SR_UIF_Msk)
        {
            TIM13->SR = ~TIM_SR_UIF_Msk;
            timer13.isrUpdate();
        }
#if defined(TIM13_CC1_ENABLE)
        if (TIM13->DIER & TIM_DIER_CC1IE_Msk && TIM13->SR & TIM_SR_CC1IF_Msk)
        {
            TIM13->SR = ~TIM_SR_CC1IF_Msk;
            timer13.isrCC1();
        }
#endif
#if defined(TIM13_CC2_ENABLE)
        if (TIM13->DIER & TIM_DIER_CC2IE_Msk && TIM13->SR & TIM_SR_CC2IF_Msk)
        {
            TIM13->SR = ~TIM_SR_CC2IF_Msk;
            timer13.isrCC2();
        }
#endif
#if defined(TIM13_CC3_ENABLE)
        if (TIM13->DIER & TIM_DIER_CC3IE_Msk && TIM13->SR & TIM_SR_CC3IF_Msk)
        {
            TIM13->SR = ~TIM_SR_CC3IF_Msk;
            timer13.isrCC3();
        }
#endif
#if defined(TIM13_CC4_ENABLE)
        if (TIM13->DIER & TIM_DIER_CC4IE_Msk && TIM13->SR & TIM_SR_CC4IF_Msk)
        {
            TIM13->SR = ~TIM_SR_CC4IF_Msk;
            timer13.isrCC4();
        }
#endif
#endif
    }
}

#endif

#if defined(TIM9_ENABLE) && defined(TIM9)
static void setTim9ClockEn(bool en)
{
    clock.peripheral.setTimer9En(en);
}

static void setTim9IntEn(bool en)
{
    nvic.setTimer9En(en);
}

static void resetTim9(void)
{
//    clock.peripheral.resetTimer9();
}

drv::Timer timer9(TIM9, setTim9ClockEn, setTim9IntEn, resetTim9, getTimerApb2ClkFreq);

extern "C"
{
    void TIM1_BRK_TIM9_IRQHandler(void)
    {
        if (TIM9->DIER & TIM_DIER_UIE_Msk && TIM9->SR & TIM_SR_UIF_Msk)
        {
            TIM9->SR = ~TIM_SR_UIF_Msk;
            timer9.isrUpdate();
        }
#if defined(TIM9_CC1_ENABLE)
        if (TIM9->DIER & TIM_DIER_CC1IE_Msk && TIM9->SR & TIM_SR_CC1IF_Msk)
        {
            TIM9->SR = ~TIM_SR_CC1IF_Msk;
            timer9.isrCC1();
        }
#endif
#if defined(TIM9_CC2_ENABLE)
        if (TIM9->DIER & TIM_DIER_CC2IE_Msk && TIM9->SR & TIM_SR_CC2IF_Msk)
        {
            TIM9->SR = ~TIM_SR_CC2IF_Msk;
            timer9.isrCC2();
        }
#endif
#if defined(TIM9_CC3_ENABLE)
        if (TIM9->DIER & TIM_DIER_CC3IE_Msk && TIM9->SR & TIM_SR_CC3IF_Msk)
        {
            TIM9->SR = ~TIM_SR_CC3IF_Msk;
            timer9.isrCC3();
        }
#endif
#if defined(TIM9_CC4_ENABLE)
        if (TIM9->DIER & TIM_DIER_CC4IE_Msk && TIM9->SR & TIM_SR_CC4IF_Msk)
        {
            TIM9->SR = ~TIM_SR_CC4IF_Msk;
            timer9.isrCC4();
        }
#endif
    }
}

#endif

#if defined(TIM10_ENABLE) && defined(TIM10)
static void setTim10ClockEn(bool en)
{
    clock.peripheral.setTimer9En(en);
}

static void setTim10IntEn(bool en)
{
    nvic.setTimer10En(en);
}

static void resetTim10(void)
{
//    clock.peripheral.resetTimer10();
}

drv::Timer timer10(TIM10, setTim10ClockEn, setTim10IntEn, resetTim10, getTimerApb2ClkFreq);

#ifndef TIM10_ISR_USED

void TIM1_UP_TIM10_IRQHandler(void)
{
    if (TIM10->DIER & TIM_DIER_UIE_Msk && TIM10->SR & TIM_SR_UIF_Msk)
    {
        TIM10->SR = ~TIM_SR_UIF_Msk;
        timer10.isrUpdate();
    }
#if defined(TIM10_CC1_ENABLE)
    if (TIM10->DIER & TIM_DIER_CC1IE_Msk && TIM10->SR & TIM_SR_CC1IF_Msk)
    {
        TIM10->SR = ~TIM_SR_CC1IF_Msk;
        timer10.isrCC1();
    }
#endif
#if defined(TIM10_CC2_ENABLE)
    if (TIM10->DIER & TIM_DIER_CC2IE_Msk && TIM10->SR & TIM_SR_CC2IF_Msk)
    {
        TIM10->SR = ~TIM_SR_CC2IF_Msk;
        timer10.isrCC2();
    }
#endif
#if defined(TIM10_CC3_ENABLE)
    if (TIM10->DIER & TIM_DIER_CC3IE_Msk && TIM10->SR & TIM_SR_CC3IF_Msk)
    {
        TIM10->SR = ~TIM_SR_CC3IF_Msk;
        timer10.isrCC3();
    }
#endif
#if defined(TIM10_CC4_ENABLE)
    if (TIM10->DIER & TIM_DIER_CC4IE_Msk && TIM10->SR & TIM_SR_CC4IF_Msk)
    {
        TIM10->SR = ~TIM_SR_CC4IF_Msk;
        timer10.isrCC4();
    }
#endif
}

#endif

#endif

#if defined(TIM11_ENABLE) && defined(TIM11)
static void setTim11ClockEn(bool en)
{
    clock.peripheral.setTimer11En(en);
}

static void setTim11IntEn(bool en)
{
    nvic.setTimer11En(en);
}

static void resetTim11(void)
{
//    clock.peripheral.resetTimer11();
}


drv::Timer timer11(TIM11, setTim11ClockEn, setTim11IntEn, resetTim11, getTimerApb2ClkFreq);

extern "C"
{
    void TIM1_TRG_COM_TIM11_IRQHandler(void)
    {
        if (TIM11->DIER & TIM_DIER_UIE_Msk && TIM11->SR & TIM_SR_UIF_Msk)
        {
            TIM11->SR = ~TIM_SR_UIF_Msk;
            timer11.isrUpdate();
        }
#if defined(TIM11_CC1_ENABLE)
        if (TIM11->DIER & TIM_DIER_CC1IE_Msk && TIM11->SR & TIM_SR_CC1IF_Msk)
        {
            TIM11->SR = ~TIM_SR_CC1IF_Msk;
            timer11.isrCC1();
        }
#endif
#if defined(TIM11_CC2_ENABLE)
        if (TIM11->DIER & TIM_DIER_CC2IE_Msk && TIM11->SR & TIM_SR_CC2IF_Msk)
        {
            TIM11->SR = ~TIM_SR_CC2IF_Msk;
            timer11.isrCC2();
        }
#endif
#if defined(TIM11_CC3_ENABLE)
        if (TIM11->DIER & TIM_DIER_CC3IE_Msk && TIM11->SR & TIM_SR_CC3IF_Msk)
        {
            TIM11->SR = ~TIM_SR_CC3IF_Msk;
            timer11.isrCC3();
        }
#endif
#if defined(TIM11_CC4_ENABLE)
        if (TIM11->DIER & TIM_DIER_CC4IE_Msk && TIM11->SR & TIM_SR_CC4IF_Msk)
        {
            TIM11->SR = ~TIM_SR_CC4IF_Msk;
            timer11.isrCC4();
        }
#endif
    }
}

#endif

#if defined(TIM12_ENABLE) && defined(TIM12)
static void setTim12ClockEn(bool en)
{
    clock.peripheral.setTimer12En(en);
}

static void setTim12IntEn(bool en)
{
    nvic.setTimer12En(en);
}

static void resetTim12(void)
{
//    clock.peripheral.resetTimer12();
}

drv::Timer timer12(TIM12, setTim12ClockEn, setTim12IntEn, resetTim12, getTimerApb1ClkFreq);

extern "C"
{
    void TIM8_BRK_TIM12_IRQHandler(void)
    {
        if (TIM12->DIER & TIM_DIER_UIE_Msk && TIM12->SR & TIM_SR_UIF_Msk)
        {
            TIM12->SR = ~TIM_SR_UIF_Msk;
            timer12.isrUpdate();
        }
#if defined(TIM12_CC1_ENABLE)
        if (TIM12->DIER & TIM_DIER_CC1IE_Msk && TIM12->SR & TIM_SR_CC1IF_Msk)
        {
            TIM12->SR = ~TIM_SR_CC1IF_Msk;
            timer12.isrCC1();
        }
#endif
#if defined(TIM12_CC2_ENABLE)
        if (TIM12->DIER & TIM_DIER_CC2IE_Msk && TIM12->SR & TIM_SR_CC2IF_Msk)
        {
            TIM12->SR = ~TIM_SR_CC2IF_Msk;
            timer12.isrCC2();
        }
#endif
#if defined(TIM12_CC3_ENABLE)
        if (TIM12->DIER & TIM_DIER_CC3IE_Msk && TIM12->SR & TIM_SR_CC3IF_Msk)
        {
            TIM12->SR = ~TIM_SR_CC3IF_Msk;
            timer12.isrCC3();
        }
#endif
#if defined(TIM12_CC4_ENABLE)
        if (TIM12->DIER & TIM_DIER_CC4IE_Msk && TIM12->SR & TIM_SR_CC4IF_Msk)
        {
            TIM12->SR = ~TIM_SR_CC4IF_Msk;
            timer12.isrCC4();
        }
#endif
    }
}

#endif

#if defined(TIM13_ENABLE) && defined(TIM13)
static void setTim13ClockEn(bool en)
{
    clock.peripheral.setTimer13En(en);
}

static void setTim13IntEn(bool en)
{
    nvic.setTimer13En(en);
}

static void resetTim13(void)
{
//    clock.peripheral.resetTimer13();
}

drv::Timer timer13(TIM13, setTim13ClockEn, setTim13IntEn, resetTim13, getTimerApb1ClkFreq);

#ifndef TIM13_ISR_USED

extern "C"
{
    void TIM8_UP_TIM13_IRQHandler(void)
    {
        if (TIM13->DIER & TIM_DIER_UIE_Msk && TIM13->SR & TIM_SR_UIF_Msk)
        {
            TIM13->SR = ~TIM_SR_UIF_Msk;
            timer13.isrUpdate();
        }
#if defined(TIM13_CC1_ENABLE)
        if (TIM13->DIER & TIM_DIER_CC1IE_Msk && TIM13->SR & TIM_SR_CC1IF_Msk)
        {
            TIM13->SR = ~TIM_SR_CC1IF_Msk;
            timer13.isrCC1();
        }
#endif
#if defined(TIM13_CC2_ENABLE)
        if (TIM13->DIER & TIM_DIER_CC2IE_Msk && TIM13->SR & TIM_SR_CC2IF_Msk)
        {
            TIM13->SR = ~TIM_SR_CC2IF_Msk;
            timer13.isrCC2();
        }
#endif
#if defined(TIM13_CC3_ENABLE)
        if (TIM13->DIER & TIM_DIER_CC3IE_Msk && TIM13->SR & TIM_SR_CC3IF_Msk)
        {
            TIM13->SR = ~TIM_SR_CC3IF_Msk;
            timer10.isrCC3();
        }
#endif
#if defined(TIM13_CC4_ENABLE)
        if (TIM13->DIER & TIM_DIER_CC4IE_Msk && TIM13->SR & TIM_SR_CC4IF_Msk)
        {
            TIM13->SR = ~TIM_SR_CC4IF_Msk;
            timer13.isrCC4();
        }
#endif
    }
}

#endif

#endif

#if defined(TIM14_ENABLE) && defined(TIM14)
static void setTim14ClockEn(bool en)
{
    clock.peripheral.setTimer14En(en);
}

static void setTim14IntEn(bool en)
{
    nvic.setTimer14En(en);
}

static void resetTim14(void)
{
//    clock.peripheral.resetTimer14();
}

drv::Timer timer14(TIM14, setTim14ClockEn, setTim14IntEn, resetTim14, getTimerApb1ClkFreq);

extern "C"
{
#if defined(STM32F0)
    void TIM14_IRQHandler(void)
#else
    void TIM8_TRG_COM_TIM14_IRQHandler(void)
#endif
    {
        if (TIM14->DIER & TIM_DIER_UIE_Msk && TIM14->SR & TIM_SR_UIF_Msk)
        {
            TIM14->SR = ~TIM_SR_UIF_Msk;
            timer14.isrUpdate();
        }
#if defined(TIM14_CC1_ENABLE)
        if (TIM14->DIER & TIM_DIER_CC1IE_Msk && TIM14->SR & TIM_SR_CC1IF_Msk)
        {
            TIM14->SR = ~TIM_SR_CC1IF_Msk;
            timer14.isrCC1();
        }
#endif
#if defined(TIM14_CC2_ENABLE)
        if (TIM14->DIER & TIM_DIER_CC2IE_Msk && TIM14->SR & TIM_SR_CC2IF_Msk)
        {
            TIM14->SR = ~TIM_SR_CC2IF_Msk;
            timer14.isrCC2();
        }
#endif
#if defined(TIM14_CC3_ENABLE)
        if (TIM14->DIER & TIM_DIER_CC3IE_Msk && TIM14->SR & TIM_SR_CC3IF_Msk)
        {
            TIM14->SR = ~TIM_SR_CC3IF_Msk;
            timer14.isrCC3();
        }
#endif
#if defined(TIM14_CC4_ENABLE)
        if (TIM14->DIER & TIM_DIER_CC4IE_Msk && TIM14->SR & TIM_SR_CC4IF_Msk)
        {
            TIM14->SR = ~TIM_SR_CC4IF_Msk;
            timer14.isrCC4();
        }
#endif
    }
}

#endif

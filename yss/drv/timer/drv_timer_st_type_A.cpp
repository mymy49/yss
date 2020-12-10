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

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) ||                                                 \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                                                                 \
    defined(STM32F429xx) || defined(STM32F439xx) ||                                                                                                 \
    defined(STM32F100xB) || defined(STM32F100xE) ||                                                                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) ||                                                 \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) ||                                                 \
    defined(STM32F105xC) ||                                                                                                                         \
    defined(STM32F107xC) ||                                                                                                                         \
    defined(STM32G431xx) || defined(STM32G441xx) ||                                                                                                 \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB) || \
    defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) ||                                                 \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                                                                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                                                                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                                                                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

#include <__cross_studio_io.h>

#include <drv/peripherals.h>
#include <drv/timer/drv_st_timer_type_A_register.h>

static unsigned int getTimerApb2ClkFreq(void)
{
    return clock.getTimerApb2ClkFreq();
}

static unsigned int getTimerApb1ClkFreq(void)
{
    return clock.getTimerApb1ClkFreq();
}

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

drv::Timer timer1(TIM1, setTim1ClockEn, setTim1IntEn, getTimerApb2ClkFreq);

extern "C"
{
#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx) ||                                                 \
    defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)

    void TIM1_UP_TIM10_IRQHandler(void)
#elif defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)
    void TIM1_UP_TIM16_IRQHandler(void)
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

drv::Timer timer2(TIM2, setTim2ClockEn, setTim2IntEn, getTimerApb1ClkFreq);

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

drv::Timer timer3(TIM3, setTim3ClockEn, setTim3IntEn, getTimerApb1ClkFreq);

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

drv::Timer timer4(TIM4, setTim4ClockEn, setTim4IntEn, getTimerApb1ClkFreq);

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

drv::Timer timer5(TIM5, setTim5ClockEn, setTim5IntEn, getTimerApb1ClkFreq);

extern "C"
{
    void TIM5_IRQHandler(void)
    {
        if (TIM5->DIER & TIM_DIER_UIE_Msk && TIM5->SR & TIM_SR_UIF_Msk)
        {
            TIM5->SR = ~TIM_SR_UIF_Msk;
            timer5.isrUpdate();
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
            timer5.isrCC4();
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

drv::Timer timer6(TIM6, setTim6ClockEn, setTim6IntEn, getTimerApb1ClkFreq);

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

drv::Timer timer7(TIM7, setTim7ClockEn, setTim7IntEn, getTimerApb1ClkFreq);

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

drv::Timer timer8(TIM8, setTim8ClockEn, setTim8IntEn, getTimerApb2ClkFreq);

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

drv::Timer timer9(TIM9, setTim9ClockEn, setTim9IntEn, getTimerApb2ClkFreq);

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

drv::Timer timer10(TIM10, setTim10ClockEn, setTim10IntEn, getTimerApb2ClkFreq);

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

drv::Timer timer11(TIM11, setTim11ClockEn, setTim11IntEn, getTimerApb2ClkFreq);

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

drv::Timer timer12(TIM12, setTim12ClockEn, setTim12IntEn, getTimerApb1ClkFreq);

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

drv::Timer timer13(TIM13, setTim13ClockEn, setTim13IntEn, getTimerApb1ClkFreq);

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

drv::Timer timer14(TIM14, setTim14ClockEn, setTim14IntEn, getTimerApb1ClkFreq);

extern "C"
{
    void TIM8_TRG_COM_TIM14_IRQHandler(void)
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

namespace drv
{
Timer::Timer(TIM_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc)
{
    mPeri = peri;
    mGetClockFreq = getClockFreq;
    mIsrUpdate = 0;
    mTimeUpdateCnt = 0;
    mIsrInputCapture1 = 0;
    mIsrInputCapture2 = 0;
    mIsrInputCapture3 = 0;
    mIsrInputCapture4 = 0;
}

void Timer::initSystemTime(void)
{
    mPeri->PSC = (unsigned short)(getClockFreq() / 1000000) - 1;
    mPeri->ARR = 60000;
    mPeri->CNT = 60000;
    mPeri->DIER |= TIM_DIER_UIE_Msk;
}

void Timer::init(unsigned int psc, unsigned int arr)
{
    mPeri->PSC = (unsigned short)psc;
    mPeri->ARR = (unsigned short)arr;
}

void Timer::init(unsigned int freq)
{
    unsigned int psc, arr, clk = getClockFreq();

    arr = clk / freq;
    psc = arr / (0xffff + 1);
    arr /= psc + 1;

    mPeri->PSC = psc;
    mPeri->ARR = arr;
}

void Timer::setUpdateIntEn(bool en)
{
    if (en)
        mPeri->DIER |= TIM_DIER_UIE_Msk;
    else
        mPeri->DIER &= ~TIM_DIER_UIE_Msk;
}

void Timer::setCC1IntEn(bool en)
{
    if (en)
        mPeri->DIER |= TIM_DIER_CC1IE_Msk;
    else
        mPeri->DIER &= ~TIM_DIER_CC1IE_Msk;
}

void Timer::setCC2IntEn(bool en)
{
    if (en)
        mPeri->DIER |= TIM_DIER_CC2IE_Msk;
    else
        mPeri->DIER &= ~TIM_DIER_CC2IE_Msk;
}

void Timer::setCC3IntEn(bool en)
{
    if (en)
        mPeri->DIER |= TIM_DIER_CC3IE_Msk;
    else
        mPeri->DIER &= ~TIM_DIER_CC3IE_Msk;
}

void Timer::setCC4IntEn(bool en)
{
    if (en)
        mPeri->DIER |= TIM_DIER_CC4IE_Msk;
    else
        mPeri->DIER &= ~TIM_DIER_CC4IE_Msk;
}

void Timer::start(void)
{
    mPeri->CR1 |= TIM_CR1_CEN_Msk;
}

void Timer::stop(void)
{
    mPeri->CR1 &= ~TIM_CR1_CEN_Msk;
}

void Timer::setOnePulse(bool en)
{
    if (en)
        mPeri->CR1 |= TIM_CR1_OPM_Msk;
    else
        mPeri->CR1 &= ~TIM_CR1_OPM_Msk;
}

void Timer::initInputCaptureCh1(unsigned char option)
{
    mPeri->CCMR1 = (1 << TIM_CCMR1_CC1S_Pos) | (2 << TIM_CCMR1_IC1F_Pos);

    if (option & define::timer::inputCapture::RISING_EDGE)
        mPeri->CCER &= TIM_CCER_CC1P_Msk;
    else
        mPeri->CCER |= TIM_CCER_CC1P_Msk;

    mPeri->CCER |= TIM_CCER_CC1E_Msk;
}

void Timer::initInputCaptureCh2(unsigned char option)
{
    mPeri->CCMR1 = (1 << TIM_CCMR1_CC2S_Pos) | (2 << TIM_CCMR1_IC2F_Pos);

    if (option & define::timer::inputCapture::RISING_EDGE)
        mPeri->CCER &= TIM_CCER_CC2P_Msk;
    else
        mPeri->CCER |= TIM_CCER_CC2P_Msk;

    mPeri->CCER |= TIM_CCER_CC2E_Msk;
}

void Timer::initInputCaptureCh3(unsigned char option)
{
    mPeri->CCMR2 = (1 << TIM_CCMR2_CC3S_Pos) | (2 << TIM_CCMR2_IC3F_Pos);

    if (option & define::timer::inputCapture::RISING_EDGE)
        mPeri->CCER &= TIM_CCER_CC3P_Msk;
    else
        mPeri->CCER |= TIM_CCER_CC3P_Msk;

    mPeri->CCER |= TIM_CCER_CC3E_Msk;
}

void Timer::initInputCaptureCh4(unsigned char option)
{
    mPeri->CCMR2 = (1 << TIM_CCMR2_CC4S_Pos) | (2 << TIM_CCMR2_IC4F_Pos);

    if (option & define::timer::inputCapture::RISING_EDGE)
        mPeri->CCER &= TIM_CCER_CC4P_Msk;
    else
        mPeri->CCER |= TIM_CCER_CC4P_Msk;

    mPeri->CCER |= TIM_CCER_CC4E_Msk;
}

void Timer::initPwmCh1(bool risingAtMatch)
{
#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
#else
    setTimMainOutputEn(mPeri, true);
#endif
    setTimCc1s(mPeri, 0);
    setTimOc1pe(mPeri, 0);
    setTimOc1fe(mPeri, 1);
    setTimCc1e(mPeri, 1);
    if (risingAtMatch)
        setTimOc1m(mPeri, 6);
    else
        setTimOc1m(mPeri, 7);
}

void Timer::initPwmCh2(bool risingAtMatch)
{
#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
#else
    setTimMainOutputEn(mPeri, true);
#endif
    setTimCc2s(mPeri, 0);
    setTimOc2pe(mPeri, 0);
    setTimOc2fe(mPeri, 1);
    setTimCc2e(mPeri, 1);
    if (risingAtMatch)
        setTimOc2m(mPeri, 6);
    else
        setTimOc2m(mPeri, 7);
}

void Timer::initPwmCh3(bool risingAtMatch)
{
#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
#else
    setTimMainOutputEn(mPeri, true);
#endif
    setTimCc3s(mPeri, 0);
    setTimOc3pe(mPeri, 0);
    setTimOc3fe(mPeri, 1);
    setTimCc3e(mPeri, 1);
    if (risingAtMatch)
        setTimOc3m(mPeri, 6);
    else
        setTimOc3m(mPeri, 7);
}

void Timer::initPwmCh4(bool risingAtMatch)
{
#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
#else
    setTimMainOutputEn(mPeri, true);
#endif
    setTimCc4s(mPeri, 0);
    setTimOc4pe(mPeri, 0);
    setTimOc4fe(mPeri, 1);
    setTimCc4e(mPeri, 1);
    if (risingAtMatch)
        setTimOc4m(mPeri, 6);
    else
        setTimOc4m(mPeri, 7);
}

void Timer::setPwmCh1(float ratio)
{
    mPeri->CCR1 = (unsigned short)((float)mPeri->ARR * ratio);
}

void Timer::setPwmCh2(float ratio)
{
    mPeri->CCR2 = (unsigned short)((float)mPeri->ARR * ratio);
}

void Timer::setPwmCh3(float ratio)
{
    mPeri->CCR3 = (unsigned short)((float)mPeri->ARR * ratio);
}

void Timer::setPwmCh4(float ratio)
{
    mPeri->CCR4 = (unsigned short)((float)mPeri->ARR * ratio);
}

unsigned int Timer::getCounterValue(void)
{
    return getTimCnt(mPeri);
}

unsigned int Timer::getOverFlowCount(void)
{
    return 60000;
}

unsigned int drv::Timer::getClockFreq(void)
{
    return mGetClockFreq();
}

void drv::Timer::setUpdateIsr(void (*isr)(void))
{
    mIsrUpdate = isr;
}

void drv::Timer::setInputCapture1Isr(void (*isr)(unsigned int cnt, unsigned long long acc))
{
    mIsrInputCapture1 = isr;
}

void drv::Timer::setInputCapture2Isr(void (*isr)(unsigned int cnt, unsigned long long acc))
{
    mIsrInputCapture2 = isr;
}

void drv::Timer::setInputCapture3Isr(void (*isr)(unsigned int cnt, unsigned long long acc))
{
    mIsrInputCapture3 = isr;
}

void drv::Timer::setInputCapture4Isr(void (*isr)(unsigned int cnt, unsigned long long acc))
{
    mIsrInputCapture4 = isr;
}

void drv::Timer::isrCC1(bool event)
{
    signed int cnt, ccr = (signed int)mPeri->CCR1;
    unsigned long long accCnt;

    cnt = (signed int)(mTimeUpdateCnt - mLastUpdateCnt1);

    if (event)
    {
        if ((unsigned int)ccr > (unsigned int)mLastCcr1)
        {
            mLastUpdateCnt1 = mTimeUpdateCnt - 1;
            cnt--;
        }
        else
            mLastUpdateCnt1 = mTimeUpdateCnt;
    }
    else
        mLastUpdateCnt1 = mTimeUpdateCnt;

    cnt = cnt * 65536;
    cnt += ccr - mLastCcr1;
    mLastCcr1 = ccr;

    accCnt = mLastUpdateCnt1 * 65536 + ccr;

    if (mIsrInputCapture1)
        mIsrInputCapture1(cnt, accCnt);
}

void drv::Timer::isrCC2(bool event)
{
    signed int cnt, ccr = (signed int)mPeri->CCR2;
    unsigned long long accCnt;

    cnt = (signed int)(mTimeUpdateCnt - mLastUpdateCnt2);

    if (event)
    {
        if ((unsigned int)ccr > (unsigned int)mLastCcr2)
        {
            mLastUpdateCnt2 = mTimeUpdateCnt - 1;
            cnt--;
        }
        else
            mLastUpdateCnt2 = mTimeUpdateCnt;
    }
    else
        mLastUpdateCnt2 = mTimeUpdateCnt;

    cnt = cnt * 65536;
    cnt += ccr - mLastCcr2;
    mLastCcr2 = ccr;

    accCnt = mLastUpdateCnt2 * 65536 + ccr;

    if (mIsrInputCapture2)
        mIsrInputCapture2(cnt, accCnt);
}

void drv::Timer::isrCC3(bool event)
{
    signed int cnt, ccr = (signed int)mPeri->CCR3;

    cnt = (signed int)(mTimeUpdateCnt - mLastUpdateCnt3);

    if (event)
    {
        if ((unsigned int)ccr > (unsigned int)mLastCcr3)
        {
            mLastUpdateCnt3 = mTimeUpdateCnt - 1;
            cnt--;
        }
        else
            mLastUpdateCnt3 = mTimeUpdateCnt;
    }
    else
        mLastUpdateCnt3 = mTimeUpdateCnt;

    cnt = cnt * 65536;
    cnt += ccr - mLastCcr3;

    mLastCcr3 = ccr;

    if (mIsrInputCapture3)
        mIsrInputCapture3(cnt, 0);
}

void drv::Timer::isrCC4(bool event)
{
    signed int cnt, ccr = (signed int)mPeri->CCR4;

    cnt = (signed int)(mTimeUpdateCnt - mLastUpdateCnt4);

    if (event)
    {
        if ((unsigned int)ccr > (unsigned int)mLastCcr4)
        {
            mLastUpdateCnt4 = mTimeUpdateCnt - 1;
            cnt--;
        }
        else
            mLastUpdateCnt4 = mTimeUpdateCnt;
    }
    else
        mLastUpdateCnt4 = mTimeUpdateCnt;

    cnt = cnt * 65536;
    cnt += ccr - mLastCcr4;

    mLastCcr4 = ccr;

    if (mIsrInputCapture4)
        mIsrInputCapture4(cnt, 0);
}

unsigned long long drv::Timer::getCaptureUpdateCntCh1(void)
{
    unsigned long long buf = mLastUpdateCnt1;
    buf *= 65536;
    buf += mLastCcr1;
    return buf;
}

unsigned long long drv::Timer::getCaptureUpdateCntCh2(void)
{
    unsigned long long buf = mLastUpdateCnt2;
    buf *= 65536;
    buf += mLastCcr2;
    return buf;
}

unsigned long long drv::Timer::getCaptureUpdateCntCh3(void)
{
    unsigned long long buf = mLastUpdateCnt3;
    buf *= 65536;
    buf += mLastCcr3;
    return buf;
}

unsigned long long drv::Timer::getCaptureUpdateCntCh4(void)
{
    unsigned long long buf = mLastUpdateCnt4;
    buf *= 65536;
    buf += mLastCcr4;
    return buf;
}

void drv::Timer::isrUpdate(void)
{
    if (mIsrUpdate)
        mIsrUpdate();
    mTimeUpdateCnt++;
}

}
#endif
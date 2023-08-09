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

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <yss/instance.h>
#include <config.h>
#include <targets/nordic/nrf52840_bitfields.h>

static uint32_t  getFrequency(void)
{
	return clock.getSystemClockFrequency();
}

#if defined(TIM0_ENABLE) && defined(NRF_TIMER0)
static void enableInterruptTim0(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(TIMER0_IRQn);
	nvic.unlock();
}

static const Drv::Config gDrvTimer0Config
{
	0,						//void (*clockFunc)(bool en);
	enableInterruptTim0,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getFrequency			//uint32_t (*getClockFunc)(void);
};

Timer timer0(NRF_TIMER0, gDrvTimer0Config);

extern "C"
{
void TIMER0_IRQHandler(void)
{
	NRF_TIMER0->EVENTS_COMPARE[0] = 0;
	timer0.isrUpdate();
}
}
#endif



#if defined(TIM2_ENABLE) && defined(TIMER2)
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
	clock.peripheral.resetTimer2();
}

drv::Timer timer2(TIMER2, setTim2ClockEn, setTim2IntEn, resetTim2, getTimerApb1ClkFreq);

extern "C"
{
void TIMER2_IRQHandler(void)
{
	if (TIMER2->DIE & TIMER_DIE_UPIE && TIMER2->STR & TIMER_STR_UPIF)
	{
		TIMER2->STR = ~TIMER_STR_UPIF;
		timer2.isrUpdate();
	}
}
}
#endif



#if defined(TIM3_ENABLE) && defined(TIMER3)
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
	clock.peripheral.resetTimer3();
}

drv::Timer timer3(TIMER3, setTim3ClockEn, setTim3IntEn, resetTim3, getTimerApb1ClkFreq);

extern "C"
{
void TIMER3_IRQHandler(void)
{
	if (TIMER3->DIE & TIMER_DIE_UPIE && TIMER3->STR & TIMER_STR_UPIF)
	{
		TIMER3->STR = ~TIMER_STR_UPIF;
		timer3.isrUpdate();
	}
}
}
#endif



#if defined(TIM4_ENABLE) && defined(TIMER4)
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
	clock.peripheral.resetTimer4();
}

drv::Timer timer4(TIMER4, setTim4ClockEn, setTim4IntEn, resetTim4, getTimerApb1ClkFreq);

extern "C"
{
void TIMER4_IRQHandler(void)
{
	if (TIMER4->DIE & TIMER_DIE_UPIE && TIMER4->STR & TIMER_STR_UPIF)
	{
		TIMER4->STR = ~TIMER_STR_UPIF;
		timer4.isrUpdate();
	}
}
}
#endif



#if defined(TIM5_ENABLE) && defined(TIMER5)
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
	clock.peripheral.resetTimer5();
}

drv::Timer timer5(TIMER5, setTim5ClockEn, setTim5IntEn, resetTim5, getTimerApb1ClkFreq);

extern "C"
{
void TIMER5_IRQHandler(void)
{
	if (TIMER5->DIE & TIMER_DIE_UPIE && TIMER5->STR & TIMER_STR_UPIF)
	{
		TIMER5->STR = ~TIMER_STR_UPIF;
		timer5.isrUpdate();
	}
}
}
#endif



#if defined(TIM6_ENABLE) && defined(TIMER6)
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
	clock.peripheral.resetTimer6();
}

drv::Timer timer6(TIMER6, setTim6ClockEn, setTim6IntEn, resetTim6, getTimerApb1ClkFreq);

extern "C"
{
void TIMER6_IRQHandler(void)
{
	if (TIMER6->DIE & TIMER_DIE_UPIE && TIMER6->STR & TIMER_STR_UPIF)
	{
		TIMER6->STR = ~TIMER_STR_UPIF;
		timer6.isrUpdate();
	}
}
}
#endif



#if defined(TIM7_ENABLE) && defined(TIMER7)
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
	clock.peripheral.resetTimer7();
}

drv::Timer timer7(TIMER7, setTim7ClockEn, setTim7IntEn, resetTim7, getTimerApb1ClkFreq);

extern "C"
{
void TIMER7_IRQHandler(void)
{
	if (TIMER7->DIE & TIMER_DIE_UPIE && TIMER7->STR & TIMER_STR_UPIF)
	{
		TIMER7->STR = ~TIMER_STR_UPIF;
		timer7.isrUpdate();
	}
}
}

#endif

#if defined(TIM8_ENABLE) && defined(TIMER8)
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
	clock.peripheral.resetTimer8();
}

drv::Timer timer8(TIMER8, setTim8ClockEn, setTim8IntEn, resetTim8, getTimerApb2ClkFreq);

extern "C"
{
void TIMER8_UP_TIMER13_IRQHandler(void)
{
	if (TIMER8->DIE & TIMER_DIE_UPIE && TIMER8->STR & TIMER_STR_UPIF)
	{
		TIMER8->STR = ~TIMER_STR_UPIF;
		timer8.isrUpdate();
	}

#if defined(TIM13_ENABLE) && defined(TIMER13)
#define TIMER13_ISR_DEFINED
	if (TIMER13->DIE & TIMER_DIE_UPIE && TIMER13->STR & TIMER_STR_UPIF)
	{
		TIMER13->STR = ~TIMER_STR_UPIF;
		timer13.isrUpdate();
	}
#endif
}
}
#endif

#if defined(TIM9_ENABLE) && defined(TIMER9)
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
	clock.peripheral.resetTimer9();
}

drv::Timer timer9(TIMER9, setTim9ClockEn, setTim9IntEn, resetTim9, getTimerApb2ClkFreq);

extern "C"
{
void TIMER1_BRK_TIMER9_IRQHandler(void)
{
	if (TIMER9->DIE & TIMER_DIE_UPIE && TIMER9->STR & TIMER_STR_UPIF)
	{
		TIMER9->STR = ~TIMER_STR_UPIF;
		timer9.isrUpdate();
	}
}
}
#endif

#if defined(TIM10_ENABLE) && defined(TIMER10)
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
	clock.peripheral.resetTimer10();
}

drv::Timer timer10(TIMER10, setTim10ClockEn, setTim10IntEn, resetTim10, getTimerApb2ClkFreq);

#ifndef TIMER10_ISR_DEFINED
extern "C"
{
void TIM1_UP_TIM10_IRQHandler(void)
{
	if (TIMER10->DIE & TIMER_DIE_UPIE && TIMER10->STR & TIMER_STR_UPIF)
	{
		TIMER10->STR = ~TIMER_STR_UPIF;
		timer10.isrUpdate();
	}
}
}
#endif

#endif



#if defined(TIM11_ENABLE) && defined(TIMER11)
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
	clock.peripheral.resetTimer11();
}

drv::Timer timer11(TIMER11, setTim11ClockEn, setTim11IntEn, resetTim11, getTimerApb2ClkFreq);

extern "C"
{
void TIMER1_TRG_COM_TIMER11_IRQHandler(void)
{
	if (TIMER11->DIE & TIMER_DIE_UPIE && TIMER11->STR & TIMER_STR_UPIF)
	{
		TIMER11->STR = ~TIMER_STR_UPIF;
		timer11.isrUpdate();
	}
}
}
#endif



#if defined(TIM12_ENABLE) && defined(TIMER12)
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
	clock.peripheral.resetTimer12();
}

drv::Timer timer12(TIMER12, setTim12ClockEn, setTim12IntEn, resetTim12, getTimerApb1ClkFreq);

extern "C"
{
void TIMER8_BRK_TIMER12_IRQHandler(void)
{
	if (TIMER12->DIE & TIMER_DIE_UPIE && TIMER12->STR & TIMER_STR_UPIF)
	{
		TIMER12->STR = ~TIMER_STR_UPIF;
		timer12.isrUpdate();
	}
}
}
#endif



#if defined(TIM13_ENABLE) && defined(TIMER13)
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
	clock.peripheral.resetTimer13();
}

drv::Timer timer13(TIMER13, setTim13ClockEn, setTim13IntEn, resetTim13, getTimerApb1ClkFreq);

#ifndef TIMER13_ISR_DEFINED
extern "C"
{
void TIM8_UP_TIM13_IRQHandler(void)
{
	if (TIMER13->DIE & TIMER_DIE_UPIE && TIMER13->STR & TIMER_STR_UPIF)
	{
		TIMER13->STR = ~TIMER_STR_UPIF;
		timer13.isrUpdate();
	}
}
}
#endif
#endif



#if defined(TIM14_ENABLE) && defined(TIMER14)
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
	clock.peripheral.resetTimer14();
}

drv::Timer timer14(TIMER14, setTim14ClockEn, setTim14IntEn, resetTim14, getTimerApb1ClkFreq);

extern "C"
{
void TIMER8_TRG_COM_TIMER14_IRQHandler(void)
{
	if (TIMER14->DIE & TIMER_DIE_UPIE && TIMER14->STR & TIMER_STR_UPIF)
	{
		TIMER14->STR = ~TIMER_STR_UPIF;
		timer14.isrUpdate();
	}
}
}
#endif

#endif


////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(GD32F1) || defined(STM32F1)

#include <config.h>
#include <yss.h>
#include <yss/reg.h>
#include <cmsis/mcu/st_gigadevice/rcc_stm32_gd32f1.h>

#if defined(GD32F1)
#if defined(__SEGGER_LINKER)
#define YSS_CAN1_RX0_IRQHandler		USBD_LP_CAN0_RX0_IRQHandler
#define YSS_CAN2_RX0_IRQHandler		CAN1_RX0_IRQHandler
#else
#define YSS_CAN1_RX0_IRQHandler		USBD_LP_CAN1_RX0_IRQHandler
#define YSS_CAN2_RX0_IRQHandler		CAN2_RX0_IRQHandler
#endif
#else
#define YSS_CAN1_RX0_IRQHandler		USBD_LP_CAN1_RX0_IRQHandler
#define YSS_CAN2_RX0_IRQHandler		CAN2_RX0_IRQHandler
#endif

//********** can1 구성 설정 및 변수 선언 **********
#if defined(CAN1_ENABLE) && defined(CAN1)

static void setCan1ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_CAN1EN_Pos, en);
	clock.unlock();
}

static void setCan1IntEn(bool en)
{
    nvic.lock();
    nvic.enableInterrupt(USB_LP_CAN1_RX0_IRQn, en);
    nvic.unlock();
}

static void resetCan1(void)
{
	clock.lock();
    clock.resetApb2(RCC_APB1RSTR_CAN1RST_Pos);
	clock.unlock();
}

Can can1((YSS_CAN_Peri*)CAN1, setCan1ClockEn, setCan1IntEn, resetCan1, getApb1ClockFrequency);

extern "C"
{
	void YSS_CAN1_RX0_IRQHandler(void)
	{
		can1.isr();
	}
}

#endif

//********** can2 구성 설정 및 변수 선언 **********
#if defined(CAN2_ENABLE) && defined(CAN2)
static void setCan2ClockEn(bool en)
{
	clock.peripheral.setCan2En(en);
}

static void setCan2IntEn(bool en)
{
	nvic.setCan2En(en);
}

static void resetCan2(void)
{
	clock.peripheral.resetCan2();
}

Can can2(CAN2, setCan2ClockEn, setCan2IntEn, resetCan2, getClockFreq);

extern "C"
{
	void YSS_CAN2_RX0_IRQHandler(void)
	{
		can2.isr();
	}
}

#endif

#endif

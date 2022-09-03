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

#include <drv/mcu.h>

#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7)

#include <yss/instance.h>
#include <config.h>

//********** can1 구성 설정 및 변수 선언 **********
#if defined(CAN1_ENABLE) && (defined(CAN1) || defined(FDCAN1))

static uint32_t getClockFreq(void)
{
	return clock.getApb1ClkFreq();
}

static void setCan1ClockEn(bool en)
{
	clock.peripheral.setCan1En(en);
}

static void setCan1IntEn(bool en)
{
	nvic.setCan1En(en);
}

static void resetCan1(void)
{
	clock.peripheral.resetCan1();
}

Can can1((YSS_CAN_Peri*)CAN1, setCan1ClockEn, setCan1IntEn, resetCan1, getClockFreq);

extern "C"
{
#if defined(STM32F1)
	void USB_LP_CAN1_RX0_IRQHandler(void)
	{
		can1.isr();
//		usbd.isr();
	}
#elif defined(STM32F4) || defined(STM32F7)
	void CAN1_RX0_IRQHandler(void)
	{
		can1.isr();
	}
#endif
}

#endif

//********** can2 구성 설정 및 변수 선언 **********
#if defined(CAN2_ENABLE) && (defined(CAN2) || defined(FDCAN2))
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
	void CAN2_RX0_IRQHandler(void)
	{
		can2.isr();
	}
}

#endif

#endif

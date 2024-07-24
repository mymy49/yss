/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(GD32F1)

#include <config.h>
#include <yss.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/rcc_stm32_gd32f1.h>

#if defined(__SEGGER_LINKER)
#define YSS_CAN1_RX0_IRQHandler		USBD_LP_CAN0_RX0_IRQHandler
#define YSS_CAN2_RX0_IRQHandler		CAN1_RX0_IRQHandler
#else
#define YSS_CAN1_RX0_IRQHandler		USB_LP_CAN1_RX0_IRQHandler
#define YSS_CAN2_RX0_IRQHandler		CAN2_RX0_IRQHandler
#endif

static uint32_t getApb1ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}

//********** can1 구성 설정 및 변수 선언 **********
#if defined(CAN1_ENABLE) && defined(CAN1)

static void enableCan1Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_CAN1EN_Pos, en);
	clock.unlock();
}

static void enableCan1Interrupt(bool en)
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

static const Drv::setup_t gDrvCan1Setup = 
{
	enableCan1Clock,		//void (*clockFunc)(bool en);
	enableCan1Interrupt,	//void (*nvicFunc)(bool en);
	resetCan1,				//void (*resetFunc)(void);
	getApb1ClockFrequency,	//uint32_t (*getClockFreq)(void);
};

static const Can::Setup gCan1Setup = 
{
	CAN1	//YSS_CAN_Peri *dev;
};

Can can1(gDrvCan1Setup, gCan1Setup);

extern "C"
{
	void YSS_CAN1_RX0_IRQHandler(void)
	{
		can1.isr();
	}
}

#endif

#endif

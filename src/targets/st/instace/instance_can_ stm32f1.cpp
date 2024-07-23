/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F1) || defined(STM32F7) || defined(STM32F4)

#include <config.h>
#include <yss.h>

#include <targets/st/bitfield.h>

#if CAN1_ENABLE && defined(CAN1)
static uint32_t getApb1ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}

static void enableCan1Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_CAN1EN_Pos, en);
	clock.unlock();
}

static void enableCan1Interrupt(bool en)
{
    nvic.lock();
#if defined(STM32F1)
    nvic.enableInterrupt(USB_LP_CAN1_RX0_IRQn, en);
#elif defined(STM32F7) || defined(STM32F4)
    nvic.enableInterrupt(CAN1_RX0_IRQn, en);
#endif
	nvic.enableInterrupt(CAN1_SCE_IRQn, en);
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

static const Can::setup_t gCan1Setup = 
{
	CAN1	//YSS_CAN_Peri *dev;
};

Can can1(gDrvCan1Setup, gCan1Setup);

extern "C"
{
#if defined(STM32F1)
	void USB_LP_CAN1_RX0_IRQHandler(void)
#elif defined(STM32F7) || defined (STM32F4)
	void CAN1_RX0_IRQHandler(void)
#endif
	{
		can1.isrRx();
	}

	void CAN1_SCE_IRQHandler(void)
	{
		can1.isrEvent();
	}
}
#endif

#endif

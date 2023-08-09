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

static const Drv::Setup gDrvCan1Setup = 
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

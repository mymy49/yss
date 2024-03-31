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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(W7500)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/wiznet/bitfield_w7500x.h>


#if defined(UART0) && UART0_ENABLE
static void enableUart0Clock(bool en)
{
	clock.lock();
	CRG->UARTCLK_SSR = 1;
	clock.unlock();
}

static void enableUart0Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(UART0_IRQn, en);
	nvic.unlock();
}

static uint32_t getUart0ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM0CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->UARTCLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvUart0Setup = 
{
	enableUart0Clock,		//void (*clockFunc)(bool en);
	enableUart0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getUart0ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Uart::setup_t gUart0Setup = 
{
	(YSS_USART_Typedef*)UART0	//YSS_SPI_Peri *peri;
};

Uart uart0(gDrvUart0Setup, gUart0Setup);

extern "C"
{
	void UART0_IRQHandler(void)
	{
		uart0.isr();
	}
}
#endif


#if defined(UART1) && UART1_ENABLE
static void enableUart1Clock(bool en)
{
	clock.lock();
	CRG->UARTCLK_SSR = 1;
	clock.unlock();
}

static void enableUart1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(UART1_IRQn, en);
	nvic.unlock();
}

static uint32_t getUart1ClockFrequency(void)
{
	uint32_t clk;

	switch(CRG->PWM0CLK_SSR & 0x3)
	{
	case 0 : // 비활성화
	default :
		return 0;
	
	case 1 : // MCLK
		clk = clock.getMclkFrequency();
		break;

	case 2 : // RCLK
		clk = clock.getRclkFrequency();
		break;
	
	case 3 : // OCLK
		clk = clock.getOclkFrequency();
		break;
	}

	return clk / (1 << (CRG->UARTCLK_PVSR & 0x7));
}

static const Drv::setup_t gDrvUart1Setup = 
{
	enableUart1Clock,		//void (*clockFunc)(bool en);
	enableUart1Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getUart1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const Uart::setup_t gUart1Setup = 
{
	(YSS_USART_Typedef*)UART1,	//YSS_SPI_Peri *peri;
};

Uart uart1(gDrvUart1Setup, gUart1Setup);

extern "C"
{
	void UART1_IRQHandler(void)
	{
		uart1.isr();
	}
}
#endif

#endif


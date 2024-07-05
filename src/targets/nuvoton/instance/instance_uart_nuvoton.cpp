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

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/nuvoton/bitfield_m48x.h>

#if defined(UART0) && UART0_ENABLE
static void enableUart0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_UART0CKEN_Pos, en);
}

static void enableUart0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(UART0_IRQn, en);
}

static uint32_t getUart0ClockFrequency(void)
{
	uint32_t clk = 0;

	switch((CLK->CLKSEL1 & CLK_CLKSEL1_UART0SEL_Msk) >> CLK_CLKSEL1_UART0SEL_Pos)
	{
	case 0 : // HXT
		clk = clock.getHxtFrequency();
		break;
	
	case 1 : // PLL
		clk = clock.getPllFrequency();
		break;

	case 2 : // LXT
		clk = 32768;
		break;
	
	case 3 : // HIRC
		clk = clock.getHircFrequency();
		break;
	}

	return clk / (((CLK->CLKDIV0 & CLK_CLKDIV0_UART0DIV_Msk) >> CLK_CLKDIV0_UART0DIV_Pos) + 1);
}

static const Drv::setup_t gDrvUart0Setup = 
{
	enableUart0Clock,		//void (*clockFunc)(bool en);
	enableUart0Interrupt,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getUart0ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static Dma::dmaInfo_t gUart0TxDmaInfo = 
{
	PDMA_DIR_MEM_TO_PERI |
	PDMA_WIDTH_8 |
	PDMA_SAR_INC |
	PDMA_REQ_SINGLE |  
	PDMA_DAR_FIX | 
	PDMA_BURST_1 | 
	PDMA_OP_BASIC,		// uint32_t ctl;
	PDMA_UART0_TX,		// uint8_t src;
	(void*)&UART0->DAT,	// void *cpar;
};

static const Uart::setup_t gUart0Setup = 
{
	(YSS_USART_Typedef*)UART0,	// YSS_SPI_Peri *peri;
	gUart0TxDmaInfo				// Dma::dmaInfo_t txDmaInfo;
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

#endif


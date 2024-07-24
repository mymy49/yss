/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(EFM32PG22) || defined(EFR32BG22)

#include <drv/peripheral.h>
#include <yss/instance.h>
#include <config.h>
#include <targets/siliconlabs/define_efm32pg22_efr32bg22.h>

#if defined(EFM32PG22)
#include <targets/siliconlabs/efm32pg22_cmu.h>
#include <targets/siliconlabs/efm32pg22_ldma.h>
#include <targets/siliconlabs/efm32pg22_ldmaxbar_defines.h>
#elif defined(EFR32BG22)
#include <targets/siliconlabs/efr32bg22_cmu.h>
#include <targets/siliconlabs/efr32bg22_ldma.h>
#include <targets/siliconlabs/efr32bg22_ldmaxbar_defines.h>
#endif

static uint32_t getClockFreqeuncy(void)
{
	return clock.getApb0Frequency();
}

using namespace define::dma;

#if USART_COUNT >= 1 && defined(UART0_ENABLE)
#if defined(SPI0_ENABLE) && defined(UART0_ENABLE)
#error "SPI0과 UART0은 동시에 활성화 될 수 없습니다."
#endif
static void enableClockUart0(bool en)
{
	clock.lock();
	clock.enableApb0Clock(_CMU_CLKEN0_USART0_SHIFT, en);
	clock.unlock();
}

static void enableInterruptUart0(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(USART0_RX_IRQn, en);
	nvic.unlock();
}

static const Drv::setup_t gDrvUart0Config
{
	enableClockUart0,		//void (*clockFunc)(bool en);
	enableInterruptUart0,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getClockFreqeuncy		//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gUart0TxDmaInfo = 
{
	(dstinc::NONE << _LDMA_CH_CTRL_DSTINC_SHIFT) |	// uint32_t controlRegister1
	(size::BYTE << _LDMA_CH_CTRL_SIZE_SHIFT) |
	(srcinc::ONE << _LDMA_CH_CTRL_SRCINC_SHIFT) |	
	(reqmode::BLOCK << _LDMA_CH_CTRL_REQMODE_SHIFT) |	
	(blocksize::UNIT2 << _LDMA_CH_CTRL_BLOCKSIZE_SHIFT) |	
	(structtype::TRANSFER << _LDMA_CH_CTRL_STRUCTTYPE_SHIFT) |
	_LDMA_CH_CTRL_DONEIEN_MASK,
	0,								// uint32_t controlRegister2
	0x80000000 |					// uint32_t controlRegister3
	LDMAXBAR_CH_REQSEL_SOURCESEL_USART0 |
	LDMAXBAR_CH_REQSEL_SIGSEL_USART0TXEMPTY,
	(void*)&USART0_S->TXDATA			//void *dataRegister;
};

static const Uart::Config gUart0Config
{
	USART0_S,				//YSS_SPI_Peri *peri;
	dmaChannelList,		//Dma *dmaChannelList;
	&gUart0TxDmaInfo	//Dma::dmaInfo_t txDmaInfo;
};

Uart uart0(gDrvUart0Config, gUart0Config);

extern "C"
{
	void USART0_RX_IRQHandler(void)
	{
		uart0.isr();
	}
}
#endif



#if USART_COUNT >= 2 && defined(UART1_ENABLE)
#if defined(SPI1_ENABLE) && defined(UART1_ENABLE)
#error "SPI0과 UART0은 동시에 활성화 될 수 없습니다."
#endif
static void enableClockUart1(bool en)
{
	clock.lock();
	clock.enableApb0Clock(_CMU_CLKEN0_USART1_SHIFT, en);
	clock.unlock();
}

static void enableInterruptUart1(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(USART1_RX_IRQn, en);
	nvic.unlock();
}

static const Drv::setup_t gDrvUart1Config
{
	enableClockUart1,		//void (*clockFunc)(bool en);
	enableInterruptUart1,	//void (*nvicFunc)(bool en);
	0,						//void (*resetFunc)(void);
	getClockFreqeuncy		//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gUart1TxDmaInfo = 
{
	(dstinc::NONE << _LDMA_CH_CTRL_DSTINC_SHIFT) |	// uint32_t controlRegister1
	(size::BYTE << _LDMA_CH_CTRL_SIZE_SHIFT) |
	(srcinc::ONE << _LDMA_CH_CTRL_SRCINC_SHIFT) |	
	(reqmode::BLOCK << _LDMA_CH_CTRL_REQMODE_SHIFT) |	
	(blocksize::UNIT2 << _LDMA_CH_CTRL_BLOCKSIZE_SHIFT) |	
	(structtype::TRANSFER << _LDMA_CH_CTRL_STRUCTTYPE_SHIFT) |
	_LDMA_CH_CTRL_DONEIEN_MASK,
	0,								// uint32_t controlRegister2
	0x80000000 |					// uint32_t controlRegister3
	LDMAXBAR_CH_REQSEL_SOURCESEL_USART1 |
	LDMAXBAR_CH_REQSEL_SIGSEL_USART1TXEMPTY,
	(void*)&USART1_S->TXDATA			//void *dataRegister;
};

static const Uart::Config gUart1Config
{
	USART1_S,				//YSS_SPI_Peri *peri;
	dmaChannelList,		//Dma *dmaChannelList;
	&gUart1TxDmaInfo	//Dma::dmaInfo_t txDmaInfo;
};

Uart uart1(gDrvUart1Config, gUart1Config);

extern "C"
{
	void USART1_RX_IRQHandler(void)
	{
		uart1.isr();
	}
}
#endif

#endif


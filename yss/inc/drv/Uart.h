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

#ifndef YSS_DRV_UART__H_
#define YSS_DRV_UART__H_

#include <drv/mcu.h>
#include <yss/error.h>

#if defined(STM32F1) || defined(STM32F4)

#include "uart/define_uart_stm32f1_f4.h"

typedef USART_TypeDef		YSS_USART_Peri;

#elif defined(STM32F7)

#include "uart/define_uart_stm32f7.h"

typedef USART_TypeDef		YSS_USART_Peri;

#elif defined(GD32F1)

#include "uart/define_uart_gd32f1_f4.h"

typedef USART_TypeDef		YSS_USART_Peri;

#elif defined (GD32F450)

#include "uart/define_uart_gd32f1_f4.h"

typedef unsigned int		YSS_USART_Peri;

#elif defined(NRF52840_XXAA)

#include "uart/define_uart_gd32f1_f4.h"

typedef NRF_UART_Type		YSS_USART_Peri;

#else

#define YSS_DRV_UART_UNSUPPORTED

#endif

#ifndef YSS_DRV_UART_UNSUPPORTED

#include <drv/peripheral.h>

#include <drv/Drv.h>
#include <sac/Comm.h>
#include <drv/Dma.h>

namespace drv
{
class Uart : public Drv
{
	YSS_USART_Peri *mPeri;
	unsigned char *mRcvBuf;
	unsigned int mRcvBufSize;
	unsigned int mTail, mHead;
	bool mOneWireModeFlag;

#if !defined(YSS_DRV_DMA_UNSUPPORTED)
	Dma *mTxDma;
	Dma::DmaInfo mTxDmaInfo;
#endif

  public:
#if !defined(YSS_DRV_DMA_UNSUPPORTED)
	struct Config
	{
		YSS_USART_Peri *peri;
		Dma &txDma;
		Dma::DmaInfo txDmaInfo;
	};
#else
	struct Config
	{
		YSS_USART_Peri *peri;
	};
#endif

	Uart(const Drv::Config drvConfig, const Config config);
	Uart(YSS_USART_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), unsigned int (*getClockFreq)(void));

	error init(unsigned int baud, unsigned int receiveBufferSize);
	error init(unsigned int baud, void *receiveBuffer, unsigned int receiveBufferSize);

	void isr(void);
	char getWaitUntilReceive(void);
	signed short get(void);
	void flush(void);
	error send(void *src, unsigned int size);
	error send(const void *src, unsigned int size);
	void send(char data);
	void setOneWireMode(bool en);
	void push(char data);
};
}

#endif

#endif

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

#if defined(STM32F4)

#include "uart/define_uart_stm32f1_f4.h"

typedef USART_TypeDef		YSS_USART_Peri;

#elif defined(STM32F7)

#include "uart/define_uart_stm32f7.h"

typedef USART_TypeDef		YSS_USART_Peri;

#elif defined(GD32F1) || defined (GD32F450) || defined(STM32F1)

#include "uart/define_uart_gd32f1_f4.h"

typedef uint32_t		YSS_USART_Peri;

#elif defined(NRF52840_XXAA)

#include "uart/define_uart_gd32f1_f4.h"

typedef NRF_UART_Type		YSS_USART_Peri;

#else

#define YSS_DRV_UART_UNSUPPORTED

#endif

#ifndef YSS_DRV_UART_UNSUPPORTED

#include <drv/Drv.h>
#include <drv/Dma.h>

class Uart : public Drv
{
	YSS_USART_Peri *mPeri;
	int8_t *mRcvBuf;
	int32_t  mRcvBufSize;
	int32_t  mTail, mHead;
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
	Uart(YSS_USART_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), uint32_t (*getClockFreq)(void));

	error init(int32_t  baud, int32_t  receiveBufferSize);
	error init(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize);

	void isr(void);
	int8_t getWaitUntilReceive(void);
	int16_t get(void);
	void flush(void);
	error send(void *src, int32_t  size);
	error send(const void *src, int32_t  size);
	void send(int8_t data);
	void setOneWireMode(bool en);
	void push(int8_t data);
};

#endif

#endif

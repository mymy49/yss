////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

//#include <__cross_studio_io.h>
#include <config.h>
#include <drv/peripherals.h>
#include <drv/uart/drv_st_uart_type_A_register.h>

static unsigned int getApb2ClkFreq(void)
{
	return clock.getApb2ClkFreq();
}

static unsigned int getApb1ClkFreq(void)
{
	return clock.getApb1ClkFreq();
}

#if defined(USART1) && defined(UART1_ENABLE)
static void setUart1ClockEn(bool en)
{
	clock.peripheral.setUart1En(en);
} 

static void setUart1IntEn(bool en)
{
	nvic.setUart1En(en);
}

drv::Uart uart1(USART1, setUart1ClockEn, setUart1IntEn,  YSS_DMA_MAP_UART1_TX_STREAM, YSS_DMA_MAP_UART1_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);

extern "C"
{
	void USART1_IRQHandler(void)
	{
		uart1.isr();
	}
}
#endif

#if	defined(USART2) && defined(UART2_ENABLE)
static void setUart2ClockEn(bool en)
{
	clock.peripheral.setUart2En(en);
} 

static void setUart2IntEn(bool en)
{
	nvic.setUart2En(en);
}

drv::Uart uart2(USART2, setUart2ClockEn, setUart2IntEn, YSS_DMA_MAP_UART2_TX_STREAM, YSS_DMA_MAP_UART2_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
	void USART2_IRQHandler(void)
	{
		uart2.isr();
	}
}

#endif

#if	defined(USART3) && defined(UART3_ENABLE)
static void setUart3ClockEn(bool en)
{
	clock.peripheral.setUart3En(en);
} 

static void setUart3IntEn(bool en)
{
	nvic.setUart3En(en);
}

drv::Uart uart3(USART3, setUart3ClockEn, setUart3IntEn, YSS_DMA_MAP_UART3_TX_STREAM, YSS_DMA_MAP_UART3_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
	void USART3_IRQHandler(void)
	{
		uart3.isr();
	}
}

#endif

#if	defined(UART4) && defined(UART4_ENABLE)
static void setUart4ClockEn(bool en)
{
	clock.peripheral.setUart4En(en);
} 

static void setUart4IntEn(bool en)
{
	nvic.setUart4En(en);
}

drv::Uart uart4(UART4, setUart4ClockEn, setUart4IntEn,	YSS_DMA_MAP_UART4_TX_STREAM, YSS_DMA_MAP_UART4_TX_CHANNEL,	define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
	void UART4_IRQHandler(void)
	{
		uart4.isr();
	}
}

#endif

#if	defined(UART5) && defined(UART5_ENABLE)
static void setUart5ClockEn(bool en)
{
	clock.peripheral.setUart5En(en);
} 

static void setUart5IntEn(bool en)
{
	nvic.setUart5En(en);
}

drv::Uart uart5(UART5, setUart5ClockEn, setUart5IntEn,	YSS_DMA_MAP_UART5_TX_STREAM, YSS_DMA_MAP_UART5_TX_CHANNEL,	define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
	void UART5_IRQHandler(void)
	{
		uart5.isr();
	}
}

#endif

#if	defined(USART6) && defined(UART6_ENABLE)
static void setUart6ClockEn(bool en)
{
	clock.peripheral.setUart6En(en);
} 

static void setUart6IntEn(bool en)
{
	nvic.setUart6En(en);
}

drv::Uart uart6(USART6, setUart6ClockEn, setUart6IntEn, YSS_DMA_MAP_UART6_TX_STREAM, YSS_DMA_MAP_UART6_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);

extern "C"
{
	void USART6_IRQHandler(void)
	{
		uart6.isr();
	}
}

#endif

#if	defined(UART7) && defined(UART7_ENABLE)
static void setUart7ClockEn(bool en)
{
	clock.peripheral.setUart7En(en);
} 

static void setUart7IntEn(bool en)
{
	nvic.setUart7En(en);
}

drv::Uart uart7(UART7, setUart7ClockEn, setUart7IntEn, YSS_DMA_MAP_UART7_TX_STREAM, YSS_DMA_MAP_UART7_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
	void UART7_IRQHandler(void)
	{
		uart7.isr();
	}
}

#endif

#if	defined(UART8) && defined(UART8_ENABLE)
static void setUart8ClockEn(bool en)
{
	clock.peripheral.setUart8En(en);
} 

static void setUart8IntEn(bool en)
{
	nvic.setUart8En(en);
}

drv::Uart uart8(UART8, setUart8ClockEn, setUart8IntEn, YSS_DMA_MAP_UART8_TX_STREAM, YSS_DMA_MAP_UART8_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
	void UART8_IRQHandler(void)
	{
		uart8.isr();
	}
}

#endif

namespace drv
{
	Uart::Uart(USART_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), Stream *txStream, unsigned char txChannel, unsigned short priority, unsigned int (*getClockFreq)(void)) :  Drv(clockFunc, nvicFunc)
	{
		this->set(txChannel, (void*)&(peri->TDR), priority);

		mGetClockFreq = getClockFreq;
		mTxStream = txStream;
		mPeri = peri;
		mRcvBuf = 0;
		mTail = 0;
		mHead = 0;
	}

	bool Uart::init(unsigned int baud, unsigned int receiveBufferSize)
	{
		unsigned int brr, clk = mGetClockFreq();

		if(mRcvBuf)
			delete mRcvBuf;
		mRcvBuf = new unsigned char[receiveBufferSize];

		if(mRcvBuf == 0)
			return false;

		mRcvBufSize = receiveBufferSize;

		brr = clk / baud;
		setUsartBrr(mPeri, brr);
		setUsartTxEn(mPeri, true);
		setUsartRxEn(mPeri, true);
		setUsartDmaTxEn(mPeri, true);
		setUsartRxneiEn(mPeri, true);
		setUsartEn(mPeri, true);

		return true;
	}

	bool Uart::send(void *src, unsigned int size, unsigned int timeout)
	{
		if(mTxStream)
			return mTxStream->send(this, src, size, timeout);
		else
			return false;
	}

	bool Uart::send(const void *src, unsigned int size, unsigned int timeout)
	{
		if(mTxStream)
			return mTxStream->send(this, (void*)src, size, timeout);
		else
			return false;
	}

	void Uart::push(char data)
	{
		if(mRcvBuf)
		{
			mRcvBuf[mHead++] = data;
			if(mHead >= mRcvBufSize)
				mHead = 0;
		}
	}

	void Uart::isr(void)
	{
		unsigned int sr = mPeri->ISR;

		push(mPeri->RDR);

		if(sr & (1 << 3))
		{
			flush();
		}
	}

	void Uart::flush(void)
	{
		mHead = mTail = 0;
	}

	signed short Uart::get(void)
	{
		signed short buf = -1;

		if(mHead != mTail)
		{
			buf = (unsigned char)mRcvBuf[mTail++];
			if(mTail >= mRcvBufSize)
				mTail = 0;
		}

		return buf;
	}

	char Uart::getWaitUntilReceive(void)
	{
		signed short data;

		while(1)
		{
			data = get();
			if(data >= 0)
				return (char)data;
			thread::switchContext();
		}
	}
}
#endif

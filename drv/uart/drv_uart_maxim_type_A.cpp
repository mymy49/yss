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
/*
#if defined(MAX32660)

#include <config.h>
#include <drv/peripherals.h>
#include <drv/uart/drv_st_uart_type_A_register.h>

static unsigned long getClkFreq(void)
{
	return clock.getApbClkFreq();
}

#if	defined(MXC_UART0) && defined(UART0_ENABLE)
static void setUart1ClockEn(bool en)
{
//	clock.peripheral.setUart1En(en);
} 

static void setUart1IntEn(bool en)
{
//	nvic.setUart1En(en);
}

//drv::Uart uart1(USART1, setUart1ClockEn, setUart1IntEn,  YSS_DMA_MAP_UART1_TX_STREAM, YSS_DMA_MAP_UART1_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb2ClkFreq);

extern "C"
{
	//void USART1_IRQHandler(void)
	//{
	//	uart1.isr();
	//}
}
#endif

#if	defined(MXC_UART1) && defined(UART1_ENABLE)
static void setUart2ClockEn(bool en)
{
//	clock.peripheral.setUart2En(en);
} 

static void setUart2IntEn(bool en)
{
//	nvic.setUart2En(en);
}

//drv::Uart uart2(USART2, setUart2ClockEn, setUart2IntEn, YSS_DMA_MAP_UART2_TX_STREAM, YSS_DMA_MAP_UART2_TX_CHANNEL, define::dma::priorityLevel::LOW, getApb1ClkFreq);

extern "C"
{
	//void USART2_IRQHandler(void)
	//{
	//	uart2.isr();
	//}
}

#endif

namespace drv
{
	Uart::Uart(mxc_uart_regs_t *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned long (*getClockFreq)(void)) :  Drv(clockFunc, nvicFunc)
	{
		this->set(txChannel, (void*)&(peri->TDR), priority);

		mGetClockFreq = getClockFreq;
		mTxStream = txStream;
		mPeri = peri;
		mRcvBuf = 0;
		mTail = 0;
		mHead = 0;
	}

	bool Uart::init(unsigned long baud, unsigned long receiveBufferSize)
	{
		unsigned long brr, clk = mGetClockFreq();

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
		unsigned long sr = mPeri->ISR;

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

	signed short Uart::pop(void)
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

	char Uart::get(void)
	{
		signed short data;

		while(1)
		{
			data = pop();
			if(data >= 0)
				return (char)data;
			thread::switchContext();
		}
	}
}
#endif
*/
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

#if defined(MAX32660)

#include <yss/mcu.h>
#include <config.h>
#include <drv/peripherals.h>
#include <drv/uart/drv_maxim_uart_type_A_define.h>
#include <yss/malloc.h>
#include <instance/instance_clock.h>

#if defined(MXC_UART0) && defined(UART0_ENABLE)
static void setUart0ClockEn(bool en)
{
	clock.peripheral.setUart0En(en);
} 

static void setUart0IntEn(bool en)
{
	nvic.setUart0En(en);
}

drv::Uart uart0(MXC_UART0, setUart0ClockEn, setUart0IntEn);

extern "C"
{
	void UART0_IRQHandler(void)
	{
		uart0.isr();
	}
}
#endif

#if defined(MXC_UART1) && defined(UART1_ENABLE)
static void setUart1ClockEn(bool en)
{
	clock.peripheral.setUart1En(en);
} 

static void setUart1IntEn(bool en)
{
	nvic.setUart1En(en);
}

drv::Uart uart1(MXC_UART1, setUart1ClockEn, setUart1IntEn);

extern "C"
{
	void UART1_IRQHandler(void)
	{
		uart1.isr();
	}
}

#endif

namespace drv
{
	Uart::Uart(mxc_uart_regs_t *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) :  Drv(clockFunc, nvicFunc)
	{
		mPeri = peri;
		mRcvBuf = 0;
		mTail = 0;
		mHead = 0;
	}

	bool Uart::init(unsigned int baud, unsigned int receiveBufferSize)
	{
		unsigned int ibaud, dbaud, clk = clock.getApbClkFreq() / 16;

		if(mRcvBuf)
			delete mRcvBuf;
#if YSS_L_HEAP_USE
		mRcvBuf = (unsigned char*)lmalloc(receiveBufferSize);
#else
		mRcvBuf = (unsigned char*)hmalloc(receiveBufferSize);
#endif
		if(mRcvBuf == 0)
			return false;

		mRcvBufSize = receiveBufferSize;
		
		ibaud = clk / baud;
		dbaud = (clk % baud) * 127 / baud;
		mPeri->baud0 = (3 << MXC_F_UART_BAUD0_FACTOR_POS) | (ibaud << MXC_F_UART_BAUD0_IBAUD_POS);
		mPeri->baud1 = dbaud << MXC_F_UART_BAUD1_DBAUD_POS;
		mPeri->int_en |= MXC_F_UART_INT_EN_RX_FIFO_THRESH;
		mPeri->ctrl = 3 << MXC_F_UART_CTRL_CHAR_SIZE_POS | MXC_F_UART_CTRL_ENABLE;
		mPeri->thresh_ctrl &= ~MXC_F_UART_THRESH_CTRL_RX_FIFO_THRESH_POS;
		mPeri->thresh_ctrl |= 1 << MXC_F_UART_THRESH_CTRL_RX_FIFO_THRESH_POS;

		return true;
	}

	bool Uart::send(void *src, unsigned int size, unsigned int timeout)
	{
		unsigned char *data = (unsigned char*)src;

		for(int i=0;i<size;i++)
		{
			while(mPeri->status & MXC_F_UART_STATUS_TX_FULL)
				thread::yield();
			mPeri->fifo = data[i];
		}

		while(mPeri->status & MXC_F_UART_STATUS_TX_BUSY)
			thread::yield();

		return true;
	}

	bool Uart::send(const void *src, unsigned int size, unsigned int timeout)
	{
		unsigned char *data = (unsigned char*)src;

		for(int i=0;i<size;i++)
		{
			while(mPeri->status & MXC_F_UART_STATUS_TX_FULL)
				thread::yield();
			mPeri->fifo = data[i];
		}

		while(mPeri->status & MXC_F_UART_STATUS_TX_BUSY)
			thread::yield();
		
		return true;
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
		push(mPeri->fifo);
		mPeri->int_fl = MXC_F_UART_INT_FL_RX_FIFO_THRESH;
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

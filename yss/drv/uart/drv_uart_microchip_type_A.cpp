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

#if defined(__SAML21E15A__) || defined(__SAML21E15B__) || defined(__SAML21E16A__) || defined(__SAML21E16B__) || \
	defined(__SAML21E17A__) || defined(__SAML21E17B__) || defined(__SAML21E18B__) || defined(__SAML21G16A__) || \
	defined(__SAML21G16B__) || defined(__SAML21G17A__) || defined(__SAML21G17B__) || defined(__SAML21G18A__) || \
	defined(__SAML21G18B__) || defined(__SAML21J16A__) || defined(__SAML21J16B__) || defined(__SAML21J17A__) || \
	defined(__SAML21J17B__) || defined(__SAML21J18A__) || defined(__SAML21J18B__)

#include <config.h>
#include <drv/peripherals.h>
#include <drv/uart/drv_maxim_uart_type_A_define.h>
#include <yss/malloc.h>
#include <yss/mcu.h>
#include <yss/instance.h>

static unsigned int getTimerClkFreq(void)
{
	return clock.getApbClkFrequency();
}

#if defined(SERCOM0) && defined(UART0_ENABLE)
static void setUart0ClockEn(bool en)
{
	clock.peripheral.setUart0En(en);
}

static void setUart0IntEn(bool en)
{
	nvic.setUart0En(en);
}

drv::Uart uart0(SERCOM0, setUart0ClockEn, setUart0IntEn, getTimerClkFreq);

extern "C"
{
	void SERCOM0_Handler(void)
	{
		uart0.isr();
	}
}
#endif

#if defined(SERCOM1) && defined(UART1_ENABLE)
static void setUart1ClockEn(bool en)
{
	clock.peripheral.setUart1En(en);
}

static void setUart1IntEn(bool en)
{
	nvic.setUart1En(en);
}

drv::Uart uart1(SERCOM1, setUart1ClockEn, setUart1IntEn, getTimerClkFreq);

extern "C"
{
	void SERCOM1_Handler(void)
	{
		uart1.isr();
	}
}

#endif

#if defined(SERCOM2) && defined(UART2_ENABLE)
static void setUart2ClockEn(bool en)
{
	clock.peripheral.setUart2En(en);
}

static void setUart2IntEn(bool en)
{
	nvic.setUart2En(en);
}

drv::Uart uart2(SERCOM2, setUart2ClockEn, setUart2IntEn, getTimerClkFreq);

extern "C"
{
	void SERCOM2_Handler(void)
	{
		uart2.isr();
	}
}

#endif

#if defined(SERCOM3) && defined(UART3_ENABLE)
static void setUart3ClockEn(bool en)
{
	clock.peripheral.setUart3En(en);
}

static void setUart3IntEn(bool en)
{
	nvic.setUart3En(en);
}

drv::Uart uart3(SERCOM3, setUart3ClockEn, setUart3IntEn, getTimerClkFreq);

extern "C"
{
	void SERCOM3_Handler(void)
	{
		uart3.isr();
	}
}

#endif

#if defined(SERCOM4) && defined(UART4_ENABLE)
static void setUart4ClockEn(bool en)
{
	clock.peripheral.setUart4En(en);
}

static void setUart4IntEn(bool en)
{
	nvic.setUart4En(en);
}

drv::Uart uart4(SERCOM4, setUart4ClockEn, setUart4IntEn, getTimerClkFreq);

extern "C"
{
	void SERCOM4_Handler(void)
	{
		uart4.isr();
	}
}

#endif

#if defined(SERCOM5) && defined(UART5_ENABLE)
static void setUart5ClockEn(bool en)
{
	clock.peripheral.setUart5En(en);
}

static void setUart5IntEn(bool en)
{
	nvic.setUart5En(en);
}

drv::Uart uart5(SERCOM5, setUart5ClockEn, setUart5IntEn, getTimerClkFreq);

extern "C"
{
	void SERCOM5_Handler(void)
	{
		uart5.isr();
	}
}

#endif

namespace drv
{
Uart::Uart(Sercom *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc)
{
	mPeri = peri;
	mRcvBuf = 0;
	mTail = 0;
	mHead = 0;
	mGetClockFreq = getClockFreq;
	mTxPad = 0;
	mRxPad = 0;
}

bool Uart::init(unsigned int baud, unsigned int receiveBufferSize)
{
	SercomUsart *peri = (SercomUsart *)mPeri;
	unsigned int ibaud, dbaud, clk = mGetClockFreq() / 16, reg;

	if (mRcvBuf)
		delete mRcvBuf;
#if YSS_L_HEAP_USE
	mRcvBuf = (unsigned char *)lmalloc(receiveBufferSize);
#else
	mRcvBuf = (unsigned char *)hmalloc(receiveBufferSize);
#endif
	if (mRcvBuf == 0)
		return false;

	mRcvBufSize = receiveBufferSize;

	peri->CTRLA.bit.SWRST = true;
	while (peri->SYNCBUSY.bit.SWRST)
		thread::yield();

	peri->CTRLA.reg |= 1 << SERCOM_USART_CTRLA_MODE_Pos | 4 << SERCOM_USART_CTRLA_SAMPR_Pos | SERCOM_USART_CTRLA_DORD | mRxPad << SERCOM_USART_CTRLA_RXPO_Pos | mTxPad << SERCOM_USART_CTRLA_TXPO_Pos;
	peri->CTRLB.reg |= SERCOM_USART_CTRLB_RXEN | SERCOM_USART_CTRLB_TXEN;
	peri->BAUD.reg = 65536 - (65536 * 3 * baud / mGetClockFreq());
	peri->INTENSET.reg = SERCOM_USART_INTENSET_RXC;
	peri->CTRLA.bit.ENABLE = true;

	return true;
}

bool Uart::send(void *src, unsigned int size, unsigned int timeout)
{
	SercomUsart *peri = (SercomUsart *)mPeri;
	unsigned char *data = (unsigned char *)src;

	for (int i = 0; i < size; i++)
	{
		peri->DATA.reg = data[i];
		while (~peri->INTFLAG.reg & SERCOM_USART_INTFLAG_TXC)
			thread::yield();
		peri->INTFLAG.reg = SERCOM_USART_INTFLAG_TXC;
	}

	return true;
}

bool Uart::send(const void *src, unsigned int size, unsigned int timeout)
{
	SercomUsart *peri = (SercomUsart *)mPeri;
	unsigned char *data = (unsigned char *)src;

	for (int i = 0; i < size; i++)
	{
		peri->DATA.reg = data[i];
		while (~peri->INTFLAG.reg & SERCOM_USART_INTFLAG_TXC)
			thread::yield();
		peri->INTFLAG.reg = SERCOM_USART_INTFLAG_TXC;
	}

	return true;
}

void Uart::push(char data)
{
	if (mRcvBuf)
	{
		mRcvBuf[mHead++] = data;
		if (mHead >= mRcvBufSize)
			mHead = 0;
	}
}

void Uart::isr(void)
{
	SercomUsart *peri = (SercomUsart *)mPeri;

	push(peri->DATA.reg);
	peri->INTFLAG.reg = SERCOM_USART_INTFLAG_RXC;
}

void Uart::flush(void)
{
	mHead = mTail = 0;
}

signed short Uart::get(void)
{
	signed short buf = -1;

	if (mHead != mTail)
	{
		buf = (unsigned char)mRcvBuf[mTail++];
		if (mTail >= mRcvBufSize)
			mTail = 0;
	}

	return buf;
}

char Uart::getWaitUntilReceive(void)
{
	signed short data;

	while (1)
	{
		data = get();
		if (data >= 0)
			return (char)data;
		thread::yield();
	}
}

void Uart::setPad(unsigned char txPad, unsigned char rxPad)
{
	mTxPad = txPad;
	mRxPad = rxPad;
}
}

#endif
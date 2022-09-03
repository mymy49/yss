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

#include <drv/peripheral.h>

#if defined(STM32G4)

#include <drv/Uart.h>
#include <yss/thread.h>

namespace drv
{
Uart::Uart(USART_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), uint32_t (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
	mGetClockFreq = getClockFreq;
	mPeri = peri;
	mRcvBuf = 0;
	mTail = 0;
	mHead = 0;
}

bool Uart::init(uint32_t baud, uint32_t receiveBufferSize)
{
	uint32_t brr, clk = mGetClockFreq();

	if (mRcvBuf)
		delete mRcvBuf;
	mRcvBuf = new uint8_t[receiveBufferSize];

	if (mRcvBuf == 0)
		return false;

	mRcvBufSize = receiveBufferSize;

	brr = clk / baud;
	mPeri->BRR = brr;
	mPeri->CR1 |= USART_CR1_TE_Msk | USART_CR1_RE_Msk | USART_CR1_RXNEIE_Msk | USART_CR1_UE_Msk;

	return true;
}

bool Uart::send(void *src, uint32_t size, uint32_t timeout)
{
	uint8_t *bSrc = (uint8_t *)src;
	for (uint32_t i = 0; i < size; i++)
	{
		while (!(mPeri->ISR & USART_ISR_TXE_Msk))
			thread::yield();

		mPeri->TDR = bSrc[i];
	}

	while (!(mPeri->ISR & USART_ISR_TC_Msk))
		thread::yield();

	return true;
}

bool Uart::send(const void *src, uint32_t size, uint32_t timeout)
{
	return send((void *)src, size, timeout);
}

void Uart::send(int8_t data)
{
	mPeri->ISR = ~USART_ISR_TC_Msk;
	mPeri->RDR = data;
	while (~mPeri->ISR & USART_ISR_TC_Msk)
		thread::yield();
}

void Uart::push(int8_t data)
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
	uint32_t sr = mPeri->ISR;

	push(mPeri->RDR);

	if (sr & (1 << 3))
	{
		flush();
	}
}

void Uart::flush(void)
{
	mHead = mTail = 0;
}

int16_t Uart::get(void)
{
	int16_t buf = -1;

	if (mHead != mTail)
	{
		buf = (uint8_t)mRcvBuf[mTail++];
		if (mTail >= mRcvBufSize)
			mTail = 0;
	}

	return buf;
}

int8_t Uart::getWaitUntilReceive(void)
{
	int16_t data;

	while (1)
	{
		data = get();
		if (data >= 0)
			return (int8_t)data;
		thread::yield();
	}
}
}
#endif
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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(GD32F10X_XD) || defined(GD32F10X_HD)

#include <drv/Uart.h>
#include <yss/reg.h>
//#include <drv/uart/register_uart_stm32f1_f4.h>

namespace drv
{
Uart::Uart(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mGetClockFreq = config.getClockFreq;
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mPeri = config.peri;
	mRcvBuf = 0;
	mTail = 0;
	mHead = 0;
}

bool Uart::init(unsigned int baud, unsigned int receiveBufferSize)
{
	unsigned int man, fra, buf;
	unsigned int clk = mGetClockFreq() >> 4;

	if (mRcvBuf)
		delete mRcvBuf;
	mRcvBuf = new unsigned char[receiveBufferSize];

	if (mRcvBuf == 0)
		return false;

	mRcvBufSize = receiveBufferSize;

	man = clk / baud;
	man &= 0xfff;
	fra = 16 * (clk % baud) / baud;
	fra &= 0xf;
	
	// 장치 비활성화
	setBitData(mPeri->CTLR1, false, 13);
	
	// 보레이트 설정
	setTwoFieldData(mPeri->BRR, 0xFFF << 4, man, 4, 0xF << 0, fra, 0);
	
	// TX En, RX En, Rxnei En, 장치 En
	mPeri->CTLR1 = 0x202C;

	return true;
}

bool Uart::initOneWire(unsigned int baud, unsigned int receiveBufferSize)
{
	unsigned int man, fra, buf;
	unsigned int clk = mGetClockFreq() >> 4;

	if (mRcvBuf)
		delete mRcvBuf;
	mRcvBuf = new unsigned char[receiveBufferSize];

	if (mRcvBuf == 0)
		return false;

	mRcvBufSize = receiveBufferSize;

	man = clk / baud;
	man &= 0xfff;
	fra = 16 * (clk % baud) / baud;
	fra &= 0xf;

	// 장치 비활성화
	setBitData(mPeri->CTLR1, false, 13);

	// 보레이트 설정
	setTwoFieldData(mPeri->BRR, 0xFFF << 4, man, 4, 0xF << 0, fra, 0);
	
	// Half-Duplex 활성화
	setBitData(mPeri->CTLR3, true, 3);

	// TX En, RX En, Rxnei En, 장치 En
	mPeri->CTLR1 = 0x202C;

	return true;
}

bool Uart::send(void *src, unsigned int size, unsigned int timeout)
{
	bool result;

	if(mTxDma == 0)
		return false;

	mTxDma->lock();

	setBitData(mPeri->CTLR3, true, 7);		// TX DMA 활성화

	mPeri->STR = ~USART_STR_TC;

	if (mPeri->CTLR3 & USART_CTLR3_DENT)	// Half-Duplex 활성화시
		setBitData(mPeri->CTLR1, false, 2);	// RX 비활성화
	
	result = mTxDma->send(mTxDmaInfo, src, size, timeout);

	if(result)
		while (!(mPeri->STR & USART_STR_TC))
			thread::yield();

	if (mPeri->CTLR3 & USART_CTLR3_DENT)	// Half-Duplex 활성화시
		setBitData(mPeri->CTLR1, true, 2);	// RX 활성화

	setBitData(mPeri->CTLR3, false, 7);		// TX DMA 비활성화

	mTxDma->unlock();

	return result;
}

bool Uart::send(const void *src, unsigned int size, unsigned int timeout)
{
	bool result;

	if(mTxDma == 0)
		return false;

	mTxDma->lock();

	setBitData(mPeri->CTLR3, true, 7);		// TX DMA 활성화

	if (mPeri->CTLR3 & USART_CTLR3_DENT)	// Half-Duplex 활성화시
		setBitData(mPeri->CTLR1, false, 2);	// RX 비활성화

	mPeri->STR = ~USART_STR_TC;
	
	result = mTxDma->send(mTxDmaInfo, (char*)src, size, timeout);

	if(result)
		while (!(mPeri->STR & USART_STR_TC))
			thread::yield();

	if (mPeri->CTLR3 & USART_CTLR3_DENT)	// Half-Duplex 활성화시
		setBitData(mPeri->CTLR1, true, 2);	// RX 활성화

	setBitData(mPeri->CTLR3, false, 7);		// TX DMA 비활성화
	mTxDma->unlock();

	return result;
}

void Uart::send(char data)
{
	mPeri->STR = ~USART_STR_TC;
	mPeri->DR = data;
	while (~mPeri->STR & USART_STR_TC)
		thread::yield();
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
	unsigned int sr = mPeri->STR;

	push(mPeri->DR);

	if (sr & (1 << 3))
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
}
#endif
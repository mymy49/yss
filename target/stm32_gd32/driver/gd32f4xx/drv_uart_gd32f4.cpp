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

#if false

#include <drv/Uart.h>
#include <yss/reg.h>
#include <util/Timeout.h>

enum
{
	STAT0 = 0, DATA, BAUD, CTL0, CTL1, CTL2, GP, CTL3, RT, STAT1, CHC
};

Uart::Uart(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mPeri = config.peri;
	mRcvBuf = 0;
	mTail = 0;
	mHead = 0;
}

error Uart::init(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize)
{
	int32_t  man, fra, buf;
	int32_t  clk = Drv::getClockFrequency() >> 4;

	mRcvBuf = (int8_t*)receiveBuffer;
	mRcvBufSize = receiveBufferSize;

	man = clk / baud;
	man &= 0xfff;
	fra = 16 * (clk % baud) / baud;
	fra &= 0xf;
	
	// 장치 비활성화
	setBitData(mPeri[CTL0], false, 13);
	
	// 보레이트 설정
	setTwoFieldData(mPeri[BAUD], 0xFFF << 4, man, 4, 0xF << 0, fra, 0);
	
	// TX En, RX En, Rxnei En, 장치 En
	mPeri[CTL0] = 0x202C;
	mPeri[CTL2] |= USART_CTL2_DENT;

	return Error::NONE;
}

error Uart::send(void *src, int32_t  size)
{
	error result;
	mTxDma->lock();

	mPeri[STAT0] = ~USART_STAT0_TC;

	if(mOneWireModeFlag)
		setBitData(mPeri[CTL0], false, 2);	// RX 비활성화
	
	result = mTxDma->transfer(mTxDmaInfo, src, size);

	if(result == Error::NONE)
	{
		while (!(mPeri[STAT0] & USART_STAT0_TC))
			thread::yield();
	}

	if(mOneWireModeFlag)
		setBitData(mPeri[CTL0], true, 2);	// RX 비활성화

	mTxDma->unlock();

	return Error::NONE;

error_handler:
	mTxDma->unlock();
	return result;
}

void Uart::send(int8_t data)
{
	mPeri[STAT0] = ~USART_STAT0_TC;
	mPeri[DATA] = data;
	while (!(mPeri[STAT0] & USART_STAT0_TC))
		thread::yield();
}

void Uart::isr(void)
{
	uint32_t sr = mPeri[STAT0];

	push(mPeri[DATA]);

	if (sr & (1 << 3))
	{
		flush();
	}
}

#endif


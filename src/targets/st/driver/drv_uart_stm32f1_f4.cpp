////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F4_N) || defined (STM32F1_N)

#include <drv/peripheral.h>
#include <drv/Uart.h>
#include <yss/thread.h>
#include <yss/reg.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#elif defined(STM32F103xB) || defined(STM32F103xE)
#include <targets/st/bitfield_stm32f103xx.h>
#endif

Uart::Uart(const Drv::Setup drvSetup, const Setup setup) : Drv(drvSetup)
{
	mTxDma = &setup.txDma;
	mTxDmaInfo = setup.txDmaInfo;
	mDev = setup.dev;
	mRcvBuf = 0;
	mTail = 0;
	mHead = 0;
	mOneWireModeFlag = false;
}

error Uart::initialize(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize)
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
	setBitData(mDev->CR1, false, USART_CR1_UE_Pos);
	
	// 보레이트 설정
	setTwoFieldData(mDev->BRR,	USART_BRR_DIV_Mantissa_Msk, man, USART_BRR_DIV_Mantissa_Pos, 
								USART_BRR_DIV_Fraction_Msk, fra, USART_BRR_DIV_Fraction_Pos);
	
	// TX En, RX En, Rxnei En, 장치 En
	mDev->CR1 = USART_CR1_RE_Msk | USART_CR1_TE_Msk | USART_CR1_RXNEIE_Msk | USART_CR1_UE_Msk;

	return error::ERROR_NONE;
}

error Uart::send(void *src, int32_t  size)
{
	error result;

	if(size == 0)
		return error::ERROR_NONE;

	if(mTxDma == 0)
		return error::DMA;

	mTxDma->lock();

	setBitData(mDev->CR3, true, 7);		// TX DMA 활성화

	mDev->SR = ~USART_SR_TC;

	if(mOneWireModeFlag)
		setBitData(mDev->CR1, false, 2);	// RX 비활성화
	
	result = mTxDma->send(mTxDmaInfo, src, size);

	if(result == error::ERROR_NONE)
		while (!(mDev->SR & USART_SR_TC))
			thread::yield();

	if(mOneWireModeFlag)
		setBitData(mDev->CR1, true, 2);	// RX 활성화

	setBitData(mDev->CR3, false, 7);		// TX DMA 비활성화

	mTxDma->unlock();

	return result;
}

void Uart::send(int8_t data)
{
	if(mOneWireModeFlag)
		setBitData(mDev->CR1, false, 2);	// RX 비활성화

	mDev->SR = ~USART_SR_TC;
	mDev->DR = data;
	while (~mDev->SR & USART_SR_TC)
		thread::yield();

	if(mOneWireModeFlag)
		setBitData(mDev->CR1, true, 2);	// RX 활성화
}

void Uart::isr(void)
{
	uint32_t sr = mDev->SR;

	push(mDev->DR);

	if (sr & (1 << 3))
	{
		flush();
	}
}

#endif


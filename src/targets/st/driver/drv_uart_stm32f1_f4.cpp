////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F4) || defined (STM32F1) || defined(GD32F1)

#include <drv/peripheral.h>
#include <drv/Uart.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

Uart::Uart(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mTxDma = &setup.txDma;
	mTxDmaInfo = setup.txDmaInfo;
	mDev = setup.dev;
	mRcvBuf = 0;
	mTail = 0;
	mHead = 0;
	mOneWireModeFlag = false;
}

error_t Uart::initialize(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize)
{
	int32_t  man, fra;
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

	return error_t::ERROR_NONE;
}

error_t Uart::setStopBit(stopbit_t stopBit)
{
	bool enableFlag;

	enableFlag = (mDev->CR1 & USART_CR1_UE_Msk) == USART_CR1_UE_Msk;
	if(enableFlag)
		mDev->CR1 &= ~USART_CR1_UE_Msk;
	
	setFieldData(mDev->CR2, USART_CR2_STOP_Msk, stopBit, USART_CR2_STOP_Pos);

	if(enableFlag)
		mDev->CR1 |= USART_CR1_UE_Msk;

	return error_t::ERROR_NONE;
}

void Uart::setOneWireMode(bool en)
{
	mOneWireModeFlag = en;
	setBitData(mDev->CR3, en, USART_CR3_HDSEL_Pos);
}

error_t Uart::send(void *src, int32_t  size)
{
	error_t result;

	if(size == 0)
		return error_t::ERROR_NONE;

	if(mTxDma == 0)
		return error_t::DMA_ERROR;

	mTxDma->lock();

	setBitData(mDev->CR3, true, 7);		// TX DMA 활성화

	mDev->SR = ~USART_SR_TC;

	if(mOneWireModeFlag)
	{
		setBitData(mDev->CR1, false, USART_CR1_RE_Pos);	// RX 비활성화
		setBitData(mDev->CR1, true, USART_CR1_TE_Msk);	// TX 활성화
	}

	result = mTxDma->send(mTxDmaInfo, src, size);

	if(result == error_t::ERROR_NONE)
		while (!(mDev->SR & USART_SR_TC))
			thread::yield();

	if(mOneWireModeFlag)
	{
		setBitData(mDev->CR1, true, USART_CR1_RE_Pos);	// RX 활성화
		setBitData(mDev->CR1, false, USART_CR1_TE_Msk);	// TX 비활성화
	}

	setBitData(mDev->CR3, false, 7);		// TX DMA 비활성화

	mTxDma->unlock();

	return result;
}

void Uart::send(int8_t data)
{
	if(mOneWireModeFlag)
	{
		setBitData(mDev->CR1, false, 2);	// RX 비활성화
	}

	mDev->SR = ~USART_SR_TC;
	mDev->DR = data;
	while (~mDev->SR & USART_SR_TC)
		thread::yield();

	if(mOneWireModeFlag)
	{
		setBitData(mDev->CR1, true, 2);	// RX 활성화
	}
}

void Uart::isr(void)
{
	uint32_t sr = mDev->SR;

	if(sr & (USART_SR_FE_Msk | USART_SR_ORE_Msk | USART_SR_NE_Msk))
	{
		if(sr & USART_SR_FE_Msk && mIsrForFrameError)
			mIsrForFrameError();

		if(sr & USART_SR_ORE_Msk)
			__NOP();

		mDev->DR;
		mDev->SR = USART_SR_FE_Msk | USART_SR_ORE_Msk | USART_SR_NE_Msk;
	}
	else if(mIsrForRxData)
		mIsrForRxData(mDev->DR);
	else
		push(mDev->DR);
}

#endif


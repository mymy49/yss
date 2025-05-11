/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F0) || defined(STM32F7) || defined(STM32G4)

#include <drv/peripheral.h>
#include <drv/Uart.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <targets/st/bitfield.h>

Uart::Uart(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
#if defined(YSS__UART_RX_DMA)
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mDev = setup.dev;
	mRcvBuf = 0;
	mTail = 0;
	mOneWireModeFlag = false;
	mIsrForFrameError = 0;
	mIsrForRxData = 0;
	mRxDma = 0;
#else
	mTxDma = &setup.txDma;
	mTxDmaInfo = setup.txDmaInfo;
	mDev = setup.dev;
	mRcvBuf = 0;
	mTail = 0;
	mHead = 0;
	mIsrForFrameError = 0;
	mIsrForRxData = 0;
#endif
}
/*
error_t Uart::initializeAsTransmitterOnly(int32_t baud)
{
	int32_t  man, fra;
	int32_t  clk = Drv::getClockFrequency() >> 4;

	man = clk / baud;
	man &= 0xfff;
	fra = 16 * (clk % baud) / baud;
	fra &= 0xf;
	
	// 장치 비활성화
	setBitData(mDev->CR1, false, 13);
	
	// 보레이트 설정
	setTwoFieldData(mDev->BRR, 0xFFF << 4, man, 4, 0xF << 0, fra, 0);

#if defined(STM32G4)
	// DMA 활성화
	mDev->CR3 = USART_CR3_DMAT_Msk;		// TX DMA 활성화
#endif
	
	// TX En, 장치 En
	mDev->CR3 |= USART_CR3_EIE_Msk;
	mDev->CR1 = USART_CR1_TE_Msk | USART_CR1_UE_Msk;

	return error_t::ERROR_NONE;
}
*/
error_t Uart::initialize(config_t config)
{
	int32_t  man, fra;
	int32_t  clk = Drv::getClockFrequency() >> 4;

	man = clk / config.baudrate;
	man &= 0xfff;
	fra = 16 * (clk % config.baudrate) / config.baudrate;
	fra &= 0xf;
	
	// 장치 비활성화
	setBitData(mDev->CR1, false, 13);
	
	// 보레이트 설정
	setTwoFieldData(mDev->BRR, 0xFFF << 4, man, 4, 0xF << 0, fra, 0);
	
	// Stop bit 설정
	setFieldData(mDev->CR2, USART_CR2_STOP_Msk, config.stopbit, USART_CR2_STOP_Pos);
	
#if defined(STM32G4)
	// DMA 활성화
	mTail = mRcvBufSize;
	mDev->CR3 = USART_CR3_DMAT_Msk | USART_CR3_DMAR_Msk;		// TX, RX DMA 활성화
	mRxDma = getOccupancyDma();
	mRxDma->transferAsCircularMode(&mRxDmaInfo, receiveBuffer, receiveBufferSize);
#endif
	
	mDev->CR1 = 0;
	mMode = config.mode;

	switch((uint8_t)config.mode)
	{
	case MODE_ONE_WIRE :
	case MODE_NORMAL :
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
		mDev->CR1 |= USART_CR1_TE_Msk;
#pragma GCC diagnostic pop

		// 고의로 break 누락

	case MODE_RX_ONLY :
#if defined(STM32G4)
		mDev->CR1 |= USART_CR1_RE_Msk;
#else
		mDev->CR1 |= USART_CR1_RE_Msk | USART_CR1_RXNEIE_Msk;
#endif
		// 수신 버퍼 설정
		if(config.rcvBuf == nullptr)
			mRcvBuf = new int8_t[config.rcvBufSize];
		else
			mRcvBuf = (int8_t*)config.rcvBuf;

		mRcvBufSize = config.rcvBufSize;
		break;
	
	case MODE_TX_ONLY :
		mDev->CR1 |= USART_CR1_TE_Msk;
		break;
	}

	// TX En, RX En, Rxnei En, 장치 En
#if defined(STM32G4)
	mDev->CR3 |= USART_CR3_EIE_Msk;
	mDev->CR1 = USART_CR1_TE_Msk | USART_CR1_RE_Msk | USART_CR1_UE_Msk;
#else
	mDev->CR3 |= USART_CR3_EIE_Msk;
	mDev->CR1 |= USART_CR1_UE_Msk;
#endif
	return error_t::ERROR_NONE;
}

void Uart::enable(bool en)
{
	mDev->ICR = 0xFFFFFFFF;
	setBitData(mDev->CR1, en, USART_CR1_UE_Pos);
}

error_t Uart::changeBaudrate(int32_t baud)
{
	int32_t  man, fra;
	int32_t  clk = Drv::getClockFrequency() >> 4;
	bool enableFlag;

	man = clk / baud;
	man &= 0xfff;
	fra = 16 * (clk % baud) / baud;
	fra &= 0xf;
	
	enableFlag = (mDev->CR1 & USART_CR1_UE_Msk) == USART_CR1_UE_Msk;
	if(enableFlag)
		mDev->CR1 &= ~USART_CR1_UE_Msk;
	
	setTwoFieldData(mDev->BRR, 0xFFF << 4, man, 4, 0xF << 0, fra, 0);

	if(enableFlag)
		mDev->CR1 |= USART_CR1_UE_Msk;

	return error_t::ERROR_NONE;
}

#if defined(STM32F0) || defined(STM32F7)
error_t Uart::send(void *src, int32_t  size)
{
	error_t result;

	if(size == 0)
		return error_t::ERROR_NONE;

	if(mTxDma == 0)
		return error_t::DMA_ERROR;

	mTxDma->lock();

	setBitData(mDev->CR3, true, USART_CR3_DMAT_Pos);	// TX DMA 활성화

	mDev->ICR = USART_ICR_TCCF_Msk;

	if(mMode == MODE_ONE_WIRE)
	{
		setBitData(mDev->CR1, false, USART_CR1_RE_Pos);	// RX 비활성화
	}
		
	result = mTxDma->transfer(mTxDmaInfo, src, size);

	if(result == error_t::ERROR_NONE)
		while (!(mDev->ISR & USART_ISR_TC_Msk))
			thread::yield();

	if(mMode == MODE_ONE_WIRE)
	{
		setBitData(mDev->CR1, true, USART_CR1_RE_Pos);	// RX 활성화
	}

	setBitData(mDev->CR3, false, USART_CR3_DMAT_Pos);		// TX DMA 비활성화

	mTxDma->unlock();

	return result;
}
#elif defined(STM32G4)
error_t Uart::send(void *src, int32_t  size)
{
	error_t result;
	Dma *dma;

	if(size == 0)
		return error_t::ERROR_NONE;

	mDev->ICR = USART_ICR_TCCF_Msk;

	if(mOneWireModeFlag)
	{
		setBitData(mDev->CR1, false, USART_CR1_RE_Pos);	// RX 비활성화
	}

	dma = getIdleDma();
	
	result = dma->transfer(mTxDmaInfo, src, size);

	if(result == error_t::ERROR_NONE)
	{
		while (!(mDev->ISR & USART_ISR_TC_Msk))
			thread::yield();
	}

	if(mOneWireModeFlag)
	{
		setBitData(mDev->CR1, true, USART_CR1_RE_Pos);	// RX 활성화
	}

	dma->unlock();

	return result;
}
#endif

void Uart::send(int8_t data)
{
	if(mMode == MODE_ONE_WIRE)
	{
		setBitData(mDev->CR1, false, USART_CR1_RE_Pos);	// RX 비활성화
	}

	mDev->ICR = USART_ICR_TCCF_Msk;
	mDev->TDR = data;
	while (~mDev->ISR & USART_ISR_TC)
		thread::yield();

	if(mMode == MODE_ONE_WIRE)
	{
		setBitData(mDev->CR1, true, USART_CR1_RE_Pos);	// RX 활성화
	}
}

void Uart::isr(void)
{
	uint32_t sr = mDev->ISR;

	if(sr & (USART_ISR_FE_Msk | USART_ISR_ORE_Msk | USART_ISR_NE_Msk))
	{
		if(sr & USART_ISR_FE_Msk && mIsrForFrameError)
			mIsrForFrameError();

		if(sr & USART_ISR_ORE_Msk)
			__NOP();

		mDev->RDR;
#if defined(STM32G4)
		mDev->ICR = USART_ICR_FECF_Msk | USART_ICR_ORECF_Msk | USART_ICR_NECF_Msk;
#else
		mDev->ICR = USART_ICR_FECF_Msk | USART_ICR_ORECF_Msk | USART_ICR_NCF_Msk;
#endif
	}
	else if(mIsrForRxData)
		mIsrForRxData(mDev->RDR);
	else
		push(mDev->RDR);
}

#endif


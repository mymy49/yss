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
	mOneWireModeFlag = false;
	mIsrForFrameError = 0;
	mIsrForRxData = 0;
#endif
}

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
	setBitData(mDev->CR1, false, 13);
	
	// 보레이트 설정
	setTwoFieldData(mDev->BRR, 0xFFF << 4, man, 4, 0xF << 0, fra, 0);
	
#if defined(STM32G4)
	// DMA 활성화
	mTail = mRcvBufSize;
	mDev->CR3 = USART_CR3_DMAT_Msk | USART_CR3_DMAR_Msk;		// TX, RX DMA 활성화
	mRxDma = getOccupancyDma();
	mRxDma->transferAsCircularMode(&mRxDmaInfo, receiveBuffer, receiveBufferSize);
#endif

	// TX En, RX En, Rxnei En, 장치 En
#if defined(STM32G4)
	mDev->CR3 |= USART_CR3_EIE_Msk;
	mDev->CR1 = USART_CR1_TE_Msk | USART_CR1_RE_Msk | USART_CR1_UE_Msk;
#else
	mDev->CR3 |= USART_CR3_EIE_Msk;
	mDev->CR1 = USART_CR1_TE_Msk | USART_CR1_RE_Msk | USART_CR1_UE_Msk | USART_CR1_RXNEIE_Msk;
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

	if(mOneWireModeFlag)
	{
		setBitData(mDev->CR1, false, USART_CR1_RE_Pos);	// RX 비활성화
	}
		
	result = mTxDma->send(mTxDmaInfo, src, size);

	if(result == error_t::ERROR_NONE)
		while (!(mDev->ISR & USART_ISR_TC_Msk))
			thread::yield();

	if(mOneWireModeFlag)
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
	if(mOneWireModeFlag)
	{
		setBitData(mDev->CR1, false, USART_CR1_RE_Pos);	// RX 비활성화
	}

	mDev->ICR = USART_ICR_TCCF_Msk;
	mDev->TDR = data;
	while (~mDev->ISR & USART_ISR_TC)
		thread::yield();

	if(mOneWireModeFlag)
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


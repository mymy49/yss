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

#if defined(W7500)

#include <drv/peripheral.h>
#include <drv/Uart.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/wiznet/bitfield_w7500x.h>

Uart::Uart(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
}

error_t Uart::initialize(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize)
{
	int32_t  brdi, brdf;
	int32_t  clk = Drv::getClockFrequency() >> 4;

	brdi = clk / baud;
	if(brdi > 0xFFFF)
		return error_t::WRONG_CONFIG;

	brdf = 64 * (clk % baud) / baud;
	
	// 장치 비활성화
	mDev->CR &= ~UART_CR_UARTEN;
	
	// 보레이트 설정
	mDev->IBRD = brdi;
	mDev->FBRD = brdf;

	// 전송 비트 설정
	mDev->LCR_H = UART_LCR_H_WLEN;
	
	// TX En, RX En, Rxnei En, 장치 En
	mDev->CR |= UART_CR_RXE | UART_CR_TXE | UART_CR_UARTEN;

	// RX 인터럽트 활성화
	mDev->IMSC |= UART_IMSC_RXIM;

	mRcvBuf = (int8_t*)receiveBuffer;
	mRcvBufSize = receiveBufferSize;

	return error_t::ERROR_NONE;
}

error_t Uart::changeBaudrate(int32_t baud)
{
	int32_t  brdi, brdf;
	int32_t  clk = Drv::getClockFrequency() >> 4;
	bool enableFlag;

	brdi = clk / baud;
	if(brdi > 0xFFFF)
		return error_t::WRONG_CONFIG;

	brdf = 64 * (clk % baud) / baud;
	
	enableFlag = (mDev->CR & UART_CR_UARTEN) == UART_CR_UARTEN;
	if(enableFlag)
		mDev->CR &= ~UART_CR_UARTEN;
	
	// 보레이트 설정
	mDev->IBRD = brdi;
	mDev->FBRD = brdf;

	if(enableFlag)
		mDev->CR |= UART_CR_UARTEN;

	return error_t::ERROR_NONE;
}

error_t Uart::setStopBit(stopbit_t stopBit)
{
	bool enableFlag;

	enableFlag = (mDev->CR & UART_CR_UARTEN) == UART_CR_UARTEN;
	if(enableFlag)
		mDev->CR &= ~UART_CR_UARTEN;
	
	setFieldData(mDev->LCR_H, 1 << 3, stopBit, 3);

	if(enableFlag)
		mDev->CR |= UART_CR_UARTEN;

	return error_t::ERROR_NONE;
}

error_t Uart::send(void *src, int32_t  size)
{
	uint8_t *csrc = (uint8_t*)src;

	if(size == 0)
		return error_t::ERROR_NONE;

	for(int32_t i = 0; i < size; i++)
		send(*csrc++);

	return error_t::ERROR_NONE;
}

void Uart::send(int8_t data)
{
	if(mOneWireModeFlag)
	{
		mDev->CR &= ~UART_CR_RXE;	// RX 비활성화
	}

	mDev->DR = data;
	while (mDev->FR & UART_FR_BUSY)
		thread::yield();

	if(mOneWireModeFlag)
	{
		mDev->CR |= UART_CR_RXE;	// RX 활성화
	}
}

void Uart::isr(void)
{
	push(mDev->DR);
}
#endif


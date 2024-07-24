/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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


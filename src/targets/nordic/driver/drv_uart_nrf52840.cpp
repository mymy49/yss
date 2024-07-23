/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <drv/Uart.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <util/Timeout.h>
#include <targets/nordic/nrf52840_bitfields.h>

Uart::Uart(const Drv::setup_t drvConfig, const Config config) : Drv(drvConfig)
{
	mDev = config.dev;
	mRcvBuf = 0;
	mTail = 0;
	mHead = 0;
	mOneWireModeFlag = false;
}

error Uart::initialize(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize)
{
	mRcvBuf = (int8_t*)receiveBuffer;
	mRcvBufSize = receiveBufferSize;
		
	// 장치 비활성화
	mDev->ENABLE = 0;

	// 보레이트 설정
	mDev->BAUDRATE = (int32_t )(268.435456f * (float)baud);
	
	// TX En, RX En, Rxnei En, 장치 En
	mDev->INTENSET = UART_INTENSET_RXDRDY_Msk;
	mDev->TASKS_STARTRX = 1;
	mDev->TASKS_STARTTX = 1;
	mDev->ENABLE = UART_ENABLE_ENABLE_Enabled;
	
	return error::ERROR_NONE;
}

error Uart::send(void *src, int32_t  size)
{
	error result;
	int8_t *data = (int8_t*)src;
	
	if(mOneWireModeFlag)
		mDev->TASKS_STOPRX = 1;

	for(uint32_t i=0;i<size;i++)
	{
		mDev->EVENTS_TXDRDY = 0;
		mDev->TXD = *data++;

		while(!mDev->EVENTS_TXDRDY)
			thread::yield();
	}

	mDev->EVENTS_TXDRDY = 0;

	return error::ERROR_NONE;
error_handler :
	if(mOneWireModeFlag)
		mDev->TASKS_STARTRX = 1;
	
	return result;
}

void Uart::send(int8_t data)
{
	if(mOneWireModeFlag)
		mDev->TASKS_STOPRX = 1;

	while(!mDev->EVENTS_TXDRDY)
		thread::yield();
	mDev->EVENTS_TXDRDY = 0;
	
	mDev->TXD = data;

	while(!mDev->EVENTS_TXDRDY)
		thread::yield();

	if(mOneWireModeFlag)
		mDev->TASKS_STARTRX = 1;
}

void Uart::isr(void)
{
	push(mDev->RXD);
	mDev->EVENTS_RXDRDY = 0;
}

#endif


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
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <drv/Uart.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <util/Timeout.h>
#include <targets/nordic/nrf52840_bitfields.h>

Uart::Uart(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
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


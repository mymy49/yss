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

#if defined(__M480_FAMILY)

#include <yss.h>
#include <drv/peripheral.h>
#include <drv/Uart.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m48x.h>

Uart::Uart(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
}

error_t Uart::initialize(int32_t  baud, void *receiveBuffer, int32_t  receiveBufferSize)
{
	error_t result;
	
	// 보레이트 설정
	result = changeBaudrate(baud);
	if(result != error_t::ERROR_NONE)
		return result;
	
	// 데이터 길이를 8 Bit로 설정
	setFieldData(mDev->LINE, UART_LINE_WLS_Msk, 0x3, UART_LINE_WLS_Pos);

	// RX 인터럽트 활성화
	setBitData(mDev->INTEN, true, UART_INTEN_RDAIEN_Pos);
	setBitData(mDev->INTEN, true, UART_INTEN_TXPDMAEN_Pos);
	
	// 수신 버퍼 설정
	mRcvBuf = (int8_t*)receiveBuffer;
	mRcvBufSize = receiveBufferSize;

	mTxDma = allocateDma();
	if(mTxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mTxDma->setSource(mTxDmaInfo.src);

	return error_t::ERROR_NONE;
}

error_t Uart::changeBaudrate(int32_t baud)
{
	int32_t  clk = Drv::getClockFrequency();
	int16_t  brd;

	brd = clk / (baud * 16);
	if(brd > 0xFFFF)
		return error_t::WRONG_CONFIG;
	
	setFieldData(mDev->BAUD, UART_BAUD_BRD_Msk, brd, UART_BAUD_BRD_Pos);

	return error_t::ERROR_NONE;
}

error_t Uart::setStopBit(stopbit_t stopBit)
{
	setFieldData(mDev->LINE, UART_LINE_NSB_Msk, stopBit, UART_LINE_NSB_Pos);

	return error_t::ERROR_NONE;
}

error_t Uart::send(void *src, int32_t  size)
{
	if(size == 0)
		return error_t::ERROR_NONE;

	mTxDma->transfer(mTxDmaInfo, src, size);

	return error_t::ERROR_NONE;
}

void Uart::send(int8_t data)
{
	mDev->DAT = data;
	while (~mDev->INTSTS & UART_INTSTS_TXENDIF_Msk)
		thread::yield();
}

void Uart::isr(void)
{
	push(mDev->DAT);
}
#endif


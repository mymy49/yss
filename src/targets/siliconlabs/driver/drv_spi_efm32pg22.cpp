/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(EFM32PG22)

#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <util/Timeout.h>
#include <targets/siliconlabs/efm32pg22_usart.h>

Spi::Spi(const Drv::setup_t drvSetup, const Setup setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mDmaChannelList = setup.dmaChannelList;
	mTxDmaInfo = setup.txDmaInfo;
}

error Spi::initializeAsMain(void)
{
	// 장치 비활성화
	mDev->EN_SET = _USART_EN_EN_MASK;

	// TX En, RX En, Rxnei En, 장치 En
	mDev->CTRL = _USART_CTRL_SYNC_MASK;
	mDev->CMD = _USART_CMD_RXEN_MASK | _USART_CMD_TXEN_MASK | _USART_CMD_MASTEREN_MASK;
	mDev->IEN_SET = _USART_IEN_RXDATAV_MASK;

	return error::ERROR_NONE;
}

error Spi::setSpecification(const specification_t &spec)
{
	if (mLastSpec == &spec)
		return error::ERROR_NONE;
	mLastSpec = &spec;

	uint32_t div;
	float buf = Drv::getClockFrequency();

	// 보레이트 설정
	buf = 32.f * (buf / ((float)spec.maxFreq * 2.f) - 1.f);
	div = buf;
	if(buf - div > 0.f)
		div++;

	if(div > 0xFFFFF)
		return error::WRONG_CLOCK_FREQUENCY;

	setFieldData(mDev->CLKDIV, _USART_CLKDIV_DIV_MASK, div, _USART_CLKDIV_DIV_SHIFT);
	setFieldData(mDev->FRAME, _USART_FRAME_DATABITS_MASK, spec.bit, _USART_FRAME_DATABITS_SHIFT);
	setFieldData(mDev->CTRL, _USART_CTRL_CLKPOL_MASK | _USART_CTRL_CLKPHA_MASK, spec.mode, _USART_CTRL_CLKPOL_SHIFT);

	return error::ERROR_NONE;
}

void Spi::enable(bool en)
{
}

void Spi::send(int8_t data)
{
	mDev->IF_CLR = 0xFFFF;
	mDev->TXDATA = data;

	while(~mDev->IF & _USART_IF_TXC_MASK)
		thread::yield();
}

/*
error Uart::send(void *src, int32_t  size)
{
	error result;
	int8_t *data = (int8_t*)src;
	uint8_t ch;

	while(1)
	{
		for(ch=0;ch<8;ch++)
		{
			if(mDmaChannelList[ch]->check())
				goto sending;
		}
		thread::yield();
	}

sending:
	mDmaChannelList[ch]->transfer(*(Dma::dmaInfo_t*)mTxDmaInfo, src, size);
	
	mDmaChannelList[ch]->unlock();
	return error::ERROR_NONE;
}

void Uart::send(int8_t data)
{
	mDev->IF_CLR = 0xFFFF;
	mDev->TXDATA = data;

	while(~mDev->IF & _USART_IF_TXC_MASK)
		thread::yield();
}
*/
void Spi::isr(void)
{
//	push(mDev->RXDATA);
}

#endif


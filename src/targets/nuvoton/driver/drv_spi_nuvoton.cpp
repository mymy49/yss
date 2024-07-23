/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

#include <yss.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m48x.h>

Spi::Spi(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mLastSpec = nullptr;
	mTxDma = nullptr;
	mRxDma = nullptr;
}

error_t Spi::setSpecification(const specification_t &spec)
{
	if (mLastSpec == &spec)
		return error_t::ERROR_NONE;
	mLastSpec = &spec;

	uint32_t reg;
	uint32_t div, clk = Drv::getClockFrequency();
	
	div = clk / spec.maxFreq;
	if(clk % spec.maxFreq == 0 && div > 0)
		div--;

	if(div > 0x1FF)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	reg = mDev->CTL;
	reg &= ~(SPI_CTL_DWIDTH_Msk);
	reg |= spec.bit << SPI_CTL_DWIDTH_Pos;
	mDev->CTL = reg;

	mDev->CLKDIV = div;

	return error_t::ERROR_NONE;
}

error_t Spi::initializeAsMain(void)
{
	mDev->CTL = 0x00000034;	// Reset Value
	mDev->PDMACTL = SPI_PDMACTL_RXPDMAEN_Msk | SPI_PDMACTL_TXPDMAEN_Msk;

	mTxDma = allocateDma();
	if(mTxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mRxDma = allocateDma();
	if(mRxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mTxDma->setSource(mTxDmaInfo.src);
	mRxDma->setSource(mRxDmaInfo.src);

	return error_t::ERROR_NONE;
}

error_t Spi::initializeAsSub(void)
{

	return error_t::ERROR_NONE;
}

void Spi::enable(bool en)
{
	setBitData(mDev->CTL, en, SPI_CTL_SPIEN_Pos);
}

error_t Spi::send(void *src, int32_t  size)
{
	if(size == 0)
		return error_t::ERROR_NONE;
	
	mRxDma->ready(mRxDmaInfo, src, size);
	mTxDma->transfer(mTxDmaInfo, src, size);

	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();

	return error_t::ERROR_NONE;
}

error_t Spi::exchange(void *des, int32_t  size)
{
	return error_t::ERROR_NONE;
}

void Spi::receiveAsCircularMode(void *src, uint16_t count)
{

}

uint8_t Spi::exchange(uint8_t data)
{
	*(uint8_t*)&mDev->TX = data;

	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();

	return mDev->RX;
}

void Spi::send(uint8_t data)
{
	*(int8_t*)&mDev->TX = data;
	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();
}

void Spi::isr(void)
{

	thread::signal(mThreadId);
}

#endif

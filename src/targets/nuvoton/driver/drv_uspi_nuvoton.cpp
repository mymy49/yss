/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)

#include <yss.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonUspi.h>
#include <yss/thread.h>
#include <yss/reg.h>

#if defined(USPI0)

NuvotonUspi::NuvotonUspi(const Drv::setup_t drvSetup, const setup_t setup) : Spi(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mTxDma = nullptr;
	mRxDma = nullptr;
}

error_t NuvotonUspi::setSpecification(const specification_t &spec)
{
	if (mLastSpec == &spec)
		return error_t::ERROR_NONE;

	uint32_t reg, bit;
	uint32_t div, clk = Drv::getClockFrequency();
	
	div = clk / spec.maxFreq;
	if(clk % spec.maxFreq == 0 && div > 0)
		div--;

	if(div > 0x3FF)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	if(spec.bit < BIT_BIT4)
	{
		return error_t::UNSUPPORTED_CONFIG;
	}
	if(spec.bit <= BIT_BIT8)
	{
	}
	else if(spec.bit <= BIT_BIT16)
	{
		mTxDmaInfo.ctl |= PDMA_WIDTH_16;
		mRxDmaInfo.ctl |= PDMA_WIDTH_16;
	}
	else
		return error_t::UNSUPPORTED_CONFIG;

	bit = spec.bit + 4 & 0xF;
	setFieldData(mDev->LINECTL, USPI_LINECTL_DWIDTH_Msk, bit, USPI_LINECTL_DWIDTH_Pos);
	setFieldData(mDev->PROTCTL, USPI_PROTCTL_SCLKMODE_Msk, spec.mode, USPI_PROTCTL_SCLKMODE_Pos);
	setFieldData(mDev->BRGEN, USPI_BRGEN_CLKDIV_Msk, div, USPI_BRGEN_CLKDIV_Pos);

	mLastSpec = &spec;

	return error_t::ERROR_NONE;
}

error_t NuvotonUspi::initialize(config_t config)
{
	mDev->CTL = 1 << USPI_CTL_FUNMODE_Pos;
	
	if(config.mode != MODE_MAIN)
		return error_t::NOT_SUPPORTED_YET;

	mDev->PROTCTL = 0;

	mTxDma = system::allocateDma();
	if(mTxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mRxDma = system::allocateDma();
	if(mRxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mDev->PDMACTL |= USPI_PDMACTL_PDMAEN_Msk | USPI_PDMACTL_RXPDMAEN_Msk | USPI_PDMACTL_TXPDMAEN_Msk;

	mTxDma->setSource(mTxDmaInfo.src);
	mRxDma->setSource(mRxDmaInfo.src);

	return error_t::ERROR_NONE;
}

void NuvotonUspi::enable(bool en)
{
	setBitData(mDev->PROTCTL, en, USPI_PROTCTL_PROTEN_Pos);
}

error_t NuvotonUspi::send(void *src, int32_t  size)
{
	if(size == 0)
		return error_t::ERROR_NONE;
	
	mTxDma->transfer(mTxDmaInfo, src, size);

	while (mDev->PROTSTS & USPI_PROTSTS_BUSY_Msk)
		thread::yield();

	return error_t::ERROR_NONE;
}

error_t NuvotonUspi::exchange(void *des, int32_t  size)
{
	if(size == 0)
		return error_t::ERROR_NONE;
	
	while(~mDev->BUFSTS & USPI_BUFSTS_RXEMPTY_Msk)
		mDev->RXDAT;

	mRxDma->ready(mRxDmaInfo, des, size);
	mTxDma->transfer(mTxDmaInfo, des, size);

	while (mDev->PROTSTS & USPI_PROTSTS_BUSY_Msk)
		thread::yield();

	return error_t::ERROR_NONE;
}

uint32_t NuvotonUspi::exchange(uint32_t data)
{
	while(~mDev->BUFSTS & USPI_BUFSTS_RXEMPTY_Msk)
		mDev->RXDAT;

	*(uint32_t*)&mDev->TXDAT = data;

	while (mDev->PROTSTS & USPI_PROTSTS_BUSY_Msk)
		thread::yield();

	return mDev->RXDAT;
}

void NuvotonUspi::send(uint32_t data)
{
	*(uint32_t*)&mDev->TXDAT = data;
	while (mDev->PROTSTS & USPI_PROTSTS_BUSY_Msk)
		thread::yield();
}

void NuvotonUspi::isr(void)
{

}

#endif

#endif


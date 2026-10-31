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
#include <targets/nuvoton/NuvotonSpi.h>
#include <yss/scheduler.h>
#include <yss/reg.h>
#include <util/runtime.h>

/**
 * @file drv_spi_nuvoton.cpp
 * @brief SPI target-specific driver source file for Nuvoton.
 */

#pragma GCC optimize("O1")

NuvotonSpi::NuvotonSpi(const Drv::setup_t drvSetup, const setup_t setup) : Spi(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mTxDma = nullptr;
	mRxDma = nullptr;
}


error_t NuvotonSpi::setSpecification(const specification_t &spec)
{
	if (mLastSpec == &spec)
		return error_t::ERROR_NONE;
	
	setBitData(mDev->CTL, false, SPI_CTL_SPIEN_Pos);

	uint32_t reg, bit;
	uint32_t div, clk = Drv::getClockFrequency(), mode = 0;
	
	div = clk / spec.maxFreq;
	if(clk % spec.maxFreq == 0 && div > 0)
		div--;

	if(div > 0x1FF)
		return error_t::WRONG_CLOCK_FREQUENCY;

	switch(spec.mode)
	{
	case 0 :
		mode = 0x3 << SPI_CTL_RXNEG_Pos;
		break;

	case 1 :
		mode = 0x0 << SPI_CTL_RXNEG_Pos;
		break;

	case 2 :
		mode = 0x7 << SPI_CTL_RXNEG_Pos;
		break;

	case 3 :
		mode = 0x4 << SPI_CTL_RXNEG_Pos;
		break;
	}

	mTxDmaInfo.ctl &= ~(PDMA_WIDTH_16 | PDMA_WIDTH_32);
	mRxDmaInfo.ctl &= ~(PDMA_WIDTH_16 | PDMA_WIDTH_32);
	
	if(spec.bit < BIT_BIT8)
	{
		return error_t::UNSUPPORTED_CONFIG;
	}
	else if(spec.bit == BIT_BIT8)
	{
	}
	else if(spec.bit <= BIT_BIT16)
	{
		mTxDmaInfo.ctl |= PDMA_WIDTH_16;
		mRxDmaInfo.ctl |= PDMA_WIDTH_16;
	}
	else 
	{
		mTxDmaInfo.ctl |= PDMA_WIDTH_32;
		mRxDmaInfo.ctl |= PDMA_WIDTH_32;
	}

	bit = (spec.bit + 4) & 0x1F;
	reg = mDev->CTL;
	reg &= ~(SPI_CTL_DWIDTH_Msk | SPI_CTL_RXNEG_Msk | SPI_CTL_TXNEG_Msk | SPI_CTL_CLKPOL_Msk);
	reg |= (bit << SPI_CTL_DWIDTH_Pos) | mode;
	mDev->CTL = reg;
	mDev->CLKDIV = div;

	mLastSpec = &spec;
	
	setBitData(mDev->CTL, true, SPI_CTL_SPIEN_Pos);

	return error_t::ERROR_NONE;
}

error_t NuvotonSpi::initialize(config_t config)
{
	mMode = config.mode;

	switch(mMode)
	{
	case Spi::MODE_MAIN :	
		mDev->CTL = 0x00000034;	// Reset Value
		break;
	
	default:
		return error_t::NOT_SUPPORTED_YET;
	}

	mTxDma = yss::allocateDma();
	if(mTxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mRxDma = yss::allocateDma();
	if(mRxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mTxDma->setSource(mTxDmaInfo.src);
	mRxDma->setSource(mRxDmaInfo.src);

	return error_t::ERROR_NONE;
}

error_t NuvotonSpi::send(void *src, int32_t  size, uint32_t timeout)
{
	uint64_t endTime = runtime::getUsec() + ++timeout * 1000 - 500;

	if(size == 0)
		return error_t::ERROR_NONE;
	
	mTxDma->ready(mTxDmaInfo, src, size);

	thread::resetWaitingSignalPendingFlag();

	mDev->PDMACTL = SPI_PDMACTL_TXPDMAEN_Msk;
	
	thread::waitForSignal(timeout);

	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();

	mDev->PDMACTL = 0;
	
	if(runtime::getUsec() >= endTime)
		return error_t::TIMEOUT;
	else
		return error_t::ERROR_NONE;
}

error_t NuvotonSpi::exchange(void *des, int32_t  size, uint32_t timeout)
{
	uint64_t endTime = runtime::getUsec() + ++timeout * 1000 - 500;

	if(size == 0)
		return error_t::ERROR_NONE;

	while(~mDev->STATUS & SPI_STATUS_RXEMPTY_Msk)
		mDev->RX;

	mRxDma->ready(mRxDmaInfo, des, size, true);
	mTxDma->ready(mTxDmaInfo, des, size, false);

	thread::resetWaitingSignalPendingFlag();

	mDev->PDMACTL = SPI_PDMACTL_RXPDMAEN_Msk | SPI_PDMACTL_TXPDMAEN_Msk;

	thread::waitForSignal(timeout);

	mDev->PDMACTL = 0;

	if(runtime::getUsec() >= endTime)
		return error_t::TIMEOUT;
	else
		return error_t::ERROR_NONE;
}

uint32_t NuvotonSpi::exchange(uint32_t data)
{
	*(uint32_t*)&mDev->TX = data;

	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();

	return mDev->RX;
}

void NuvotonSpi::send(uint32_t data)
{
	*(uint32_t*)&mDev->TX = data;
	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();
}

void NuvotonSpi::isr(void)
{

}

#endif

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

I2s::I2s(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mDma = nullptr;
	mBclk = 0;
	mMclk = 0;
}

error_t I2s::initialize(const specification_t &spec)
{
	int32_t clk, mclk, bclk, div = 1;
	uint32_t ctl = (spec.std << SPI_I2SCTL_FORMAT_Pos) | (spec.dataBit << SPI_I2SCTL_WDWIDTH_Pos) | SPI_I2SCTL_MCLKEN_Msk | SPI_I2SCTL_I2SEN_Msk ;
	
	clk = bclk = getClockFrequency();
	mDma = allocateDma();
	if(mDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	switch(spec.dataBit)
	{
	case BIT_8BIT :
		div = 16;
		break;
	case BIT_16BIT :
		div = 32;
		mTxDmaInfo.ctl |= PDMA_WIDTH_16;
		mRxDmaInfo.ctl |= PDMA_WIDTH_16;
		break;

	case BIT_24BIT :
	case BIT_32BIT :
		div = 64;
		mTxDmaInfo.ctl |= PDMA_WIDTH_32;
		mRxDmaInfo.ctl |= PDMA_WIDTH_32;
		break;
	}
	
	bclk /= div * 2;	
	mclk = bclk / 4;
	bclk = bclk / spec.sampleRate;
	bclk--;
	if(bclk < 0)
		return error_t::WRONG_CLOCK_FREQUENCY;
	
	mclk = mclk / spec.sampleRate;

	switch(spec.mode)
	{
	case MODE_MAIN_TX :
		ctl |= SPI_I2SCTL_TXEN_Msk;
		mDma->setSource(mTxDmaInfo.src);
		break;

	case MODE_MAIN_RX :
		ctl |= SPI_I2SCTL_RXEN_Msk;
		mDma->setSource(mRxDmaInfo.src);
		break;
	
	case MODE_SUB_TX :
		ctl |= SPI_I2SCTL_TXEN_Msk | SPI_I2SCTL_SLAVE_Msk;
		mDma->setSource(mTxDmaInfo.src);
		break;

	case MODE_SUB_RX :
		ctl |= SPI_I2SCTL_RXEN_Msk | SPI_I2SCTL_SLAVE_Msk;
		mDma->setSource(mRxDmaInfo.src);
		break;
	}
	
	mDev->PDMACTL |= SPI_PDMACTL_TXPDMAEN_Msk | SPI_PDMACTL_RXPDMAEN_Msk;

	mDev->I2SCLK = (mclk << SPI_I2SCLK_MCLKDIV_Pos) | (bclk << SPI_I2SCLK_BCLKDIV_Pos);

	mDev->I2SCTL = ctl;

	mBclk = clk / div / ((bclk + 1) * 2);

	if(mclk)
		mMclk = clk / (mclk * 2);
	else
		mMclk = clk;

	return error_t::ERROR_NONE;
}

uint32_t I2s::getBclkFrequency(void)
{
	return mBclk;
}

uint32_t I2s::getMclkFrequency(void)
{
	return mMclk;
}

error_t I2s::transfer(void *src, uint16_t count)
{
	if(count == 0)
		return error_t::ERROR_NONE;
	if(mDev->I2SCTL & SPI_I2SCTL_TXEN_Msk)
		return mDma->transferAsCircularMode(mTxDmaInfo, src, count);
	else
		return mDma->transferAsCircularMode(mRxDmaInfo, src, count);
}

/*
error_t Spi::setSpecification(const specification_t &spec)
{
	if (mLastSpec == &spec)
		return error_t::ERROR_NONE;
	mLastSpec = &spec;

	uint32_t reg;
	uint32_t div, clk = Drv::getClockFrequency(), mode = 0;
	
	div = clk / spec.maxFreq;
	if(clk % spec.maxFreq == 0 && div > 0)
		div--;

	if(div > 0x1FF)
		return error_t::WRONG_CLOCK_FREQUENCY;

	switch(spec.mode)
	{
	case 0 :
		mode = 0x0 << SPI_CTL_RXNEG_Pos;
		break;
	case 1 :
		mode = 0x3 << SPI_CTL_RXNEG_Pos;
		break;

	case 2 :
		mode = 0x4 << SPI_CTL_RXNEG_Pos;
		break;

	case 3 :
		mode = 0x7 << SPI_CTL_RXNEG_Pos;
		break;
	}
	
	reg = mDev->CTL;
	reg &= ~(SPI_CTL_DWIDTH_Msk | SPI_CTL_RXNEG_Msk | SPI_CTL_TXNEG_Msk | SPI_CTL_CLKPOL_Msk);
	reg |= (spec.bit << SPI_CTL_DWIDTH_Pos) | mode;
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
*/
#endif

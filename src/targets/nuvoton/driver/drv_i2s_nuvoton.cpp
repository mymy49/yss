/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <yss.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/nuvoton/bitfield_m4xx.h>

I2s::I2s(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mCurrentDma = nullptr;
	mDataSize = 0;
	mLrclk = 0;
	mMclk = 0;
}

error_t I2s::initialize(const config_t &spec)
{
	int32_t clk, mclk, bclk, div = 1;
	uint32_t ctl = (spec.std << SPI_I2SCTL_FORMAT_Pos) | (spec.dataBit << SPI_I2SCTL_WDWIDTH_Pos) | SPI_I2SCTL_MCLKEN_Msk | SPI_I2SCTL_I2SEN_Msk ;
	
	clk = bclk = getClockFrequency();
	mCurrentDma = allocateDma();
	if(mCurrentDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	switch(spec.dataBit)
	{
	case BIT_8BIT :
		div = 16;
		mDataSize = 1;
		break;
	case BIT_16BIT :
		div = 32;
		mTxDmaInfo.ctl |= PDMA_WIDTH_32;
		mRxDmaInfo.ctl |= PDMA_WIDTH_32;
		mDataSize = 2;
		break;

	case BIT_24BIT :
	case BIT_32BIT :
		div = 64;
		mTxDmaInfo.ctl |= PDMA_WIDTH_32;
		mRxDmaInfo.ctl |= PDMA_WIDTH_32;
		mDataSize = 4;
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
		mCurrentDma->setSource(mTxDmaInfo.src);
		break;

	case MODE_MAIN_RX :
		ctl |= SPI_I2SCTL_RXEN_Msk;
		mCurrentDma->setSource(mRxDmaInfo.src);
		break;
	
	case MODE_SUB_TX :
		ctl |= SPI_I2SCTL_TXEN_Msk | SPI_I2SCTL_SLAVE_Msk;
		mCurrentDma->setSource(mTxDmaInfo.src);
		break;

	case MODE_SUB_RX :
		ctl |= SPI_I2SCTL_RXEN_Msk | SPI_I2SCTL_SLAVE_Msk;
		mCurrentDma->setSource(mRxDmaInfo.src);
		break;
	}
	setFieldData(mDev->FIFOCTL, SPI_FIFOCTL_TXTH_Msk, 1, SPI_FIFOCTL_TXTH_Pos);

	setFieldData(mDev->FIFOCTL, SPI_FIFOCTL_RXTH_Msk, 2, SPI_FIFOCTL_RXTH_Pos);
	
	mDev->PDMACTL |= SPI_PDMACTL_TXPDMAEN_Msk | SPI_PDMACTL_RXPDMAEN_Msk;

	mDev->I2SCLK = (mclk << SPI_I2SCLK_MCLKDIV_Pos) | (bclk << SPI_I2SCLK_BCLKDIV_Pos);

	mDev->I2SCTL = ctl;

	mLrclk = clk / div / ((bclk + 1) * 2);

	if(mclk)
		mMclk = clk / (mclk * 2);
	else
		mMclk = clk;

	return error_t::ERROR_NONE;
}

uint32_t I2s::getLrclkFrequency(void)
{
	return mLrclk;
}

uint32_t I2s::getMclkFrequency(void)
{
	return mMclk;
}

error_t I2s::transfer(void *src, uint16_t count)
{
	if(count == 0)
		return error_t::ERROR_NONE;
	
	mDataBuffer = (uint8_t*)src;
	mTransferBufferSize = mLastTransferIndex = count;

	if(mDev->I2SCTL & SPI_I2SCTL_TXEN_Msk)
		return mCurrentDma->transferAsCircularMode(mTxDmaInfo, src, count);
	else
		return mCurrentDma->transferAsCircularMode(mRxDmaInfo, src, count);
}

void* I2s::getCurrentBuffer(void)
{
	return mCurrentDma->getCircularModePreviouslyTransmittedDataBuffer();
}

void I2s::stop(void)
{
	mCurrentDma->stop();
}

uint32_t I2s::getTxCount(void)
{
	if(mReleasedSentCount != mCurrentDma->getCircularModeSentCount())
		return mTransferBufferSize / 2;
	else
		return 0;
}

uint32_t I2s::getRxCount(void)
{
	if(mReleasedSentCount != mCurrentDma->getCircularModeSentCount())
		return mTransferBufferSize / 2;
	else
		return 0;
}

void I2s::releaseBuffer(int32_t count)
{
	mReleasedSentCount++;
}

#endif


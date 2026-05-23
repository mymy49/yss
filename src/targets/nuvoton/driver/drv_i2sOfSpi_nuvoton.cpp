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
#include <targets/nuvoton/NuvotonI2sInSpi.h>
#include <yss/scheduler.h>
#include <yss/reg.h>

NuvotonI2sInSpi::NuvotonI2sInSpi(const Drv::setup_t drvSetup, const setup_t setup) : I2s(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mCurrentDma = nullptr;
	mDataSize = 0;
	mLrclk = 0;
	mMclk = 0;
}

error_t NuvotonI2sInSpi::initialize(const config_t &spec)
{
	int32_t clk, mclk, bclk, div = 1;
	uint32_t ctl, wordWidth;
	
	clk = bclk = getClockFrequency();
	mCurrentDma = system::allocateDma();
	if(mCurrentDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	switch(spec.wordWidth)
	{
	case WORD_WIDTH_8BIT :
		div = 16;
		mDataSize = 1;
		wordWidth = 0;
		break;
	case WORD_WIDTH_16BIT :
		div = 32;
		mTxDmaInfo.ctl |= PDMA_WIDTH_32;
		mRxDmaInfo.ctl |= PDMA_WIDTH_32;
		mDataSize = 2;
		wordWidth = 1;
		break;

	case WORD_WIDTH_24BIT :
		div = 64;
		mTxDmaInfo.ctl |= PDMA_WIDTH_32;
		mRxDmaInfo.ctl |= PDMA_WIDTH_32;
		mDataSize = 4;
		wordWidth = 2;

	case WORD_WIDTH_32BIT :
		div = 64;
		mTxDmaInfo.ctl |= PDMA_WIDTH_32;
		mRxDmaInfo.ctl |= PDMA_WIDTH_32;
		mDataSize = 4;
		wordWidth = 3;
		break;
	}
	
	ctl = (spec.std << SPI_I2SCTL_FORMAT_Pos) | (wordWidth << SPI_I2SCTL_WDWIDTH_Pos) | SPI_I2SCTL_MCLKEN_Msk | SPI_I2SCTL_I2SEN_Msk ;

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

uint32_t NuvotonI2sInSpi::getLrclkFrequency(void)
{
	return mLrclk;
}

uint32_t NuvotonI2sInSpi::getMclkFrequency(void)
{
	return mMclk;
}

error_t NuvotonI2sInSpi::transfer(void *src, uint16_t count)
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

void* NuvotonI2sInSpi::getCurrentBuffer(void)
{
	return mCurrentDma->getCircularModePreviouslyTransmittedDataBuffer();
}

void NuvotonI2sInSpi::stop(void)
{
	mCurrentDma->stop();
}

uint32_t NuvotonI2sInSpi::getTxCount(void)
{
	if(mReleasedSentCount != mCurrentDma->getCircularModeSentCount())
		return mTransferBufferSize / 2;
	else
		return 0;
}

uint32_t NuvotonI2sInSpi::getRxCount(void)
{
	if(mReleasedSentCount != mCurrentDma->getCircularModeSentCount())
		return mTransferBufferSize / 2;
	else
		return 0;
}

void NuvotonI2sInSpi::releaseBuffer(int32_t count)
{
	mReleasedSentCount++;
}

I2s::wordWidth_t NuvotonI2sInSpi::getWordWidth(void)
{
#warning "임시로 작성된 내용임 수정필요"
	return WORD_WIDTH_16BIT;
}

I2s::std_t NuvotonI2sInSpi::getI2sStandard(void)
{
#warning "임시로 작성된 내용임 수정필요"
	return STD_I2S_PHILIPS;
}

#endif


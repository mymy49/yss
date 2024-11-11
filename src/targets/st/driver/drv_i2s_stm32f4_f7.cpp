/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>
#include <yss/debug.h>

#if defined(STM32F4_)

#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/I2s.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

I2s::I2s(const Drv::setup_t drvConfig, const setup_t config) : Drv(drvConfig)
{
	mDev = config.peri;
	mTxDma = &config.txDma;
	mTxDmaInfo = &config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = &config.rxDmaInfo;
	mLastTransferIndex = 0;
	mCurrentDma = mTxDma;
	mDataBuffer = 0;
	mTransferBufferSize = 0;
	mDataSize = 2;
	mFrameErrorIsr = 0;
}

error_t I2s::initializeTransmitterAsMain(const specification_t &spec)
{
	//uint32_t multiple = 384;
	//uint32_t lrck = 128000;
	//uint32_t mclk = 49152000;
	//uint32_t clock = getClockFrequency();

	// I2s::specification_t의 enum 정의가 STM32F 시리즈의 레지스터 기준으로 작성되어 1대1로 사용함
	// 다른 MCU에서는 리맵이 필요함
	uint8_t dataBit = spec.dataBit;
	uint8_t standard = spec.standard;
	uint8_t chlen = spec.chlen;

	setBitData(mDev->I2SCFGR, false, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
	
	mDev->I2SPR = SPI_I2SPR_MCKOE_Msk | 0 << SPI_I2SPR_ODD_Pos | 4 << SPI_I2SPR_I2SDIV_Pos;
	mDev->I2SCFGR = chlen << SPI_I2SCFGR_CHLEN_Pos | dataBit << SPI_I2SCFGR_DATLEN_Pos | 0 << SPI_I2SCFGR_CKPOL_Pos | standard << SPI_I2SCFGR_I2SSTD_Pos | 2 << SPI_I2SCFGR_I2SCFG_Pos | 1 << SPI_I2SCFGR_I2SMOD_Pos;
	mDev->CR2 = SPI_CR2_TXDMAEN_Msk | SPI_CR2_ERRIE_Msk;

	setBitData(mDev->I2SCFGR, true, SPI_I2SCFGR_I2SE_Pos);	// I2S 활성화

	mCurrentDma = mTxDma;

	switch(spec.dataBit)
	{
	case BIT_16BIT :
		mDataSize = 2;
		break;
	default :
		mDataSize = 4;
		break;
	}

	return error_t::NOT_INITIALIZED;
}

error_t I2s::initializeTransmitterAsSub(const specification_t &spec)
{
	//uint32_t multiple = 384;
	//uint32_t lrck = 128000;
	//uint32_t mclk = 49152000;
	//uint32_t clock = getClockFrequency();

	// I2s::specification_t의 enum 정의가 STM32F 시리즈의 레지스터 기준으로 작성되어 1대1로 사용함
	// 다른 MCU에서는 리맵이 필요함
	uint8_t dataBit = spec.dataBit;
	uint8_t standard = spec.standard;
	uint8_t chlen = spec.chlen;

	setBitData(mDev->I2SCFGR, false, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
	
	mDev->I2SPR = 0 << SPI_I2SPR_ODD_Pos | 4 << SPI_I2SPR_I2SDIV_Pos;
	mDev->I2SCFGR = chlen << SPI_I2SCFGR_CHLEN_Pos | dataBit << SPI_I2SCFGR_DATLEN_Pos | 0 << SPI_I2SCFGR_CKPOL_Pos | standard << SPI_I2SCFGR_I2SSTD_Pos | 0 << SPI_I2SCFGR_I2SCFG_Pos | 1 << SPI_I2SCFGR_I2SMOD_Pos;
	mDev->CR2 = SPI_CR2_TXDMAEN_Msk | SPI_CR2_ERRIE_Msk;

	setBitData(mDev->I2SCFGR, true, SPI_I2SCFGR_I2SE_Pos);	// I2S 활성화

	mCurrentDma = mTxDma;

	switch(spec.dataBit)
	{
	case BIT_16BIT :
		mDataSize = 2;
		break;
	default :
		mDataSize = 4;
		break;
	}

	return error_t::NOT_INITIALIZED;
}

error_t I2s::initializeReceiverAsSub(const specification_t &spec)
{
	// I2s::specification_t의 enum 정의가 STM32F 시리즈의 레지스터 기준으로 작성되어 1대1로 사용함
	// 다른 MCU에서는 리맵이 필요함
	uint8_t dataBit = spec.dataBit;
	uint8_t standard = spec.standard;
	uint8_t chlen = spec.chlen;

	setBitData(mDev->I2SCFGR, false, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
	
	mDev->I2SPR = 2;
	mDev->I2SCFGR = chlen << SPI_I2SCFGR_CHLEN_Pos | dataBit << SPI_I2SCFGR_DATLEN_Pos | 0 << SPI_I2SCFGR_CKPOL_Pos | standard << SPI_I2SCFGR_I2SSTD_Pos | 1 << SPI_I2SCFGR_I2SCFG_Pos | 1 << SPI_I2SCFGR_I2SMOD_Pos;
	mDev->CR2 = SPI_CR2_RXDMAEN_Msk | SPI_CR2_ERRIE_Msk;

	setBitData(mDev->I2SCFGR, true, SPI_I2SCFGR_I2SE_Pos);	// I2S 활성화

	mCurrentDma = mRxDma;

	switch(spec.dataBit)
	{
	case BIT_16BIT :
		mDataSize = 2;
		break;
	default :
		mDataSize = 4;
		break;
	}

	return error_t::ERROR_NONE;
}

void I2s::transferAsCircularMode(void *src, uint16_t size)
{
	mLastTransferIndex = size;
	mTransferBufferSize = size;
	mDataBuffer = (uint8_t*)src;
	
	switch(getFieldData(mDev->I2SCFGR, SPI_I2SCFGR_I2SCFG_Msk, SPI_I2SCFGR_I2SCFG_Pos))
	{
	case 0 :
	case 2 :
		mCurrentDma->lock();
		mCurrentDma->transferAsCircularMode(mTxDmaInfo, src, size);
		break;;
	case 1 :
	case 3 :
		mCurrentDma->lock();
		mCurrentDma->transferAsCircularMode(mRxDmaInfo, src, size);
		break;
	}
}

void I2s::setThreadIdOfTransferCircularDataHandler(void)
{
	mTxDma->setThreadIdOfTransferCircularDataHandler();
}

void I2s::stop(void)
{
	mTxDma->stop();
	mTxDma->unlock();
}

void I2s::isr(void)
{
	uint16_t sr = mDev->SR;
	if(sr & SPI_SR_FRE_Msk)
	{
		if(mFrameErrorIsr)
			mFrameErrorIsr();
	}

	if(sr & SPI_SR_OVR_Msk)
	{
		mDev->DR;
		mDev->DR;
	}
}

#endif

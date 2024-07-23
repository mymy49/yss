/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F4) && defined(SAI1)

#include <yss/debug.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/Sai.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

#define MAIN_TRANSMITTER	0
#define MAIN_RECEIVER		1
#define SUB_TRANSMITTER		2
#define SUB_RECEIVER		3

Sai::Sai(const Drv::setup_t drvConfig, const Config config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mBlock = config.block;
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = config.rxDmaInfo;
	mCurrentDma = mTxDma;
	mDataBuffer = 0;
	mTransferBufferSize = 0;
	mDataSize = 2;
}

error Sai::initializeI2sReceiverAsSub(const I2sSpecification &spec)
{
	uint8_t frame = 16 + spec.chlen * 16;
	setBitData(mBlock->CR1, false, SAI_xCR1_SAIEN_Pos); // 장치 비활성화
	
	switch(spec.standard)
	{
	case I2S::STD_PHILIPS :
		mBlock->CR1 =	SAI_xCR1_CKSTR_Msk | 
										SAI_xCR1_DMAEN_Msk |
										((spec.dataBit << SAI_xCR1_DS_Pos) & SAI_xCR1_DS_Msk) | 
										((SUB_RECEIVER << SAI_xCR1_MODE_Pos) & SAI_xCR1_MODE_Msk);
		mBlock->CR2 =	SAI_xCR2_CPL_Msk |
										0 << SAI_xCR2_FTH_Pos;
		mBlock->FRCR =	SAI_xFRCR_FSOFF_Msk | 
										SAI_xFRCR_FSDEF_Msk |
										(((frame - 1) << SAI_xFRCR_FSALL_Pos) & SAI_xFRCR_FSALL_Msk) | 
										(((frame * 2 - 1) << SAI_xFRCR_FRL_Pos) & SAI_xFRCR_FRL_Msk) ;
		mBlock->SLOTR =	(0x3 << SAI_xSLOTR_SLOTEN_Pos) | 
										(1 << SAI_xSLOTR_NBSLOT_Pos);
		break;

	default :
		return error::NOT_INITIALIZED;
	}

	if(spec.dataBit == I2S::DATA_BIT_16BIT)
	{
		mRxDmaInfo.controlRegister1 &= ~(DMA_SxCR_MSIZE_Msk | DMA_SxCR_PSIZE_Msk);
		mRxDmaInfo.controlRegister1 |= (define::dma::size::HALF_WORD << DMA_SxCR_MSIZE_Pos) | (define::dma::size::HALF_WORD << DMA_SxCR_PSIZE_Pos);
	}
	else
	{
		mRxDmaInfo.controlRegister1 &= ~(DMA_SxCR_MSIZE_Msk | DMA_SxCR_PSIZE_Msk);
		mRxDmaInfo.controlRegister1 |= (define::dma::size::WORD << DMA_SxCR_MSIZE_Pos) | (define::dma::size::WORD << DMA_SxCR_PSIZE_Pos);
	}

	setBitData(mBlock->CR1, true, SAI_xCR1_SAIEN_Pos); // 장치 활성화
	mCurrentDma = mRxDma;

	switch(spec.dataBit)
	{
	case DATA_BIT_16BIT :
		mDataSize = 2;
		break;
	default :
		mDataSize = 4;
		break;
	}

	return error::NOT_INITIALIZED;
}

error Sai::initializeI2sTransmitterAsMain(const I2sSpecification &spec)
{
	uint8_t frame = 16 + spec.chlen * 16;
	setBitData(mBlock->CR1, false, SAI_xCR1_SAIEN_Pos); // 장치 비활성화
	
	switch(spec.standard)
	{
	case I2S::STD_PHILIPS :
		mBlock->CR1 =	SAI_xCR1_CKSTR_Msk | 
										SAI_xCR1_DMAEN_Msk |
										((spec.dataBit << SAI_xCR1_DS_Pos) & SAI_xCR1_DS_Msk) | 
										((0 << SAI_xCR1_MCKDIV_Pos) & SAI_xCR1_MCKDIV_Msk) |
										((MAIN_TRANSMITTER << SAI_xCR1_MODE_Pos) & SAI_xCR1_MODE_Msk);
		mBlock->CR2 =	SAI_xCR2_CPL_Msk |
										0 << SAI_xCR2_FTH_Pos;
		mBlock->FRCR =	SAI_xFRCR_FSOFF_Msk | 
										SAI_xFRCR_FSDEF_Msk |
										(((frame - 1) << SAI_xFRCR_FSALL_Pos) & SAI_xFRCR_FSALL_Msk) | 
										(((frame * 2 - 1) << SAI_xFRCR_FRL_Pos) & SAI_xFRCR_FRL_Msk) ;
		mBlock->SLOTR =	(0x3 << SAI_xSLOTR_SLOTEN_Pos) | 
										(1 << SAI_xSLOTR_NBSLOT_Pos);
		break;

	default :
		return error::NOT_INITIALIZED;
	}

	if(spec.dataBit == I2S::DATA_BIT_16BIT)
	{
		mTxDmaInfo.controlRegister1 &= ~(DMA_SxCR_MSIZE_Msk | DMA_SxCR_PSIZE_Msk);
		mTxDmaInfo.controlRegister1 |= (define::dma::size::HALF_WORD << DMA_SxCR_MSIZE_Pos) | (define::dma::size::HALF_WORD << DMA_SxCR_PSIZE_Pos);
	}
	else
	{
		mTxDmaInfo.controlRegister1 &= ~(DMA_SxCR_MSIZE_Msk | DMA_SxCR_PSIZE_Msk);
		mTxDmaInfo.controlRegister1 |= (define::dma::size::WORD << DMA_SxCR_MSIZE_Pos) | (define::dma::size::WORD << DMA_SxCR_PSIZE_Pos);
	}

	setBitData(mBlock->CR1, true, SAI_xCR1_SAIEN_Pos); // 장치 활성화
	mCurrentDma = mTxDma;

	switch(spec.dataBit)
	{
	case DATA_BIT_16BIT :
		mDataSize = 2;
		break;
	default :
		mDataSize = 4;
		break;
	}

	return error::NOT_INITIALIZED;
}

void Sai::transferAsCircularMode(void *src, uint16_t size)
{
	mLastTransferIndex = size;
	mTransferBufferSize = size;
	mDataBuffer = (uint8_t*)src;

	switch(getFieldData(mBlock->CR1, SAI_xCR1_MODE_Msk, SAI_xCR1_MODE_Pos))
	{
	case SUB_RECEIVER :
	case MAIN_RECEIVER :
		mCurrentDma->lock();
		mCurrentDma->transferAsCircularMode(&mRxDmaInfo, src, size);
		break;
	case SUB_TRANSMITTER :
	case MAIN_TRANSMITTER :
		mCurrentDma->lock();
		mCurrentDma->transferAsCircularMode(&mTxDmaInfo, src, size);
		break; 
	}
}

void Sai::setThreadIdOfTransferCircularDataHandler(void)
{
	mTxDma->setThreadIdOfTransferCircularDataHandler();
}

#endif

////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F7)

#include <yss/debug.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/Sai.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/sai_stm32f7.h>
#include <targets/st_gigadevice/dma_stm32_gd32f4_f7.h>

#define MAIN_TRANSMITTER	0
#define MAIN_RECEIVER		1
#define SUB_TRANSMITTER		2
#define SUB_RECEIVER		3

Sai::Sai(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
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
	setBitData(mBlock[SAI_BLOCK_REG::CR1], false, SAI_xCR1_SAIEN_Pos); // 장치 비활성화
	
	switch(spec.standard)
	{
	case I2S::STD_PHILIPS :
		mBlock[SAI_BLOCK_REG::CR1] =	SAI_xCR1_CKSTR_Msk | 
										SAI_xCR1_DMAEN_Msk |
										((spec.dataBit << SAI_xCR1_DS_Pos) & SAI_xCR1_DS_Msk) | 
										((SUB_RECEIVER << SAI_xCR1_MODE_Pos) & SAI_xCR1_MODE_Msk);
		mBlock[SAI_BLOCK_REG::CR2] =	SAI_xCR2_CPL_Msk |
										0 << SAI_xCR2_FTH_Pos;
		mBlock[SAI_BLOCK_REG::FRCR] =	SAI_xFRCR_FSOFF_Msk | 
										SAI_xFRCR_FSDEF_Msk |
										((frame-1 << SAI_xFRCR_FSALL_Pos) & SAI_xFRCR_FSALL_Msk) | 
										((frame*2-1 << SAI_xFRCR_FRL_Pos) & SAI_xFRCR_FRL_Msk) ;
		mBlock[SAI_BLOCK_REG::SLOTR] =	(0x3 << SAI_xSLOTR_SLOTEN_Pos) | 
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

	setBitData(mBlock[SAI_BLOCK_REG::CR1], true, SAI_xCR1_SAIEN_Pos); // 장치 활성화
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
	setBitData(mBlock[SAI_BLOCK_REG::CR1], false, SAI_xCR1_SAIEN_Pos); // 장치 비활성화
	
	switch(spec.standard)
	{
	case I2S::STD_PHILIPS :
		mBlock[SAI_BLOCK_REG::CR1] =	SAI_xCR1_CKSTR_Msk | 
										SAI_xCR1_DMAEN_Msk |
										((spec.dataBit << SAI_xCR1_DS_Pos) & SAI_xCR1_DS_Msk) | 
										((0 << SAI_xCR1_MCKDIV_Pos) & SAI_xCR1_MCKDIV_Msk) |
										((MAIN_TRANSMITTER << SAI_xCR1_MODE_Pos) & SAI_xCR1_MODE_Msk);
		mBlock[SAI_BLOCK_REG::CR2] =	SAI_xCR2_CPL_Msk |
										0 << SAI_xCR2_FTH_Pos;
		mBlock[SAI_BLOCK_REG::FRCR] =	SAI_xFRCR_FSOFF_Msk | 
										SAI_xFRCR_FSDEF_Msk |
										((frame-1 << SAI_xFRCR_FSALL_Pos) & SAI_xFRCR_FSALL_Msk) | 
										((frame*2-1 << SAI_xFRCR_FRL_Pos) & SAI_xFRCR_FRL_Msk) ;
		mBlock[SAI_BLOCK_REG::SLOTR] =	(0x3 << SAI_xSLOTR_SLOTEN_Pos) | 
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

	setBitData(mBlock[SAI_BLOCK_REG::CR1], true, SAI_xCR1_SAIEN_Pos); // 장치 활성화
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

	switch(getFieldData(mBlock[SAI_BLOCK_REG::CR1], SAI_xCR1_MODE_Msk, SAI_xCR1_MODE_Pos))
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

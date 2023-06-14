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
#include <yss/debug.h>

#if defined(GD32F4) || defined(STM32F7)

#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/I2s.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/spi_stm32_gd32f0_f1_f4.h>

I2s::I2s(const Drv::Config drvConfig, const Config config) : Drv(drvConfig)
{
	mPeri = config.peri;
	mTxDma = &config.txDma;
	mTxDmaInfo = &config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = &config.rxDmaInfo;
	mLastTransferIndex = 0;
	mCurrentDma = mTxDma;
	mDataBuffer = 0;
	mTransferBufferSize = 0;
	mDataSize = 2;
}

error I2s::initializeTransmitterAsMain(const Specification &spec)
{
	uint32_t multiple = 384;
	uint32_t lrck = 128000;
	uint32_t mclk = 49152000;
	uint32_t clock = getClockFrequency();

	// I2s::Specification의 enum 정의가 STM32F 시리즈의 레지스터 기준으로 작성되어 1대1로 사용함
	// 다른 MCU에서는 리맵이 필요함
	uint8_t dataBit = spec.dataBit;
	uint8_t standard = spec.standard;
	uint8_t chlen = spec.chlen;

	setBitData(mPeri[SPI_REG::I2SCFGR], false, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
	
	mPeri[SPI_REG::I2SPR] = SPI_I2SPR_MCKOE_Msk | 0 << SPI_I2SPR_ODD_Pos | 1 << SPI_I2SPR_I2SDIV_Pos;
	mPeri[SPI_REG::I2SCFGR] = chlen << SPI_I2SCFGR_CHLEN_Pos | dataBit << SPI_I2SCFGR_DATLEN_Pos | 0 << SPI_I2SCFGR_CKPOL_Pos | standard << SPI_I2SCFGR_I2SSTD_Pos | 2 << SPI_I2SCFGR_I2SCFG_Pos | 1 << SPI_I2SCFGR_I2SMOD_Pos;
	mPeri[SPI_REG::CR2] = SPI_CR2_TXDMAEN_Msk;

	setBitData(mPeri[SPI_REG::I2SCFGR], true, SPI_I2SCFGR_I2SE_Pos);	// I2S 활성화

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

	return error::NOT_INITIALIZED;
}

error I2s::initializeReceiverAsSub(const Specification &spec)
{
	// I2s::Specification의 enum 정의가 STM32F 시리즈의 레지스터 기준으로 작성되어 1대1로 사용함
	// 다른 MCU에서는 리맵이 필요함
	uint8_t dataBit = spec.dataBit;
	uint8_t standard = spec.standard;
	uint8_t chlen = spec.chlen;

	setBitData(mPeri[SPI_REG::I2SCFGR], false, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
	
	mPeri[SPI_REG::I2SPR] = 2;
	mPeri[SPI_REG::I2SCFGR] = chlen << SPI_I2SCFGR_CHLEN_Pos | dataBit << SPI_I2SCFGR_DATLEN_Pos | 0 << SPI_I2SCFGR_CKPOL_Pos | standard << SPI_I2SCFGR_I2SSTD_Pos | 1 << SPI_I2SCFGR_I2SCFG_Pos | 1 << SPI_I2SCFGR_I2SMOD_Pos;
	mPeri[SPI_REG::CR2] = SPI_CR2_RXDMAEN_Msk | SPI_CR2_ERRIE_Msk;

	setBitData(mPeri[SPI_REG::I2SCFGR], true, SPI_I2SCFGR_I2SE_Pos);	// I2S 활성화

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

	return error::ERROR_NONE;
}

void I2s::transferAsCircularMode(void *src, uint16_t size)
{
	mLastTransferIndex = size;
	mTransferBufferSize = size;
	mDataBuffer = (uint8_t*)src;

	if(getFieldData(mPeri[SPI_REG::I2SCFGR], SPI_I2SCFGR_I2SCFG_Msk, SPI_I2SCFGR_I2SCFG_Pos) <= 1) 
	{
		mCurrentDma->lock();
		mCurrentDma->transferAsCircularMode(mRxDmaInfo, src, size);
		return;
	}
	else
	{
		mCurrentDma->lock();
		mCurrentDma->transferAsCircularMode(mTxDmaInfo, src, size);
		return;
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
	uint16_t sr = mPeri[SPI_REG::SR];
	if(sr & SPI_SR_FRE_Msk)
	{
		setBitData(mPeri[SPI_REG::I2SCFGR], false, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
		setBitData(mPeri[SPI_REG::I2SCFGR], true, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
	}

	if(sr & SPI_SR_OVR_Msk)
	{
		mPeri[SPI_REG::DR];
		mPeri[SPI_REG::DR];
	}
}

#endif

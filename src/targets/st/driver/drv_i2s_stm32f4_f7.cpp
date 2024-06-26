////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>
#include <yss/debug.h>

#if defined(STM32F4)

#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/I2s.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

I2s::I2s(const Drv::setup_t drvConfig, const Config config) : Drv(drvConfig)
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

	setBitData(mPeri->I2SCFGR, false, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
	
	mPeri->I2SPR = SPI_I2SPR_MCKOE_Msk | 0 << SPI_I2SPR_ODD_Pos | 4 << SPI_I2SPR_I2SDIV_Pos;
	mPeri->I2SCFGR = chlen << SPI_I2SCFGR_CHLEN_Pos | dataBit << SPI_I2SCFGR_DATLEN_Pos | 0 << SPI_I2SCFGR_CKPOL_Pos | standard << SPI_I2SCFGR_I2SSTD_Pos | 2 << SPI_I2SCFGR_I2SCFG_Pos | 1 << SPI_I2SCFGR_I2SMOD_Pos;
	mPeri->CR2 = SPI_CR2_TXDMAEN_Msk | SPI_CR2_ERRIE_Msk;

	setBitData(mPeri->I2SCFGR, true, SPI_I2SCFGR_I2SE_Pos);	// I2S 활성화

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

	setBitData(mPeri->I2SCFGR, false, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
	
	mPeri->I2SPR = 0 << SPI_I2SPR_ODD_Pos | 4 << SPI_I2SPR_I2SDIV_Pos;
	mPeri->I2SCFGR = chlen << SPI_I2SCFGR_CHLEN_Pos | dataBit << SPI_I2SCFGR_DATLEN_Pos | 0 << SPI_I2SCFGR_CKPOL_Pos | standard << SPI_I2SCFGR_I2SSTD_Pos | 0 << SPI_I2SCFGR_I2SCFG_Pos | 1 << SPI_I2SCFGR_I2SMOD_Pos;
	mPeri->CR2 = SPI_CR2_TXDMAEN_Msk | SPI_CR2_ERRIE_Msk;

	setBitData(mPeri->I2SCFGR, true, SPI_I2SCFGR_I2SE_Pos);	// I2S 활성화

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

	setBitData(mPeri->I2SCFGR, false, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
	
	mPeri->I2SPR = 2;
	mPeri->I2SCFGR = chlen << SPI_I2SCFGR_CHLEN_Pos | dataBit << SPI_I2SCFGR_DATLEN_Pos | 0 << SPI_I2SCFGR_CKPOL_Pos | standard << SPI_I2SCFGR_I2SSTD_Pos | 1 << SPI_I2SCFGR_I2SCFG_Pos | 1 << SPI_I2SCFGR_I2SMOD_Pos;
	mPeri->CR2 = SPI_CR2_RXDMAEN_Msk | SPI_CR2_ERRIE_Msk;

	setBitData(mPeri->I2SCFGR, true, SPI_I2SCFGR_I2SE_Pos);	// I2S 활성화

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
	
	switch(getFieldData(mPeri->I2SCFGR, SPI_I2SCFGR_I2SCFG_Msk, SPI_I2SCFGR_I2SCFG_Pos))
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
	uint16_t sr = mPeri->SR;
	if(sr & SPI_SR_FRE_Msk)
	{
		if(mFrameErrorIsr)
			mFrameErrorIsr();
	}

	if(sr & SPI_SR_OVR_Msk)
	{
		mPeri->DR;
		mPeri->DR;
	}
}

#endif

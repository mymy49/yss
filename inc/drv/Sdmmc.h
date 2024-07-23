/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_SDMMC__H_
#define YSS_DRV_SDMMC__H_

#include "mcu.h"

#if defined(STM32F7)

typedef SDMMC_TypeDef	YSS_SDMMC_Peri;

#elif defined(STM32F4)

typedef SDIO_TypeDef	YSS_SDMMC_Peri;

#else

#define YSS_DRV_SDMMC_UNSUPPORTED

#endif

#ifndef YSS_DRV_SDMMC_UNSUPPORTED

#include "Drv.h"
#include "Dma.h"
#include <sac/SdMemory.h>
#include <yss/error.h>

class Sdmmc : public Drv, public sac::SdMemory
{
public :
	struct Config
	{
		YSS_SDMMC_Peri *peri;
		Dma &txDma;
		Dma::dmaInfo_t txDmaInfo;
		Dma &rxDma;
		Dma::dmaInfo_t rxDmaInfo;
	};

	Sdmmc(const Drv::setup_t &drvConfig, const Config &config);

	error_t initialize(void);

	void lock(void);

	void unlock(void);

private :
	YSS_SDMMC_Peri *mPeri;
	Dma *mTxDma, *mRxDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	bool mAcmdFlag;
	uint8_t mBlockSize;

protected:
	virtual error_t sendCmd(uint8_t cmd, uint32_t arg, uint8_t responseType);

	virtual uint32_t getShortResponse(void);

	virtual void getLongResponse(void *des);

	virtual void setSdioClockBypass(bool en);

	virtual void setSdioClockEn(bool en);

	virtual void setClockFrequency(int32_t  frequency);

	virtual void enablePower(bool en = true);

	virtual void readyRead(void *des, uint16_t length);

	virtual void stopReadyRead(void);

	virtual void readyWrite(void *des, uint16_t length);

	virtual void setDataBlockSize(uint8_t blockSize);

	virtual error_t waitUntilReadComplete(void);

	virtual error_t waitUntilWriteComplete(void);

	virtual bool setBusWidth(uint8_t width);

	virtual void unlockRead(void);

	virtual void unlockWrite(void);
};

#endif

#endif


/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_SDH__H_
#define YSS_NUVOTON_DRV_SDH__H_

#include <drv/Sdmmc.h>
#include <drv/Dma.h>
#include <yss/error.h>

/**
 * @file NuvotonSdh.h
 * @brief SDH (Secure Digital Host) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonSdh
 * @brief Driver class for the Secure Digital Host (SDH) peripheral on Nuvoton MCUs.
 *
 * @details
 * This class inherits from the base Sdmmc class. It provides functions to communicate
 * with SD and MMC cards using the SDH peripheral. It implements low-level command transmission,
 * response reading, and DMA-based block reads and writes.
 */
class NuvotonSdh : public Sdmmc
{
public :
	/**
	 * @brief Initializes the SDH peripheral.
	 * @details Resets the DMA and general host controls, enables card detection interrupt, and sets timing parameters.
	 *
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(void);

	// Internal system configurations. Do not call from user application.
	typedef struct
	{
		SDH_T *dev;
		void (*setSdhClockFrequency)(uint32_t freq);
	}setup_t;

	NuvotonSdh(const Drv::setup_t &drvSetup, const setup_t &setup);

private :
	SDH_T *mDev;
	Dma *mTxDma, *mRxDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	bool mAcmdFlag;
	uint8_t mBlockSize;
	void (*setSdhClockFrequency)(uint32_t freq);

protected:
	virtual error_t sendPowerOn74Clock(void);

	virtual error_t sendCmd(cmd_t cmd, uint32_t arg, response_t responseType);

	virtual uint32_t getShortResponse(void);

	virtual void getLongResponse(void *des);

	virtual void setSdioClockBypass(bool en);

	virtual void setSdioClockEn(bool en);

	virtual void setClockFrequency(int32_t  frequency);

	virtual void enablePower(bool en = true);

	virtual void readyRead(void *des, uint16_t length);

	virtual void stopReadyRead(void);

	virtual void readyWrite(void *des, uint16_t length);

	virtual void setDataBlockSize(uint16_t blockSize);

	virtual error_t waitUntilReadComplete(void);

	virtual error_t waitUntilWriteComplete(void);

	virtual bool setBusWidth(busWidth_t width);
};

#endif



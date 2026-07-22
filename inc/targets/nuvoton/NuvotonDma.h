/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_DMA__H_
#define YSS_DRV_NUVOTON_DMA__H_

#include <drv/Drv.h>
#include <yss/error.h>
#include <yss/scheduler.h>

/**
 * @file NuvotonDma.h
 * @brief DMA (Direct Memory Access) driver class header file for Nuvoton MCUs.
 */

/**
 * @class Dma
 * @brief Base DMA class providing driver functions for DMA/PDMA channels on Nuvoton MCUs.
 *
 * @details
 * This class wraps Nuvoton's Peripheral DMA (PDMA) channels, offering functions for
 * synchronous block transfers, pre-triggered ready setups, circular buffer transfers,
 * and status checking (completion and error flags).
 */
class Dma : public Drv
{
  public:
	/**
	 * @brief Structure containing configuration settings for a DMA transfer.
	 */
	typedef struct
	{
		uint32_t ctl;     ///< Control register value (transfer direction, width, burst size, etc.)
		uint8_t src;      ///< Peripheral request source number for the DMA channel
		void *cpar;       ///< Peripheral address (destination or source register pointer)
	}dmaInfo_t;
	
	/**
	 * @brief Initializes the DMA device.
	 */
	void initialize(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Executes a synchronous DMA transfer.
	 * @details This function initiates the transfer and blocks the calling thread
	 * until the transfer completes or an error occurs.
	 *
	 * @param[in] dmaInfo Reference to the DMA transfer configuration struct.
	 * @param[in] data Pointer to the source or destination data buffer in memory.
	 * @param[in] count Total number of data elements to transfer.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t transfer(dmaInfo_t &dmaInfo, void *data, int32_t  count) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Prepares a DMA channel for a transfer without starting it immediately.
	 * @details Configures the transfer parameters but does not trigger it.
	 * This is typically used when the transfer is triggered by external peripheral hardware.
	 *
	 * @param[in] dmaInfo Reference to the DMA transfer configuration struct.
	 * @param[in,out] data Pointer to the data buffer.
	 * @param[in] count Total number of data elements to transfer.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t ready(dmaInfo_t &dmaInfo, void *data, int32_t  count) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Configures and starts a continuous circular mode transfer.
	 * @details The transfer runs indefinitely in a loop over the provided buffer.
	 * Call stop() to abort the transfer.
	 *
	 * @param[in] dmaInfo Reference to the DMA transfer configuration struct.
	 * @param[in,out] data Pointer to the data buffer.
	 * @param[in] count Total number of data elements to transfer per cycle.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t transferAsCircularMode(const dmaInfo_t &dmaInfo, void *data, uint16_t count) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the remaining number of data elements to transfer.
	 *
	 * @return uint16_t The remaining transfer count.
	 */
	uint16_t getRemainingTransferCount(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the number of completed circular buffer cycles.
	 * @note Only relevant in circular or scatter-gather modes.
	 *
	 * @return uint16_t The completed transfer count.
	 */
	uint16_t getCircularModeSentCount(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the buffer pointer of the last completed transfer chunk in circular mode.
	 * @details Useful to identify which half of the circular buffer is ready to be written to or read.
	 *
	 * @return void* Pointer to the buffer that has just finished transmitting/receiving.
	 */
	void* getCircularModePreviouslyTransmittedDataBuffer(void);
	
	/**
	 * @brief Aborts the active DMA transfer on this channel.
	 */
	void stop(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Manually triggers a transfer that was configured via ready().
	 */
	void trigger(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Checks if the last initiated DMA transfer completed successfully.
	 *
	 * @return bool True if the transfer is complete, false otherwise.
	 */
	bool isComplete(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Checks if an error occurred during the last DMA transfer.
	 *
	 * @return bool True if a transfer error occurred, false otherwise.
	 */
	bool isError(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Sets the peripheral request source number for this DMA channel.
	 *
	 * @param[in] src The hardware peripheral trigger source ID.
	 */
	virtual void setSource(uint8_t src) __attribute__((optimize("-O1"))) = 0;
	

	// Internal system functions. Do not call from user application.
	void remainingTransfer(void);

	void isr(void) __attribute__((optimize("-O1")));

	struct setup_t
	{
		PDMA_T *dma;
		DSCT_T *peri;
	};

	Dma(const Drv::setup_t drvSetup, const setup_t dmaSetup);

  protected :
	PDMA_T *mDma;
	DSCT_T *mChannel;
	DSCT_T mMainChannel, mSubChannel;
	threadId_t mThreadId;
	int32_t mRemainSize, mAddr;
	uint32_t mCircularSentCnt;
	uint8_t mSrcNum, mChNum;
	bool mCompleteFlag, mErrorFlag;
	bool mCircularModeFlag;
	bool mDirFlag;
};

class DmaChannel1 : public Dma
{
public :
	DmaChannel1(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel2 : public Dma
{
public :
	DmaChannel2(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel3 : public Dma
{
public :
	DmaChannel3(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel4 : public Dma
{
public :
	DmaChannel4(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel5 : public Dma
{
public :
	DmaChannel5(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel6 : public Dma
{
public :
	DmaChannel6(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel7 : public Dma
{
public :
	DmaChannel7(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel8 : public Dma
{
 public :
	DmaChannel8(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel9 : public Dma
{
public :
	DmaChannel9(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel10 : public Dma
{
public :
	DmaChannel10(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel11 : public Dma
{
public :
	DmaChannel11(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel12 : public Dma
{
public :
	DmaChannel12(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel13 : public Dma
{
public :
	DmaChannel13(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel14 : public Dma
{
public :
	DmaChannel14(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel15 : public Dma
{
public :
	DmaChannel15(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

class DmaChannel16 : public Dma
{
public :
	DmaChannel16(const Drv::setup_t drvSetup, const Dma::setup_t dmaSetup);
	virtual void setSource(uint8_t src);
};

#endif



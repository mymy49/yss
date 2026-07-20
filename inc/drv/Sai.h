/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_SAI__H_
#define YSS_DRV_SAI__H_

#include "mcu.h"

#if defined(STM32F4) && defined(SAI)

typedef SAI_TypeDef			YSS_SAI_Peri;
typedef SAI_Block_TypeDef	YSS_SAI_Block_Peri;

#else

#define YSS_DRV_SAI_UNSUPPORTED

typedef volatile uint32_t	YSS_SAI_Peri;
typedef volatile uint32_t	YSS_SAI_Block_Peri;

#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>

/**
 * @file Sai.h
 * @brief Serial Audio Interface (SAI) driver class header file.
 *
 * ### Initialization Flow
 * 1. Configure the GPIO pins related to the SAI peripheral (SD, SCK, MCLK, FS) as alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the peripheral using `enableClock()`.
 * 3. Define the configuration struct (specifying master/sub mode, data format, standard) using `I2sSpecification`.
 * 4. Initialize the SAI peripheral as a receiver or transmitter using `initializeI2sReceiverAsSub()` or `initializeI2sTransmitterAsMain()`.
 * 5. Enable the peripheral interrupts using `enableInterrupt()`.
 *
 * ### Initialization Example
 * @code
 * // Configure target pins for SAI function
 * gpioC.setAsAltFunc(1, Gpio::PC1_SAI1_SD);
 * gpioF.setAsAltFunc(8, Gpio::PF8_SAI1_SCK);
 * gpioF.setAsAltFunc(9, Gpio::PF9_SAI1_FS);
 * 
 * sai1.enableClock(); // Supply clock
 * 
 * Sai::I2sSpecification spec = {
 *     Sai::DATA_BIT_16BIT, // dataBit
 *     Sai::CHLEN_32BIT,    // chlen
 *     Sai::STD_PHILIPS     // standard
 * };
 * 
 * // Initialize as I2S Receiver Sub
 * sai1.initializeI2sReceiverAsSub(spec);
 * sai1.enableInterrupt(); // Enable interrupts
 * @endcode
 *
 * ### Continuous Circular DMA Transmission
 * - The driver supports streaming data continuously using circular DMA buffers.
 * - Call `transferAsCircularMode()` to start circular DMA transmissions.
 * - Call `setThreadIdOfTransferCircularDataHandler()` inside the dedicated audio thread to register the calling thread. The driver will automatically trigger/wake up the registered thread when the DMA buffer is half-full or completely filled.
 */

/**
 * @class Sai
 * @brief Driver class for the Serial Audio Interface (SAI) peripheral interface.
 */
class Sai : public Drv
{
public:
	struct Config
	{
		YSS_SAI_Peri *peri;
		YSS_SAI_Block_Peri *block;
		Dma &txDma;
		Dma::dmaInfo_t txDmaInfo;
		Dma &rxDma;
		Dma::dmaInfo_t rxDmaInfo;
	};

	struct I2sSpecification
	{
		uint8_t dataBit;
		uint8_t chlen;
		uint8_t standard;
	};

	enum I2S
	{
		DATA_BIT_16BIT = 4,
		DATA_BIT_24BIT = 6,
		DATA_BIT_32BIT = 7,

		CHLEN_16BIT = 0,
		CHLEN_32BIT = 1,

		STD_PHILIPS = 0,
	};

	Sai(const Drv::setup_t drvConfig, const Config config);

	error_t initializeI2sReceiverAsSub(const I2sSpecification &spec);

	error_t initializeI2sTransmitterAsMain(const I2sSpecification &spec);

	/**
	 * @brief Transmits the configured buffer in circular mode via DMA.
	 * @details When the buffer transfer reaches the end, it automatically rolls back to the beginning of the buffer
	 *          and repeats the transmission. The loop continues until the stop() function is called.
	 *          If setThreadIdOfTransferCircularDataHandler() is called beforehand to register a handler thread,
	 *          the handler thread will be notified/triggered when the buffer is half-full or completely filled/transmitted.
	 * 
	 * @param[in] src Pointer to the circular data buffer to be transmitted.
	 * @param[in] size The size of the circular data buffer in bytes. Maximum size is 0xFFFF.
	 */
	void transferAsCircularMode(void *src, uint16_t size);

	/**
	 * @brief Registers the thread ID of the calling thread as the handler thread for circular mode DMA data.
	 * @details Call this function once from the thread dedicated to processing circular buffer transfers.
	 */
	void setThreadIdOfTransferCircularDataHandler(void);

	uint32_t getTxCount(void);

	uint32_t getRxCount(void);

	void* getCurrrentBuffer(void);

	void releaseBuffer(int32_t count);

	void flush(void);

private :
	YSS_SAI_Peri *mPeri;
	YSS_SAI_Block_Peri *mBlock;
	Dma *mTxDma, *mRxDma, *mCurrentDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	uint8_t *mDataBuffer, mDataSize;
	int32_t mLastTransferIndex, mTransferBufferSize, mLastCheckCount;
};

#endif

// WARNING: This peripheral driver is incomplete and not recommended for production use.
// Current status: Only I2S receiver mode has been implemented and tested for SAI1B.
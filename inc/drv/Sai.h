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
	/**
	 * @struct Config
	 * @brief Hardware configuration structure for the SAI driver instance.
	 *
	 * @details
	 * Specifies the hardware peripheral pointers and DMA channel assignments
	 * for the SAI block. This struct is passed to the constructor and is
	 * used for low-level hardware initialization.
	 */
	struct Config
	{
		YSS_SAI_Peri *peri;            ///< Pointer to the parent SAI peripheral register block (e.g. SAI1).
		YSS_SAI_Block_Peri *block;     ///< Pointer to the specific SAI block register (SAI1 Block A or Block B).
		Dma &txDma;                    ///< Reference to the DMA channel used for audio transmission.
		Dma::dmaInfo_t txDmaInfo;      ///< DMA configuration parameters for the transmit channel.
		Dma &rxDma;                    ///< Reference to the DMA channel used for audio reception.
		Dma::dmaInfo_t rxDmaInfo;      ///< DMA configuration parameters for the receive channel.
	};

	/**
	 * @struct I2sSpecification
	 * @brief I2S audio format specification for SAI initialization.
	 *
	 * @details
	 * Defines the audio data format (bit depth, channel length, and framing
	 * standard) for I2S-compatible operation through the SAI peripheral.
	 * Use the `I2S` enum constants defined in this class to populate these fields.
	 */
	struct I2sSpecification
	{
		uint8_t dataBit;   ///< Audio data bit depth (use I2S::DATA_BIT_16BIT, DATA_BIT_24BIT, or DATA_BIT_32BIT).
		uint8_t chlen;     ///< Channel length in bits per frame slot (use I2S::CHLEN_16BIT or CHLEN_32BIT).
		uint8_t standard;  ///< Audio framing standard (use I2S::STD_PHILIPS for I2S Philips standard).
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

	/**
	 * @brief Gets the accumulated count of audio words transmitted out of the ring buffer.
	 * @details Valid only in transmitter mode.
	 * @return uint32_t Total number of audio words transmitted since the last `transferAsCircularMode()` call.
	 */
	uint32_t getTxCount(void);

	/**
	 * @brief Gets the accumulated count of audio words received into the ring buffer.
	 * @details Valid only in receiver mode.
	 * @return uint32_t Total number of audio words received since the last `transferAsCircularMode()` call.
	 */
	uint32_t getRxCount(void);

	/**
	 * @brief Gets a pointer to the current position of the DMA ring buffer.
	 *
	 * @details
	 * Returns a pointer to the oldest unprocessed audio data in the ring buffer.
	 * After processing, call `releaseBuffer()` with the number of consumed samples
	 * to free those slots for new incoming data.
	 *
	 * @return void* Pointer to the oldest unprocessed audio data in the ring buffer.
	 */
	void* getCurrrentBuffer(void);

	/**
	 * @brief Releases the specified number of audio samples from the ring buffer.
	 *
	 * @details
	 * Advances the ring buffer's consumer (tail) pointer by `count` positions,
	 * freeing those slots for new incoming audio data. Must be called after
	 * processing data returned by `getCurrrentBuffer()`.
	 *
	 * @param[in] count Number of audio samples to release from the buffer.
	 */
	void releaseBuffer(int32_t count);

	/**
	 * @brief Flushes any pending audio data in the SAI and DMA hardware FIFOs.
	 *
	 * @details
	 * Resets the internal DMA and SAI FIFOs to discard any partially
	 * transferred audio data. Typically called before stopping or restarting
	 * circular mode transfers.
	 */
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
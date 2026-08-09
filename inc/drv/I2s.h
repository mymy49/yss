/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_I2S__H_
#define YSS_DRV_I2S__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @file I2s.h
 * @brief Inter-IC Sound (I2S) driver class header file.
 *
 * ### Initialization Flow
 * 1. Configure the GPIO pins related to the I2S peripheral (MCK, CK, SD, WS) as alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the peripheral using `enableClock()`.
 * 3. Define the configuration struct (mode, dataBit, channel length, standard, sampleRate, master clock output enable) using `config_t`.
 * 4. Initialize the I2S peripheral using `initialize()`.
 * 5. Enable the peripheral interrupts using `enableInterrupt()`.
 *
 * ### Initialization Example
 * @code
 * // Configure target pins for I2S function
 * gpioC.setAsAltFunc(7, Gpio::PC7_I2S3_MCK);
 * gpioC.setAsAltFunc(10, Gpio::PC10_I2S3_CK);
 * gpioC.setAsAltFunc(12, Gpio::PC12_I2S3_SD);
 * gpioA.setAsAltFunc(4, Gpio::PA4_I2S3_WS);
 * 
 * i2s3.enableClock(); // Supply clock
 * 
 * // Configure I2S parameters (Master transmitter, 16-bit, Philips standard, 48 kHz sample rate)
 * I2s::config_t i2sConfig = {
 *     I2s::MODE_MAIN_TX,  // mode
 *     I2s::BIT_16BIT,     // dataBit
 *     I2s::CHLEN_16BIT,   // chlen
 *     I2s::STD_PHILIPS,   // std
 *     48000,              // sampleRate
 *     true                // mckoe (Master clock output enable)
 * };
 * 
 * i2s3.initialize(i2sConfig);
 * i2s3.enableInterrupt(); // Enable interrupts
 * @endcode
 *
 * ### Continuous Circular DMA Transmission
 * - The driver supports streaming data continuously using circular DMA buffers.
 * - Call `transferAsCircularMode()` to start continuous circular DMA transmissions.
 * - Call `releaseBuffer()` to advance the write pointer inside the ring buffer once processing is complete.
 */

/**
 * @class I2s
 * @brief Driver class for the I2S (Inter-IC Sound) audio interface.
 * 
 * @details
 * This driver class handles I2S audio interface peripherals.
 * On some MCUs (such as STM32), SPI and I2S peripherals share the same hardware registers, 
 * so peripherals with the same instance number cannot be used simultaneously.
 */
class I2s : public Drv
{
public:
	/**
	 * @brief Enumeration for I2S operating modes.
	 */
	typedef enum
	{
		MODE_NOT_INITIALIZED = 0, ///< Peripheral is not initialized
		MODE_MAIN_TX,             ///< Transmitter Master mode
		MODE_MAIN_RX,             ///< Receiver Master mode
		MODE_SUB_TX,              ///< Transmitter Slave mode
		MODE_SUB_RX               ///< Receiver Slave mode
	}mode_t;

	/**
	 * @brief Enumeration for data word width.
	 */
	typedef enum
	{
		WORD_WIDTH_8BIT = 0,  ///< 8-bit word width
		WORD_WIDTH_16BIT,     ///< 16-bit word width
		WORD_WIDTH_18BIT,     ///< 18-bit word width
		WORD_WIDTH_20BIT,     ///< 20-bit word width
		WORD_WIDTH_24BIT,     ///< 24-bit word width
		WORD_WIDTH_32BIT      ///< 32-bit word width
	}wordWidth_t;
	
	/**
	 * @brief Enumeration for channel length (number of bits per channel frame).
	 */
	typedef enum
	{
		CHLEN_16BIT = 0, ///< 16-bit channel length
		CHLEN_32BIT,     ///< 32-bit channel length
	}chlen_t;

	/**
	 * @brief Enumeration for standard audio protocols.
	 */
	typedef enum
	{
		STD_I2S_PHILIPS = 0,  ///< I2S Philips standard
		STD_MSB_JUSTIFIED,    ///< MSB Justified standard
		STD_LSB_JUSTIFIED,    ///< LSB Justified standard
		STD_PCM,              ///< PCM standard
		STD_PCM_MODE_A,       ///< PCM Mode A
		STD_PCM_MODE_B,       ///< PCM Mode B
		STD_DSP               ///< DSP standard
	}std_t;

	/**
	 * @struct config_t
	 * @brief Configuration parameters for I2S peripheral initialization.
	 */
	typedef struct
	{
		mode_t mode;             ///< I2S operating mode.
		wordWidth_t wordWidth;   ///< Data word width.
		std_t std;               ///< Audio protocol standard.
		int32_t sampleRate;      ///< Target sample rate in Hz.
	}config_t;
	
	/**
	 * @brief Initializes the I2S peripheral.
	 * @details The target sample rate clock is calculated dynamically but absolute accuracy is not guaranteed.
	 *          After initialization, call getLrclkFrequency() or getMclkFrequency() to check the actual frequencies.
	 * 
	 * @param[in] config Reference to I2S configuration parameters.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t initialize(const config_t &config) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Gets the actual LRCLK frequency of the I2S interface.
	 * 
	 * @return uint32_t Frequency in Hz.
	 */
	virtual uint32_t getLrclkFrequency(void) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Gets the actual MCLK frequency of the I2S interface.
	 * 
	 * @return uint32_t Frequency in Hz.
	 */
	virtual uint32_t getMclkFrequency(void) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Starts transmitting/receiving a data buffer using DMA as a circular ring buffer.
	 * @details Once transmission reaches the end of the buffer, it wraps around to the beginning.
	 *          This process continues until stop() is called. The user should check getTxCount() or getRxCount()
	 *          to determine how many words have been processed, and refill or process the buffer.
	 * 
	 * @param[in] src Pointer to the data buffer.
	 * @param[in] count The buffer depth in terms of audio data frames (maximum 65535).
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t transfer(void *src, uint16_t count) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Stops DMA-based data transfer.
	 */
	virtual void stop(void) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Gets the accumulated count of words sent out of the ring buffer.
	 * @details Valid only when the mode is MODE_MAIN_TX or MODE_SUB_TX.
	 * 
	 * @return uint32_t Word count sent.
	 */
	virtual uint32_t getTxCount(void) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Gets the accumulated count of words received into the ring buffer.
	 * @details Valid only when the mode is MODE_MAIN_RX or MODE_SUB_RX.
	 * 
	 * @return uint32_t Word count received.
	 */
	virtual uint32_t getRxCount(void) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Gets the pointer to the next section of the ring buffer to write/read.
	 * 
	 * @return void* Pointer to the current active buffer index.
	 */
	virtual void* getCurrentBuffer(void) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Advances the ring buffer's current write/read pointer.
	 * 
	 * @param[in] count Number of frames/words written or read by the application.
	 */
	virtual void releaseBuffer(int32_t count) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Gets the size of one complete audio channel frame in bytes.
	 *
	 * @details
	 * Returns the byte size of a single audio sample frame based on the
	 * configured channel length (`chlen_t`). For example, a stereo 16-bit
	 * frame (CHLEN_32BIT) returns 4 bytes (2 channels × 2 bytes each).
	 * This value is useful for calculating DMA transfer sizes.
	 *
	 * @return uint32_t Size of one audio channel frame in bytes.
	 */
	uint32_t getChannelFrameSize(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the configured data word width of the I2S interface.
	 *
	 * @details
	 * Returns the data word width that was set during `initialize()`.
	 * This is useful for downstream audio processing code that needs
	 * to know the bit depth of the audio samples.
	 *
	 * @return wordWidth_t The configured word width enumeration value.
	 */
	virtual wordWidth_t getWordWidth(void) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Gets the configured I2S audio protocol standard.
	 *
	 * @details
	 * Returns the audio framing standard (e.g. Philips I2S, MSB-justified,
	 * PCM) that was configured during `initialize()`. This is useful for
	 * connected audio codec driver code that needs to verify the protocol
	 * configuration matches its own setup.
	 *
	 * @return std_t The configured I2S standard enumeration value.
	 */
	virtual std_t getI2sStandard(void) __attribute__((optimize("-O1"))) = 0;
	
	// The following are internal functions and do not need to be called by the user application.
	I2s(const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

protected :
	mode_t mMode;                              ///< Current I2S operating mode (master/slave, TX/RX).
	Dma *mCurrentDma;                          ///< Pointer to the DMA channel currently used for circular transfer.
	int32_t mLastTransferIndex;                ///< DMA transfer index at the time of the last `getTxCount()`/`getRxCount()` call.
	int32_t mTransferBufferSize;               ///< Total size of the circular transfer buffer in audio frames.
	int32_t mLastCheckCount;                   ///< Snapshot count used to compute delta frames processed since last check.
	uint8_t *mDataBuffer;                      ///< Pointer to the circular data buffer used for DMA transfer.
	uint8_t mDataSize;                         ///< Byte size of a single audio sample word (derived from word width).
};

/*
	// The following is an example configuration for the STM32F407 MCU.

	gpioC.setAsAltFunc(7, Gpio::PC7_I2S3_MCK);
	gpioC.setAsAltFunc(10, Gpio::PC10_I2S3_CK);
	gpioC.setAsAltFunc(12, Gpio::PC12_I2S3_SD);
	gpioA.setAsAltFunc(4, Gpio::PA4_I2S3_WS);

	I2s::config_t i2s3Config = 
	{
		I2s::MODE_MAIN_TX,	//mode_t mode;
		I2s::BIT_16BIT,		//dataBit_t dataBit;
		I2s::CHLEN_16BIT,	//chlen_t chlen;
		I2s::STD_PHILIPS,	//std_t std;
		48000,				//int32_t sampleRate;
		true				//bool mckoe;
	};

	i2s3.enableClock();
	i2s3.initialize(i2s3Config);
	i2s3.enableInterrupt();
*/

#endif


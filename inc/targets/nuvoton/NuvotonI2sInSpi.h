/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_I2S__H_
#define YSS_NUVOTON_DRV_I2S__H_

#include <drv/peripheral.h>
#include <drv/I2s.h>
#include <drv/Dma.h>

/**
 * @file NuvotonI2sInSpi.h
 * @brief I2S (Inter-IC Sound) driver class header file using SPI hardware on Nuvoton MCUs.
 */

/**
 * @class NuvotonI2sInSpi
 * @brief Driver class for running I2S protocols over SPI hardware blocks on Nuvoton MCUs.
 *
 * @details
 * This class inherits from the base I2s class. It configures the SPI peripheral to operate
 * in I2S master or slave mode (Tx or Rx) and handles data transfers via DMA circular buffers.
 */
class NuvotonI2sInSpi : public I2s
{
public :
	/**
	 * @brief Initializes the I2S peripheral over the SPI block.
	 * @details Allocates a DMA channel and configures word width, I2S standard, clock frequency,
	 * master/slave mode, and interrupts.
	 *
	 * @param[in] config Configuration settings specifying sample rate, word width, mode, standard, etc.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(const config_t &config) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the actual calculated LRCLK (sample rate) clock frequency.
	 *
	 * @return uint32_t LRCLK frequency in Hz.
	 */
	virtual uint32_t getLrclkFrequency(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the actual calculated master clock (MCLK) frequency.
	 *
	 * @return uint32_t MCLK frequency in Hz.
	 */
	virtual uint32_t getMclkFrequency(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Starts an asynchronous data transfer using circular DMA.
	 *
	 * @param[in] src Pointer to the data transmit/receive buffer.
	 * @param[in] count Total number of data elements in the buffer.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t transfer(void *src, uint16_t count) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Stops the active I2S circular DMA transfer.
	 */
	virtual void stop(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the number of transmitted data blocks that are ready for processing.
	 *
	 * @return uint32_t Count of sent blocks.
	 */
	virtual uint32_t getTxCount(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the number of received data blocks that are ready to be read.
	 *
	 * @return uint32_t Count of received blocks.
	 */
	virtual uint32_t getRxCount(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets a pointer to the buffer block that has just finished transferring.
	 *
	 * @return void* Pointer to the previously transmitted/received data block.
	 */
	virtual void* getCurrentBuffer(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Releases a specified number of data elements from the buffer after processing.
	 *
	 * @param[in] count Number of elements to release.
	 */
	virtual void releaseBuffer(int32_t count) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the configured word bit width.
	 *
	 * @return wordWidth_t The bit width of each word.
	 */
	virtual wordWidth_t getWordWidth(void)  __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the configured I2S standard protocol.
	 *
	 * @return std_t The standard protocol configuration.
	 */
	virtual std_t getI2sStandard(void)  __attribute__((optimize("-O1")));
	
	// Internal system configurations. Do not call from user application.
	typedef struct
	{
		SPI_T *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
	}setup_t;

	NuvotonI2sInSpi(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private :
	SPI_T *mDev;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	uint32_t mReleasedSentCount;

	uint32_t mLrclk, mMclk;
};

#endif



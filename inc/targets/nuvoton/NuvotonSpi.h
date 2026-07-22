/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_SPI__H_
#define YSS_DRV_NUVOTON_SPI__H_

#include <drv/peripheral.h>
#include <stdint.h>

#include <drv/Spi.h>
#include <drv/Dma.h>
#include <yss/scheduler.h>

/**
 * @file NuvotonSpi.h
 * @brief SPI (Serial Peripheral Interface) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonSpi
 * @brief Driver class for the SPI peripheral on Nuvoton MCUs.
 *
 * @details
 * This class inherits from the base Spi class and provides functions to initialize SPI,
 * set physical bus configurations (baudrate, clock mode, data width), enable/disable the module,
 * and transfer data using either synchronous polling or DMA engines.
 */
class NuvotonSpi : public Spi
{
  public:
	/**
	 * @brief Initializes the SPI hardware peripheral.
	 *
	 * @param[in] config Configuration settings for the SPI peripheral (e.g. Master/Slave).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(config_t config) __attribute__((optimize("-O1")));

	/**
	 * @brief Sets the physical SPI communication specifications.
	 * @details Configures data bit depth, maximum frequency, and clock mode (CPOL/CPHA).
	 *
	 * @param[in] spec Pointer to target device specification settings.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t setSpecification(const specification_t &spec) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Enables or disables the SPI peripheral.
	 *
	 * @param[in] en If set to true, enables SPI; otherwise disables it.
	 */
	virtual void enable(bool en) __attribute__((optimize("-O1")));

	/**
	 * @brief Sends a single word of data synchronously.
	 *
	 * @param[in] data Data word to send.
	 */
	virtual void send(uint32_t data) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Sends a data block asynchronously/synchronously using DMA.
	 *
	 * @param[in] src Pointer to the data transmit buffer.
	 * @param[in] size Size of the data block to send.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t send(void *src, int32_t  size) __attribute__((optimize("-O1")));

	/**
	 * @brief Exchanges a single word of data synchronously (Full-Duplex).
	 *
	 * @param[in] data Data word to send.
	 * @return uint32_t Received data word.
	 */
	virtual uint32_t exchange(uint32_t data) __attribute__((optimize("-O1")));

	/**
	 * @brief Exchanges a data block using DMA (Full-Duplex).
	 *
	 * @param[in,out] des Pointer to the data buffer (serves as source and destination).
	 * @param[in] size Size of the data block in bytes.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t exchange(void *des, int32_t size) __attribute__((optimize("-O1")));

	// Internal system configurations. Do not call from user application.
	struct setup_t
	{
		SPI_T *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
	};

	NuvotonSpi(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private:
	SPI_T *mDev;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	Dma *mTxDma, *mRxDma;
};

#endif



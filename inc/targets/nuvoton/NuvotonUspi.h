/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_USCI__H_
#define YSS_DRV_NUVOTON_USCI__H_

#include <drv/peripheral.h>
#include <stdint.h>

#include <drv/Spi.h>
#include <drv/Dma.h>
#include <yss/scheduler.h>

#if defined(USPI0)

/**
 * @file NuvotonUspi.h
 * @brief USPI (USCI-SPI) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonUspi
 * @brief Driver class for the USCI SPI (USPI) peripheral on Nuvoton MCUs.
 *
 * @details
 * This class inherits from the base Spi class and configures Nuvoton's Universal Serial Control
 * Interface (USCI) to operate as a serial peripheral interface (SPI). It provides setup,
 * transmission, and full-duplex exchange capabilities using DMA channels.
 */
class NuvotonUspi : public Spi
{
  public:
	/**
	 * @brief Initializes the USCI SPI peripheral.
	 * @details Allocates DMA channels, sets the operational mode (main/master mode), and enables PDMA request gates.
	 *
	 * @param[in] config Configuration settings for the USCI SPI peripheral.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(config_t config) __attribute__((optimize("-O1")));

	/**
	 * @brief Configures target device communication specifications.
	 * @details Automatically sets up data bit length (4 ~ 16 bits), clock frequency divider, and clock mode (CPOL/CPHA).
	 *
	 * @param[in] spec Pointer to target device specification settings.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t setSpecification(const specification_t &spec) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Enables or disables the USCI SPI protocol logic.
	 *
	 * @param[in] en If set to true, enables protocol; otherwise disables it.
	 */
	virtual void enable(bool en) __attribute__((optimize("-O1")));

	/**
	 * @brief Transmits a single word of data synchronously.
	 *
	 * @param[in] data Data word to send.
	 */
	virtual void send(uint32_t data) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Sends a data block using DMA.
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
		USPI_T *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
	};

	NuvotonUspi(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private:
	USPI_T *mDev;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	Dma *mTxDma, *mRxDma;
};

#endif

#endif



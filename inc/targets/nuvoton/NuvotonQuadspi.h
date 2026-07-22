/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NVUTON_QUADSPI__H_
#define YSS_DRV_NVUTON_QUADSPI__H_

#include <drv/Quadspi.h>
#include <drv/Dma.h>

/**
 * @file NuvotonQuadspi.h
 * @brief Quad SPI (QSPI) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonQuadspi
 * @brief Driver class for the Quad SPI (QSPI) peripheral on Nuvoton MCUs.
 *
 * @details
 * This class inherits from the base Quadspi class and provides interface functions to configure
 * and use the Quad SPI hardware in Master mode. It supports single-word/block transmissions,
 * full-duplex exchanges, and half-duplex receptions using DMA channels.
 */
class NuvotonQuadspi : public Quadspi
{
public :
	/**
	 * @brief Initializes the QSPI master device.
	 * @details Allocates a DMA channel and resets the internal FIFO and PDMA control registers.
	 *
	 * @param[in] config Configuration settings for the QSPI device.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(config_t config);

	/**
	 * @brief Configures target device timing specifications.
	 * @details Automatically calculates the clock divisor based on maximum frequency and sets clock mode (CPOL/CPHA).
	 *
	 * @param[in] spec Device specification parameters.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t setSpecification(const specification_t &spec);

	/**
	 * @brief Transmits a single word of data (up to 32 bits).
	 *
	 * @param[in] dataform Format configuration for the data transaction (data width, bit width, bit order, etc.).
	 * @param[in] data The data word to transmit.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t transmit(dataform_t dataform, uint32_t data);

	/**
	 * @brief Transmits and receives a single word of data simultaneously.
	 *
	 * @param[in] dataform Format configuration for the data transaction.
	 * @param[in,out] data Reference to the data word. Holds transmit data on call, and receives response data.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t exchange(dataform_t dataform, uint32_t &data);

	/**
	 * @brief Receives a single word of data.
	 *
	 * @param[in] dataform Format configuration for the data transaction.
	 * @param[out] data Reference to the variable where the received data will be stored.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t receive(dataform_t dataform, uint32_t &data);

	/**
	 * @brief Transmits a block of data bytes.
	 *
	 * @param[in] dataform Format configuration for the data transaction.
	 * @param[in] data Pointer to the transmit data buffer.
	 * @param[in] size Size of the data buffer in bytes.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t transmit(dataform_t dataform, void *data, uint32_t size);

	/**
	 * @brief Exchanges a block of data bytes.
	 *
	 * @param[in] dataform Format configuration for the data transaction.
	 * @param[in,out] data Pointer to the data buffer. Acts as transmit source and receives destination.
	 * @param[in] size Size of the data buffer in bytes.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t exchange(dataform_t dataform, void *data, uint32_t size);

	// Internal system interrupt routine. Do not call from user application.
	void isr(void);

	// Internal system configurations. Do not call from user application.
	struct setup_t
	{
		QSPI_T *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
	};

	NuvotonQuadspi(const Drv::setup_t drvSetup, const setup_t setup);

private :
	QSPI_T *mDev;
	Dma *mDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	uint32_t mClockMode;
};

#endif



/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_CRC__H_
#define YSS_NUVOTON_DRV_CRC__H_

#include <drv/Crc.h>

/**
 * @file NuvotonCrc.h
 * @brief CRC (Cyclic Redundancy Check) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonCrc
 * @brief Driver class for the CRC peripheral on Nuvoton MCUs.
 *
 * @details
 * This class provides interface functions to configure and use the hardware CRC generator.
 * It supports initializing, configuring input/checksum bit order, resetting CRC checksum,
 * and calculating the checksum for 8-bit, 16-bit, and 32-bit data block sizes.
 */
class NuvotonCrc : public Crc
{
public :
	NuvotonCrc(const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	/**
	 * @brief Initializes the CRC device with the given configuration.
	 * @details Enables the CRC peripheral.
	 *
	 * @param[in] config Configuration settings for the CRC device.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t initialize(config_t config) __attribute__((optimize("-O1")));

	/**
	 * @brief Configures the CRC device settings.
	 * @details Sets CRC mode, data length, input bit order, checksum bit order, and seed.
	 *
	 * @param[in] config Configuration settings for the CRC device.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t configure(config_t config) __attribute__((optimize("-O1")));

	/**
	 * @brief Calculates the CRC checksum for a data block.
	 *
	 * @param[in] src Pointer to the input data block.
	 * @param[in] size Size of the data block in bytes.
	 * @return uint32_t The calculated CRC checksum.
	 */
	virtual uint32_t calculate(void *src, uint32_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Resets the CRC checksum calculation to its initial seed state.
	 */
	virtual void resetChecksum(void) __attribute__((optimize("-O1")));

private :
	CRC_T *mDev;
	datalen_t mDataLen;
};

#endif



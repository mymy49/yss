/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CRC__H_
#define YSS_DRV_CRC__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @file Crc.h
 * @brief CRC (Cyclic Redundancy Check) peripheral driver class header file.
 */

/**
 * @class Crc
 * @brief Driver class for the CRC (Cyclic Redundancy Check) peripheral.
 * 
 * @details
 * This driver class provides support for hardware-accelerated CRC checksum calculations.
 * It allows configuring various CRC modes (CCITT, CRC-8, CRC-16, CRC-32) and data widths.
 */
class Crc : public Drv
{
public :
	/**
	 * @brief Enumeration for CRC calculation modes/polynomials.
	 */
	typedef enum
	{
		CRC_MODE_CCITT, ///< CCITT mode (polynomial 0x1021)
		CRC_MODE_CRC8,  ///< 8-bit CRC mode
		CRC_MODE_CRC16, ///< 16-bit CRC mode
		CRC_MODE_CRC32  ///< 32-bit CRC mode (Standard ethernet polynomial 0x04C11DB7)
	}mode_t;

	/**
	 * @brief Enumeration for input data bit length per write transaction.
	 */
	typedef enum
	{
		CRC_DAT_LEN_8BIT = 0, ///< 8-bit data write width
		CRC_DAT_LEN_16BIT,    ///< 16-bit data write width
		CRC_DAT_LEN_32BIT     ///< 32-bit data write width
	}datalen_t;

	/**
	 * @struct config_t
	 * @brief Configuration structure for the CRC device.
	 */
	typedef struct
	{
		mode_t mode;                    ///< The CRC calculation mode/polynomial type.
		datalen_t datalen;              ///< The data width of the write operations to the CRC core.
		uint32_t seed;                  ///< The initial seed value used when resetting the checksum.
		bool writeBitOrderReverse;      ///< True to reverse the bit order of incoming data written to the core.
		bool checksumBitOrderReverse;   ///< True to reverse the bit order of the calculated checksum result.
	}config_t;

	/**
	 * @brief Configures the operation mode of the CRC device.
	 * 
	 * @param[in] config The configuration settings for the CRC device.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t configure(config_t config) = 0;

	/**
	 * @brief Calculates the CRC checksum for a block of data.
	 * 
	 * @param[in] src Pointer to the data payload buffer.
	 * @param[in] size The size of the data payload in bytes.
	 * @return uint32_t The calculated CRC checksum.
	 */
	virtual uint32_t calculate(void *src, uint32_t size) = 0;

	/**
	 * @brief Resets the CRC checksum value to its initial seed.
	 */
	virtual void resetChecksum(void) = 0;

	/**
	 * @brief Constructor for the Crc class.
	 * 
	 * @param[in] drvSetup The base driver setup configuration.
	 */
	Crc(const Drv::setup_t drvSetup);

protected :
};

#endif


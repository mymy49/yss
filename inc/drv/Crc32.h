/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CRC32__H_
#define YSS_DRV_CRC32__H_

#include "peripheral.h"

#if defined(GD32F1) || defined(STM32F4) || defined(STM32F7) || defined(STM32F1)
typedef CRC_TypeDef		YSS_CRC32_Dev;
#else
typedef void YSS_CRC32_Dev;
#define YSS_DRV_CRC32_UNSUPPORTED
#endif

#include "Drv.h"

/**
 * @file Crc32.h
 * @brief CRC-32 peripheral driver class header file.
 * 
 * ### Initialization Flow
 * 1. Supply clock to the CRC-32 peripheral using the `enableClock()` function.
 * 2. Once the clock is enabled, the peripheral is immediately ready for use.
 * 
 * ### Usage
 * 1. Call `resetCrc32Value()` to reset the internal CRC calculation value.
 * 2. Choose `calculateInLittleEndian()` or `calculateInBigEndian()` based on the endianness of the data stream, 
 *    and call the function with the source data and its size.
 * 3. Call `getCrc32Value()` to retrieve the final calculated CRC-32 value.
 */

/**
 * @class Crc32
 * @brief Driver class for the CRC-32 hardware calculator peripheral.
 * 
 * @details
 * This driver class provides interface functions to perform hardware-accelerated 32-bit CRC (CRC-32) calculations.
 * It supports processing data in both Little-Endian and Big-Endian formats.
 */
class Crc32 : public Drv
{
public:
	/**
	 * @brief Resets the current CRC-32 accumulated calculation value to its initial state.
	 */
	void resetCrc32Value(void);
	
	/**
	 * @brief Calculates the CRC-32 of the data stream in 32-bit Little-Endian format.
	 * 
	 * @param[in] src Pointer to the data payload buffer to calculate CRC-32 for.
	 * @param[in] size The size of the data payload in bytes.
	 */
	void calculateInLittleEndian(void *src, uint32_t size);

	/**
	 * @brief Calculates the CRC-32 of the data stream in 32-bit Big-Endian format.
	 * 
	 * @param[in] src Pointer to the data payload buffer to calculate CRC-32 for.
	 * @param[in] size The size of the data payload in bytes.
	 */
	void calculateInBigEndian(void *src, uint32_t size);
	
	/**
	 * @brief Gets the current accumulated CRC-32 calculation value.
	 * 
	 * @return uint32_t The accumulated CRC-32 result.
	 */
	uint32_t getCrc32Value(void);
	
	/**
	 * @brief Constructor for the Crc32 class.
	 * 
	 * @param[in] peri Pointer to the hardware CRC peripheral instance.
	 * @param[in] drvSetup The base driver setup configuration.
	 */
	Crc32(YSS_CRC32_Dev *peri, const Drv::setup_t drvSetup);

private:
	YSS_CRC32_Dev *mPeri; ///< Pointer to the hardware CRC peripheral instance.
};

#endif
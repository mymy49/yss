/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_FLASH_NUVOTON__H_
#define YSS_CLASS_FLASH_NUVOTON__H_

#include <yss/error.h>
#include <drv/mcu.h>

/**
 * @file NuvotonFlash.h
 * @brief Flash Memory Controller driver class header file for Nuvoton MCUs.
 */

/**
 * @class Flash
 * @brief Driver class for the Flash Memory Controller (FMC) on Nuvoton MCUs.
 *
 * @details
 * This class provides interface functions to perform ISP (In-System Programming) operations,
 * including page erasing, word programming, reading from flash memory, and retrieving the
 * unique device identifier (UID).
 */
class Flash
{
public :
	/**
	 * @brief Erases a single page of flash memory.
	 *
	 * @param[in] page The page index to erase.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t erasePage(uint16_t page) __attribute__((optimize("-O1")));

	/**
	 * @brief Calculates the start address of a specified flash page.
	 *
	 * @param[in] page The page index.
	 * @return uint32_t The absolute hardware memory address of the page.
	 */
	uint32_t getPageAddress(uint16_t page) __attribute__((optimize("-O1")));

	/**
	 * @brief Programs a block of flash memory at a specific destination address.
	 *
	 * @param[in] des Pointer to the destination flash memory address (must be 32-bit aligned).
	 * @param[in] src Pointer to the source data buffer.
	 * @param[in] count Number of 32-bit words to program.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t program(void *des, uint32_t *src, uint32_t count) __attribute__((optimize("-O1")));

	/**
	 * @brief Programs a block of flash memory starting at the beginning of a specified page.
	 *
	 * @param[in] page The destination page index.
	 * @param[in] src Pointer to the source data buffer.
	 * @param[in] count Number of 32-bit words to program.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t program(uint16_t page, uint32_t *src, uint32_t count) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Reads data from flash memory in 32-bit (4-byte) word units.
	 *
	 * @param[in] page The page index to read from.
	 * @param[in] sector The offset inside the page (in units of 32-bit words, i.e., 4-byte increments).
	 * @param[in] count Number of 32-bit words to read.
	 * @param[out] dataReg Pointer to the destination buffer to store the read data.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t read4Xbytes(uint16_t page, uint16_t sector, uint16_t count, uint32_t *dataReg) __attribute__((optimize("-O1")));

	/**
	 * @brief Reads the unique identifier (UID) of the MCU.
	 *
	 * @param[out] des Pointer to the buffer where the UID word will be stored.
	 * @param[in] index The word index of the UID (0 to 2).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t readUniqueId(uint32_t *des, uint8_t index);
	
private :
	error_t executeCommand(uint8_t cmd) __attribute__((optimize("-O1")));

	error_t enable(bool en) __attribute__((optimize("-O1")));

	error_t program32bit(uint32_t addr, uint32_t data) __attribute__((optimize("-O1")));

	error_t read32bit(uint32_t addr, uint32_t* data) __attribute__((optimize("-O1")));
};

#endif



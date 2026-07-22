/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Memory.h
 * @brief Hardware Abstraction Layer (HAL) interface for non-volatile / byte-addressable memory devices.
 */

#ifndef YSS_SAC_SERIAL_MEMORY__H_
#define YSS_SAC_SERIAL_MEMORY__H_

#include <stdint.h>
#include <yss/error.h>

/**
 * @class Memory
 * @brief Abstract base class for memory devices (e.g., EEPROM, FRAM, SPI/I2C Flash).
 *
 * This class provides standard high-level write and read methods for various primitive data types.
 * Bounds checking is performed automatically in `write()` and `read()` against `getSize()` before delegating
 * to the low-level pure virtual methods `writeBytes()` and `readBytes()`.
 */
class Memory
{
public:
	/**
	 * @brief Writes an 8-bit unsigned integer to the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[in] src Data value to write.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t write(uint32_t addr, uint8_t src);

	/**
	 * @brief Writes an 8-bit signed integer to the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[in] src Data value to write.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t write(uint32_t addr, int8_t src);

	/**
	 * @brief Writes a 16-bit unsigned integer to the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[in] src Data value to write.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t write(uint32_t addr, uint16_t src);

	/**
	 * @brief Writes a 16-bit signed integer to the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[in] src Data value to write.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t write(uint32_t addr, int16_t src);

	/**
	 * @brief Writes a 32-bit unsigned integer to the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[in] src Data value to write.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t write(uint32_t addr, uint32_t src);

	/**
	 * @brief Writes a 32-bit signed integer to the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[in] src Data value to write.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t write(uint32_t addr, int32_t src);

	/**
	 * @brief Writes a 32-bit single-precision floating-point number to the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[in] src Data value to write.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t write(uint32_t addr, float src);

	/**
	 * @brief Writes a 64-bit double-precision floating-point number to the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[in] src Data value to write.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t write(uint32_t addr, double src);

	/**
	 * @brief Writes a 64-bit unsigned integer to the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[in] src Data value to write.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t write(uint32_t addr, uint64_t src);

	/**
	 * @brief Writes a 64-bit signed integer to the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[in] src Data value to write.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t write(uint32_t addr, int64_t src);

	/**
	 * @brief Reads an 8-bit unsigned integer from the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[out] des Reference to variable storing the read value.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t read(uint32_t addr, uint8_t &des);

	/**
	 * @brief Reads an 8-bit signed integer from the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[out] des Reference to variable storing the read value.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t read(uint32_t addr, int8_t &des);

	/**
	 * @brief Reads a 16-bit unsigned integer from the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[out] des Reference to variable storing the read value.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t read(uint32_t addr, uint16_t &des);

	/**
	 * @brief Reads a 16-bit signed integer from the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[out] des Reference to variable storing the read value.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t read(uint32_t addr, int16_t &des);

	/**
	 * @brief Reads a 32-bit unsigned integer from the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[out] des Reference to variable storing the read value.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t read(uint32_t addr, uint32_t &des);

	/**
	 * @brief Reads a 32-bit signed integer from the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[out] des Reference to variable storing the read value.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t read(uint32_t addr, int32_t &des);

	/**
	 * @brief Reads a 32-bit single-precision floating-point number from the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[out] des Reference to variable storing the read value.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t read(uint32_t addr, float &des);

	/**
	 * @brief Reads a 64-bit double-precision floating-point number from the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[out] des Reference to variable storing the read value.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t read(uint32_t addr, double &des);

	/**
	 * @brief Reads a 64-bit unsigned integer from the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[out] des Reference to variable storing the read value.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t read(uint32_t addr, uint64_t &des);

	/**
	 * @brief Reads a 64-bit signed integer from the specified memory address.
	 * @param[in] addr Target byte address.
	 * @param[out] des Reference to variable storing the read value.
	 * @return error_t::ERROR_NONE on success, or error_t::OUT_OF_RANGE if out of bounds.
	 */
	error_t read(uint32_t addr, int64_t &des);

	/**
	 * @brief Writes raw byte data to the specified memory address.
	 *
	 * Must be implemented by hardware-specific memory drivers.
	 *
	 * @param[in] addr Starting byte address.
	 * @param[in] src Pointer to source data buffer.
	 * @param[in] size Number of bytes to write.
	 * @return Error code indicating operation result.
	 */
	virtual error_t writeBytes(uint32_t addr, void *src, uint32_t size) = 0;

	/**
	 * @brief Reads raw byte data from the specified memory address.
	 *
	 * Must be implemented by hardware-specific memory drivers.
	 *
	 * @param[in] addr Starting byte address.
	 * @param[out] des Pointer to destination buffer where read data will be stored.
	 * @param[in] size Number of bytes to read.
	 * @return Error code indicating operation result.
	 */
	virtual error_t readBytes(uint32_t addr, void *des, uint32_t size) = 0;

protected:
	/**
	 * @brief Gets the total capacity of the memory device in bytes.
	 *
	 * Must be implemented by derived hardware memory classes to provide total memory size.
	 *
	 * @return Total memory size in bytes.
	 */
	virtual uint32_t getSize(void) = 0;

};

#endif
/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file MassStorage.h
 * @brief Hardware Abstraction Layer (HAL) interface for mass storage devices.
 */

#ifndef	YSS_SAC_MASS_STORAGE__H_
#define	YSS_SAC_MASS_STORAGE__H_

#include <yss/scheduler.h>
#include <yss/error.h>
#include <yss/Mutex.h>

/**
 * @class MassStorage
 * @brief Abstract base class for block-based mass storage devices.
 *
 * This class defines the standard interface for block-oriented storage devices
 * such as SD cards, USB flash drives, and eMMC modules. It inherits from Mutex
 * to support thread-safe operations across concurrent tasks.
 */
class MassStorage : public Mutex
{
public :
	/**
	 * @brief Gets the size of a single storage block in bytes.
	 *
	 * @return The block size in bytes (e.g., 512 bytes for standard SD cards).
	 */
	virtual uint32_t getBlockSize(void) = 0;

	/**
	 * @brief Gets the total number of blocks available on the storage device.
	 *
	 * @return The total block count.
	 */
	virtual uint32_t getNumOfBlock(void) = 0;

	/**
	 * @brief Writes a single block of data to the specified block index.
	 *
	 * @param[in] block Target block index to write to.
	 * @param[in] src Pointer to the source memory buffer containing data to write.
	 * @return Error code indicating success (error_t::ERROR_NONE) or failure.
	 */
	virtual error_t write(uint32_t block, void *src) = 0;

	/**
	 * @brief Reads a single block of data from the specified block index.
	 *
	 * @param[in] block Target block index to read from.
	 * @param[out] des Pointer to the destination memory buffer to store read data.
	 * @return Error code indicating success (error_t::ERROR_NONE) or failure.
	 */
	virtual error_t read(uint32_t block, void *des) = 0;

	/**
	 * @brief Checks whether the mass storage device is connected and ready.
	 *
	 * @return True if the device is connected and ready for I/O; false otherwise.
	 */
	virtual bool isConnected(void) = 0;
};

#endif


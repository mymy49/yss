/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Hbi.h
 * @brief Host Bus Interface (HBI) driver class header file.
 */

#ifndef YSS_DRV_HBI__H_
#define YSS_DRV_HBI__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @class Hbi
 * @brief Host Bus Interface (HBI) driver base class.
 * 
 * @details
 * This driver class provides virtual APIs for initializing and managing the Host Bus Interface,
 * which is commonly used to communicate with external memories/peripherals.
 */
class Hbi
{
public:
	/**
	 * @brief Enumeration for burst transfer group size.
	 */
	typedef enum
	{
		BURST_GROUP_SIZE_16BYTES = 0, ///< 16 bytes burst size
		BURST_GROUP_SIZE_32BYTES,     ///< 32 bytes burst size
		BURST_GROUP_SIZE_64BYTES,     ///< 64 bytes burst size
		BURST_GROUP_SIZE_128BYTES     ///< 128 bytes burst size
	}bustGroupSize_t;

	/**
	 * @struct config_t
	 * @brief Configuration parameters for HBI initialization.
	 */
    typedef struct
	{
		float tCSS_min_ns;       ///< Minimum chip select setup time in ns.
		float tACC_min_ns;       ///< Minimum access time in ns.
		float tCSH_min_ns;       ///< Minimum chip select hold time in ns.
		float tCSHI_min_ns;      ///< Minimum chip select high time in ns.
		float tCSM_max_us;       ///< Maximum chip select pulse width in us.
		bustGroupSize_t bgs;     ///< Burst group size.
		uint32_t capcacity;      ///< Total capacity of the attached memory in bytes.
		uint32_t maxFrequency;   ///< Maximum supported HBI frequency in Hz.
	}config_t;

	/**
	 * @brief Initializes the HBI peripheral with specified configuration.
	 * 
	 * @param[in] config HBI controller configuration.
	 * @param[in] ahbclkFreq Current frequency of the AHB clock in Hz.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t initialize(config_t config, uint32_t ahbclkFreq) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Gets the total capacity configured for the host bus.
	 * 
	 * @return uint32_t Capacity in bytes.
	 */
	uint32_t getCapacity(void);

	// The following are internal functions/variables and do not need to be called by the user application.
protected:
	uint32_t mCapacity; ///< Stored capacity of the external memory.

};

#endif


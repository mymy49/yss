/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Pbus.h
 * @brief Parallel Bus (PBUS) driver class header file.
 */

#ifndef YSS_DRV_PBUS__H_
#define YSS_DRV_PBUS__H_

#include "peripheral.h"

#if defined(STM32F7)

#else

#define YSS_DRV_PBUS_UNSUPPORTED

#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>

/**
 * @class Pbus
 * @brief Driver class for the Parallel Bus (PBUS) interface.
 */
class Pbus : public Drv
{
public:
	typedef struct
	{
		uint8_t dataLatency;		// HCLK * dataLatency
		uint8_t clockDiv;			// HCLK / clockDiv
		uint8_t busTurnaround;		// HCLK * busTurnaround
		uint8_t data;				// HCLK * data
		uint8_t addrHold;			// HCLK * addrHold
		uint8_t addrSetup;			// HCLK * addrSetup
	}specification_t;
	
	/**
	 * @brief Initializes the PBUS peripheral.
	 * 
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t initialize(void);

	/**
	 * @brief Configures transmission specifications for the PBUS.
	 * 
	 * @param[in] spec Struct containing target timing and latency specifications.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t setSpecification(const specification_t &spec);

	// The following are internal functions and do not need to be called by the user application.
	Pbus(const Drv::setup_t drvSetup);

private:
};

#endif


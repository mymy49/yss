/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file I2c.h
 * @brief I2C (Inter-Integrated Circuit) driver class header file.
 */

#ifndef YSS_DRV_I2C__H_
#define YSS_DRV_I2C__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @class I2c
 * @brief Driver class for the I2C peripheral interface.
 * 
 * @details
 * This driver class provides virtual APIs for initializing and performing standard
 * I2C master transmit (send) and receive operations.
 */
class I2c : public Drv
{
public:
	/**
	 * @brief Enumeration for I2C communication speed modes.
	 */
    typedef enum
	{
		SPEED_STANDARD = 0, ///< Standard Mode (up to 100 kHz)
		SPEED_FAST,         ///< Fast Mode (up to 400 kHz)
		SPEED_FAST_PLUS     ///< Fast Mode Plus (up to 1 MHz)
	}speed_t;

	/**
	 * @brief Main configuration parameters for I2C peripheral setup.
	 */
	typedef struct
	{
		speed_t speed;			///< Communication speed mode.
	}mainConfig_t;

	/**
	 * @brief Initializes the I2C peripheral with specified configurations.
	 * 
	 * @param[in] config Main setup configurations.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t initialize(mainConfig_t config) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Transmits a block of data to a slave device.
	 * 
	 * @param[in] addr The 7-bit or 10-bit address of the target I2C slave.
	 * @param[in] src Pointer to the data payload buffer to be sent.
	 * @param[in] size The size of the data payload in bytes.
	 * @param[in] timeout Timeout limit for the operation in milliseconds.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t send(uint8_t addr, void *src, uint32_t size, uint32_t timeout = 500) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Receives a block of data from a slave device.
	 * 
	 * @param[in] addr The 7-bit or 10-bit address of the target I2C slave.
	 * @param[out] des Pointer to the destination buffer to store the received data.
	 * @param[in] size The size of the data payload to receive in bytes.
	 * @param[in] timeout Timeout limit for the operation in milliseconds.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout = 500) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Generates an I2C STOP condition to release the bus.
	 */
	virtual void stop(void) __attribute__((optimize("-O1"))) = 0;

	// The following are internal functions and do not need to be called by the user application.
	I2c(const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));
};

#endif


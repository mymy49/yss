/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_I2C__H_
#define YSS_NUVOTON_DRV_I2C__H_

#include <drv/I2c.h>
#include <yss/error.h>

/**
 * @file NuvotonI2c.h
 * @brief I2C (Inter-Integrated Circuit) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonI2c
 * @brief Driver class for the I2C peripheral on Nuvoton MCUs operating in master mode.
 *
 * @details
 * This class inherits from the base I2c class and provides control functions to initialize the
 * I2C interface, transmit data to a slave, receive data from a slave, and trigger stop conditions.
 * The driver uses interrupt-driven status state-machines to manage bus transactions.
 */
class NuvotonI2c : public I2c
{
public:
	/**
	 * @brief Initializes the I2C master device.
	 * @details Calculates the clock divider based on the requested bus speed (standard/fast mode).
	 *
	 * @param[in] config Master configuration settings (e.g., bus speed).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(mainConfig_t config) __attribute__((optimize("-O1")));

	/**
	 * @brief Transmits a data block to a specified slave address.
	 *
	 * @param[in] addr The 7-bit target slave address (unshifted).
	 * @param[in] src Pointer to the data buffer to send.
	 * @param[in] size Size of the data block in bytes.
	 * @param[in] timeout Transaction timeout duration in milliseconds (default is 500).
	 * @return error_t Returns an error code (ERROR_NONE on success, or NACK/TIMEOUT).
	 */
	virtual error_t send(uint8_t addr, void *src, uint32_t size, uint32_t timeout = 500) __attribute__((optimize("-O1")));

	/**
	 * @brief Receives a data block from a specified slave address.
	 *
	 * @param[in] addr The 7-bit target slave address (unshifted).
	 * @param[out] des Pointer to the destination buffer to store the received data.
	 * @param[in] size Size of the data block in bytes.
	 * @param[in] timeout Transaction timeout duration in milliseconds (default is 500).
	 * @return error_t Returns an error code (ERROR_NONE on success, or NACK/TIMEOUT).
	 */
	virtual error_t receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout = 500) __attribute__((optimize("-O1")));

	/**
	 * @brief Generates an I2C STOP condition on the bus.
	 */
	virtual void stop(void) __attribute__((optimize("-O1")));

	// Internal system functions. Do not call from user application.
	struct setup_t
	{
		I2C_T *dev;
	};

	NuvotonI2c(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private :
	I2C_T *mDev;
	int32_t mDataCount;
	uint8_t *mDataBuf, mAddr;
	error_t mError;
	bool mDir, mComplete;
};

#endif



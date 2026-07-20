/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_I2C__H_
#define YSS_DRV_I2C__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @file I2c.h
 * @brief I2C (Inter-Integrated Circuit) driver class header file.
 *
 * ### Initialization Flow
 * 1. Configure the GPIO pins related to the I2C peripheral (SCL, SDA) as alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the peripheral using `enableClock()`.
 * 3. Initialize the I2C driver setting the speed configuration (Standard Mode, Fast Mode) using `initialize()`.
 * 4. Enable the peripheral interrupts using `enableInterrupt()`.
 *
 * ### Initialization Example
 * @code
 * // Configure target pins for I2C function
 * gpioB.setAsAltFunc(6, Gpio::PB6_I2C1_SCL);
 * gpioB.setAsAltFunc(7, Gpio::PB7_I2C1_SDA);
 * 
 * i2c1.enableClock(); // Supply clock
 * 
 * // Configure I2C speed
 * I2c::mainConfig_t i2cConfig = {
 *     I2c::SPEED_FAST // Fast Mode (400 kHz)
 * };
 * 
 * i2c1.initialize(i2cConfig);
 * i2c1.enableInterrupt(); // Enable interrupt service
 * @endcode
 *
 * ### Transmission Flow
 * 1. Call `lock()` to gain exclusive access to the I2C bus.
 * 2. Call `send()` with the 7-bit slave address, payload data pointer, data size, and optional timeout.
 * 3. Call `stop()` to release the bus or generate a STOP condition.
 * 4. Call `unlock()` to release ownership.
 *
 * ### Transmission Example
 * @code
 * uint8_t txData[] = {0x00, 0x12, 0x34}; // Reg address and values
 * 
 * i2c1.lock();
 * if (i2c1.send(0xA0, txData, sizeof(txData)) == error_t::ERROR_NONE)
 * {
 *     // Transmit success
 * }
 * i2c1.unlock();
 * @endcode
 *
 * ### Reception Flow
 * 1. Call `lock()` to acquire exclusive access.
 * 2. Call `receive()` with the 7-bit slave address, destination buffer pointer, expected bytes to receive, and optional timeout.
 * 3. Call `stop()` if necessary.
 * 4. Call `unlock()` to release ownership.
 *
 * ### Reception Example
 * @code
 * uint8_t rxData[2];
 * 
 * i2c1.lock();
 * // First send registry address, then read response
 * uint8_t regAddr = 0x10;
 * if (i2c1.send(0xA0, &regAddr, 1) == error_t::ERROR_NONE)
 * {
 *     if (i2c1.receive(0xA0, rxData, 2) == error_t::ERROR_NONE)
 *     {
 *         // Read success
 *     }
 * }
 * i2c1.unlock();
 * @endcode
 *
 * ### Hardware/Driver Implementation Details
 * - On supported platforms (e.g. Nuvoton), the driver executes I2C transactions asynchronously via interrupt-driven state machines and yields the calling thread (`thread::yield()`) to save CPU resources while waiting for hardware events.
 */

/**
 * @class I2c
 * @brief Driver class for the I2C peripheral interface.
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


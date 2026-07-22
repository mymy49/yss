/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_QUADSPI__H_
#define YSS_DRV_QUADSPI__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @file Quadspi.h
 * @brief Quad-SPI (QSPI) driver class header file.
 *
 * ### Initialization Flow
 * 1. Configure the GPIO pins related to the QSPI peripheral (CS, CLK, IO0 to IO3) as alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the peripheral using `enableClock()`.
 * 3. Initialize the QSPI peripheral using `initialize()`.
 * 4. Configure QSPI transmission specifications (max frequency, flash capacity, clock mode) using `setSpecification()`.
 *
 * ### Initialization Example
 * @code
 * // Configure target pins for QSPI function
 * gpioA.setAsAltFunc(6, Gpio::PA6_QUADSPI_CLK);
 * gpioA.setAsAltFunc(7, Gpio::PA7_QUADSPI_CS);
 * gpioB.setAsAltFunc(0, Gpio::PB0_QUADSPI_IO0);
 * gpioB.setAsAltFunc(1, Gpio::PB1_QUADSPI_IO1);
 * gpioB.setAsAltFunc(2, Gpio::PB2_QUADSPI_IO2);
 * gpioB.setAsAltFunc(3, Gpio::PB3_QUADSPI_IO3);
 * 
 * qspi.enableClock(); // Supply clock
 * 
 * Quadspi::config_t qspiConfig = {
 *     Quadspi::MODE_MAIN // Master mode
 * };
 * qspi.initialize(qspiConfig);
 * 
 * Quadspi::specification_t qspiSpec = {
 *     50000000,                  // maxFrequency 50 MHz
 *     16 * 1024 * 1024,          // capacity 16 MB
 *     Quadspi::CLOCK_MODE_MODE0  // Clock mode 0
 * };
 * qspi.setSpecification(qspiSpec);
 * @endcode
 *
 * ### Transmission/Reception Flow
 * 1. Formulate the `dataform_t` struct specifying transaction bit width (Single, Double, Quad), MSB/LSB order, reordering, and data width.
 * 2. Call `transmit()`, `exchange()`, or `receive()` with the dataform configuration and data.
 *
 * ### Transmission Example
 * @code
 * Quadspi::dataform_t df = {
 *     Quadspi::BIT_WIDTH_QUAD,       // bitWidth
 *     Quadspi::DATA_WIDTH_8BIT,      // dataWidth
 *     Quadspi::BIT_ORDER_MSB,        // bitOrder
 *     Quadspi::BYTE_REORDER_DISABLE  // byteReorder
 * };
 * 
 * uint8_t writeCmd = 0x02; // Page Program Command
 * qspi.transmit(df, writeCmd);
 * @endcode
 */

/**
 * @class Quadspi
 * @brief Driver class for the Quad-SPI (QSPI) peripheral interface.
 */
class Quadspi : public Drv
{
public :
	typedef enum
	{
		MODE_MAIN = 0,
		MODE_SUB
	}mode_t;

	typedef enum
	{
		CLOCK_MODE_MODE0 = 0,
		CLOCK_MODE_MODE1,
		CLOCK_MODE_MODE2,
		CLOCK_MODE_MODE3,
	}clockMode_t;

	typedef enum
	{
		BIT_WIDTH_SINGLE = 0,
		BIT_WIDTH_DOUBLE,
		BIT_WIDTH_QUAD,
	}bitWidth_t;

	typedef enum
	{
		DATA_WIDTH_8BIT = 0,
		DATA_WIDTH_9BIT,
		DATA_WIDTH_10BIT,
		DATA_WIDTH_11BIT,
		DATA_WIDTH_12BIT,
		DATA_WIDTH_13BIT,
		DATA_WIDTH_14BIT,
		DATA_WIDTH_15BIT,
		DATA_WIDTH_16BIT,
		DATA_WIDTH_17BIT,
		DATA_WIDTH_18BIT,
		DATA_WIDTH_19BIT,
		DATA_WIDTH_20BIT,
		DATA_WIDTH_21BIT,
		DATA_WIDTH_22BIT,
		DATA_WIDTH_23BIT,
		DATA_WIDTH_24BIT,
		DATA_WIDTH_25BIT,
		DATA_WIDTH_26BIT,
		DATA_WIDTH_27BIT,
		DATA_WIDTH_28BIT,
		DATA_WIDTH_29BIT,
		DATA_WIDTH_30BIT,
		DATA_WIDTH_31BIT,
		DATA_WIDTH_32BIT
	}dataWidth_t;

	typedef enum
	{
		BIT_ORDER_MSB = 0,
		BIT_ORDER_LSB
	}bitOrder_t;

	typedef enum
	{
		BYTE_REORDER_DISABLE = 0,
		BYTE_REORDER_ENABLE
	}byteReorder_t;

	typedef struct 
	{
		uint32_t maxFrequncy;
		uint32_t capacity;
		clockMode_t clockMode;
	}specification_t;

	typedef struct 
	{
		bitWidth_t bitWidth;
		dataWidth_t dataWidth;
		bitOrder_t bitOrder;
		byteReorder_t byteReorder;
	}dataform_t;

	typedef struct
	{
		mode_t mode;
	}config_t;

	virtual error_t initialize(config_t config) = 0;

	virtual error_t setSpecification(const specification_t &spec) = 0;

	virtual error_t transmit(dataform_t dataform, uint32_t data) = 0;

	virtual error_t exchange(dataform_t dataform, uint32_t &data) = 0;

	virtual error_t receive(dataform_t dataform, uint32_t &data) = 0;

	virtual error_t transmit(dataform_t dataform, void *data, uint32_t size) = 0;

	virtual error_t exchange(dataform_t dataform, void *data, uint32_t size) = 0;

	uint32_t getCapacity(void);

	// The following are internal functions and do not need to be called by the user application.
	Quadspi(const Drv::setup_t drvSetup);

protected :
	uint32_t mCapacity;
	specification_t *mLastSpec;
	dataform_t *mLastForm;
};

#endif


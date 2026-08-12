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
	/**
	 * @brief Enumeration for QSPI operating mode.
	 */
	typedef enum
	{
		MODE_MAIN = 0, ///< Master (main) mode: the QSPI controller drives the clock.
		MODE_SUB       ///< Slave (sub) mode: clock is provided by an external master.
	}mode_t;

	/**
	 * @brief Enumeration for QSPI clock polarity mode.
	 * @details Selects the idle state and capture edge of the QSPI serial clock.
	 */
	typedef enum
	{
		CLOCK_MODE_MODE0 = 0, ///< Clock idles Low;  data sampled on rising edge  (CPOL=0, CPHA=0)
		CLOCK_MODE_MODE1,     ///< Clock idles Low;  data sampled on falling edge (CPOL=0, CPHA=1)
		CLOCK_MODE_MODE2,     ///< Clock idles High; data sampled on falling edge (CPOL=1, CPHA=0)
		CLOCK_MODE_MODE3,     ///< Clock idles High; data sampled on rising edge  (CPOL=1, CPHA=1)
	}clockMode_t;

	/**
	 * @brief Enumeration for the number of active data lines (bus width).
	 */
	typedef enum
	{
		BIT_WIDTH_SINGLE = 0, ///< Single-bit (1-wire) SPI mode (standard SPI)
		BIT_WIDTH_DOUBLE,     ///< Dual-bit (2-wire) mode (Dual SPI)
		BIT_WIDTH_QUAD,       ///< Quad-bit (4-wire) mode (Quad SPI / QSPI)
	}bitWidth_t;

	/**
	 * @brief Enumeration for the number of data bits per QSPI transaction frame.
	 * @details Selects how many bits are transferred in a single QSPI frame (8 to 32 bits).
	 */
	typedef enum
	{
		DATA_WIDTH_8BIT  = 0,  ///< 8-bit data frame
		DATA_WIDTH_9BIT,       ///< 9-bit data frame
		DATA_WIDTH_10BIT,      ///< 10-bit data frame
		DATA_WIDTH_11BIT,      ///< 11-bit data frame
		DATA_WIDTH_12BIT,      ///< 12-bit data frame
		DATA_WIDTH_13BIT,      ///< 13-bit data frame
		DATA_WIDTH_14BIT,      ///< 14-bit data frame
		DATA_WIDTH_15BIT,      ///< 15-bit data frame
		DATA_WIDTH_16BIT,      ///< 16-bit data frame
		DATA_WIDTH_17BIT,      ///< 17-bit data frame
		DATA_WIDTH_18BIT,      ///< 18-bit data frame
		DATA_WIDTH_19BIT,      ///< 19-bit data frame
		DATA_WIDTH_20BIT,      ///< 20-bit data frame
		DATA_WIDTH_21BIT,      ///< 21-bit data frame
		DATA_WIDTH_22BIT,      ///< 22-bit data frame
		DATA_WIDTH_23BIT,      ///< 23-bit data frame
		DATA_WIDTH_24BIT,      ///< 24-bit data frame
		DATA_WIDTH_25BIT,      ///< 25-bit data frame
		DATA_WIDTH_26BIT,      ///< 26-bit data frame
		DATA_WIDTH_27BIT,      ///< 27-bit data frame
		DATA_WIDTH_28BIT,      ///< 28-bit data frame
		DATA_WIDTH_29BIT,      ///< 29-bit data frame
		DATA_WIDTH_30BIT,      ///< 30-bit data frame
		DATA_WIDTH_31BIT,      ///< 31-bit data frame
		DATA_WIDTH_32BIT       ///< 32-bit data frame
	}dataWidth_t;

	/**
	 * @brief Enumeration for the bit transmission order within a data frame.
	 */
	typedef enum
	{
		BIT_ORDER_MSB = 0, ///< Most Significant Bit transmitted first (standard)
		BIT_ORDER_LSB      ///< Least Significant Bit transmitted first
	}bitOrder_t;

	/**
	 * @brief Enumeration for byte reordering (endianness swap) of multi-byte transfers.
	 */
	typedef enum
	{
		BYTE_REORDER_DISABLE = 0, ///< No byte reordering; data is transmitted in memory order
		BYTE_REORDER_ENABLE       ///< Byte order is reversed (big-endian ↔ little-endian swap)
	}byteReorder_t;

	/**
	 * @struct specification_t
	 * @brief Device-level QSPI flash/memory specification.
	 *
	 * @details
	 * Used with `setSpecification()` to inform the driver about the capabilities
	 * and constraints of the connected QSPI device. Must be called once after
	 * `initialize()` before any data transfer operations.
	 */
	typedef struct 
	{
		uint32_t maxFrequncy; ///< Maximum QSPI clock frequency supported by the connected device in Hz.
		uint32_t capacity;    ///< Total addressable capacity of the connected device in bytes.
		clockMode_t clockMode;///< QSPI clock polarity and phase mode compatible with the device.
	}specification_t;

	/**
	 * @struct dataform_t
	 * @brief Per-transaction data format specification for QSPI transfers.
	 *
	 * @details
	 * Passed to `transmit()`, `exchange()`, or `receive()` to specify how bits
	 * are sent/received in that particular transaction (bus width, data width,
	 * bit order, byte reorder). Different commands (e.g. single-wire command
	 * byte followed by quad-wire data) require different dataform configurations.
	 */
	typedef struct 
	{
		bitWidth_t bitWidth;        ///< Number of active data lines for this transaction (single/dual/quad).
		dataWidth_t dataWidth;      ///< Number of bits per data frame in this transaction.
		bitOrder_t bitOrder;        ///< Bit transmission order (MSB-first or LSB-first).
		byteReorder_t byteReorder;  ///< Byte reorder (endianness swap) setting for multi-byte frames.
	}dataform_t;

	/**
	 * @struct config_t
	 * @brief One-time initialization configuration for the QSPI peripheral.
	 */
	typedef struct
	{
		mode_t mode; ///< QSPI operating mode: master (MODE_MAIN) or slave (MODE_SUB).
	}config_t;

	/**
	 * @brief Initializes the QSPI peripheral.
	 *
	 * @param[in] config One-time initialization configuration.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t initialize(config_t config) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Applies the device-level QSPI specification (max frequency, capacity, clock mode).
	 *
	 * @details
	 * Must be called after `initialize()` and before any data transfer.
	 * Different devices on the same bus may require different specifications.
	 *
	 * @param[in] spec Reference to the device specification structure.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t setSpecification(const specification_t &spec) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Transmits a single data word.
	 *
	 * @param[in] dataform Data format specification for this transaction.
	 * @param[in] data     Data word to transmit.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t transmit(dataform_t dataform, uint32_t data) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Simultaneously transmits and receives a single data word.
	 *
	 * @param[in]  dataform Data format specification for this transaction.
	 * @param[out] data     Reference to a variable where the received data word is stored.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t exchange(dataform_t dataform, uint32_t &data) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Receives a single data word.
	 *
	 * @param[in]  dataform Data format specification for this transaction.
	 * @param[out] data     Reference to a variable where the received data word is stored.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t receive(dataform_t dataform, uint32_t &data) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Transmits a block of data.
	 *
	 * @param[in] dataform Data format specification for this transaction.
	 * @param[in] data     Pointer to the data payload buffer.
	 * @param[in] size     Number of bytes to transmit.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t transmit(dataform_t dataform, void *data, uint32_t size) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Simultaneously transmits and receives a block of data.
	 *
	 * @details
	 * The transmitted data buffer is overwritten with the received data in-place.
	 *
	 * @param[in,out] data Pointer to the buffer: input data to transmit, output received data.
	 * @param[in]     size Number of bytes to exchange.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t exchange(dataform_t dataform, void *data, uint32_t size) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Gets the capacity of the connected QSPI device.
	 *
	 * @details
	 * Returns the capacity value last set by `setSpecification()`.
	 *
	 * @return uint32_t The device capacity in bytes.
	 */
	uint32_t getCapacity(void);

	// The following are internal functions and do not need to be called by the user application.
	/**
	 * @brief Constructor for the Quadspi class.
	 *
	 * @param[in] drvSetup Base driver setup configuration (clock, NVIC function pointers).
	 */
	Quadspi(const Drv::setup_t drvSetup);

protected :
	uint32_t mCapacity;              ///< Cached capacity of the connected QSPI device in bytes.
	specification_t *mLastSpec;      ///< Pointer to the last applied device specification.
	dataform_t *mLastForm;           ///< Pointer to the last applied data format configuration.
};

#endif


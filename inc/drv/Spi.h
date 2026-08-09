/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more
 * details.
 */

#ifndef YSS_DRV_SPI__H_
#define YSS_DRV_SPI__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @file Spi.h
 * @brief Serial Peripheral Interface (SPI) driver class header file.
 *
 * ### Initialization Flow
 * 1. Configure target pins (MISO, MOSI, SCK) as alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Supply the peripheral clock using `enableClock()`.
 * 3. Initialize the SPI device using `initialize()`.
 * 4. Enable the peripheral interrupts using `enableInterrupt()`.
 *
 * ### Initialization Example
 * @code
 * // Configure GPIO pins for SPI function
 * gpioA.setAsAltFunc(5, Gpio::PA5_SPI1_SCK);
 * gpioA.setAsAltFunc(6, Gpio::PA6_SPI1_MISO);
 * gpioA.setAsAltFunc(7, Gpio::PA7_SPI1_MOSI);
 * 
 * spi1.enableClock();          // Supply clock
 * 
 * Spi::config_t spiConfig = {
 *     Spi::MODE_MAIN            // Configure as main/master device
 * };
 * spi1.initialize(spiConfig);  // Initialize the peripheral
 * spi1.enableInterrupt();       // Enable interrupt handler
 * @endcode
 *
 * ### Transmit/Exchange Flow
 * 1. Call `lock()` to acquire ownership of the SPI hardware from other threads.
 * 2. Call `setSpecification()` to configure the mode, bit width, and speed parameters.
 * 3. Call `enable(true)` to activate the SPI peripheral.
 * 4. Drive the Chip Select (CS) pin of the target device to Low.
 * 5. Call `send()` or `exchange()` to perform data transmission/reception.
 * 6. Drive the Chip Select (CS) pin of the target device to High.
 * 7. Call `enable(false)` to deactivate the SPI peripheral.
 * 8. Call `unlock()` to release ownership.
 *
 * ### Transmit/Exchange Example
 * @code
 * Spi::specification_t spec = {
 *     Spi::CLOCK_MODE_MODE0,   // SPI Clock polarity and phase (mode 0)
 *     10000000,                // 10 MHz max clock frequency
 *     Spi::BIT_BIT8            // 8-bit transfer width
 * };
 * 
 * spi1.lock();                 // Prevent concurrent access
 * spi1.setSpecification(spec); // Configure SPI parameters
 * spi1.enable(true);           // Enable SPI peripheral
 * 
 * gpioA.setOutput(4, false);   // Chip Select (CS) Low
 * 
 * uint8_t txData = 0x55, rxData;
 * rxData = spi1.exchange(txData); // Exchange a single byte
 * 
 * gpioA.setOutput(4, true);    // Chip Select (CS) High
 * 
 * spi1.enable(false);          // Disable SPI peripheral
 * spi1.unlock();               // Release ownership
 * @endcode
 *
 * ### Hardware/Driver Implementation Details
 * - The driver supports configurable data widths from 4-bit up to 32-bit depending on hardware limits.
 * - On supported platforms (e.g. Nuvoton), the driver automatically utilizes PDMA channels to transfer block data and yields the calling thread to optimize CPU performance.
 */

/**
 * @class Spi
 * @brief Driver class for the Serial Peripheral Interface (SPI) peripheral.
 */
class Spi : public Drv {
public:
  /**
   * @brief Enumeration for SPI operating mode (master or slave).
   */
  typedef enum {
    MODE_MAIN = 0, ///< Master (main) mode: generates the clock signal.
    MODE_SUB,      ///< Slave (sub) mode: clock is driven by an external master.
  } mode_t;

  /**
   * @brief Enumeration for SPI clock polarity and phase mode (CPOL/CPHA).
   * @details Determines the idle state of the clock and which clock edge
   *          is used to sample or shift data.
   *          - Mode 0: CPOL=0, CPHA=0 — idle Low, sample on rising edge
   *          - Mode 1: CPOL=0, CPHA=1 — idle Low, sample on falling edge
   *          - Mode 2: CPOL=1, CPHA=0 — idle High, sample on falling edge
   *          - Mode 3: CPOL=1, CPHA=1 — idle High, sample on rising edge
   */
  typedef enum {
    CLOCK_MODE_MODE0 = 0, ///< CPOL=0, CPHA=0 (idle Low, sample on leading/rising edge)
    CLOCK_MODE_MODE1,     ///< CPOL=0, CPHA=1 (idle Low, sample on trailing/falling edge)
    CLOCK_MODE_MODE2,     ///< CPOL=1, CPHA=0 (idle High, sample on leading/falling edge)
    CLOCK_MODE_MODE3,     ///< CPOL=1, CPHA=1 (idle High, sample on trailing/rising edge)
  } clockMode_t;

  /**
   * @brief Enumeration for SPI data transfer word width (number of bits per frame).
   * @details Selects the number of bits transferred in a single SPI frame.
   *          Supported range is 4-bit to 32-bit depending on the target hardware.
   */
  typedef enum {
    BIT_BIT4  = 0,  ///< 4-bit transfer width
    BIT_BIT5,       ///< 5-bit transfer width
    BIT_BIT6,       ///< 6-bit transfer width
    BIT_BIT7,       ///< 7-bit transfer width
    BIT_BIT8,       ///< 8-bit transfer width (most common)
    BIT_BIT9,       ///< 9-bit transfer width
    BIT_BIT10,      ///< 10-bit transfer width
    BIT_BIT11,      ///< 11-bit transfer width
    BIT_BIT12,      ///< 12-bit transfer width
    BIT_BIT13,      ///< 13-bit transfer width
    BIT_BIT14,      ///< 14-bit transfer width
    BIT_BIT15,      ///< 15-bit transfer width
    BIT_BIT16,      ///< 16-bit transfer width
    BIT_BIT17,      ///< 17-bit transfer width
    BIT_BIT18,      ///< 18-bit transfer width
    BIT_BIT19,      ///< 19-bit transfer width
    BIT_BIT20,      ///< 20-bit transfer width
    BIT_BIT21,      ///< 21-bit transfer width
    BIT_BIT22,      ///< 22-bit transfer width
    BIT_BIT23,      ///< 23-bit transfer width
    BIT_BIT24,      ///< 24-bit transfer width
    BIT_BIT25,      ///< 25-bit transfer width
    BIT_BIT26,      ///< 26-bit transfer width
    BIT_BIT27,      ///< 27-bit transfer width
    BIT_BIT28,      ///< 28-bit transfer width
    BIT_BIT29,      ///< 29-bit transfer width
    BIT_BIT30,      ///< 30-bit transfer width
    BIT_BIT31,      ///< 31-bit transfer width
    BIT_BIT32,      ///< 32-bit transfer width
  } bit_t;

  /**
   * @struct specification_t
   * @brief Per-transaction SPI transfer specification.
   *
   * @details
   * Used with `setSpecification()` to configure clock mode, maximum frequency,
   * and data width for the connected peripheral. Different slave devices on the
   * same bus may require different specifications; reconfigure before each transaction.
   */
  typedef struct {
    clockMode_t mode;   ///< SPI clock polarity and phase mode (CPOL/CPHA).
    int32_t maxFreq;    ///< Maximum SPI clock frequency in Hz. The driver selects the closest achievable frequency that does not exceed this value.
    bit_t bit;          ///< Data transfer word width (number of bits per SPI frame).
  } specification_t;

  /**
   * @struct config_t
   * @brief One-time initialization configuration for the SPI peripheral.
   */
  typedef struct {
    mode_t mode; ///< SPI operating mode: master (MODE_MAIN) or slave (MODE_SUB).
  } config_t;

  /**
   * @brief Initializes the SPI peripheral.
   * @details The device is initialized but not yet enabled.
   *
   * @param[in] config Configuration parameters.
   * @return error_t Returns ERROR_NONE on success.
   */
  virtual error_t initialize(config_t config)
      __attribute__((optimize("-O1"))) = 0;

  /**
   * @brief Configures transmission specifications for the SPI peripheral.
   * @details Before calling this function, the peripheral must be disabled
   * using enable(false).
   *
   * @param[in] spec Struct containing target speed, mode, and bit width
   * specifications.
   * @return error_t Returns ERROR_NONE on success.
   */
  virtual error_t setSpecification(const specification_t &spec)
      __attribute__((optimize("-O1"))) = 0;

  /**
   * @brief Transmits a single byte of data.
   * @details Received data during transmission is discarded.
   *
   * @param[in] data The data byte to transmit.
   */
  virtual void send(uint32_t data) __attribute__((optimize("-O1"))) = 0;

  /**
   * @brief Transmits a block of data.
   * @details Received data during transmission is discarded.
   *
   * @param[in] src Pointer to the data payload buffer.
   * @param[in] size The size of the data payload in bytes.
   * @return error_t Returns ERROR_NONE on success.
   */
  virtual error_t send(void *src, int32_t size)
      __attribute__((optimize("-O1"))) = 0;

  /**
   * @brief Transmits and receives a single byte of data simultaneously.
   *
   * @param[in] data The data byte to transmit.
   * @return uint32_t The received data byte.
   */
  virtual uint32_t exchange(uint32_t data) __attribute__((optimize("-O1"))) = 0;

  /**
   * @brief Transmits and receives a block of data simultaneously.
   * @details Transmitted data buffer is overwritten with the received data.
   *
   * @param[in,out] des Pointer to the buffer where data is read from and
   * written to.
   * @param[in] size The size of the data block to exchange in bytes.
   * @return error_t Returns ERROR_NONE on success.
   */
  virtual error_t exchange(void *des, int32_t size)
      __attribute__((optimize("-O1"))) = 0;

  // The following are internal functions and do not need to be called by the
  // user application.
  Spi(const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

protected:
  const specification_t *mLastSpec;
  mode_t mMode;

  /**
   * @brief Enables or disables the SPI peripheral.
   * @details To ensure correct transmission, call setSpecification() to
   * configure target parameters before calling enable(true).
   *
   * @param[in] en If true, enables the SPI peripheral. If false, disables it.
   */
  virtual void enable(bool en) __attribute__((optimize("-O1"))) = 0;
};

#endif

// Initialization guide:
//		- Use Gpio::setAsAltFunc() to configure target pins for SPI function.
//		- Supply clock to the peripheral using enableClock().
//		- Call initialize() to configure the device as a master.
//		- Enable SPI interrupts using enableInterrupt().

// Transmit/Exchange guide:
//		- Call lock() to prevent concurrent access from other threads.
//		- Call setSpecification() to configure the transmission specs for the target device.
//		- Call enable(true) to activate the SPI peripheral.
//		- Set the Chip Select (CS) pin of the target device to Low.
//		- Call send() or exchange() to transmit or exchange data.
//		- Set the Chip Select (CS) pin of the target device to High.
//		- Call enable(false) to deactivate the SPI peripheral.
//		- Call unlock() to release ownership.

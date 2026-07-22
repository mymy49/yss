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
  typedef enum {
    MODE_MAIN = 0,
    MODE_SUB,
  } mode_t;

  typedef enum {
    CLOCK_MODE_MODE0 = 0,
    CLOCK_MODE_MODE1,
    CLOCK_MODE_MODE2,
    CLOCK_MODE_MODE3,
  } clockMode_t;

  typedef enum {
    BIT_BIT4 = 0,
    BIT_BIT5,
    BIT_BIT6,
    BIT_BIT7,
    BIT_BIT8,
    BIT_BIT9,
    BIT_BIT10,
    BIT_BIT11,
    BIT_BIT12,
    BIT_BIT13,
    BIT_BIT14,
    BIT_BIT15,
    BIT_BIT16,
    BIT_BIT17,
    BIT_BIT18,
    BIT_BIT19,
    BIT_BIT20,
    BIT_BIT21,
    BIT_BIT22,
    BIT_BIT23,
    BIT_BIT24,
    BIT_BIT25,
    BIT_BIT26,
    BIT_BIT27,
    BIT_BIT28,
    BIT_BIT29,
    BIT_BIT30,
    BIT_BIT31,
    BIT_BIT32,
  } bit_t;

  typedef struct {
    clockMode_t mode;
    int32_t maxFreq;
    bit_t bit;
  } specification_t;

  typedef struct {
    mode_t mode;
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

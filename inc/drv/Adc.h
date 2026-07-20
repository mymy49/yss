/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more
 * details.
 */

#ifndef YSS_DRV_ADC__H_
#define YSS_DRV_ADC__H_

#include "Drv.h"
#include <yss/error.h>

#include <drv/Drv.h>
#include <yss/error.h>

/**
 * @file Adc.h
 * @brief ADC (Analog-to-Digital Converter) driver class header file.
 *
 * ### Initialization Flow
 * 1. Configure the GPIO pins related to the ADC as analog pins using the
 * `setAsAnalog()` function.
 * 2. Supply clock to the ADC peripheral using the `enableClock()` function.
 * 3. Initialize the ADC driver settings using the `initialize()` function.
 * 4. Register input channels using the `add()` function.
 * 5. Enable the interrupt for the peripheral using the `enableInterrupt()`
 * function.
 * 6. Start the conversion process using the `convert()` function.
 *
 * ### Initialization Example
 * @code
 * gpioA.setAsAnalog(4); // Set GPIOA pin 4 to analog mode
 *
 * adc1.enableClock();
 * adc1.initialize(1); // Set the number of channels to 1
 *
 * // Register channel 4 with Low Pass Filter level 10 and 12-bit resolution
 * adc1.add(define::gpio::analog::PA4_ADC_IN4, Adc::LPF_LV10, Adc::RES_BIT12);
 *
 * adc1.enableInterrupt();
 * adc1.convert(true); // Start converting
 * @endcode
 *
 * ### Retrieving ADC Results
 * - Retrieve the converted ADC results at any time using the `getResult()`
 * function.
 *
 * ### Result Retrieval Example
 * @code
 * int32_t result = adc1.getResult(0); // Retrieve the result of the channel
 * registered at index 0
 * @endcode
 *
 * ### Hardware/Driver Implementation Details
 * - The ADC driver operates via interrupts. Upon completion of each conversion,
 * the interrupt service routine rotates to the next registered ADC channel.
 * - Consequently, the sampling period of each individual channel is equal to
 * the total rotation cycle of all registered channels. To reduce the sampling
 * period, the sample time of all registered inputs must be minimized.
 * - For inputs sensitive to sampling latency, it is recommended to assign them
 * to separate ADC hardware instances. For example, assign low-speed channels to
 * `adc1` and high-speed channels to `adc2` (with only one or a few channels
 * registered).
 * - The ADC results are affected by the `lpflv` parameter of the `add()`
 * function. The configured Low Pass Filter level determines how fast the
 * filtered value converges to the physical value. The filter level is specified
 * as a relative level to prioritize processing speed rather than frequency.
 */

/**
 * @class Adc
 * @brief Driver class for ADC (Analog-to-Digital Converter) peripherals.
 *
 * @details
 * This class provides driver functions for ADC peripherals. It performs ADC
 * conversions on multiple channels by time-sharing a single ADC peripheral. The
 * resolution and Low Pass Filter (LPF) level can be configured for each input
 * channel.
 *
 * Note that the LPF level is qualitative rather than quantitative. This design
 * choice avoids a significant negative impact on the MCU's execution
 * performance. The user should observe the operating state and choose an
 * appropriate level. When the Low Pass Filter is active, it generates an
 * approximated result with a higher resolution than the physical ADC hardware
 * resolution.
 */
class Adc : public Drv {
public:
  /**
   * @brief Enumeration for Low Pass Filter (LPF) levels.
   * @details Higher levels provide stronger filtering but increase latency.
   */
  typedef enum {
    LPF_LV0 = 0, ///< LPF Level 0 (Filter disabled or minimum filtering)
    LPF_LV1,     ///< LPF Level 1
    LPF_LV2,     ///< LPF Level 2
    LPF_LV3,     ///< LPF Level 3
    LPF_LV4,     ///< LPF Level 4
    LPF_LV5,     ///< LPF Level 5
    LPF_LV6,     ///< LPF Level 6
    LPF_LV7,     ///< LPF Level 7
    LPF_LV8,     ///< LPF Level 8
    LPF_LV9,     ///< LPF Level 9
    LPF_LV10,    ///< LPF Level 10
    LPF_LV11,    ///< LPF Level 11
    LPF_LV12,    ///< LPF Level 12
    LPF_LV13,    ///< LPF Level 13
    LPF_LV14,    ///< LPF Level 14
    LPF_LV15,    ///< LPF Level 15
    LPF_LV16,    ///< LPF Level 16
    LPF_LV17,    ///< LPF Level 17
    LPF_LV18,    ///< LPF Level 18
    LPF_LV19,    ///< LPF Level 19
    LPF_LV20     ///< LPF Level 20
  } lpfLv_t;

  /**
   * @brief Enumeration for ADC resolution bits.
   * @details Defines the virtual resolution of the ADC channel, which can be
   * higher than the physical resolution when LPF is applied.
   */
  typedef enum {
    RES_BIT12 = 19, ///< 12-bit resolution
    RES_BIT13 = 18, ///< 13-bit resolution
    RES_BIT14 = 17, ///< 14-bit resolution
    RES_BIT15 = 16, ///< 15-bit resolution
    RES_BIT16 = 15, ///< 16-bit resolution
  } bit_t;

  /**
   * @brief Struct representing the configuration and state of an ADC channel.
   */
  typedef struct {
    int32_t result;   ///< The last converted and filtered ADC result.
    lpfLv_t lpfLevel; ///< The Low Pass Filter level applied to this channel.
    bit_t bit;        ///< The resolution bit depth config for this channel.
  } channel_t;

  /**
   * @brief Initializes the ADC device.
   * @details This function only initializes the internal driver states and
   * allocates memory. The ADC hardware is not fully activated or enabled yet.
   *
   * @param[in] numOfChannel The number of ADC channels to operate. Memory for
   * channel configurations will be dynamically allocated from the heap.
   * @return error_t Returns an error code (ERROR_NONE on success).
   */
  virtual error_t initialize(uint8_t numOfChannel) = 0;

  /**
   * @brief Adds and registers an ADC input channel.
   * @details Registers one input channel with a specific Low Pass Filter level
   * and resolution. Each channel must be added individually.
   *
   * @param[in] ch The hardware ADC channel number to register.
   * @param[in] lpflv The Low Pass Filter level for the channel.
   * @param[in] bit The virtual resolution bit depth for the channel.
   * @return error_t Returns an error code (ERROR_NONE on success).
   */
  virtual error_t add(uint8_t ch, lpfLv_t lpflv, bit_t bit) = 0;

  /**
   * @brief Starts or stops the ADC conversions.
   *
   * @param[in] en If true, starts the ADC conversion loop. If false, stops it.
   * @return error_t Returns an error code (ERROR_NONE on success).
   */
  virtual error_t convert(bool en) = 0;

  /**
   * @brief Gets the conversion result of a registered channel by its
   * registration index.
   *
   * @param[in] index The registration index of the channel (ranging from 0 to
   * numOfChannel - 1).
   * @return int32_t The ADC conversion result.
   */
  int32_t getResult(uint8_t index);

  /**
   * @brief Constructor for the Adc class.
   *
   * @param[in] drvSetup The base driver setup configuration.
   */
  Adc(const Drv::setup_t drvSetup);

protected:
  channel_t *mChannel; ///< Pointer to the array of registered channels.
  uint8_t
      mConvertingIndex; ///< The index of the channel currently being converted.
  uint8_t mChCount;     ///< The number of currently registered channels.
  uint8_t mMaxChCount;  ///< The maximum number of channels allowed (set during
                        ///< initialization).

  /**
   * @brief Dynamically allocates memory for the channel configurations.
   *
   * @param[in] numOfCh The number of channels to allocate memory for.
   * @return error_t Returns an error code (ERROR_NONE on success).
   */
  error_t malloc(uint8_t numOfCh);
};

#endif

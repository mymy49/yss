/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_DAC__H_
#define YSS_DRV_DAC__H_

#include "mcu.h"

#if defined (STM32F4) || defined(STM32F7)

typedef DAC_TypeDef				YSS_DAC_Peri;

#else

#define YSS_DRV_DAC_UNSUPPORTED
typedef volatile uint32_t		YSS_DAC_Peri;

#endif

#include "Drv.h"

/**
 * @file Dac.h
 * @brief DAC (Digital-to-Analog Converter) driver class header file.
 * 
 * ### Initialization Flow
 * 1. Configure the GPIO pin related to the target DAC channel as analog mode using the `setAsAnalog()` function.
 * 2. Supply clock to the DAC peripheral using the `enableClock()` function.
 * 3. Initialize the DAC driver configurations using the `initialize()` function.
 * 4. Enable individual DAC channels using `enableChannel1()` or `enableChannel2()`.
 * 5. Note: `enableInterrupt()` can be called but has no functional effect for the DAC driver.
 * 
 * ### Initialization Example
 * @code
 * gpioA.setAsAnalog(4); // Set GPIOA pin 4 to analog mode
 * 
 * dac1.enableClock();
 * dac1.initialize();
 * dac1.enableChannel1();
 * dac1.enableInterrupt();
 * @endcode
 * 
 * ### Usage
 * - Call `setOutputChannel1()` or `setOutputChannel2()` to set the analog output voltage value (typically 12-bit, e.g. 0 to 4095).
 * 
 * ### Usage Example
 * @code
 * dac1.setOutputChannel1(123); // Output analog voltage level matching DAC value 123
 * @endcode
 */

/**
 * @class Dac
 * @brief Driver class for the DAC (Digital-to-Analog Converter) peripheral.
 * 
 * @details
 * This driver class provides interface functions to configure and output analog voltages
 * using the hardware DAC channels. Each channel must be enabled individually after initializing the device.
 */
class Dac : public Drv
{
public:
	/**
	 * @brief Initializes the DAC device.
	 * @details This function only performs basic configuration; the individual DAC channels 
	 *          are not activated/enabled yet and require separate enabling calls.
	 */
	void initialize(void);

	/**
	 * @brief Enables or disables DAC Channel 1.
	 * 
	 * @param[in] en True to enable the channel, false to disable.
	 */
	void enableChannel1(bool en = true);

	/**
	 * @brief Enables or disables DAC Channel 2.
	 * 
	 * @param[in] en True to enable the channel, false to disable.
	 */
	void enableChannel2(bool en = true);
	
	/**
	 * @brief Sets the output value for DAC Channel 1.
	 * 
	 * @param[in] value The DAC output value (analog level, typically 12-bit).
	 */
	void setOutputChannel1(uint16_t value);

	/**
	 * @brief Sets the output value for DAC Channel 2.
	 * 
	 * @param[in] value The DAC output value (analog level, typically 12-bit).
	 */
	void setOutputChannel2(uint16_t value);

	/**
	 * @struct setup_t
	 * @brief Hardware setup configuration structure for the DAC driver.
	 */
	struct setup_t
	{
		YSS_DAC_Peri *dev; ///< Pointer to the hardware peripheral instance.
	};

	/**
	 * @brief Constructor for the Dac class.
	 * 
	 * @param[in] drvSetup The base driver setup configuration.
	 * @param[in] setup The DAC-specific hardware setup configuration.
	 */
	Dac(const Drv::setup_t drvSetup, const setup_t setup);

private:
	YSS_DAC_Peri *mDev; ///< Pointer to the hardware peripheral instance.
};

#endif


/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_EADC__H_
#define YSS_DRV_NUVOTON_EADC__H_

#include <drv/Adc.h>

/**
 * @file NuvotonEadc.h
 * @brief EADC (Enhanced Analog-to-Digital Converter) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonEadc
 * @brief Driver class for the EADC peripheral on Nuvoton MCUs.
 *
 * @details
 * This class inherits from the base Adc class and provides controls for the Enhanced ADC (EADC)
 * module. It allows initializing channels, configuring software trigger delay parameters, starting/stopping
 * conversions, and handles automatic channel-rotation interrupts.
 *
 * ### Initialization Flow
 * 1. Configure related GPIO pins as analog mode using Gpio's `setAsAnalog()`.
 * 2. Supply clock to the EADC peripheral using `enableClock()`.
 * 3. Initialize driver resources using `initialize()`.
 * 4. Register EADC channels using `add()`.
 * 5. Enable the interrupt for the module using `enableInterrupt()`.
 * 6. Start the conversion process using `convert(true)`.
 *
 * ### Initialization Example
 * @code
 * gpioA.setAsAnalog(4); // Set GPIOA pin 4 to analog mode
 *
 * eadc.enableClock();
 * eadc.initialize(1);  // Reserve space for 1 channel
 * eadc.add(4, Adc::LPF_LV10, Adc::RES_BIT12); // Add EADC channel 4 with LPF level 10 and 12-bit resolution
 * eadc.enableInterrupt();
 * eadc.convert(true);  // Start conversions
 * @endcode
 *
 * ### Retrieving Results
 * - Use `getResult()` at any time to obtain the filtered ADC conversion value.
 * @code
 * int32_t result = eadc.getResult(0); // Retrieve result of channel at index 0
 * @endcode
 */
class NuvotonEadc : public Adc
{
public :
	struct setup_t
	{
		EADC_T *dev;
	};

	NuvotonEadc(const Drv::setup_t drvSetup, const setup_t setup);

	/**
	 * @brief Initializes the EADC device.
	 * @details Allocates internal memory for the specified number of channels.
	 *
	 * @param[in] numOfChannel Number of channels to operate.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(uint8_t numOfChannel);
	
	/**
	 * @brief Registers an input channel with specific LPF level and resolution.
	 *
	 * @param[in] ch EADC hardware channel index (0 to 15).
	 * @param[in] lpflv Low-pass filter level applied to the channel.
	 * @param[in] bit Conversion resolution bits.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t add(uint8_t ch, lpfLv_t lpflv, bit_t bit);

	/**
	 * @brief Configures the conversion start delay for a registered channel.
	 * @details Sets trigger delay divisor (TRGDLYDIV field) and trigger delay count (TRGDLYCNT field)
	 * for the EADC sample control register corresponding to the channel registered at the specified index.
	 * Refer to the MCU hardware datasheet for details on exact delay timing calculations.
	 *
	 * @param[in] index The registered index of the channel (order in which add() was called).
	 * @param[in] div Trigger delay clock divisor factor.
	 * @param[in] count Trigger delay clock count.
	 */
	void setConversionStartDelay(uint8_t index, uint8_t div, uint8_t count);

	/**
	 * @brief Starts or stops the conversion sequence.
	 *
	 * @param[in] en If set to true, triggers continuous conversion; otherwise stops conversions.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t convert(bool en);

	// Internal system interrupt routine. Do not call from user application.
	void isr(void);

private :
	EADC_T *mDev;
	uint32_t mSwTrigger;
};

#endif


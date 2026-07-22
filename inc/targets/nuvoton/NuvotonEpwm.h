/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_EPWM__H_
#define YSS_DRV_EPWM__H_

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <drv/peripheral.h>
#include <drv/Drv.h>
#include <yss/error.h>

/**
 * @file NuvotonEpwm.h
 * @brief EPWM (Enhanced Pulse Width Modulation) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonEpwm
 * @brief Driver class for the EPWM peripheral on Nuvoton MCUs.
 *
 * @details
 * This class provides interface functions to configure and control the Enhanced PWM (EPWM)
 * peripheral. It supports initializing the PWM frequency per channel, starting/stopping
 * channel counters, changing frequency dynamically, setting output compare registers directly
 * or via duty ratio, and configuring channels as inverted or non-inverted PWM outputs.
 */
class NuvotonEpwm : public Drv
{
public:
	/**
	 * @brief Initializes the EPWM channel and sets the output period based on frequency.
	 * @details The actual frequency may deviate slightly depending on the peripheral clock status.
	 *
	 * @param[in] ch The EPWM channel index (0 ~ 5).
	 * @param[in] freq Desired frequency of the PWM output in Hz.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t initialize(uint8_t ch, uint32_t freq) __attribute__((optimize("-O1")));

	/**
	 * @brief Changes the output frequency of the EPWM channel.
	 * @details This function can be called while EPWM is active. Some MCU targets may temporarily
	 * stop the peripheral internally during the update. The actual frequency may deviate slightly
	 * depending on the peripheral clock status.
	 *
	 * @param[in] ch The EPWM channel index (0 ~ 5).
	 * @param[in] freq Desired frequency of the PWM output in Hz.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t changeFrequency(uint8_t ch, uint32_t freq) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the clock frequency of EPWM channels 0 and 1.
	 *
	 * @return uint32_t Clock frequency in Hz.
	 */
	uint32_t getClockFrequency01(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Starts the EPWM counter for the specified channel.
	 *
	 * @param[in] ch The EPWM channel index (0 ~ 5).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t start(uint8_t ch) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Stops the EPWM counter for the specified channel.
	 *
	 * @param[in] ch The EPWM channel index (0 ~ 5).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t stop(uint8_t ch) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the maximum (TOP) value of the EPWM counter for the specified channel.
	 *
	 * @param[in] ch The EPWM channel index (0 ~ 5).
	 * @return uint32_t The TOP value of the PWM counter.
	 */
	uint32_t getTopValue(uint8_t ch) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Sets the duty ratio of the specified EPWM channel.
	 *
	 * @param[in] ch The EPWM channel index (0 ~ 5).
	 * @param[in] ratio The duty ratio to set (0.0 to 1.0).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setDutyRatio(uint8_t ch, float ratio) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Directly sets the compare register value of the specified EPWM channel.
	 * @details Retrieve the maximum counter value using getTopValue() first, and then
	 * use this function to set the raw output compare register value.
	 *
	 * @param[in] ch The EPWM channel index (0 ~ 5).
	 * @param[in] counter The output compare register value to set.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setCompareValue(uint8_t ch, int16_t  counter) __attribute__((optimize("-O1")));

	/**
	 * @brief Configures the specified channel as a standard PWM output.
	 * @details Generates a waveform based on the UP counter: transitions to High at Zero
	 * and transitions to Low at Match.
	 *
	 * @param[in] ch The EPWM channel index (0 ~ 5).
	 * @param[in] inverse If set to true, generates an inverted waveform (transitions to High at Match).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setAsPwmOutput(uint8_t ch, bool inverse = false);

	// Internal system functions. Do not call from user application.
	struct setup_t
	{
		EPWM_T *dev;
		uint32_t (*getClock01Func)(void);
		uint32_t (*getClock23Func)(void);
		uint32_t (*getClock45Func)(void);
	};

	NuvotonEpwm(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

  protected:
	EPWM_T *mDev;
	uint32_t (*mGetClock01Func)(void);
	uint32_t (*mGetClock23Func)(void);
	uint32_t (*mGetClock45Func)(void);
};

/**
 * @example epwm_init_example
 * @code
 * // Initialize EPWM0 channels on GPIO pins:
 * gpioA.setAsAltFunc(5, Gpio::PA5_EPWM0_CH0);
 * gpioA.setAsAltFunc(4, Gpio::PA4_EPWM0_CH1);
 * gpioA.setAsAltFunc(3, Gpio::PA3_EPWM0_CH2);
 * gpioA.setAsAltFunc(2, Gpio::PA2_EPWM0_CH3);
 * gpioA.setAsAltFunc(1, Gpio::PA1_EPWM0_CH4);
 * gpioA.setAsAltFunc(0, Gpio::PA0_EPWM0_CH5);
 *
 * epwm0.enableClock();			// Enable peripheral clock for EPWM0
 *
 * // Initialize CH0
 * epwm0.initialize(0, 1000);		// Initialize EPWM0 CH0 frequency to 1kHz
 * epwm0.setAsPwmOutput(0, true);	// Configure CH0 as inverted PWM output
 * epwm0.start(0);					// Start counter for CH0
 * epwm0.setDutyRatio(0, 0.1f);		// Set duty ratio of CH0 to 10%
 *
 * // Initialize CH1
 * epwm0.initialize(1, 1000);		// Initialize EPWM0 CH1 frequency to 1kHz
 * epwm0.setAsPwmOutput(1);		// Configure CH1 as non-inverted PWM output
 * epwm0.start(1);					// Start counter for CH1
 * epwm0.setDutyRatio(1, 0.2f);		// Set duty ratio of CH1 to 20%
 *
 * // Initialize CH2
 * epwm0.initialize(2, 1000);		// Initialize EPWM0 CH2 frequency to 1kHz
 * epwm0.setAsPwmOutput(2);		// Configure CH2 as non-inverted PWM output
 * epwm0.start(2);					// Start counter for CH2
 * epwm0.setDutyRatio(2, 0.3f);		// Set duty ratio of CH2 to 30%
 *
 * // Initialize CH3
 * epwm0.initialize(3, 1000);		// Initialize EPWM0 CH3 frequency to 1kHz
 * epwm0.setAsPwmOutput(3);		// Configure CH3 as non-inverted PWM output
 * epwm0.start(3);					// Start counter for CH3
 * epwm0.setDutyRatio(3, 0.4f);		// Set duty ratio of CH3 to 40%
 *
 * // Initialize CH4
 * epwm0.initialize(4, 1000);		// Initialize EPWM0 CH4 frequency to 1kHz
 * epwm0.setAsPwmOutput(4);		// Configure CH4 as non-inverted PWM output
 * epwm0.start(4);					// Start counter for CH4
 * epwm0.setDutyRatio(4, 0.5f);		// Set duty ratio of CH4 to 50%
 *
 * // Initialize CH5
 * epwm0.initialize(5, 1000);		// Initialize EPWM0 CH5 frequency to 1kHz
 * epwm0.setAsPwmOutput(5);		// Configure CH5 as non-inverted PWM output
 * epwm0.start(5);					// Start counter for CH5
 * epwm0.setDutyRatio(5, 0.6f);		// Set duty ratio of CH5 to 60%
 * @endcode
 */
#endif

#endif



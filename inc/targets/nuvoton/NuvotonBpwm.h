/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_BPWM__H_
#define YSS_DRV_BPWM__H_

#include <drv/peripheral.h>
#include <drv/Drv.h>
#include <yss/error.h>

/**
 * @file NuvotonBpwm.h
 * @brief BPWM (Basic Pulse Width Modulation) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonBpwm
 * @brief Driver class for the BPWM peripheral on Nuvoton MCUs.
 *
 * @details
 * This class provides interface functions to configure and control the Basic PWM (BPWM)
 * peripheral. It supports initializing the PWM frequency, starting/stopping the timer counter,
 * changing frequency dynamically, setting output compare registers directly or via duty ratio,
 * and configuring channels as inverted or non-inverted PWM outputs.
 */
class NuvotonBpwm : public Drv
{
public:
	/**
	 * @brief Initializes the BPWM device and sets the output period based on frequency.
	 * @details The actual frequency may deviate slightly depending on the peripheral clock status.
	 *
	 * @param[in] freq Desired frequency of the PWM output in Hz.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t initialize(uint32_t freq) __attribute__((optimize("-O1")));

	/**
	 * @brief Changes the output frequency of the BPWM device.
	 * @details This function can be called while BPWM is active. Some MCU targets may temporarily
	 * stop the peripheral internally during the update. The actual frequency may deviate slightly
	 * depending on the peripheral clock status.
	 *
	 * @param[in] freq Desired frequency of the PWM output in Hz.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t changeFrequency(uint32_t freq) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Starts the BPWM counter.
	 */
	void start(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Stops the BPWM counter.
	 */
	void stop(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the maximum (TOP) value of the BPWM counter.
	 *
	 * @return uint32_t The TOP value of the PWM counter.
	 */
	uint32_t getTopValue(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Sets the duty ratio of the specified BPWM channel.
	 *
	 * @param[in] ch The BPWM channel index (0 ~ 5).
	 * @param[in] ratio The duty ratio to set (0.0 to 1.0).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setDutyRatio(uint8_t ch, float ratio) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Directly sets the compare register value of the specified BPWM channel.
	 * @details Retrieve the maximum counter value using getTopValue() first, and then
	 * use this function to set the raw output compare register value.
	 *
	 * @param[in] ch The BPWM channel index (0 ~ 5).
	 * @param[in] counter The output compare register value to set.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setCompareValue(uint8_t ch, int16_t  counter) __attribute__((optimize("-O1")));

	/**
	 * @brief Configures the specified channel as a standard PWM output.
	 * @details Generates a waveform based on the UP counter: transitions to High at Zero
	 * and transitions to Low at Match.
	 *
	 * @param[in] ch The BPWM channel index (0 ~ 5).
	 * @param[in] inverse If set to true, generates an inverted waveform (transitions to High at Match).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setAsPwmOutput(uint8_t ch, bool inverse = false);

	// Internal system functions. Do not call from user application.
	struct setup_t
	{
		BPWM_T *dev;
	};

	NuvotonBpwm(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

protected:
	BPWM_T *mDev;
};

/**
 * @example bpwm_init_example
 * @code
 * // Initialize BPWM0 channels on GPIO pins:
 * gpioA.setAsAltFunc(11, Gpio::PA11_BPWM0_CH0);	// Set PA11 as BPWM0 CH0
 * gpioA.setAsAltFunc(10, Gpio::PA10_BPWM0_CH1);	// Set PA10 as BPWM0 CH1
 * gpioA.setAsAltFunc(9, Gpio::PA9_BPWM0_CH2);		// Set PA9 as BPWM0 CH2
 * gpioA.setAsAltFunc(8, Gpio::PA8_BPWM0_CH3);		// Set PA8 as BPWM0 CH3
 *
 * bpwm0.enableClock();							// Enable peripheral clock for BPWM0
 * bpwm0.initialize(1000);							// Initialize BPWM0 frequency to 1kHz
 * bpwm0.setAsPwmOutput(0, true);					// Configure CH0 as inverted PWM output
 * bpwm0.setAsPwmOutput(1);						// Configure CH1 as non-inverted PWM output
 * bpwm0.setAsPwmOutput(2);						// Configure CH2 as non-inverted PWM output
 * bpwm0.setAsPwmOutput(3);						// Configure CH3 as non-inverted PWM output
 * bpwm0.start();									// Start timer counter
 *
 * bpwm0.setDutyRatio(0, 0.1f);						// Set duty ratio of BPWM0 CH0 to 10%
 * bpwm0.setDutyRatio(1, 0.2f);						// Set duty ratio of BPWM0 CH1 to 20%
 * bpwm0.setDutyRatio(2, 0.3f);						// Set duty ratio of BPWM0 CH2 to 30%
 * bpwm0.setDutyRatio(3, 0.4f);						// Set duty ratio of BPWM0 CH3 to 40%
 * @endcode
 */
#endif



/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_TMR__H_
#define YSS_NUVOTON_DRV_TMR__H_

#include <drv/Timer.h>
#include <yss/error.h>

/**
 * @file NuvotonTmr.h
 * @brief TMR (Timer) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonTmr
 * @brief Driver class for the basic Timer (TMR) peripheral on Nuvoton MCUs.
 *
 * @details
 * This class inherits from the base Timer class. It provides functions to initialize the timer,
 * configure it for periodic or one-shot (one-pulse) mode, start/stop the counter, modify the operating
 * frequency dynamically, and read the raw counter register.
 */
class NuvotonTmr : public Timer
{
public:
	/**
	 * @brief Initializes the timer with a desired frequency.
	 *
	 * @param[in] freq Desired frequency in Hz.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(uint32_t freq) __attribute__((optimize("-O1")));

	/**
	 * @brief Sets the timer to operate in one-pulse (one-shot) mode or continuous mode.
	 * @note Must be called after initialize(). Calling this before initialize() will be ignored
	 * because initialize() resets mode registers.
	 *
	 * @param[in] en If set to true, sets the timer to one-pulse mode. If false, sets to continuous mode (default after init).
	 */
	virtual void setOnePulse(bool en) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Starts the timer counter.
	 */
	virtual void start(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Stops the timer counter.
	 */
	virtual void stop(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Changes the operating frequency of the timer dynamically.
	 * @details This function can be called while the timer is running. Some MCUs might briefly stop
	 * the peripheral internally. The actual frequency may deviate depending on peripheral clock speed.
	 *
	 * @param[in] freq Desired frequency in Hz.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t changeFrequency(uint32_t freq) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the current timer counter value.
	 *
	 * @return uint32_t The current counter value.
	 */
	virtual uint32_t getCounterValue(void) __attribute__((optimize("-O1")));

	// Internal system configurations. Do not call from user application.
	struct setup_t
	{
		TIMER_T *dev;
	};

	NuvotonTmr(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

private :
	TIMER_T *mDev;
};

#endif



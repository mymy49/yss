/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Timer.h
 * @brief Basic timer driver class header file.
 */

#ifndef YSS_DRV_TIMER__H_
#define YSS_DRV_TIMER__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @class Timer
 * @brief Driver class for basic timer peripherals.
 * 
 * @details
 * This driver supports basic timer features. Enhanced or specialized timers are typically 
 * implemented in separate driver classes, unless their register maps are compatible with 
 * this basic timer interface.
 */
class Timer : public Drv
{
public:
	Timer(const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	/**
	 * @brief Initializes the timer based on the target frequency.
	 * @details The frequency may not be exact depending on the timer's input clock resolution.
	 * 
	 * @param[in] freq Operation frequency in Hz.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t initialize(uint32_t freq) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Registers the interrupt service routine (ISR) callback function for timer update events.
	 * @details Calling functions that cause context switching inside this ISR is strictly prohibited.
	 *          Please refer to the explanation of functions that cause context switching in yss.h,
	 *          as well as the distinction between ISR functions and Callback functions.
	 * 
	 * @param[in] isr Pointer to the callback function.
	 */
	void setIsrForUpdate(void (*isr)(void)) __attribute__((optimize("-O1")));

	/**
	 * @brief Sets the timer to run in one-pulse mode (stops after one cycle).
	 * @details Must be called after initialize(), otherwise the settings may be overwritten/ignored.
	 *          Default state is false.
	 * 
	 * @param[in] en If true, the timer runs once. If false, the timer runs continuously.
	 */
	virtual void setOnePulse(bool en) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Starts the timer counter.
	 */
	virtual void start(void) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Stops the timer counter.
	 */
	virtual void stop(void) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Changes the timer operating frequency.
	 * @details Frequency can be updated on-the-fly. On some MCUs, the driver may temporarily stop the peripheral internally.
	 *          Actual output frequency accuracy depends on the timer clock status.
	 * 
	 * @param[in] freq Target frequency in Hz.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t changeFrequency(uint32_t freq) __attribute__((optimize("-O1"))) = 0;

	virtual uint32_t getCounterValue(void) __attribute__((optimize("-O1"))) = 0;

	void isrUpdate(void) __attribute__((optimize("-O1")));

protected :
	void (*mIsrUpdate)(void);
};

#endif


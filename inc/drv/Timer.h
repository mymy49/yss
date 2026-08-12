/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_TIMER__H_
#define YSS_DRV_TIMER__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @file Timer.h
 * @brief Basic timer driver class header file.
 *
 * ### Initialization Flow
 * 1. Supply clock to the Timer peripheral using `enableClock()`.
 * 2. Initialize the Timer driver setting the frequency using `initialize()`.
 * 3. Register the ISR callback function for timer updates using `setIsrForUpdate()`.
 * 4. Enable the NVIC interrupts using `enableInterrupt()`.
 * 5. Start the timer counter using `start()`.
 *
 * ### Initialization Example
 * @code
 * // Register a callback function
 * void onTimerUpdate(void)
 * {
 *     // Perform fast ISR actions here (do not trigger context switch)
 * }
 * 
 * timer2.enableClock();             // Enable peripheral clock
 * timer2.initialize(1000);          // Initialize timer at 1 kHz (1ms interval)
 * timer2.setIsrForUpdate(onTimerUpdate); // Set callback
 * timer2.enableInterrupt();         // Enable NVIC interrupt
 * timer2.start();                   // Start counter
 * @endcode
 *
 * ### Guidelines for ISR Callback Functions
 * - The registered callback functions are executed inside the actual hardware Interrupt Service Routine context.
 * - **CRITICAL WARNING**: It is strictly forbidden to call any scheduler-blocking or context-switching operations (e.g. `thread::yield()`, `Mutex::lock()`, etc.) inside the ISR update callback. Doing so will lead to hardware faults. Refer to `yss.h` for details on functions that trigger context switches.
 *
 * ### Frequency Configuration and Accuracy
 * - The peripheral clock divider is calculated automatically during `initialize()` or `changeFrequency()`.
 * - The actual frequency might deviate slightly depending on the peripheral clock source resolution.
 */

/**
 * @class Timer
 * @brief Driver class for basic timer peripherals.
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

	/**
	 * @brief Gets the current value of the hardware timer counter register.
	 *
	 * @details
	 * Returns the raw counter register value at the time of the call.
	 * This can be used to implement elapsed-time measurement at a finer
	 * granularity than the update interrupt period, or for debugging.
	 *
	 * @return uint32_t The current hardware timer counter value.
	 */
	virtual uint32_t getCounterValue(void) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Internal ISR handler called by the hardware timer update interrupt.
	 *
	 * @details
	 * Invokes the registered `mIsrUpdate` callback function.
	 * This function is called from the hardware interrupt vector and must NOT
	 * be called directly by user application code.
	 */
	void isrUpdate(void) __attribute__((optimize("-O1")));

protected :
	void (*mIsrUpdate)(void);
};

#endif


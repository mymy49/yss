/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_TIMER_NRF52__H_
#define YSS_CLASS_TIMER_NRF52__H_

#include <drv/Timer.h>
#include <yss/error.h>

class nRF52_Timer : public Timer
{
public:
	/**
	 * @brief Initializes the timer based on the target frequency.
	 * @details The frequency may not be exact depending on the timer's input clock resolution.
	 * 
	 * @param[in] freq Operation frequency in Hz.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t initialize(uint32_t freq) override;

	/**
	 * @brief Sets the timer to run in one-pulse mode (stops after one cycle).
	 * @details Must be called after initialize(), otherwise the settings may be overwritten/ignored.
	 *          Default state is false.
	 * 
	 * @param[in] en If true, the timer runs once. If false, the timer runs continuously.
	 */
	virtual void setOnePulse(bool en) override;
	
	/**
	 * @brief Starts the timer counter.
	 */
	virtual void start(void) override;
	
	/**
	 * @brief Stops the timer counter.
	 */
	virtual void stop(void) override;
	
	/**
	 * @brief Changes the timer operating frequency.
	 * @details Frequency can be updated on-the-fly. On some MCUs, the driver may temporarily stop the peripheral internally.
	 *          Actual output frequency accuracy depends on the timer clock status.
	 * 
	 * @param[in] freq Target frequency in Hz.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t changeFrequency(uint32_t freq);

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
	virtual uint32_t getCounterValue(void);

	struct setup_t
	{
		NRF_TIMER_Type *dev;
	};

	nRF52_Timer(const Drv::setup_t drvSetup, const setup_t setup);

protected :
	NRF_TIMER_Type *mDev;

	void (*mIsrUpdate)(void);
};

#endif


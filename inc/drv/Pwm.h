/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_PWM__H_
#define YSS_DRV_PWM__H_

#include "peripheral.h"

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F7) || defined(STM32F4) || defined(STM32G4)

typedef TIM_TypeDef			YSS_PWM_Peri;

#elif defined(W7500)

typedef PWM_TypeDef			YSS_PWM_Peri;

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

typedef TIMER_T				YSS_PWM_Peri;

#else

#define YSS_DRV_PWM_UNSUPPORTED

#endif

#ifndef YSS_DRV_PWM_UNSUPPORTED

#include "Drv.h"
#include <yss/error.h>

/**
 * @file Pwm.h
 * @brief Pulse Width Modulation (PWM) driver class header file.
 *
 * ### Initialization Flow
 * 1. Configure the GPIO pins related to the PWM channels (CH1 to CH4) as alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the Timer/PWM peripheral using `enableClock()`.
 * 3. Initialize the PWM driver using the frequency-based `initialize()` or PSC/TOP-based `initialize()`.
 * 4. Initialize target channel output mode (e.g. rising-at-match or standard) using `initializeChannel()`.
 * 5. Start the counter using `start()`.
 *
 * ### Initialization Example
 * @code
 * // Configure GPIO PA0 to PWM alternative function
 * gpioA.setAsAltFunc(0, Gpio::PA0_TIM2_CH1);
 * 
 * pwm2.enableClock(); // Supply clock
 * 
 * // Initialize PWM frequency at 20 kHz
 * pwm2.initialize(20000); 
 * 
 * // Initialize Channel 1 output mode (e.g. standard duty control)
 * pwmCh1.initializeChannel(false);
 * 
 * // Set duty ratio to 50%
 * pwmCh1.setDutyRatio(0.5f);
 * 
 * pwm2.start(); // Start counter
 * @endcode
 *
 * ### Duty Cycle and TOP value
 * - The PWM duty cycle can be set in two ways:
 *   1. Qualitatively: `setDutyRatio()` using a float range from `0.0f` to `1.0f`.
 *   2. Quantitatively: `setCompareValue()` using an integer tick count. First call `getTopValue()` to retrieve the counter maximum value (TOP) corresponding to the configured frequency.
 */

/**
 * @class Pwm
 * @brief Driver class for PWM (Pulse Width Modulation) peripherals using MCU timers.
 */
class Pwm : public Drv
{
public:
	/**
	 * @brief Initializes the PWM output cycle based on frequency.
	 * @details The frequency may not be exact depending on the timer's input clock resolution.
	 * 
	 * @param[in] freq PWM output frequency in Hz.
	 * @param[in] risingAtMatch Output waveform configuration. If false, output remains High when the counter is less than the compare value.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t initialize(uint32_t freq, bool risingAtMatch = false) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Initializes the PWM using prescaler (PSC) and counter TOP value directly.
	 * 
	 * @param[in] psc Prescaler value.
	 * @param[in] top Timer counter TOP value.
	 * @param[in] risingAtMatch Output waveform configuration.
	 * @return error_t Returns ERROR_NONE on success.
	 * 
	 * @note Range limitations:
	 *       - STM32: psc (0 ~ 65535), top (maximum bit value of the timer).
	 *       - Wiznet W7500x: psc (0 ~ 63), top (0x00000000 ~ 0xFFFFFFFF).
	 *       - Nuvoton M4xx: psc (0 ~ 255), top (0x000000 ~ 0xFFFFFF).
	 */
	error_t initialize(uint32_t psc, uint32_t top, bool risingAtMatch = false) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Changes the PWM output frequency.
	 * @details Frequency can be updated on-the-fly. On some MCUs, the driver may temporarily stop the peripheral internally.
	 *          Actual output frequency accuracy depends on the timer clock status.
	 * 
	 * @param[in] freq Target PWM frequency in Hz.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t changeFrequency(uint32_t freq) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Sets the PWM to produce a single pulse (One-Pulse Mode).
	 * @details Must be called after initialize(), otherwise the settings may be overwritten/ignored.
	 *          Default state is false.
	 * 
	 * @param[in] en If true, configures the timer to run once. If false, configures it to run continuously.
	 */
	void setOnePulse(bool en) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Starts the PWM counter.
	 */
	void start(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Stops the PWM counter.
	 */
	void stop(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the current TOP value of the PWM counter.
	 * 
	 * @return uint32_t The TOP value.
	 */
	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1"))) = 0;
	
	/**	
	 * @brief Sets the PWM duty ratio.
	 * 
	 * @param[in] ratio Duty ratio (0.0 to 1.0).
	 */
	virtual void setDutyRatio(float ratio) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Sets the compare register value directly to change the duty cycle.
	 * @details First call getTopValue() to obtain the maximum range, then set the compare register value directly.
	 * 
	 * @param[in] counter The comparison counter value.
	 */
	virtual void setCompareValue(int32_t  counter) __attribute__((optimize("-O1"))) = 0 ;

	// The following are internal functions and do not need to be called by the user application.
	struct setup_t
	{
		YSS_PWM_Peri *dev;
#if defined(STM32F1) || defined(STM32F4) || defined(STM32F7) || defined(STM32G4) || defined(STM32F0)
		uint8_t bit;
#endif
#if defined(W7500)
		uint8_t index;
#endif
	};

	/**
	 * @brief Constructor for the Pwm class (legacy: using peripheral pointer directly).
	 */
	Pwm(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	/**
	 * @brief Constructor for the Pwm class (using setup_t configuration structure).
	 */
	Pwm(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

  protected:
	YSS_PWM_Peri *mDev; ///< Pointer to the hardware timer peripheral register block.

#if defined(W7500)
	uint8_t mIndex;       ///< W7500-specific PWM channel index.
	bool mRisingAtMatch;  ///< W7500-specific output polarity flag.
#endif

	/**
	 * @brief Initializes the hardware output channel.
	 *
	 * @details
	 * Target-specific implementation that configures the timer output compare
	 * register and output mode for the channel. Called internally by `initialize()`.
	 *
	 * @param[in] risingAtMatch Output waveform polarity. See `initialize()` for details.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t initializeChannel(bool risingAtMatch = false) __attribute__((optimize("-O1"))) = 0;
};

/**
 * @class PwmCh1
 * @brief PWM Channel 1 driver class.
 *
 * @details
 * Controls the Compare/Capture Channel 1 output of the shared timer peripheral.
 * Inherits all frequency and counter management functions from `Pwm`.
 * Use `initializeChannel()` to configure the output mode, and `setDutyRatio()`
 * or `setCompareValue()` to control the duty cycle independently of other channels.
 */
class PwmCh1 : public Pwm
{
  public:
	error_t initializeChannel(bool risingAtMatch = false) __attribute__((optimize("-O1")));

	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1")));

	virtual void setDutyRatio(float ratio) __attribute__((optimize("-O1")));

	virtual void setCompareValue(int32_t  counter) __attribute__((optimize("-O1")));

	PwmCh1(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	PwmCh1(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1"))) __attribute__((optimize("-O1")));
};

class PwmCh2 : public Pwm
{
  public:
	error_t initializeChannel(bool risingAtMatch = false) __attribute__((optimize("-O1")));

	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1")));

	virtual void setDutyRatio(float ratio) __attribute__((optimize("-O1")));

	virtual void setCompareValue(int32_t  counter) __attribute__((optimize("-O1")));

	PwmCh2(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	PwmCh2(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));
};

/**
 * @class PwmCh2
 * @brief PWM Channel 2 driver class.
 *
 * @details
 * Controls the Compare/Capture Channel 2 output of the shared timer peripheral.
 * Inherits all frequency and counter management functions from `Pwm`.
 * Use `initializeChannel()` to configure the output mode, and `setDutyRatio()`
 * or `setCompareValue()` to control the duty cycle independently of other channels.
 */
class PwmCh3 : public Pwm
{
  public:
	error_t initializeChannel(bool risingAtMatch = false) __attribute__((optimize("-O1")));

	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1")));

	virtual void setDutyRatio(float ratio) __attribute__((optimize("-O1")));

	virtual void setCompareValue(int32_t  counter) __attribute__((optimize("-O1")));

	PwmCh3(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	PwmCh3(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));
};

/**
 * @class PwmCh4
 * @brief PWM Channel 4 driver class.
 *
 * @details
 * Controls the Compare/Capture Channel 4 output of the shared timer peripheral.
 * Inherits all frequency and counter management functions from `Pwm`.
 * Use `initializeChannel()` to configure the output mode, and `setDutyRatio()`
 * or `setCompareValue()` to control the duty cycle independently of other channels.
 */
class PwmCh4 : public Pwm
{
  public:
	error_t initializeChannel(bool risingAtMatch = false) __attribute__((optimize("-O1")));

	virtual uint32_t getTopValue(void) __attribute__((optimize("-O1")));

	virtual void setDutyRatio(float ratio) __attribute__((optimize("-O1")));

	virtual void setCompareValue(int32_t  counter) __attribute__((optimize("-O1")));

	PwmCh4(YSS_PWM_Peri *peri, const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	PwmCh4(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));
};

#endif

#endif


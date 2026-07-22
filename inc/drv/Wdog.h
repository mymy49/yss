/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_WDOG__H_
#define YSS_DRV_WDOG__H_

#include "peripheral.h"

#if defined(STM32F0)

typedef IWDG_TypeDef		YSS_WDOG_peri;

#else

typedef void WDOG_peri;
#define YSS_DRV_WDOG_UNSUPPORTED

#endif

#ifndef YSS_DRV_WDOG_UNSUPPORTED

#include "Drv.h"
#include <yss/error.h>

/**
 * @file Wdog.h
 * @brief Watchdog timer driver class header file.
 *
 * ### Initialization Flow
 * 1. Initialize the Watchdog timer specifying target prescaler division and reload count using `initialize()`.
 * 2. Start the Watchdog (the timer starts counting down automatically upon initialization).
 *
 * ### Initialization Example
 * @code
 * // Initialize Watchdog (prescaler divide by 64, reload value 1000)
 * wdog.initialize(4, 1000); 
 * @endcode
 *
 * ### Feeding/Updating the Watchdog
 * - Call `update()` periodically inside the main execution loop or a watchdog thread to reload the counter and prevent the system from resetting.
 *
 * ### Feeding Example
 * @code
 * while(true)
 * {
 *     // Perform main execution cycle
 *     
 *     wdog.update(); // Feed the watchdog
 *     thread::yield();
 * }
 * @endcode
 */

/**
 * @class Wdog
 * @brief Watchdog timer (WDOG) driver class.
 */
class Wdog : public Drv
{
public:
	/**
	 * @brief Initializes the Watchdog timer.
	 * 
	 * @param[in] prescale Prescaler divider value.
	 * @param[in] reload Reload counter value.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t initialize(uint8_t prescale, uint16_t reload);

	/**
	 * @brief Reloads/feeds the Watchdog timer to prevent reset.
	 */
	void update(void);

	// The following are internal functions and do not need to be called by the user application.
	struct Config
	{
		YSS_WDOG_peri *dev;
	};

	Wdog(const Drv::setup_t drvConfig, const Config config);

private:
	YSS_WDOG_peri *mPeri;
	uint16_t mReload;
};

#endif

#endif

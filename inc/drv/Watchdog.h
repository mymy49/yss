/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_WATCHDOG__H_
#define YSS_DRV_WATCHDOG__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @file Watchdog.h
 * @brief Watchdog Timer (WDT) driver base class header file.
 *
 * ### Overview
 * This file defines the abstract base class for Watchdog Timer drivers in the
 * YSS framework. A watchdog timer is a hardware safety mechanism that resets
 * the system if the software fails to periodically "feed" (reload) it within
 * a configured timeout interval.
 *
 * ### Initialization Flow
 * 1. Enable the watchdog peripheral clock using the `enableClock()` function.
 * 2. Initialize the watchdog with the desired timeout interval using the
 *    target-specific `initialize()` function (e.g., `NuvotonWdt::initialize()`).
 * 3. Periodically call `update()` within the application's main loop or a
 *    dedicated thread to prevent a system reset.
 *
 * ### Initialization Example
 * @code
 * wdt.enableClock();
 * wdt.initialize(NuvotonWdt::INTERVAL_1p638_Sec); // 1.638 second timeout
 * @endcode
 *
 * ### Feeding the Watchdog
 * - Call `update()` periodically at an interval shorter than the configured
 *   timeout to prevent the watchdog from triggering a system reset.
 *
 * ### Usage Example
 * @code
 * while (true)
 * {
 *     wdt.update(); // Feed the watchdog
 *     // ... application logic ...
 * }
 * @endcode
 *
 * ### Hardware/Driver Implementation Details
 * - This class is an abstract base; the actual hardware access is implemented
 *   in the target-specific derived class (e.g., `NuvotonWdt`).
 * - `isWorking()` can be used to verify the watchdog is active before relying
 *   on it for system safety.
 */

/**
 * @class Watchdog
 * @brief Abstract base class for Watchdog Timer (WDT) peripheral drivers.
 *
 * @details
 * This class provides the abstract interface for watchdog timer drivers.
 * Derived classes implement the target-specific hardware access logic.
 * The watchdog timer monitors system health and forces a system reset if the
 * software fails to call `update()` within the configured timeout period.
 */
class Watchdog : public Drv
{
public:
	/**
	 * @brief Reloads (feeds) the watchdog timer counter to prevent a system reset.
	 * @details This function must be called periodically, at an interval shorter
	 * than the configured watchdog timeout period. Failure to do so will cause
	 * the watchdog to trigger a system reset. The specific reload mechanism is
	 * implemented by the target-specific derived class.
	 */
	virtual void update() = 0;

	/**
	 * @brief Checks whether the watchdog timer is currently active and running.
	 *
	 * @return bool Returns `true` if the watchdog is enabled and running,
	 *              `false` otherwise.
	 */
	virtual bool isWorking() = 0;

	/**
	 * @brief Constructor for the Watchdog base class.
	 *
	 * @param[in] drvConfig The base driver setup configuration structure,
	 *                      containing clock, interrupt, and reset function pointers.
	 */
	Watchdog(const Drv::setup_t drvConfig);

private:
};

#endif

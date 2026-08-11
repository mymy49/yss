/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_WDT__H_
#define YSS_NUVOTON_DRV_WDT__H_

#include <drv/Watchdog.h>

/**
 * @file NuvotonWdt.h
 * @brief Nuvoton target-specific Watchdog Timer (WDT) driver class header file.
 *
 * ### Overview
 * This file defines the `NuvotonWdt` class, which implements the `Watchdog`
 * abstract interface for Nuvoton MCU families (M480, M4xx, M25x). It provides
 * hardware-specific initialization, watchdog feeding, and status checking for
 * the Nuvoton WDT peripheral.
 *
 * ### Initialization Flow
 * 1. Enable the WDT peripheral clock using the `enableClock()` function.
 * 2. Enable the WDT interrupt using the `enableInterrupt()` function if ISR
 *    handling is needed.
 * 3. Initialize the watchdog with the desired timeout interval using
 *    `initialize()`. The default interval is `INTERVAL_26p214_Sec`.
 * 4. Periodically call `update()` to prevent a system reset.
 *
 * ### Initialization Example
 * @code
 * wdt.enableClock();
 * wdt.initialize(NuvotonWdt::INTERVAL_1p638_Sec); // Set ~1.6 second timeout
 * @endcode
 *
 * ### Feeding the Watchdog
 * - Call `update()` at regular intervals, shorter than the configured timeout,
 *   to reload the hardware counter and prevent a reset.
 *
 * ### Usage Example
 * @code
 * while (true)
 * {
 *     wdt.update(); // Feed the watchdog to prevent reset
 *     // ... application tasks ...
 * }
 * @endcode
 *
 * ### Hardware/Driver Implementation Details
 * - The `initialize()` function performs the Nuvoton register unlock sequence
 *   before writing to protected WDT control registers, and re-locks them
 *   afterward.
 * - The `update()` function writes the magic value `0x00005AA5` to the
 *   WDT RSTCNT register to reload the counter, as required by the hardware.
 * - Both the WDT enable bit (`WDTEN`) and the reset enable bit (`RSTEN`) must
 *   be set for the watchdog to trigger a system reset on timeout.
 * - `isWorking()` verifies both `WDTEN` and `RSTEN` bits are set.
 */

/**
 * @class NuvotonWdt
 * @brief Nuvoton-specific Watchdog Timer driver class.
 *
 * @details
 * This class implements the `Watchdog` abstract interface for Nuvoton MCU
 * families (M480, M4xx, M25x series). It manages the Nuvoton WDT hardware
 * peripheral, including initialization with a configurable timeout interval,
 * periodic counter reload (feeding), and status checking.
 */
class NuvotonWdt : public Watchdog
{
public:
	/**
	 * @brief Enumeration for the WDT timeout interval selection.
	 * @details Defines the available watchdog timeout periods. The actual
	 * time values are derived from the WDT clock source (typically the
	 * internal LIRC at ~10 kHz).
	 */
	typedef enum
	{
		INTERVAL_0p4_mSec   = 0, ///< Timeout interval: approximately 0.4 ms
		INTERVAL_1p6_mSec,       ///< Timeout interval: approximately 1.6 ms
		INTERVAL_6p4_mSec,       ///< Timeout interval: approximately 6.4 ms
		INTERVAL_25p6_mSec,      ///< Timeout interval: approximately 25.6 ms
		INTERVAL_102p4_mSec,     ///< Timeout interval: approximately 102.4 ms
		INTERVAL_409p6_mSec,     ///< Timeout interval: approximately 409.6 ms
		INTERVAL_1p638_Sec,      ///< Timeout interval: approximately 1.638 seconds
		INTERVAL_6p553_Sec,      ///< Timeout interval: approximately 6.553 seconds
		INTERVAL_26p214_Sec,     ///< Timeout interval: approximately 26.214 seconds (default)
	}interval_t;

	/**
	 * @brief Initializes the Nuvoton WDT hardware peripheral.
	 * @details Unlocks the Nuvoton system register protection, sets the
	 * watchdog timeout interval, enables the WDT and its reset function,
	 * and then re-locks the register protection. Must be called before
	 * the first call to `update()`.
	 *
	 * @param[in] interval The timeout interval selection. Defaults to
	 *                     `INTERVAL_26p214_Sec` (~26 seconds) if not specified.
	 * @return error_t Returns `ERROR_NONE` on success.
	 */
	error_t initialize(interval_t interval = INTERVAL_26p214_Sec) __attribute__((optimize("-O1")));

	/**
	 * @brief Reloads (feeds) the watchdog counter to prevent a system reset.
	 * @details Writes the hardware-required magic value (`0x00005AA5`) to
	 * the WDT RSTCNT register to restart the timeout counter.
	 */
	virtual void update() override;

	/**
	 * @brief Checks whether the watchdog timer is currently active.
	 * @details Verifies that both the WDT enable bit (`WDTEN`) and the
	 * reset enable bit (`RSTEN`) are set in the WDT control register.
	 *
	 * @return bool Returns `true` if the WDT is enabled and the reset
	 *              function is active, `false` otherwise.
	 */
	virtual bool isWorking() override;

	/**
	 * @brief WDT interrupt service routine handler.
	 * @details Called from the WDT IRQ handler. Override this behavior
	 * in the application if custom WDT interrupt handling is needed.
	 */
	void isr();

	/**
	 * @brief Setup structure for the NuvotonWdt driver.
	 * @details Contains the hardware-specific configuration required to
	 * initialize the NuvotonWdt instance.
	 */
	struct setup_t
	{
		WDT_T *dev; ///< Pointer to the Nuvoton WDT hardware register structure.
	};

	/**
	 * @brief Constructor for the NuvotonWdt driver.
	 *
	 * @param[in] drvSetup The base driver setup configuration, containing
	 *                     clock, interrupt, and reset function pointers.
	 * @param[in] setup    The Nuvoton WDT-specific setup structure containing
	 *                     the pointer to the WDT hardware register block.
	 */
	NuvotonWdt(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

protected:
	WDT_T *mDev; ///< Pointer to the Nuvoton WDT hardware register structure.
};

#endif

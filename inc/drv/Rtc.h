/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Rtc.h
 * @brief Real-Time Clock (RTC) driver class header file.
 *
 * @details
 * This file provides the driver class for the on-chip Real-Time Clock (RTC)
 * peripheral. The RTC maintains a calendar and/or a free-running counter
 * backed by a low-power clock source (typically the 32.768 kHz LSE crystal
 * or the internal LSI oscillator), allowing it to continue operating even
 * when the main MCU power domain is in low-power or standby mode.
 *
 * ### Supported Targets
 * - STM32F4, STM32F7, STM32G4, STM32L0 — calendar (year/month/day/hour/
 *   min/sec) and subsecond register support.
 *
 * Currently the driver is conditionally disabled (`#if false`). To enable it
 * for a supported target, update the preprocessor condition in this file and
 * configure the appropriate clock source in the system clock initialization.
 *
 * ### Initialization Flow (when enabled)
 * 1. Select and enable the RTC clock source (LSE or LSI) via the Clock driver.
 * 2. Call `init()` passing the clock source and frequency.
 * 3. Optionally set the initial calendar values using `setYear()`,
 *    `setMonth()`, etc.
 * 4. Call `refresh()` periodically if polling-based calendar reads are needed.
 *
 * ### Calendar Read Example
 * @code
 * rtc.init(RTC_LSE, 32768); // Use 32.768 kHz LSE crystal
 *
 * uint8_t year  = rtc.getYear();
 * uint8_t month = rtc.getMonth();
 * uint8_t day   = rtc.getDay();
 * uint8_t hour  = rtc.getHour();
 * uint8_t min   = rtc.getMin();
 * uint8_t sec   = rtc.getSec();
 * @endcode
 */

#ifndef YSS_DRV_RTC__H_
#define YSS_DRV_RTC__H_

#include "mcu.h" ///< MCU target selection and macro definitions

#if false

#define USE_RTC_INTERFACE

typedef volatile uint32_t		YSS_RTC_Peri; ///< Hardware RTC peripheral register type

#include "rtc/define_rtc_stm32f4_f7_g4.h"

#else

#define YSS_DRV_RTC_UNSUPPORTED ///< Defined when the RTC driver is not enabled for the current build

#endif

#ifndef YSS_DRV_RTC_UNSUPPORTED

#include "Drv.h"              ///< Base driver class (clock, NVIC, reset management)
#include <sac/RtcCalendar.h>  ///< RTC calendar interface abstraction class

#if defined(USE_CALENDAR)
class Rtc : public Drv, public sac::RtcCalendar
#elif defined(USE_RTC_INTERFACE)
class Rtc : public Drv, public sac::Rtc
#else
/**
 * @class Rtc
 * @brief Driver class for the Real-Time Clock (RTC) peripheral.
 *
 * @details
 * Provides access to the hardware RTC for timekeeping with or without
 * full calendar functionality, depending on the target MCU and the
 * selected interface class (`sac::RtcCalendar` or `sac::Rtc`).
 *
 * On STM32F4/F7/G4 targets the RTC hardware directly maintains BCD-coded
 * year, month, day, weekday, hour, minute, second, and sub-second registers.
 * These are accessible through the get/set family of functions below.
 *
 * The RTC peripheral is write-protected by hardware; `unprotect()` and
 * `protect()` are called internally around register writes.
 */
class Rtc : public Drv
#endif
{
	YSS_RTC_Peri *mPeri; ///< Pointer to the hardware RTC peripheral register block.

	/**
	 * @brief Removes the hardware write protection from the RTC registers.
	 * @details Called internally before writing to calendar or counter registers.
	 */
	void unprotect(void);

	/**
	 * @brief Re-applies the hardware write protection to the RTC registers.
	 * @details Called internally after writing to calendar or counter registers.
	 */
	void protect(void);

  public:
	/**
	 * @brief Constructor for the Rtc class.
	 *
	 * @param[in] peri        Pointer to the hardware RTC peripheral register block.
	 * @param[in] clockFunc   Function pointer to enable/disable the RTC peripheral clock.
	 * @param[in] nvicFunc    Function pointer to enable/disable the RTC NVIC interrupt.
	 * @param[in] resetFunc   Function pointer to reset the RTC peripheral hardware.
	 */
	Rtc(YSS_RTC_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void));

	/**
	 * @brief Initializes and starts the RTC peripheral.
	 *
	 * @details
	 * Configures the RTC clock source, prescaler, and optional LSE drive
	 * strength, then starts the RTC counter. Must be called before any
	 * calendar or counter access functions.
	 *
	 * @param[in] src      RTC clock source selector (target-specific define).
	 * @param[in] freq     Frequency of the selected clock source in Hz (e.g. 32768).
	 * @param[in] lseDrive LSE oscillator drive strength (0 = lowest, 3 = highest).
	 *                     Only applicable when LSE is selected as the clock source.
	 * @return bool        Returns true on success, false on initialization failure.
	 */
	bool init(uint8_t src, uint32_t freq, uint8_t lseDrive = 0);

	/**
	 * @brief Refreshes the internally cached calendar values from hardware registers.
	 *
	 * @details
	 * On some targets, reading the RTC calendar registers requires a specific
	 * shadowing procedure. Call this function before reading calendar fields
	 * if polling-based access is used.
	 */
	void refresh(void);

	/**
	 * @brief Gets the current RTC free-running counter value.
	 *
	 * @return uint32_t The 32-bit RTC counter value.
	 */
	uint32_t getCounter(void);

	/**
	 * @brief Sets the RTC free-running counter to the specified value.
	 *
	 * @param[in] cnt The counter value to set.
	 * @return bool   Returns true on success.
	 */
	bool setCounter(uint32_t cnt);

#if defined(STM32F7) || defined(STM32F4) || defined(STM32L0) || defined(STM32G4)
	/**
	 * @brief Gets the current year from the RTC calendar (BCD format, 0–99).
	 * @return uint8_t Two-digit year value (e.g. 24 for 2024).
	 */
	uint8_t getYear(void);

	/**
	 * @brief Sets the year in the RTC calendar.
	 * @param[in] year Two-digit year value (0–99).
	 * @return bool    Returns true on success.
	 */
	bool setYear(uint8_t year);

	/**
	 * @brief Gets the current month from the RTC calendar (1–12).
	 * @return uint8_t Month value.
	 */
	uint8_t getMonth(void);

	/**
	 * @brief Sets the month in the RTC calendar.
	 * @param[in] month Month value (1–12).
	 * @return bool     Returns true on success.
	 */
	bool setMonth(uint8_t month);

	/**
	 * @brief Gets the current day of the month from the RTC calendar (1–31).
	 * @return uint8_t Day value.
	 */
	uint8_t getDay(void);

	/**
	 * @brief Sets the day of the month in the RTC calendar.
	 * @param[in] day Day value (1–31).
	 * @return bool   Returns true on success.
	 */
	bool setDay(uint8_t day);

	/**
	 * @brief Gets the current weekday from the RTC calendar.
	 * @return uint8_t Weekday value (1 = Monday … 7 = Sunday, hardware-dependent).
	 */
	uint8_t getWeekDay(void);

	/**
	 * @brief Sets the weekday in the RTC calendar.
	 * @param[in] weekDay Weekday value.
	 * @return bool       Returns true on success.
	 */
	bool setWeekDay(uint8_t weekDay);

	/**
	 * @brief Gets the current hour from the RTC calendar (0–23).
	 * @return uint8_t Hour value in 24-hour format.
	 */
	uint8_t getHour(void);

	/**
	 * @brief Sets the hour in the RTC calendar.
	 * @param[in] hour Hour value (0–23).
	 * @return bool    Returns true on success.
	 */
	bool setHour(uint8_t hour);

	/**
	 * @brief Gets the current minute from the RTC calendar (0–59).
	 * @return uint8_t Minute value.
	 */
	uint8_t getMin(void);

	/**
	 * @brief Sets the minute in the RTC calendar.
	 * @param[in] min Minute value (0–59).
	 * @return bool   Returns true on success.
	 */
	bool setMin(uint8_t min);

	/**
	 * @brief Gets the current second from the RTC calendar (0–59).
	 * @return uint8_t Second value.
	 */
	uint8_t getSec(void);

	/**
	 * @brief Sets the second in the RTC calendar.
	 * @param[in] min Second value (0–59).
	 * @return bool   Returns true on success.
	 */
	bool setSec(uint8_t min);

	/**
	 * @brief Gets the sub-second fractional value from the RTC register.
	 *
	 * @details
	 * Returns the raw sub-second countdown register value. The resolution
	 * depends on the RTC input clock frequency and the configured prescaler.
	 *
	 * @return uint16_t Raw sub-second register value.
	 */
	uint16_t getSubsec(void);
#endif
};

#endif

#endif


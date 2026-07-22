/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_PERIOD__H_
#define YSS_UTIL_PERIOD__H_

#include <drv/peripheral.h>
#include <stdint.h>

/**
 * @file Period.h
 * @brief Period timer helper class header file.
 */

/**
 * @class Period
 * @brief Utility class to run thread operations at a precise fixed interval.
 *
 * @details
 * This class locks executing threads into a defined periodic timeline (in microseconds).
 * Calling wait() yields/sleeps the thread until the next exact step of the periodic timeline is reached.
 */
class Period
{
	uint64_t mLastTime;
	uint32_t mPeriod;

  public:
	/**
	 * @brief Constructor for Period.
	 *
	 * @param[in] time The periodic interval duration in microseconds.
	 */
	Period(uint32_t time);

	/**
	 * @brief Default Constructor for Period. Default interval is 1,000,000 microseconds (1 second).
	 */
	Period(void);

	/**
	 * @brief Resets the base reference time to the current system microsecond time.
	 */
	void reset(void);

	/**
	 * @brief Blocks/yields the executing thread until the next period time.
	 *
	 * @return uint32_t The actual elapsed duration since the last wait period started in microseconds.
	 */
	uint32_t wait(void);

	/**
	 * @brief Dynamically changes the periodic interval duration.
	 * @note Automatically triggers a reset() of the reference starting time.
	 *
	 * @param[in] time The new periodic interval duration in microseconds.
	 */
	void setPeriod(uint32_t time);
};

#endif


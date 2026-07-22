/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_TIMEOUT__H_
#define YSS_UTIL_TIMEOUT__H_

#include <drv/mcu.h>
#include <stdint.h>

/**
 * @file Timeout.h
 * @brief Timeout helper class header file.
 */

/**
 * @class Timeout
 * @brief Utility class to track non-blocking timeout deadlines.
 *
 * @details
 * This class calculates and tracks a millisecond-based deadline. It can be used
 * within loops or state machines to check if a specific time budget has elapsed using isTimeout().
 */
class Timeout
{
#if !(defined(__CORE_CM0PLUS_H_GENERIC) || defined(__CORE_CM0_H_GENERIC))
	uint64_t mEndTime;
#else
	uint32_t mEndTime;
#endif
	uint32_t mTimeout;
  public:
	/**
	 * @brief Default Constructor for Timeout. Initializes the deadline to the current time.
	 */
	Timeout(void);

	/**
	 * @brief Constructor for Timeout. Sets a deadline of current time + timeout.
	 *
	 * @param[in] timeout Timeout duration in milliseconds.
	 */
	Timeout(uint32_t timeout);

	/**
	 * @brief Resets the timeout deadline using the previously defined timeout duration.
	 */
	void reset(void);

	/**
	 * @brief Resets the timeout deadline using a new timeout duration.
	 *
	 * @param[in] timeout New timeout duration in milliseconds.
	 */
	void reset(uint32_t timeout);

	/**
	 * @brief Checks if the deadline has passed.
	 *
	 * @return bool True if timeout occurred, false otherwise.
	 */
	bool isTimeout(void);

};

#endif
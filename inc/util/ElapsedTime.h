/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_ELAPSED_TIME__H_
#define YSS_UTIL_ELAPSED_TIME__H_

#include <drv/mcu.h>
#include <yss/Mutex.h>

/**
 * @file ElapsedTime.h
 * @brief Elapsed Time helper class header file.
 */

/**
 * @class ElapsedTime
 * @brief Utility class to measure elapsed time.
 *
 * @details
 * This class uses the system runtime clock (in microseconds) to calculate the time
 * difference between a reference start time (set during construction or reset) and the call time.
 * Access is guarded internally by a Mutex for thread-safety.
 */
class ElapsedTime
{
public:
	/**
	 * @brief Constructor for ElapsedTime. Automatically records the starting reference time.
	 */
	ElapsedTime(void);

	/**
	 * @brief Resets the starting reference time to the current system time.
	 */
	void reset(void);

	/**
	 * @brief Gets the elapsed time in microseconds.
	 *
	 * @return uint32_t Elapsed time in microseconds.
	 */
	uint32_t getUsec(void);

	/**
	 * @brief Gets the elapsed time in milliseconds.
	 *
	 * @return uint32_t Elapsed time in milliseconds.
	 */
	uint32_t getMsec(void);

	/**
	 * @brief Gets the elapsed time in seconds.
	 *
	 * @return uint32_t Elapsed time in seconds.
	 */
	uint32_t getSec(void);

private:
	Mutex mMutex;
	uint64_t mStartTime;
};

#endif
/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_RUNTIME__H_
#define YSS_RUNTIME__H_

#include <stdint.h>
#include <drv/mcu.h>

/**
 * @file runtime.h
 * @brief System runtime clock timer functions.
 */

/**
 * @namespace runtime
 * @brief Namespace containing functions to retrieve system runtime clock metrics (microseconds, milliseconds, seconds).
 */
namespace runtime
{
/**
 * @brief Gets the elapsed time since startup in seconds.
 *
 * @return uint32_t Elapsed time in seconds.
 */
uint32_t getSec(void);

/**
 * @brief Gets the elapsed time since startup in milliseconds.
 *
 * @return uint64_t Elapsed time in milliseconds.
 */
uint64_t getMsec(void);

/**
 * @brief Gets the elapsed time since startup in microseconds.
 *
 * @return uint64_t Elapsed time in microseconds.
 */
uint64_t getUsec(void);

/**
 * @brief Starts the system runtime clock source timer.
 */
void start(void);

/**
 * @brief Stops the system runtime clock source timer.
 */
void stop(void);
}

#endif
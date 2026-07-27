/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_STDLIB__H_
#define YSS_STDLIB__H_

#include <stdlib.h>
#include <stdint.h>

/**
 * @file stdlib.h
 * @brief Extended standard library utilities for the YSS framework.
 *
 * @details
 * This file defines helper and utility functions extending standard library
 * functions, such as fast hexadecimal conversion helpers.
 */

extern "C"
{
	/**
	 * @brief Converts a hexadecimal ASCII string to a 32-bit unsigned integer.
	 *
	 * @details
	 * Parses a null-terminated hex string of up to 8 characters and converts it into its
	 * corresponding 32-bit unsigned integer value. If an invalid hex character is
	 * encountered, or if the string is empty or longer than 8 characters, the function
	 * returns 0.
	 *
	 * @param[in] src Pointer to the null-terminated ASCII hexadecimal string to convert.
	 * @return uint32_t The converted 32-bit unsigned integer, or 0 if conversion fails.
	 */
	uint32_t atox(const char *src);
}

#endif

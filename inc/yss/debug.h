/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DEBUG__H_
#define YSS_DEBUG__H_

#include <stdint.h>

/**
 * @file debug.h
 * @brief Debug logging and formatting helper functions.
 */

#if defined(__SEGGER_LINKER) || defined(ST_CUBE_IDE)
/**
 * @brief Prints formatted debug output (similar to printf).
 *
 * @param[in] fmt Format control string.
 * @param[in] ... Optional arguments.
 * @return int32_t Number of characters printed on success.
 */
int32_t  debug_printf(const char *fmt,...);
#else
#include <__cross_studio_io.h>
#endif
#endif


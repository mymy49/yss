/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DEBUG__H_
#define YSS_DEBUG__H_

#include <stdint.h>

#if defined(__SEGGER_LINKER) || defined(ST_CUBE_IDE)
int32_t  debug_printf(const char *fmt,...);
#else
#include <__cross_studio_io.h>
#endif
#endif

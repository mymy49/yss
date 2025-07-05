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

namespace runtime
{
uint32_t getSec(void);

uint64_t getMsec(void);

uint64_t getUsec(void);

void start(void);

void stop(void);
}

#endif
/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_KEY__H_
#define YSS_KEY__H_

#include <drv/mcu.h>
#include <stdint.h>

#if !defined(ERROR_MCU_NOT_ABLE)

namespace key
{
void clear(void);
bool addPushHandler(bool (*trigger)(void), void (*handler)(void), int32_t  deadTime = 50);
bool addPushHandler(bool (*trigger)(void), bool &flag, int32_t  deadTime = 50);
bool addReleaseHandler(bool (*trigger)(void), bool &flag);
bool addHandlerWithRepeat(bool (*trigger)(void), void (*handler)(void), uint32_t repeatDelay = 50);
bool addCountUpHandler(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, bool cycle = false);
bool addCountUpHandlerWithRepeat(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, bool cycle = false, uint32_t accpetDelay = 1000, uint32_t repeatDelay = 50);
bool addCountDownHandler(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, bool cycle = false);
bool addCountDownHandlerWithRepeat(bool (*trigger)(void), int32_t &num, int32_t  min, int32_t  max, bool cycle = false, uint32_t acceptDelay = 1000, uint32_t repeatDelay = 50);
}

#endif

#endif


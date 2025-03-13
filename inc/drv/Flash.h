/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_FLASH__H_
#define YSS_DRV_FLASH__H_

#include "mcu.h"

#if defined(STM32F4) || defined(STM32F1) || defined(STM32F7) || defined (STM32F0) || defined(GD32F1)

#include <targets/st/class_flash_stm32f0_f1_f4_f7.h>

#elif defined(STM32G4)

#error "구조 조정으로 인해 삭제했습니다. 다시 작성해야 합니다."

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <targets/nuvoton/class_flash.h>

#else

#define YSS_DRV_FLASH_UNSUPPORTED

#endif

#endif


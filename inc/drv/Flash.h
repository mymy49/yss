/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
/**
 * @file Flash.h
 * @brief Flash controller driver configuration wrapper header file.
 *
 * @details
 * This file is a configuration selector that includes the target-specific Flash controller driver class definitions (e.g. ST Microelectronics STM32 series or Nuvoton M480/M4xx series).
 *
 * ### Common Methods Exposed by Flash Classes
 * Target flash controller implementations typically provide APIs to perform page erases, address resolution, byte/word programming, and unique device ID reading.
 *
 * ### Erasure & Programming Example (e.g., Nuvoton Target)
 * @code
 * Flash flash;
 * 
 * uint32_t pageIndex = 100;
 * uint32_t dataBuffer[128]; // Data to write (512 bytes)
 * 
 * // 1. Erase the target page before writing
 * if (flash.erasePage(pageIndex) == error_t::ERROR_NONE)
 * {
 *     // 2. Program the page with new data (e.g. 128 words)
 *     if (flash.program(pageIndex, dataBuffer, 128) == error_t::ERROR_NONE)
 *     {
 *         // Programming successful
 *     }
 * }
 * @endcode
 */

#ifndef YSS_DRV_FLASH__H_
#define YSS_DRV_FLASH__H_

#include "mcu.h"

#if defined(STM32F4) || defined(STM32F1) || defined(STM32F7) || defined (STM32F0) || defined(GD32F1)

#include <targets/st/class_flash_stm32f0_f1_f4_f7.h>

#elif defined(STM32G4)

#error "Deleted due to restructuring. Needs to be rewritten."

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <targets/nuvoton/NuvotonFlash.h>

#else

#define YSS_DRV_FLASH_UNSUPPORTED

#endif

#endif


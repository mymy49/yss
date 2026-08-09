/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Clock.h
 * @brief Clock controller driver configuration wrapper header file.
 *
 * @details
 * This file is a configuration selector that includes the target-specific
 * clock controller driver class definition based on the active MCU macro.
 *
 * The Clock driver provides APIs to configure the MCU's clock tree:
 * selecting clock sources (HSI, HSE, PLL), setting PLL multipliers and
 * dividers, configuring bus prescalers (AHB, APB1, APB2), enabling
 * peripheral clocks, and querying the resulting system and bus frequencies.
 *
 * ### Supported Targets
 * - Nuvoton M480 / M4xx / M25x series → `targets/nuvoton/NuvotonClock.h`
 *
 * ### Typical Usage
 * The clock driver is initialized once at system startup before any
 * peripheral drivers are configured. Refer to the target-specific clock
 * header for the concrete API and configuration structures.
 *
 * @code
 * // Example: Nuvoton M480 - enable PLL and set system clock to 192 MHz
 * clock.enablePll(192000000);
 * clock.setSysClock(NuvotonClock::CLK_SRC_PLL);
 * @endcode
 */

#ifndef YSS_DRV_CLOCK__H_
#define YSS_DRV_CLOCK__H_

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
#include <targets/nuvoton/NuvotonClock.h>
#endif

#endif


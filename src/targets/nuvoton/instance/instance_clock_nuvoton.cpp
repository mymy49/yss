/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <targets/nuvoton/NuvotonClock.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)

// Clock Instance
Clock clock __attribute__((section(".non_init")));

#endif


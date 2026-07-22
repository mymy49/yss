/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE__H_
#define YSS_INSTANCE__H_

#include <drv/Nvic.h>

/**
 * @file instance.h
 * @brief Global hardware driver instances declaration file.
 */

#if defined(NVIC)
extern Nvic nvic;   ///< Global instance of NVIC (Nested Vectored Interrupt Controller) driver.
#endif

#if defined(__M25x_FAMILY) || defined(__M4xx_FAMILY)
#include <targets/nuvoton/instance.h>
#endif

#endif



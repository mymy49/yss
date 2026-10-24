/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

// Flash Instance
#ifndef YSS_DRV_FLASH_UNSUPPORTED
#if defined(FLASH) || defined (FMC)
Flash flash;
#endif
#endif

// NVIC Instance
#ifndef YSS_DRV_NVIC_UNSUPPORTED
Nvic nvic;
#endif

/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef __BITFIELD_STM32_H
#define __BITFIELD_STM32_H

#if defined(GD32F10X_MD) || defined(STM32F103xE) || defined(STM32F103xB)
#include <targets/st/bitfield_stm32f103xx.h>
#elif defined(STM32F030xC)
#include <targets/st/bitfield_stm32f030xx.h>
#elif defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F407xx)
#include <targets/st/bitfield_stm32f407xx.h>
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#elif defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#elif defined(STM32G474xx)
#include <targets/st/bitfield_stm32g474xx.h>
#endif

#endif


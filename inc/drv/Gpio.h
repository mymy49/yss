/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Gpio.h
 * @brief GPIO (General Purpose Input/Output) driver class definition selection.
 */

#ifndef YSS_DRV_GPIO__H_
#define YSS_DRV_GPIO__H_

#include <stdint.h>

class Gpio;

/**
 * @struct pin_t
 * @brief Structure representing a specific GPIO pin mapping.
 */
typedef struct
{
	Gpio *port; ///< Pointer to the GPIO port instance.
	uint8_t pin; ///< GPIO pin number index.
}pin_t;

// GPIO class definition selection depending on target MCU
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0) || defined(GD32F1) || defined(STM32G4)
#include <targets/st/class_gpio_stm32.h>
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
#include <targets/nuvoton/NuvotonGpio.h>
#endif

#endif


/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_GPIO__H_
#define YSS_DRV_GPIO__H_

#include <stdint.h>

class Gpio;

typedef struct
{
	Gpio *port;
	uint8_t pin;
}pin_t;

// Gpio class 선언부 정의
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0) || defined(GD32F1) || defined(STM32G4)
#include <targets/st/class_gpio_stm32.h>
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M251_SUBFAMILY__)
#include <targets/nuvoton/NuvotonGpio.h>
#endif

#endif


/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_GPIO__H_
#define YSS_DRV_GPIO__H_

#include "peripheral.h"
#include <stdint.h>

// YSS_GPIO_Peri 자료형 선헌
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0) || defined(GD32F1) || defined(STM32G4)
typedef GPIO_TypeDef			YSS_GPIO_Peri;
#elif defined(STM32L1)

#include "gpio/define_gpio_stm32l1.h"

typedef volatile uint32_t		YSS_GPIO_Peri;

#elif defined(GD32F4)

#include <targets/st_gigadevice/define_gpio_gd32f4.h>

typedef volatile uint32_t		YSS_GPIO_Peri;

#elif defined(NRF52840_XXAA)

#include <targets/nordic/define_gpio_nrf52840.h>

typedef NRF_GPIO_Type			YSS_GPIO_Peri;

#elif defined(EFM32PG22) || defined(EFR32BG22)

typedef GPIO_TypeDef			YSS_GPIO_Peri;
#define GpioTargetHeaderFile	<targets/siliconlabs/class_gpio_efm32pg22_efr32bg22.h>

#elif defined(W7500)

typedef GPIO_TypeDef			YSS_GPIO_Peri;
#define GpioTargetHeaderFile	<targets/wiznet/class_gpio_w7500x.h>

#elif defined(CPU_MIMXRT1011DAE5A)

typedef GPIO_Type				YSS_GPIO_Peri;
#define GpioTargetHeaderFile	<targets/nxp/class_gpio_mimxrt.h>

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
typedef GPIO_T					YSS_GPIO_Peri;
#else

typedef volatile uint32_t		YSS_GPIO_Peri;

#define YSS_DRV_GPIO_UNSUPPORTED

#endif

class Gpio;

typedef struct
{
	Gpio *port;
	uint8_t pin;
}pin_t;

// Gpio class 선언부 정의
#if defined(STM32F7) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0) || defined(GD32F1) || defined(STM32G4)
#include <targets/st/class_gpio_stm32.h>
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
#include <targets/nuvoton/class_gpio.h>
#endif

#endif


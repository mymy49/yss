/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Gpio.h
 * @brief GPIO (General Purpose Input/Output) driver class selector header file.
 *
 * @details
 * This file is a configuration selector that includes the target-specific GPIO controller driver class definitions (e.g. ST Microelectronics STM32 series or Nuvoton M480/M4xx series). It also defines the common `pin_t` structure.
 *
 * ### Common Methods Exposed by Gpio Classes
 * Target GPIO implementations typically provide APIs to set pins to input, output, analog, or alternative functions, as well as read/write digital high/low levels.
 *
 * ### Usage Example (Output Configuration)
 * @code
 * // 1. Configure Pin 0 of GPIOA as output push-pull
 * gpioA.setAsOutput(0, Gpio::PUSH_PULL, Gpio::SLEWRATE_NORMAL);
 * 
 * // 2. Set PA0 high
 * gpioA.setOutput(0, true);
 * 
 * // 3. Set PA0 low
 * gpioA.setOutput(0, false);
 * @endcode
 *
 * ### Pin Packaging Struct
 * - The `pin_t` struct packages a GPIO port reference and a pin index into a single variable, making it easy to pass pin references to other drivers (such as SDMMC card detect pins or SPI Chip Select pins).
 */

#ifndef YSS_DRV_GPIO__H_
#define YSS_DRV_GPIO__H_

#include <stdint.h>
#include "Drv.h"
#include <yss/error.h>

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
#elif defined(__MAX32665_FAMILY)
#include <targets/analog_devices/Max32665Gpio.h>
#elif defined(NRF52840_XXAA)
#include <targets/nordic/nRF52_Gpio.h>
#else

class Gpio : public Drv
{
public:
	/**
	 * @brief Sets the output logic state of the specified pin.
	 *
	 * @param[in] pin Pin number (0 ~ 15).
	 * @param[in] data Output state (true for High, false for Low).
	 */
	void setOutput(uint8_t pin, bool data) __attribute__((optimize("-O1"))) {}

	/**
	 * @brief Reads the input logic state of a pin.
	 *
	 * @param[in] pin Pin number (0 ~ 15).
	 * @return bool True if pin state is High, false if pin state is Low.
	 */
	bool getInputData(uint8_t pin) { return false; }
	
	Gpio(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1"))) {}

	void isr(void) {}

private:
};

#endif

#endif


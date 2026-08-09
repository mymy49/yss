/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Nvic.h
 * @brief Nested Vectored Interrupt Controller (NVIC) driver class header file.
 *
 * @details
 * This file provides a thin driver wrapper around the ARM Cortex-M NVIC hardware.
 * It exposes a simplified API to enable or disable individual interrupt lines
 * by their IRQ number, without requiring the user to directly manipulate CMSIS
 * NVIC registers.
 *
 * ### Usage
 * The `Nvic` class is typically instantiated as a singleton global object by
 * the yss framework and is not intended to be created by the user directly.
 * The peripheral drivers (Uart, Spi, I2c, etc.) call `enableInterrupt()` of
 * the base `Drv` class, which internally delegates to the NVIC hardware.
 *
 * ### Direct IRQ Control Example
 * @code
 * // Enable IRQ line 35 (device-specific mapping) at NVIC level
 * nvic.enableInterrupt((IRQn_Type)35, true);
 *
 * // Disable IRQ line 35
 * nvic.enableInterrupt((IRQn_Type)35, false);
 * @endcode
 */

#ifndef YSS_DRV_NVIC__H_
#define YSS_DRV_NVIC__H_

#include "peripheral.h" ///< Target-specific peripheral register definitions (IRQn_Type, etc.)
#include "Drv.h"        ///< Base driver class providing clock/interrupt management infrastructure

/**
 * @class Nvic
 * @brief Driver class for the ARM Cortex-M Nested Vectored Interrupt Controller (NVIC).
 *
 * @details
 * Inherits from `Drv` to integrate seamlessly with the yss peripheral driver framework.
 * Provides direct control over individual IRQ lines at the NVIC level, independent of
 * specific peripheral clocking or resetting operations.
 *
 * This class is used internally by the framework to manage hardware interrupts.
 * End users typically do not need to interact with this class directly.
 */
class Nvic : public Drv
{
  public:
	/**
	 * @brief Default constructor for the Nvic class.
	 *
	 * @details
	 * Initializes the NVIC driver object. No hardware configuration is
	 * performed at construction time.
	 */
	Nvic(void);

	/**
	 * @brief Enables or disables a specific IRQ line in the NVIC.
	 *
	 * @details
	 * Directly sets or clears the enable bit for the specified interrupt
	 * position in the NVIC Interrupt Set-Enable or Clear-Enable register.
	 * This is equivalent to calling `NVIC_EnableIRQ()` or `NVIC_DisableIRQ()`
	 * from CMSIS, but exposed through the yss driver interface.
	 *
	 * @param[in] position The IRQ number to configure (of type `IRQn_Type`,
	 *                     defined in the target-specific device header).
	 * @param[in] en       If true, enables the interrupt; if false, disables it.
	 *                     Defaults to true.
	 */
	void enableInterrupt(IRQn_Type position, bool en = true);
};

#endif


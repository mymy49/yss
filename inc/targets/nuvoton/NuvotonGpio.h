/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_GPIO_NUVOTON__H_
#define YSS_CLASS_GPIO_NUVOTON__H_

#include <yss/error.h>
#include <drv/peripheral.h>
#include <drv/Drv.h>
#include <yss/scheduler.h>

/**
 * @file NuvotonGpio.h
 * @brief GPIO (General Purpose Input/Output) driver class header file for Nuvoton MCUs.
 */

/**
 * @class Gpio
 * @brief Driver class for the GPIO peripheral on Nuvoton MCUs.
 *
 * @details
 * This class provides interface functions to configure GPIO pins as input, output, or
 * alternate functions, adjust output/slew rate modes, handle internal pull-up/pull-down resistors,
 * and assign GPIO interrupts (edge or level triggered) to either callback functions or scheduler triggers.
 */
class Gpio : public Drv
{
public:
	/**
	 * @brief Enumeration for GPIO output types.
	 */
	typedef enum 
	{
		PUSH_PULL = 1,   ///< Push-pull output mode
		OPEN_DRAIN,      ///< Open-drain output mode
		QUASI_BIDIR      ///< Quasi-bidirectional mode
	}otype_t;
	
	/**
	 * @brief Enumeration for alternate function output types.
	 */
	typedef enum
	{
		AF_PUSH_PULL = 0, ///< Alternate function Push-pull mode
		AF_OPEN_DRAIN,    ///< Alternate function Open-drain mode
	}atype_t;
	
	/**
	 * @brief Enumeration for GPIO slew rate settings.
	 */
	typedef enum
	{
		SLEWRATE_NORMAL = 0, ///< Normal slew rate
		SLEWRATE_HIGH,       ///< High slew rate
		SLEWRATE_FAST        ///< Fast slew rate
	}slewrate_t;
	
	// Include target-specific altFunc_t definition
#if defined(__M46x_SUBFAMILY)
#include "def_gpio_m46x.h"
#elif defined(__M251_SUBFAMILY)
#include "def_gpio_m25x.h"
#elif defined(__M43x_SUBFAMILY)
#include "def_gpio_m43x.h"
#endif

	/**
	 * @brief Struct package mapping a GPIO port, pin index, and alternate function.
	 */
	typedef struct
	{
		GPIO_T *port;    ///< Pointer to GPIO hardware register base (e.g. GPIOA, GPIOB)
		uint8_t pin;     ///< Pin number (0 ~ 15)
		altFunc_t func;  ///< Alternate function mapping selector
	}altFuncPackage_t;

	/**
	 * @brief Enumeration for GPIO pull-up / pull-down settings.
	 */
	typedef enum
	{
		PUPD_NONE = 0,    ///< Floating (no pull-up or pull-down)
		PUPD_PULL_UP,     ///< Internal pull-up resistor enabled
		PUPD_PULL_DOWN    ///< Internal pull-down resistor enabled
	}pupd_t;
	
	/**
	 * @brief Enumeration for GPIO interrupt trigger sources.
	 */
	typedef enum
	{
		EDGE_RISING,     ///< Interrupt triggered on rising edge
		EDGE_FALLING,    ///< Interrupt triggered on falling edge
		EDGE_BOTH,       ///< Interrupt triggered on both rising and falling edges
		LEVEL_HIGH,      ///< Interrupt triggered on high level state
		LEVEL_LOW        ///< Interrupt triggered on low level state
	}source_t;

	/**
	 * @brief Configures a pin as output mode.
	 *
	 * @param[in] pin Pin number (0 ~ 15).
	 * @param[in] otype Output type (PUSH_PULL, OPEN_DRAIN, or QUASI_BIDIR).
	 * @param[in] slewrate Slew rate speed (SLEWRATE_NORMAL, SLEWRATE_HIGH, or SLEWRATE_FAST).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setAsOutput(uint8_t pin, otype_t otype = PUSH_PULL, slewrate_t slewrate = SLEWRATE_NORMAL) __attribute__((optimize("-O1")));

	/**
	 * @brief Configures a pin as input mode.
	 *
	 * @param[in] pin Pin number (0 ~ 15).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setAsInput(uint8_t pin) __attribute__((optimize("-O1")));

	/**
	 * @brief Sets the output logic state of the specified pin.
	 *
	 * @param[in] pin Pin number (0 ~ 15).
	 * @param[in] data Output state (true for High, false for Low).
	 */
	void setOutput(uint8_t pin, bool data) __attribute__((optimize("-O1")));

	/**
	 * @brief Configures a pin to operate as an alternate function pin.
	 *
	 * @param[in] pin Pin number (0 ~ 15).
	 * @param[in] altfunc Alternate function enum value.
	 * @param[in] atype Alternate function output type (AF_PUSH_PULL or AF_OPEN_DRAIN).
	 * @param[in] slewrate Slew rate speed.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setAsAltFunc(uint8_t pin, altFunc_t altfunc, atype_t atype = AF_PUSH_PULL, slewrate_t slewrate = SLEWRATE_NORMAL) __attribute__((optimize("-O1")));

	/**
	 * @brief Sets the internal pull-up/pull-down resistor settings for the pin.
	 *
	 * @param[in] pin Pin number (0 ~ 15).
	 * @param[in] pupd Pull-up/pull-down configuration.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setPullUpDown(uint8_t pin, pupd_t pupd);

	/**
	 * @brief Enables GPIO interrupt on the pin with a function pointer callback.
	 * @note Do not call any functions that trigger context switching inside the ISR.
	 * Refer to `yss.h` for distinction between ISR and Callback functions.
	 *
	 * @param[in] pin Pin number (0 ~ 15).
	 * @param[in] src Interrupt trigger source configuration.
	 * @param[in] isr Pointer to the callback function.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setGpioInterrupt(uint8_t pin, source_t src, void (*isr)(void));

	/**
	 * @brief Enables GPIO interrupt on the pin with a scheduler trigger ID.
	 * @note Do not call any functions that trigger context switching inside the ISR.
	 * Refer to `yss.h` for distinction between ISR and Callback functions.
	 *
	 * @param[in] pin Pin number (0 ~ 15).
	 * @param[in] src Interrupt trigger source configuration.
	 * @param[in] trigger Scheduler trigger ID.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setGpioInterrupt(uint8_t pin, source_t src, triggerId_t trigger);
	
	/**
	 * @brief Configures multiple pins to their alternate function states.
	 * @details Intended to configure startup IO functions before BSS section is initialized.
	 * Using other GPIO functions before BSS initialization may result in undefined behaviors.
	 *
	 * @param[in] package Pointer to an array of altFuncPackage_t.
	 * @param[in] count Number of packages in the array.
	 * @param[in] atype Alternate function output type.
	 * @param[in] slewrate Slew rate speed.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t setPackageAsAltFunc(altFuncPackage_t *package, uint8_t count, atype_t atype = AF_PUSH_PULL, slewrate_t slewrate = SLEWRATE_NORMAL);

	/**
	 * @brief Reads the input logic state of a pin.
	 *
	 * @param[in] pin Pin number (0 ~ 15).
	 * @return bool True if pin state is High, false if pin state is Low.
	 */
	bool getInputData(uint8_t pin);
	
	// Internal system functions. Do not call from user application.
	struct setup_t
	{
		GPIO_T *dev;
		volatile uint32_t *mfp;
	};

	Gpio(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void);

private:
	GPIO_T *mDev;
	volatile uint32_t *mMfp, *mOutputReg;
	void (*mIsr[16])(void);
	bool mTriggerFlag[16];
	int32_t  mTriggerNum[16];
};

#endif
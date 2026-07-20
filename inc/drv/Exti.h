/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Exti.h
 * @brief External Interrupt (EXTI) Driver Class
 */

#ifndef YSS_DRV_EXTI__H_
#define YSS_DRV_EXTI__H_

#include "mcu.h"

#if defined(GD32F1) || defined(GD32F4) || defined(STM32F4) || defined(STM32F7) || defined(STM32F0) || defined(STM32F1)

#define EXTI_COUNT		16

#elif defined(NRF52840_XXAA)

#define EXTI_COUNT		8

#else

#define YSS_DRV_EXTI_UNSUPPORTED
#define EXTI_COUNT		0

#endif

#include "Drv.h"
#include "Gpio.h"
#include <yss/error.h>
#include <yss/scheduler.h>

/**
 * @brief External Interrupt (EXTI) Driver Class.
 * 
 * Provides APIs for configuring and handling external interrupts (EXTI).
 * This class inherits from Drv and handles mapping GPIO pins to EXTI lines,
 * setting trigger modes, enabling/disabling EXTI lines, and registering ISR callbacks.
 */
class Exti : public Drv
{
public:
	/**
	 * @brief Trigger edge mode configuration.
	 */
	typedef enum
	{
		RISING = 0x1,  ///< Trigger on rising edge
		FALLING = 0x2  ///< Trigger on falling edge
	}mode_t;

	/**
	 * @brief GPIO Port definitions.
	 */
	enum
	{
		PORTA = 0,
		PORTB,
		PORTC,
		PORTD,
		PORTE,
		PORTF,
		PORTG,
		PORTH,
		PORTI,
		PORTJ,
		PORTK,
	};

	/**
	 * @brief Construct a new Exti object.
	 * 
	 * @param clockFunc Function pointer to enable/disable the peripheral clock.
	 * @param nvicFunc Function pointer to enable/disable the NVIC interrupt.
	 */
	Exti(void (*clockFunc)(bool en), void (*nvicFunc)(bool en));

	/**
	 * @brief Add and configure an external interrupt callback.
	 * 
	 * Maps a GPIO pin to an EXTI line and registers a standard callback function.
	 * Note that the EXTI is not enabled automatically upon calling add().
	 * Use enable() to activate the interrupt line.
	 * 
	 * @param gpio Reference to the GPIO port object.
	 * @param pin The GPIO pin number (0-15).
	 * @param mode The trigger edge mode (RISING, FALLING, etc.).
	 * @param func Pointer to the callback function to be executed on interrupt.
	 * @return error_t Error code indicating success or failure.
	 */
	error_t add(Gpio &gpio, uint8_t pin, mode_t mode, void (*func)(void));

	/**
	 * @brief Add and configure an external interrupt that triggers a scheduler event.
	 * 
	 * Maps a GPIO pin to an EXTI line and registers a scheduler trigger ID.
	 * Note that the EXTI is not enabled automatically upon calling add().
	 * Use enable() to activate the interrupt line.
	 * 
	 * @param gpio Reference to the GPIO port object.
	 * @param pin The GPIO pin number (0-15).
	 * @param mode The trigger edge mode (RISING, FALLING, etc.).
	 * @param trigger The scheduler trigger ID to trigger.
	 * @return error_t Error code indicating success or failure.
	 */
	error_t add(Gpio &gpio, uint8_t pin, mode_t mode, triggerId_t trigger);
	
	/**
	 * @brief Temporarily enable or disable the external interrupt line.
	 * 
	 * When calling add(), the EXTI line is not enabled by default.
	 * Use this function to enable or disable the interrupt dynamically.
	 * 
	 * @param pin The pin number representing the EXTI line.
	 * @param enable Set to true to enable the interrupt, or false to disable it.
	 */
	void enable(uint8_t pin, bool enable = true);

	/**
	 * @brief Interrupt service routine (ISR) entry handler.
	 * 
	 * This handler processes the EXTI line event and executes the registered callback.
	 * It should be called from the actual hardware ISR vector.
	 * 
	 * @param num The EXTI line number to process.
	 */
	void isr(int32_t  num);
private:
	void (*mIsr[EXTI_COUNT])(void); ///< Array of callback function pointers for EXTI lines.

	bool mTriggerFlag[EXTI_COUNT]; ///< Flag array indicating if a scheduler trigger is registered.

	int32_t  mTriggerNum[EXTI_COUNT]; ///< Array of scheduler trigger IDs for EXTI lines.
};

#endif


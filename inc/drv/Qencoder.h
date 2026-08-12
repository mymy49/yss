/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Qencoder.h
 * @brief Quadrature Encoder (QENCODER) driver class header file.
 *
 * @details
 * This driver provides an interface for reading the position and direction of
 * a rotary incremental encoder using the quadrature encoder interface built
 * into certain MCU timer peripherals (e.g. TIM on STM32F4/F7).
 *
 * In quadrature encoder mode the timer hardware automatically tracks the
 * encoder count by decoding the two phase-shifted square wave signals
 * (Channel A and Channel B), incrementing the counter on one edge direction
 * and decrementing on the other.
 *
 * ### Initialization Flow
 * 1. Configure the two GPIO pins connected to encoder Channel A and Channel B
 *    as alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the peripheral using `enableClock()`.
 * 3. Initialize the quadrature encoder mode using `initialize()`.
 * 4. Start counting using `start()`.
 *
 * ### Initialization Example
 * @code
 * // Configure encoder pins as timer input capture alternative functions
 * gpioA.setAsAltFunc(0, Gpio::PA0_TIM2_CH1_ETR); // Channel A
 * gpioA.setAsAltFunc(1, Gpio::PA1_TIM2_CH2);      // Channel B
 *
 * qencoder2.enableClock();
 * qencoder2.initialize();
 * qencoder2.start();
 * @endcode
 *
 * ### Reading Position
 * - Call `getCount()` to read the current signed 16-bit position count.
 *   Clockwise rotation increments the count; counter-clockwise decrements it.
 * - Call `resetCount()` to zero the counter at a reference position.
 *
 * ### Reading Example
 * @code
 * int16_t position = qencoder2.getCount();
 * if (position != 0)
 * {
 *     // Process encoder position
 * }
 * qencoder2.resetCount(); // Reset to zero at current position
 * @endcode
 *
 * @note This driver is currently supported only on STM32F4 and STM32F7.
 *       On unsupported targets the `YSS_DRV_QENCODER_UNSUPPORTED` macro is
 *       defined and the hardware type is replaced with a dummy volatile type.
 */

#ifndef YSS_DRV_QENCODER__H_
#define YSS_DRV_QENCODER__H_

#include "peripheral.h" ///< Target-specific peripheral register definitions

#if defined(STM32F4) || defined(STM32F7)

typedef TIM_TypeDef		YSS_QENCODER_Peri; ///< Hardware peripheral register type for STM32F4/F7

#else

#define YSS_DRV_QENCODER_UNSUPPORTED               ///< Defined when the target MCU does not support this driver
typedef volatile uint32_t	YSS_QENCODER_Peri; ///< Dummy peripheral type for unsupported targets

#endif

#include "Drv.h" ///< Base driver class

/**
 * @class Qencoder
 * @brief Driver class for the Quadrature Encoder interface.
 *
 * @details
 * This class configures an MCU timer peripheral in quadrature encoder mode to
 * decode the two-phase pulse output of an incremental rotary encoder.
 * The hardware counter automatically increments or decrements in response to
 * encoder shaft rotation, allowing the application to read absolute relative
 * position without a polling ISR.
 *
 * Thread safety: `getCount()` and `resetCount()` are lightweight register
 * accesses. If called concurrently from multiple threads, wrap them with a
 * Mutex if atomicity is required.
 */
class Qencoder : public Drv
{
public:
	/**
	 * @struct setup_t
	 * @brief Hardware setup configuration structure for the Qencoder driver.
	 */
	struct setup_t
	{
		YSS_QENCODER_Peri *peri; ///< Pointer to the hardware timer peripheral instance used for quadrature decoding.
	};

	/**
	 * @brief Constructor for the Qencoder class.
	 *
	 * @param[in] drvSetup Reference to the base driver setup configuration
	 *                     (clock, NVIC, and reset function pointers).
	 * @param[in] setup    Reference to the Qencoder-specific hardware setup
	 *                     (pointer to the timer peripheral).
	 */
	Qencoder(const Drv::setup_t &drvSetup, const setup_t &setup);

	/**
	 * @brief Initializes the timer peripheral in quadrature encoder mode.
	 *
	 * @details
	 * Configures the timer's Channel 1 and Channel 2 inputs to decode
	 * the two quadrature phase signals. Both rising and falling edges of
	 * both channels are counted, providing four counts per encoder cycle
	 * (x4 resolution mode).
	 *
	 * Must be called after `enableClock()` and before `start()`.
	 */
	void initialize(void);

	/**
	 * @brief Starts the encoder counter.
	 *
	 * @details
	 * Enables the timer counter, allowing the hardware to begin tracking
	 * encoder pulses. After calling this function, `getCount()` will return
	 * a value that changes with encoder rotation.
	 */
	void start(void);

	/**
	 * @brief Stops the encoder counter.
	 *
	 * @details
	 * Disables the timer counter. The last captured count value is preserved
	 * and can still be read via `getCount()` after stopping.
	 */
	void stop(void);

	/**
	 * @brief Returns the current encoder position count.
	 *
	 * @details
	 * Reads the 16-bit timer counter register and returns it as a signed
	 * integer. Clockwise rotation produces positive increments and
	 * counter-clockwise rotation produces negative increments (or vice versa
	 * depending on the physical wiring and encoder polarity).
	 *
	 * The count wraps around at the 16-bit boundary (±32767).
	 *
	 * @return int16_t The current signed encoder position count.
	 */
	int16_t getCount(void);

	/**
	 * @brief Resets the encoder position counter to zero.
	 *
	 * @details
	 * Sets the timer counter register to 0, establishing the current
	 * physical encoder position as the new reference zero point.
	 */
	void resetCount(void);

protected:
	YSS_QENCODER_Peri *mPeri; ///< Pointer to the hardware timer peripheral instance.
};

#endif


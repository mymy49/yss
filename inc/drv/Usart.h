/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Usart.h
 * @brief Universal Synchronous Asynchronous Receiver Transmitter (USART) driver class header file.
 *
 * @details
 * This file defines the `Usart` driver class which extends the `Uart` driver class
 * with synchronous clock output (SCK) support. In USART mode, the peripheral can
 * generate a clock signal on the SCK pin synchronized to the transmitted data,
 * allowing communication with synchronous slave devices such as certain sensors,
 * external ADCs, or SPI-compatible devices without requiring a separate SPI instance.
 *
 * ### Initialization Flow
 * 1. Configure the GPIO pins (TX, RX, and optionally SCK) as alternative functions
 *    using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the peripheral using `enableClock()`.
 * 3. Initialize the USART using `initialize()` (inherited from `Uart`).
 * 4. Enable the peripheral interrupts using `enableInterrupt()`.
 * 5. Optionally enable the SCK output using `enableSck()`.
 */

#ifndef YSS_DRV_USART__H_
#define YSS_DRV_USART__H_

#include "Uart.h" ///< Parent Uart driver class providing all asynchronous UART functionality

#if defined(YSS_DRV_UART_UNSUPPORTED)

#define YSS_DRV_USART_UNSUPPORTED ///< Defined when the target MCU does not support a USART peripheral

#endif

/**
 * @class Usart
 * @brief Driver class for the USART peripheral interface.
 *
 * @details
 * Extends the `Uart` class with synchronous clock output support.
 * All standard UART operations (initialize, send, receive, getRxByte, etc.)
 * are inherited from `Uart`. The only USART-specific addition is
 * `enableSck()`, which enables or disables the synchronized clock output
 * on the SCK pin.
 *
 * When SCK output is enabled, the USART transmits data in synchronous
 * master mode. Only use this when the remote device expects a synchronized
 * clock rather than a standard UART framing.
 */
class Usart : public Uart
{
public:
	/**
	 * @brief Enables or disables the USART clock output (SCK) pin.
	 * 
	 * @param[in] en If true, enables SCK clock output. If false, disables it.
	 */
	void enableSck(bool en = true) __attribute__((optimize("-O1")));

	// The following are internal functions and do not need to be called by the user application.
	Usart(const Drv::setup_t drvConfig, const Uart::setup_t config) __attribute__((optimize("-O1")));
};

#endif

// Initialization guide:
//		- Use Gpio::setAsAltFunc() to configure target pins for USART function.
//		- Supply clock to the peripheral using enableClock().
//		- Call initialize() to configure the receive buffer and baud rate, and enable the device.
//		- Enable USART interrupts using enableInterrupt().

// Transmit guide:
//		- Call lock() to prevent concurrent access from other threads.
//		- Call send() to transmit one or multiple bytes.
//		- Call unlock() to release ownership.

// Receive guide (using getRxByte()):
//		- Call getRxByte(). If the return value is >= 0, process it as valid data.
//		- If negative, ignore the returned value.

// Receive guide (using waitUntilReceive()):
//		- Calling waitUntilReceive() blocks the thread until data is received or timeout occurs.
//		- Process the received data upon return.
//		- Caution: This blocks the thread, so design the loop structure carefully.



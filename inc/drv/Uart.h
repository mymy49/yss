/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_UART__H_
#define YSS_DRV_UART__H_

#include "Drv.h"
#include <yss/error.h>

/**
 * @file Uart.h
 * @brief Universal Asynchronous Receiver Transmitter (UART) driver class header file.
 *
 * ### Initialization Flow
 * 1. Configure the GPIO pins related to the UART as alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the peripheral using `enableClock()`.
 * 3. Initialize the UART driver, setting the baud rate, mode, stop bits, parity, and receive buffer configuration using `initialize()`.
 * 4. Enable the peripheral interrupts using `enableInterrupt()`.
 *
 * ### Initialization Example
 * @code
 * // Configure target pins for UART function
 * gpioA.setAsAltFunc(2, Gpio::PA2_USART2_TX);
 * gpioA.setAsAltFunc(3, Gpio::PA3_USART2_RX);
 * 
 * uart2.enableClock(); // Supply clock
 * 
 * // Configure UART parameters
 * Uart::config_t uartConfig = {
 *     Uart::MODE_NORMAL,   // mode
 *     115200,              // baudrate
 *     Uart::STOP_1BIT,     // stopbit
 *     Uart::PARITY_NONE,   // parity
 *     nullptr,             // rcvBuf (nullptr for dynamic allocation)
 *     512                  // rcvBufSize (512 bytes)
 * };
 * 
 * uart2.initialize(uartConfig);
 * uart2.enableInterrupt(); // Enable RX/TX interrupt handling
 * @endcode
 *
 * ### Transmission Flow
 * 1. Call `lock()` to gain exclusive access to the UART interface.
 * 2. Call `send()` with the data payload pointer and size, or send a single byte.
 * 3. Call `unlock()` to release ownership.
 *
 * ### Transmission Example
 * @code
 * char msg[] = "Hello World\r\n";
 * 
 * uart2.lock();
 * uart2.send(msg, sizeof(msg) - 1);
 * uart2.unlock();
 * @endcode
 *
 * ### Reception Flow
 * Reception is handled asynchronously via an internal ring buffer.
 * - Call `getRxCount()` to check the number of bytes currently stored in the buffer.
 * - Call `getRxBuffer()` to acquire the buffer pointer to the oldest valid data block.
 * - Process the data.
 * - Call `releaseRxBuffer()` with the number of bytes read to free the slots.
 * - Alternatively, call `waitUntilReceive()` to block the thread until data is received or a timeout occurs.
 *
 * ### Reception Example (Non-blocking check)
 * @code
 * uint32_t count = uart2.getRxCount();
 * if(count > 0)
 * {
 *     int8_t *buf = uart2.getRxBuffer();
 *     for(uint32_t i = 0; i < count; i++)
 *     {
 *         char c = buf[i];
 *         // Process character c
 *     }
 *     uart2.releaseRxBuffer(count); // Free slots in ring buffer
 * }
 * @endcode
 *
 * ### Reception Example (Blocking wait)
 * @code
 * while(true)
 * {
 *     if(uart2.waitUntilReceive(1000)) // Wait for up to 1 second
 *     {
 *         int16_t c = uart2.getRxByte();
 *         if(c >= 0)
 *         {
 *             // Process received byte c
 *         }
 *     }
 *     else
 *     {
 *         // Timeout occurred, handle idle
 *     }
 * }
 * @endcode
 */

/**
 * @class Uart
 * @brief Driver class for the Universal Asynchronous Receiver Transmitter (UART) peripheral.
 */
class Uart : public Drv
{
public:
	/**
	 * @brief Enumeration for UART operating modes.
	 */
	typedef enum
	{
		MODE_NORMAL,  ///< Standard Tx and Rx mode.
		MODE_TX_ONLY, ///< Transmitter-only mode.
		MODE_RX_ONLY, ///< Receiver-only mode.
		MODE_ONE_WIRE ///< Single-wire half-duplex mode.
	}mode_t;

	/**
	 * @brief Enumeration for UART stop bit configuration.
	 */
	typedef enum
	{
		STOP_1BIT = 0,
		STOP_2BIT = 1
	}stopbit_t;

	/**
	 * @brief Enumeration for UART parity configuration.
	 */
	typedef enum
	{
		PARITY_NONE = 0,
		PARITY_ODD,
		PARITY_EVEN,
		PARITY_MARK,
		PARITY_SPACE
	}parityBit_t;

	/**
	 * @brief Configuration parameters for UART peripheral setup.
	 */
	typedef struct
	{
		mode_t mode;        ///< UART operating mode.
		uint32_t baudrate;  ///< Baud rate.
		stopbit_t stopbit;  ///< Number of stop bits.
		parityBit_t parity; ///< Parity setting.
		bool hwfc;
		void *rcvBuf;       ///< Pointer to user-allocated receive buffer (if nullptr, memory will be allocated dynamically).
		uint32_t rcvBufSize;///< Size of the receive buffer.
	}config_t;
	
	/**
	 * @brief Callback handlers for UART interrupt events.
	 */
	typedef struct
	{
		void (*dataRx)(uint8_t rxData); ///< Callback function pointer for data reception interrupt.
		void (*frameError)(void);       ///< Callback function pointer for frame error interrupt.
		void (*parityError)(void);      ///< Callback function pointer for parity error interrupt.
	}handler_t;

	/**
	 * @brief Initializes the UART device with the specified configuration.
	 * @details If config_t::rcvBuf is set to nullptr, the driver automatically allocates the memory of size config_t::rcvBufSize from the heap.
	 * 
	 * @param[in] config Configuration settings.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t initialize(config_t config) __attribute__((optimize("-O1")));

	/**
	 * @brief Changes the communication baud rate while operating.
	 * 
	 * @param[in] baudrate The target baud rate.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t changeBaudrate(int32_t baudrate) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Returns the oldest received byte in the buffer.
	 * @details If there is no received byte available, it returns -1 (0xFFFF).
	 *          Otherwise, it returns a value between 0x0000 and 0x00FF (the received byte).
	 * 
	 * @return int16_t The received byte, or -1 if the buffer is empty.
	 */
	int16_t getRxByte(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the number of bytes currently stored in the receive buffer.
	 * @details The pointer to the valid receive buffer can be obtained using getRxBuffer().
	 * 
	 * @return uint32_t Number of received bytes.
	 */
	uint32_t getRxCount(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the pointer to the oldest valid data block in the receive buffer.
	 * @details Subsequent received bytes are stored sequentially. The valid range of indexes is from 0 to getRxCount() - 1.
	 *          After consuming the data, releaseRxBuffer() must be called to release/free the buffer slots.
	 * 
	 * @return int8_t* Pointer to the received data.
	 */
	int8_t* getRxBuffer(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Releases a specified number of bytes from the receive buffer after processing.
	 * @details This function must be called to allow receiving new incoming data. 
	 *          The count parameter must be equal to the count retrieved via getRxCount().
	 * 
	 * @param[in] count The number of bytes to release.
	 */
	void releaseRxBuffer(uint32_t count) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Blocks/waits until at least one byte of data is received or timeout occurs.
	 * @details Calls thread::yield() internally during idle waiting.
	 * 
	 * @param[in] timeout Timeout value in milliseconds.
	 * @return bool Returns true if data was received, false on timeout.
	 */
	bool waitUntilReceive(uint32_t timeout) __attribute__((optimize("-O1")));

	/**
	 * @brief Flushes/clears the receive buffer.
	 */
	void flush(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Transmits a block of data.
	 * 
	 * @param[in] src Pointer to the data payload buffer.
	 * @param[in] size The size of the data payload in bytes.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t send(void *src, int32_t  size) __attribute__((optimize("-O1"))) = 0;
	
	/**
	 * @brief Transmits a single byte of data.
	 * 
	 * @param[in] data The byte to transmit.
	 */
	virtual void send(int8_t data) __attribute__((optimize("-O1"))) = 0;

	/**
	 * @brief Registers callback handler functions for UART interrupt events.
	 * 
	 * @param[in] handler Struct containing target interrupt callback function pointers (set to nullptr for unused interrupts).
	 */
	void setIsrHandler(handler_t handler) __attribute__((optimize("-O1")));

	// The following are internal functions and do not need to be called by the user application.
	Uart(const Drv::setup_t drvSetup);

	void push(int8_t data) __attribute__((optimize("-O1")));

protected:
	int8_t *mRcvBuf;
	int32_t  mRcvBufSize;
	int32_t  mTail, mHead;
	mode_t mMode;
	handler_t mIsrHandler;
};

#endif

// Initialization guide:
//		- Use Gpio::setAsAltFunc() to configure target pins for UART function.
//		- Supply clock to the peripheral using enableClock().
//		- Call initialize() to configure the receive buffer and baud rate, and enable the device.
//		- Enable UART interrupts using enableInterrupt().

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



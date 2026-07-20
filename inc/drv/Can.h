/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CAN__H_
#define YSS_DRV_CAN__H_

#include "peripheral.h"
#include "Drv.h"
#include <yss/error.h>

/**
 * @file Can.h
 * @brief CAN (Controller Area Network) driver base class header file.
 * 
 * ### Initialization Flow (Target-Specific Implementation)
 * 1. Configure the GPIO pins related to the CAN peripheral as alternative functions using the `setAsAltFunc()` function.
 * 2. Define the device configuration struct (e.g., target-specific `config_t`).
 * 3. Supply the peripheral clock using the `enableClock()` function.
 * 4. Initialize the CAN device using the target-specific `initialize()` function.
 * 5. Enable the peripheral interrupts using the `enableInterrupt()` function.
 * 6. Configure reception filters using target-specific filter functions (e.g., `setStdMaskFilter()` or `setExtMaskFilter()`).
 * 
 * ### Initialization Example (Target-Specific, e.g., Nuvoton/STM32)
 * @code
 * // Configure the peripheral configuration
 * const NuvotonCanFd::config_t canConfig
 * {
 *     250000,          // uint32_t baudrate;       // Nominal baudrate
 *     128,             // uint32_t rxBufferDepth;  // RX packet ring-buffer size
 *     0.875f,          // float samplePoint;       // Sample point (typically 87.5%)
 *     false,           // bool enableSilent;       // Silent mode
 *     false            // bool enableLoopback;     // Loopback mode
 * };
 * 
 * can1.enableClock();                 // Enable CAN1 peripheral clock
 * can1.initialize(canConfig);         // Initialize CAN1 peripheral
 * can1.enableInterrupt();             // Enable CAN1 interrupt
 * can1.setExtMaskFilter(0, 0x0, 0x0); // Configure mask 0 to accept all extended frames
 * @endcode
 * 
 * ### Transmission Flow
 * 1. Prepare the message payload and identifier.
 * 2. Call the `lock()` function to secure exclusive access to the CAN peripheral.
 * 3. Transmit the message using `sendStdCanMessage()` or `sendXtdCanMessage()`.
 * 4. Call the `unlock()` function to release the mutex and allow other threads access.
 * 
 * ### Transmission Example
 * @code
 * uint8_t dataBuffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
 * 
 * can1.lock(); // Lock mutex for thread-safe access
 * can1.sendStdCanMessage(0x123, dataBuffer, 8); // Send standard frame
 * can1.unlock(); // Unlock mutex
 * @endcode
 * 
 * ### Reception Flow
 * - Continuously check for new messages in a loop using `isNewRxMessage()`.
 * - Retrieve the received frame via `getNewRxCanMessage()`.
 * - If no new messages are present, yield CPU execution to other threads using `thread::yield()` to optimize resource consumption.
 * 
 * ### Reception Example
 * @code
 * while(true)
 * {
 *     if(can1.isNewRxMessage())
 *     {
 *         canMsg_t rcvMsg = can1.getNewRxCanMessage();
 *         if(!rcvMsg.xtd) // Check if standard frame
 *         {
 *             switch(rcvMsg.id)
 *             {
 *                 case 0x100:
 *                     // Handle standard message ID 0x100
 *                     break;
 *                 case 0x101:
 *                     // Handle standard message ID 0x101
 *                     break;
 *             }
 *         }
 *         else // Extended frame
 *         {
 *             switch(rcvMsg.id)
 *             {
 *                 case 0x10000000:
 *                     // Handle extended message ID 0x10000000
 *                     break;
 *             }
 *         }
 *     }
 *     else
 *     {
 *         // Yield execution to other threads if no new messages are available
 *         thread::yield();
 *     }
 * }
 * @endcode
 */

/**
 * @struct canMsg_t
 * @brief Structure representing a CAN message frame.
 */
typedef struct
{
	bool xtd;          ///< True if it is an extended ID (29-bit), false if standard ID (11-bit).
	uint32_t id;       ///< CAN Identifier.
	uint8_t dlc;       ///< Data Length Code (number of bytes of data, 0 to 8).
	uint8_t data[8];   ///< Data payload buffer.
}canMsg_t;

/**
 * @class Can
 * @brief Base class for CAN (Controller Area Network) driver.
 * 
 * @details
 * This class provides the base virtual interface for CAN driver instances.
 * Since CAN configuration structs and filter registers vary by MCU manufacturer, 
 * initialization and filter setting functions are defined in target-specific subclasses.
 * 
 * The class inherits from `Mutex`, so thread safety should be managed by using the `lock()` 
 * and `unlock()` functions when sending CAN messages.
 */
class Can : public Drv
{
public :
	/**
	 * @brief Gets the configured nominal baudrate.
	 * 
	 * @return uint32_t The nominal baudrate in bps.
	 */
	virtual uint32_t getBaudrate(void) = 0;

	/**
	 * @brief Gets the configured sample point ratio.
	 * 
	 * @return float The sample point as a fraction (typically between 0.0 and 1.0, e.g., 0.875).
	 */
	virtual float getSamplePoint(void) = 0;

	/**
	 * @brief Sends a standard CAN message (11-bit identifier).
	 * 
	 * @param[in] id The 11-bit standard CAN identifier.
	 * @param[in] src Pointer to the data payload buffer to be sent.
	 * @param[in] dlc The Data Length Code (number of data bytes, up to 8).
	 */
	virtual void sendStdCanMessage(uint16_t id, uint8_t *src, uint8_t dlc) = 0;

	/**
	 * @brief Sends an extended CAN message (29-bit identifier).
	 * 
	 * @param[in] id The 29-bit extended CAN identifier.
	 * @param[in] src Pointer to the data payload buffer to be sent.
	 * @param[in] dlc The Data Length Code (number of data bytes, up to 8).
	 */
	virtual void sendXtdCanMessage(uint32_t id, uint8_t *src, uint8_t dlc) = 0;

	/**
	 * @brief Checks if there is a new received message in the RX buffer.
	 * 
	 * @return bool True if a new message is available, false otherwise.
	 */
	virtual bool isNewRxMessage(void) = 0;

	/**
	 * @brief Retrieves the next received CAN message from the RX buffer.
	 * 
	 * @return canMsg_t The received CAN message structure.
	 */
	virtual canMsg_t getNewRxCanMessage(void) = 0;

	/**
	 * @brief Constructor for the Can base class.
	 * 
	 * @param[in] drvSetup The base driver setup configuration.
	 */
	Can(const Drv::setup_t drvSetup);

private :
};

#endif


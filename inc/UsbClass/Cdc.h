/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_CDC__H_
#define YSS_USB_CLASS_CDC__H_

#include "UsbClass.h"
#include <yss/error.h>

/**
 * @file Cdc.h
 * @brief USB Communications Device Class (CDC) base driver class header file.
 */

/**
 * @class Cdc
 * @brief Base class for USB CDC (Communications Device Class) virtual COM ports.
 *
 * @details
 * This class provides standard USB CDC Virtual COM Port interfaces, including initialization,
 * data transmission and reception, checking for transmission clearance (CTS/DTR status),
 * and registering host line-coding configuration changes (baudrate, stop bits, parity).
 */
class Cdc : public UsbClass
{
public :
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
	/**
	 * @brief Class-Specific Interface Descriptor for CDC.
	 */
	typedef struct
	{
		uint8_t bLength;             ///< Size of this descriptor in bytes.
		uint8_t bDescriptorType;     ///< CS_INTERFACE descriptor type.
		uint8_t bDescriptorSubtype;  ///< Header functional descriptor subtype.
		uint16_t bcdCDC;             ///< USB Class Definitions for Communication Devices Specification release number.
	}csInterfaceDesc_t __attribute__ ((__packed__));
	
	/**
	 * @brief Enumeration for stop bits configuration.
	 */
	typedef enum
	{
		STOP_1BIT = 0,               ///< 1 stop bit
		STOP_1_5BIT,                 ///< 1.5 stop bits
		STOP_2BIT                    ///< 2 stop bits
	}stopBit_t;

	/**
	 * @brief Enumeration for parity configuration.
	 */
	typedef enum
	{
		PARITY_NONE = 0,             ///< No parity
		PARITY_ODD,                  ///< Odd parity
		PARITY_EVEN,                 ///< Even parity
		PARITY_MARK,                 ///< Mark parity
		PARITY_SPACE                 ///< Space parity
	}parityBit_t;

	/**
	 * @brief Structure containing line coding parameters requested by the host.
	 */
	typedef struct
	{
		uint32_t dwDTERate;          ///< Data terminal rate, in bits per second (Baudrate).
		stopBit_t bCharFormat;       ///< Stop bits.
		parityBit_t bParityType;     ///< Parity type.
		uint8_t bDataBits;           ///< Data bits (5, 6, 7, 8 or 16).
	}lineCoding_t  __attribute__ ((__packed__));
#pragma GCC diagnostic pop

	/**
	 * @brief USB CDC configuration structure.
	 */
	typedef struct 
	{
		const char *manufactureString;   ///< Manufacturer name string descriptor.
		const char *productString;       ///< Product name string descriptor.
		const char *serialNumberString;  ///< Device serial number string descriptor.
	}config_t;
	
	/**
	 * @brief Initializes the USB CDC device driver.
	 * @details Configures descriptors, endpoint parameters, and string values.
	 *
	 * @param[in] config Reference to the CDC configuration structure.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(const config_t &config) __attribute__((optimize("-O1")));

	/**
	 * @brief Transmits a data block to the host.
	 * @note Prior to transmission, isClearToSend() must be checked to confirm host connection.
	 *
	 * @param[in] src Pointer to the data transmit buffer.
	 * @param[in] size Size of the data block to send.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t send(void *src, uint32_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Transmits a const data block to the host.
	 * @note Prior to transmission, isClearToSend() must be checked to confirm host connection.
	 *
	 * @param[in] src Pointer to the constant data transmit buffer.
	 * @param[in] size Size of the data block to send.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t send(const void *src, uint32_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the size of received CDC data currently available in the buffer.
	 *
	 * @return uint32_t Number of bytes received from the host.
	 */
	uint32_t getRxDataCount(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Copies the received data into the user buffer.
	 *
	 * @param[out] des Pointer to the destination buffer.
	 * @param[in] size Size of the data to copy. Must be equal to the value returned by getRxDataCount().
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t getRxData(void *des, uint32_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Registers a callback function to handle host Line Coding changes.
	 *
	 * @param[in] func Pointer to the line coding callback handler function.
	 */
	void setCallbackLineCodeHandler(void (*func)(lineCoding_t lineCode)) __attribute__((optimize("-O1")));

	/**
	 * @brief Checks if the host is ready to receive data (CTS/DTE status).
	 * @details This function must return true before calling send().
	 *
	 * @return bool True if transmission is clear, false otherwise.
	 */
	bool isClearToSend(void) __attribute__((optimize("-O1")));

	// Internal system functions. Do not call from user application.
	Cdc(void) __attribute__((optimize("-O1")));

	virtual void handleWakeup(void) __attribute__((optimize("-O1")));

	virtual uint8_t getUsingEpCount(void) __attribute__((optimize("-O1")));

protected :
	config_t mConfig;
	lineCoding_t mLineCoding;
	void (*mCallback_handleLineCode)(lineCoding_t lineCode);
	uint8_t mIntInEpNum, mBulkInEpNum, mBulkOutEpNum;
	bool mDte, mRts;

	void getEmptyCsInterfaceDescriptor(csInterfaceDesc_t *des) __attribute__((optimize("-O1")));

private :
	virtual void handleSetConfiguration(uint16_t value) __attribute__((optimize("-O1")));

	virtual void handleClassSpecificRequest(void) __attribute__((optimize("-O1")));
};

#endif

/**
 * @example cdc_init_example
 * Refer to NuvotonCdc.h for subclass initialization details.
 */

/**
 * @example cdc_transmit_example
 * @code
 * if (cdc.isClearToSend())       // Verify host receiver state
 * {
 *     cdc.send(sendBuf, len);    // Transmit data block
 * }
 * @endcode
 */

/**
 * @example cdc_receive_example
 * @code
 * uint32_t len = cdc.getRxDataCount(); // Check if new data exists
 * if (len > 0)
 * {
 *     cdc.getRxData(rcvBuf, len);      // Copy received data to rcvBuf
 *     for (uint32_t i = 0; i < len; i++)
 *     {
 *         debug_printf("%c", rcvBuf[i]); // Print to debug console
 *     }
 * }
 * @endcode
 */
/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_DUAL_CDC__H_
#define YSS_USB_CLASS_DUAL_CDC__H_

#include "UsbClass.h"
#include <yss/error.h>

/**
 * @file DualCdc.h
 * @brief USB Dual Communications Device Class (Dual CDC) base driver class header file.
 */

/**
 * @class DualCdc
 * @brief Base class for USB Dual CDC virtual COM ports (two independent virtual COM port interfaces).
 *
 * @details
 * This class provides standard USB Dual CDC interfaces. It handles device descriptor setup,
 * two separate communications channels (Channel 0 and Channel 1) with independent send, receive,
 * check clear-to-send (CTS), and line coding callbacks.
 */
class DualCdc : public UsbClass
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
	 * @brief USB Dual CDC configuration structure.
	 */
	typedef struct 
	{
		const char *manufactureString;   ///< Manufacturer name string descriptor.
		const char *productString;       ///< Product name string descriptor.
		const char *serialNumberString;  ///< Device serial number string descriptor.
	}config_t;
	
	/**
	 * @brief Initializes the USB Dual CDC device driver.
	 * @details Configures descriptors, endpoint parameters, and string values.
	 *
	 * @param[in] config Reference to the CDC configuration structure.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(const config_t &config) __attribute__((optimize("-O1")));

	/**
	 * @brief Transmits a data block to the host on Channel 0.
	 * @note Prior to transmission, isClearToSend0() must be checked to confirm host connection.
	 *
	 * @param[in] src Pointer to the data transmit buffer.
	 * @param[in] size Size of the data block to send.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t send0(void *src, uint32_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Transmits a const data block to the host on Channel 0.
	 * @note Prior to transmission, isClearToSend0() must be checked to confirm host connection.
	 *
	 * @param[in] src Pointer to the constant data transmit buffer.
	 * @param[in] size Size of the data block to send.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t send0(const void *src, uint32_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Transmits a data block to the host on Channel 1.
	 * @note Prior to transmission, isClearToSend1() must be checked to confirm host connection.
	 *
	 * @param[in] src Pointer to the data transmit buffer.
	 * @param[in] size Size of the data block to send.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t send1(void *src, uint32_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Transmits a const data block to the host on Channel 1.
	 * @note Prior to transmission, isClearToSend1() must be checked to confirm host connection.
	 *
	 * @param[in] src Pointer to the constant data transmit buffer.
	 * @param[in] size Size of the data block to send.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t send1(const void *src, uint32_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the size of received data currently available on Channel 0.
	 *
	 * @return uint32_t Number of bytes received from the host.
	 */
	uint32_t getRxDataCount0(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the size of received data currently available on Channel 1.
	 *
	 * @return uint32_t Number of bytes received from the host.
	 */
	uint32_t getRxDataCount1(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Copies the received data on Channel 0 into the user buffer.
	 *
	 * @param[out] des Pointer to the destination buffer.
	 * @param[in] size Size of the data to copy. Must be equal to the value returned by getRxDataCount0().
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t getRxData0(void *des, uint32_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Copies the received data on Channel 1 into the user buffer.
	 *
	 * @param[out] des Pointer to the destination buffer.
	 * @param[in] size Size of the data to copy. Must be equal to the value returned by getRxDataCount1().
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t getRxData1(void *des, uint32_t size) __attribute__((optimize("-O1")));

	/**
	 * @brief Registers a callback function to handle host Line Coding changes on Channel 0.
	 *
	 * @param[in] func Pointer to the line coding callback handler function.
	 */
	void setCallbackLineCodeHandler0(void (*func)(lineCoding_t lineCode)) __attribute__((optimize("-O1")));

	/**
	 * @brief Registers a callback function to handle host Line Coding changes on Channel 1.
	 *
	 * @param[in] func Pointer to the line coding callback handler function.
	 */
	void setCallbackLineCodeHandler1(void (*func)(lineCoding_t lineCode)) __attribute__((optimize("-O1")));

	/**
	 * @brief Checks if the host is ready to receive data on Channel 0 (CTS/DTE status).
	 *
	 * @return bool True if transmission is clear, false otherwise.
	 */
	bool isClearToSend0(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Checks if the host is ready to receive data on Channel 1 (CTS/DTE status).
	 *
	 * @return bool True if transmission is clear, false otherwise.
	 */
	bool isClearToSend1(void) __attribute__((optimize("-O1")));

	// Internal system functions. Do not call from user application.
	DualCdc(void) __attribute__((optimize("-O1")));

	virtual void handleWakeup(void) __attribute__((optimize("-O1")));

	virtual uint8_t getUsingEpCount(void) __attribute__((optimize("-O1")));

protected :
	config_t mConfig;
	lineCoding_t mLineCoding0;
	lineCoding_t mLineCoding1;
	void (*mCallback_handleLineCode0)(lineCoding_t lineCode);
	void (*mCallback_handleLineCode1)(lineCoding_t lineCode);
	uint8_t mIntInEpNum0, mBulkInEpNum0, mBulkOutEpNum0;
	uint8_t mIntInEpNum1, mBulkInEpNum1, mBulkOutEpNum1;
	bool mDte0, mRts0;
	bool mDte1, mRts1;

	void getEmptyCsInterfaceDescriptor(csInterfaceDesc_t *des) __attribute__((optimize("-O1")));

private :
	virtual void handleSetConfiguration(uint16_t value) __attribute__((optimize("-O1")));

	virtual void handleClassSpecificRequest(void) __attribute__((optimize("-O1")));
};

#endif

/**
 * @example dual_cdc_init_example
 * Refer to NuvotonDualCdc.h for subclass initialization details.
 */

/**
 * @example dual_cdc_transmit_example
 * @code
 * if (dualCdc.isClearToSend0())
 * {
 *     dualCdc.send0(sendBuf, len); // Send data on Channel 0
 * }
 * @endcode
 */

/**
 * @example dual_cdc_receive_example
 * @code
 * uint32_t len = dualCdc.getRxDataCount0();
 * if (len > 0)
 * {
 *     dualCdc.getRxData0(rcvBuf, len); // Read data from Channel 0
 * }
 * @endcode
 */
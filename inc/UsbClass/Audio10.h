/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_AUDIO10__H_
#define YSS_USB_CLASS_AUDIO10__H_

#include "UsbClass.h"
#include <yss/error.h>

/**
 * @file Audio10.h
 * @brief USB Audio Class 1.0 base driver class header file.
 */

/**
 * @class Audio10
 * @brief Base class for USB Audio Class 1.0 devices.
 *
 * @details
 * This class provides standard USB Audio Class 1.0 setup and data handling interfaces.
 * It defines methods for initialization, receiving audio data streams, and managing audio
 * properties (e.g. volume control).
 */
class Audio10 : public UsbClass
{
public :
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"

#pragma GCC diagnostic pop

	/**
	 * @brief USB Audio Class configuration structure.
	 */
	typedef struct 
	{
		const char *manufactureString;   ///< Manufacturer name string descriptor.
		const char *productString;       ///< Product name string descriptor.
		const char *serialNumberString;  ///< Device serial number string descriptor.
	}config_t;
	
	/**
	 * @brief Initializes the USB Audio Class 1.0 device driver.
	 * @details Sets up descriptors, endpoints, and manufacturer/product identity strings.
	 *
	 * @param[in] config Reference to the Audio Class configuration structure.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(const config_t &config) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the size of received audio data currently available in the buffer.
	 *
	 * @return uint32_t Number of bytes received from the host.
	 */
	uint32_t getRxDataCount(void) __attribute__((optimize("-O1")));

	/**
	 * @brief Copies the received audio data into the user buffer.
	 *
	 * @param[out] des Pointer to the destination buffer to copy audio data.
	 * @param[in] size Size of the data to copy. Must be equal to the value returned by getRxDataCount().
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t getRxData(void *des, uint32_t size) __attribute__((optimize("-O1")));

	// Internal system functions. Do not call from user application.
	Audio10(void) __attribute__((optimize("-O1")));

	virtual void handleWakeup(void) __attribute__((optimize("-O1")));

	virtual uint8_t getUsingEpCount(void) __attribute__((optimize("-O1")));

protected :
	config_t mConfig;
	uint8_t mOutEpNum, mInEpNum;
	int32_t mVolumeLeft, mVolumeRight;

private :
};

/**
 * @example usb_audio_init_example
 * Refer to NuvotonAudio10.h for subclass initialization details.
 */

/**
 * @example usb_audio_recv_example
 * @code
 * uint32_t len = audio.getRxDataCount(); // Get the size of received audio data
 * if (len > 0)
 * {
 *     audio.getRxData(rcvBuf, len);      // Copy the received audio data into rcvBuf
 *     // Process the received audio stream in rcvBuf...
 * }
 * @endcode
 */
#endif


/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CAN_FD__H_
#define YSS_DRV_CAN_FD__H_

#include "Can.h"

/**
 * @file CanFd.h
 * @brief CAN FD (Controller Area Network Flexible Data-Rate) driver base class header file.
 */

/**
 * @enum dlc_t
 * @brief Enumeration representing the Data Length Code (DLC) for CAN FD.
 * @details CAN FD supports payload sizes up to 64 bytes using non-linear DLC values.
 */
typedef enum
{
	DLC_0BYTE = 0,   ///< 0 bytes of data payload
	DLC_1BYTE1,      ///< 1 byte of data payload
	DLC_2BYTES,      ///< 2 bytes of data payload
	DLC_3BYTES,      ///< 3 bytes of data payload
	DLC_4BYTES,      ///< 4 bytes of data payload
	DLC_5BYTES,      ///< 5 bytes of data payload
	DLC_6BYTES,      ///< 6 bytes of data payload
	DLC_7BYTES,      ///< 7 bytes of data payload
	DLC_8BYTES,      ///< 8 bytes of data payload
	DLC_12BYTES,     ///< 12 bytes of data payload
	DLC_16BYTES,     ///< 16 bytes of data payload
	DLC_20BYTES,     ///< 20 bytes of data payload
	DLC_24BYTES,     ///< 24 bytes of data payload
	DLC_32BYTES,     ///< 32 bytes of data payload
	DLC_48BYTES,     ///< 48 bytes of data payload
	DLC_64BYTES      ///< 64 bytes of data payload
}dlc_t;

/**
 * @struct canfdMsg_t
 * @brief Structure representing a CAN FD message frame.
 */
typedef struct 
{
	bool xtd;          ///< True if extended identifier (29-bit), false if standard identifier (11-bit).
	bool fdf;          ///< FD Format indicator. True if CAN FD format, false if Classic CAN.
	uint32_t id;       ///< CAN FD message identifier.
	dlc_t dlc;         ///< Data Length Code specifying payload size.
	uint8_t data[64];  ///< Data payload buffer (up to 64 bytes).
}canfdMsg_t;

/**
 * @class CanFd
 * @brief Base class for CAN FD (Controller Area Network Flexible Data-Rate) driver.
 * 
 * @details
 * This class inherits from `Can` and extends it to support the CAN FD protocol features, 
 * including dual baud rates (nominal and data phases) and larger data payloads up to 64 bytes.
 */
class CanFd : public Can
{
public :
	/**
	 * @brief Gets the configured data phase baudrate.
	 * 
	 * @return uint32_t The data phase baudrate in bps.
	 */
	virtual uint32_t getDataBuadrate(void) = 0;

	/**
	 * @brief Gets the configured data phase sample point ratio.
	 * 
	 * @return float The data phase sample point as a fraction (typically between 0.0 and 1.0, e.g., 0.875).
	 */
	virtual float getDataSamplePoint(void) = 0;

	/**
	 * @brief Sends a standard CAN FD message (11-bit identifier).
	 * 
	 * @param[in] id The 11-bit standard CAN identifier.
	 * @param[in] src Pointer to the data payload buffer to be sent.
	 * @param[in] dlc The Data Length Code specifying the size of the payload.
	 * @param[in] brs Bit Rate Switch flag. If true, switches to data phase baudrate.
	 */
	virtual void sendStdCanfdMessage(uint16_t id, uint8_t *src, dlc_t dlc, bool brs = true) = 0;

	/**
	 * @brief Sends an extended CAN FD message (29-bit identifier).
	 * 
	 * @param[in] id The 29-bit extended CAN identifier.
	 * @param[in] src Pointer to the data payload buffer to be sent.
	 * @param[in] dlc The Data Length Code specifying the size of the payload.
	 * @param[in] brs Bit Rate Switch flag. If true, switches to data phase baudrate.
	 */
	virtual void sendXtdCanfdMessage(uint32_t id, uint8_t *src, dlc_t dlc, bool brs = true) = 0;

	/**
	 * @brief Retrieves the next received CAN FD message from the RX buffer.
	 * 
	 * @return canfdMsg_t The received CAN FD message structure.
	 */
	virtual canfdMsg_t getNewRxCanfdMessage(void) = 0;

	/**
	 * @brief Constructor for the CanFd base class.
	 * 
	 * @param[in] drvSetup The base driver setup configuration.
	 */
	CanFd(const Drv::setup_t drvSetup);

protected :
	static const uint8_t mDlcTable[16]; ///< Table converting DLC codes to byte lengths.
};

#endif


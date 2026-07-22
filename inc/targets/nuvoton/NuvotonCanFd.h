/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_CAN__H_
#define YSS_DRV_NUVOTON_CAN__H_

#include <drv/CanFd.h>
#include <yss/error.h>

/**
 * @file NuvotonCanFd.h
 * @brief CAN FD (Controller Area Network Flexible Data-Rate) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonCanFd
 * @brief Driver class for the CAN FD peripheral on Nuvoton MCUs.
 *
 * @details
 * This class provides interface functions to configure, send, and receive CAN/CAN FD frames.
 * It inherits from the base CanFd class and supports standard/extended CAN messages as well
 * as CAN FD messages with optional Bit Rate Switching (BRS).
 */
class NuvotonCanFd : public CanFd
{
public:
	/**
	 * @brief Configuration structure for the CAN FD peripheral.
	 */
	typedef struct
	{
		uint8_t dbrp;			///< Data Bit Rate Prescaler (0 ~ 31)
		uint8_t dtseg1;			///< Data Time Segment 1 (0 ~ 31)
		uint8_t dtseg2;			///< Data Time Segment 2 (0 ~ 15)
		uint8_t dsjw;			///< Data Synchronization Jump Width (0 ~ 15)
		uint16_t nbrp;			///< Nominal Bit Rate Prescaler (0 ~ 511)
		uint8_t ntseg1;			///< Nominal Time Segment 1 (1 ~ 255)
		uint8_t ntseg2;			///< Nominal Time Segment 2 (1 ~ 127)
		uint8_t nsjw;			///< Nominal Synchronization Jump Width (0 ~ 127)
		bool fdOperaiton;		///< Enable CAN FD operation mode
		bool enableSilent;		///< Enable Silent mode for listen-only or testing
		bool enableLoopback;	///< Enable Loopback mode for self-testing
	}config_t;
	
	/**
	 * @brief Initializes the CAN FD device.
	 *
	 * @param[in] config Configuration settings for bit-timing and operating mode.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t initialize(config_t config);
	
	/**
	 * @brief Gets the configured nominal baudrate.
	 *
	 * @return uint32_t The nominal baudrate in bps.
	 */
	virtual uint32_t getBaudrate(void);

	/**
	 * @brief Gets the configured nominal sample point.
	 *
	 * @return float The nominal sample point ratio (e.g. 0.8f for 80%).
	 */
	virtual float getSamplePoint(void);

	/**
	 * @brief Gets the configured data baudrate (only applicable for CAN FD).
	 *
	 * @return uint32_t The data baudrate in bps.
	 */
	virtual uint32_t getDataBuadrate(void);

	/**
	 * @brief Gets the configured data sample point (only applicable for CAN FD).
	 *
	 * @return float The data sample point ratio.
	 */
	virtual float getDataSamplePoint(void);

	/**
	 * @brief Sends a standard CAN (11-bit ID) message.
	 *
	 * @param[in] id The standard 11-bit identifier.
	 * @param[in] src Pointer to the data payload buffer (up to 8 bytes).
	 * @param[in] dlc Data Length Code (0 to 8).
	 */
	virtual void sendStdCanMessage(uint16_t id, uint8_t *src, uint8_t dlc);

	/**
	 * @brief Sends an extended CAN (29-bit ID) message.
	 *
	 * @param[in] id The extended 29-bit identifier.
	 * @param[in] src Pointer to the data payload buffer (up to 8 bytes).
	 * @param[in] dlc Data Length Code (0 to 8).
	 */
	virtual void sendXtdCanMessage(uint32_t id, uint8_t *src, uint8_t dlc);

	/**
	 * @brief Sends a standard CAN FD (11-bit ID) message.
	 *
	 * @param[in] id The standard 11-bit identifier.
	 * @param[in] src Pointer to the data payload buffer (up to 64 bytes).
	 * @param[in] dlc Data Length Code (dlc_t enum value representing size up to 64).
	 * @param[in] brs Enable Bit Rate Switch (default is true).
	 */
	virtual void sendStdCanfdMessage(uint16_t id, uint8_t *src, dlc_t dlc, bool brs = true);

	/**
	 * @brief Sends an extended CAN FD (29-bit ID) message.
	 *
	 * @param[in] id The extended 29-bit identifier.
	 * @param[in] src Pointer to the data payload buffer (up to 64 bytes).
	 * @param[in] dlc Data Length Code (dlc_t enum value representing size up to 64).
	 * @param[in] brs Enable Bit Rate Switch (default is true).
	 */
	virtual void sendXtdCanfdMessage(uint32_t id, uint8_t *src, dlc_t dlc, bool brs = true);

	/**
	 * @brief Checks if a new received message is available in the buffer.
	 *
	 * @return bool True if a new message exists, false otherwise.
	 */
	virtual bool isNewRxMessage(void);

	/**
	 * @brief Retrieves a standard/extended CAN message from the receive queue.
	 *
	 * @return canMsg_t The received CAN message structure.
	 */
	virtual canMsg_t getNewRxCanMessage(void);

	/**
	 * @brief Retrieves a CAN FD message from the receive queue.
	 *
	 * @return canfdMsg_t The received CAN FD message structure.
	 */
	virtual canfdMsg_t getNewRxCanfdMessage(void);

	// Internal system functions. Do not call from user application.
	struct setup_t
	{
		CANFD_T *dev;
	};
	
	// Receive interrupt service routine.
	void isr0(void);
	
	// Error interrupt service routine.
	void isr1(void);

	NuvotonCanFd(const Drv::setup_t drvSetup, const setup_t setup);

private :
	typedef struct
	{
		uint8_t stdFilterCount;
		uint8_t extFilterCount;
		uint8_t rxFifoCount0;
		uint8_t rxFifoCount1;
		uint8_t rxBufferCount;
		uint8_t txEventFifo;
		uint8_t txFifoCount;
		uint8_t txBufferCount;
	}malloc_t;

	typedef struct
	{
		uint32_t id : 29;
		uint32_t rtr : 1;
		uint32_t xtd : 1;
		uint32_t esi : 1;
		uint32_t rxts : 16;
		uint32_t dlc : 4;
		uint32_t brs : 1;
		uint32_t fdf : 1;
		uint32_t rsv : 2;
		uint32_t fidx : 7;
		uint32_t anmf : 1;
		uint8_t data[64];
	}rxBuffer_t;
	
	typedef struct
	{
		uint32_t id : 29;
		uint32_t rtr : 1;
		uint32_t xtd : 1;
		uint32_t esi : 1;
		uint32_t rsv0 : 8;
		uint32_t mm0 : 8;
		uint32_t dlc : 4;
		uint32_t brs : 1;
		uint32_t fdf : 1;
		uint32_t rsv1 : 1;
		uint32_t efc : 1;
		uint32_t mm1 : 8;
		uint8_t data[64];
	}txBuffer_t;
	
	typedef struct
	{
		uint32_t sfid2 : 11;
		uint32_t rsv : 5;
		uint32_t sfid1 : 11;
		uint32_t sfec : 3;
		uint32_t sft : 2;
	}stdFilter_t;

	typedef struct
	{
		uint32_t sfid2 : 11;
		uint32_t rsv : 5;
		uint32_t sfid1 : 11;
		uint32_t sfec : 3;
		uint32_t sft : 2;
	}extFilter_t;

	CANFD_T *mDev;
	rxBuffer_t *mRxFifo0;
	rxBuffer_t *mRxBuffer;
	txBuffer_t *mTxFifo;
	stdFilter_t *mStdFilter;
	extFilter_t *mExtFilter;
	uint32_t mHead, mTail, mRxBufferDepth;
};

#endif



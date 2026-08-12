/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_SDMMC__H_
#define YSS_DRV_SDMMC__H_

#include "Drv.h"
#include <yss/error.h>
#include <util/ElapsedTime.h>
#include <drv/Gpio.h>
#include <hal/MassStorage.h>

/**
 * @file Sdmmc.h
 * @brief SD/MMC peripheral driver class header file.
 *
 * ### Initialization Flow
 * 1. Configure the GPIO pins related to the SDMMC peripheral (CLK, CMD, D0 to D3/D7) as alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Configure card detect pin using `setDetectPin()` if present.
 * 3. Supply clock to the peripheral using `enableClock()`.
 * 4. Initialize the driver using `initialize()`.
 * 5. Attempt card connection using `connect()`.
 *
 * ### Initialization Example
 * @code
 * // Configure target pins for SDMMC function
 * gpioC.setAsAltFunc(8, Gpio::PC8_SDMMC1_D0);
 * gpioC.setAsAltFunc(9, Gpio::PC9_SDMMC1_D1);
 * gpioC.setAsAltFunc(10, Gpio::PC10_SDMMC1_D2);
 * gpioC.setAsAltFunc(11, Gpio::PC11_SDMMC1_D3);
 * gpioC.setAsAltFunc(12, Gpio::PC12_SDMMC1_CK);
 * gpioD.setAsAltFunc(2, Gpio::PD2_SDMMC1_CMD);
 * 
 * sdmmc.setDetectPin(pin::gpio::GPIOC_13, true); // Active High detect
 * 
 * sdmmc.enableClock(); // Supply clock
 * sdmmc.initialize();  // Initialize driver
 * 
 * if (sdmmc.connect() == error_t::ERROR_NONE)
 * {
 *     // Card connected successfully
 * }
 * @endcode
 *
 * ### Mass Storage Interface
 * - The Sdmmc class implements the `MassStorage` virtual interface class.
 * - Once connected, it can be passed to FAT file system middleware or read/written directly using `read()` and `write()` block APIs (512-byte blocks).
 *
 * ### Read/Write Block Example
 * @code
 * uint8_t buffer[512];
 * 
 * // Read block index 100
 * if (sdmmc.read(100, buffer) == error_t::ERROR_NONE)
 * {
 *     // Process buffer content
 *     
 *     // Write modified buffer content back to block index 100
 *     sdmmc.write(100, buffer);
 * }
 * @endcode
 */

/**
 * @class Sdmmc
 * @brief Driver class for the SD/MMC peripheral interface.
 */
class Sdmmc : public Drv, public MassStorage
{
public :
	typedef enum
	{
		BLOCK_1_BYTE = 0,
		BLOCK_2_BYTES = 1,
		BLOCK_4_BYTES = 2,
		BLOCK_8_BYTES = 3,
		BLOCK_16_BYTES = 4,
		BLOCK_32_BYTES = 5,
		BLOCK_64_BYTES = 6,
		BLOCK_128_BYTES = 7,
		BLOCK_256_BYTES = 8,
		BLOCK_512_BYTES = 9,
		BLOCK_1024_BYTES = 10,
		BLOCK_2048_BYTES = 11,
		BLOCK_4096_BYTES = 12,
		BLOCK_8192_BYTES = 13,
		BLOCK_16384_BYTES = 14,
	}blockSize_t;

	typedef enum
	{
		BUS_WIDTH_1BIT = 0,
		BUS_WIDTH_4BIT = 1,
		BUS_WIDTH_8BIT = 2,
	}busWidth_t;

	/**
	 * @brief Enumeration for SD/MMC command response types.
	 *
	 * @details
	 * Specifies the response format expected from the card after a command is issued.
	 * The response type determines how the host reads and validates the card's reply.
	 */
	typedef enum
	{
		RESPONSE_NO_R = 0, ///< No response. The card does not reply to this command.
		RESPONSE_R1,       ///< R1: 48-bit normal response. Contains the card status register.
		RESPONSE_R1b,      ///< R1b: Same as R1 with an optional busy signal on the data line (indicates ongoing operation).
		RESPONSE_R2,       ///< R2: 136-bit long response. Contains the CID or CSD register contents.
		RESPONSE_R3,       ///< R3: 48-bit response. Contains the OCR (Operating Condition Register) in response to ACMD41.
		RESPONSE_R6,       ///< R6: 48-bit published RCA (Relative Card Address) response. Returned by CMD3.
		RESPONSE_R7,       ///< R7: 48-bit card interface condition response. Returned by CMD8 to verify voltage compatibility.
	}response_t;

	typedef enum
	{
		CMD0_GO_IDLE_STATE = 0,
		CMD1_SEND_OP_COND,
		CMD2_ALL_SEND_CID,
		CMD3_SET_RELATIVE_ADDR,
		CMD4_SET_DSR,
		CMD5_SD_APP_OP_COND,
		CMD6_SWITCH,
		CMD7_SELECT_DESELECT_CARD,
		CMD8_SEND_IF_COND,
		CMD9_SEND_CSD,
		CMD10_SEND_CID,
		CMD12_STOP_TRANSMISSION = 12,
		CMD13_SEND_STATUS,
		CMD16_SET_BLOCKLEN = 16,
		CMD17_READ_SINGLE_BLOCK,
		CMD18_READ_MULTIPLE_BLOCK,
		CMD23_SET_BLOCK_COUNT = 23,
		CMD24_WRITE_BLOCK,
		CMD25_WRITE_MULTIPLE_BLOCK,
		CMD32_ERASE_WR_BLK_START = 32,
		CMD33_ERASE_WR_BLK_END,
		CMD38_ERASE = 38,
		CMD52_IO_RW_DIRECT = 52,
		CMD53_IO_RW_EXTENDED,
		CMD55_APP_CMD = 55,
		CMD58_READ_OCR = 58,
		CMD59_CRC_ON_OFF
	}cmd_t;

	typedef enum
	{
		ACMD6_SET_BUS_WIDTH = 6,
		ACMD13_SD_STATUS = 13,
		ACMD23_SET_WR_BLK_ERASE_COUNT = 23,
		ACMD41_SD_APP_OP_COND = 41,
		ACMD51_SEND_SCR = 51
	}acmd_t;

	/**
	 * @brief Constructor for the Sdmmc class.
	 *
	 * @param[in] drvConfig Reference to the base driver setup configuration.
	 */
	Sdmmc(const Drv::setup_t &drvConfig);

	/**
	 * @brief Initializes the SDMMC peripheral hardware.
	 *
	 * @details
	 * Configures the SDMMC peripheral clocks, GPIO, and internal DMA.
	 * Must be called before any card operations (connect, read, write).
	 *
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t initialize(void) = 0;

	/**
	 * @brief Checks whether a card is physically detected in the slot.
	 *
	 * @details
	 * Reads the card detect GPIO pin (configured by `setDetectPin()`) and
	 * returns true if a card is present. If no detect pin is configured,
	 * this function always returns true.
	 *
	 * @return bool True if a card is detected, false otherwise.
	 */
	bool isDetected(void);

	/**
	 * @brief Configures the card detect GPIO pin and its active polarity.
	 *
	 * @param[in] pin             GPIO pin identifier used for card detection.
	 * @param[in] detectPolarity  If true, card is present when the pin is High;
	 *                            if false, card is present when the pin is Low.
	 */
	void setDetectPin(pin_t pin, bool detectPolarity = false);

	/**
	 * @brief Checks whether a card is currently connected and initialized.
	 *
	 * @return bool True if a card has been successfully connected, false otherwise.
	 */
	bool isConnected(void);

	/**
	 * @brief Initiates the SD/MMC card initialization and identification sequence.
	 *
	 * @details
	 * Performs the full SD/MMC initialization protocol: power-on, CMD0 reset,
	 * CMD8 voltage check, ACMD41 initialization loop, CMD2 CID read, CMD3
	 * RCA assignment, CMD9 CSD read, CMD7 select, and optional bus width switch.
	 * After a successful call, the card is ready for read/write operations.
	 *
	 * @return error_t Returns ERROR_NONE on successful card initialization.
	 */
	error_t connect(void);

	/**
	 * @brief Disconnects the card and powers down the SDMMC peripheral.
	 *
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t disconnect(void);

	/**
	 * @brief Sets the supply voltage level for the SDMMC interface.
	 *
	 * @details
	 * Informs the driver of the actual SDMMC interface supply voltage (in volts).
	 * This is used to select the appropriate OCR voltage window during
	 * card initialization (e.g. 3.3 V for standard SD, 1.8 V for UHS-I).
	 *
	 * @param[in] vcc Supply voltage in volts (e.g. 3.3f).
	 */
	void setVcc(float vcc);

	/**
	 * @brief Gets the block size of the connected card.
	 *
	 * @details
	 * Returns the fixed block (sector) size in bytes of the connected SD/MMC card.
	 * For SDHC/SDXC cards this is always 512 bytes.
	 *
	 * @return uint32_t Block size in bytes.
	 */
	virtual uint32_t getBlockSize(void);

	/**
	 * @brief Gets the total number of blocks (sectors) on the connected card.
	 *
	 * @details
	 * Returns the maximum logical block address (LBA) supported by the card.
	 * Total capacity = `getNumOfBlock()` × `getBlockSize()` bytes.
	 *
	 * @return uint32_t Total number of blocks.
	 */
	virtual uint32_t getNumOfBlock(void);

	/**
	 * @brief Writes a single 512-byte block to the card.
	 *
	 * @details
	 * Sends CMD24 (WRITE_BLOCK) to write a 512-byte sector from the `src`
	 * buffer to the specified block address. Blocks the calling thread until
	 * the write operation completes or a timeout occurs.
	 *
	 * @param[in] block Block (sector) address to write to.
	 * @param[in] src   Pointer to the 512-byte source data buffer.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t write(uint32_t block, void *src); 

	/**
	 * @brief Reads a single 512-byte block from the card.
	 *
	 * @details
	 * Sends CMD17 (READ_SINGLE_BLOCK) to read a 512-byte sector from the
	 * specified block address into the `des` buffer. Blocks the calling
	 * thread until the read operation completes or a timeout occurs.
	 *
	 * @param[in]  block Block (sector) address to read from.
	 * @param[out] des   Pointer to the 512-byte destination data buffer.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	virtual error_t read(uint32_t block, void *des);

protected:
	uint32_t mRca, mMaxBlockAddr, mReadBlockLen;
	uint8_t mLastResponseCmd;

	virtual error_t sendPowerOn74Clock(void) = 0;
	
	virtual error_t sendCmd(cmd_t cmd, uint32_t arg, response_t responseType) = 0;

	virtual uint32_t getShortResponse(void) = 0;

	virtual void getLongResponse(void *des) = 0;

	virtual void setClockFrequency(int32_t  frequency) = 0;

	virtual void setSdioClockEn(bool en) = 0;

	virtual void enablePower(bool en = true) = 0;

	virtual void readyRead(void *des, uint16_t length) = 0;

	virtual void stopReadyRead(void) = 0;

	virtual void readyWrite(void *src, uint16_t length) = 0;

	virtual void setDataBlockSize(uint16_t blockSize) = 0;

	virtual error_t waitUntilReadComplete(void) = 0;

	virtual error_t waitUntilWriteComplete(void) = 0;

	virtual bool setBusWidth(busWidth_t width) = 0;

private :
	typedef struct
	{
		uint32_t reserved1 : 3;			// 0~2
		uint32_t akeSeqError : 1;		// 3
		uint32_t reserved2 : 1;			// 4
		uint32_t appCmd : 1;			// 5
		uint32_t fxEvent : 1;			// 6
		uint32_t reserved3 : 1;			// 7
		uint32_t readyForData : 1;		// 8
		uint32_t currentState : 4;		// 9~12
		uint32_t eraseReset : 1;		// 13
		uint32_t cardEccDisabled : 1;	// 14
		uint32_t wpEraseSkip : 1;		// 15
		uint32_t csdOverwrite : 1;		// 16
		uint32_t reserved4 : 2;			// 17~18
		uint32_t error_t : 1;				// 19
		uint32_t ccError : 1;			// 20
		uint32_t cardEccFaield : 1;		// 21
		uint32_t illegalCommand: 1;		// 22
		uint32_t comCrcError : 1;		// 23
		uint32_t lockUnlockFailed : 1;	// 24
		uint32_t cardIsLocked : 1;		// 25
		uint32_t wpViolation : 1;		// 26
		uint32_t eraseParm : 1;			// 27
		uint32_t eraseSeqError : 1;		// 28
		uint32_t blockLenError : 1;		// 29
		uint32_t addressError : 1;		// 30
		uint32_t outOfRange : 1;		// 31
	}cardStatus_t;

	typedef struct
	{
		uint32_t reserved1 : 15;				// 0~14
		uint32_t voltage_2_7v_2_8v : 1;			// 15
		uint32_t voltage_2_8v_2_9v : 1;			// 16
		uint32_t voltage_2_9v_3_0v : 1;			// 17
		uint32_t voltage_3_0v_3_1v : 1;			// 18
		uint32_t voltage_3_1v_3_2v : 1;			// 19
		uint32_t voltage_3_2v_3_3v : 1;			// 20
		uint32_t voltage_3_3v_3_4v : 4;			// 21
		uint32_t voltage_3_4v_3_5v : 1;			// 22
		uint32_t voltage_3_5v_3_6v : 1;			// 23
		uint32_t swichingTo_1_8vAccepted : 1;	// 24
		uint32_t reserved2 : 2;					// 25~26
		uint32_t over2TbSupportStatus : 1;		// 27
		uint32_t reserved3 : 1;					// 28
		uint32_t uhs2CardStatus : 1;			// 29
		uint32_t cardPapacityStatus : 1;		// 30
		uint32_t cardPowerUpStatus : 1;			// 31
	}ocrRegister_t;

	ElapsedTime mLastWriteTime, mLastReadTime;
	bool mConnectedFlag, mHcsFlag, mDetectPolarity;
	float mVcc;
	triggerId_t mTriggerId;
	pin_t mDetectPin;

	error_t sendAcmd(acmd_t cmd, uint32_t arg, response_t responseType);

	cardStatus_t getCardStatus(void);

	error_t select(bool en);
};

#endif


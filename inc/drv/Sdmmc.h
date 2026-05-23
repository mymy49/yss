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

	typedef enum
	{
		RESPONSE_NO_R = 0,	// No Response
		RESPONSE_R1,		// normal response command.
		RESPONSE_R1b,		// R1b is identical to R1 with an optional busy signal transmitted on the data line.
		RESPONSE_R2,		// Code length is 136 bits. The contents of the CID register are sent as a response to the commands CMD2 and CMD10.
		RESPONSE_R3,		// Code length is 48 bits. The contents of the OCR register are sent as a response to ACMD41.
		RESPONSE_R6,		// Code length is 48 bit. The bits 45:40 indicate the index of the command to be responded to - in that case, it will be '000011' (together with bit 5 in the status bits it means = CMD3).
		RESPONSE_R7,		// Card interface condition, Code length is 48 bits.
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

	Sdmmc(const Drv::setup_t &drvConfig);

	virtual error_t initialize(void) = 0;

	bool isDetected(void);

	void setDetectPin(pin_t pin, bool detectPolarity = false);

	bool isConnected(void);

	error_t connect(void);

	error_t disconnect(void);

	void setVcc(float vcc);

	virtual uint32_t getBlockSize(void);

	virtual uint32_t getNumOfBlock(void);

	virtual error_t write(uint32_t block, void *src); 

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


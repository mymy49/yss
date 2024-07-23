/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_SD_MEMORY__H_
#define YSS_SAC_SD_MEMORY__H_

#include "MassStorage.h"
#include <util/ElapsedTime.h>
#include <yss/error.h>
#include <yss/thread.h>
#include <drv/Gpio.h>

namespace sac
{
class SdMemory : public MassStorage
{
public:
	enum
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

		BUS_WIDTH_1BIT = 0,
		BUS_WIDTH_4BIT = 1,
		BUS_WIDTH_8BIT = 2,
		
		ERROR_NONE = 0,
		ERROR_CMD_TIMEOUT,
		ERROR_CMD_CRC,
		ERROR_DATA_TIMEOUT,
		ERROR_DATA_CRC,
		ERROR_RESPONSE_CMD,
		ERROR_NOT_READY,

		RESPONSE_NONE = 0,
		RESPONSE_SHORT,
		RESPONSE_LONG,
	};

	SdMemory(void);

	// 소멸자를 호출할 일이 없으므로 소멸자는 생략
	
	error_t connect(void);

	error_t disconnect(void);

	void setVcc(float vcc);

	bool isConnected(void);

	bool isDetected(void);

	uint32_t getBlockSize(void);

	uint32_t getNumOfBlock(void);

	error_t write(uint32_t block, void *src);

	error_t read(uint32_t block, void *des);

	void setDetectPin(pin_t pin, bool autoConnect = false, bool detectPolarity = false);

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
	}CardStatus_t;

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
	}OcrRegister_t;

	ElapsedTime mLastWriteTime, mLastReadTime;
	bool mConnectedFlag, mHcsFlag;
	float mVcc;

	error_t sendAcmd(uint8_t cmd, uint32_t arg, uint8_t responseType);

	CardStatus_t getCardStatus(void);

	error_t select(bool en);

protected:
	uint32_t mRca, mMaxBlockAddr, mReadBlockLen;
	uint8_t mLastResponseCmd;
	
	virtual error_t sendCmd(uint8_t cmd, uint32_t arg, uint8_t responseType) = 0;

	virtual uint32_t getShortResponse(void) = 0;

	virtual void getLongResponse(void *des) = 0;

	virtual void setClockFrequency(int32_t  frequency) = 0;

	virtual void setSdioClockEn(bool en) = 0;

	virtual void enablePower(bool en = true) = 0;

	virtual void readyRead(void *des, uint16_t length) = 0;

	virtual void stopReadyRead(void) = 0;

	virtual void readyWrite(void *src, uint16_t length) = 0;

	virtual void setDataBlockSize(uint8_t blockSize) = 0;

	virtual error_t waitUntilReadComplete(void) = 0;

	virtual error_t waitUntilWriteComplete(void) = 0;

	virtual bool setBusWidth(uint8_t width) = 0;

	virtual void unlockRead(void) = 0;

	virtual void unlockWrite(void) = 0;

private :
	triggerId_t mTriggerId;
	pin_t mDetectPin;
	bool mDetectPolarity;
};
}

#endif

// 해결해야 할 숙제
//	- SD 메모리 전송 타이밍을 읽어서 적용 시키는 작업


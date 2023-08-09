////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_SAC_SD_MEMORY__H_
#define YSS_SAC_SD_MEMORY__H_

#include "MassStorage.h"
#include <util/ElapsedTime.h>
#include <yss/error.h>

namespace sac
{
class SdMemory : public MassStorage
{
	struct CardStatus
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
		uint32_t error : 1;				// 19
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
	};

	struct OcrRegister
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
	};

	bool mConnectedFlag, mHcsFlag;
	float mVcc;

	error sendAcmd(uint8_t cmd, uint32_t arg, uint8_t responseType);
	CardStatus getCardStatus(void);
	error select(bool en);
	ElapsedTime mLastWriteTime, mLastReadTime;

  protected:
	uint32_t mRca, mMaxBlockAddr, mReadBlockLen;
	uint8_t mLastResponseCmd;
	
	virtual error sendCmd(uint8_t cmd, uint32_t arg, uint8_t responseType) = 0;
	virtual uint32_t getShortResponse(void) = 0;
	virtual void getLongResponse(void *des) = 0;
	virtual void setClockFrequency(int32_t  frequency) = 0;
	virtual void setSdioClockEn(bool en) = 0;
	virtual void setPower(bool en) = 0;
	virtual void readyRead(void *des, uint16_t length) = 0;
	virtual void readyWrite(void *src, uint16_t length) = 0;
	virtual void setDataBlockSize(uint8_t blockSize) = 0;
	virtual error waitUntilReadComplete(void) = 0;
	virtual error waitUntilWriteComplete(void) = 0;
	virtual bool setBusWidth(uint8_t width) = 0;
	virtual void unlockRead(void) = 0;
	virtual void unlockWrite(void) = 0;

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
	
	error connect(void);
	void disconnect(void);

	void setVcc(float vcc);
	bool isConnected(void);

	uint32_t getBlockSize(void);
	uint32_t getNumOfBlock(void);

	error write(uint32_t block, void *src);
	error read(uint32_t block, void *des);

};
}

#endif

// 해결해야 할 숙제
//	- SD 메모리 전송 타이밍을 읽어서 적용 시키는 작업


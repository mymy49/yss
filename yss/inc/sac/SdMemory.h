////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_SAC_SD_MEMORY__H_
#define YSS_SAC_SD_MEMORY__H_

#include <drv/Gpio.h>
#include "MassStorage.h"
#include <util/ElapsedTime.h>
#include <yss/error.h>

namespace sac
{
class SdMemory : public MassStorage
{
	struct CardStatus
	{
		unsigned int reserved1 : 3;			// 0~2
		unsigned int akeSeqError : 1;		// 3
		unsigned int reserved2 : 1;			// 4
		unsigned int appCmd : 1;			// 5
		unsigned int fxEvent : 1;			// 6
		unsigned int reserved3 : 1;			// 7
		unsigned int readyForData : 1;		// 8
		unsigned int currentState : 4;		// 9~12
		unsigned int eraseReset : 1;		// 13
		unsigned int cardEccDisabled : 1;	// 14
		unsigned int wpEraseSkip : 1;		// 15
		unsigned int csdOverwrite : 1;		// 16
		unsigned int reserved4 : 2;			// 17~18
		unsigned int error : 1;				// 19
		unsigned int ccError : 1;			// 20
		unsigned int cardEccFaield : 1;		// 21
		unsigned int illegalCommand: 1;		// 22
		unsigned int comCrcError : 1;		// 23
		unsigned int lockUnlockFailed : 1;	// 24
		unsigned int cardIsLocked : 1;		// 25
		unsigned int wpViolation : 1;		// 26
		unsigned int eraseParm : 1;			// 27
		unsigned int eraseSeqError : 1;		// 28
		unsigned int blockLenError : 1;		// 29
		unsigned int addressError : 1;		// 30
		unsigned int outOfRange : 1;		// 31
	};

	struct OcrRegister
	{
		unsigned int reserved1 : 15;				// 0~14
		unsigned int voltage_2_7v_2_8v : 1;			// 15
		unsigned int voltage_2_8v_2_9v : 1;			// 16
		unsigned int voltage_2_9v_3_0v : 1;			// 17
		unsigned int voltage_3_0v_3_1v : 1;			// 18
		unsigned int voltage_3_1v_3_2v : 1;			// 19
		unsigned int voltage_3_2v_3_3v : 1;			// 20
		unsigned int voltage_3_3v_3_4v : 4;			// 21
		unsigned int voltage_3_4v_3_5v : 1;			// 22
		unsigned int voltage_3_5v_3_6v : 1;			// 23
		unsigned int swichingTo_1_8vAccepted : 1;	// 24
		unsigned int reserved2 : 2;					// 25~26
		unsigned int over2TbSupportStatus : 1;		// 27
		unsigned int reserved3 : 1;					// 28
		unsigned int uhs2CardStatus : 1;			// 29
		unsigned int cardPapacityStatus : 1;		// 30
		unsigned int cardPowerUpStatus : 1;			// 31
	};

	drv::Gpio::Pin mDetectPin;

	bool mAbleFlag, mHcsFlag;
	float mVcc;

	error sendAcmd(unsigned char cmd, unsigned int arg, unsigned char responseType);
	CardStatus getCardStatus(void);
	error select(bool en);
	ElapsedTime mLastWriteTime, mLastReadTime;

  protected:
	unsigned int mRca, mAuSize, mMaxBlockAddr, mReadBlockLen;
	unsigned char mLastResponseCmd;
	
	virtual error sendCmd(unsigned char cmd, unsigned int arg, unsigned char responseType) = 0;
	virtual unsigned int getShortResponse(void) = 0;
	virtual void getLongResponse(void *des) = 0;
	virtual void setSdioClockBypass(bool en) = 0;
	virtual void setSdioClockEn(bool en) = 0;
	virtual void setPower(bool en) = 0;
	virtual void readyRead(void *des, unsigned short length) = 0;
	virtual void readyWrite(void *src, unsigned short length) = 0;
	virtual void setDataBlockSize(unsigned char blockSize) = 0;
	virtual error waitUntilReadComplete(void) = 0;
	virtual error waitUntilWriteComplete(void) = 0;
	virtual bool setBusWidth(unsigned char width) = 0;
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
	
	void start(void);
	bool connect(void);
	void setDetectPin(drv::Gpio::Pin pin);
	void setVcc(float vcc);
	void isrDetection(void);
	bool isConnected(void);

	unsigned int getBlockSize(void);
	unsigned int getNumOfBlock(void);

	error write(unsigned int block, void *src);
	error read(unsigned int block, void *des);

};
}

#endif

// 해결해야 할 숙제
//	- SD 메모리 전송 타이밍을 읽어서 적용 시키는 작업


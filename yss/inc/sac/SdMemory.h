////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_SAC_SD_MEMORY__H_
#define YSS_SAC_SD_MEMORY__H_

#include <drv/Gpio.h>

namespace sac
{
class SdMemory
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
	void (*mDetectionIsr)(bool detect);

  protected:
	unsigned int mRca;
	unsigned char mBlockSize;
	
	virtual bool sendCmd(unsigned char cmd, unsigned int arg) = 0;
	virtual bool sendAcmd(unsigned char cmd, unsigned int arg) = 0;
	virtual unsigned int getResponse1(void) = 0;
	virtual unsigned int getResponse2(void) = 0;
	virtual unsigned int getResponse3(void) = 0;
	virtual unsigned int getResponse4(void) = 0;
	virtual void setSdioClockBypass(bool en) = 0;
	virtual void setSdioClockEn(bool en) = 0;
	virtual void setPower(bool en) = 0;
	virtual void readyRead(void *des, unsigned short length) = 0;
	virtual void setDataBlockSize(unsigned char blockSize) = 0;

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
	};

	SdMemory(void);
	
	void start(void);
	bool connect(void);
	void setDetectPin(drv::Gpio::Pin pin);
	void setVcc(float vcc);
	CardStatus getCardStatus(void);
	void setDetectionIsr(void (*isr)(bool detect));
	void isrDetection(void);
	bool isConnected(void);
	
};
}

#endif
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
	drv::Gpio::Pin mDetectPin;

	bool mAbleFlag, mHcsFlag;
	float mVcc;
	void (*mDetectionIsr)(bool detect);
  protected:
	unsigned int mRca;
	
  public:
	SdMemory(void);
	
	void start(void);
	bool connect(void);
	void setDetectPin(drv::Gpio::Pin pin);
	void setVcc(float vcc);
	CardStatus getCardStatus(void);
	void setDetectionIsr(void (*isr)(bool detect));
	void isrDetection(void);
	bool isConnected(void);

	virtual bool sendCmd(unsigned char cmd, unsigned int arg) = 0;
	virtual bool sendAcmd(unsigned char cmd, unsigned int arg) = 0;
	virtual unsigned int getResponse1(void) = 0;
	virtual unsigned int getResponse2(void) = 0;
	virtual unsigned int getResponse3(void) = 0;
	virtual unsigned int getResponse4(void) = 0;
	virtual void setSdioClockBypass(bool en) = 0;
	virtual void setSdioClockEn(bool en) = 0;
	virtual void setPower(bool en) = 0;
};
}

#endif
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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>
#include <sac/SdMemory.h>
#include <yss/thread.h>
#include <yss/instance.h>
#include <__cross_studio_io.h>

#define SD_IDLE 0
#define SD_READY 1
#define SD_IDENT 2
#define SD_STBY 3
#define SD_TRANS 4
#define SD_DATA 5
#define SD_RCA 6
#define SD_PRG 7
#define SD_DIS 8

namespace sac
{
void trigger_handleSdmmcDetection(void *var);

SdMemory::SdMemory(void)
{
	mDetectionIsr = 0;
	mAbleFlag = false;
	mVcc = 3.3;
	mRca = 0;
	mDetectPin.port = 0;
	mDetectPin.pin = 0;
}

void SdMemory::setVcc(float vcc)
{
	mVcc = vcc;
}

#define POWER_2_7__2_8 (1 << 15)
#define POWER_2_8__2_9 (1 << 16)
#define POWER_2_9__3_0 (1 << 17)
#define POWER_3_0__3_1 (1 << 18)
#define POWER_3_1__3_2 (1 << 19)
#define POWER_3_2__3_3 (1 << 20)
#define POWER_3_3__3_4 (1 << 21)
#define POWER_3_4__3_5 (1 << 22)
#define POWER_3_5__3_6 (1 << 23)

inline unsigned int getOcr(float vcc)
{
	unsigned long ocr = 0;

	if ((float)2.7 <= vcc && (float)2.8 <= vcc)
		ocr = POWER_2_7__2_8;
	else if ((float)2.8 <= vcc && (float)2.9 <= vcc)
		ocr = POWER_2_8__2_9;
	else if ((float)2.9 <= vcc && (float)3.0 <= vcc)
		ocr = POWER_2_9__3_0;
	else if ((float)3.0 <= vcc && (float)3.1 <= vcc)
		ocr = POWER_3_0__3_1;
	else if ((float)3.1 <= vcc && (float)3.2 <= vcc)
		ocr = POWER_3_1__3_2;
	else if ((float)3.2 <= vcc && (float)3.3 <= vcc)
		ocr = POWER_3_2__3_3;
	else if ((float)3.3 <= vcc && (float)3.4 <= vcc)
		ocr = POWER_3_3__3_4;
	else if ((float)3.4 <= vcc && (float)3.5 <= vcc)
		ocr = POWER_3_4__3_5;
	else if ((float)3.5 <= vcc && (float)3.6 <= vcc)
		ocr = POWER_3_5__3_6;

	return ocr;
}

bool SdMemory::connect(void)
{
	unsigned int ocr = 0x40000000;
	CardStatus sts;
	unsigned char *buf = new unsigned char[512];
	
	setSdioClockBypass(false);
	setSdioClockEn(true);

	// CMD0 (SD메모리 리셋)
	if (sendCmd(0, 0) == false)
		goto error;

	// CMD8 (SD메모리가 SD ver 2.0을 지원하는지 확인)
	if (sendCmd(8, 0x000001AA) == false) // 2.7V ~ 3.6V 동작 설정
		goto error;
	if (getResponse1() != 0x000001AA)
		goto error;

	// ACMD41
	// 지원하는 전원을 확인
	if (sendAcmd(41, 0) == false)
	{
		// 실패시 현제 장치는 MMC
		goto error;
	}

	// SD메모리에 공급되는 전원에 대한 비트를 얻어옴
	ocr = getOcr(mVcc);

	// 현재 공급되는 전원과 카드가 지원하는 전원을 비교
	if ((getResponse1() & ocr) == 0)
		goto error;
	
	// 카드에서 HCS를 지원하는지 확인
	if (getResponse1() & 0x40000000)
	{
		mHcsFlag = true;
	}
	else
		mHcsFlag = false;

	// 카드의 초기화 시작과 카드의 초기화가 끝나기 기다림
	do
	{
		if (sendAcmd(41, ocr) == false)
			goto error;
	} while (getResponse1() & 0x80000000);

	// CMD2 (CID를 얻어옴)
	if (sendCmd(2, 0) == false)
		goto error;

	// CMD3 (새로운 RCA 주소와 SD메모리의 상태를 얻어옴)
	if (sendCmd(3, 0) == false)
		goto error;
	mRca = getResponse1() & 0xffff0000;

	sts = getCardStatus();
	if(sts.currentState != SD_STBY)
		goto error;

	setDataBlockSize(BLOCK_512_BYTES);
	readyRead(buf, 512);
	sendAcmd(13, 0);

	setSdioClockBypass(true);

	delete buf;
	return true;
error:
	setSdioClockEn(false);
	mRca = 0;
	delete buf;
	return false;
}

void SdMemory::setDetectPin(drv::Gpio::Pin pin)
{
	mDetectPin = pin;
}

bool SdMemory::isConnected(void)
{
	return mAbleFlag;
}

void SdMemory::start(void)
{
	if(mDetectPin.port)
	{
		int threadId = trigger::add(trigger_handleSdmmcDetection, this, 512);
		exti.add(*mDetectPin.port, mDetectPin.pin, define::exti::mode::FALLING | define::exti::mode::RISING, threadId);
		trigger::run(threadId);
	}
}

SdMemory::CardStatus SdMemory::getCardStatus(void)
{
	CardStatus sts;
	unsigned int *buf = (unsigned int*)&sts;

	if (sendCmd(13, mRca))
		*buf = getResponse1();
	else
		*buf = 0xFFFFFFFF;

	return sts;
}

void SdMemory::isrDetection(void)
{
	sdmmc.lock();

	if (mDetectPin.port->getData(mDetectPin.pin) == false && mAbleFlag == false)
	{
		setPower(true);
		if(sdmmc.connect())
		{
			mAbleFlag = true;

			debug_printf("SD Memory Conected!!\n");

			if(mDetectionIsr)
				mDetectionIsr(true);
		}
		else
		{
			mAbleFlag = false;
			setPower(false);
			debug_printf("SD Memory Detected but connection failed!!\n");
		}
	}
	else
	{
		mAbleFlag = false;
		setPower(false);
		debug_printf("SD Memory Disconected!!\n");
		if(mDetectionIsr)
			mDetectionIsr(false);
	}
	
	sdmmc.unlock();
}

void trigger_handleSdmmcDetection(void *var)
{
	SdMemory *obj = (SdMemory*)var;
	
	obj->isrDetection();
}
}
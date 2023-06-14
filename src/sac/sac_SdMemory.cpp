////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>
#include <sac/SdMemory.h>
#include <yss/thread.h>
#include <yss/instance.h>
#include <string.h>

#define SD_IDLE 0
#define SD_READY 1
#define SD_IDENT 2
#define SD_STBY 3
#define SD_TRANS 4
#define SD_DATA 5
#define SD_RCA 6
#define SD_PRG 7
#define SD_DIS 8

#define HCS		0x40000000
#define BUSY	0x80000000

#if !defined(YSS_DRV_SDMMC_UNSUPPORTED)

namespace sac
{
SdMemory::SdMemory(void)
{
	mConnectedFlag = false;
	mVcc = 3.3;
	mRca = 0x00000000;
	mLastResponseCmd = 0;
	mMaxBlockAddr = 0;
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

inline uint32_t getOcr(float vcc)
{
	uint32_t ocr = 0;

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

inline int32_t  extractAuSize(void *src)
{
	uint8_t *cSrc = (uint8_t*)src;
	int32_t  loop = cSrc[10] >> 4 & 0xF, auSize = 16 * 1024;

	for(int32_t  i=1;i<loop;i++)
	{
		auSize *= 2;
	}

	return auSize;
}

inline int32_t  extractReadBlLen(void *src)
{
	uint8_t *cSrc = (uint8_t *)src;
	uint8_t buf = cSrc[5] & 0xF;

	switch(buf)
	{
	case 9 :
		return 512;
	case 10 :
		return 1024;
	case 11 :
		return 2048;
	default :
		return 0;
	}
}

inline int32_t  extractCSizeVersion2(void *src)
{
	uint8_t *buf = (uint8_t *)src;
	return (uint32_t)buf[9] | (uint32_t)buf[8] << 8 | (uint32_t)(buf[7] & 0x3F) << 16;
}

inline int32_t  extractMaxBlockLength(void *src)
{
	uint8_t *buf = (uint8_t *)src;

	switch(*buf >> 6)
	{
	case 0 : // version 1.0
		
		return 0;
	case 1 : // version 2.0
		return (extractCSizeVersion2(buf) + 1) * 1024;
	default :
		return 0;
	}
}

inline int32_t  extractReadBlockLength(void *src)
{
	uint8_t *buf = (uint8_t *)src;

	switch(*buf >> 6)
	{
	case 0 : // version 1.0
		
		return 0;
	case 1 : // version 2.0
		return 512;
	default :
		return 0;
	}
}

error SdMemory::connect(void)
{
	uint32_t ocr, capacity, temp, mult;
	CardStatus sts;
	error result;
	uint8_t *cbuf = new uint8_t[64];
	uint32_t *ibuf = (uint32_t*)cbuf;

	memset(cbuf, 0, 64);

	setPower(true);
	setBusWidth(BUS_WIDTH_1BIT);
	setClockFrequency(400000);
	setSdioClockEn(true);

	mRca = 0x00000000;

	// CMD0 (SD메모리 리셋)
	result = sendCmd(0, 0, RESPONSE_NONE);

	// CMD8 (SD메모리가 SD ver 2.0을 지원하는지 확인)
	result = sendCmd(8, 0x000001AA, RESPONSE_SHORT);
	if (result != error::ERROR_NONE) // 2.7V ~ 3.6V 동작 설정
		goto error;
	if (getShortResponse() != 0x000001AA)
		goto error;

	// SD메모리에 공급되는 전원에 대한 비트를 얻어옴
	ocr = getOcr(mVcc);

	// ACMD41
	// 지원하는 전원을 확인
	result = sendAcmd(41, ocr | HCS, RESPONSE_SHORT);
	if (result != error::CMD_CRC_FAIL)
	{
		// 실패시 현재 장치는 MMC
		goto error;
	}

	// 현재 공급되는 전원과 카드가 지원하는 전원을 비교
	if ((getShortResponse() & ocr) == 0)
		goto error;
	
	// 카드의 초기화가 끝나기 기다림
	do
	{
		result = sendAcmd(41, ocr | HCS, RESPONSE_SHORT);
		if (result != error::CMD_CRC_FAIL)
			goto error;
	} while ((getShortResponse() & BUSY) == 0);

	// 카드에서 HCS를 지원하는지 확인
	if (getShortResponse() & HCS)
	{
		mHcsFlag = true;
	}
	else
		mHcsFlag = false;

	// CMD2 (CID를 얻어옴)
	result = sendCmd(2, 0, RESPONSE_LONG);
	if (result != error::NO_RESPONSE_CMD)
		goto error;

	// CMD3 (새로운 RCA 주소와 SD메모리의 상태를 얻어옴)
	result = sendCmd(3, 0, RESPONSE_SHORT);
	if (result != error::ERROR_NONE)
		goto error;
	mRca = getShortResponse() & 0xffff0000;

	sts = getCardStatus();
	if(sts.currentState != SD_STBY)
		goto error;

	// CID 레지스터 읽어오기
	result = sendCmd(10, mRca, RESPONSE_LONG);
	if(result != error::NO_RESPONSE_CMD)
		goto error;

	getLongResponse(cbuf);

	// CSD 레지스터 읽어오기 
	result = sendCmd(9, mRca, RESPONSE_LONG);
	if(result != error::NO_RESPONSE_CMD)
		goto error;

	getLongResponse(cbuf);
	
	mMaxBlockAddr = extractMaxBlockLength(cbuf);
	mReadBlockLen = extractReadBlockLength(cbuf);
	
	result = select(true);
	if(result != ERROR_NONE)
		goto error;

	temp = mReadBlockLen;
	for(capacity=0; temp != 1; capacity++)
	{
		temp /= 2;
	}
	setDataBlockSize(capacity);

	setClockFrequency(25000000);

	mConnectedFlag = true;
	
	delete cbuf;
	return error::ERROR_NONE;

error:
	setSdioClockEn(false);
	mRca = 0;
	mMaxBlockAddr = 0;
	mConnectedFlag = false;
	setPower(false);

	delete cbuf;
	return result;
}

void SdMemory::disconnect(void)
{
	setSdioClockEn(false);
	mRca = 0;
	mMaxBlockAddr = 0;
	mConnectedFlag = false;
	setPower(false);
}

error SdMemory::sendAcmd(uint8_t cmd, uint32_t arg, uint8_t responseType)
{
	error result;

	SdMemory::CardStatus status;

	// CMD55 - 다음 명령을 ACMD로 인식 하도록 사전에 보냄
	result = sendCmd(55, mRca, RESPONSE_SHORT);
	if (result != error::ERROR_NONE) 
		return result;

	*(uint32_t*)(&status) = getShortResponse();
	if (status.appCmd == 0 || status.readyForData == 0)
		return error::NOT_READY;
	
	// 이번에 전송하는 명령을 ACMD로 인식
	result = sendCmd(cmd, arg, responseType);

	return result;
}

bool SdMemory::isConnected(void)
{
	return mConnectedFlag;
}

error SdMemory::select(bool en)
{
	error result;
	if(en)
		result = sendCmd(7, mRca, RESPONSE_SHORT);
	else
		result = sendCmd(7, 0, RESPONSE_SHORT);
	
	return result;
}

SdMemory::CardStatus SdMemory::getCardStatus(void)
{
	CardStatus sts;
	uint32_t *buf = (uint32_t*)&sts;

	if (sendCmd(13, mRca, RESPONSE_SHORT) == ERROR_NONE)
		*buf = getShortResponse();
	else
		*buf = 0xFFFFFFFF;

	return sts;
}

uint32_t SdMemory::getNumOfBlock(void)
{
	return mMaxBlockAddr;
}

//void SdMemory::isrDetection(void)
//{
//	sdmmc.lock();

//	thread::delay(500);

//	if (mDetectPin.port->getData(mDetectPin.pin) == false && mConnectedFlag == false)
//	{
//		setPower(true);
//		if(sdmmc.connect() == error::ERROR_NONE)
//		{
//			mConnectedFlag = true;
//			sdmmc.unlock();

//			if(mCallbackConnected)
//				mCallbackConnected(true);
//		}
//		else
//		{
//			mConnectedFlag = false;
//			setPower(false);
//			sdmmc.unlock();
//		}
//	}
//	else if(mDetectPin.port->getData(mDetectPin.pin) == true && mConnectedFlag == true)
//	{
//		mConnectedFlag = false;
//		setPower(false);
//		sdmmc.unlock();

//		if(mCallbackConnected)
//			mCallbackConnected(false);
//	}
//	else
//	{
//		sdmmc.unlock();
//	}
//}

uint32_t SdMemory::getBlockSize(void)
{
	return mReadBlockLen;
}

error SdMemory::read(uint32_t block, void *des)
{
	error result;

	while(mLastWriteTime.getMsec() <= 15 || mLastReadTime.getUsec() <= 500)
		thread::yield();

	readyRead(des, 512);
	result = sendCmd(17, block, RESPONSE_SHORT);
	if(result != error::ERROR_NONE)
		goto error_handle;
	result = waitUntilReadComplete();
	mLastReadTime.reset();
	return result;

error_handle:
	unlockRead();
	return result;
}

error SdMemory::write(uint32_t block, void *src)
{
	error result;
	while(mLastWriteTime.getMsec() <= 15 || mLastReadTime.getUsec() <= 500)
		thread::yield();

	readyWrite(src, 512);
	result = sendCmd(24, block, RESPONSE_SHORT);
	if(result != error::ERROR_NONE)
		goto error_handle;
	
	result = waitUntilWriteComplete();
	mLastWriteTime.reset();

	return result;

error_handle:
	mLastWriteTime.reset();
	unlockWrite();
	return result;
}

}

#endif


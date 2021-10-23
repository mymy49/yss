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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.10.19~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_PROTOCOL_DYNAMIXEL_V2__H_
#define YSS_PROTOCOL_DYNAMIXEL_V2__H_

#include <drv/drv_Uart.h>
#include <yss/Mutex.h>

class DynamixelV2
{
  private:
	struct Status
	{
		unsigned char id;
		unsigned char error;
		unsigned short model;
		unsigned char version;
	};

	drv::Uart *mUart;
	Mutex mMutex;
	static const char mHeader[4];
	unsigned char mIdList[256], mNumOfMotor, mLastRcvId, mLastRcvError;
	unsigned short mPreCalculatedCrc;
	char mRcvByte;
	Status *mStatus;
	bool mInitFlag;

	bool send(unsigned char id, unsigned char instruction, unsigned short len, void *parm);
	bool send(unsigned char id, unsigned char instruction, unsigned short addr, unsigned short len, void *parm);
	unsigned short calculateCrc16(char data, unsigned short crc);
	unsigned short calculateCrc16(const void *buf, int len, unsigned short crc);
	bool checkResponse(unsigned char id, unsigned char instruction, unsigned short len, void *parm);
	bool checkReceivedDataPatten(const char *patten, unsigned char len);
	bool getByte(void);

  public:
	DynamixelV2(drv::Uart &uart);
	~DynamixelV2(void);
	bool init(void);
	unsigned char getCount(void);
	unsigned char getId(unsigned char index);
	unsigned short getModelNumber(unsigned char index);
	unsigned char getFirmwareVersion(unsigned char index);
	bool read(unsigned char id, void *des, unsigned short addr, unsigned short len);
	bool write(unsigned char id, void *src, unsigned short addr, unsigned short len);
};

#endif
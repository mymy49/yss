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

#ifndef YSS_PROTOCOL_DYNAMIXEL_V2__H_
#define YSS_PROTOCOL_DYNAMIXEL_V2__H_

#include <drv/Uart.h>
#include <yss/Mutex.h>
#include <util/ElapsedTime.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

class DynamixelV2
{
  private:
	struct Status
	{
		uint8_t id;
		uint8_t error;
		uint16_t model;
		uint8_t version;
	};

	Uart *mUart;
	Mutex mMutex;
	static const uint8_t mHeader[4];
	uint8_t mIdList[256], mNumOfMotor, mLastRcvId, mLastRcvError;
	uint16_t mPreCalculatedCrc;
	int8_t mRcvByte;
	Status *mStatus;
	bool mInitFlag;
	ElapsedTime mSendingDelay;

	bool send(uint8_t id, uint8_t instruction, uint16_t len, void *parm);
	bool send(uint8_t id, uint8_t instruction, uint16_t addr, uint16_t len, void *parm);
	uint16_t calculateCrc16(int8_t data, uint16_t crc);
	uint16_t calculateCrc16(const void *buf, int32_t  len, uint16_t crc);
	bool checkResponse(uint8_t id, uint8_t instruction, uint16_t len, void *parm);
	bool checkReceivedDataPatten(const uint8_t *patten, uint8_t len);
	bool getByte(void);

  public:
	enum
	{
		ERROR_RESULT_FAIL = 1,
		ERROR_INSTRUCTION,
		ERROR_CRC,
		ERROR_DATA_RANGE,
		ERROR_DATA_LENGTH,
		ERROR_LIMIT,
		ERROR_ACCESS,
		ERROR_RESPONSE_FAIL,
	};

	DynamixelV2(Uart &uart);
	~DynamixelV2(void);
	bool initialize(void);
	uint8_t getCount(void);
	uint8_t getId(uint8_t index);
	uint16_t getModelNumber(uint8_t index);
	uint8_t getFirmwareVersion(uint8_t index);
	uint8_t getErrorCode(void);
	bool read(uint8_t id, void *des, uint16_t addr, uint16_t len);
	bool write(uint8_t id, void *src, uint16_t addr, uint16_t len, bool noResponse = false);
};

#endif

#endif


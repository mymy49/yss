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

#include <drv/peripheral.h>
#include <external/crc16.h>
#include <protocol/Dynamixel_V2.h>
#include <string.h>
#include <util/ElapsedTime.h>
#include <yss/thread.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

static const uint16_t crc_table[256] = {
	0x0000, 0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
	0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027, 0x0022,
	0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D, 0x8077, 0x0072,
	0x0050, 0x8055, 0x805F, 0x005A, 0x804B, 0x004E, 0x0044, 0x8041,
	0x80C3, 0x00C6, 0x00CC, 0x80C9, 0x00D8, 0x80DD, 0x80D7, 0x00D2,
	0x00F0, 0x80F5, 0x80FF, 0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1,
	0x00A0, 0x80A5, 0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1,
	0x8093, 0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
	0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197, 0x0192,
	0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE, 0x01A4, 0x81A1,
	0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB, 0x01FE, 0x01F4, 0x81F1,
	0x81D3, 0x01D6, 0x01DC, 0x81D9, 0x01C8, 0x81CD, 0x81C7, 0x01C2,
	0x0140, 0x8145, 0x814F, 0x014A, 0x815B, 0x015E, 0x0154, 0x8151,
	0x8173, 0x0176, 0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162,
	0x8123, 0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
	0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104, 0x8101,
	0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D, 0x8317, 0x0312,
	0x0330, 0x8335, 0x833F, 0x033A, 0x832B, 0x032E, 0x0324, 0x8321,
	0x0360, 0x8365, 0x836F, 0x036A, 0x837B, 0x037E, 0x0374, 0x8371,
	0x8353, 0x0356, 0x035C, 0x8359, 0x0348, 0x834D, 0x8347, 0x0342,
	0x03C0, 0x83C5, 0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1,
	0x83F3, 0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
	0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7, 0x03B2,
	0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E, 0x0384, 0x8381,
	0x0280, 0x8285, 0x828F, 0x028A, 0x829B, 0x029E, 0x0294, 0x8291,
	0x82B3, 0x02B6, 0x02BC, 0x82B9, 0x02A8, 0x82AD, 0x82A7, 0x02A2,
	0x82E3, 0x02E6, 0x02EC, 0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2,
	0x02D0, 0x82D5, 0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1,
	0x8243, 0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
	0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264, 0x8261,
	0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E, 0x0234, 0x8231,
	0x8213, 0x0216, 0x021C, 0x8219, 0x0208, 0x820D, 0x8207, 0x0202};

namespace Instruction
{
enum
{
	NOP,
	PING,
	READ,
	WRITE,
	REG_WRITE,

	STATUS = 0x55,
};
}

const uint8_t DynamixelV2::mHeader[4] = {0xFF, 0xFF, 0xFD, 0x00};

DynamixelV2::DynamixelV2(Uart &uart)
{
	mUart = &uart;
	mStatus = 0;
	mNumOfMotor = 0;
	mInitFlag = false;
	memset(mIdList, 0x00, sizeof(mIdList));

	mPreCalculatedCrc = calculateCrc16(mHeader, 4, 0);
}

bool DynamixelV2::getByte(void)
{
	ElapsedTime timeout;
	int16_t data;

	while (1)
	{
		if (timeout.getMsec() >= 500)
			return false;
		data = mUart->get();
		if (data >= 0)
		{
			//debug_printf("0x%02x\n", data);
			mRcvByte = data;
			return true;
		}
		thread::yield();
	}
}

bool DynamixelV2::checkReceivedDataPatten(const uint8_t *patten, uint8_t len)
{
	for (int32_t  i = 0; i < len; i++)
	{
		if (getByte() == false)
			return false;

		if (mRcvByte != patten[i])
			return false;
	}

	return true;
}

DynamixelV2::~DynamixelV2(void)
{
	if (mStatus)
		delete mStatus;
}

bool DynamixelV2::send(uint8_t id, uint8_t instruction, uint16_t len, void *parm)
{
	uint16_t totalLen = len + 3;
	int8_t sendBuf[4] = {(int8_t)id, (int8_t)(totalLen & 0xFF), (int8_t)(totalLen >> 8), (int8_t)instruction};
	uint16_t crc = mPreCalculatedCrc;
	crc = calculateCrc16(sendBuf, sizeof(sendBuf), crc);
	crc = calculateCrc16(parm, len, crc);

	if (mUart->send(mHeader, sizeof(mHeader)) == false)
		return false;
	if (mUart->send(sendBuf, sizeof(sendBuf)) == false)
		return false;
	if (len && mUart->send(parm, len) == false)
		return false;
	if (mUart->send(&crc, sizeof(crc)) == false)
		return false;
	return true;
}

bool DynamixelV2::send(uint8_t id, uint8_t instruction, uint16_t addr, uint16_t len, void *parm)
{
	uint16_t totalLen = len + 5;
	int8_t sendBuf[6] = {(int8_t)id, (int8_t)(totalLen & 0xFF), (int8_t)(totalLen >> 8), (int8_t)instruction, (int8_t)(addr & 0xFF), (int8_t)(addr >> 8)};
	uint16_t crc = mPreCalculatedCrc;
	crc = calculateCrc16(sendBuf, sizeof(sendBuf), crc);
	crc = calculateCrc16(parm, len, crc);

	if (mUart->send(mHeader, sizeof(mHeader)) == false)
		return false;
	if (mUart->send(sendBuf, sizeof(sendBuf)) == false)
		return false;
	if (len && mUart->send(parm, len) == false)
		return false;
	if (mUart->send(&crc, sizeof(crc)) == false)
		return false;
	return true;
}

bool DynamixelV2::initialize(void)
{
	uint8_t count = 0;
	int8_t parm[3];

	mUart->lock();
#if defined(YSS__CORE_CM0_H_GENERIC)
	while(mSendingDelay.getMsec() <= 1)
#else
	while(mSendingDelay.getUsec() <= 32)
#endif
		thread::yield();
	send(0xFE, Instruction::PING, 0, parm);

	while (1) // 연결된 장치 갯수 확인
	{
		if (checkResponse(0xFE, Instruction::STATUS, 3, parm) == false)
			break;

		count++;
	}

	if (count == 0)
		goto error;

	if (mStatus)
		delete mStatus;
	mStatus = new Status[count];
	if (mStatus == 0)
		goto error;

	send(0xFE, Instruction::PING, 0, parm);

	for (uint8_t i = 0; i < count; i++) // 필요한 정보 수집
	{
		if (checkResponse(0xFE, Instruction::STATUS, 3, parm) == false)
			goto error;

		mStatus[i].id = mLastRcvId;
		mStatus[i].error = mLastRcvError;
		mStatus[i].model = parm[0];
		mStatus[i].model |= (uint16_t)parm[1] << 8;
		mStatus[i].version = parm[2];
	}

	mSendingDelay.reset();
	mUart->unlock();
	mInitFlag = true;
	mNumOfMotor = count;
	return true;

error:
	mSendingDelay.reset();
	mUart->unlock();
	if (mStatus)
		delete mStatus;
	mStatus = 0;
	mInitFlag = false;
	mNumOfMotor = 0;
	return false;
}

bool DynamixelV2::checkResponse(uint8_t id, uint8_t instruction, uint16_t len, void *parm)
{
	uint16_t crc, rcvCrc;
	int8_t *src;
	int8_t *des = (int8_t *)parm;

	if (checkReceivedDataPatten(mHeader, 4) == false)
		return false;
	crc = mPreCalculatedCrc; // 미리 계산된 header CRC

	if (getByte() == false) // ID
		return false;
	if (id != 0xFE && id != mRcvByte)
		return false;
	mLastRcvId = mRcvByte;
	crc = calculateCrc16(mRcvByte, crc);

	len += 4; // LEN1
	src = (int8_t *)&len;
	if (getByte() == false)
		return false;
	if (mRcvByte != src[0])
		return false;
	crc = calculateCrc16(mRcvByte, crc);

	if (getByte() == false) // LEN2
		return false;
	if (mRcvByte != src[1])
		return false;
	crc = calculateCrc16(mRcvByte, crc);

	if (getByte() == false) // INSTRUCTION
		return false;
	if (mRcvByte != instruction)
		return false;
	crc = calculateCrc16(mRcvByte, crc);

	if (getByte() == false) // ERROR
		return false;
	mLastRcvError = mRcvByte;
	crc = calculateCrc16(mRcvByte, crc);

	len -= 4;
	for (int32_t  i = 0; i < len; i++) // PARM
	{
		if (getByte() == false)
			return false;
		des[i] = mRcvByte;
		crc = calculateCrc16(mRcvByte, crc);
	}

	if (getByte() == false) // CRC1
		return false;
	rcvCrc = mRcvByte;

	if (getByte() == false) // CRC2
		return false;
	rcvCrc |= (uint16_t)mRcvByte << 8;

	if (crc != rcvCrc)
		return false;

	return true;
}

uint8_t DynamixelV2::getCount(void)
{
	return mNumOfMotor;
}

uint8_t DynamixelV2::getId(uint8_t index)
{
	if (mNumOfMotor <= index)
		return 0xFF;

	if (mStatus)
		return mStatus[index].id;
	else
		return 0xFF;
}

uint16_t DynamixelV2::getModelNumber(uint8_t index)
{
	if (mNumOfMotor <= index)
		return 0x0;

	if (mStatus)
		return mStatus[index].model;
	else
		return 0x0;
}

uint8_t DynamixelV2::getFirmwareVersion(uint8_t index)
{
	if (mNumOfMotor <= index)
		return 0x0;

	if (mStatus)
		return mStatus[index].version;
	else
		return 0x0;
}

uint8_t DynamixelV2::getErrorCode(void)
{
	return mLastRcvError;
}

uint16_t DynamixelV2::calculateCrc16(const void *buf, int32_t  len, uint16_t crc)
{
	uint16_t i;

	for (int32_t  j = 0; j < len; j++)
	{
		i = ((uint16_t)(crc >> 8) ^ ((int8_t *)buf)[j]) & 0xFF;
		crc = (crc << 8) ^ crc_table[i];
	}

	return crc;
}

uint16_t DynamixelV2::calculateCrc16(int8_t data, uint16_t crc)
{
	uint16_t i = ((uint16_t)(crc >> 8) ^ data) & 0xFF;
	crc = (crc << 8) ^ crc_table[i];

	return crc;
}

bool DynamixelV2::read(uint8_t id, void *des, uint16_t addr, uint16_t len)
{
	uint16_t sendBuf[2] = {addr, len};
	bool rt;

	mUart->lock();
	if(mLastRcvError)
	{
		while(mSendingDelay.getMsec() <= 10)
			thread::yield();
	}
	else
	{
#if defined(YSS__CORE_CM0_H_GENERIC)
		while(mSendingDelay.getMsec() <= 1)
#else
		while(mSendingDelay.getUsec() <= 25)
#endif
			thread::yield();
	}
	mUart->flush();
	send(id, Instruction::READ, 4, sendBuf);
	rt = checkResponse(id, Instruction::STATUS, len, des);
	if(!rt)
		mLastRcvError = ERROR_RESPONSE_FAIL;
	mSendingDelay.reset();
	mUart->unlock();

	return rt;
}

bool DynamixelV2::write(uint8_t id, void *src, uint16_t addr, uint16_t len, bool noResponse)
{
	bool rt;

	mUart->lock();
	if(mLastRcvError)
	{
		while(mSendingDelay.getMsec() <= 10)
			thread::yield();
	}
	else
	{
#if defined(YSS__CORE_CM0_H_GENERIC)
		while(mSendingDelay.getMsec() <= 1)
#else
		while(mSendingDelay.getUsec() <= 25)
#endif
			thread::yield();
	}
	mUart->flush();
	send(id, Instruction::WRITE, addr, len, src);
	if(noResponse)
	{
		mUart->unlock();
		return true;
	}
	rt = checkResponse(id, Instruction::STATUS, 0, 0);
	if(!rt)
		mLastRcvError = ERROR_RESPONSE_FAIL;
	mSendingDelay.reset();
	mUart->unlock();

	return rt;
}

#endif


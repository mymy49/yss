/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>
#include <external/crc16.h>
#include <mod/dynamixel/DynamixelV2.h>
#include <string.h>
#include <util/ElapsedTime.h>
#include <util/Timeout.h>
#include <yss/thread.h>
#include <yss/debug.h>

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

const uint8_t DynamixelV2::mHeader[4] = {0xFF, 0xFF, 0xFD, 0x00};

const uint8_t DynamixelV2::mErrorTable[7] = {error_t::ERROR_NONE, error_t::INSTRUCTION_ERROR, error_t::CRC_ERROR, error_t::DATA_RANGE_ERROR, error_t::DATA_LENGTH_ERROR, error_t::DATA_LIMIT_ERROR, error_t::ACCESS_ERROR};

DynamixelV2::DynamixelV2(Uart &uart)
{
	mId = 0xFE;
	mUart = &uart;
	mPreCalculatedCrc = calculateCrc16(mHeader, 4, 0);
}

void DynamixelV2::setId(uint8_t id)
{
	mId = id;
}

error_t DynamixelV2::initialize(void)
{
	error_t result;
	uint8_t status[2];
	uint16_t len = 2;

	lock();

	result = send(PING, 0, 0);
	if(result != error_t::ERROR_NONE)
		goto error_handler;
	
	result = checkResponse(len, status);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	unlock();

	return error_t::ERROR_NONE;

error_handler :
	return result;
	unlock();
}

error_t DynamixelV2::factoryReset(void)
{
	error_t result;

	lock();

	result = send(FACTORY_RESET, 0, 0);
	if(result != error_t::ERROR_NONE)
		goto error_handler;
	
	unlock();

	return error_t::ERROR_NONE;

error_handler :
	unlock();
	return result;
}

error_t DynamixelV2::send(cmd_t cmd, uint16_t len, void *parm)
{
	error_t result;
	int8_t sendBuf[4] = {(int8_t)mId, (int8_t)(len + 3), (int8_t)((len + 3) >> 8), (int8_t)cmd};
	uint16_t crc = mPreCalculatedCrc;

	crc = calculateCrc16(sendBuf, sizeof(sendBuf), crc);
	crc = calculateCrc16(parm, len, crc);

	result = mUart->send(mHeader, sizeof(mHeader));
	if (result != error_t::ERROR_NONE)
		return result;

	result = mUart->send(sendBuf, sizeof(sendBuf));
	if (result != error_t::ERROR_NONE)
		return result;

	if(len)
	{
		result = mUart->send(parm, len);
		if (result != error_t::ERROR_NONE)
			return result;
	}

	return mUart->send(&crc, sizeof(crc));
}

error_t DynamixelV2::send(cmd_t cmd, uint16_t addr, uint16_t len, void *parm)
{
	error_t result;
	int8_t sendBuf[4] = {(int8_t)mId, (int8_t)(len + 5), (int8_t)((len + 5) >> 8), (int8_t)cmd}, *caddr = (int8_t*)&addr;
	uint16_t crc = mPreCalculatedCrc;

	crc = calculateCrc16(sendBuf, sizeof(sendBuf), crc);
	crc = calculateCrc16(caddr, 2, crc);
	crc = calculateCrc16(parm, len, crc);

	result = mUart->send(mHeader, sizeof(mHeader));
	if (result != error_t::ERROR_NONE)
		return result;

	result = mUart->send(sendBuf, sizeof(sendBuf));
	if (result != error_t::ERROR_NONE)
		return result;

	result = mUart->send(caddr, 2);
	if (result != error_t::ERROR_NONE)
		return result;

	result = mUart->send(parm, len);
	if (result != error_t::ERROR_NONE)
		return result;

	return mUart->send(&crc, sizeof(crc));
}

error_t DynamixelV2::write(uint8_t addr, void *src, uint16_t &len, bool noResponse)
{
	error_t result;

	lock();
	
	result = send(WRITE, addr, len, src);
	if(result != error_t::ERROR_NONE)
		goto ret;

	if(!noResponse)
		result = checkResponse(len, src);

ret :
	unlock();
	return result;
}

error_t DynamixelV2::read(uint8_t addr, void *des, uint16_t &len)
{
	error_t result;
	uint16_t len_ = 2;

	lock();
	
	result = send(READ, addr, len_, &len);
	if(result != error_t::ERROR_NONE)
		goto ret;

	result = checkResponse(len, des);

ret :
	unlock();
	return result;
}

void DynamixelV2::lock(void)
{
	mUart->lock();
}

void DynamixelV2::unlock(void)
{
	mUart->unlock();
}

error_t DynamixelV2::checkResponse(uint16_t &len, void *des)
{
	uint32_t count;
	uint8_t *buf, data, step = 0, error, *cdes = (uint8_t*)des;
	uint16_t rlen, index, crc, rcrc;
	Timeout timeout(500);

	while(1)
	{
		count = mUart->getRxCount();

		if(count)
		{
			buf = (uint8_t*)mUart->getRxBuffer();
			for(uint32_t i = 0; i < count; i++)
			{
				data = buf[i];
				switch(step)
				{
				case 0 : // Header 1 확인
					if(data == 0xFF)
						step++;
					break;
				
				case 1 : // Header 2 확인
					if(data == 0xFF)
						step++;
					else
						step = 0;
					break;
				
				case 2 : // Header 3 확인
					if(data == 0xFD)
						step++;
					else
						step = 0;
					break;

				case 3 : // Header 4 확인
					if(data == 0x00)
					{
						crc = mPreCalculatedCrc;
						step++;
					}
					else
						step = 0;
					break;
				
				case 4 : // ID
					if(data == mId)
					{
						crc = calculateCrc16(data, crc);
						step++;
					}
					else
						step = 0;
					break; 
				
				case 5 : // Length L
					rlen = data;
					crc = calculateCrc16(data, crc);
					step++;
					break;
				
				case 6 : // Length H
					rlen |= (uint16_t)data << 8;
					crc = calculateCrc16(data, crc);
					step++;
					break;

				case 7 : // Instruction (CMD)
					if(data == STATUS)
					{
						crc = calculateCrc16(data, crc);
						step++;
					}
					else
						step = 0;
					break;

				case 8 : // Error
					error = data;
					index = 0;
					crc = calculateCrc16(data, crc);
					rlen -= 4;
					if(rlen)
						step++;
					else
						step += 2;
					break;

				case 9 : // Data
					crc = calculateCrc16(data, crc);
					if(len > index)
						cdes[index] = data;
					index++;
					if(rlen == index)
						step++;
					break;
				
				case 10 : // CRC L
					rcrc = data;
					step++;
					break;
				
				case 11 : // CRC H
					rcrc |= (uint16_t)data << 8;
					if(crc == rcrc)
						return (error_t)mErrorTable[error];
					else
						return error_t::CHECK_SUM;
					break;
				}
			}

			mUart->releaseRxBuffer(count);

			if(timeout.isTimeout())
			{
				return error_t::TIMEOUT;
			}
		}

		thread::yield();
	}
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

#endif


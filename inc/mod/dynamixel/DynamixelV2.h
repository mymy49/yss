/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_DYNAMIXEL_DYNAMIXEL_V2__H_
#define YSS_MOD_DYNAMIXEL_DYNAMIXEL_V2__H_

#include <drv/Uart.h>
#include <yss/Mutex.h>
#include <util/ElapsedTime.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

class DynamixelV2
{
public :
	DynamixelV2(Uart &uart);

	void setId(uint8_t id);

	error_t initialize(void);
	
	error_t factoryReset(void);

protected :
	typedef enum
	{
		NOP,
		PING,
		READ,
		WRITE,
		REG_WRITE,
		ACTION,
		FACTORY_RESET,

		STATUS = 0x55,
	}cmd_t;

	uint8_t mId;
	Uart *mUart;
	uint16_t mPreCalculatedCrc;

	error_t send(cmd_t cmd, uint16_t len, void *parm);

	error_t send(cmd_t cmd, uint16_t addr, uint16_t len, void *parm);

	error_t write(uint8_t addr, void *src, uint16_t &len, bool noResponse = false);

	error_t read(uint8_t addr, void *des, uint16_t &len);

	error_t checkResponse(uint16_t &len, void *des);

	void lock(void);

	void unlock(void);

private :
	static const uint8_t mHeader[4];

	static const uint8_t mErrorTable[7];

	uint16_t calculateCrc16(int8_t data, uint16_t crc);

	uint16_t calculateCrc16(const void *buf, int32_t  len, uint16_t crc);
};

#endif

#endif


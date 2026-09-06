/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_HAL_BLE__H_
#define YSS_HAL_BLE__H_

#include <yss/error.h>
//#include <bluetooth/Ble4p0.h>

class Ble4p0;

class BleRadio
{
	const static uint32_t mMaxBufferSize = 258;
public :
	typedef enum
	{
		BLE_1MBPS,
		BLE_2MBPS
	}speed_t;

	BleRadio();

	virtual error_t initializeAsBle() = 0;

	virtual error_t setChannel(uint8_t channel) = 0;

	virtual error_t setSpeed(speed_t speed) = 0;

	virtual error_t receive(uint32_t timeout = 1000) = 0;

	virtual error_t transmit(uint32_t timeout = 1000) = 0;

	virtual error_t transmitAdv(uint32_t timeout = 1000, uint16_t tifs = 150) = 0;

	void *getRxBuffer();

	void *getTxBuffer();

	void *getAdvBuffer();

	void setBleStack(Ble4p0 *stack);

protected :
	uint32_t getFrequency(uint8_t channel);
	uint8_t mTxBuffer[mMaxBufferSize] __attribute__((aligned(4)));
	uint8_t mRxBuffer[mMaxBufferSize] __attribute__((aligned(4)));
	uint8_t mAdvBuffer[mMaxBufferSize] __attribute__((aligned(4)));

	Ble4p0 *mBleStack;
	 
private :
};

#endif


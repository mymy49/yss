/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_FX1_CPU__H_
#define YSS_MOD_FX1_CPU__H_

#include <stdint.h>
#include <yss/error.h>
#include <yss/thread.h>

class Fx1Cpu
{
	const static uint32_t mMemoryS0Count = 0xC00, mMemoryStepCount = 0x100, mMemoryPlcD8xxxCount = 256;
public :
	Fx1Cpu(void);

	~Fx1Cpu(void);
	
	void processComm(void);

private :
	uint8_t mRxData[255], mTxData[255];
	uint8_t mRxDataSize;
	threadId_t mThreadId;
	
	// 내장 메모리 설정
	uint32_t mMemoryS0[mMemoryS0Count];
	uint16_t mMemoryStep[mMemoryStepCount];
	uint16_t mMemoryPlcD8xxx[mMemoryPlcD8xxxCount];
	

	uint8_t atox(uint8_t tens, uint8_t units);

	uint8_t xtoaTens(uint8_t hex);

	uint8_t xtoaUnits(uint8_t hex);

	void handleCommRxData(void);

	virtual uint32_t getRxCount(void) = 0;

	virtual error_t getRxData(void *des, uint32_t size) = 0;

	virtual error_t sendData(void *src, uint32_t size) = 0;

	void responseRead(uint16_t addr, uint8_t size);
};

#endif


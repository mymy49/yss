/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_GX_WORKS2__H_
#define YSS_MOD_GX_WORKS2__H_

#include <stdint.h>
#include <yss/error.h>
#include <yss/thread.h>

class GxWorks2
{
public :
	GxWorks2(void);

	~GxWorks2(void);
	
	void processComm(void);

private :
	uint8_t mRxData[255], mTxData[255];
	uint8_t mRxDataSize;
	threadId_t mThreadId;

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


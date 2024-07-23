/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_COMM_MODBUS__H_
#define YSS_MOD_COMM_MODBUS__H_

#include <yss/instance.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

class Modbus : private Mutex
{
  private:
	Uart *mPeri;
	void (*setRx)(void);
	void (*setTx)(void);
	int16_t *mRcvBuf;
	int16_t *mMemory;
	void (*rcvHandler)(uint16_t addr, int16_t data);
	int32_t  mThreadId;
	uint16_t mMemoryDepth, mRcvBufSize;
	uint8_t mId, mCrcHi, mCrcLo;
	bool mSendFlag, mReceiveFlag;

	void calculateCrc(uint8_t byte);
	void calculateCrc(void *src, uint16_t size);
	void resetCrc(void);
	void responseReadInputRegister(uint16_t addr, uint16_t size);
	void responseWriteSingleRegister(uint16_t addr);
	void responseWriteMultiRegister(uint16_t addr, uint16_t size);

  public:
	struct Config
	{
		Uart &peri;
		uint32_t threadStacksize;
		void (*setRx)(void);
		void (*setTx)(void);
		void (*receiveHandler)(uint16_t addr, int16_t data);
	};

	Modbus(uint16_t rcvBufSize, uint16_t memoryDepth);
	bool initialize(Config config);
	void process(void);
	void setId(uint8_t id);
	void setData(uint16_t addr, int16_t data);
	int16_t getData(uint16_t addr);
	bool isReceived(void);
	bool isSent(void);
};

#endif

#endif


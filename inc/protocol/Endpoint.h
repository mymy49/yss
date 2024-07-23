/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_PROTOCOL_ENDPOINT__H_
#define YSS_PROTOCOL_ENDPOINT__H_

#include <drv/Uart.h>
#include <yss/Mutex.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

class Fifo;

class Endpoint
{
  public:
	enum
	{
		MAX_ENDPOINT_NUM = 8
	};

  private:
	Uart *mUart;
	int32_t mSenderThreadId, mReceiverThreadId, mBufSize;
	uint8_t mNumOfEndpoint;
	uint8_t mRcvBuf[254];
	Fifo *mTxFifo[MAX_ENDPOINT_NUM], *mRxFifo[MAX_ENDPOINT_NUM];
	Mutex mMutex;

  public:
	Endpoint(Uart &uart, uint8_t numOfEndpoint, uint32_t fifoSize);
	~Endpoint(void);
	void initialize(void);
	void processSender(void);
	void processReceiver(void);
	uint8_t getWaitUntilReceive(uint8_t endpoint);
	int16_t get(uint8_t endpoint);
	void send(uint8_t endpoint, const void *src, uint32_t len);
};

#endif

#endif


/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_XMODEM__H_
#define YSS_UTIL_XMODEM__H_

#include <drv/Uart.h>
#include <yss/Mutex.h>

#if !defined(YSS_DRV_UART_UNSUPPORTED)

class Xmodem
{
	Uart *mUart;
	int32_t mThreadId;
	uint8_t mPaceketData[132];
	uint32_t mRetryNum;
	bool mResultFlag, mCompleteFlag;
	Mutex mMutex;
	void (*mReceiveHandler)(uint8_t packetNum, uint8_t *data);

	uint8_t receiveOnePacket(void);

  public:
	Xmodem(Uart &uart);
	void start(void);
	void stop(void);
	void process(void);
	void setReceiveHandler(void (*handler)(uint8_t packetNum, uint8_t *data));
	void setRetry(uint32_t num);
	bool isComplete(void);
};

#endif

#endif


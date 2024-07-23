/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_WIZNET_SOCKET__H_
#define YSS_MOD_WIZNET_SOCKET__H_

#include <yss/Mutex.h>
#include <yss/error.h>

class iEthernet;

class WiznetSocket : public Mutex
{
	iEthernet *mPeri;
	uint8_t mSocketNumber, mInterruptFlag, mStatusFlag;
	int8_t *mRxBuffer;
	uint16_t mRxBufferSize, mHead, mTail;

  protected:

  public:
	enum
	{
		// Protocol
		TCP = 0x01,

		// Command
		OPEN = 0x01,
		CONNECT = 0x04,

		// Status
		TCP_SOCKET_OPEN_OK = 0x01,
		SOCKET_CONNECT_REQUEST_SENT = 0x02,
		SOCKET_ESTABLISHED = 0x03,
		SOCKET_DISCONNECTED = 0x04,

		// Interrupt
		SOCKET_INT_CON = 0x01,

		// Status Flag
		INITIALIZATION = 0x01,
		CONNECTION = 0x02,
		OVER_FLOW = 0x04,
	};

	struct Host
	{
		uint8_t ip[4];
		uint16_t port;
	};

	WiznetSocket(void);
	error_t initialize(iEthernet &obj, uint8_t socketNumber, uint16_t rxBufferSize);
	error_t connectToHost(const Host &host);
	error_t waitUntilConnect(uint32_t timeout = 20000);
	error_t sendData(void *src, uint32_t size);
	uint8_t getStatus(void);
	void isr(uint8_t interrupt);
	uint16_t getReceivedDataSize(void);
	uint8_t getReceivedByte(void);
	error_t getReceivedBytes(void *des, uint16_t size);
};

#endif


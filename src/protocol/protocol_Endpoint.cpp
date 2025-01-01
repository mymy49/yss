/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <external/crc16.h>
#include <util/ElapsedTime.h>
#include <drv/peripheral.h>
#include <protocol/Endpoint.h>
#include <util/Fifo.h>
#include <yss/thread.h>

// 일시적으로 지원을 중단합니다.

/*
#ifndef YSS_DRV_UART_UNSUPPORTED

#define STX 0x02
#define ETX 0x03
#define ECHO 0x0E

uint32_t gRemain;

static void thread_processSender(void *var);
static void thread_processReceiver(void *var);

Endpoint::Endpoint(Uart &uart, uint8_t numOfEndpoint, uint32_t fifoSize)
{
	if (numOfEndpoint > MAX_ENDPOINT_NUM)
		numOfEndpoint = MAX_ENDPOINT_NUM;

	mUart = &uart;
	mUart->lock();
	mNumOfEndpoint = numOfEndpoint;
	mBufSize = fifoSize;

	for (uint8_t i = 0; i < numOfEndpoint; i++)
	{
		mTxFifo[i] = new Fifo(fifoSize);
		mRxFifo[i] = new Fifo(fifoSize);
	}

	mSenderThreadId = 0;
	mReceiverThreadId = 0;
}

void Endpoint::initialize(void)
{
	mSenderThreadId = thread::add(thread_processSender, this, 512);
	mReceiverThreadId = thread::add(thread_processReceiver, this, 512);
}

Endpoint::~Endpoint(void)
{
	for (uint8_t i = 0; i < mNumOfEndpoint; i++)
	{
		delete mTxFifo[i];
		delete mRxFifo[i];
	}
}

void Endpoint::processSender(void)
{
	Fifo *fifo;

	while (1)
	{
		for (uint8_t i = 0; i < mNumOfEndpoint; i++)
		{
			fifo = mTxFifo[i];
			while (fifo->getStoredSize())
			{
				mUart->send(fifo->pop());
			}
		}

		thread::yield();
	}
}

void Endpoint::processReceiver(void)
{
	uint8_t chksum, rcvData, endpoint, size;

	while (1)
	{
	start:
		rcvData = mUart->getWaitUntilReceive();
		chksum = rcvData;
		if (rcvData != STX)
			goto start;

		endpoint = mUart->getWaitUntilReceive();
		if (endpoint >= mNumOfEndpoint)
			goto start;
		chksum ^= endpoint;

		size = mUart->getWaitUntilReceive();
		if (size > 254)
			goto start;
		chksum ^= size;

		rcvData = mUart->getWaitUntilReceive();
		if (rcvData != ECHO)
			goto start;
		chksum ^= rcvData;

		for (uint8_t i = 0; i < size; i++)
		{
			rcvData = mUart->getWaitUntilReceive();
			chksum ^= rcvData;
			mRcvBuf[i] = rcvData;
		}

		rcvData = mUart->getWaitUntilReceive();
		if (rcvData != ETX)
			goto start;
		chksum ^= rcvData;

		rcvData = mUart->getWaitUntilReceive();
		if (chksum != rcvData)
			goto start;

		mRxFifo[endpoint]->push(mRcvBuf, size);
	}
}

uint8_t Endpoint::getWaitUntilReceive(uint8_t endpoint)
{
	if (endpoint > mNumOfEndpoint)
		return 0;

	while (mRxFifo[endpoint]->getStoredSize() == 0)
		thread::yield();

	return mRxFifo[endpoint]->pop();
}

int16_t Endpoint::get(uint8_t endpoint)
{
	if (endpoint > mNumOfEndpoint)
		return -1;

	if (mRxFifo[endpoint]->getStoredSize() == 0)
		return -1;
	else
		return mRxFifo[endpoint]->pop();
}

void Endpoint::send(uint8_t endpoint, const void *src, uint32_t len)
{
	if (endpoint > mNumOfEndpoint)
		return;

	uint32_t  remain;
	uint8_t *byte;
	uint8_t header[4], headerLen = 4;
	volatile uint8_t chksum = 0;

	header[0] = STX;
	header[1] = endpoint;
	header[2] = len;
	header[3] = ECHO;

	for (int32_t  i = 0; i < 4; i++)
		chksum ^= header[i];

	byte = (uint8_t *)src;
	for (uint32_t  i = 0; i < len; i++)
		chksum ^= byte[i];

	chksum ^= ETX;

	byte = header;
	mMutex.lock();
	while (headerLen)
	{
		remain = mBufSize - mTxFifo[endpoint]->getStoredSize();
		gRemain = remain;
		if (remain > 2)
		{
			if (remain > headerLen)
				remain = headerLen;
			headerLen -= remain;
			mTxFifo[endpoint]->push(byte, remain);
			byte += remain;
		}
		else
			thread::yield();
	}

	byte = (uint8_t *)src;
	while (len)
	{
		remain = mBufSize - mTxFifo[endpoint]->getStoredSize();
		if (remain > 2)
		{
			if (remain > len)
				remain = len;
			len -= remain;
			mTxFifo[endpoint]->push(byte, remain);
			byte += remain;
		}
		else
			thread::yield();
	}

	do
	{
		remain = mBufSize - mTxFifo[endpoint]->getStoredSize();
		if (remain < 4)
			thread::yield();
	} while (remain < 4);

	mTxFifo[endpoint]->push(ETX);
	mTxFifo[endpoint]->push(chksum);

	mMutex.unlock();
}

static void thread_processSender(void *var)
{
	Endpoint *endpoint = (Endpoint *)var;
	endpoint->processSender();
}

static void thread_processReceiver(void *var)
{
	Endpoint *endpoint = (Endpoint *)var;
	endpoint->processReceiver();
}

#endif

*/

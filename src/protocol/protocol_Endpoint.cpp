////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <external/crc16.h>
#include <util/ElapsedTime.h>
#include <drv/peripheral.h>
#include <protocol/Endpoint.h>
#include <util/Fifo.h>
#include <yss/thread.h>

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
	uint32_t count;
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

	int32_t  remain;
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
	for (int32_t  i = 0; i < len; i++)
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


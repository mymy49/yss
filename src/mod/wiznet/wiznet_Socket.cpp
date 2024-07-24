/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>
#include <mod/wiznet/WiznetSocket.h>
#include <mod/wiznet/iEhternet.h>
#include <util/Timeout.h>

#ifndef YSS_DRV_SPI_UNSUPPORTED

WiznetSocket::WiznetSocket(void)
{
	mStatusFlag = 0;
	mRxBuffer = 0;
	mRxBufferSize = mHead = mTail = 0;
}

error_t WiznetSocket::initialize(iEthernet &obj, uint8_t socketNumber, uint16_t rxBufferSize)
{
	if(socketNumber >= obj.getSocketLength())
		return error_t::OUT_OF_RANGE;

	mPeri = &obj;
	mPeri->lock();
	if(mPeri->isWorking())
	{
		mSocketNumber = socketNumber;
		mPeri->setSocket(socketNumber, *this);
		mPeri->unlock();

		if(mRxBuffer)
			delete mRxBuffer;

		mRxBuffer = new int8_t[rxBufferSize];
		if(mRxBuffer == 0)
			return error_t::MALLOC_FAILED;
		mRxBufferSize = rxBufferSize;
		mHead = mTail = 0;

		mPeri->lock();
		mPeri->setSocketInterruptEnable(socketNumber, true);
		mPeri->unlock();

		mStatusFlag |= INITIALIZATION;

		return error_t::ERROR_NONE;
	}
	else
	{
		mPeri->unlock();
		return error_t::NOT_INITIALIZED;
	}
}

error_t WiznetSocket::connectToHost(const Host &host)
{
	if(~mStatusFlag & INITIALIZATION)
		return error_t::NOT_INITIALIZED;

	uint8_t status;

	thread::yield();

	mPeri->lock();
	if(mPeri->setSocketMode(mSocketNumber, TCP, 0) == false)
	{
		mPeri->unlock();
		return error_t::OUT_OF_RANGE;
	}

	mPeri->setSocketPort(mSocketNumber, host.port);
	mPeri->setSocketDestinationPort(mSocketNumber, host.port);
	mPeri->setSocketDestinationIpAddress(mSocketNumber, (uint8_t*)host.ip);
	mPeri->unlock();
	
	for(int32_t  i=0;i<3;i++)
	{
		mPeri->lock();
		mPeri->command(mSocketNumber, OPEN);
		if(mPeri->getSocketStatus(mSocketNumber) != TCP_SOCKET_OPEN_OK)
		{
			mPeri->unlock();
			thread::delay(500);
			continue;
		}
		mPeri->unlock();
	
		mPeri->lock();
		mPeri->command(mSocketNumber, CONNECT);
		mPeri->unlock();
		
		// 여기서 딜레이를 안주면 status가 제대로 업데이트 안됨.
		thread::delay(5);

		mPeri->lock();
		status = mPeri->getSocketStatus(mSocketNumber);
		mPeri->unlock();

		if(status == SOCKET_ESTABLISHED)
			return error_t::ERROR_NONE;
		else if(status == SOCKET_CONNECT_REQUEST_SENT)
			return error_t::ERROR_NONE;

		thread::delay(500);
	}
	
	return error_t::TIMEOUT;
}

error_t WiznetSocket::waitUntilConnect(uint32_t timeout)
{
	if(~mStatusFlag & INITIALIZATION)
		return error_t::NOT_INITIALIZED;

	Timeout tout(timeout);
	uint8_t status;

	while(!tout.isTimeout())
	{
		mPeri->lock();
		status = mPeri->getSocketStatus(mSocketNumber);
		mPeri->unlock();

		if(status == SOCKET_ESTABLISHED)
			return error_t::ERROR_NONE;
		else if(status == 0)
			return error_t::UNKNOWN;
		
		thread::delay(100);
	}

	return error_t::TIMEOUT;
}

error_t WiznetSocket::sendData(void *src, uint32_t size)
{
	if(~mStatusFlag & INITIALIZATION)
		return error_t::NOT_INITIALIZED;
	else if(~mStatusFlag & CONNECTION)
		return error_t::NOT_CONNECTED;

	uint32_t freeBufferSize;
	int8_t *csrc = (int8_t*)src;

	while(size)
	{
		mPeri->lock();
		freeBufferSize = mPeri->getTxFreeBufferSize(mSocketNumber);
		if(freeBufferSize > size)
			freeBufferSize = size;
		if(freeBufferSize > 0)
			mPeri->sendSocketData(mSocketNumber, csrc, freeBufferSize);
		mPeri->unlock();

		csrc += freeBufferSize;
		size -= freeBufferSize;
		if(freeBufferSize == 0)
			thread::yield();
	}

	return error_t::ERROR_NONE;
}

uint8_t WiznetSocket::getStatus(void)
{
	return mStatusFlag;
}

uint16_t WiznetSocket::getReceivedDataSize(void)
{
	if (mTail <= mHead)
		return mHead - mTail;
	else
		return mRxBufferSize - (mTail - mHead);
}

uint8_t WiznetSocket::getReceivedByte(void)
{
	uint8_t data = mRxBuffer[mTail++];

	if(mTail >= mRxBufferSize)
		mTail = 0;

	return data;
}

error_t WiznetSocket::getReceivedBytes(void *des, uint16_t size)
{
	(void)des;
	(void)size;

	return error_t::NOT_READY;
}

void WiznetSocket::isr(uint8_t interrupt)
{
	if(interrupt & 0x01)
		mStatusFlag |= CONNECTION;
	
	if(interrupt & 0x02)
		mStatusFlag &= ~CONNECTION;
	
	if(interrupt & 0x04)
	{
		uint16_t rxSize, size;

		mPeri->lock();
		rxSize = mPeri->getRxReceivedSize(mSocketNumber);
		mPeri->unlock();

		while(rxSize)
		{
			if(mHead >= mTail)
				size = mRxBufferSize - mHead;
			else
				size = mRxBufferSize - mTail;
			
			if(rxSize < size)
				size = rxSize;
			
			if(size)
			{
				mPeri->lock();
				mPeri->receiveSocketData(mSocketNumber, &mRxBuffer[mHead], size);
				mPeri->unlock();

				rxSize -= size;
				mHead += size;
				if(mHead >= mRxBufferSize)
					mHead = 0;
			}
			else
				thread::yield();
		}
	}
}

#endif



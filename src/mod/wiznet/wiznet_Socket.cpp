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

error WiznetSocket::initialize(iEthernet &obj, uint8_t socketNumber, uint16_t rxBufferSize)
{
	if(socketNumber >= obj.getSocketLength())
		return error::OUT_OF_RANGE;

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
			return error::MALLOC_FAILED;
		mRxBufferSize = rxBufferSize;
		mHead = mTail = 0;

		mPeri->lock();
		mPeri->setSocketInterruptEnable(socketNumber, true);
		mPeri->unlock();

		mStatusFlag |= INITIALIZATION;

		return error::ERROR_NONE;
	}
	else
	{
		mPeri->unlock();
		return error::NOT_INITIALIZED;
	}
}

error WiznetSocket::connectToHost(const Host &host)
{
	if(~mStatusFlag & INITIALIZATION)
		return error::NOT_INITIALIZED;

	uint8_t status;

	thread::yield();

	mPeri->lock();
	if(mPeri->setSocketMode(mSocketNumber, TCP, 0) == false)
	{
		mPeri->unlock();
		return error::OUT_OF_RANGE;
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
			return error::ERROR_NONE;
		else if(status == SOCKET_CONNECT_REQUEST_SENT)
			return error::ERROR_NONE;

		thread::delay(500);
	}
	
	return error::TIMEOUT;
}

error WiznetSocket::waitUntilConnect(uint32_t timeout)
{
	if(~mStatusFlag & INITIALIZATION)
		return error::NOT_INITIALIZED;

	Timeout tout(timeout);
	uint8_t status;

	while(!tout.isTimeout())
	{
		mPeri->lock();
		status = mPeri->getSocketStatus(mSocketNumber);
		mPeri->unlock();

		if(status == SOCKET_ESTABLISHED)
			return error::ERROR_NONE;
		else if(status == 0)
			return error::UNKNOWN;
		
		thread::delay(100);
	}

	return error::TIMEOUT;
}

error WiznetSocket::sendData(void *src, uint32_t size)
{
	if(~mStatusFlag & INITIALIZATION)
		return error::NOT_INITIALIZED;
	else if(~mStatusFlag & CONNECTION)
		return error::NOT_CONNECTED;

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

	return error::ERROR_NONE;
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

error WiznetSocket::getReceivedBytes(void *des, uint16_t size)
{
	(void)des;
	(void)size;

	return error::NOT_READY;
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



/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <UsbClass/Cdc.h>
#include <drv/Usbd.h>
#include <string.h>

Cdc::Cdc(void)
{
	mCallback_handleLineCode = nullptr;
	mDte = mRts = false;
	mLineCoding.dwDTERate = 9600;
	mLineCoding.bCharFormat = STOP_1BIT;
	mLineCoding.bParityType = PARITY_NONE;
	mLineCoding.bDataBits = 7;

	memset(&mConfig, 0x00, sizeof(mConfig));
}

error_t Cdc::initialize(const config_t &config)
{
	mConfig = config;

	return error_t::ERROR_NONE;
}

uint8_t Cdc::getUsingEpCount(void)
{
	return 3;
}

void Cdc::handleWakeup(void)
{
	
}

void Cdc::handleSetConfiguration(uint16_t __attribute__((unused))value)
{
	mUsbd->lock();
	mUsbd->send(0, 0, 0, true);
	mUsbd->unlock();
}

void Cdc::getEmptyCsInterfaceDescriptor(csInterfaceDesc_t *des)
{
	*des = 
	{
		0x05,	//uint8_t bLength;
		0x24,	//uint8_t bDescriptorType;
		0,		//uint8_t bDescriptorSubtype;
		0		//uint16_t bcdCDC;
	};
}

void Cdc::setCallbackLineCodeHandler(void (*func)(lineCoding_t lineCode))
{
	mCallback_handleLineCode = func;
}

error_t Cdc::send(void *src, uint32_t size)
{
	mUsbd->lock();
	mUsbd->send(mBulkInEpNum, src, size);
	mUsbd->unlock();

	return error_t::ERROR_NONE;
}

error_t Cdc::send(const void *src, uint32_t size)
{
	return send((void*)src, size);
}

bool Cdc::isClearToSend(void)
{
	return mDte || mRts;
}

uint32_t Cdc::getRxDataCount(void)
{
	return getOutRxDataSize(mBulkOutEpNum);
}

error_t Cdc::getRxData(void *des, uint32_t size)
{
	return mUsbd->getOutRxData(mBulkOutEpNum, des, size);
}

void Cdc::handleClassSpecificRequest(void)
{
	uint8_t rcvSize;

	if(mSetupData[0] & 0x80) // Device to Host
	{
		switch(mSetupData[1])
		{
		case 0x21 : // Get Line Code
			mUsbd->lock();
			mUsbd->send(0, &mLineCoding, 7, true);
			mUsbd->unlock();
			break;

		default :
			mUsbd->lock();
			mUsbd->stall(0);
			mUsbd->unlock();
			break;
		}
	}
	else
	{
		switch(mSetupData[1])
		{
		case 0x22 : // Set Control Line State
			mUsbd->lock();
			mDte = mSetupData[2] & 0x01;
			mRts = (mSetupData[2] >> 1) & 0x01;
			mUsbd->send(0, 0, 0, true);
			mUsbd->unlock();
			break;
		
		case 0x20 : // Set Line Code
			mUsbd->flushSetupOutData();
			
			mUsbd->lock();
			mUsbd->send(0, 0, 0, true);
			mUsbd->unlock();
			
			if(mUsbd->waitUntilRxSetupOutData(200) == error_t::ERROR_NONE)
			{
				rcvSize = mUsbd->getSetupOutDataSize();
				if(rcvSize == 7)
				{
					memcpy(&mLineCoding, mUsbd->getSetupOutDataPointer(), rcvSize);

					if(mCallback_handleLineCode)
						mCallback_handleLineCode(mLineCoding);
				}
			}
			break;
		
		default :
			mUsbd->lock();
			mUsbd->stall(0);
			mUsbd->unlock();
			break;
		}
	}
}	 



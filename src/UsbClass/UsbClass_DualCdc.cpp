/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <UsbClass/DualCdc.h>
#include <drv/Usbd.h>
#include <string.h>

DualCdc::DualCdc(void)
{
	mCallback_handleLineCode0 = nullptr;
	mCallback_handleLineCode1 = nullptr;
	mDte0 = mRts0 = false;
	mDte1 = mRts1 = false;
	mLineCoding0.dwDTERate = 9600;
	mLineCoding0.bCharFormat = STOP_1BIT;
	mLineCoding0.bParityType = PARITY_NONE;
	mLineCoding0.bDataBits = 7;

	mLineCoding1 = mLineCoding0;

	memset(&mConfig, 0x00, sizeof(mConfig));
}

error_t DualCdc::initialize(const config_t &config)
{
	mConfig = config;

	return error_t::ERROR_NONE;
}

uint8_t DualCdc::getUsingEpCount(void)
{
	return 6;
}

void DualCdc::handleWakeup(void)
{
	
}

void DualCdc::handleSetConfiguration(uint16_t __attribute__((unused))value)
{
	mUsbd->lock();
	mUsbd->send(0, 0, 0, true);
	mUsbd->unlock();
}

void DualCdc::getEmptyCsInterfaceDescriptor(csInterfaceDesc_t *des)
{
	*des = 
	{
		0x05,	//uint8_t bLength;
		0x24,	//uint8_t bDescriptorType;
		0,		//uint8_t bDescriptorSubtype;
		0,		//uint16_t bcdCDC;
	};
}

void DualCdc::setCallbackLineCodeHandler0(void (*func)(lineCoding_t lineCode))
{
	mCallback_handleLineCode0 = func;
}

void DualCdc::setCallbackLineCodeHandler1(void (*func)(lineCoding_t lineCode))
{
	mCallback_handleLineCode1 = func;
}

error_t DualCdc::send0(void *src, uint32_t size)
{
	mUsbd->lock();
	mUsbd->send(mBulkInEpNum0, src, size);
	mUsbd->unlock();

	return error_t::ERROR_NONE;
}

error_t DualCdc::send0(const void *src, uint32_t size)
{
	return send0((void*)src, size);
}

error_t DualCdc::send1(void *src, uint32_t size)
{
	mUsbd->lock();
	mUsbd->send(mBulkInEpNum1, src, size);
	mUsbd->unlock();

	return error_t::ERROR_NONE;
}

error_t DualCdc::send1(const void *src, uint32_t size)
{
	return send0((void*)src, size);
}

bool DualCdc::isClearToSend0(void)
{
	return mDte0 && mRts0;
}

bool DualCdc::isClearToSend1(void)
{
	return mDte1 && mRts1;
}

uint32_t DualCdc::getRxDataCount0(void)
{
	return getOutRxDataSize(mBulkOutEpNum0);
}

uint32_t DualCdc::getRxDataCount1(void)
{
	return getOutRxDataSize(mBulkOutEpNum1);
}

error_t DualCdc::getRxData0(void *des, uint32_t size)
{
	return mUsbd->getOutRxData(mBulkOutEpNum0, des, size);
}

error_t DualCdc::getRxData1(void *des, uint32_t size)
{
	return mUsbd->getOutRxData(mBulkOutEpNum1, des, size);
}

void DualCdc::handleClassSpecificRequest(void)
{
	uint8_t rcvSize;

	if(mSetupData[0] & 0x80) // Device to Host
	{
		switch(mSetupData[1])
		{
		case 0x21 : // Get Line Code
			if(mSetupData[4] == 0)
			{
				mUsbd->lock();
				mUsbd->send(0, &mLineCoding0, 7, true);
				mUsbd->unlock();
			}
			else if(mSetupData[4] == 2)
			{
				mUsbd->lock();
				mUsbd->send(0, &mLineCoding0, 7, true);
				mUsbd->unlock();
			}
			else
			{
				mUsbd->lock();
				mUsbd->stall(0);
				mUsbd->unlock();
			}
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
			if(mSetupData[4] == 0)
			{
				mDte0 = mSetupData[2] & 0x01;
				mRts0 = (mSetupData[2] >> 1) & 0x01;
			}
			else if(mSetupData[4] == 2)
			{
				mDte1 = mSetupData[2] & 0x01;
				mRts1 = (mSetupData[2] >> 1) & 0x01;
			}
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
					if(mSetupData[4] == 0)
					{
						memcpy(&mLineCoding0, mUsbd->getSetupOutDataPointer(), rcvSize);

						if(mCallback_handleLineCode0)
							mCallback_handleLineCode0(mLineCoding0);
					}
					else if(mSetupData[4] == 2)
					{
						memcpy(&mLineCoding1, mUsbd->getSetupOutDataPointer(), rcvSize);

						if(mCallback_handleLineCode1)
							mCallback_handleLineCode1(mLineCoding1);
					}
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



/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <UsbClass/Audio10.h>
#include <drv/Usbd.h>
#include <string.h>

Audio10::Audio10(void)
{
	//mCallback_handleLineCode = nullptr;
	//mDte = mRts = false;
	//mLineCoding.dwDTERate = 9600;
	//mLineCoding.bCharFormat = STOP_1BIT;
	//mLineCoding.bParityType = PARITY_NONE;
	//mLineCoding.bDataBits = 7;

	//memset(&mConfig, 0x00, sizeof(mConfig));
}

error_t Audio10::initialize(const config_t &config)
{
	mConfig = config;

	return error_t::ERROR_NONE;
}

uint8_t Audio10::getUsingEpCount(void)
{
	return 2;
}

void Audio10::handleWakeup(void)
{
	
}

void Audio10::handleSetConfiguration(uint16_t value)
{
	mUsbd->lock();
	mUsbd->send(0, 0, 0, true);
	mUsbd->unlock();
}

uint32_t Audio10::getRxDataCount(void)
{
	return getOutRxDataSize(mOutEpNum);
}

error_t Audio10::getRxData(void *des, uint32_t size)
{
	return mUsbd->getOutRxData(mOutEpNum, des, size);
}

/*
void Audio10::getEmptyCsInterfaceDescriptor(csInterfaceDesc_t *des)
{
	*des = 
	{
		0x05,	//uint8_t bLength;
		0x24,	//uint8_t bDescriptorType;
				//uint8_t bDescriptorSubtype;
				//uint16_t bcdCDC;
	};
}

void Audio10::setCallbackLineCodeHandler(void (*func)(lineCoding_t lineCode))
{
	mCallback_handleLineCode = func;
}

error_t Audio10::send(void *src, uint32_t size)
{
	mUsbd->lock();
	mUsbd->send(mBulkInEpNum, src, size);
	mUsbd->unlock();

	return error_t::ERROR_NONE;
}

error_t Audio10::send(const void *src, uint32_t size)
{
	return send((void*)src, size);
}

bool Audio10::isClearToSend(void)
{
	return mDte || mRts;
}

*/
void Audio10::handleClassSpecificRequest(void)
{
	uint8_t rcvSize, bufU8;
	uint32_t bufU32;
	uint16_t bufU16;

	if(mSetupData[0] & 0x80) // Device to Host
	{
		switch(mSetupData[1])
		{
		case 0x81 : // 
			if((mSetupData[0] & 0x0F) == 0x02)
			{
				mUsbd->lock();
				bufU32 = 96000;
				mUsbd->send(0, &bufU32, mSetupData[6], true);
				mUsbd->unlock();
			}
			else
			{
				switch(mSetupData[3])
				{
				case 0x01 : // Mute Control
					if(mSetupData[5] == 0x05) // Rec
					{
						mUsbd->lock();
						bufU8 = 1;
						mUsbd->send(0, &bufU8, 1, true);
						mUsbd->unlock();
					}
					else if(mSetupData[5] == 0x06) // Play
					{
						mUsbd->lock();
						bufU8 = 1;
						mUsbd->send(0, &bufU8, 1, true);
						mUsbd->unlock();
					}
					break;
				
				case 0x02 : // Volume Control
					if(mSetupData[5] == 0x05) // Rec
					{
						mUsbd->lock();
						bufU16 = 0x1000;
						mUsbd->send(0, &bufU16, 2, true);
						mUsbd->unlock();
					}
					else if(mSetupData[5] == 0x06) // Play
					{
						mUsbd->lock();
						bufU16 = 0x1000;
						mUsbd->send(0, &bufU16, 2, true);
						mUsbd->unlock();
					}
					break;

				default:
					mUsbd->lock();
					mUsbd->stall(0);
					mUsbd->unlock();
					break;
				}
			}
			break;

		case 0x82 : // Get Min
			switch(mSetupData[3])
			{
			case 0x02 : // Volume
				if(mSetupData[5] == 0x05) // Rec
				{
					mUsbd->lock();
					bufU16 = 0x8000;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				else if(mSetupData[5] == 0x06) // Play
				{
					mUsbd->lock();
					bufU16 = 0x8000;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				break;
			
			default:
				mUsbd->lock();
				mUsbd->stall(0);
				mUsbd->unlock();
				break;
			}
			break;
		
		case 0x83 : // Get Max
			switch(mSetupData[3])
			{
			case 0x02 : // Volume
				if(mSetupData[5] == 0x05) // Rec
				{
					mUsbd->lock();
					bufU16 = 0x7FFF;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				else if(mSetupData[5] == 0x06) // Play
				{
					mUsbd->lock();
					bufU16 = 0x7FFF;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				break;
			
			default:
				mUsbd->lock();
				mUsbd->stall(0);
				mUsbd->unlock();
				break;
			}
			break;

		case 0x84 : // Get Resolution
			switch(mSetupData[3])
			{
			case 0x02 : // Volume
				if(mSetupData[5] == 0x05) // Rec
				{
					mUsbd->lock();
					bufU16 = 0x0400;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				else if(mSetupData[5] == 0x06) // Play
				{
					mUsbd->lock();
					bufU16 = 0x0400;
					mUsbd->send(0, &bufU16, 2, true);
					mUsbd->unlock();
				}
				break;
			
			default:
				mUsbd->lock();
				mUsbd->stall(0);
				mUsbd->unlock();
				break;
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
		case 0x01 : // Mute Control
			mUsbd->lock();
			mUsbd->send(0, 0, 0, true);
			mUsbd->unlock();
			break;
			
		case 0x02 : // Volume
			mUsbd->lock();
			mUsbd->send(0, 0, 0, true);
			mUsbd->unlock();
			break;
		
		default :
			mUsbd->lock();
			mUsbd->stall(0);
			mUsbd->unlock();
			break;
		}
	}
}	 




/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <UsbClass/Cdc.h>


Cdc::Cdc(void)
{
	mConfig = nullptr;
}

error_t Cdc::initialize(const config_t &config)
{
	mConfig = &config;

	return error_t::ERROR_NONE;
}

uint8_t Cdc::getUsingEpCount(void)
{
	return mUsingEpCount;
}

void Cdc::handleWakeup(void)
{
	
}

void Cdc::getEmptyCsInterfaceDescriptor(csInterfaceDesc_t *des)
{
	*des = 
	{
		0x05,	//uint8_t bLength;
		0x24,	//uint8_t bDescriptorType;
				//uint8_t bDescriptorSubtype;
				//uint16_t bcdCDC;
	};
}



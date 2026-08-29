/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <bluetooth/Ble4p0.h>
#include <hal/Ble.h>
#include <yss/debug.h>

#pragma GCC optimize("O1")

Ble4p0::Ble4p0()
{

}

error_t Ble4p0::initialize(config_t config)
{
	mDev = &config.dev;
	
	mDev->initializeAsBle();
	mDev->setSpeed(Ble::BLE_1MBPS);

	runThread();

	return error_t::ERROR_NONE;
}

uint8_t* Ble4p0::getRxMacAddress()
{
	return &((uint8_t*)mDev->getRxBuffer())[2];
}

uint16_t Ble4p0::getRxCount()
{
	return (uint16_t)((uint8_t*)mDev->getRxBuffer())[1];
}

Ble4p0::packetType_t Ble4p0::getRxPacketType()
{
	return (Ble4p0::packetType_t)(*(uint8_t*)mDev->getRxBuffer() & 0x0F);
}

uint8_t Ble4p0::getRxAdvCount()
{
	return ((uint8_t*)mDev->getRxBuffer())[8];
}

uint8_t Ble4p0::getRxAdvType()
{
	return ((uint8_t*)mDev->getRxBuffer())[9];
}

bool Ble4p0::isRxAdvInfoAble()
{
	return getRxCount() > 6;
}


void Ble4p0::thread()
{
	uint8_t *mac;

	mDev->setChannel(39);

	while(1)
	{
		// Scanning Test
		if(mDev->receive() == error_t::ERROR_NONE)
		{
			switch(getRxPacketType())
			{
			case Ble4p0::PACKET_TYPE_ADV_IND :	
				mac = getRxMacAddress();
				if(isRxAdvInfoAble())
					debug_printf("Advertising : [%02X:%02X:%02X:%02X:%02X:%02X] Len : %d, Type = %02X\n", mac[5], mac[4], mac[3], mac[2], mac[1], mac[0], getRxAdvCount(), getRxAdvType());
				else
					debug_printf("Advertising : [%02X:%02X:%02X:%02X:%02X:%02X]\n", mac[5], mac[4], mac[3], mac[2], mac[1], mac[0]);
				break;

			default :
				break;
			}
		}

		thread::yield();
	}
}



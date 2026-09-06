/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <bluetooth/Ble4p0.h>
#include <hal/BleRadio.h>
#include <yss/debug.h>
#include <string.h>
#include <bluetooth/Ble4p0.h>

#pragma GCC optimize("O1")

Ble4p0::Ble4p0()
{
}

error_t Ble4p0::initialize(config_t config)
{
	mDev = &config.dev;
	mType = config.deviceType;
	mDeviceName = config.deviceName;
	mConnectingFlag = false;
	
	mDev->initializeAsBle();
	mDev->setSpeed(BleRadio::BLE_1MBPS);
	mDev->setBleStack(this);

	mMacAddr[0] = 0xAA;
	mMacAddr[1] = 0xBB;
	mMacAddr[2] = 0xCC;
	mMacAddr[3] = 0xDD;
	mMacAddr[4] = 0xEE;
	mMacAddr[5] = 0xCF;

	uint8_t len = strlen(config.deviceName);
	uint8_t *des = (uint8_t*)mDev->getAdvBuffer();
	uint8_t *src = (uint8_t*)mMacAddr;

	*des++ = PACKET_TYPE_SCAN_RSP | 0x40;
	*des++ = len + 8;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;
	*des++ = *src++;

	*des++ = len + 1;
	*des++ = AD_TYPE_COMPLETE_LOCAL_NAME;
	memcpy(des, config.deviceName, len);

	runThread();

	return error_t::ERROR_NONE;
}

bool Ble4p0::isAdvScanReq()
{
	uint8_t *buf = (uint8_t*)mDev->getRxBuffer();

	if(packetType_t(buf[0] & 0x0F) == PACKET_TYPE_SCAN_REQ &&
		buf[1] == 12 &&
		buf[8] == mMacAddr[0] &&
		buf[9] == mMacAddr[1] &&
		buf[10] == mMacAddr[2] &&
		buf[11] == mMacAddr[3] &&
		buf[12] == mMacAddr[4] &&
		buf[13] == mMacAddr[5])
	{
		return true;
	}
	else
		return false;
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

void Ble4p0::resetTxLength()
{
	mTxLen = 6;
}

void Ble4p0::setTxAdv(packetType_t type, bool txAdd, bool rxAdd)
{
	*(uint8_t*)mDev->getTxBuffer() = (uint8_t)type | txAdd << 6 | rxAdd << 7;
}

void Ble4p0::copyTxMacAddress()
{
	uint8_t *des = &((uint8_t*)mDev->getTxBuffer())[2];
	uint8_t *src = mMacAddr;

	*des++ =*src++;
	*des++ =*src++;
	*des++ =*src++;
	*des++ =*src++;
	*des++ =*src++;
	*des++ =*src++;
}

void Ble4p0::appendTxAdvType(adType_t type, void* src, uint8_t length)
{
	uint8_t *des = &((uint8_t*)mDev->getTxBuffer())[mTxLen + 2];
	*des++ = length + 1;
	*des++ = type;
	memcpy(des, src, length);

	mTxLen += length + 2;
}

void Ble4p0::updatePayloadLength()
{
	uint8_t *des = &((uint8_t*)mDev->getTxBuffer())[1];
	*des = mTxLen;	
}

void Ble4p0::setTxAdv(advFlag_t type1, advFlag_t type2, advFlag_t type3, advFlag_t type4)
{
	uint8_t *des = &((uint8_t*)mDev->getTxBuffer())[10];
	*des = (uint8_t)(type1 | type2 | type3 | type4);
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
	uint8_t channel;

	while(1)
	{
		if(mConnectingFlag)
		{
		}
		else
		{
			resetTxLength();

			if(mType == TYPE_CONNECTABLE)
				setTxAdv(PACKET_TYPE_ADV_IND, true, false);
			else
				setTxAdv(PACKET_TYPE_ADV_NONCONN_IND, true, false);

			copyTxMacAddress();

			uint8_t buf[32];
			buf[0] = ADV_FLAG_LE_GENERAL_DISC_MODE | ADV_FLAG_BR_EDR_NOT_SUPPORTED;
			appendTxAdvType(AD_TYPE_FLAGS, buf, 1);
			updatePayloadLength();
			
			if(37 > channel || channel > 39)
				channel = 37;

			mDev->setChannel(channel++); 
			mDev->transmitAdv(2);
			thread::delay(10);
		}
	}
}


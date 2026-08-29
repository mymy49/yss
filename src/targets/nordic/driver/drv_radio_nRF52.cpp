/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <yss.h>
#include <drv/peripheral.h>
#include <targets/nordic/nRF52_Radio.h>
#include <yss/scheduler.h>
#include <yss/reg.h>
#include <nrf52840_bitfields.h>
#include <yss/debug.h>

#pragma GCC optimize("O1")

nRF52_Radio::nRF52_Radio(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mRadioBuffer = nullptr;
	mDev = setup.dev;
}

error_t nRF52_Radio::initialize(config_t config)
{

	return error_t::ERROR_NONE;
}

error_t nRF52_Radio::initializeAsBle()
{
	mDev->POWER = RADIO_POWER_POWER_Enabled;
	setThreeFieldsData(mDev->PCNF0, RADIO_PCNF0_LFLEN_Msk, 8, RADIO_PCNF0_LFLEN_Pos,
									RADIO_PCNF0_S0LEN_Msk, 1, RADIO_PCNF0_S0LEN_Pos,
									RADIO_PCNF0_S1LEN_Msk, 0, RADIO_PCNF0_S1LEN_Pos);
	setFourFieldsData(mDev->PCNF1,	RADIO_PCNF1_MAXLEN_Msk, 255, RADIO_PCNF1_MAXLEN_Pos,
									RADIO_PCNF1_STATLEN_Msk, 0, RADIO_PCNF1_STATLEN_Pos, 
									RADIO_PCNF1_BALEN_Msk, 3, RADIO_PCNF1_BALEN_Pos, 
									RADIO_PCNF1_ENDIAN_Msk, RADIO_PCNF1_ENDIAN_Little, RADIO_PCNF1_ENDIAN_Pos);

	setBitData(mDev->PCNF1, RADIO_PCNF1_WHITEEN_Enabled, RADIO_PCNF1_WHITEEN_Pos);

	mDev->BASE0 = 0x89BED600;
	mDev->PREFIX0 = 0x8E;
	mDev->RXADDRESSES = 0x01;

	setTwoFieldsData(mDev->CRCCNF,	RADIO_CRCCNF_LEN_Msk, RADIO_CRCCNF_LEN_Three, RADIO_CRCCNF_LEN_Pos, 
									RADIO_CRCCNF_SKIPADDR_Msk, RADIO_CRCCNF_SKIPADDR_Skip, RADIO_CRCCNF_SKIPADDR_Pos);  
	
	mDev->CRCPOLY = 0x0000065B;
	mDev->CRCINIT = 0x555555;

	mRadioBuffer = new uint8_t[258];
	mDev->PACKETPTR = (uint32_t)mRadioBuffer;

	return error_t::ERROR_NONE;
}

error_t nRF52_Radio::setChannel(uint8_t channel)
{
	mDev->FREQUENCY = getFrequency(channel) - 2400;
	mDev->DATAWHITEIV = channel | 0x40;

	return error_t::ERROR_NONE;
}

error_t nRF52_Radio::setSpeed(speed_t speed)
{
	switch(speed)
	{
	case BLE_1MBPS :
	   	mDev->MODE = RADIO_MODE_MODE_Ble_1Mbit;
		break;

	case BLE_2MBPS :
		mDev->MODE = RADIO_MODE_MODE_Ble_2Mbit;
		break;

	default :
		return error_t::UNSUPPORTED_CONFIG;
	}

	return error_t::ERROR_NONE;
}

error_t nRF52_Radio::receive()
{
	uint32_t primask = __get_PRIMASK();

	mThreadId = thread::getCurrentThreadId();

	__disable_irq();
	mDev->SHORTS = RADIO_SHORTS_READY_START_Msk | RADIO_SHORTS_END_DISABLE_Msk;
	mDev->EVENTS_CRCOK = 0;
	mDev->EVENTS_CRCERROR = 0;
	mDev->INTENSET = RADIO_INTENSET_END_Msk;
	NRF_RADIO->TASKS_RXEN = 1; 

	thread::waitForSignal();

	mDev->INTENCLR = RADIO_INTENCLR_END_Msk;

	__set_PRIMASK(primask);
	
	if(NRF_RADIO->EVENTS_CRCOK)
		return error_t::ERROR_NONE;
	else if(NRF_RADIO->EVENTS_CRCERROR)
		return error_t::CRC_ERROR;
	else
		return error_t::UNKNOWN;
}

void* nRF52_Radio::getRxBuffer()
{
	return mRadioBuffer;
}

void nRF52_Radio::isr()
{
	if(mDev->INTENSET & RADIO_INTENSET_END_Msk && mDev->EVENTS_END)
	{
		mDev->EVENTS_END = 0;
		thread::signal(mThreadId);
	}
}

#endif



/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <drv/Radio.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <util/Timeout.h>
#include <targets/nordic/nrf52840_bitfields.h>

uint8_t gData[512];

Radio::Radio(YSS_RADIO_Peri *peri, const Drv::setup_t drvConfig) : Drv(drvConfig)
{
	mPeri = peri;
}

error Radio::initialize(void)
{
	mPeri->MODE = RADIO_MODE_MODE_Ieee802154_250Kbit;
	mPeri->FREQUENCY = (5 << RADIO_FREQUENCY_FREQUENCY_Pos) & RADIO_FREQUENCY_FREQUENCY_Msk;
	mPeri->PACKETPTR = (uint32_t)gData;
//	mPeri->PCNF1 = ((128 << RADIO_PCNF1_MAXLEN_Pos) & RADIO_PCNF1_MAXLEN_Msk) |
	
	return error::ERROR_NONE;
}

#endif


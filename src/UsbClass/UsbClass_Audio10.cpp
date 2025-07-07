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
	memset(&mConfig, 0x00, sizeof(mConfig));
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

uint32_t Audio10::getRxDataCount(void)
{
	return mUsbd->getOutRxDataSize(mOutEpNum);
}

error_t Audio10::getRxData(void *des, uint32_t size)
{
	return mUsbd->getOutRxData(mOutEpNum, des, size);
}


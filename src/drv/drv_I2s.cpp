/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/I2s.h>

/**
 * @file drv_I2s.cpp
 * @brief Generic I2S (Inter-IC Sound) driver source file.
 */

I2s::I2s(const Drv::setup_t drvSetup) : Drv(drvSetup)
{
}

uint32_t I2s::getChannelFrameSize(void)
{
	// Return the configured I2S data channel frame size.
	return mDataSize;
}


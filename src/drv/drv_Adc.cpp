/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/Adc.h>

Adc::Adc(const Drv::setup_t drvSetup) : Drv(drvSetup)
{
	// Initialize ADC channel state and counters before allocation.
	mChannel = nullptr;
	mConvertingIndex = 0;
	mChCount = 0;
	mMaxChCount = 0;
}

int32_t Adc::getResult(uint8_t index)
{
	// Return the converted value at the requested channel index.
	// Shift the raw ADC result by the configured resolution bits.
	if(index < mChCount)
		return mChannel[index].result >> mChannel[index].bit;
	else
		return -1;
}

error_t Adc::malloc(uint8_t numOfCh)
{
	// Allocate the channel descriptor array for the requested number of ADC inputs.
	mChannel = new channel_t[numOfCh];

	if(mChannel == nullptr)
		return error_t::MALLOC_FAILED;

	mMaxChCount = numOfCh;

	return error_t::ERROR_NONE;
}


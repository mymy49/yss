/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI

#include <sac/TftLcdDriver.h>

bool TftLcdDriver::getReverseRgbOrder(void)
{
	return false;
}

bool TftLcdDriver::getReverseEndian(void)
{
	return false;
}

#endif


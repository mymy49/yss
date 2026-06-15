/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/Hbi.h>

uint32_t Hbi::getCapacity(void)
{
	// Return the configured HBI storage capacity in bytes.
	return mCapacity;
}


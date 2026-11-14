/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/Quadspi.h>

#pragma GCC optimize("O1")

/**
 * @file drv_Quadspi.cpp
 * @brief Generic QuadSPI (Queued Serial Peripheral Interface) driver source file.
 */

Quadspi::Quadspi(const Drv::setup_t drvSetup) : Drv(drvSetup)
{
	// Initialize cache variables for timing and transaction formats.
	mLastSpec = nullptr;
	mLastForm = nullptr;
}



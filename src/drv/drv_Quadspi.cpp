/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

 #include <drv/Quadspi.h>

Quadspi::Quadspi(const Drv::setup_t drvSetup) : Drv(drvSetup)
{
	mLastSpec = nullptr;
	mLastForm = nullptr;
}


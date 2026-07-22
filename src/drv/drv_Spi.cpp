/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>
#include <yss/debug.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/Spi.h>
#include <yss/scheduler.h>
#include <yss/reg.h>

/**
 * @file drv_Spi.cpp
 * @brief Generic SPI (Serial Peripheral Interface) driver source file.
 */

#if !defined(YSS_DRV_SPI_UNSUPPORTED)

Spi::Spi(const Drv::setup_t drvSetup) : Drv(drvSetup)
{
	// Initialize cache pointer for the last applied hardware specification.
	mLastSpec = nullptr;
}

#endif



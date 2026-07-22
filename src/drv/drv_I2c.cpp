/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/I2c.h>
#include <util/Timeout.h>
#include <yss/scheduler.h>

/**
 * @file drv_I2c.cpp
 * @brief Generic I2C (Inter-Integrated Circuit) driver source file.
 */

I2c::I2c(const Drv::setup_t drvSetup) : Drv(drvSetup)
{
}



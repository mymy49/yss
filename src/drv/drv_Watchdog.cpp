/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/Watchdog.h>
#include <util/Timeout.h>
#include <yss/scheduler.h>

Watchdog::Watchdog(const Drv::setup_t drvSetup) : Drv(drvSetup)
{

}


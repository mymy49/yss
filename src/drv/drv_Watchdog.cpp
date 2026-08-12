/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/Watchdog.h>
#include <util/Timeout.h>
#include <yss/scheduler.h>

/**
 * @brief Constructor for the Watchdog base class.
 * @details Initializes the base `Drv` class with the provided driver setup
 * configuration. This constructor is called by target-specific derived classes
 * (e.g., `NuvotonWdt`) to initialize the common driver infrastructure, such
 * as clock and interrupt management.
 *
 * @param[in] drvSetup The base driver setup configuration structure,
 *                     containing pointers to clock, interrupt, and reset
 *                     handler functions.
 */
Watchdog::Watchdog(const Drv::setup_t drvSetup) : Drv(drvSetup)
{

}

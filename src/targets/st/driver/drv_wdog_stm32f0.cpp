/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(STM32F0)

#include <drv/Wdog.h>
#include <yss.h>
#include <targets/st/bitfield.h>

Wdog::Wdog(const Drv::setup_t drvConfig, const Config config) : Drv(drvConfig)
{
	(void)config;
}

error_t Wdog::initialize(uint8_t prescale, uint16_t reload)
{
	(void)prescale;
	(void)reload;
	return error_t::ERROR_NONE;
}

#endif


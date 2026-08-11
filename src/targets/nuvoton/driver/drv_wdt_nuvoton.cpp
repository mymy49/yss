/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)

#include <targets/nuvoton/NuvotonWdt.h>
#include <yss/reg.h>

NuvotonWdt::NuvotonWdt(const Drv::setup_t drvSetup, const setup_t setup) : Watchdog(drvSetup)
{
	// Store reference to the hardware register structure.
	mDev = setup.dev;
}

error_t NuvotonWdt::initialize(interval_t interval)
{
	// Register Unlock sequence
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;
	
	setFieldData(mDev->CTL, WDT_CTL_TOUTSEL_Msk, interval, WDT_CTL_TOUTSEL_Pos);
	mDev->CTL |= WDT_CTL_WDTEN_Msk | WDT_CTL_RSTEN_Msk;

	// Register Lock
	SYS->REGLCTL = 0x00;

	return error_t::ERROR_NONE;
}

void NuvotonWdt::update()
{
	mDev->RSTCNT = 0x00005AA5;
}

bool NuvotonWdt::isWorking()
{
	return ((mDev->CTL & (WDT_CTL_WDTEN_Msk | WDT_CTL_RSTEN_Msk)) == (WDT_CTL_WDTEN_Msk | WDT_CTL_RSTEN_Msk));
}


void NuvotonWdt::isr()
{
	
}

#endif



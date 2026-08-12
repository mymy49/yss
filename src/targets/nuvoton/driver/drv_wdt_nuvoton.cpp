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

/**
 * @brief Constructor for the NuvotonWdt driver.
 * @details Initializes the base `Watchdog` class with the provided driver
 * setup configuration and stores the pointer to the Nuvoton WDT hardware
 * register block for later use by other member functions.
 *
 * @param[in] drvSetup The base driver setup configuration, containing
 *                     pointers to the clock, interrupt, and reset functions.
 * @param[in] setup    The Nuvoton WDT-specific setup structure containing
 *                     the pointer to the WDT hardware register block.
 */
NuvotonWdt::NuvotonWdt(const Drv::setup_t drvSetup, const setup_t setup) : Watchdog(drvSetup)
{
	// Store reference to the hardware register structure.
	mDev = setup.dev;
}

/**
 * @brief Initializes the Nuvoton WDT hardware peripheral.
 * @details Performs the Nuvoton system register unlock sequence (write 0x59,
 * 0x16, 0x88 to SYS->REGLCTL) to gain access to write-protected registers,
 * sets the timeout interval in WDT_CTL, enables both the WDT (`WDTEN`) and
 * the hardware reset-on-timeout (`RSTEN`) functions, and then re-locks the
 * register protection by writing 0x00 to SYS->REGLCTL.
 *
 * @param[in] interval The timeout interval selection from the `interval_t`
 *                     enum. Defaults to `INTERVAL_26p214_Sec`.
 * @return error_t Returns `ERROR_NONE` on success.
 */
error_t NuvotonWdt::initialize(interval_t interval)
{
	// Register Unlock sequence: required before writing to protected registers.
	SYS->REGLCTL = 0x59;
	SYS->REGLCTL = 0x16;
	SYS->REGLCTL = 0x88;
	
	// Set the timeout interval field and enable WDT with reset-on-timeout.
	setFieldData(mDev->CTL, WDT_CTL_TOUTSEL_Msk, interval, WDT_CTL_TOUTSEL_Pos);
	mDev->CTL |= WDT_CTL_WDTEN_Msk | WDT_CTL_RSTEN_Msk;

	// Register Lock: re-enable register protection after configuration.
	SYS->REGLCTL = 0x00;

	return error_t::ERROR_NONE;
}

/**
 * @brief Reloads (feeds) the watchdog counter to prevent a system reset.
 * @details Writes the Nuvoton-required magic value `0x00005AA5` to the
 * WDT RSTCNT register. This action reloads the watchdog counter, preventing
 * it from reaching zero and triggering a system reset.
 */
void NuvotonWdt::update()
{
	mDev->RSTCNT = 0x00005AA5;
}

/**
 * @brief Checks whether the Nuvoton WDT is currently active.
 * @details Reads the WDT control register and verifies that both the WDT
 * enable bit (`WDT_CTL_WDTEN_Msk`) and the reset enable bit
 * (`WDT_CTL_RSTEN_Msk`) are set. Both bits must be active for the watchdog
 * to operate as a system safety mechanism.
 *
 * @return bool Returns `true` if both WDTEN and RSTEN bits are set,
 *              `false` otherwise.
 */
bool NuvotonWdt::isWorking()
{
	return ((mDev->CTL & (WDT_CTL_WDTEN_Msk | WDT_CTL_RSTEN_Msk)) == (WDT_CTL_WDTEN_Msk | WDT_CTL_RSTEN_Msk));
}

/**
 * @brief WDT interrupt service routine handler.
 * @details This function is called from the WDT IRQ handler
 * (`WDT_IRQHandler`). Currently reserved for future use; application-level
 * ISR handling can be implemented here if needed.
 */
void NuvotonWdt::isr()
{
	
}

#endif

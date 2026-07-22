/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_NUVOTON_DUAL_CDC__H_
#define YSS_USB_CLASS_NUVOTON_DUAL_CDC__H_

#include "DualCdc.h"

/**
 * @file NuvotonDualCdc.h
 * @brief USB Dual CDC driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonDualCdc
 * @brief Driver class for USB Dual CDC (two virtual COM ports) on Nuvoton MCUs.
 *
 * @details
 * This class inherits from DualCdc. It implements target-specific virtual functions to handle
 * device descriptors and endpoints on Nuvoton USB Device (USBD) hardware.
 */
class NuvotonDualCdc : public DualCdc
{
public :
	// Internal system functions. Do not call from user application.
	NuvotonDualCdc(void) __attribute__((optimize("-O1")));

	virtual error_t initialize(const config_t &config = {"Nuvoton", "USB Virtual COM"}) __attribute__((optimize("-O1")));

	virtual bool getEpDescriptor(uint8_t index, epDesc_t *des) __attribute__((optimize("-O1")));

	virtual void handleGetDeviceDescriptor(void) __attribute__((optimize("-O1")));

	virtual void handleGetConfigDescriptor(uint16_t size) __attribute__((optimize("-O1")));

	virtual void handleGetDeviceQualifierDescriptor(void) __attribute__((optimize("-O1")));

	virtual void handleGetStringDescriptor(uint8_t index, uint16_t size) __attribute__((optimize("-O1")));

private :
};

#endif

/**
 * @example nuvoton_dual_cdc_init_example
 * @code
 * const char *manufacture = "Nuvoton";
 * const char *product = "yss OS Virtual COM Port";
 *
 * Cdc::config_t cdcConfig =
 * {
 *     manufacture,    // Manufacturer name string
 *     product,        // Product name string
 *     nullptr         // Serial number string (null if none)
 * };
 *
 * cdc.initialize(cdcConfig); // Initialize USB Dual CDC Virtual COM Ports
 *
 * // Initialize USBD GPIO pins:
 * gpioA.setAsAltFunc(12, Gpio::PA12_USB_VBUS);      // VBUS
 * gpioA.setAsAltFunc(13, Gpio::PA13_USBD_DN);        // D-
 * gpioA.setAsAltFunc(14, Gpio::PA14_USBD_DP);        // D+
 * gpioA.setAsAltFunc(15, Gpio::PA15_USB_OTG_ID);     // OTG ID
 *
 * usbd.enableClock();          // Enable USBD peripheral clock
 * usbd.initialize(cdc);        // Initialize USBD stack as Dual CDC
 * usbd.enableInterrupt();      // Enable USBD interrupts
 * @endcode
 */


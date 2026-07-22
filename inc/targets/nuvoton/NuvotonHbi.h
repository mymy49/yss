/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_HBI__H_
#define YSS_DRV_NUVOTON_HBI__H_

#include <drv/Hbi.h>

/**
 * @file NuvotonHbi.h
 * @brief HBI (HyperBus Interface) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonHbi
 * @brief Driver class for the HyperBus Interface (HBI) peripheral on Nuvoton MCUs.
 *
 * @details
 * This class provides interface functions to configure and operate HyperBus devices
 * (such as HyperRAM or HyperFlash memory). It handles device initialization, clock speed checks,
 * bus timing configurations, and basic self-testing (write/read verification).
 */
class NuvotonHbi : public Hbi
{
public:
	/**
	 * @brief Initializes the HBI device.
	 * @details Configures the CS setup/hold times, access latency cycles, burst size,
	 * and endian settings according to target clock frequency. Performs a read/write test
	 * to verify memory communication.
	 *
	 * @param[in] config HyperBus device configuration parameters.
	 * @param[in] hbiClkFreq Desired clock frequency for the HyperBus interface in Hz.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t initialize(config_t config, uint32_t hbiClkFreq) __attribute__((optimize("-O1")));

	// Internal system interrupt routine. Do not call from user application.
	void isr(void) __attribute__((optimize("-O1")));

private :
	HBI_T *mDev;
};

#endif



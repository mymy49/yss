/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Radio.h
 * @brief Radio (2.4 GHz RF transceiver) driver class header file.
 *
 * @details
 * This file provides the driver class for the on-chip 2.4 GHz radio peripheral
 * available on supported Nordic Semiconductor MCUs (currently nRF52840).
 * The driver encapsulates the hardware radio register access through the
 * `NRF_RADIO_Type` peripheral register structure.
 *
 * ### Supported Targets
 * - Nordic nRF52840 → `NRF_RADIO_Type` peripheral
 *
 * On unsupported targets, the `YSS_DRV_RADIO_UNSUPPORTED` macro is defined
 * and the class body is excluded from compilation.
 *
 * ### Initialization Flow
 * 1. Supply clock to the peripheral using `enableClock()`.
 * 2. Call `initialize()` to configure the radio hardware (mode, frequency,
 *    TX power, packet format, etc.).
 * 3. Enable the NVIC interrupt using `enableInterrupt()`.
 *
 * @note This driver is under development. Refer to the target-specific
 *       implementation for the full API surface and configuration details.
 */

#ifndef YSS_DRV_RADIO__H_
#define YSS_DRV_RADIO__H_

#include "mcu.h" ///< MCU target selection and macro definitions

#if defined(NRF52840_XXAA)
typedef NRF_RADIO_Type YSS_RADIO_Peri; ///< Hardware radio peripheral register type for nRF52840
#else
#define YSS_DRV_RADIO_UNSUPPORTED ///< Defined when the target MCU does not have a supported radio peripheral
#endif

#ifndef YSS_DRV_RADIO_UNSUPPORTED

#include "Drv.h"          ///< Base driver class (clock, NVIC, reset management)
#include "../yss/error.h" ///< yss error code definitions

/**
 * @class Radio
 * @brief Driver class for the on-chip 2.4 GHz radio peripheral (nRF52840).
 *
 * @details
 * Provides a hardware abstraction layer for the nRF52840's integrated
 * 2.4 GHz radio transceiver. The radio supports multiple protocols
 * (Bluetooth LE, IEEE 802.15.4, proprietary 1 Mbps / 2 Mbps modes).
 *
 * @note This driver is currently in early development. Only basic
 *       initialization is implemented. Advanced features such as packet
 *       configuration, channel selection, and TX/RX handling are not
 *       yet exposed through this interface.
 */
class Radio : public Drv
{
	YSS_RADIO_Peri *mPeri; ///< Pointer to the hardware radio peripheral register block.
	uint16_t mReload;      ///< Reserved reload value for internal use.

  public:
	/**
	 * @brief Constructor for the Radio class.
	 *
	 * @param[in] peri      Pointer to the hardware radio peripheral register block.
	 * @param[in] drvConfig Base driver setup configuration (clock, NVIC function pointers).
	 */
	Radio(YSS_RADIO_Peri *peri, const Drv::setup_t drvConfig);

	/**
	 * @brief Initializes the radio peripheral hardware.
	 *
	 * @details
	 * Performs the initial hardware configuration for the radio peripheral,
	 * including enabling the required clocks and setting default operating
	 * parameters.
	 *
	 * @return error_t Returns ERROR_NONE on success, or an error code on failure.
	 */
	error_t initialize(void);
};

#endif

#endif

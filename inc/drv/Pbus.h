/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Pbus.h
 * @brief Parallel Bus (PBUS) driver class header file.
 *
 * @details
 * This driver provides an interface to configure the STM32F7 Flexible Memory
 * Controller (FMC) for synchronous parallel bus access to external memory or
 * peripherals. The timing registers control the latency of data, address hold,
 * and bus turnaround cycles to match the connected device's timing requirements.
 *
 * ### Supported Targets
 * - STM32F7 — uses the FMC synchronous NOR/PSRAM controller in burst mode.
 *
 * On unsupported targets `YSS_DRV_PBUS_UNSUPPORTED` is defined and the class
 * body is excluded from compilation.
 *
 * ### Initialization Flow
 * 1. Configure all parallel bus GPIO pins (data, address, control) as
 *    alternative functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the FMC peripheral using `enableClock()`.
 * 3. Call `initialize()` to enable the FMC bank.
 * 4. Call `setSpecification()` to apply timing parameters that match the
 *    connected device's datasheet requirements.
 *
 * ### Initialization Example
 * @code
 * Pbus::specification_t spec =
 * {
 *     2,   // dataLatency  : 2 × HCLK additional data latency
 *     2,   // clockDiv     : HCLK / 2 = FMC clock
 *     0,   // busTurnaround: 0 × HCLK bus turnaround time
 *     4,   // data         : 4 × HCLK data phase duration
 *     1,   // addrHold     : 1 × HCLK address hold time
 *     0    // addrSetup    : 0 × HCLK address setup time
 * };
 *
 * pbus.enableClock();
 * pbus.initialize();
 * pbus.setSpecification(spec);
 * @endcode
 */

#ifndef YSS_DRV_PBUS__H_
#define YSS_DRV_PBUS__H_

#include "peripheral.h" ///< Target-specific peripheral register definitions

#if defined(STM32F7)

#else

#define YSS_DRV_PBUS_UNSUPPORTED ///< Defined when the target MCU does not support the parallel bus controller

#endif

#include "Drv.h" ///< Base driver class (clock, NVIC, reset management)
#include "Dma.h" ///< DMA driver class (included for potential DMA-backed transfers)
#include <yss/error.h> ///< yss error code definitions

/**
 * @class Pbus
 * @brief Driver class for the Parallel Bus (PBUS) interface.
 *
 * @details
 * Configures the STM32F7 FMC (Flexible Memory Controller) for synchronous
 * burst access to an external parallel device. The driver manages the FMC
 * timing registers to satisfy the connected device's address setup, data
 * hold, clock division, and bus turnaround requirements.
 *
 * After `initialize()` and `setSpecification()` are called, the device's
 * address space is directly memory-mapped and can be accessed via normal
 * pointer operations without further driver involvement.
 */
class Pbus : public Drv
{
public:
	/**
	 * @struct specification_t
	 * @brief Timing specification structure for the Parallel Bus interface.
	 *
	 * @details
	 * Each field represents a timing parameter expressed as a multiplier of the
	 * HCLK period (or divisor, for `clockDiv`). The actual timing in nanoseconds
	 * is determined by the HCLK frequency. Refer to the connected device's
	 * datasheet and the STM32F7 FMC reference manual for correct values.
	 */
	typedef struct
	{
		uint8_t dataLatency;    ///< Additional data latency in HCLK cycles. HCLK × dataLatency is added to the read access time.
		uint8_t clockDiv;       ///< FMC clock divider. The FMC synchronous clock frequency = HCLK / clockDiv.
		uint8_t busTurnaround;  ///< Bus turnaround time in HCLK cycles. Inserted between consecutive read/write accesses on the data bus.
		uint8_t data;           ///< Data phase duration in HCLK cycles. Controls how long the data lines are held valid.
		uint8_t addrHold;       ///< Address hold time in HCLK cycles. Duration the address is held stable after the strobe.
		uint8_t addrSetup;      ///< Address setup time in HCLK cycles. Duration the address is held stable before the strobe assertion.
	}specification_t;

	/**
	 * @brief Initializes the PBUS (FMC) peripheral.
	 *
	 * @details
	 * Enables the FMC bank and applies default configuration.
	 * Must be called after `enableClock()` and before `setSpecification()`.
	 *
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t initialize(void);

	/**
	 * @brief Configures the parallel bus timing specification.
	 *
	 * @details
	 * Writes the FMC timing registers based on the provided `specification_t`
	 * fields. The values must be computed from the target device datasheet
	 * and the actual HCLK frequency. Calling this function while active bus
	 * transfers are in progress may cause undefined behavior.
	 *
	 * @param[in] spec Reference to the timing and latency specification structure.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t setSpecification(const specification_t &spec);

	// The following are internal functions and do not need to be called by the user application.
	/**
	 * @brief Constructor for the Pbus class.
	 *
	 * @param[in] drvSetup Base driver setup configuration (clock, NVIC function pointers).
	 */
	Pbus(const Drv::setup_t drvSetup);

private:
};

#endif


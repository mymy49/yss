/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Sdram.h
 * @brief SDRAM (Synchronous Dynamic Random-Access Memory) controller driver class header file.
 *
 * @details
 * This driver provides an interface for configuring the external SDRAM controller
 * (FMC Bank 5/6) found on STM32F4xx and STM32F7xx devices. Once initialized,
 * the SDRAM appears as a transparent memory-mapped region to the CPU and DMA
 * controllers, and no further driver interaction is needed for normal read/write
 * operations.
 *
 * ### Supported Targets
 * - STM32F446xx, STM32F429xx, STM32F767xx, STM32F746xx → `FMC_Bank5_6_TypeDef`
 *
 * On unsupported targets `YSS_DRV_SDRAM_UNSUPPORTED` is defined and the class
 * body is excluded from compilation.
 *
 * ### Initialization Flow
 * 1. Configure all SDRAM GPIO pins (address, data, control) as alternative
 *    functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the FMC peripheral using `enableClock()`.
 * 3. Call `initialize()` with the target SDRAM bank number and a
 *    `specification_t` struct describing the device timing and geometry.
 * 4. After initialization, the SDRAM address space can be accessed as
 *    a normal C pointer (e.g. `uint16_t *sdram = (uint16_t *)0xC0000000`).
 *
 * ### Initialization Example
 * @code
 * Sdram::specification_t spec =
 * {
 *     8,          // columnAddress   : 8-bit column address
 *     12,         // rowAddress      : 12-bit row address
 *     16,         // dbusWidth       : 16-bit data bus width
 *     4,          // internalBank    : 4 internal banks
 *     3,          // casLatency      : CAS latency of 3 cycles
 *     100000000,  // maxFrequency    : 100 MHz maximum clock
 *     2,          // tMrd            : Load Mode Register to Active delay (cycles)
 *     70,         // tXsr            : Exit Self-Refresh to Active (ns)
 *     42,         // tRas            : Active to Precharge minimum time (ns)
 *     63,         // tRc             : Row Cycle time (ns)
 *     2,          // tWr             : Write Recovery time (cycles)
 *     18,         // tRp             : Precharge to Active time (ns)
 *     18,         // tRcd            : Active to Read/Write time (ns)
 *     0,          // tOh             : Output hold time (ns)
 *     0,          // tAc             : Access time (ns)
 *     64,         // tRefresh        : Refresh period (ms)
 *     4096,       // numOfRow        : Number of rows (for refresh counter calculation)
 *     false,      // writeProtection : Disable write protection
 *     false,      // burstRead       : Disable burst read
 *     0x0231      // mode            : Mode register value
 * };
 *
 * sdram.enableClock();
 * sdram.initialize(1, spec, SystemCoreClock);
 * @endcode
 */

#ifndef YSS_DRV_SDRAM__H_
#define YSS_DRV_SDRAM__H_

#include "peripheral.h" ///< Target-specific peripheral register definitions

#if defined(STM32F446xx) || defined(STM32F429xx) || defined(STM32F767xx) || defined(STM32F746xx)

typedef FMC_Bank5_6_TypeDef	YSS_SDRAM_Peri; ///< FMC Bank 5/6 peripheral type for SDRAM on STM32F4/F7

#else

#define YSS_DRV_SDRAM_UNSUPPORTED ///< Defined when the target MCU does not support the SDRAM controller

#endif

#ifndef YSS_DRV_SDRAM_UNSUPPORTED

#include "Drv.h"    ///< Base driver class (clock, NVIC, reset management)
#include <stdint.h> ///< Standard fixed-width integer types

/**
 * @class Sdram
 * @brief Driver class for the external SDRAM memory controller.
 *
 * @details
 * Configures the FMC (Flexible Memory Controller) Bank 5/6 to interface with
 * an external SDRAM chip. After `initialize()` completes successfully, the
 * SDRAM device is accessible as a contiguous memory-mapped region beginning
 * at the address assigned to the configured FMC bank by the MCU memory map.
 *
 * All timing parameters in `specification_t` must be derived from the SDRAM
 * datasheet and the actual FMC clock frequency; incorrect values may cause
 * data corruption or hardware lockup.
 */
class Sdram : public Drv
{
  public:
	/**
	 * @struct specification_t
	 * @brief SDRAM device timing and geometry specification structure.
	 *
	 * @details
	 * All time-based fields (tMrd … tRefresh) should be derived from the
	 * SDRAM datasheet and expressed in nanoseconds unless noted otherwise.
	 * The driver calculates the corresponding FMC register values based on
	 * the actual FMC clock frequency passed to `initialize()`.
	 */
	struct specification_t
	{
		uint8_t  columnAddress;   ///< Number of column address bits (e.g. 8, 9, 10, or 11).
		uint8_t  rowAddress;      ///< Number of row address bits (e.g. 11, 12, or 13).
		uint8_t  dbusWidth;       ///< Data bus width in bits (8, 16, or 32).
		uint8_t  internalBank;    ///< Number of internal SDRAM banks (2 or 4).
		uint8_t  casLatency;      ///< CAS (Column Address Strobe) latency in clock cycles (1, 2, or 3).
		uint32_t maxFrequency;    ///< Maximum operating clock frequency of the SDRAM device in Hz.
		uint32_t tMrd;            ///< Load Mode Register to Active delay in clock cycles.
		uint32_t tXsr;            ///< Exit Self-Refresh to Active command delay in ns.
		uint32_t tRas;            ///< Active to Precharge minimum time in ns.
		uint32_t tRc;             ///< Row Cycle time (Active to Active or Refresh to Active) in ns.
		uint32_t tWr;             ///< Write Recovery time in clock cycles.
		uint32_t tRp;             ///< Precharge to Active command delay in ns.
		uint32_t tRcd;            ///< Active to Read/Write command delay in ns.
		uint32_t tOh;             ///< Output hold time in ns (used for FMC output setup).
		uint32_t tAc;             ///< Data access time from clock edge in ns.
		uint32_t tRefresh;        ///< SDRAM refresh period in milliseconds.
		uint16_t numOfRow;        ///< Total number of rows in the SDRAM array (used to compute the refresh rate).
		bool     writeProtection; ///< If true, write-protects the SDRAM bank (read-only access).
		bool     burstRead;       ///< If true, enables burst read mode on the FMC.
		uint16_t mode;            ///< SDRAM Mode Register value to be written during initialization (device-specific).
	};

	/**
	 * @brief Constructor for the Sdram class.
	 *
	 * @param[in] drvConfig Base driver setup configuration (clock, NVIC function pointers).
	 */
	Sdram(const Drv::setup_t drvConfig);

	/**
	 * @brief Initializes and configures the SDRAM controller.
	 *
	 * @details
	 * Applies the FMC timing registers based on the `specification_t` values
	 * and the supplied FMC clock frequency, issues the SDRAM initialization
	 * command sequence (precharge all, auto-refresh, load mode register), and
	 * programs the auto-refresh counter.
	 *
	 * @param[in] bank  FMC SDRAM bank number (1 or 2).
	 * @param[in] spec  Reference to the SDRAM device timing and geometry specification.
	 * @param[in] freq  Actual FMC clock frequency in Hz (used for timing register calculation).
	 * @return bool     Returns true on successful initialization, false on failure.
	 */
	bool initialize(uint8_t bank, const specification_t &spec, uint32_t freq);

  private:
	specification_t *mSpec; ///< Pointer to the last applied specification (for reference after init).
	YSS_SDRAM_Peri  *mDev;  ///< Pointer to the FMC Bank 5/6 hardware peripheral register block.
	uint32_t (*mGetClockFrequencyFunc)(void); ///< Function pointer to retrieve the current FMC clock frequency.
};

#endif

#endif


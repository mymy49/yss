/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>

#if defined(WDT) && WDT_ENABLE
/**
 * @brief Enables or disables the APB0 clock for the WDT peripheral.
 * @details This static function is registered as the clock control callback
 * in the `Drv::setup_t` configuration structure. It delegates to the system
 * clock manager to gate the WDT clock on the APB0 bus.
 *
 * @param[in] en Set to `true` to enable the WDT clock, `false` to disable it.
 */
static void enableClock(bool en)
{
	clock.enableApb0Clock(CLK_APBCLK0_WDTCKEN_Pos, en);
}

/**
 * @brief Enables or disables the NVIC interrupt for the WDT peripheral.
 * @details This static function is registered as the interrupt control callback
 * in the `Drv::setup_t` configuration structure. It enables or disables the
 * WDT interrupt line in the Nested Vectored Interrupt Controller (NVIC).
 *
 * @param[in] en Set to `true` to enable the WDT interrupt, `false` to disable it.
 */
static void enableInterrupt(bool en)
{
	nvic.enableInterrupt(WDT_IRQn, en);
}

/**
 * @brief Base driver setup configuration for the WDT peripheral.
 * @details Defines the callback functions used by the `Drv` base class to
 * manage the WDT peripheral's clock gate and NVIC interrupt line. The reset
 * and clock-get function pointers are not required for the WDT and are set
 * to `0`.
 */
static const Drv::setup_t gDrvWdtSetup = 
{
	enableClock,		//void (*clockFunc)(bool en);
	enableInterrupt,	//void (*nvicFunc)(bool en);
	0,					//void (*resetFunc)(void);
	0					//uint32_t (*getClockFunc)(void);
};

/**
 * @brief Nuvoton WDT-specific hardware setup configuration.
 * @details Provides the pointer to the Nuvoton WDT hardware register block.
 * This structure is passed to the `NuvotonWdt` constructor to bind the driver
 * instance to the physical hardware peripheral.
 */
static const NuvotonWdt::setup_t gWdtSetup = 
{
	WDT				// WDT_T *dev;
};

/**
 * @brief Global NuvotonWdt driver instance for the WDT peripheral.
 * @details This object is the application-accessible handle for the Nuvoton
 * WDT peripheral. It is declared as `extern NuvotonWdt wdt` in the target's
 * instance.h header and can be used directly in application code.
 */
NuvotonWdt wdt(gDrvWdtSetup, gWdtSetup);

extern "C"
{
	/**
	 * @brief WDT IRQ handler entry point.
	 * @details This C-linkage function is the interrupt vector for the WDT
	 * peripheral. It delegates to the `NuvotonWdt::isr()` member function of
	 * the global `wdt` instance to handle the interrupt.
	 */
	void WDT_IRQHandler(void)
	{
		wdt.isr();
	}
}
#endif


#endif

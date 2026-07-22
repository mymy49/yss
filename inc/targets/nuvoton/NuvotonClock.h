/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_CLOCK_NUVOTON__H_
#define YSS_CLASS_CLOCK_NUVOTON__H_

#include <yss/error.h>
#include <drv/Drv.h>

/**
 * @file NuvotonClock.h
 * @brief Clock controller driver class header file for Nuvoton MCUs.
 */

/**
 * @class Clock
 * @brief Clock controller driver class for managing internal/external oscillators, PLL, HCLK, and peripheral clocks.
 *
 * @details
 * This class provides interface functions to configure internal/external oscillators
 * (HXT, HIRC, MIRC, LIRC), configure the PLL, select the system HCLK source, and enable/disable
 * clock gates for AHB and APB peripherals. It also includes functions to enter low-power modes (Idle, Power Down).
 */
class Clock : public Drv
{
public:
	/**
	 * @brief Enables the External High Speed Crystal Oscillator (HXT).
	 *
	 * @param[in] hseHz The frequency of the external crystal in Hz.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t enableHxt(uint32_t hseHz) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Enables or disables the High-speed Internal RC Oscillator (HIRC).
	 *
	 * @param[in] en If set to true, enables HIRC; otherwise disables it.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t enableHirc(bool en) __attribute__((optimize("-O1")));

#if defined(__M251_SUBFAMILY)
	/**
	 * @brief Enables or disables the Medium-speed Internal RC Oscillator (MIRC).
	 * @note Only available on M251 subfamily MCUs.
	 *
	 * @param[in] en If set to true, enables MIRC; otherwise disables it.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t enableMirc(bool en) __attribute__((optimize("-O1")));
#endif

	/**
	 * @brief Enables or disables the Low-speed Internal RC Oscillator (LIRC).
	 *
	 * @param[in] en If set to true, enables LIRC; otherwise disables it.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t enableLirc(bool en) __attribute__((optimize("-O1")));

	/**
	 * @brief Gets the frequency of the High-speed Internal RC Oscillator (HIRC).
	 *
	 * @return uint32_t HIRC frequency in Hz.
	 */
	uint32_t getHircFrequency(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the frequency of the External High Speed Crystal Oscillator (HXT).
	 *
	 * @return uint32_t HXT frequency in Hz.
	 */
	uint32_t getHxtFrequency(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the frequency of the Low-speed Internal RC Oscillator (LIRC).
	 *
	 * @return uint32_t LIRC frequency in Hz.
	 */
	uint32_t getLircFrequency(void) __attribute__((optimize("-O1")));

#if defined(__M251_SUBFAMILY)
	/**
	 * @brief Gets the frequency of the Medium-speed Internal RC Oscillator (MIRC).
	 * @note Only available on M251 subfamily MCUs.
	 *
	 * @return uint32_t MIRC frequency in Hz.
	 */
	uint32_t getMircFrequency(void) __attribute__((optimize("-O1")));
#endif

	/**
	 * @brief Gets the configured PLL output frequency.
	 *
	 * @return uint32_t PLL frequency in Hz.
	 */
	uint32_t getPllFrequency(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the current HCLK (system clock) frequency.
	 *
	 * @return uint32_t HCLK frequency in Hz.
	 */
	uint32_t getHclkClockFrequency(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the APB0 bus clock frequency.
	 *
	 * @return uint32_t APB0 clock frequency in Hz.
	 */
	uint32_t getApb0ClockFrequency(void) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Gets the APB1 bus clock frequency.
	 *
	 * @return uint32_t APB1 clock frequency in Hz.
	 */
	uint32_t getApb1ClockFrequency(void) __attribute__((optimize("-O1")));

	/**
	 * @brief PLL clock source enumeration.
	 */
#if defined(__M251_SUBFAMILY)
	typedef enum
	{
		PLL_SRC_HXT = 0,    ///< External High Speed Crystal Oscillator (HXT)
		PLL_SRC_HIRC,       ///< High-speed Internal RC Oscillator (HIRC)
		PLL_SRC_HXT2,       ///< Alternate External High Speed Clock Source
		PLL_SRC_MIRC        ///< Medium-speed Internal RC Oscillator (MIRC)
	}pllSrc_t;
#else
	typedef enum
	{
		PLL_SRC_HXT = 0,    ///< External High Speed Crystal Oscillator (HXT)
		PLL_SRC_HIRC,       ///< High-speed Internal RC Oscillator (HIRC)
	}pllSrc_t;
#endif	

	/**
	 * @brief Enables the Phase Locked Loop (PLL).
	 * @details The output clock frequency is calculated as:
	 * \f[ F_{OUT} = F_{IN} \times \frac{2 \times (fbdiv + 2)}{NO} \f]
	 * where \f$ NO \f$ is determined by outdiv:
	 * - outdiv = 0: \f$ NO = 1 \f$
	 * - outdiv = 1 or 2: \f$ NO = 2 \f$
	 * - outdiv = 3: \f$ NO = 4 \f$
	 *
	 * @param[in] src The PLL input reference clock source.
	 * @param[in] indiv Input clock divisor (0 ~ 63).
	 * @param[in] fbdiv Feedback multiplier divisor (0 ~ 512).
	 * @param[in] outdiv Output clock divider selector (0 ~ 3).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t enablePll(pllSrc_t src, uint8_t indiv, uint16_t fbdiv, uint8_t outdiv) __attribute__((optimize("-O1")));

	/**
	 * @brief HCLK clock source enumeration.
	 */
	typedef enum
	{
#if defined(__M251_SUBFAMILY)
		HCLK_SRC_HXT = 0,   ///< External High Speed Crystal Oscillator (HXT)
		HCLK_SRC_LXT,       ///< External Low Speed Crystal Oscillator (LXT)
		HCLK_SRC_PLL,       ///< Phase Locked Loop (PLL)
		HCLK_SRC_LRIC,      ///< Low-speed Internal RC Oscillator (LIRC)
		HCLK_SRC_MIRC = 5,  ///< Medium-speed Internal RC Oscillator (MIRC)
		HCLK_SRC_HIRC = 7   ///< High-speed Internal RC Oscillator (HIRC)
#elif defined(__M43x_SUBFAMILY) || defined(__M46x_SUBFAMILY)
		HCLK_SRC_HXT = 0,   ///< External High Speed Crystal Oscillator (HXT)
		HCLK_SRC_LXT,       ///< External Low Speed Crystal Oscillator (LXT)
		HCLK_SRC_PLL,       ///< Phase Locked Loop (PLL)
		HCLK_SRC_LRIC,      ///< Low-speed Internal RC Oscillator (LIRC)
		HCLK_SRC_HIRC = 7   ///< High-speed Internal RC Oscillator (HIRC)
#endif
	}hclkSrc_t;
	
	/**
	 * @brief Configures the clock sources and prescalers for HCLK and PCLKs.
	 * @details This function automatically configures the internal Flash memory access latency cycles.
	 *
	 * @param[in] src Clock source for HCLK.
	 * @param[in] hclkDiv Divisor for HCLK. Must be 0 if PLL is selected as the HCLK source.
	 * @param[in] pclk0Div Divisor for PCLK0 (scaled down from HCLK).
	 * @param[in] pclk1Div Divisor for PCLK1 (scaled down from HCLK).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 *
	 * @note
	 * For M483 / M46x series, PCLK0 and PCLK1 clock frequencies must not exceed 96 MHz.
	 */
	error_t setHclkClockSource(hclkSrc_t src, uint8_t hclkDiv, uint8_t pclk0Div, uint8_t pclk1Div) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Enables or disables a clock gate on the AHB0 bus.
	 * @note On MCUs without explicit AHB0/AHB1 divisions, this maps to the general AHB bus clock gate.
	 *
	 * @param[in] position The bit position in the clock enable register corresponding to the peripheral.
	 * @param[in] en If set to true, enables the clock gate; otherwise disables it.
	 */
	void enableAhb0Clock(uint32_t position, bool en = true) __attribute__((optimize("-O1")));

	/**
	 * @brief Enables or disables a clock gate on the AHB1 bus.
	 *
	 * @param[in] position The bit position in the clock enable register corresponding to the peripheral.
	 * @param[in] en If set to true, enables the clock gate; otherwise disables it.
	 */
	void enableAhb1Clock(uint32_t position, bool en = true) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Enables or disables a clock gate on the APB0 bus.
	 *
	 * @param[in] position The bit position in the clock enable register corresponding to the peripheral.
	 * @param[in] en If set to true, enables the clock gate; otherwise disables it.
	 */
	void enableApb0Clock(uint32_t position, bool en = true) __attribute__((optimize("-O1")));

	/**
	 * @brief Enables or disables a clock gate on the APB1 bus.
	 *
	 * @param[in] position The bit position in the clock enable register corresponding to the peripheral.
	 * @param[in] en If set to true, enables the clock gate; otherwise disables it.
	 */
	void enableApb1Clock(uint32_t position, bool en = true) __attribute__((optimize("-O1")));

	/**
	 * @brief Enables or disables a clock gate on the APB2 bus.
	 *
	 * @param[in] position The bit position in the clock enable register corresponding to the peripheral.
	 * @param[in] en If set to true, enables the clock gate; otherwise disables it.
	 */
	void enableApb2Clock(uint32_t position, bool en = true) __attribute__((optimize("-O1")));
	
	/**
	 * @brief Enters Power Down mode.
	 * @details The MCU can be woken up from Power Down mode by events such as RTC, WDT, I2C,
	 * Timer, UART, BOD, GPIO, EINT, USCI, USBD, and ACMP interrupts.
	 */
	void enterPowerDownMode(void);

	/**
	 * @brief Enters Idle mode.
	 * @details The MCU can be woken up from Idle mode by any enabled peripheral interrupt.
	 */
	void enterIdleMode(void);

private:
};

#endif
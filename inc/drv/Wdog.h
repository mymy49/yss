/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Wdog.h
 * @brief Watchdog timer driver class header file.
 */

#ifndef YSS_DRV_WDOG__H_
#define YSS_DRV_WDOG__H_

#include "peripheral.h"

#if defined(STM32F0)

typedef IWDG_TypeDef		YSS_WDOG_peri;

#else

typedef void WDOG_peri;
#define YSS_DRV_WDOG_UNSUPPORTED

#endif

#ifndef YSS_DRV_WDOG_UNSUPPORTED

#include "Drv.h"
#include <yss/error.h>

/**
 * @class Wdog
 * @brief Watchdog timer (WDOG) driver class.
 */
class Wdog : public Drv
{
public:
	/**
	 * @brief Initializes the Watchdog timer.
	 * 
	 * @param[in] prescale Prescaler divider value.
	 * @param[in] reload Reload counter value.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t initialize(uint8_t prescale, uint16_t reload);

	/**
	 * @brief Reloads/feeds the Watchdog timer to prevent reset.
	 */
	void update(void);

	// The following are internal functions and do not need to be called by the user application.
	struct Config
	{
		YSS_WDOG_peri *dev;
	};

	Wdog(const Drv::setup_t drvConfig, const Config config);

private:
	YSS_WDOG_peri *mPeri;
	uint16_t mReload;
};

#endif

#endif

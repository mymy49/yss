/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_WATCHDOG__H_
#define YSS_DRV_WATCHDOG__H_

#include "Drv.h"
#include <yss/error.h>

class Watchdog : public Drv
{
public:
	/**
	 * @brief Reloads/feeds the Watchdog timer to prevent reset.
	 */
	virtual void update() = 0;

	virtual bool isWorking() = 0;

	Watchdog(const Drv::setup_t drvConfig);

private:
};

#endif


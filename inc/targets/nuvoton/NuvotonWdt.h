/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_WDT__H_
#define YSS_NUVOTON_DRV_WDT__H_

#include <drv/Watchdog.h>

class NuvotonWdt : public Watchdog
{
public:
	typedef enum
	{
		INTERVAL_0p4_mSec = 0,
		INTERVAL_1p6_mSec,
		INTERVAL_6p4_mSec,
		INTERVAL_25p6_mSec,
		INTERVAL_102p4_mSec,
		INTERVAL_409p6_mSec,
		INTERVAL_1p638_Sec,
		INTERVAL_6p553_Sec,
		INTERVAL_26p214_Sec,
	}interval_t;

	error_t initialize(interval_t interval = INTERVAL_26p214_Sec) __attribute__((optimize("-O1")));

	virtual void update() override;

	virtual bool isWorking() override;

	void isr();

	struct setup_t
	{
		WDT_T *dev;
	};

	NuvotonWdt(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

protected:
	WDT_T *mDev;
};

#endif



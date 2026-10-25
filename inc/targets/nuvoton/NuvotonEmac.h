/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_EMAC__H_
#define YSS_DRV_NUVOTON_EMAC__H_

#include <hal/Ethernet.h>
#include <drv/Drv.h>
#include <yss/error.h>

class NuvotonEmac : public Ethernet, public Drv
{
public :
	struct setup_t
	{
		EMAC_T *dev;
	};

	NuvotonEmac(const Drv::setup_t drvSetup, const setup_t setup);

	error_t initialize(config_t config) override;

protected :
	void updateConfig() override;

private :
	EMAC_T *mDev;

};

#endif


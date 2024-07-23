/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_RADIO__H_
#define YSS_DRV_RADIO__H_

#include "mcu.h"

#if defined(NRF52840_XXAA)
typedef NRF_RADIO_Type YSS_RADIO_Peri;
#else
#define YSS_DRV_RADIO_UNSUPPORTED
#endif

#ifndef YSS_DRV_RADIO_UNSUPPORTED

#include "Drv.h"
#include "../yss/error.h"

class Radio : public Drv
{
	YSS_RADIO_Peri *mPeri;
	uint16_t mReload;

  public:
	Radio(YSS_RADIO_Peri *peri, const Drv::setup_t drvConfig);
	error initialize(void);
};

#endif

#endif
